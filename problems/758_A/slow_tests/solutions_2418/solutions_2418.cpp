#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  int t, c;
  cin >> t;
  vector<int> r;
  for (int i = 0; i < t; i++) {
    cin >> c;
    r.push_back(c);
  }
  for (int j = 0; j < t; j++) {
    cnt += abs((*max_element(r.begin(), r.end()) - r[j]));
  }
  cout << cnt << endl;
  ;
}
