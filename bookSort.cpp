/*

    bookSort.cpp
    Created by Timothy McRoy
    11/8/14
*/

#include "bookSort.h"
void bookSort(List & list)
{
    int i, j;
    Book tmp;
    for (i=1;i<list.size();i++)
    {
        j=i;
        while(j>0 && list[j-1].rating()>list[j].rating())
        {
            tmp       = list[j];
            list[j]   = list[j-1];
            list[j-1] = tmp;
            j-=1;
        }
    }
}



/*

//Couldn't get this to work right.  I spent way too much time on it.
void bookMerge(List &list, int start, int finish, int middle)
{
    List tmp = List();
    int i = start;
    int j = middle;
    while (i<=middle && j<=finish)
    {
        if ((list[i].rating()) <= (list[j].rating()))
        {
            std::cout<<list[i].rating()<<" <= "<<list[j].rating()<<std::endl;
            tmp.append(list[i]);
            i+=1;
        }
        else
        {
            std::cout<<list[i].rating()<<" > "<<list[j].rating()<<std::endl;
            tmp.append(list[j]);
            j+=1;

        }
    }
    if(tmp.size()>0 && tmp.size()<15)
        //std::cout<<tmp<<std::endl;

    while (i<=middle)
    {
        tmp.append(list[i]);
        i+=1;
    }
    while(j<finish)
    {
        tmp.append(list[j]);
        j+=1;
    }
    for (int k = 0; k<tmp.size();k++)
    {
        list[k] = tmp[k];
    }
    if(tmp.size()>1)
    {
        std::cout<<"Final tmp ="<<tmp<<std::endl;
    }
}


void bookSort(List &list, int start=0, int finish=-1)
{
    if(finish ==-1)
    {
        finish = list.size() -1;
    }
    int middle;
    if (start < finish)
    {
        middle = (start+finish) /2;

        bookSort(list, start, middle);
        bookSort(list, middle+1,finish);
        //std::cout<<"Merging section ["<<start<<":"<<middle<<"] with section ["<<middle+1<<":"<<finish<<"]"<<" to make ["<<start<<":"<<finish<<"]"<<std::endl;
        bookMerge(list, start, finish, middle);
    }
}
*/
