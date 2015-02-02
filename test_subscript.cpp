// bigint Test Program
//
// Tests:  subscript, uses ==
//

#include "bigint.hpp"
#include <cassert>

//===========================================================================
int main ()
{
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }	
    {
	// Setup
	bigint bi(4321);

	// Test
	int digit = bi[1];

	// Verify
	assert (bi == 4321);
	assert(digit == 2);

     }	
     {	
       // Setup
       bigint bi(987654);

      // Test
      int digit = bi[1];

      //  Verify
      assert (bi == 987654);
      assert (digit= 5);
     }
     {
      // Setup
      bigint bi(76543);

     // Test
     int digit = bi[2];

     // Verify
     assert (bi == 76543);
     assert (digit == 5);
     }
     {
     // Setupt
     bigint bi("123456789012345678");

     // Test
     int digit = bi[15];

     // Verify
     assert (bi =="123456789012345678");
     assert (digit == 3);

    }

    
    //Add test cases as needed.

    std::cout << "Done testing subscript." << std::endl;
}

