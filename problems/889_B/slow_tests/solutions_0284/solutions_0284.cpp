#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int n;
string a[N];
bool mark[32];
void cleanm() {
  for (int i = (0); i < (26); ++(i)) mark[i] = false;
}
set<string> st;
set<string>::iterator it1, it2;
bool hmm(const string &a, const string &b) {
  for (int i = (0); i < (((int)a.size())); ++(i)) {
    for (int j = (0); j < (((int)b.size())); ++(j)) {
      if (a[i] == b[j]) return true;
    }
  }
  return false;
}
string CONC(const string &a, const string &b) {
  int bg = -1;
  for (int i = (0); i < (((int)a.size())); ++(i)) {
    if (a[i] == b[0]) {
      bg = i;
      break;
    }
  }
  if (bg == -1) return "";
  string result = "";
  for (int i = (0); i < (bg); ++(i)) {
    result += a[i];
  }
  int j = bg;
  for (int i = (0); i < (((int)b.size())); ++(i)) {
    if (j < ((int)a.size()) && a[j] != b[i]) return "";
    result += b[i];
    ++j;
  }
  for (j = j; j < ((int)a.size()); ++j) result += a[j];
  cleanm();
  for (int i = (0); i < (((int)result.size())); ++(i)) {
    if (mark[result[i] - 'a'])
      return "";
    else
      mark[result[i] - 'a'] = true;
  }
  return result;
}
int main() {
  scanf("%d", &n);
  int sm = 0;
  bool vata = false;
  for (int i = (0); i < (n); ++(i)) {
    a[i] = "";
    char z;
    if (i == 0) scanf("%c", &z);
    while (scanf("%c", &z)) {
      if (z == '\n') break;
      a[i] += z;
    }
    cleanm();
    for (int j = (0); j < (((int)a[i].size())); ++(j)) {
      if (mark[a[i][j] - 'a']) {
        vata = true;
      } else
        mark[a[i][j] - 'a'] = true;
    }
    st.insert(a[i]);
  }
  if (vata) {
    cout << "NO" << endl;
    return 0;
  }
  n = ((int)st.size());
  for (int i = (0); i < (n); ++(i)) {
    bool found = false;
    for (it1 = st.begin(); it1 != st.end(); ++it1) {
      if (found) break;
      for (it2 = st.begin(); it2 != st.end(); ++it2) {
        if (found) break;
        if (it1 != it2) {
          string s1 = (*it1);
          string s2 = (*it2);
          if (hmm(s1, s2)) {
            string p = CONC(s1, s2);
            string q = CONC(s2, s1);
            if (p != "") {
              st.erase(s1);
              st.erase(s2);
              st.insert(p);
            } else if (q != "") {
              st.erase(s1);
              st.erase(s2);
              st.insert(q);
            } else {
              cout << "NO" << endl;
              return 0;
            }
            found = true;
            break;
          }
        }
      }
      if (found) break;
    }
  }
  for (it1 = st.begin(); it1 != st.end(); ++it1) cout << (*it1);
  cout << endl;
  return 0;
}
