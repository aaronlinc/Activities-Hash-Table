//Aaron Lincoln
//
//
//Loads data from file into activities hash table
//Lets the user interact with the table. Such as 
//displaying all, displaying by location, searching
//by location, and removing by location.

#include "table.h"
using namespace std;

//Prototypes
int load_activities(activities & to_add, table & hash );

int main()
{
    activities to_add, found;
    table hash;
    char response = 'y';
    char * user_inp = new char[50];

    load_activities(to_add, hash);
    
    do{
        //User Interface
        //Display all activities
        cout << "Display all actvities? (y,n): ";
        cin >> response; cin.ignore(100, '\n');
        if(tolower(response) == 'y')
            hash.display_all();
        //Display by location
        cout << "Display actvities by location? (y,n): ";
        cin >> response; cin.ignore(100, '\n');
        if(tolower(response) == 'y')
        {
            cout << "Enter a location: ";
            cin.get(user_inp, 50, '\n'); cin.ignore(100, '\n');
            if(!hash.display(user_inp))
                cout << "Not Found!\n";
        }
        //Search and display
        cout << "Search actvities by location? (y,n): ";
        cin >> response; cin.ignore(100, '\n');
        if(tolower(response) == 'y')
        {
            cout << "Enter a location: ";
            cin.get(user_inp, 50, '\n'); cin.ignore(100, '\n');
            if(hash.retrieve(user_inp, found))
                found.display();
            else
                cout << "Not found!\n";
        }
        //Remove by location
        cout << "Remove actvities by location? (y,n): ";
        cin >> response; cin.ignore(100, '\n');
        if(tolower(response) == 'y')
        {
            cout << "Enter a location: ";
            cin.get(user_inp, 50, '\n'); cin.ignore(100, '\n');
            if(hash.remove(user_inp))
                cout << "Item removed!\n";
            else
                cout << "Not found!\n";
        }
   
        cout << "Run program again? (y, n): ";
        cin >> response; cin.ignore(100, '\n');

    }while(tolower(response) == 'y'); 

    return 0;    
}
// Loads activitiess from external file "activities.txt" 
// into the hash table.
int load_activities(activities & to_add, table & hash )
{
    ifstream fin;
    char * name = new char[45];
    char * description = new char[150];
    char * location = new char[21];
    int difficulty = 0;
    char gear = 'Y';
    char * key;

    fin.open("activities.txt");
    if(fin)
    {
	fin.get(name,45, ':');
	while(!fin.eof())
	{
	    fin.ignore(100,':');
            fin.get(description, 150, ':');
            fin.ignore(150,':');
            fin.get(location, 21, ':');
	    fin.ignore(100,':');
            fin >> difficulty;
	    fin.ignore(100,':');
            fin >> gear;
            fin.ignore(100,'\n');
            key = new char[strlen(location) +1];
            strcpy(key, location);
            to_add.add_activities(name, description, location, difficulty, gear);
            hash.insert(key, to_add);
            delete [] key;
            name = new char[45];
            description = new char[150];
            location = new char[21];
            fin.get(name,45, ':');
	} 
    }fin.close();
    return 1;
}

