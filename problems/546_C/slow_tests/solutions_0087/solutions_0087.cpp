#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2, x, y, i;
  cin >> n;
  queue<int> q1;
  queue<int> q2;
  cin >> k1;
  for (i = 0; i < k1; i++) {
    cin >> x;
    q1.push(x);
  }
  cin >> k2;
  for (i = 0; i < k2; i++) {
    cin >> x;
    q2.push(x);
  }
  for (i = 1; i <= 40000000; i++) {
    x = q1.front();
    q1.pop();
    y = q2.front();
    q2.pop();
    if (x > y) {
      q1.push(y);
      q1.push(x);
    } else if (y > x) {
      q2.push(x);
      q2.push(y);
    }
    if (q1.empty()) break;
    if (q2.empty()) break;
  }
  if (q1.empty())
    cout << i << " "
         << "2" << endl;
  else if (q2.empty())
    cout << i << " "
         << "1" << endl;
  else
    cout << "-1" << endl;
  return (0);
}
