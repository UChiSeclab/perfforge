#include <bits/stdc++.h>
using namespace std;
int k;
string s;
vector<int> len;
bool check(int x) {
  int pos = 0, ans = 0;
  while (pos < len.size()) {
    int tmp = x;
    while (pos < len.size() && tmp >= len[pos]) tmp -= len[pos++];
    ++ans;
    if (ans > k) return false;
  }
  return true;
}
int main() {
  cin >> k;
  getline(cin, s);
  getline(cin, s);
  int tmp = 0;
  for (int i = 0; i < s.size(); i++) {
    ++tmp;
    if (s[i] == ' ' || s[i] == '-') {
      len.push_back(tmp);
      tmp = 0;
    }
  }
  len.push_back(tmp);
  int lbound = 0, ubound = 1000000;
  for (int i = 0; i < 1500; i++) {
    int mid = (lbound + ubound) / 2;
    if (check(mid))
      ubound = mid;
    else
      lbound = mid + 1;
  }
  cout << lbound << endl;
  return 0;
}
