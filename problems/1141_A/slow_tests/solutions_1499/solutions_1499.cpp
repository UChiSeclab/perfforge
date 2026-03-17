#include <bits/stdc++.h>
using namespace std;
int calcu(int a, int b) {
  if (b == a) return 0;
  if (b == 0 || a == 0) return -1;
  if (b % a) return -1;
  int c = b / a;
  if (c % 2 && c % 3) return -1;
  queue<int> que;
  bool finish = false;
  int times = 0;
  que.push(c);
  while (!finish) {
    int len = que.size();
    for (int i = 0; i < len; i++) {
      int n = que.front();
      que.pop();
      if (n == 1) return times;
      if (!(n % 2)) que.push(n / 2);
      if (!(n % 3)) que.push(n / 3);
    }
    times++;
    if (que.empty()) {
      finish = true;
    }
  }
  return -1;
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << calcu(a, b);
  return 0;
}
