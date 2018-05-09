/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File.h
 * Author: setler
 *
 * Created on April 25, 2018, 2:32 PM
 */

#ifndef FILE_H
#define FILE_H

#include <cstddef>
#include <iostream>
#include <string.h>

class File {
public:
    File();
    File(const File& orig);
    virtual ~File();
        
    //the next file in a dir
    File *file;
    
    std::string name = "";
    std::string path = "";
    int size = 0;
    
    static File * sort_by_name(File * files);
    static File * sort_by_size(File * files);
    
    int partition_by_name(File *file, int l, int h);
    int partition_by_size(File *file, int l, int h);
    void qsort_by_name(File *file, int l, int h);
    void qsort_by_size(File *file, int l, int h);
    
    static File * get_file(int i, File *file);
    static void set_file(int i, File *file, File *files);
    static int count(File *file);
    
private:

};

#endif /* FILE_H */

