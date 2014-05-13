#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

struct DataElement
{
  int index;
  int value;
  bool operator < (const DataElement &_data) const
  {
    return this->value < _data.value;
  }
};

DataElement array[100001];

int main(int argc, char *argv[])
{
  int N, M;
  scanf("%d %d", &N, &M);

  for (int i = 1; i <= N; ++i)
  {
    scanf("%d", &array[i].value);
    array[i].index = i;
  }

  sort(array + 1, array + N + 1);
  
  for (int i = 0; i < M; ++i)
  {
    int lhs, rhs, k;
    scanf("%d %d %d", &lhs, &rhs, &k);

    int result = 0;
    for (int j = 1; j <= N; ++j)
    {
      if (lhs <= array[j].index && rhs >= array[j].index)
      {
        k--;
        if (0 == k)
        {
          result = array[j].value;
          break;
        }
      }
    }
    printf("%d\n", result);
  }

  return 0;
}
