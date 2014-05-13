#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int L;
  cin >> L;

  string line;
  cin >> line;

  vector<char> count_vec(L, 0);

  int count = 0;
  for (int i = 0; i < L; ++i)
  {
    if ('1' == line[i])
      count++;
    count_vec[i] = count;
  }

  int m, n;
  while (cin >> m >> n)
    cout << count_vec[n] - count_vec[m] + (line[m] - '0') << endl;
  // Be careful about the line[m], if '0' == line[m], then the result is count_vec[n] - count_vec[m]
  // otherwise, the result is count_vec[n] - count_vec[m] + 1
  
  return 0;
}
