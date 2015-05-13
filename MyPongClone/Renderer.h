//
//  Renderer.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-12.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__Renderer__
#define __MyPongClone__Renderer__

#define GLEW_STATIC
#include <GL/glew.h>
#include <stdio.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class Renderer {
public:
    Renderer(float width, float height) {
        setupShader();
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);
        setupVertices();
        setupElementBuffer();
        bindAttributes(shaderProgram);

        GLuint tex;
        glGenTextures(1, &tex);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        GLuint color[] = { 255, 255, 255, 255 };
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
        
        glViewport(0, 0, width, height);
        projection = glm::ortho(0.0f, width, height, 0.0f);
        view = glm::mat4();
        GLint uniTrans = glGetUniformLocation(shaderProgram, "uMatrix");
        glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(projection));
    }
    
    void bindAttributes(GLuint &shaderProgram);
    void cleanUp();
    void flush();
    void render(sf::FloatRect &bounds);
    void setupElementBuffer();
    void setupVertices();
    void startRender();
    GLuint setupShader();
private:
    sf::Shader shader;
    glm::mat4 projection;
    glm::mat4 view;
    GLuint fragmentShader;
    GLuint shaderProgram;
    GLuint vao;
    GLuint vbo;
    GLuint vertexShader;
    GLuint ebo;
};

#endif /* defined(__MyPongClone__Renderer__) */
