#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T>
bool chmin(T& a, const T& b) {
  return (b < a) ? (a = b, true) : false;
}
template <class T>
bool chmax(T& a, const T& b) {
  return (b > a) ? (a = b, true) : false;
}
template <typename T>
istream& operator>>(istream& i, vector<T>& v) {
  for (int j = (int)(0); j < (int)(v.size()); j++) i >> v[j];
  return i;
}
template <typename T>
string join(vector<T>& v) {
  stringstream s;
  for (int i = (int)(0); i < (int)(v.size()); i++) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
  if (v.size()) o << join(v);
  return o;
}
template <typename T>
string join(vector<vector<T>>& vv) {
  string s = "\n";
  for (int i = (int)(0); i < (int)(vv.size()); i++) s += join(vv[i]) + "\n";
  return s;
}
template <typename T>
ostream& operator<<(ostream& o, vector<vector<T>>& vv) {
  if (vv.size()) o << join(vv);
  return o;
}
int main() {
  int n;
  cin >> n;
  int f = 1;
  vector<int> now = {0};
  while (n--) {
    int a;
    cin >> a;
    now.push_back(a);
    now.back() *= f;
    a = now.back();
    now.pop_back();
    now[0] += a;
    f++;
  }
  cout << now[0] << endl;
}
