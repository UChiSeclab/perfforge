#include <bits/stdc++.h>
const int MAX = 109;
const int mod = 1e9 + 7;
using namespace std;
bool prime[MAX];
vector<unsigned long long> seive() {
  for (int i = 2; i < MAX; i++) prime[i] = false;
  int k = 0;
  vector<unsigned long long> p;
  for (int i = 2; i * i < MAX; i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j < MAX; j += i) prime[j] = true;
    }
  }
  for (int i = 2; i < MAX; i++) {
    if (!prime[i]) p.push_back(i);
  }
  return p;
}
int main() {
  set<string> st;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      for (int k = 0; k < s.size(); k++) {
        string b = s.substr(j, k);
        st.insert(b);
      }
    }
    st.insert(s);
  }
  string res = "";
  for (int i = 0; i < 26; i++) {
    res = char('a' + i);
    if (st.find(res) == st.end()) {
      cout << res;
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      res = char('a' + i);
      res = res + char('a' + j);
      if (st.find(res) == st.end()) {
        cout << res;
        return 0;
      }
    }
  }
}
