//Aaron Lincoln
//
//
//A hash table to store activities with
//all their data in. Hashed by location,
//search by location, display by location,
//and remove by location. Implemented with
//and array of linear linked lists.

#include "activities.h"

//LLL with a activities as the data
struct node
{
    activities activity;
    node * next;
};

class table
{
    public:
        table();
        ~table();
        int insert( char * key, const activities & to_add);
        int retrieve( char * to_find, activities & found);
        int display_all();
        int display( char * location);
        int remove(char * location);

    private:
        node ** hash; //dynammically allocated array of head pointers
        int hash_table_size;
        int location_key( char * key);
};
