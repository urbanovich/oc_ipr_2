/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dir.h
 * Author: setler
 *
 * Created on April 24, 2018, 10:31 PM
 */

#ifndef HelperDir_H
#define HelperDir_H

#include <dirent.h>
#include <stdio.h>

#include "Dir.h"
#include "File.h"
#include <sys/stat.h>
#include <string.h>
#include <sstream>

class HelperDir {
public:
    HelperDir();
    HelperDir(const HelperDir& orig);
    virtual ~HelperDir();
    
    Dir* read(std::string pathdir);
    
private:

};

#endif /* DIR_H */

