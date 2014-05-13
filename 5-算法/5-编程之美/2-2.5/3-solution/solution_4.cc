#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int
get_result();

vector<int>
recursion(vector<int> _array, const int _k);

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int N;
  cin >> N;

  vector<int> array(N, 0);
  
  for (int i = 0; i < N; ++i)
    cin >> array[i];

  const vector<int> result = recursion(array, 3);
  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << "\t";
  cout << endl;

  return 0;
}

int
get_result()
{
  return 0;
}

vector<int>
recursion(vector<int> _array, const int _k)
{
  const int rand_pos = rand() % _array.size();

  vector<int> lhs_vec, rhs_vec;
  vector<int> result;
  
  for (int i = 0; i < _array.size(); ++i)
  {
    if (_array[i] >= _array[rand_pos])
      lhs_vec.push_back(_array[i]);
    else
      rhs_vec.push_back(_array[i]);
  }

  if (lhs_vec.size() == _k)
  {
    return lhs_vec;
  }
  else if (lhs_vec.size() < _k)
  {
    result.insert(result.end(), lhs_vec.begin(), lhs_vec.end());
    const vector<int> temp_result = recursion(rhs_vec, _k - lhs_vec.size());
    result.insert(result.end(), temp_result.begin(), temp_result.end());
  }
  else
  {
    result = recursion(lhs_vec, _k);
  }
  
  return result;
}
