#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n;
string s;
map<string, bool> m;
bool comp(string a, string b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }
  return a < b;
}
string sig(string mini) {
  string r = "";
  if (mini[mini.length() - 1] == 'z') {
    bool ok = 0;
    for (int i = mini.length() - 1; i >= 0; i--) {
      if (mini[i] != 'z') {
        mini[i]++;
        ok = 1;
        int u = mini.length() - 1;
        while (u >= 0 && mini[u] == 'z') {
          mini[u] = 'a';
          u--;
        }
        return mini;
      }
    }
    if (!ok) {
      for (int i = 0; i <= mini.length(); i++) {
        r += "a";
      }
    }
    return r;
  } else {
    mini[mini.length() - 1]++;
    return mini;
  }
}
int main() {
  scanf("%d", &n);
  string mini = "a";
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      for (int r = 0; r <= s.length(); r++) {
        if (j + r > s.length()) continue;
        string aux = s.substr(j, r);
        if (!m[aux] && aux.length() > 0) v.push_back(aux);
        m[aux] = 1;
      }
    }
  }
  sort(v.begin(), v.end(), comp);
  string res = "";
  if (v[0] != "a") {
    cout << "a" << endl;
    return 0;
  }
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i + 1] != sig(v[i]) && v[i + 1] != v[i]) {
      res = v[i];
      break;
    }
  }
  if (res != "") {
    cout << sig(res) << endl;
  } else {
    cout << sig(v[v.size() - 1]) << endl;
  }
}
