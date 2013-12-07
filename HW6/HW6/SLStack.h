#ifndef SLStack_H
#define SLStack_H

#include "slist.h"

template<class T>
class SLStack
{

public:

typedef T value_type;

SLStack();						// default ctor //
SLStack(const SLStack &orig); 	// copy constructor //
~SLStack();						// destructor //

bool empty();					// returns a bool indicating if Stack is empty //
bool empty() const;
SLStack & top();				// returns a reference to item on Top of Stack //
SLStack & top() const;
void push(value_type);			// moves inputted value to stack //
void pop();						// gives back the top item on stack //

private:
SList<T> * ptr; 					// pointer to stack
};

template<class T>
SLStack<T>::SLStack()
{
top = 0;
}

template<class T>
SLStack<T>::SLStack(const SLStack &orig)
{
}

template<class T>
SLStack<T>::~SLStack()
{
}

template<class T>
bool SLStack<T>::empty()
{
if (top == 0) { return true; }		// nothing on the stack? return true //
else { return false; }				// something is there? return false //
}

// pre-conditions: stack exists //
// post-conditions: returns reference to what ever was at the top of the stack //
template<class T>
SLStack<T> & SLStack<T>::top()
{
	return (value_type p);
}

// pre-conditions: none
// post-conditions input data is moved to top of stack //
template<class T>
void SLStack<T>::push(value_type a)
{
/*
SList * p = new SList(a);			// something I found on the internet //
p -> next=top;						// may not even be good //
top = p;
*/
}

// pre-conditions:
// post-conditions:
template<class T>
void SLStack<T>::pop()		// should we be calling SLStack::top() here? //
{							 
/*
SList * p = top;
top = top->next;				// I'll admit I don't know what's going on here //
value_type x=p->_data;			// some stuff I found online //
delete p;
*/
}

#endif