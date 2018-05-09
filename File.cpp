/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File.cpp
 * Author: setler
 * 
 * Created on April 25, 2018, 2:32 PM
 */

#include "File.h"

File::File() {
}

File::File(const File& orig) {
}

File::~File() {
}

File* File::get_file(int i, File *file) {
    int index = 0;
    File *f;
    f = file;
    while (f->file != NULL) {
        
        if (index == i) {
            
            break;
        }
        
        f = f->file;
        index++;
    }
    
    return f;
}

void File::set_file(int i, File *file, File *files) {
    int index = 0;
    File *f, *prev, *next, *copy;
    f = files;
    prev = f;
    while (f->file != NULL) {
        
        if (index == i) {
            
            if (index != 0) {
                copy = new File();
                copy->file = next;
                copy->name = file->name;
                copy->path = file->path;
                copy->size = file->size;
                prev->file = copy;
                /*delete f;*/
            } else {
                f->name = file->name;
                f->path = file->path;
                f->size = file->size;
            }
                                        
            break;
        }
        
        prev = f;
        f = f->file;
        next = f->file;
        
        index++;
    }
}

int File::count(File *file) {
    int index = 0;
    File *f;
    f = file;
    while (f->file != NULL) {
        f = f->file;
        index++;
    }
    
    return index;
}

File * File::sort_by_name(File* files) {
    int count = File::count(files);
    files->qsort_by_name(files, 0, count - 1);
}

int File::partition_by_name(File *files, int l, int h) {
    File *ai, *aj;
    File *f = File::get_file(l, files);
    std::string p = f->name;
    int i = l - 1;
    int j = h + 1;
    while (true) {
        do {
            i++;
            ai = File::get_file(i, files);
        } while (ai->name < p);
        
        do {
            j--;
            aj = File::get_file(j, files);            
        } while (aj->name > p);
        
        if (i >= j) {
            return j;
        }
        
        File::set_file(j, ai, files);
        File::set_file(i, aj, files);
    }
}

void File::qsort_by_name(File *file, int l, int h) {
    
    if (l < h) {
        int p = partition_by_name(file, l, h);
        qsort_by_name(file, l, p);
        qsort_by_name(file, p + 1, h);
    }
}

File * File::sort_by_size(File* files) {
    int count = File::count(files);
    files->qsort_by_size(files, 0, count - 1);
}

int File::partition_by_size(File *files, int l, int h) {
    File *ai, *aj;
    File *f = File::get_file(l, files);
    int p = f->size;
    int i = l - 1;
    int j = h + 1;
    while (true) {
        do {
            i++;
            ai = File::get_file(i, files);
        } while (ai->size < p);
        
        do {
            j--;
            aj = File::get_file(j, files);
        } while (aj->size > p);
        
        if (i >= j) {
            return j;
        }
        
        File::set_file(j, ai, files);
        File::set_file(i, aj, files);
    }
}

void File::qsort_by_size(File *file, int l, int h) {
    
    if (l < h) {
        int p = partition_by_size(file, l, h);
        qsort_by_size(file, l, p);
        qsort_by_size(file, p + 1, h);
    }
}