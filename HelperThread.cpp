/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelperThread.cpp
 * Author: setler
 * 
 * Created on May 8, 2018, 9:53 PM
 */

#include <math.h>

#include "HelperThread.h"

HelperThread::HelperThread() {
}

HelperThread::HelperThread(int amount, std::string src_path, std::string desc_path) {
    this->amount = amount;
    this->src_path = src_path;
    this->desc_path = desc_path;
}

HelperThread::HelperThread(const HelperThread& orig) {
}

HelperThread::~HelperThread() {
}

void HelperThread::copy_file_thread(bool &finished, File *f, std::string desc_path) {
    
    try {
        std::ifstream file(f->path, std::ifstream::binary);
        if (file) {
            // get length of file:
            file.seekg(0, file.end);
            int length = file.tellg();
            file.seekg(0, file.beg);

            char * buffer = new char [length];

            // read data as a block:
            file.read(buffer, length);

            std::ofstream newfile;
            mkdir(desc_path.c_str(), 0777);
            newfile.open (desc_path + "/" + f->name);
            newfile << buffer;
            newfile.close();

            std::cout << std::this_thread::get_id() << " | " << f->path << " | " << f->name << " | " << length << " byte;" << std::endl;

            if (file)
                std::cout << "all characters read successfully." << std::endl;
            else
                std::cout << "error: only " << file.gcount() << " could be read" << std::endl;
            file.close();

            delete[] buffer;

            finished = true;
        } else {
            finished = false;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void HelperThread::copy(File* f) {
    
    std::thread threads[this->amount];

    bool working[this->amount];
    for (int i = 0; i < this->amount; ++i) {
        working[i] = false;
    }
    
    int start_file = 0;
    int finished_file = 0;
    while (true) {
        
        //Launch a group of threads
        for (int i = 0; i < this->amount; ++i) {
            if (!working[i]) {
                File *file = File::get_file(start_file, f);
                threads[i] = std::thread(HelperThread::copy_file_thread, std::ref(working[i]), file, this->desc_path);
                start_file++;
            }
        }

        //Join the threads with the main thread
        for (auto& th : threads) {
            th.join();
        }
                
        for (int i = 0; i < this->amount; ++i) {
            if (working[i]) {
                working[i] = false;
                finished_file++;
            }
        }
        
        if (finished_file == (File::count(f))) {
            break;
        }
        
    }
}