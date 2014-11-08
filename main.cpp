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
    char filename[] = "test_subset.tsv";
    load_book_data(filename, list);
    return 0;
}


