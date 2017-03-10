/*
// Problem Statement
//      You have an array of integers: the int[] A. When you give the array to Hero, he will execute the following steps:

//     At the beginning, he will set the variable X to zero.
//     For each element Y of A, in the given order, he will set X to (X + (X xor Y)).
//     He will announce the final value of the variable X.

// Before you give the array A to Hero, you are allowed to permute its elements arbitrarily. Compute and return the largest possible value that can be announced by Hero.

// Definition

// Class:	Xscoregame
// Method:	getscore
// Parameters:	int[]
// Returns:	int
// Method signature:	int getscore(int[] A)
// (be sure your method is public)


// Constraints
// -	A will contain between 1 and 15 elements, inclusive.
// -	Each element in A will be between 0 and 50, inclusive.
*/

#include <iostream>

class Xscoregame {
public:
  int getscore(int A[], int n)
  {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int p = i;
      int tmp = 0;
      for (int j = i; j < n; j++) {
        if (tmp < (A[j] ^ sum)) {
          tmp = A[j] ^ sum;
          p = j;
        }
      }
      sum += tmp;
      // swap i, p
      if (p != i) {
        tmp = A[i];
        A[i] = A[p];
        A[p] = tmp;
      }
    }
    return sum;
  }
};

struct test_data_t {
  int *a;
  int n;
};

int main()
{
  int a1[] = {1,2,3};
  int a2[] = {10,0,0,0};
  int a3[] = {1,1,1,1,1,1};
  int a4[] = {1,0,1,0,1,0,1,0};
  int a5[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};

  test_data_t tests[] = {
    {a1, 3},
    {a2, 4},
    {a3, 6},
    {a4, 8},
    {a5, 15},
    {NULL, 0}
  };

  Xscoregame sg;
  int i;
  test_data_t *test;
  for (i = 1, test = tests; test->a != NULL; test++, i++) {
    std::cout << "TestCase #" << i << ": "
              << sg.getscore(test->a, test->n)
              << std::endl;
  }

  return 0;
}
