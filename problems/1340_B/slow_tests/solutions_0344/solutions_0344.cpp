#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void printVec(const T &v, char sep = ' ') {
  for (auto &i : v) cout << i << sep;
}
template <typename T>
void printVecPair(const T &v, char sep = ' ') {
  for (auto &i : v) cout << i.first << " " << i.second << sep;
}
int n, k;
vector<string> dig;
string number[10];
int convert(string s1, string s2) {
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    if (s1[i] != s2[i]) {
      if (s1[i] == '0')
        ans++;
      else
        return -1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  dig.resize(n);
  number[0] = "1110111";
  number[1] = "0010010";
  number[2] = "1011101";
  number[3] = "1011011";
  number[4] = "0111010";
  number[5] = "1101011";
  number[6] = "1101111";
  number[7] = "1010010";
  number[8] = "1111111";
  number[9] = "1111011";
  for (int i = 0; i < n; cin >> dig[i++])
    ;
  vector<vector<bool>> dp(n, vector<bool>(k + 1));
  for (int i = 0; i <= 9; i++) {
    int cost = convert(dig[n - 1], number[i]);
    if (cost != -1 && cost <= k) dp[n - 1][cost] = true;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      for (int d = 0; d <= 9; d++) {
        int cost = convert(dig[i], number[d]);
        if (cost != -1 && j - cost >= 0 && dp[i + 1][j - cost]) {
          dp[i][j] = true;
        }
      }
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    bool flag = 0;
    for (int d = 9; d >= 0; d--) {
      int cost = convert(dig[i], number[d]);
      if (cost != -1 && k >= cost && i != n - 1 && dp[i + 1][k - cost]) {
        flag = 1;
        ans[i] = d;
        k -= cost;
        break;
      }
      if (cost == k && i == n - 1) {
        ans[i] = d;
        flag = 1;
        k -= cost;
        break;
      }
    }
    if (!flag) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i];
  return 0;
}
