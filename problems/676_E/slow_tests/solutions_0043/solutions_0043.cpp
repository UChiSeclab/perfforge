#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005;
const int INF = 1 << 29;
int n, k;
int a[NMAX];
bool prime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int get_prime(int x, int y) {
  int p = x + rand() % y;
  while (!prime(p)) {
    p++;
  }
  return p;
}
int main() {
  srand(time(0));
  cin.sync_with_stdio(false);
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    string s;
    cin >> s;
    if (s[0] == '?') {
      a[i] = INF;
    } else {
      sscanf(s.c_str(), "%d", &a[i]);
      cnt++;
    }
  }
  if (k == 0) {
    if (a[0] == INF) {
      if (cnt & 1) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    } else if (a[0] == 0) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    return 0;
  }
  if (cnt <= n) {
    if (n & 1) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    return 0;
  }
  int p1 = get_prime(9e8, 1e9);
  int p2 = get_prime(9e8, 1e9);
  int b1 = 1;
  int b2 = 1;
  int sol1 = 0;
  int sol2 = 0;
  for (int i = 0; i <= n; i++) {
    sol1 = (sol1 + 1LL * a[i] * b1) % p1;
    sol2 = (sol2 + 1LL * a[i] * b2) % p2;
    b1 = (1LL * b1 * k) % p1;
    b2 = (1LL * b2 * k) % p2;
  }
  if (!sol1 && !sol2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
