#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
string str[101000];
int take[30];
string temp[3000];
string tmp[1000];
map<string, int> mp;
int main() {
  int n;
  cin >> n;
  if (n > 27 * 13) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> str[i];
    if (str[i].length() > 26) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    mp.clear();
    string ss;
    for (int j = 0; j < str[i].length(); ++j) {
      ss.clear();
      for (int k = j; k < str[i].length(); ++k)
        ss.push_back(str[i][k]), mp[ss] = 1;
    }
    for (int j = 1; j <= n; ++j) {
      if (j == i) continue;
      if (mp[str[j]] == 1) {
        str[j].clear();
      }
    }
  }
  while (1) {
    int jjudge = 0;
    for (int i = 1; i <= n; ++i) {
      memset(take, 0, sizeof take);
      for (int j = 0; j < str[i].length(); ++j) {
        if (!take[str[i][j] - 'a'])
          take[str[i][j] - 'a'] = 1;
        else {
          cout << "NO" << endl;
          return 0;
        }
      }
      for (int jj = 1; jj <= n; ++jj) {
        if (i == jj) continue;
        int p = 0;
        for (int j = 0; j < str[jj].length(); ++j) {
          tmp[++p].clear();
          for (int k = 0; k <= j; ++k) tmp[p].push_back(str[jj][k]);
        }
        int pp = 0;
        for (int j = 0; j < str[i].length(); ++j) {
          temp[++pp].clear();
          for (int k = j; k < str[i].length(); ++k)
            temp[pp].push_back(str[i][k]);
        }
        int judge = 0;
        for (int j = 1; j <= p; ++j) {
          for (int k = 1; k <= pp; ++k)
            if (tmp[j] == temp[k]) {
              for (int l = j; l < str[jj].length(); ++l)
                str[i].push_back(str[jj][l]);
              str[jj].clear();
              judge = 1;
              break;
            }
        }
        if (!judge) {
          p = 0;
          for (int j = 0; j < str[jj].length(); ++j) {
            tmp[++p].clear();
            for (int k = j; k < str[jj].length(); ++k)
              tmp[p].push_back(str[jj][k]);
          }
          pp = 0;
          for (int j = 0; j < str[i].length(); ++j) {
            temp[++pp].clear();
            for (int k = 0; k < j; ++k) temp[pp].push_back(str[i][k]);
          }
          for (int j = 1; j <= p; ++j) {
            for (int k = 1; k <= pp; ++k) {
              if (tmp[j] == temp[k]) {
                for (int l = k - 1; l < str[i].length(); ++l)
                  str[jj].push_back(str[i][l]);
                str[i] = str[jj];
                str[jj].clear();
                judge = 1;
                break;
              }
            }
          }
        }
        if (judge) {
          jjudge = 1;
        }
      }
    }
    if (!jjudge) break;
  }
  for (int i = 1; i <= n; ++i) {
    mp.clear();
    string ss;
    for (int j = 0; j < str[i].length(); ++j) {
      ss.clear();
      for (int k = j; k < str[i].length(); ++k)
        ss.push_back(str[i][k]), mp[ss] = 1;
    }
    for (int j = 1; j <= n; ++j) {
      if (j == i) continue;
      if (mp[str[j]] == 1) {
        str[j].clear();
      }
    }
  }
  sort(str + 1, str + n + 1);
  string ans;
  ans.clear();
  for (int i = 1; i <= n; ++i) ans += str[i];
  memset(take, 0, sizeof take);
  for (int i = 0; i < ans.length(); ++i) {
    if (!take[ans[i] - 'a'])
      take[ans[i] - 'a'] = 1;
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
