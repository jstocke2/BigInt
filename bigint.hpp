// Jake Stocker
// CS 23001
// Bigint Project
// bigint.hpp
//

#ifndef BIGINT_HPP
#define BIGINT_HPP


#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>




using std::ostream;
using std::istream;

const int MAX_SIZE = 100;

class bigint
{
public:
	bigint();
	bigint(int);
	bigint(const char[]);

	bool operator==(const bigint&);
	bool operator==(int);
	bool operator==(const char[]);
	bigint operator+(bigint);
	int operator[](const int);
	bigint operator* (const bigint);
	void output(ostream&) const;
	void times_10(int);  //  Multiplies bigint by another bigint
	void times_single_digit(const int);  //Multiplies by another bigint
	
	friend ostream& operator<<(ostream&, bigint&);
	friend istream& operator>>(istream&, bigint&);


private:
	bool null;
	int digits[MAX_SIZE];
	void zero();
};
#endif
