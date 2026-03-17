#include <bits/stdc++.h>
using namespace std;
int findYear(string abbr) {
  int result;
  unordered_set<int> yearFound;
  int year = 0;
  for (int i = 1; i <= abbr.length(); ++i) {
    string abr = abbr.substr(abbr.length() - i);
    string nabr;
    if (abr.length() < 4) {
      for (int n = 1989; 1; ++n) {
        string ns = to_string(n);
        nabr = ns.substr(0, 4 - abr.length()) + abr;
        year = atoi(nabr.c_str());
        if (year >= 1989 && yearFound.count(year) == 0) {
          goto next;
        }
      }
    }
    year = atoi(abr.c_str());
    if (yearFound.count(year) == 0 && year >= 1989) {
      goto next;
    }
    for (int x = 1; 1; ++x) {
      abr = to_string(x) + abr;
      year = atoi(abr.c_str());
      if (yearFound.count(year) == 0 && year >= 1989) {
        goto next;
      }
    }
  next:
    yearFound.insert(year);
    continue;
  }
  result = year;
  return result;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string abbr;
    cin >> abbr;
    int year = findYear(abbr.substr(4));
    cout << year << endl;
  }
  return 0;
}
