#include <bits/stdc++.h>
using namespace std;
int m, l, s;
char c[103];
unsigned long long int dp[105][905];
unsigned long long int fun(int pos, int fl) {
  int l;
  if (pos == m) {
    if (fl == 0)
      return 1LL;
    else
      return 0LL;
  }
  if (pos == 0)
    l = 1;
  else
    l = 0;
  if (m == 1 && pos == 0) l = 0;
  unsigned long long int &r = dp[pos][fl];
  if (r != -1) return r;
  r = 0;
  for (int i = l; i < 10; i++) {
    if ((fl - i) >= 0)
      r |= fun(pos + 1, fl - i);
    else
      break;
  }
  return r;
}
void path(int pos, int fl, unsigned long long int cnt) {
  if (pos == m) {
    return;
  }
  if (pos == 0)
    l = 1;
  else
    l = 0;
  for (int i = l; i < 10; i++) {
    if ((fl - i) >= 0) {
      unsigned long long int l = fun(pos, fl);
      cout << l << "con" << endl;
      if (cnt <= l) {
        cout << i;
        return path(pos + 1, fl - i, cnt);
      }
      cnt -= fun(pos + 1, fl - i);
    }
  }
  return;
}
void path1(int pos, int fl) {
  if (pos == m) {
    return;
  }
  if (pos == 0)
    l = 1;
  else
    l = 0;
  if (m == 1 && pos == 0) l = 0;
  for (int i = l; i < 10; i++) {
    if ((fl - i) >= 0) {
      unsigned long long int l = fun(pos + 1, fl - i);
      if (l >= 1) {
        cout << i;
        return path1(pos + 1, fl - i);
      }
    }
  }
  return;
}
void path2(int pos, int fl) {
  if (pos == m) {
    return;
  }
  if (pos == 0)
    l = 1;
  else
    l = 0;
  if (m == 1 && pos == 0) l = 0;
  for (int i = 9; i >= 0; i--) {
    if ((fl - i) >= 0) {
      unsigned long long int l = fun(pos, fl);
      if (l == 1) {
        cout << i;
        return path2(pos + 1, fl - i);
      }
    }
  }
  return;
}
int main() {
  cin >> m >> s;
  memset(dp, -1, sizeof(dp));
  unsigned long long int r = fun(0, s);
  if (r) {
    path1(0, s);
  } else
    cout << "-1";
  cout << " ";
  if (r) {
    path2(0, s);
    cout << endl;
  } else
    cout << "-1" << endl;
}
