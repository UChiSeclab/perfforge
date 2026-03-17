#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int n, k1, k2, cnt = 0;
deque<int> p1, p2;
int main() {
  scanf("%d", &n);
  scanf("%d", &k1);
  for (int i = 1; i <= k1; ++i) {
    int u;
    scanf("%d", &u);
    p1.push_back(u);
  }
  scanf("%d", &k2);
  for (int i = 1; i <= k2; ++i) {
    int u;
    scanf("%d", &u);
    p2.push_back(u);
  }
  while (p1.size() != 0 && p2.size() != 0) {
    int c1 = p1.front();
    p1.pop_front();
    int c2 = p2.front();
    p2.pop_front();
    if (c1 <= c2) {
      p2.push_back(c1);
      p2.push_back(c2);
    } else {
      p1.push_back(c2);
      p1.push_back(c1);
    }
    cnt++;
    if (cnt == 10000000) break;
    if (p1.size() == 0 || p2.size() == 0) break;
  }
  if (p1.size() == 0)
    cout << cnt << " "
         << "2";
  else if (p2.size() == 0)
    cout << cnt << " "
         << "1";
  else if (cnt == 10000000)
    cout << "-1";
}
