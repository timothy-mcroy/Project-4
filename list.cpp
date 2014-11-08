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
    p_capacity=1;
    p_data = new Book * [p_capacity];
    for (int i = 0 ; i< p_capacity; i++)
        p_data[i] = NULL;
}


//Constructor with size parameter
List::List(int size)
{
    p_size = 0;
    p_capacity = size* 2;
    p_data = new Book * [p_capacity];
    for (int i = 0 ; i< p_capacity; i++)
        p_data[i] = NULL;
}



//Destructor
List::~List()
{
 for (int i = 0; i<p_size;i++)  //Likely going to be an error on this line, but I think it's supposed to be structured like this.
	{
 	delete p_data[i];  //We have to free each individual element in the list.
 	}
 }


 //Copy Constructor
 List::List(const List & list)
 {
    p_size = list.p_size;
    p_capacity = list.p_capacity;

    p_data = new Book*[list.p_size];

    for (int i = 0; i< list.p_size; i++)
    {
        append(*(list.p_data[i]));  //This is currently a deep copy.
        p_size =-1;                         //Need to account for the size increase in append()
    }
}


int List::size() const
{
    return p_size;
}

void List::append(const Book item)
{
    p_size +=1;
    if (p_size > p_capacity)
    {
        p_resize();
    }
    Book * book = new Book(item);
    p_data[p_size-1] = book;

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


int List::index(const Book &item) const
{
    for(int i = 0; i<p_size;i++)
    {
        if (*(p_data[i] )== item)
        {
            return i;
        }
    }
    return -1;
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
            delete p_data[i];

            break;
        }
    }
    if (found)
    {
        for (int i = idx+1;i<p_size;i++)
            {
                p_data[i-1] = p_data[i];                //shift everything else in the list one to the right
            }
    p_data[p_size] = NULL;
    p_size -=1;
    }
    if (p_size < p_capacity /2 )
    {
        p_resize();
    }
     return found;
}





Book & List::operator[](int idx) const
{
    if (idx < 0)  //Allowing for negative indexing as in python.  Because python is awesome.
    {
        idx = p_size - idx;
    }
    if(p_data[idx]==NULL) // These lines handle assignment by index.
    {
        if (idx <= p_size)
            {
                p_data[idx]= new Book(); //The best we can do since Book can't have an assignment operator
            }
        else
        {
            std::cout<<"List index out of range! Aborting program"<<std::endl;
        }

    }
    return *(p_data[idx]);

}



void List::p_resize()
{
    if (p_size >= p_capacity)
     {

        p_capacity = p_capacity * 2;
        //scale up code here  //use copy constructor for model
        Book ** new_data = new Book*[p_capacity];
        for (int i = 0; i< p_size; i++)
        {
            new_data[i] = p_data[i]; //Copying only the pointers
         }
        p_data = new_data;
    }
    else if (p_size < p_capacity /2)
    {
        p_capacity = p_capacity /2;
        //scale down code here
        Book ** new_data = new Book*[p_capacity];

        for (int i = 0; i< p_size; i++)
        {
            new_data[i] = p_data[i]; //Copying only the pointers
         }
         p_data = new_data;

    }
    for(int i=p_size;i<p_capacity;i++)
    {
        p_data[i] = NULL;
    }
}


std::ostream & operator<<(std::ostream & os, const List & listy)
{
    if (&listy==NULL)
    {
        os<< "list has not been instantiated!";
        return os;
    }
    os<<"[";
    for (int i = 0; i< listy.size()-1;i++)
        {
            os<<listy[i]<<" , "<<std::endl;
        }
    os<<listy[listy.size()-1]<<"]";
    return os;
}








