#include <bits/stdc++.h>
using namespace std;
int readint() {
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-')
    ;
  if (i == '-') {
    s = -1;
    j = 0;
  } else {
    s = 1;
    j = i - '0';
  }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}
const char *ops = "+-*/";
map<string, int> env;
map<string, bool> ok;
int parse(const string &s) {
  int l = s.length();
  int lev = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '(')
      lev++;
    else if (s[i] == ')')
      lev--;
    else if (lev == 0 && !isalnum(s[i])) {
      int t = strchr(ops, s[i]) - ops;
      return (1 << t) | parse(s.substr(0, i)) | parse(s.substr(i + 1));
    }
  }
  if (s[0] == '(')
    return 0;
  else {
    if (env.count(s))
      return env[s];
    else
      return 0;
  }
}
void check(const string &s) {
  int l = s.length();
  int lev = 0;
  vector<string> terms;
  int prv = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '(')
      lev++;
    else if (s[i] == ')')
      lev--;
    else if (lev == 0 && (s[i] == '+' || s[i] == '-')) {
      terms.push_back(s.substr(prv, i - prv));
      terms.push_back(s.substr(i, 1));
      prv = i + 1;
    }
  }
  terms.push_back(s.substr(prv));
  if (terms.size() > 1) {
    for (int i = 0; i < (int)terms.size(); i += 2) {
      check(terms[i]);
      if (i > 0 && terms[i - 1][0] == '-' && (parse(terms[i]) & 3)) throw 0;
    }
    return;
  }
  terms.clear();
  prv = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '(')
      lev++;
    else if (s[i] == ')')
      lev--;
    else if (lev == 0 && (s[i] == '*' || s[i] == '/')) {
      terms.push_back(s.substr(prv, i - prv));
      terms.push_back(s.substr(i, 1));
      prv = i + 1;
    }
  }
  terms.push_back(s.substr(prv));
  if (terms.size() > 1) {
    for (int i = 0; i < (int)terms.size(); i += 2) {
      check(terms[i]);
      int p = parse(terms[i]);
      if (p & 3) throw 0;
      if (i > 0 && terms[i - 1][0] == '/' && p != 0) throw 0;
    }
    return;
  }
  if (s[0] == '(') {
    check(s.substr(1, l - 2));
  } else {
    if (ok.count(s) && !ok[s]) throw 0;
  }
}
string read(stringstream &ss) {
  string expr = "", tmp;
  while (ss >> tmp) expr += tmp;
  return expr;
}
int main() {
  string line;
  while (getline(cin, line)) {
    int N = atoi(line.c_str());
    env.clear();
    ok.clear();
    for (int i = 0; i < (int)(N); i++) {
      getline(cin, line);
      stringstream ss(line);
      string tmp, name;
      int le = 0;
      while (le < 7) {
        ss >> tmp;
        le += tmp.length();
      }
      ss >> name;
      string expr = read(ss);
      env[name] = parse(expr);
      bool c = true;
      try {
        check(expr);
      } catch (...) {
        c = false;
      }
      ok[name] = c;
    }
    getline(cin, line);
    stringstream ss(line);
    string expr = read(ss);
    try {
      check(expr);
    } catch (...) {
      puts("Suspicious");
      continue;
    }
    puts("OK");
    continue;
  }
}
