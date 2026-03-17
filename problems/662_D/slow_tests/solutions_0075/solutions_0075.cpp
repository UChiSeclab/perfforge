#include <bits/stdc++.h>
using namespace std;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
const double PI = 3.14159265358979323846;
long long ten_pow(int s) {
  long long r = 1;
  for (int i = 0; i < s; ++i) r *= 10;
  return r;
}
long long check_for(char *abbr) {
  int h = strlen(abbr);
  long long base = atoi(abbr);
  if (abbr[0] == '0') {
    base += ten_pow(h);
  }
  long long y = (1989 - base + ten_pow(h) - 1) / ten_pow(h) * ten_pow(h) + base;
  if (h > 1) {
    while (check_for(abbr + 1) >= y) y += ten_pow(h);
  }
  return y;
}
int main() {
  int n;
  cin >> n;
  char s[50];
  while (n--) {
    cin >> s;
    char *num = s + 4;
    cout << check_for(num) << endl;
  }
  return 0;
}
