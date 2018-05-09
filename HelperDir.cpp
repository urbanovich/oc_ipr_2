/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dir.cpp
 * Author: setler
 * 
 * Created on April 24, 2018, 10:31 PM
 */

#include "HelperDir.h"

#include <iostream>
#include <locale>

HelperDir::HelperDir() {
}

HelperDir::HelperDir(const HelperDir& orig) {
}

HelperDir::~HelperDir() {
}

Dir* HelperDir::read(std::string pathdir) {
    
    DIR *dp;
    struct dirent *d;
    
    Dir *dir = new Dir();
    dir->name = pathdir;
    dir->path = pathdir;
    
    static File *file = new File();
    dir->file = file;
    
    if ((dp = opendir(pathdir.c_str())) != NULL) {
        while((d = readdir(dp)) != NULL) {
            if(strcmp(".", d->d_name) == 0 ||
                strcmp("..", d->d_name) == 0)
                continue;
           
            std::string path = pathdir + "/" + d->d_name;
            
            struct stat buf;
            stat(path.c_str(), &buf);
                        
            if (S_ISDIR(buf.st_mode)) {

                Dir *tmp_dir = this->read(path);
                 
                int i_f = File::count(tmp_dir->file);
                if (i_f) {
                    File *last = File::get_file(i_f - 1, tmp_dir->file);
                    file = last->file;
                }
                
            } else if (S_ISREG(buf.st_mode)) {
                
                file->name = d->d_name;
                file->path = path;
                file->size = buf.st_size;
                
                file->file = new File();
                file = file->file;
                file->file = NULL;
            }
        }
        
    } else {
        std::cout << "can not open file: " << pathdir << std::endl;
    }
    
    closedir(dp);
    return dir;
}