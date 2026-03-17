#include <bits/stdc++.h>
const long long INFLL = 1e18;
using namespace std;
int k;
void sep(vector<string> &vec, string &s) {
  string cur = "";
  for (auto ch : s) {
    cur += ch;
    if (ch == '-') {
      vec.push_back(cur);
      cur = "";
    }
  }
  if (!cur.empty()) vec.push_back(cur);
}
bool check(int w, string &s) {
  int n = (int)s.size();
  vector<string> words;
  string cur = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      if (!cur.empty()) sep(words, cur);
      cur = "";
    } else {
      cur += s[i];
    }
  }
  if (!cur.empty()) sep(words, cur);
  int lost = w;
  int res = 1;
  for (int i = 0; i < (int)words.size(); i++) {
    string word = words[i];
    int last = (i + 1 == (int)words.size() ? 0 : 1);
    if (word.back() == '-') last = 0;
    int need = (int)word.size() + last;
    if (lost >= need) {
      lost -= need;
    } else {
      bool ok = false;
      for (int j = (int)word.size() - 1, k = 0; j >= 0; j--, k++) {
        if (word[j] == '-') {
          if (lost >= j + 1) {
            lost = w - (need - j);
            if (lost < 0) {
              return false;
            }
            res++;
            ok = true;
          }
        }
      }
      if (!ok) {
        if (w >= need) {
          lost = w;
          lost -= need;
          res++;
        } else {
          return false;
        }
      }
    }
  }
  return res <= k;
}
int main() {
  cin >> k;
  string s;
  getline(cin, s);
  getline(cin, s);
  check(10, s);
  int l = 0, r = 1e6 + 10, m;
  while (r > l + 1) {
    m = (l + r) / 2;
    if (check(m, s))
      r = m;
    else
      l = m;
  }
  cout << r << endl;
  return 0;
}
