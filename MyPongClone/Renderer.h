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
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        
        glGenBuffers(1, &vbo);
        
        glGenBuffers(1, &ebo);
        
        glViewport(0, 0, width, height);
        projection = glm::ortho(0.0f, width, height, 0.0f);
        GLint uniTrans = glGetUniformLocation(shaderProgram, "uMatrix");
        glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(projection));
    }
    
    void bindAttributes(GLuint& shaderProgram);
    void cleanUp();
    void setupElementBuffer(GLuint& ebo);
    void setupVertices(GLuint& vbo);
    GLuint setupShader();
private:
    sf::Shader shader;
    glm::mat4 projection;
    GLuint fragmentShader;
    GLuint shaderProgram;
    GLuint vao;
    GLuint vbo;
    GLuint vertexShader;
    GLuint ebo;
};

#endif /* defined(__MyPongClone__Renderer__) */
