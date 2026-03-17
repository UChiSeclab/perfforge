#include <bits/stdc++.h>
using namespace std;
const int c = -100005;
int var = 0;
bool isDiv(vector<int>& v, int k) {
  bool pos = true;
  int temp = 0;
  for (int i = 0; i < v.size(); i++) {
    temp += v[i];
    if (temp % k != 0) {
      pos = false;
      break;
    } else {
      temp /= k;
    }
  }
  if (temp != 0) pos = false;
  return pos;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 0; i < n + 1; i++) {
    string s;
    cin >> s;
    if (s == "?") {
      a[i] = c;
      var++;
    } else {
      stringstream myStream;
      myStream.str(s);
      myStream >> a[i];
    }
  }
  if (var == 0) {
    if (k == 0) {
      if (a[0] == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    } else {
      if (isDiv(a, k))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  } else {
    if (k == 0) {
      if (a[0] != 0 and a[0] != c)
        cout << "No" << endl;
      else if (a[0] == 0)
        cout << "Yes" << endl;
      else {
        if ((n + 1 - var) % 2 == 0)
          cout << "No" << endl;
        else
          cout << "Yes" << endl;
      }
    } else {
      if ((n + 1) % 2 == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
