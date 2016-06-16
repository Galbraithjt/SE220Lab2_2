/*
 * labArray.h
 *
 *  Created on: Jun 9, 2016
 *      Author: soaler
 */

#ifndef LABARRAY_H_
#define LABARRAY_H_

using namespace std;


class labArray
{
	friend std::ostream &operator<<( std::ostream &,const labArray &);
	friend std::istream &operator>>( std::istream &, labArray &);

public:
	explicit labArray(int = 10); //default constructor
	labArray(const labArray &); //copy constructor
	~labArray();//destructor
	size_t getSize() const; //return size
	labArray getLa() const;

	const labArray &operator=( const labArray &); //assignment operator
	bool operator==( const labArray & ) const;//equality operator
	labArray &operator() (labArray &, labArray &);

	//inequality operator; returns opposite of == operator
	bool operator!=(const labArray &right) const
	{
		return ! (*this == right ); //invokes labArray::operator ==
	}// end function operator !=

	//subscript operator for non-const objects returns modifiable lvalue
	int &operator[] (int);

	//subscript operator for const objects returns rvalue
	int operator[] (int) const;
private:
	size_t size; //pointer-baise array size
	int *ptr; //pointer to the first element of the pointer-baised array
	int la[10][10];
};//end class labArray

#endif
