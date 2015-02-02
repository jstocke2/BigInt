// Jake Stocker
// Test file for bigint Multiplication
//
//

#include "bigint.hpp"
#include <fstream>
int main()
{
	// Open file

	std::ifstream in("data1-2.txt");
	if (!in)
		{std::cerr <<"Unable to open file"; exit(1); }


	std:: cout << "Multiplication test program.\n";
	
	// read bigints while their are two bigints to multiply
	bigint lhs, rhs;
	while (in>>lhs && in >>rhs)
	{

		std::cout << "left:  " << lhs << std::endl;
		std::cout << "right:  " << rhs<<std::endl;

		bigint product=lhs*rhs;

	std::cout << "result:  " << product << std::endl;
	}
	
	// Close the file
	in.close();

}
