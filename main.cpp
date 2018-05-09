/*
 * To change thfile license header, choose License Headers in Project Properties.
 * To change thfile template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Urbanovich Dzmitry
 *
 * Created on April 24, 2018, 10:29 PM
 */

#include <cstdlib>
#include "HelperDir.h"
#include "Dir.h"
#include "File.h"
#include "HelperThread.h"

#include <string.h>
#include <stdlib.h> 

#include <iostream>
#include <exception>

using namespace std;
 
/*
 * 
 */
int main(int argc, char** argv) {
    
    try {
        
        if (argc != 5) {
            throw "ERROR: most be 5 arguments.";
        }
        
        std::string src_path = argv[1];
        int sort_by = atoi(argv[2]);
        std::string desc_path = argv[3];
        int amount = atoi(argv[4]);
        
        struct stat info;
        stat(src_path.c_str(), &info);
        if (!S_ISDIR(info.st_mode)) {
            throw "ERROR: src_path is not exist.";
        }

        if (sort_by != 1 && sort_by != 2) {
            throw "ERROR: sort_by most be 1 or 2(1 - sort by size, 2 - sort by name).";
        }
        
        if (desc_path.empty()) {
            throw "ERROR: desc_path is not exist.";
        }
        
        if (!amount) {
            throw "ERROR: amount of threads is not exist.";
        }
        
        //set arguments
        HelperThread helper_thread(amount, src_path, desc_path);
        
        HelperDir *helper_dir = new HelperDir();
        //read src directory
        std::cout << "finding files in " << helper_thread.src_path << std::endl;
        Dir *d = helper_dir->read(helper_thread.src_path);

        char *sort = "";
        if (sort_by == 1) {
            sort = "size";
        } else if(sort_by == 2) {
            sort = "name";
        }
        std::cout << "sorting files by " << sort << std::endl;
        //sort files
        if (sort_by == 1) {

            File::sort_by_size(d->file);

        } else if(sort_by == 2) {

            File::sort_by_name(d->file);
        }

        //copy files
        std::cout << "copying files" << std::endl;

        helper_thread.copy(d->file);
        
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return -1;
    } catch (const char* msg) {
        std::cout << msg << std::endl;
        return -1;
    }
    
    return 0;
}