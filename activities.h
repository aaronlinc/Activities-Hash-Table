//Aaron Lincoln
//
//
//A class of activites lets the user add an
//activity, display it, and match it by location;

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>


#ifndef ACTIVITIES
#define ACTIVITIES
class activities
{
	public:
		activities(void);
		~activities(void);
                //Adds two arrays to the private data membors
                //question and answer.
                int add_activities(char * name, char * description, char * location, int difficulty, char gear);
		int copy(const activities & new_activities); //Deep copy of arguments data 
                                                             //to class data members.
		int display(void); //Displays question
                int match( char * location); //Checks if user answer passed
                                             //in is a match to answer
	
        private:
            char * name;
            char * description;
            char * location;
            int difficulty;//Difficulty 1 to 5, 1 being easy 5 being hard
            char gear; // Gear reaquired (y,n)
};
#endif
