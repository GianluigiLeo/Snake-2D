#ifndef __FILE_HPP__
#define __FILE_HPP__
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <iostream>

namespace File {

    /* ============================================================================================== */
    /*                                            readFile                                            */
    /* ============================================================================================== */
    static std::string readFile(const char* filepath){
        std::string content;
        std::ifstream fileStream(filepath, std::ios::in);
        std::string line = "";

        while(!fileStream.eof()){
            getline(fileStream, line);
            content.append(line + "\n");
        }
        fileStream.close();
        return content;
    }



}//!namespace File
#endif // __FILE_HPP__