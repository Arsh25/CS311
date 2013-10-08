/*
 * birthday.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: Arsh Chauhan
 *      C++ source file for Birthday class
 *      HW #1 CS 311 Fall 2013
 */

#include "birthday.h"

#include<sstream>
using std::ostringstream;
//Pre-condition: None
//Post-condition: returns true if lhs and rhs are not equal
bool operator!=(const Birthday &lhs, const Birthday &rhs) //canonical 
{
	return !(lhs==rhs);
}


//Pre-condition: None
//Post-condition: returns true if lhs and rhs are equal
bool operator==(const Birthday &lhs, const Birthday &rhs)
{
	return ((lhs.getName()==rhs.getName())&&(lhs.getDay()==rhs.getDay())&&(lhs.getMonth()==rhs.getMonth()));
}

//Pre-condition: User must pass a valid C++/C style string
//Post-condition: Sets _name for the object qeual to the passed string 
void Birthday::setName(string &name)
{
	_name=name;
}

//Pre-condition: User must create a constant Birthday type and pass a valid string to the appropriate Ctor
//Post-condition: sets _name member variable equal to the passed string
void Birthday::setName(const string &name)
{
	_name=name;
}

//Pre-condition: day must be a valid date i.e 1<=day<=30/31
//Post-condition: sets _day member variable equal to the passed unsigned int
void Birthday::setDay(unsigned int day)
{
	_day=day;
}

//Pre-condition: Month must be a valid month i.e 1<=month<=12 
//Post-condition: sets _month member variable equal to the passed unsigned int
void Birthday::setMonth(unsigned int month)
{
	_month=month;
}

//Pre-condition: None
//Post-condition: returns _name as a C++ string
string Birthday::getName() const 
{
	return _name;
}

//Pre-condition: None
//Post-condition: returns _day as an int between 1 and 31
int Birthday::getDay() const
{
	return _day;
}

//Pre-condition: None
//Post-condition: returns _month as an int between 1 and 12
int Birthday::getMonth() const
{
	return _month;
}

//Pre-condition: os must be in a good state
//Post-condition: has written rhs to os in format _name (" month " " month as 3 letter abbrevation")"
ostream &operator<<(ostream &os, const Birthday &rhs)
{
	return os << rhs.toString();
}

// Pre-condition: None
// Post-condition: Return data in format name (" month " " month as 3 letter abbrevation")" in string form
string Birthday::toString() const
{
	string month;

	//logic to determine 3 letter abbrevation based on month stored as a number
	switch(_month) 
		{
	case 1: month="Jan";
				break;
	case 2: month="Feb";
			break;
	case 3: month="Mar";
			break;
	case 4: month="Apr";
		break;
	case 5: month="May";
		break;
	case 6: month="Jun";
		break;
	case 7: month="Jul";
		break;
	case 8: month="Aug";
		break;
	case 9: month="Sep";
		break;
	case 10: month="O";
		break;
	case 11: month="Nov";
		break;
	case 12: month="Dec";
	}
	ostringstream os;
	os << _name <<" (" << month <<" "<< _day <<")";

	return os.str();
}


