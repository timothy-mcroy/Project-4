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
    load_book_data("test_subset.tsv", list);
    std::cout<<"I hope that this still runs!"<<std::endl;
    return 0;
}
