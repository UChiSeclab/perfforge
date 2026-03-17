#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
const long double EPS = 1.0E-14;
bool check[2005];
set<long long> st;
int main() {
  long long p, q, l, r, x, y, newX, newY;
  cin >> p >> q >> l >> r;
  for (int i = 0; i < p; i++) {
    scanf("%lld %lld", &x, &y);
    for (int j = x; j <= y; j++) {
      check[j] = true;
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%lld %lld", &x, &y);
    for (int j = l; j <= r; j++) {
      newX = x + j, newY = y + j;
      for (int k = newX; k <= newY; k++) {
        if (check[k]) {
          st.insert(j);
          break;
        }
      }
    }
  }
  cout << st.size();
}
