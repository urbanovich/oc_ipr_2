/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelperThread.h
 * Author: setler
 *
 * Created on May 8, 2018, 9:53 PM
 */

#ifndef HELPERTHREAD_H
#define HELPERTHREAD_H

#include <cstdlib>
#include <iostream>
#include <thread>
#include <fstream>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <exception>

#include "File.h"

class HelperThread {
public:
    
    int amount = 6;
    std::string src_path;
    std::string desc_path;

    static void copy_file_thread(bool &finished, File *f, std::string desc_path);
    void copy(File *f);
    
    HelperThread();
    HelperThread(int amount, std::string src_path, std::string desc_path);
    HelperThread(const HelperThread& orig);
    virtual ~HelperThread();
private:

};

#endif /* HELPERTHREAD_H */

