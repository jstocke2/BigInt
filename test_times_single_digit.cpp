// bigint Test Program
//
// Tests:  times_10, uses ==
//

#include "bigint.hpp"

#include <cassert>

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi.times_single_digit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }
    {
	//Setup fixture
	bigint bi(5);
	
	// Test
	bi.times_single_digit(0);

	// Verify
	assert (bi == 0);
     }
     {
	//Setup fixture
	bigint bi(25);
	
	// Test
	bi.times_single_digit(2);

	// Verify
	assert (bi == 50);
      }
      {
	// Setup fixture
	bigint bi(111111111);

	// Test
	bi.times_single_digit(9);

	// Verify
	assert (bi == 999999999);
      }
    //Add test cases as needed.
    
    std::cout << "Done testing bigint * single digit" << std::endl;
}
