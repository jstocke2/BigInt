// Jake Stocker
// CS 23001
//
// bigint.cpp
//
//
//
//

#include "bigint.hpp"

// PRECONDITION:  NONE
// POSTCONDITION:  CREATES EMPTY BIGINT ARRAY OF MAXSIZE
void bigint::zero()
{
	for (int i=0;i<MAX_SIZE;i++){
		digits[i]=0;
	}
}

// PRECONDITION:  NONE
// POSTCONDITION:  CREATES EMPTY BIGINT AND SETS NULL TO TRUE FOR PRINTING 0  
bigint::bigint()
{	
	null=true;
	zero();
}

// PRECONDITION:  PASSES IN AN INT FOR CONVERSION TO BIGINT
// POSTCONDITION:  CONVERTS INT TO ARRAY OF BIGINT OR SETS NULL TO TRUE
bigint::bigint(int x)
{
	zero();
	if (x==0){
	null=true;
	}
	else {
	null=false;
	for (int i=0; x!= 0; i++){
		digits[i]= x %10;
		x=x/10;
	}
}
}
// PRECONDITION:  PASSES IN A CHAR ARRAY
// POSTCONDTION:  CONVERTS ALL CHARS IN THE ARRAY TO INT AND PLACES THEM
// IN A BIGINT ARRAY OR SETS NULL TRUE IF ARRAY IS ONLY '0'
bigint::bigint(const char x[]){
	zero();
	if ((*x=='0')&&(strlen(x)==1)){
	null=true;
	}
	null=false;

	for (int i=0, y= (strlen(x)-1); x[i] != '\0';  ++i, --y) {
		digits[y] = (int(x[i]) - int('0'));
	}
}


// PRECONDITION:  PASSES IN OSTREAM
// POSTCONDITION: PRINTS ZERO IF NULL IS MARKED TRUE OR PRINTS BIGINT ARRAY 
// STARTING AT FIRST NONE ZERO NUMBER
void bigint::output(ostream& out) const
{ 
	if (null==true){
	std::cout<<"0"<<std::endl;
	}

	else {
	int i = MAX_SIZE,
		j=0;

	do {
		--i;
	} while(digits[i]==0);

	do {
		if (j% 60 != 0)
			out << digits[i];
		else
			out << std::endl<<digits[i];

		--i;
		--j;
	}while(i >=0);

}
}
// PRECONDITION:  PASSES IN A BIGINT ARRAY RHS
// POSTCONDTION:  ADDS THE 2 BIGINT ARRAYS TOGETHER AND RETURNS RESULT
bigint bigint::operator+(bigint right)
{
	int i = 0,
		temp = 0,
		temp2 = 0;

	while (i < MAX_SIZE) {
		temp = right.digits[i] + digits[i] + temp;
		temp2 =  temp % 10;
		temp /= 10;
		right.digits[i] = temp2;
		++i;

	}

	return right;

}
// PRECONDITION: PASSES IN A SPOT IN THE ARRAY TO PRINT OUT
// POSTCONDITION: PRINTS OUT THE VALUE AT THE DECLARED SPOT IN THE ARRAY

int  bigint::operator[] (const int spot)
{
	return digits[spot];
}
// PRECONDTION: PASSES IN OUTSTREEAM AND A BIGINT
// POSTCONDTION:  PRINTS 0 IF NULL IS TRUE OR PRINTS 60 DIGITS PER LINE AND
// THEN GOES TO NEXT LINE
ostream& operator<< (ostream& out, bigint& num)
{
	if (num.null==true){
	  std::cout<< "0"<<std::endl;
	}


	int i = MAX_SIZE,
		j=0;
	do {
		--i;
	}while (num.digits[i]==0);

	do {
		if (j % 60 !=0)
			out << num.digits[i];
		else
			out <<std::endl << num.digits[i];

		--i;
		++j;
	}while(i >= 0);

	return out;

}


// PRECONDITION: PASSES IN ISTREAM AND A BIGINT
// POSTCONDITION: PRINTS BIGINTS UP TO SEMICOLON

istream& operator>> (istream& in, bigint& num)
{
	int i = 0;
	char next,
		temp[MAX_SIZE];

	in >> next;
	
	while (next != ';' && !in.eof()) {
		temp[i] = next;
		in >> next;
		++i;
	}

	temp[i] = 0;
	num = bigint(temp);

	return in;
}
// PRECONDITION:  PASSES IN AN INT
// POSTCONDITION:  COMPARES THAT INT TO A BIGINT
bool bigint::operator==(int x)
{
	for (int i = 0; x != 0; ++i) {
		if (digits[i] != x % 10) return false;
		x/=10;
	}
	
	return true;
}
// PRECONDTION:  PASSES IN A BIGINT
// POSTCONDITION:  COMPARES TWO BIGINTS
bool bigint::operator == (const bigint& x) 
{
	for (int i = 0; i< MAX_SIZE; i++) {
		if (x.digits[i] != digits[i]) return false;
	}
	
	return true;

}

// PRECONDITION:  PASSES IN A CHAR ARRAY
// POSTCONDTION: CONVERRTS CHAR ARRAY TO INT ARRAY AND COMPARES THE 2 ARRAYS
bool bigint::operator == (const char x[])
{
	for (int i = 0, y = (strlen(x) - 1); x[i] != '\0'; ++i, --y){
		if (digits[y] != int(x[i])- int('0')) return false;
	}
	return true;
}

void bigint::times_10(int x){

	for (int i = (MAX_SIZE - 1); i >= 0; --i) {
		digits[i] = digits[i-x];
	}



	for (int i = (x-1); i >= 0; --i) {
		digits[i] = 0;
	}
}

bigint bigint::operator* (const bigint x)
{
	bigint temp, result;

	for (int i = 0; i < MAX_SIZE; ++i) {
		temp = *this;
		temp.times_single_digit(x.digits[i]);
		temp.times_10(i);
		result = result + temp;
	}
	return result;

}

void bigint::times_single_digit(const int x)
{
	int spot_value = 0, carry = 0;

	for (int i = 0; i < MAX_SIZE; ++i) {
		spot_value = ((x *digits[i]) + carry)% 10;
		carry = ((x*digits[i]) + carry) /10;
		digits[i] = spot_value;
	}
}
