#include <bits/stdc++.h>
using namespace std;
const int MAX = 10e4 + 5;
int main() {
  int n;
  cin >> n;
  string string1 = "";
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    if (a == '1') maxi++;
    string1 += a;
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    pair<int, int> p;
    cin >> p.first;
    cin >> p.second;
    v.push_back(p);
  }
  int count = maxi;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= v[j].second and (i - v[j].second) % v[j].first == 0) {
        if (string1[j] == '0') {
          string1[j] = '1';
          count++;
        } else {
          string1[j] = '0';
          count--;
        }
      }
    }
    maxi = max(maxi, count);
    if (maxi == string1.length()) {
      break;
    }
  }
  cout << maxi;
  return 0;
}
