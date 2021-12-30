#pragma once
#include <iostream>

class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer &obj);

	//Move constructor
	Integer(Integer &&obj);

	//Copy assignment
	Integer& operator =(const Integer& a);

	//Move assignment
	Integer& operator =(Integer&& a);

	// Destructor
	~Integer();

	// Accessor for the value
	int GetValue()const;

	// Mutator for the value
	void SetValue(int value);

	// Addition operator
	Integer operator +(const Integer& a)const;

	// pre increment
	Integer & operator ++();

	// post increment
	Integer operator ++(int);

	// Comparison operator
	bool operator ==(const Integer &a)const;

	// function operator
	void operator ()();

	// type operator if I wanted to create it.  however then the global operators won't work so this is
	// here commented out only to show how it could be done
	//operator int();
};

// addition operator to allow first operand to be a primitive
Integer operator +(int x, const Integer &y);

// Comparison operator to allow first operand to be a primitive
bool operator ==(int x, const Integer& y);

std::ostream & operator <<(std::ostream & out, const Integer &a);

std::istream & operator >> (std::istream &input, Integer &a);