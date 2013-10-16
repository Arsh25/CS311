// da3.cpp (skeleton)
// Arsh Chauhan
// 10/11/2013
// For CS 311 Fall 2013
// Source file for Assignment 3

#include "da3.h"

//Pre-Conditions: 0 < n < size of (int)
//Post-Conditions: Returns number of steps before n = 1. Will not throw 
int collatz(int n)
{
	while (n != 1)
	{
	
		if( n % 2 == 0)
	{
		return 1+collatz(n/2);
	}
	else 
	{
		return 1+collatz((3*n)+1);
	}
	}
	return 0;
  
}
