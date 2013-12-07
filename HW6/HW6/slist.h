#ifndef SLIST_H_
#define SLIST_H_

#include<cstdlib> //for std::size_t
#include<algorithm>


template <class T>

class SList
{
public:
	typedef T value_type;
	typedef std::size_t size_type;
	
	SList();							//default ctor//
	SList(const SList &orig);			//copy ctor//
	~SList();							//Dctor//

	SList & operator=(SList rhs);		//copy assignment//

	size_type size() const;				//size function, returns size of list//
	template <typename InputIterator>	//input iterator, used in the read function//
	void read(InputIterator first, InputIterator Last); //read function, reads from list between first and last//
	template <typename OutputIterator>	//output interator - for write starting at iterator's position//
	void write(OutputIterator dest) const; //uses OutputIterator as a starting point//
	void reverse();						// reverses order of Linked list//
private:

	value_type _data; // Data for this node 
	//size_t _size;
	SList * _next; // Ptr to next node, NULL if empty or last item 
};

template <class T>
SList<T>::SList():_next(NULL)			// default constructor //
{
}

template <class T>
SList<T>::SList( const SList &orig)		//copy constructor//
{
	_data = orig._data;
	_next = orig._next;

}

template <class T>
SList<T>& SList<T>::operator=(SList<T> rhs)	// copy assignment //
{
	std::swap(rhs._next,_next);
	std::swap(rhs._data,_data);

	return *this;
}

template <class T>
typename SList<T>::size_type SList<T>::size() const 
{
	size_type counter = 0;
	while ( _next != NULL)// infinite loop currently, I THINK 
	{
		++counter;
	}
}

template <class T>
template <typename InputIterator>

void SList<T>::read( InputIterator first, InputIterator last)
{
//	delete _data;
	_next = NULL;
	while(first != last)
	{
		value_type val = *first++;
		_data = val;
		InputIterator temp = first++;
		_next = temp;

		if(first == last)
		{
			_next = NULL;
		}

	}

}

template<class T>
void SList<T>::reverse()
{
	InputIterator fromFirst;
	fromFirst = _next;				// fromFirst now points to the first item

	InputIterator fromLast;
	for (int i = 0; i < Slist.size()-1; i++)	// goes through the loop until it reaches the last item //
	{	
							// points _next to the next item //
		if (_next++ == NULL)			// if the next item points to NULL we should be at the end //
		{
			fromLast = _next;		// fromLast now points to the last item //
		}
		++_next;				// points _next to the next item //
	}
	
	int alternate = 1;				// used to alternate increments and decrements //
	while (fromFirst != fromLast)			// while not equal, will leave out the middle item //
	{
		if (alternate == 1)
		{
			std::swap_Iter(fromFirst, fromLast);
			fromLast++;				// because last now points at the start we increment //
			fromFirst--;				// because first now points to the end we decrement //
			alternate = 2;				// alternate //
		}
		if (alternate == 2)
		{
			std::swap_Iter(fromFirst, fromLast);
			fromLast--;				// last now points to the end, we decrement //
			fromFirst++;				// first now points to the start, we increment //
			alternate = 1;				// alternate //
		}
	}
}

#endif 

