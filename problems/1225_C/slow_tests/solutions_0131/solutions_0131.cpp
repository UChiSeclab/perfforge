#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    long long b = binpow(a, n / 2);
    return b * b;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, p, v = 0, a = -1;
  cin >> n >> p;
  for (long long i = 1; i <= 1e5; ++i) {
    long long n1 = n - p * i;
    vector<long long> ans;
    while (n1 != 0) {
      ans.push_back(n1 % 2);
      n1 /= 2;
    }
    long long cont = 0, p2 = 0;
    for (long long j = 0; j < ans.size(); ++j) {
      if (ans[j] == 1) {
        p2 += 1;
        cont += binpow(2, j);
      }
    }
    if (cont >= i && p2 <= i) {
      a = i;
      break;
    }
  }
  cout << a;
  return 0;
}
