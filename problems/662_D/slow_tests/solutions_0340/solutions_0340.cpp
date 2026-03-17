#include <bits/stdc++.h>
using namespace std;
long long num(long long cur, string s) {
  for (int i = 0; i < s.size(); i++) {
    cur = cur * 10 + s[i] - '0';
  }
  return cur;
}
string nxt(string suf, string cur) {
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    if (num(mid, suf) > num(0, cur)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  long long ans = num(l, suf);
  char ret[20];
  sprintf(ret, "%lld", ans);
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char s[20];
    scanf("%s", s);
    string year = "";
    for (int i = 4; s[i] != '\0'; i++) {
      year += s[i];
    }
    string cur = "1988";
    for (int i = year.size() - 1; i >= 0; i--) {
      cur = nxt(year.substr(i, year.size() - i), cur);
    }
    printf("%s\n", cur.c_str());
  }
  return 0;
}
