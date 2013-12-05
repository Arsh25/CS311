/*
 * TSmArray.h
 * Header file for class TSmArray 
 * Assignment 5, CS311 Fall 2013
 * 
 * Created on: 11/25/2013
 * Arsh Chauhan And Smaule George 
 */

#ifndef TSMARRAY_H_
#define TSMARRAY_H_

#include <stdexcept> //for std::out_of_range
using std::out_of_range;	
#include <cstdlib> //for std::size_t
#include <algorithm> //for std::copy
using std::copy;


// class Invariants:
// _capacity >= _size >= 0
// _capacity >= 0
// _data is 0 if _capacity==0, or points to an int array,
//  allocated with new [], owned by *this,
// holding _capacity value_types.
template <class T>
class TSmArray
{
public:
   typedef T value_type;
   typedef value_type * iterator;
   typedef const value_type * const_iterator;
   typedef std::size_t size_type;

   TSmArray();
   TSmArray(const TSmArray &orig);
   TSmArray(size_type size);
   ~TSmArray();

   TSmArray & operator=(TSmArray rhs);
  
   value_type & operator[](size_type index);
   const value_type & operator[](size_type index) const;

   size_type size() const;
   bool empty() const;

   iterator begin();
   const_iterator begin() const;
   iterator end();
   const_iterator end() const;
   void resize(size_type newsize);
   iterator insert(iterator i, const value_type & v);
   iterator remove(iterator i);
   void swap(TSmArray &rhs);

private:
   size_type _size;
   size_type _capacity;
   value_type * _data;
};



//Pre-conditions: None
//No Throw Guarantee
template <class T>
TSmArray<T>::TSmArray():_size(0),_capacity(0),_data(0)
{
}

//Pre-conditions: None
//Strong Guarantee
template <class T>
TSmArray<T>::TSmArray(const TSmArray& orig):_size(orig._size),_capacity(_size),_data(new value_type [_capacity])
{
	try 
	{
	copy(orig.begin(),orig.end(),_data);
	}
	catch (...)
	{	
	delete []_data;
	throw;
	}
}

//Pre-conditions: _size >= 0
//Strong Guarantee
template <class T>
TSmArray<T>::TSmArray(size_type size):_size(size),_capacity(_size),_data(new value_type [_capacity])
{  
}

//Pre-conditions: None
//Post-conditions: deletes _data and returns memory to OS
//No Throw Guarantee
template<class T>
TSmArray<T>::~TSmArray()
{
delete[] _data;
}

//Pre-conditions: None
//Post-condition: swaps all contents of *this with those of rhs 
// Strong Guarantee
template <class T>
TSmArray<T>& TSmArray<T>::operator=( TSmArray<T> rhs)
{
swap(rhs);
return *this;
}


//Pre-conditions: 0<=index<_size
//Post-condition: returns value of type value_type stored at location passed
//No Throw Guarantee
template <class T>
typename TSmArray<T>::value_type& TSmArray<T>::operator [](size_type index)
{
return _data[index];
}

//Pre-conditions: 0<=index<_size
//Post-condition: returns value of type value_type stored at location passed for const objects 
//No Throw Guarantee
template <class T>
typename const TSmArray<T>::value_type & TSmArray<T>::operator [](size_type index) const
{
return _data[index];
}

//Pre-conditions: None
//Post-conditions:Returns size of TSmArray by returning value stored in _size 
//No Throw Guarantee
template <class T>
typename TSmArray<T>::size_type TSmArray<T>::size() const
{
return _size;
}

//Pre-conditions: None
//Post-conditions:Returns True if array is empty 
//No Throw Guarantee
template <class T>
bool TSmArray<T>::empty() const
{
return (_size==0);
}

//Pre-conditions: None
//Post-condition: Returns first element stored in *this 
//No Throw Guarantee
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::begin()
{
return _data;
}

//Pre-conditions: None
//Post-condition: Returns first element stored in *this for const objects 
//No Throw Guarantee
template <class T>
typename TSmArray<T>::const_iterator TSmArray<T>::begin() const
{
return _data;
}

//Pre-conditions: None
//Post-condition: Returns last element stored in *this object
//No Throw Guarantee
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::end()
{
return _data+_size;
}

//Pre-conditions: None
//Post-condition: Returns last element stored in *this for const objects 
//No Throw Guarantee
template <class T>
typename TSmArray<T>::const_iterator TSmArray<T>::end() const
{
return _data+_size;
}

//Pre-conditions: _size >= 0
//Post-conditions: Changes _size member of *this to passed value 
//Strong Guarantee 
template <class T>
void TSmArray<T>::resize(size_type newsize)
{
	if (newsize <= _capacity)
	{
		_size = newsize;
	}
	else
	{
		TSmArray<T> temp(2*newsize);
		
	for(auto ii=0;ii<_size;ii++)
	{
		temp._data[ii] = _data[ii];
	}
	temp._size = (newsize);
	swap(temp);	
		
	}
}
//Pre-conditions: begin() <= i < end()
//Post-conditions: Inserts passed value position i-1 and returns i
//Strong Guarantee
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::insert(iterator i, const value_type& v)
{
	size_type index = i - begin();
	resize(_size+1);
	i = begin() + index;
	for(int ii =_size-1; ii!=index; ii--)
	{
		_data[ii] = _data[ii-1];
	}
	_data[index] = v;

	return (i);
}

//Pre-conditions: begin() <= i < end()
//Post-condtions: Removes the item referenced by i. Returns an iterator to item stored at (i-1)
//Strong Guarantee 
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::remove(iterator i)
{
	size_type index = i - begin();
	for (int ii = index; ii != _size-1; ii++)
	{
		_data[ii] = _data[ii+1];
	}
	resize(_size-1);
	return (i);
}

//Pre-conditions: None
//Post-condition: Swaps *this with rhs 
//No Throw Guarantee
template <class T>
void TSmArray<T>::swap( TSmArray<T> &rhs)
{
std::swap(rhs._size,_size);
std::swap(rhs._capacity,_capacity);
std::swap(rhs._data,_data);
}

#endif 