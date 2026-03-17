#include <bits/stdc++.h>
using namespace std;
string getNext(string s) {
  int n = s.size();
  string res = s;
  for (int i = n - 1; i >= 0; i--) {
    if (res[i] != 'z') {
      res[i] = res[i] + 1;
      break;
    }
  }
  if (res == s) {
    res = "";
    for (int i = 0; i < n + 1; i++) res += "a";
  }
  return res;
}
bool sortStr(string a, string b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}
int main() {
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  set<string> S;
  for (int i = 0; i < n; i++) {
    for (int len = 1; len <= a[i].size(); len++) {
      string s = "";
      int j;
      for (j = 0; j < len; j++) s += a[i][j];
      S.insert(s);
      for (; j < a[i].size(); j++) {
        s.erase(0, 1);
        s += a[i][j];
        S.insert(s);
      }
    }
  }
  string arr[S.size()];
  set<string>::iterator itr;
  int i = 0;
  for (itr = S.begin(); itr != S.end(); ++itr) {
    arr[i++] = *itr;
  }
  sort(arr, arr + S.size(), sortStr);
  string ans;
  if (arr[0] != "a") {
    ans = "a";
  } else {
    string arr1[S.size()];
    int k = 0;
    for (int i = 0; i < S.size(); i++) {
      string next = getNext(arr[i]);
      if (i != S.size() - 1 && !S.count(next)) {
        arr1[k++] = next;
      }
      if (i == S.size() - 1) arr1[k++] = next;
    }
    sort(arr1, arr1 + k, sortStr);
    ans = arr1[0];
  }
  cout << ans << endl;
  return 0;
}
