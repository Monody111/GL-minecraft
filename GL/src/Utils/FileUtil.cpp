//
//  FileUtil.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/7.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include "FileUtil.hpp"

string getFileContents(const string &filePath){
    stringstream Contents;
    ifstream file;
    
    try {
        file.exceptions(ifstream::badbit);
        file.open(filePath);
        Contents << file.rdbuf();
        file.close();
    } catch (ifstream::failure e) {
        cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
    }
    
    return Contents.str();
}
