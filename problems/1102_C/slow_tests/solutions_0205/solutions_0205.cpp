#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  if (x > y)
    cout << n;
  else {
    int i = 0;
    int count = 0;
    long long zero = 0;
    while (i < n) {
      vec[i] = max(zero, vec[i] - x);
      if (vec[i] == 0 && (i + 1 < n || n == 1)) {
        vec[i + 1] += y;
        i++;
        count++;
        sort(vec.begin(), vec.end());
      } else {
        vec[i] += y;
        break;
      }
    }
    cout << count;
  }
}
