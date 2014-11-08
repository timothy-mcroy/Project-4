//
//  book.cpp
//  Project4
//
//  Created by Timothy McRoy 11/5/2014
//  Copyright (c) 2014 Timothy McRoy. All rights reserved.
//
#include "book.h"

Book::Book()
{
    m_isbn    = "";
    m_title    = "";
    m_author = "";
    m_rating  = -1.0;
    m_year    = -1;

}


Book::Book(std::string isbn, std::string title, std::string author, int year, float rating)
{
    m_isbn    = isbn;
    m_title    = title;
    m_author = author;
    m_rating  = rating;
    m_year    = year;
}

Book::~Book()
{

}



//Getter Methods

int Book::year() const
{
    return m_year;
}

std::string Book::isbn() const
{
    return m_isbn;
}

std::string Book::author() const
{
    return m_author;
}

std::string Book::title() const
{
    return m_title;
}

float Book::rating() const
{
    return m_rating;
}



//Comparison operators
//== and != compare all of the elements, where the < <= > >= only compare rating.

bool Book::operator==(const Book & b) const
{
    return (m_isbn == b.m_isbn && m_author ==b.m_author && m_rating == b.m_rating && m_title ==b.m_title && m_year == b.m_year);
}




std::ostream & operator<<(std::ostream & os, const Book & b)
{
    if (&b==NULL)
    {
        os<< "b is not a valid book right now";
        return os;
    }
    os << "Title, Author, Year, ISBN, Rating = "<< b.m_title<<", "<<b.m_author<<", "<<b.m_year<<", "<<b.m_isbn<<", "<<b.m_rating;
    return os;
}
/*
bool Book::operator!=(const Book & b) const
{
    return (m_isbn != b.m_isbn && m_author !=b.m_author && m_rating != b.m_rating && m_title !=b.m_title && m_year != b.m_year);
}

//comparing only rating from here on.

bool Book::operator<(const Book & b) const
{
    return m_rating < b.m_rating;
}

bool Book::operator>(const Book & b) const
{
    return m_rating > b.m_rating;
}
bool Book::operator<=(const Book & b) const
{
    return m_rating <= b.m_rating;
}

bool Book::operator>=(const Book & b) const
{
    return m_rating >= b.m_rating;
}
*/




