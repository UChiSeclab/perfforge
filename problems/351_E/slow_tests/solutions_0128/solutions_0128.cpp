#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n;
map<int, vector<int>> m;
vector<pair<int, vector<int>>> v;
int bit[2 * N] = {0};
void ud(int i, int v) {
  for (i += N; i < 2 * N; i += i & -i) bit[i] += v;
}
int qr(int i) {
  int ans = 0;
  for (i += N; i; i ^= i & -i) ans += bit[i];
  return ans;
}
long long calc() {
  long long inv = 0;
  for (int i = n - 1; i >= 0; --i) {
    inv += qr(a[i] - 1);
    ud(a[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    ud(a[i], -1);
  }
  return inv;
}
void pa() {
  cout << "[";
  for (int i = 0; i < n; ++i) {
    if (i) cout << ",";
    cout << a[i];
  }
  cout << "]\n";
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i] = abs(a[i]);
    m[a[i]].push_back(i);
  }
  for (auto p : m) {
    v.push_back(p);
  }
  long long bv = calc();
  for (int i = v.size() - 1; i >= 0; --i) {
    vector<int> &w = v[i].second;
    int bst = 0;
    for (int j = 0; j < w.size(); ++j) {
      a[w[j]] = -a[w[j]];
      long long inv = calc();
      if (inv < bv) {
        bv = inv;
        bst = j + 1;
      }
    }
    for (int j = 0; j < w.size(); ++j) {
      if (j >= bst) a[w[j]] = -a[w[j]];
    }
  }
  cout << bv << "\n";
  return 0;
}
