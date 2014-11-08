//
//  list.h
//  Project4
//
//  Created by Jason Alan Fries on 10/17/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//
/*

Modified by Timothy McRoy on 11/1/14

*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "book.h"

class List {

private:
    Book ** p_data;
    int p_size;                                 //Using p_ as a naming convention for private variables
    int p_capacity;
    void p_resize();
public:
    List();                                      //Default Constructor
    List(int size);                            // Constructor
    ~List();                                   //Destructor

    List(const List & list);                //Copy constructor
    void append(Book item);
    bool remove(Book item);
    bool contains(Book item) const;
    int index(const Book &item) const;
    int size() const;
    void sort();
    Book & operator[](int idx) const;
    List operator=(const List & list);
    friend std::ostream & operator<<(std::ostream & os, const List & listy);
};


#endif


