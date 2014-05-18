#include <algorithm>
#include <cstdio>

const int MAX_SIZE = 21;

int matrix[MAX_SIZE][2];
int index[MAX_SIZE];

int
get_result();

int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
    printf("%d\n", get_result());
  
  return 0;
}

int
get_result()
{
  int N, K;
  scanf("%d%d", &N, &K);

  for (int i = 1; i <= N; ++i)
    scanf("%d%d", &matrix[i][0], &matrix[i][1]);

  int max_weight;
  scanf("%d", &max_weight);

  int max_value = 0, total_weight, total_value;
  for (int i = 1; i <= K; ++i)
    index[i] = i;

  bool is_finish = false;
  while (!is_finish)
  {
    while (index[K] != N + 1)
    {
      total_value = 0;
      total_weight = 0;
      for (int i = 1; i <= K; ++i)
      {
        total_value += matrix[index[i]][0];
        total_weight += matrix[index[i]][1];
      }

      if (total_weight <= max_weight)
        max_value = std::max(max_value, total_value);
      
      index[K]++;
    }

    for (int i = K - 1; i >= 0; i--)
    {
      if (0 == i)
      {
        is_finish = true;
        break;
      }

      if (index[i] < N - K + i)
      {
        index[i]++;
        for (int j = i + 1; j <= K; ++j)
          index[j] = index[i] + j - i;
        break;
      }
    }
  }
  return max_value;
}

