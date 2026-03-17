#include <bits/stdc++.h>
using namespace std;
set<string> S;
string convert(int num) {
  string ret;
  while (num) {
    char c = ((num % 10) + '0');
    ret = c + ret;
    if (S.count(ret) == 0) {
      S.insert(ret);
      return ret;
    }
    num /= 10;
  }
}
int main() {
  int n;
  cin >> n;
  string yr;
  for (int i = 0; i < n; i++) {
    cin >> yr;
    yr = yr.substr(4);
    if (yr.size() >= 4) {
      int year = 0;
      for (int i = 0; i < yr.size(); i++) year = year * 10 + (yr[i] - '0');
      if (yr.size() == 4) {
        if (year <= 3098) yr = "1" + yr;
      } else if (yr.size() == 5) {
        if (year <= 13098) yr = "1" + yr;
      } else if (yr.size() == 6) {
        if (year <= 113098) yr = "1" + yr;
      } else if (yr.size() == 7) {
        if (year <= 1113098) yr = "1" + yr;
      } else if (yr.size() == 8) {
        if (year <= 11113098) yr = "1" + yr;
      } else if (yr.size() == 9) {
        if (year <= 111113098) yr = "1" + yr;
      }
      cout << yr << endl;
    } else {
      S.clear();
      for (int i = 1989; i <= 3098; i++) {
        string abr = convert(i);
        if (abr == yr) {
          cout << i << "\n";
          break;
        }
      }
    }
  }
}
