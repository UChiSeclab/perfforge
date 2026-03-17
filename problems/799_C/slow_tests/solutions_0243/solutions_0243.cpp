#include <bits/stdc++.h>
using namespace std;
const int N = 100005, MIN = -3 * N;
struct Value {
  int first, second, first_index, second_index;
  Value() : first(MIN), second(MIN), first_index(-1), second_index(-1) {}
};
Value beauty[N][2];
void updateValue(Value &value, int new_value, int index) {
  if (new_value > value.first) {
    value.second = value.first;
    value.second_index = value.first_index;
    value.first = new_value;
    value.first_index = index;
  } else if (new_value > value.second) {
    value.second = new_value;
    value.second_index = index;
  }
}
int main() {
  int n, cd[2];
  scanf("%d %d %d", &n, &cd[0], &cd[1]);
  for (int i = 0; i < n; ++i) {
    int b, p;
    char c;
    scanf("%d %d %c", &b, &p, &c);
    updateValue(beauty[p][c - 'C'], b, p);
  }
  for (int k = 0; k < 2; ++k) {
    for (int i = 1; i <= cd[k]; ++i) {
      updateValue(beauty[i][k], beauty[i - 1][k].first,
                  beauty[i - 1][k].first_index);
      updateValue(beauty[i][k], beauty[i - 1][k].second,
                  beauty[i - 1][k].second_index);
    }
  }
  int res = 0;
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i <= cd[k]; ++i) {
      res = max(res, beauty[i][k].first + beauty[cd[k ^ 1]][k ^ 1].first);
      if (beauty[i][k].first_index != beauty[cd[k] - i][k].first_index) {
        res = max(res, beauty[i][k].first + beauty[cd[k] - i][k].first);
      } else {
        res = max(res, beauty[i][k].first + beauty[cd[k] - i][k].second);
      }
    }
  }
  printf("%d\n", res);
}
