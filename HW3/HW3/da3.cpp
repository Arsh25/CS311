// da3.cpp (skeleton)
// Arsh Chauhan
// 10/11/2013
// For CS 311 Fall 2013
// Source file for Assignment 3

#include "da3.h"


int collatz(int n)
{
	while (n != 1)
	{
	
		if( n % 2 == 0)
	{
		n = n/2;
		return 1+collatz(n);
	}
	else 
	{
		n = (3*n)+1;
		return 1+collatz(n);
	}
	}
	return 0;
      // Dummy return, so that it compiles
               // Eliminate this return statement!
    // WRITE THIS!!!
}
