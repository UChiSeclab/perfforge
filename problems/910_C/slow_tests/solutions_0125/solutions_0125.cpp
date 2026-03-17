#include <bits/stdc++.h>
using namespace std;
long long sum[10] = {0};
bool starts[10] = {0};
int p[10];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int val = 1;
    for (int j = (int)s.size() - 1; j >= 0; --j) {
      sum[s[j] - 'a'] += val;
      val *= 10;
    }
    starts[s[0] - 'a'] = true;
  }
  for (int i = 0; i < 10; ++i) {
    p[i] = i;
  }
  long long best = 1LL << 60;
  do {
    if (starts[p[0]]) {
      continue;
    }
    long long curr = 0;
    for (int i = 0; i < 10; ++i) {
      curr += i * sum[p[i]];
    }
    best = min(best, curr);
  } while (next_permutation(p, p + 10));
  cout << best << endl;
  return 0;
}
