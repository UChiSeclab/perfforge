#include <bits/stdc++.h>
using namespace std;
queue<int> r1, r2;
int n, x, TLE, asd;
bool flag;
int main() {
  cin >> n >> x;
  for (int i = 1; i <= x; i++) cin >> asd, r1.push(asd);
  cin >> x;
  for (int i = 1; i <= x; i++) cin >> asd, r2.push(asd);
  while (TLE < 10000000) {
    if (r1.size() == 0 || r2.size() == 0) {
      flag = 1;
      break;
    }
    TLE++;
    int u = r1.front(), v = r2.front();
    r1.pop(), r2.pop();
    if (u > v)
      r1.push(v), r1.push(u);
    else
      r2.push(u), r2.push(v);
  }
  if (flag)
    if (r1.size() == 0)
      cout << TLE << " " << 2 << endl;
    else
      cout << TLE << " " << 1 << endl;
  else
    puts("-1");
  return 0;
}
