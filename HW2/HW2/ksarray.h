/*Arsh Chauhan
CS-311 HW 2
header file for templated class KSArray
*/


#ifndef KSARRAY_H
#define KSARRAY_H

#include<algorithm>
using std::copy;

template <class T>

// Class Invariants: 
//0<= _size
// operators ==, !=, < should be deifned 

class KSArray 
{
	
public:
	typedef std::size_t size_type ;
	typedef T value_type;
	KSArray ();
	KSArray(size_type num);// 1 parameter Ctor, sets size equal to num
	KSArray( size_type, value_type val); // 2 parameter Ctor, sets all locations equal to val
	KSArray(const KSArray &); // Copy Ctor, performs deep copy
	~KSArray(); // Dtor
	size_type size() const; //Returns size of array
	value_type * begin() ; // Returns address of first element
	value_type *end(); // Retruns Address of last element
	const value_type *begin()const ; // begin for const array
	const value_type *end() const; // end() for const array 

	value_type & operator[](size_type index);
	const value_type & operator[](size_type index)const ;
	KSArray &operator=(const KSArray &rhs);
private:
	size_type _size; // Stores size of array
	value_type *_ptr; //Stores address to each element


};

template <class T>
bool operator == (const KSArray<T>& lhs, const KSArray<T>& rhs); // protoype for operator ==

template <class T>
bool operator!= (const KSArray<T>& lhs, const KSArray <T>& rhs); // prototype for operator !=

template <class T>
bool operator< (const KSArray<T> &lhs, const KSArray<T> &rhs) ; //Prototype for operator <

template <class T>
bool operator> (const KSArray<T>& lhs, const KSArray<T>& rhs) ; //Prototype for operator >

template<class T>
bool operator <= (const KSArray<T>& lhs, const KSArray<T>& rhs) ; //Prototype for operator <=

template<class T>
bool operator >= (const KSArray<T>& lhs, const KSArray<T>& rhs) ; //Prototype for operator >=


template <class  T>
// Default Ctor
// Pre-Conditions: None
// Post-Condiitons: Creates a new array of 10 units of value_type 
KSArray<T>::KSArray():_ptr(new value_type [10]),_size(10)
{}

template <class T>
// 1-parameter Ctor
// Pre-Conditions: 0 <= size
//Post-Conditions: creates a array of value_type with passed size 
KSArray<T>::KSArray(size_type size):_ptr(new value_type[size]), _size(size)
{}

template <class T>
// 2-parameter ctor
//Pre-Conditions: 0 <= size & valid object T1 of type value_type 
//Post-Conditions: creates an array of value_type with passed size  and all elements set to value T1
KSArray<T>::KSArray(const size_type size, value_type T1):_ptr(new value_type[size]),_size(size)
{
	
	for( int i=0;i<_size;++i)
	{
		_ptr [i] = T1;
	}
}

template<class T>
//Pre-Conditionms: None
//Post-Conditions: Returns size of array 
typename KSArray<T>::size_type KSArray<T>::size() const
{
	return _size;
}

//Copy Ctor, performs Deep copy
//Pre-conditions: begin(), end()must be defined, rhs must be avlid object of class T
//Post-conditions: dealloocates rhs, creates new object of class T identical to rhs 
template<class T>
KSArray<T>::KSArray(const KSArray &rhs):_ptr(new value_type[rhs.size()]),_size(rhs.size())
{
	copy(rhs.begin(), rhs.end(), _ptr); // canonical
}

template<class T>
// Pre-Conditions: None
// Post-Condiitons: returns address of first element in Array
typename KSArray<T>::value_type *KSArray<T>::begin()
{
	return _ptr;
}

template<class T>
// Pre-Conditions: Template must be declared as const
// Post-Condiitons: returns address of first element in Array
const typename KSArray<T>::value_type *KSArray<T>::begin() const 
{
	return _ptr;
}

template<class T>
// Pre-Conditions: None
// Post-Condiitons: returns address of last elements in Array 
typename KSArray<T>::value_type *KSArray<T>::end()
{
	return (begin()+_size); // canonical
}

template<class T>
// Pre-Conditions: Template must be declared as const
// Post-Condiitons: returns address of last elements in Array
const typename KSArray<T>::value_type *KSArray<T>::end() const 
{
	return (begin()+_size); // canonical
}

template<class T>
//Pre-Condition: None
//Post-Condition: returns address of passed subscript
typename KSArray<T>::value_type &KSArray<T>::operator[](typename KSArray::size_type index)
{
	if (0 <= index <_size)
	{
		return (_ptr[index]);
	}
}


template<class T>
//Pre-Condition: Template array must be defined as const
//Post-Condition: returns address of passed subscript
const typename KSArray<T>::value_type &KSArray<T>::operator[](typename KSArray::size_type index) const 
{
	if (0 <= index <_size)
	{
		return (_ptr[index]);
	}
}

template<class T>
//Pre-Condition: operator != must be defined
//Post-Condiiton: returns whether 2 objects are equal or not 
bool operator== (const KSArray<T>& lhs, const KSArray<T>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	else
	{
		for (int i=0; i<lhs.size();++i)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
	}
	return true;
}

template <class T>
//Pre-Condition: operator == must be defined
//Post-Condition: returns true if objects are not equal 
bool operator!= (const KSArray<T>& lhs, const KSArray<T>& rhs)
{
	return !(lhs==rhs); // canonical 
}

template <class T>
//Pre-Condition: operator == and operator < must be defined
//Post-Condition: returns true if lhs < rhs
bool operator< (const KSArray<T> & lhs, const KSArray<T> & rhs)
{
	if(lhs == rhs)
		return false;
	for( int i=0; i<lhs.size();i++)
	{
		if (i > rhs.size() - 1)
		{
			return false;
		}
		if (lhs[i] < rhs[i])
		{
			return true;
		}
		else if (lhs[i] > rhs[i])
		{
			return false;
		}
	}
	if (rhs.size() > lhs.size())
	{
		return true;
	}
	return false;
}



template <class T>
//Pre-Condition: Operator <= must be defined 
//Post-Condition: Returns true if lhs > rhs
bool operator> (const KSArray<T>& lhs, const KSArray<T>& rhs)
{
	return (!(lhs<=rhs)); // canonical
}

template<class T>
//Pre-Condition: Operators < and == must be defined
//Post-Condition: Returns true if lhs <= rhs
bool operator <= (const KSArray<T> &lhs, const KSArray<T> & rhs)
{
	return (( lhs < rhs)||(lhs == rhs)); // canonical
}

template<class T>
//Pre-Condition: Operators > and  == mst be defined
//Post-Condition: Returns true if lhs >= rhs 
bool operator >= (const KSArray<T>& lhs, const KSArray<T>& rhs)
{
	return ((lhs > rhs)||(lhs == rhs)); // canonical
}

template<class T>
//Pre-Conditiion: Operator != and functions size(), begin(), end() must be defined 
//Ppost-Condition: Assigns rhs to *this
KSArray<T> &KSArray<T>::operator=(const KSArray<T> &rhs)
{
	if (this != &rhs)
	{
		delete [] _ptr;
		_ptr = new value_type[rhs.size()];
		_size = rhs.size();
		std::copy(rhs.begin(), rhs.end(), _ptr);
	}
	return *this;
}

template<class T>
//Pre-Condiitons: None
//POst-Conditions: Memory is deallocated
KSArray<T>::~KSArray()
{
	delete [] _ptr;
}


#endif 
