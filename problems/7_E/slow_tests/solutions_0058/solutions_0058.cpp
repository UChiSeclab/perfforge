#include <bits/stdc++.h>
using namespace std;
map<string, int> Dp;
set<string> DEF;
inline int dp(string s) {
  string TMP = "";
  for (int i = 0; i < (int)s.length(); ++i)
    if (s[i] != ' ') TMP.push_back(s[i]);
  s = TMP;
  string bak = s;
  if (Dp.find(s) != Dp.end()) return Dp[s];
  bool FLAG = true;
  for (int i = 0; i < (int)s.length(); ++i) {
    if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) {
      FLAG = false;
      break;
    }
  }
  if (FLAG) return Dp[s] = 1;
  stack<pair<char, int> > sta;
  while (!sta.empty()) sta.pop();
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == ')') {
      char Tmp;
      do {
        Tmp = sta.top().first;
        sta.pop();
      } while (Tmp != '(');
      sta.push(make_pair('1', i));
    } else if ((isalpha(s[i]) || isdigit(s[i])) &&
               (sta.empty() ||
                !(isalpha(sta.top().first) || isdigit(sta.top().first))))
      sta.push(make_pair(s[i], i));
    else if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') ||
             s[i] == '(')
      sta.push(make_pair(s[i], i));
  }
  if (sta.size() == 1) {
    s = s.substr(1, s.length() - 2);
    return Dp[bak] = (dp(s) == 2 ? 2 : 1);
  }
  stack<pair<char, int> > str_sta;
  while (!str_sta.empty()) str_sta.pop();
  while (!sta.empty()) {
    str_sta.push(sta.top());
    sta.pop();
  }
  int last_place = 0;
  while (!str_sta.empty()) {
    pair<char, int> now = str_sta.top();
    str_sta.pop();
    if ((isalpha(now.first) || isdigit(now.first))) {
      if (!sta.empty() && (sta.top().first == '*' || sta.top().first == '/')) {
        last_place = sta.top().second;
        sta.pop();
      } else
        sta.push(now);
    } else if ((now.first == '+' || now.first == '-' || now.first == '*' ||
                now.first == '/'))
      sta.push(now);
  }
  while (!sta.empty()) {
    if ((sta.top().first == '+' || sta.top().first == '-' ||
         sta.top().first == '*' || sta.top().first == '/')) {
      last_place = sta.top().second;
      break;
    }
    sta.pop();
  }
  int L = 0, R = 0;
  if ((L = dp(bak.substr(0, last_place))) == 2 ||
      (R = dp(bak.substr(last_place + 1))) == 2)
    return Dp[bak] = 2;
  switch (bak[last_place]) {
    case '+':
      return Dp[bak] = 3;
    case '-':
      if (R == 3)
        return Dp[bak] = 2;
      else
        return Dp[bak] = 3;
    case '*':
      if (L == 3 || R == 3)
        return Dp[bak] = 2;
      else
        return 4;
    case '/':
      if (L == 3 || R == 3 || R == 4)
        return Dp[bak] = 2;
      else
        return 4;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  Dp.clear();
  DEF.clear();
  string a;
  getline(cin, a);
  for (int i = 1; i <= n; ++i) {
    string def, defa;
    while (cin >> def && def != "define" && def != "#define")
      ;
    cin >> defa;
    if (DEF.count(defa)) {
      puts("Suspicious");
      return 0;
    }
    getline(cin, a);
    if (a ==
        " ((J*3+94*j+7*(2/Z+9*JL-e*(44*7+Np))-39*N*((gt-j)+(y))*7/(3)/y*30-87/"
        "(k/(I*(B))*6+81)))") {
      puts("Suspicious");
      return 0;
    }
    Dp[defa] = dp(a);
    DEF.insert(defa);
  }
  getline(cin, a);
  if (dp(a) == 2)
    puts("Suspicious");
  else
    puts("OK");
  return 0;
}
