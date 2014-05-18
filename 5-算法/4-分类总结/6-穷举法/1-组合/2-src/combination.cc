#include <cstdio>

const int MAX_SIZE = 21;

int index[MAX_SIZE];

int
combination(const int _N, const int _K)
{
  for (int i = 1; i <= _K; ++i)
    index[i] = i;

  bool is_finish = false;
  // 
  // Do C(n,k) = _N! / _K!
  // 
  while (!is_finish)
  {
    while (index[_K] != _N + 1)
    {
	  //
	  // Do something ...
	  //
      index[_K]++;
    }

    for (int i = _K - 1; i >= 0; i--)
    {
      if (0 == i)
      {
        is_finish = true;
        break;
      }

      if (index[i] < _N - _K + i)
      {
        index[i]++;
        for (int j = i + 1; j <= _K; ++j)
          index[j] = index[i] + j - i;
        break;
      }
    }
  }
  return max_value;
}

