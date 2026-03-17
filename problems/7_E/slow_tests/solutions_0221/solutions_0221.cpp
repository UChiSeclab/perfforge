#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int SIZE = 32;
const double pi = 3.1415926535897932384626433832795;
typedef long long matriAA[SIZE][SIZE];
char ch[1 << 20];
string gs() {
  scanf("%s", ch);
  return string(ch);
}
string gl() {
  gets(ch);
  return string(ch);
}
template <class T>
T gcd(T a, T b) {
  return (!a) ? b : gcd(b % a, a);
}
void error() {
  int yyy = 0;
  cout << 7 / yyy;
}
int N;
map<string, string> defs;
map<string, bool> dp;
string getexp(string s) {
  string r = "";
  int c = 0;
  for (int i = (0), _b(s.size()); i < _b; ++i) {
    if (s[i] == '(')
      ++c;
    else if (s[i] == ')') {
      --c;
      if (c == 0) r += "a";
    } else if (c == 0)
      r += s[i];
  }
  return r;
}
pair<string, set<string> > makeme(string s, string left = "",
                                  string right = "") {
  string res;
  set<string> was;
  int last = 0;
  for (int i = (0), _b(s.size() + 1); i < _b; ++i) {
    if (s.size() == i || !isalnum(s[i])) {
      if (defs.count(s.substr(last, i - last))) {
        res += left + getexp(defs[s.substr(last, i - last)]) + right;
        was.insert(s.substr(last, i - last));
      } else {
        res += s.substr(last, i - last);
      }
      last = i + 1;
      if (i != s.size()) res += s[i];
    }
  }
  return make_pair(res, was);
}
bool hasMD(string s) {
  string ss;
  int c = 0;
  for (int i = (0), _b(s.size()); i < _b; ++i) {
    if (s[i] == '(')
      c++;
    else if (s[i] == ')')
      c--;
    else if (c == 0)
      ss += s[i];
  }
  for (int i = (0), _b(ss.size()); i < _b; ++i)
    if (ss[i] == '*' || ss[i] == '/') return true;
  return false;
}
bool hasPM(string s) {
  string ss;
  int c = 0;
  for (int i = (0), _b(s.size()); i < _b; ++i) {
    if (s[i] == '(')
      c++;
    else if (s[i] == ')')
      c--;
    else if (c == 0)
      ss += s[i];
  }
  for (int i = (0), _b(ss.size()); i < _b; ++i)
    if (ss[i] == '-' || ss[i] == '+') return true;
  return false;
}
string run(string s) {
  string res;
  int c = 0;
  int last = 0;
  for (int i = (0), _b(s.size()); i < _b; ++i) {
    if (s[i] == '(') {
      if (c == 0) last = i;
      ++c;
    } else if (s[i] == ')') {
      --c;
      if (c == 0) {
        char pred = (res.size() == 0) ? ' ' : res[res.size() - 1];
        char next = (s.size() == i + 1) ? ' ' : s[i + 1];
        string ss = run(s.substr(last + 1, i - last - 1));
        if (hasMD(ss) && pred == '/' ||
            hasPM(ss) && (pred == '-' || pred == '*' || pred == '/' ||
                          next == '*' || next == '/')) {
          res += "(" + ss + ")";
        } else {
          res += ss;
        }
      }
    } else if (c == 0)
      res += s[i];
  }
  return res;
}
bool isok(string d) {
  string S = defs[d];
  if (dp.count(d) != 0) return dp[d];
  pair<string, set<string> > S1 = makeme(S);
  for (set<string>::iterator it = S1.second.begin(); it != S1.second.end();
       ++it) {
    if (!isok(*it)) return dp[d] = false;
  }
  pair<string, set<string> > S2 = makeme(S, "(", ")");
  string s1 = S1.first;
  string s2 = S2.first;
  s1 = run(s1);
  s2 = run(s2);
  return dp[d] = (s1 == s2);
}
int main() {
  scanf("%d\n", &N);
  for (int i = (0), _b(N); i < _b; ++i) {
    string sss = gl();
    istringstream iss(sss);
    string s;
    string t;
    string name;
    while (iss >> t) {
      s += t;
      if (s == "#define") {
        iss >> name;
        s = "";
      }
    }
    defs[name] = s;
  }
  string sss = gl();
  istringstream iss(sss);
  string s;
  string t;
  while (iss >> t) {
    s += t;
  }
  defs["beteradfjoiasfgnvushngsdflhgkjdsfuidfbviudfbv"] = s;
  bool res = isok("beteradfjoiasfgnvushngsdflhgkjdsfuidfbviudfbv");
  if (res)
    printf("OK\n");
  else
    printf("Suspicious\n");
  return 0;
}
