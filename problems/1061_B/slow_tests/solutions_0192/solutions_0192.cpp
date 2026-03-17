#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, x, y, m, t;
  cin >> n >> m;
  vector<long long int> vec;
  long long int sm = 0;
  for (i = 0; i < n; i++) {
    cin >> j;
    vec.push_back(j);
    sm += j;
  }
  sort(vec.begin(), vec.end());
  if (vec.size() == 1) {
    printf("0\n");
    return 0;
  }
  long long int ans = 0;
  long long int curr = 0;
  for (i = 0; i < n; i++) {
    ans += 1;
    if (vec[i] > curr) curr++;
  }
  ans += max((long long int)0, vec[n - 1] - curr);
  cout << sm - ans << endl;
}
