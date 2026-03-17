#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a;
  cin >> n >> m;
  vector<long long> v;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    v.push_back(a);
  }
  if (n == 1) {
    cout << "0" << endl;
    return 0;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long cnt = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i + 1] >= v[i]) {
      cnt++;
      v[i + 1] = v[i] - 1;
    } else {
      cnt += (v[i] - v[i + 1]);
    }
  }
  if (v[v.size() - 1] > 0) {
    cnt += v[v.size() - 1];
  } else
    cnt++;
  cout << (sum - cnt) << endl;
  return 0;
}
