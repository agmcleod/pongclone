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
#include <ft2build.h>
#include FT_FREETYPE_H
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "ResourcePath.hpp"

struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};

class Renderer {
public:
    Renderer(float width, float height) {
        glViewport(0, 0, width, height);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        setupShader();
        projection = glm::ortho(0.0f, width, height, 0.0f);
        setupTextCharacters();
        
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);
        setupMainBuffer();
        
        glGenVertexArrays(1, &tVAO);
        glGenBuffers(1, &tVBO);
        
        glBindVertexArray(tVAO);
        glBindBuffer(GL_ARRAY_BUFFER, tVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        GLubyte color[] = { 255, 255, 255, 255 };
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
        
        glUseProgram(shaderProgram);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    }
    
    void cleanUp();
    void render(sf::FloatRect &bounds);
    void setupMainBuffer();
    void setupTextCharacters();
    void setupShader();
    void startRender();
    void text(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
    void compileProgram(const GLchar *vertex, const GLchar *fragment, GLuint &vertexShader, GLuint &fragmentShader, GLuint &shaderProgram);
    
    glm::mat4 projection;
    std::map<GLchar, Character> Characters;
    GLuint fragmentShader;
    GLuint shaderProgram;
    GLuint tex;
    GLuint vao;
    GLuint vbo;
    GLuint vertexShader;
    GLuint ebo;
    
    // text buffers
    GLuint tVAO;
    GLuint tVBO;
    
    // text shader
    GLuint textProgram;
    GLuint textFragShader;
    GLuint textVertShader;
};

#endif /* defined(__MyPongClone__Renderer__) */
