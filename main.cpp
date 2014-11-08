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
#include "bookSort.h"

int main( int argc,  char * argv[] ) {

    // create and populate your list using this function call
    List list = List();
    //char *filename = argv[1];
    load_book_data(argv[1], list);
    bookSort(list);
    std::cout<<list<<std::endl;
    return 0;
}


