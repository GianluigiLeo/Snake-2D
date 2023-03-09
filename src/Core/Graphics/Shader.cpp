#include "Shader.hpp"

#include <iostream>
#include "../Utils/File.hpp"
#include "../Debug/Debugger.hpp"


#include <GL/glew.h>
#include <glm/glm.hpp>

/* ============================================================================================== */
/*                                             Shader                                             */
/* ============================================================================================== */
Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath){

    std::string vertexShaderStr = File::readFile(vertexShaderPath);
    std::string fragmentShaderStr = File::readFile(fragmentShaderPath);

    const char* vertexCode = vertexShaderStr.c_str();
    const char* fragmentCode = fragmentShaderStr.c_str();

    unsigned int vertex, fragment;
    int success;

    //Compila Vertex
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    Debugger::checkOpenGLError();
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << std::endl;
        Debugger::checkShaderError(vertex);
    }

    //Compila Fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    Debugger::checkOpenGLError();
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << std::endl;
        Debugger::checkShaderError(fragment);
    }


    //Link Shader
    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertex);
    glAttachShader(shaderID, fragment);
    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
    if (!success) {
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<  std::endl;
        Debugger::checkShaderProgramError(shaderID);
    }

}



/* ============================================================================================== */
/*                                               Use                                              */
/* ============================================================================================== */
void Shader::Use() {

    glUseProgram(shaderID);

}



/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Shader::onDestroy() {

    glDeleteProgram(shaderID);
}



/* ============================================================================================== */
/* ============================================================================================== */
/*                                    utility uniform functions                                   */
/* ============================================================================================== */
/* ============================================================================================== */

/* =========================================== setBool ========================================== */
void Shader::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value); 
}

/* =========================================== setInt =========================================== */
void Shader::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value); 
}

/* ========================================== setFloat ========================================== */
void Shader::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value); 
} 




/* =========================================== setVec2 ========================================== */
 void Shader::setVec2(const std::string &name, const glm::vec2 &value) const { 
        glUniform2fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}
/* =========================================== setVec2 ========================================== */
void Shader::setVec2(const std::string &name, float x, float y) const { 
    glUniform2f(glGetUniformLocation(shaderID, name.c_str()), x, y); 
}
/* =========================================== setVec3 ========================================== */
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const { 
    glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}
/* =========================================== setVec3 ========================================== */
void Shader::setVec3(const std::string &name, float x, float y, float z) const { 
    glUniform3f(glGetUniformLocation(shaderID, name.c_str()), x, y, z); 
}
/* =========================================== setVec3 ========================================== */
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const { 
    glUniform4fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}
/* =========================================== setVec4 ========================================== */
void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const { 
    glUniform4f(glGetUniformLocation(shaderID, name.c_str()), x, y, z, w); 
}
/* =========================================== setMat2 ========================================== */
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
/* =========================================== setMat3 ========================================== */
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
/* =========================================== setMat4 ========================================== */
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}