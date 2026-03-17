#include <bits/stdc++.h>
using namespace std;
int m, n;
int co(int num, int in) {
  if (num == m) return in;
  if (num > m) return -1;
  in++;
  int in1 = co(num * 2, in);
  int in2 = co(num * 3, in);
  if (in1 == -1 && in2 == -1)
    return -1;
  else
    return in1 == -1 ? in2 : in1;
}
int main() {
  cin >> n >> m;
  cout << co(n, 0);
  return 0;
}
