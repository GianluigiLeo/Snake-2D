#ifndef __DEBUGGER_HPP__
#define __DEBUGGER_HPP__

#include <GL/glew.h>
#include <iostream>

namespace Debugger {

    /* ============================================================================================== */
    /*                                        checkShaderError                                        */
    /* ============================================================================================== */
    static void checkShaderError(unsigned int shader){
        int len = 0;
        int chWrittn = 0;
        char *log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        if(len > 0){
            log = (char*)malloc(len);
            glGetShaderInfoLog(shader, len, &chWrittn, log);
            std::cout << "Shader Info Log: " << log << std::endl;
            free(log);
        
        }
    }

    /* ============================================================================================== */
    /*                                     checkShaderProgramError                                    */
    /* ============================================================================================== */
    static void checkShaderProgramError(unsigned int prog) {
        int len = 0;
        int chWrittn = 0;
        char* log;
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
        if(len > 0){
            log = (char*)malloc(len);
            glGetProgramInfoLog(prog, len, &chWrittn, log);
            std::cout << "Program Info Log: " << log << std::endl;
            free(log);
        }

    }

    /* ============================================================================================== */
    /*                                        checkOpenGLError                                        */
    /* ============================================================================================== */
    static bool checkOpenGLError(){
        bool foundError = false;
        int glErr = glGetError();
        while(glErr != GL_NO_ERROR){
            std::cout << "glError: " << glErr << std::endl;
            foundError = true;
            glErr = glGetError();
        }

        return foundError;
    }
    
    /* ============================================================================================== */
    /*                                         checkGlfwError                                         */
    /* ============================================================================================== */
    static void checkGlfwError(int error, const char* description) {
        std::cout << "ERRORE GLFW: codice: " << error << " - " << description << std::endl;
    }

} //!namespace Debug

#endif // __DEBUGGER_HPP__