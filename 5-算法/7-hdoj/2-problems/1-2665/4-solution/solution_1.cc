#include <algorithm>
#include <cstdio>

const int MAX_SIZE = 100001;

int sorted_array[MAX_SIZE];

struct DataElement
{
  int value[MAX_SIZE];
  int left_child_count[MAX_SIZE];
};

DataElement ptree[20]; // 2 ^ 20 == 1048576 > MAX_SIZE

void
create_ptree(const int _left, const int _right, const int _height);

int
query(const int _from, const int _to, const int _kth,
      const int _left, const int _right, const int _height);

int main(int argc, char *argv[])
{
  int T = 1;
  //scanf("%d", &T);

  for (int i = 1; i <= T; ++i)
  {
    int N, M;
    scanf("%d%d", &N, &M);

    for (int j = 1; j <= N; ++j)
    {
      scanf("%d", &sorted_array[j]);
      ptree[0].value[j] = sorted_array[j];
    }

    std::sort(sorted_array + 1, sorted_array + N + 1);

    create_ptree(1, N, 0);

    for (int j = 1; j <= M; ++j)
    {
      int from, to, k;
      scanf("%d%d%d", &from, &to, &k);
      const int kth_num = query(from, to, k, 1, N, 0);
      printf("%d\n", kth_num);
    }
  }
  
  return 0;
}

//
// Create Parititin Tree
//
// @_left: from 1
// @_right: from 1
// @_height: from 0
//

void
create_ptree(const int _left, const int _right, const int _height)
{
  // Leaf node which has only one value
  if (_left == _right)
    return;
  
  const int mid = _left + (_right - _left) / 2;
  int mid_index = mid; // Used to handle the case that value[i] == sorted_array[mid]
  int left_child_index = _left, right_child_index = mid + 1;
  int cnt_value;

  // Put the value of ptree[_height] to ptree[_height + 1]
  // which put to the left of ptree[_height + 1] if value is small than sorted_array[mid]
  // which put to the right of ptree[_height + 1] if value is bigger than sorted_array[mid]
  // Notice: the value which is equal to sorted_array[mid]
  for (int i = _left; i <= _right; ++i)
  {
    cnt_value = ptree[_height].value[i];
    ptree[_height].left_child_count[i] = ptree[_height].left_child_count[i - 1];
    if (cnt_value < sorted_array[mid])
    {
      // Left child
      ptree[_height].left_child_count[i]++;
      ptree[_height + 1].value[left_child_index++] = cnt_value;
    }
    else if (cnt_value == sorted_array[mid])
    {
      // Notice: where used to make bugs
      // e.g.
      // sorted_arrat[]:  1 2 3 4 4 4 5 6 7
      if (mid_index >= _left && sorted_array[mid_index] == sorted_array[mid])
      {
        // 1 2 3 4 4 belongs to left child
        mid_index--;
        // Left child
        ptree[_height].left_child_count[i]++;
        ptree[_height + 1].value[left_child_index++] = cnt_value;
      }
      else
      {
        // 4 5 6 7 belongs to right child
        // Right child
        ptree[_height + 1].value[right_child_index++] = cnt_value;
      }
    }
    else
    {
      // Right child
      ptree[_height + 1].value[right_child_index++] = cnt_value;
    }
  }

  // ptree[_height] is finished
  // Create ptree for left child of ptree[_height + 1]
  create_ptree(_left, mid, _height + 1);
  // Create ptree for right child of ptree[_height + 1]
  create_ptree(mid + 1, _right, _height + 1);
}

//
// return the number of left child in the section [@_start, @_end]
//
// @_start: from 1
// @_end: from 1
// @_height: from 0
// 
int
count_left_child(const int _start, const int _end, const int _height)
{
  return ptree[_height].left_child_count[_end] -
      ptree[_height].left_child_count[_start - 1];
}

//
// return the number of right child in the section [@_start, @_end]
//
// @_start: from 1
// @_end: from 1
// @_height: from 0
// 
int
count_right_child(const int _start, const int _end, const int _height)
{
  return _end - _start + 1 - count_left_child(_start, _end, _height);
}

int
query(const int _from, const int _to, const int _k, const int _left, const int _right, const int _h)
{
  if (_from == _to)
    return ptree[_h].value[_from];

  const int mid = _left + (_right - _left) / 2;
  const int left_child_count = ptree[_h].left_child_count[_to] - ptree[_h].left_child_count[_from - 1];

  int next_from, next_to;
  if (_k <= left_child_count)
  {
    // Notice next_from where used to make bugs
    next_from = _left + ptree[_h].left_child_count[_from - 1] - ptree[_h].left_child_count[_left - 1];
    next_to = next_from + left_child_count - 1;
    return query(next_from, next_to, _k, _left, mid, _h + 1);
  }
  else
  {
    // Notice next_from where used to make bugs
    next_from = _from + (ptree[_h].left_child_count[_right] - ptree[_h].left_child_count[_from - 1]);
    next_to = next_from + _to - _from - left_child_count;
    return query(next_from, next_to, _k - left_child_count, mid + 1, _right, _h + 1);
  }    
}



