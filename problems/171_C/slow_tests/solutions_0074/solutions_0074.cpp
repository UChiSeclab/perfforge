#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, cnt = 0, snt = 0, f;
string s, n, s1;
vector<int> v;
char u;
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> b;
    cnt += (i * b);
  }
  cout << cnt;
}
