#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int _count = 0;
int height = 0;

vector<int>
Kbig(const vector<int> &_S, const int _k);

void
Partition(vector<int> _S, vector<int> *_Sa, vector<int> *_Sb);

int main(int argc, char *argv[])
{
  fstream fout("large-out-20140513-2", fstream::out);
  clock_t start_time = clock();
  
  int N;
  cin >> N;

  vector<int> array(N, 0);
  
  for (int i = 0; i < N; ++i)
    cin >> array[i];

  int total_times_1 = 0;
  int total_times_2 = 0;
  int times = 0;
  
  for (int i = 2; i < N; i+=1000)
  {
    times++;
    int count_sum = 0;
    int height_sum = 0;

    const int TEST_SIZE = 100;
    for (int j = 0; j < TEST_SIZE; j++)
    {
      _count = 0;
      height = 0;
      vector<int> result = Kbig(array, i);
      count_sum += _count;
      height_sum += height;
    }

    const int times_1 = TEST_SIZE * N * log2(i) / count_sum;
    const int times_2 = count_sum / (double)(TEST_SIZE * N);

    total_times_1 += times_1;
    total_times_2 += times_2;

    cout << fixed << setprecision(0)
         << "k = " << i
         << "\theight = " << (double)height_sum / TEST_SIZE
         << "\tlogK = " << log2(i)
         << "\tcount = " << (double)count_sum / TEST_SIZE
         << "\tO(N*logK) = " << N * log2(i)
         << "\tO(N*logK)/count = " << times_1
         << "\tcount/O(N) = " << times_2
         << endl;

    fout << fixed << setprecision(0)
         << "k = " << i
         << "\theight = " << (double)height_sum / TEST_SIZE
         << "\tlogK = " << log2(i)
         << "\tcount = " << (double)count_sum / TEST_SIZE
         << "\tO(N*logK) = " << N * log2(i)
         << "\tO(N*logK)/count = " << times_1
         << "\tcount/O(N) = " << times_2
         << endl;
  }

  const clock_t total_time = clock() - start_time;

  cout << "the average of O(N*logK)/count = " << (double)total_times_1 / times << endl;
  cout << "the average of count/O(N) = " << (double)total_times_2 / times << endl;
  
  fout << "the average of O(N*logK)/count = " << total_times_1 / times << endl;
  fout << "the average of count/O(N) = " << total_times_2 / times << endl;
  
  cout << "total time used: " << (double)total_time / CLOCKS_PER_SEC << endl;
  fout << "total time used: " << (double)total_time / CLOCKS_PER_SEC << endl;

  fout.close();

  return 0;
}

vector<int>
Kbig(const vector<int> &_S, const int _k)
{
  if (0 >= _k)
    return vector<int>();

  if (_S.size() <= _k)
    return _S;

  vector<int> Sa, Sb;
  Partition(_S, &Sa, &Sb);

  Sa = Kbig(Sa, _k);
  Sb = Kbig(Sb, _k - Sa.size());
  Sa.insert(Sa.end(), Sb.begin(), Sb.end());
  return Sa;
}

void
Partition(vector<int> _S, vector<int> *_Sa, vector<int> *_Sb)
{
  height++;
  _count += _S.size();
  _Sa->clear();
  _Sb->clear();

  swap(_S[0], _S[rand() % _S.size()]);

  int p = _S[0];
  for (int i = 1; i < _S.size(); ++i)
  {
    if (_S[i] > p)
      _Sa->push_back(_S[i]);
    else
      _Sb->push_back(_S[i]);
  }

  if (_Sa->size() < _Sb->size())
    _Sa->push_back(p);
  else
    _Sb->push_back(p);
}

