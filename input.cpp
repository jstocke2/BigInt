// bigint input from file, add
//
//==============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include "bigint.hpp"

//==============================================================================
int main()
{
  ifstream in;
  char ch;
  in >> ch;
    // Define object for input, exit if open fails
    std::ifstream in("data1-1.txt");
    if(!in)
        { std::cerr << "Couldn\'t open data1-1.txt, exiting.\n"; exit(1); }

    // Input, add, output
    //  bigint left, right;
    while (in >> left && in >> right)
    {
        // Output operands
        std::cout << "left:   " <<  left << "\n";
        std::cout << "right:  " << right << "\n";

        // Add
	//    bigint result = left + right;

        // Output result
        std::cout << "result: " << result << "\n\n";
    }
    
    // Close file
    in.close();

    return 0;
}

