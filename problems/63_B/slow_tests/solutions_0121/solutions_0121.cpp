#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
map<int, int> tmp;
int n, k;
bool flag;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    m[a]++;
  }
  int cnt = 0;
  while (++cnt) {
    tmp = m;
    for (int i = 1; i < k; i++)
      if (m[i]) {
        tmp[i]--;
        tmp[i + 1]++;
        flag = true;
      }
    if (flag)
      flag = false;
    else
      break;
    m = tmp;
  }
  cout << cnt - 1 << endl;
}
