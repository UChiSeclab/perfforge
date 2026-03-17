#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, l, now, next, m, pos;
  scanf("%d", &n);
  string str[n + 5];
  vector<pair<int, int> > vec;
  for (i = 0; i < n; i++) {
    cin >> str[i];
    l = str[i].length();
    l--;
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
      scanf("%d", &pos);
      pos--;
      vec.push_back({pos, i});
    }
  }
  now = 0;
  sort(vec.begin(), vec.end());
  m = vec.size();
  for (k = 0; k < m; k++) {
    next = vec[k].first;
    pos = vec[k].second;
    l = str[pos].length();
    if (now <= next) {
      for (i = now; i < next; i++) {
        printf("a");
        now++;
      }
      now = i;
      j = 0;
      for (i = next; i < next + l; i++) {
        cout << str[pos][j];
        j++;
      }
      now = i;
    } else {
      j = now - next;
      for (i = now; i < next + l; i++) {
        cout << str[pos][j];
        j++;
      }
      now = i;
    }
  }
  return 0;
}
