//
//  Renderer.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-12.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "Renderer.h"

void Renderer::bindAttributes(GLuint& shaderProgram) {
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);
    
    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
    
    GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));
    
    glBindVertexArray(0);
}

void Renderer::cleanUp() {
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}

void Renderer::render(sf::FloatRect &bounds) {
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(bounds.left, bounds.top, 0.0f));
    model = glm::scale(model, glm::vec3(bounds.width, bounds.height, 0.0f));
    GLint modelMat = glGetUniformLocation(shaderProgram, "mMatrix");
    glUniformMatrix4fv(modelMat, 1, GL_FALSE, glm::value_ptr(model));
    
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Renderer::setupElementBuffer() {
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}

void Renderer::setupVertices() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    GLfloat vertices[] = {
        //  Position(2) Color(3)     Texcoords(2)
        0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
        1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Top-right
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
        0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
    };
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
}

GLuint Renderer::setupShader() {
    const GLchar *vertex =
    "#version 150 core\n\
    in vec2 position;\n\
    in vec3 color;\n\
    in vec2 texcoord;\n\
    out vec3 Color;\n\
    out vec2 Texcoord;\n\
    uniform mat4 uMatrix;\n\
    uniform mat4 mMatrix;\n\
    void main() {\n\
    Color = color;\n\
    Texcoord = texcoord;\n\
    gl_Position = uMatrix * mMatrix * vec4(position.xy, 0.0, 1.0);\n\
    }";
    
    const GLchar *fragment =
    "#version 150 core\n\
    in vec3 Color;\n\
    in vec2 Texcoord;\n\
    out vec4 outColor;\n\
    uniform sampler2D tex;\n\
    void main() {\n\
    outColor = texture(tex, Texcoord) * vec4(Color, 1.0);\n\
    }";
    
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex, NULL);
    glCompileShader(vertexShader);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, NULL);
    glCompileShader(fragmentShader);
    
    GLint status;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    
    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        std::cout << buffer << std::endl;
        assert(false);
    }
    
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
    
    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        std::cout << buffer << std::endl;
        assert(false);
    }
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    
    glLinkProgram(shaderProgram);
    
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
    if (status != GL_TRUE) {
        char buffer[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, buffer);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << buffer << std::endl;
    }
    
    glUseProgram(shaderProgram);
    
    return shaderProgram;
}

void Renderer::startRender() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
}