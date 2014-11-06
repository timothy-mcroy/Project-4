//
//  list.cpp
//  Project4
//
//  Created by Timothy McRoy
//  Copyright (c) 2014 Timothy McRoy . All rights reserved.
//


//Default Constructor

#include "list.h"

List::List()
{ 
    p_size = 1;
    p_capacity=2;
    p_data = new Book * [p_capacity];
    for (int i = 0 ; i< p_capacity; i++)
        p_data[i] = NULL;
}


//Constructor with size parameter
List::List(int size)
{
    p_size = size;
    p_capacity = size* 2;
    p_data = new Book * [p_capacity];
    for (int i = 0 ; i< p_capacity; i++)
        p_data[i] = NULL;
}



//Destructor
List::~List()
{
 for (int i = 0; i<p_size+1;i++)  //Likely going to be an error on this line, but I think it's supposed to be structured like this.
 delete *(p_data[i]);  //We have to free each individual element in the list.
 delete p_data[i];
 }
 
 
 //Copy Constructor
 List::List(const List & list)
 {
    p_size = list.p_size;
    p_capacity = list.p_capacity;
    
    p_data = new Book*[list.p_size];
    
    for (int i = 0; i< list.p_size; i++)
    {
        this.append(*(list.p_data[i]));  //This is currently a deep copy. 
        this.size =-1;                         //Need to account for the size increase in append()
    }
}



void List::append(const Book item)
{
    p_size +=1;
    if (p_size > capacity)
    {
        this.resize();
    }
    Book * book = new Book;
    book = item;
    *(p_data[p_size]) = book;
}



bool List::contains(Book item) const
{
    for(int i= 0; i<p_size;i++)
    {
        if (*(p_data[i] )== item)
        {
            return true;
        }
    }
    return false;

}



bool List::remove(Book item)
{   
    bool found = false;
    int idx;
    for (int i =0; i< p_size;i++)
    {
        if (*(p_data[i]) == item) 
        {
            //deletion code here
            idx = i;
            found = true;
            delete *(p_data[i])
            
            break;
        }
    }
    if (found)
    {
        for (int i = idx+1;i<p_size;i++)
            {
                p_data[i-1] = p_data[i];                //shift everything else in the list one to the right
            }
    delete p_data[p_size];
    
    p_size =p_size-1;
    }
    if (p_size < capacity /2 ) 
    {
        this.resize()
    }
     return found;
}



int List::size()
{
    return p_size;
}

Book & List::operator[](int idx) const
{
    if (idx < 0)  //Allowing for negative indexing as in python.  Because python is awesome.
    {
        idx = p_size - idx;
    }
     return *(p_data[idx]);
    
}


void List::resize()
{
    int new_capacity;
    if (p_size <= p_capacity)
     {
        new_capacity = p_capacity * 2;
        //scale up code here  //use copy constructor for model
     }
    else if
    {
        p_capacity = p_capacity /2;
        //scale down code here
    }
    











