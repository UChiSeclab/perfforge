#include <bits/stdc++.h>
const int MAX_N = (int)1e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;
using namespace std;
bool bigger(string &a, string &b) {
  for (int i = 0; i < int((a).size()); i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    char a;
    string second;
    cin >> a >> a >> a >> a;
    cin >> second;
    long long start = 1989, pw = 1;
    for (int i = 1; i < int((second).size()); i++) {
      pw *= 10;
      start += pw;
    }
    string nw = "";
    long long x = start;
    while (x) {
      nw += char('0' + x % 10);
      x /= 10;
    }
    reverse(nw.begin(), nw.end());
    if (int((nw).size()) == int((second).size())) {
      if (bigger(second, nw))
        cout << second << endl;
      else
        cout << '1' << second << endl;
      continue;
    }
    while (1) {
      nw = "";
      x = start;
      while (int((nw).size()) < int((second).size())) {
        nw += char('0' + x % 10);
        x /= 10;
      }
      reverse(nw.begin(), nw.end());
      if (nw == second) {
        cout << start << endl;
        break;
      }
      start++;
    }
  }
  return 0;
}
