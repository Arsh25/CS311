// da3.h (Skeleton)
// Arsh Chauhan
// 10/11/2013
// 

// For CS 311 Fall 2013
// Header file for Assignment 3

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <iostream>   // for std::ostream
#include <string>     // for std::string
#include <stdexcept>  // for std::out_of_range
#include <algorithm>  // for std::equal


// *************************************************************** // *
// Begin DO-NOT-CHANGE section                                     // *
// Do not alter the lines below                                    // *
// *************************************************************** // *
                                                                   // *
                                                                   // *
// struct LLNode                                                   // *
// Linked List node, with client-specified value type              // *
// Invariants:                                                     // *
//     Either next_ is NULL, or next_ points to an LLNode,         // *
//      allocated with new, owned by *this.                        // *
template <typename ValueType>                                      // *
struct LLNode {                                                    // *
    ValueType data_;  // Data for this node                        // *
    LLNode * next_;   // Ptr to next node, or NULL if none         // *
                                                                   // *
    // The following simplify creation & destruction               // *
                                                                   // *
    // 1- & 2-param ctor                                           // *
    // Pre:                                                        // *
    //     theNext, if passed, is either NULL,                     // *
    //      or else it points to an LLNode, allocated with new,    // *
    //      with ownership transferred to *this.                   // *
    // Post:                                                       // *
    //     data_ == theData.                                       // *
    //     If next_ passed, then next_ == theNext.                 // *
    //      otherwise, next_ is NULL.                              // *
    explicit LLNode(const ValueType & theData,                     // *
                    LLNode * theNext = NULL)                       // *
        :data_(theData), next_(theNext)                            // *
    {}                                                             // *
                                                                   // *
    // dctor                                                       // *
    // Pre: None.                                                  // *
    // Post: None. (next_ delete'd)                                // *
    ~LLNode()                                                      // *
    { delete next_; }                                              // *
};                                                                 // *
                                                                   // *
                                                                   // *
// *************************************************************** // *
// End DO-NOT-CHANGE section                                       // *
// Do not alter the lines above                                    // *
// *************************************************************** // *


template <typename T>
T listItem(const LLNode<T> * head,
           int index)
{
	int i=0;
	bool found = false;
	while (head != NULL)
	{
		if (i == index)
		{
			found = true;
			return (head->data_);
		}
		else
		{
			i++;
			head = head->next_;
		}
	}

	if (!(found))
	{
		throw std::out_of_range(" out of range error, T list item");
	}

     //Dummy return, so that it compiles
                 // Elminate this return statement!
    // WRITE THIS!!!
}


template <typename Func>
void didItThrow(Func f,
                bool & threw)
{
	threw = false;
	
	try 
	{
		f();
		
	}
	catch (...)
	{
		threw = true;
		throw; 
	}

}


template <typename FDIter>
void printRange(FDIter first,
                FDIter last,
                std::ostream & theStream)
{
	for ( auto ii = first; ii != last; ii++)
	{
		theStream << *ii <<"\n";
	}

    // WRITE THIS!!!
}


template <typename FDIter>
bool rangesEqual(FDIter first1,
                 FDIter last1,
                 FDIter first2)
{
    // WRITE THIS!!! (And use ONE function call and NOTHING ELSE.)
	return std::equal( first1, last1, first2);
}


int collatz(int n);


#endif  //#ifndef FILE_DA3_H_INCLUDED

