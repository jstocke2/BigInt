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
        bi.times_10(0); //Or whatever you call it.

        // Verify
        assert(bi == 3);
    }
    {
    	// Setup fixture
    	bigint bi(10);

	// Test
	bi.times_10(1);

	// Verify
	assert (bi == 100);
     }
     {
     	// Setup fixture
     	bigint bi(412);
       
        // Test
        bi.times_10(3);

        // Verify
        assert (bi == 412000);
     }
    //Add test cases as needed.
     
    std::cout << "Done testing times10" << std::endl;
}

