/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dir.h
 * Author: setler
 *
 * Created on April 25, 2018, 2:31 PM
 */

#ifndef DIR_H
#define DIR_H

#include "File.h"

class Dir {
public:
    Dir();
    Dir(const Dir& orig);
    virtual ~Dir();
    
    //first child dir
    Dir *dir;
    
    std::string name;
    std::string path;
    
    //first file in the dir
    File *file;
    
private:

};

#endif /* DIR_H */

