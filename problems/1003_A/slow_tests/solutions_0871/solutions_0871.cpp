#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, max, x;
  cin >> n;
  vector<int> v;
  long long temp;
  max = 1;
  while (n-- > 0) {
    cin >> temp;
    v.push_back(temp);
  }
  for (auto x : v) {
    a = count(v.begin(), v.end(), x);
    if (a > max) {
      max = a;
    }
  }
  cout << max;
  return 0;
}
