#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 1000000000;
long long v[MAXN];
int main() {
  int n, k, m = 0;
  cin >> n >> k;
  vector<int> pos;
  memset(v, 0, sizeof v);
  for (int i = 0; i < n + 1; i++) {
    string s;
    cin >> s;
    if (s.compare("?") == 0) {
      pos.push_back(i);
    } else {
      stringstream ss;
      ss << s;
      ss >> v[i];
      if ((i & 1) && (k < 0)) v[i] *= -1;
      if (v[i] != 0) m = i + 1;
    }
  }
  if ((int)pos.size() > 0) {
    if (k == 0) {
      if (pos[0] == 0) {
        if ((n + 1 - (int)pos.size()) & 1) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      } else {
        if (v[0] == 0) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    } else {
      if ((n + 1) & 1) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  } else {
    long long acc = 0;
    bool ok = true;
    if (k == 0) {
      if (v[0] != 0) ok = false;
    } else {
      k = abs(k);
      for (int i = 0; i < m; i++) {
        if (acc % k) {
          ok = false;
          break;
        }
        acc /= k;
        acc += v[i];
      }
      if (acc != 0) ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
