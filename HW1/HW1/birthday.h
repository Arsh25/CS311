/*
 * birthday.h
 *
 *  Created on: Sep 25, 2013
 *      Author: Arsh Chauhan
 *      C++ header file for Birthday class
 *      HW #1 CS 311 Fall 2013
 */
#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include<string>
using std::string;
#include<iostream>
using std::ostream;

//Class Invariant
	// _name must be a valid C++/C string
	// 1<= _day <= 30/31
	// 1<= _month <=12

class Birthday
{
	string _name;
	unsigned int _month;
	unsigned int _day;
public:

	/* This class uses compliler generated Copy Ctor, Copy Assignment and Dtor*/

	Birthday():_name(""),_month(1),_day(1){}; // Default contructor sets name to empty string and date to 1st Jan
	Birthday(const string &name, int month, int day):_name(name),_month(month),_day(day){}; // 3 parameter constructor, user passes name,month and day
	string getName() const;
	int getMonth() const;
	int getDay() const;
	void setName(string&);
	void setName(const string&);
	void setMonth(unsigned int);
	void setDay(unsigned int);
	string toString() const;
};
bool operator!=(const Birthday&, const Birthday&);
bool operator==(const Birthday&, const Birthday&);
ostream & operator<<(ostream &os, const Birthday&);





#endif
