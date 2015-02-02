// Jake Stocker
// cs23001
//
//

#include <fstream>
#include "bigint.hpp"


int main(){

	std::ifstream fin("data1-1.txt");

	if (!fin)
		{ std::cerr << "Failed to open file"; }


	bigint bi1, bi2;

	while (fin>>bi1&&fin>>bi2)
	{

	std::cout<<"bigint 1" << bi1 << std::endl;
	std::cout<<"bigint 2" << bi2 << std::endl;

	bigint bisum;
	bisum=bi1+bi2;

	std::cout<<"The sum is "<<bisum<<std::endl;






}
}
