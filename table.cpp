//Aaron Lincoln
//
//
//Hash table of activites implemented using
//and array of linear linked lists where the 
//array size is a prime number. The table is 
//keyed by location using the private function
//location_key. 

#include "table.h"
using namespace std;

//Constructor
table::table()
{
    hash_table_size = 21;
    hash = new node * [hash_table_size];
    
    for(int i = 0; i < hash_table_size; ++i)
        hash[i] = NULL;
}
//Destructore
table::~table()
{
    for( int i = 0; i < hash_table_size; ++i)
    {
        if(hash[i])
        {
            node * temp;
            while(hash[i])
            {
                temp = hash[i] -> next;
                delete hash[i];
                hash[i] = temp;
            }
        }
    }
}

//Private hash key function.
int table::location_key( char * key)
{
    //hash key
    int length = strlen(key);
    int index = 0;
    for(int i = 0; i < length; ++i)
    {
        if( i == 0 || i == 2)
            index += (key[i] * 43);
        if( i == 4 || i == 5)
            index += (key[i] * 3);
    }
    return index % hash_table_size;
}

//Inserts the argument to_add into the hash table 
//by using the key location passed in to find an
//index and then added to the front of the linear
//linked list.
int table::insert( char * key, const activities & to_add)
{
    int index;
    index = location_key(key);

    //add to table
    node * temp;
    if(!hash[index])
    {
        hash[index] = new node;
        hash[index] -> activity.copy(to_add);
        hash[index] -> next = NULL;
        return 1;
    }
    temp = new node;
    temp -> activity.copy(to_add);
    temp -> next = hash[index];
    hash[index] = temp;
    return 2;
}

//Returns 0 if there is no match on the to_find passed in. 
//Returns 1 and copies activity information into found
//activities class.
int table::retrieve( char * to_find, activities & found)
{
    int index;
    index = location_key(to_find);
    
    if(!hash[index])
        return 0;
    node * current = hash[index];
    while(current)
    {
        if( current -> activity.match(to_find))
        {
            found.copy(current -> activity);
            return 1;
        }
        current = current -> next;
    }
    return 0; 
}
//Displays all of the hash table
int table::display_all()
{
    node * current;
    for(int i = 0; i < hash_table_size; ++i)
    {
        current = hash[i];
        while(current)
        {
            current -> activity.display();
            current = current -> next;
        }
    }
    return 1;
}
//Displays base on the location passed in
//returns 0 if nothing to display;
int table::display( char * location )
{
    int index;
    index = location_key(location);
    
    if(!hash[index])
        return 0;
    node * current = hash[index];
    while(current)
    {
        if( current -> activity.match(location))
        {
            current -> activity.display();
            return 1;
        }
        current = current -> next;
    }
    return 0; 

}
//Removes based on location passed in
//returns a 1 if removed and 0 if not.
int table::remove( char * location )
{
    int index;
    node * temp;
    node * previous = NULL;
    index = location_key(location);
    
    if(!hash[index])
        return 0;
    if( hash[index] -> activity.match(location))
    {
        temp = hash[index] -> next;
        delete hash[index];
        hash[index] = temp;
        return 1;
    }
    node * current = hash[index];
    while(current)
    {
        if( current -> activity.match(location))
        {
            temp = current -> next;
            previous -> next = temp;
            delete current;
            current = NULL;
            return 1;
        }
        previous = current;
        current = current -> next;
    }
    return 0;
}



