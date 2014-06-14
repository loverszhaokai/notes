#include "A.h"

#include <iostream>

using namespace std;

void a_print()
{
  cout << "a_print()" << endl;
}

void a_test()
{
  cout << "a_test()" << endl;
  b_test();
}

