/*
 * labArray.cpp
 *
 *  Created on: Jun 9, 2016
 *      Author: soaler
 */
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "labArray.h"

using namespace std;

labArray::labArray( int arraySize)
	:size( arraySize > 0 ? arraySize :
			throw invalid_argument( "Array size must be greater than 0") ),
		ptr(new int [size] )
{
	for ( size_t i=0; i < size; ++i)
	{
		ptr[i] = 0; //set pointer-based array element
	}

}//end array constructor
//copy constructor for array class
//must recieve a refrence to an Array
labArray::labArray(const labArray &arrayToCopy)
	:size(arrayToCopy.size ),
	 ptr( new int[size] )
{
	for (size_t i = 0; i<size; i++)
	{
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}//end Array copy constructor
}

//destructor for array class
labArray::~labArray()
{
	cout << "we sunk your array\n" << "All your arrays are belong to us";
	delete [] ptr; // release pointer-based array space
} // end destructor

size_t labArray::getSize() const
{
	return size; //number of elements in a array
}//end get size function

//overloaded assignment operator;
//const return avoids (a1 = a2) = a3
const labArray &labArray::operator =( const labArray &right)
{
	if ( &right != this) // avoid self-assignment
	{
		//for Arrays of different sizes, deallocate original
		//left-side Array, then allocate new left-side array
		if (size != right.size)
		{
			delete [] ptr; // release space
			size = right.size; //resize this object
			ptr = new int[size]; //create space for array copy
		}//end inner if

		for (size_t i = 0; i <size; ++i)
		{
			ptr[i] = right.ptr[i]; // copy array into object
		}
	} // end outer if

	return *this; //enables x = y = z, for example
} // end function operator=


//determine if two arrays are equal and
//return true, otherwise return false
bool labArray::operator==( const labArray &right ) const
{
	if (size != right.size)
	{
		return false; //arrays of different number of elements
	}

	for ( size_t i=0; i<size; ++i)
	{
		if ( ptr[i] != right.ptr[i])
		{
			return false; // arrays not equal
		}
	}

	return true; // arrays are equal
} // end functions operator ==

//overloaded subscript operator for non-const arrays;
// refrence return creates a modifiable lvalue
int &labArray::operator[] (int subscript)
{
	//check for subscript out-of-range error
	if ( subscript < 0 || subscript >= size)
	{
		throw out_of_range( "Subscript out of range" );
		return ptr[subscript];//return refrence
	}
}//end function operator []

//overloaded subscript operator for const arrays
//const refrence return creates rvalue
int labArray::operator[] (int subscript) const
{
	//check for subscript out-of-range error
	if ( subscript < 0 || subscript >= size)
	{
		throw out_of_range( "Subscript out of range" );
		return ptr[subscript];//return refrence
	}
}//end function operator []

labArray &labArray::operator() (labArray &row, labArray &column)
{
	la[row][column] = row , column;
	return la;
}

//overloaded input operator for class labArray
// inputs values for entire array
istream &operator>>(istream &input, labArray &a)
{
	for (size_t i =0; i <a.size; ++i)
	{
		input >> a.ptr[i];
	}

	return input; //enables cin >> x >> y;
} // end function

ostream &operator<<(ostream &output, const labArray &a)
{
	//output private ptr-based array
	for ( size_t i = 0; i < a.size; ++i)
	{
		output << setw(12) << a.ptr[i];

		if ( ( i + 1 ) % 4 == 0)// 4 numbers per row if output
		{
			output<<endl;
		}
	} // end for

	if (a.size % 4 != 0 ) // the last line of output
	{
		output << endl;
	}

	return output; // enable cout << x << y
} // end function oprerator <<
labArray labArray::getLa() const
{
	return la; //number of elements in a array
}//end get size function


