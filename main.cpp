//
//  main.cpp
//  Project4
//
//  Created by Jason Alan Fries on 10/21/14.
//  Copyright (c) 2014 University of Iowa. All rights reserved.
//

#include <iostream>
#include "list.h"
#include "loadfile.h"
#include "book.h"

int main( int argc, const char * argv[] ) {

    // create and populate your list using this function call
    List list = List();
    char *filename = "E:\\Code\\Programming Languages and Tools\\Project 4\\Project4\\bin\\Debug\\test_subset.tsv";
    //std::cout<<filename<<std::endl;
    load_book_data(argv[1], list);
    //std::cout<<list<<std::endl;
    return 0;
}


