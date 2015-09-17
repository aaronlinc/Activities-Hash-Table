//Aaron Lincoln
//
//
//Allows the insertion of a activity with
//the data of a name, description, location, 
//difficulty, and gear required. Data can 
//be displayed and checked for a match
//based on location.
//
#include "activities.h"
using namespace std;

//Constructor
activities::activities(void)
{
    name = new char[45];
    description = new char[150];
    location = new char[21];
    difficulty = 0;
    gear = 'Y';
}

//Destructor
activities::~activities(void)
{
    if(name)
        delete [] name;
    if(description)
        delete [] description;
    if(location)
        delete [] location;
}

//Add activity data arguments to the data 
//members in the class activities.
int activities::add_activities(char * name, char * description, char * location, int difficulty, char gear)
{
    activities to_copy; //activities class to copy data from
    
    to_copy.name = name;
    to_copy.description = description;
    to_copy.location = location;
    to_copy.difficulty = difficulty;
    to_copy.gear = gear;
    copy( to_copy); //copies to_copy's data members
                    //to class data members.
    return 1;
}

//Deep copy of the arguments data members to 
//the class data members.
int activities::copy(const activities & new_activities)
{
    if(!new_activities.name || !new_activities.description)
        return 0;
    if(name)
        delete [] name;
    name = new char[strlen(new_activities.name) + 1];
    strcpy(name, new_activities.name);
    if(description)
        delete [] description;
    description = new char[strlen(new_activities.description) + 1];
    strcpy(description, new_activities.description);
    if(location)
        delete [] location;
    location = new char[strlen(new_activities.location) + 1];
    strcpy(location, new_activities.location);

    difficulty = new_activities.difficulty;
    gear = new_activities.gear;

    return 1;
}

//Displays the activity data.
int activities::display(void)
{
    cout << "\nName: " << name << "\nDescription: "
         << description << "\nLocation: " << location
         << "\nDifficulty (1 - 5): " << difficulty
         << "\nGear: (Y, N) " << gear << endl;
    return 1;
}
//Checks for a match in the location.
//Returns 1 if match, 0 if no match.
int activities::match( char * match)
{
    if( strcmp(match, location) == 0)
        return 1;
    return 0;
}
