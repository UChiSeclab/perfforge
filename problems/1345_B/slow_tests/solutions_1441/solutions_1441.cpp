#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, max = 0, a;
  cin >> t;
  vector<long long> v, cards;
  for (int i = 0; i < t; i++) {
    cin >> a;
    v.push_back(a);
    if (a > max) max = v[i];
  }
  for (int i = 1; ((3 * i * i + i) / 2) <= max; i++) {
    cards.push_back((3 * i * i + i) / 2);
  }
  for (int i = 0; i < v.size(); i++) {
    int count = 0;
    while (v[i] >= cards[0]) {
      auto upper1 = upper_bound(cards.begin(), cards.end(), v[i]);
      if (upper1 == cards.end()) {
      } else {
      }
      v[i] -= *(--upper1);
      count++;
    }
    cout << count << "\n";
  }
}
