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
    int size() const;

    Book & operator[](int idx) const;
};


#endif

/* use the following as a guide to deleting data associated with the array of pointers
int ** arrayPtr = new int*[2];
int * b = new int;
*b = 7;
int * second = new int;
*second = 12;
arrayPtr[0] = b;
arrayPtr[1] = second;


for (int i = 0; i<2; i++)
    cout<< *(arrayPtr[i]) <<endl;

int * g = b;
delete [] arrayPtr;

for (int i = 0 ; i<2; i++)
     delete arrayPtr[i];

cout<<*second<<endl;
*/

