#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int
get_result();

int
recursion();

int main(int argc, char *argv[])
{
  int N, M;
  cin >> N >> M;

  vector<int> array(N, 0);
  
  for (int i = 0; i < N; ++i)
    cin >> array[i];

  for (int i = 0; i < M; ++i)
  {
    int l, r, k;
    cin >> l >> r >> k;

    vector<int> temp_array(array.begin() + l - 1, array.begin() + r);

    vector<int> k_vec(temp_array.begin(), temp_array.begin() + k);
    sort(k_vec.begin(), k_vec.end());

    for (int j = k; j < temp_array.size(); ++j)
    {
      if (k_vec.back() > temp_array[j])
      {
        k_vec.back() = temp_array[j];
        sort(k_vec.begin(), k_vec.end());
      }
    }
    
    cout << k_vec.back() << endl;
  }

  return 0;
}

int
get_result()
{
  return 0;
}

int
recursion()
{
  return 0;
}
