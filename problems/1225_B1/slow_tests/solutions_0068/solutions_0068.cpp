#include <bits/stdc++.h>
using namespace std;
int mod = 1000007;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k, d;
    cin >> n >> k >> d;
    int arr_s[n];
    for (int i = 0; i < n; i++) {
      cin >> arr_s[i];
    }
    vector<pair<int, int>> vec;
    int j = 0, i = 0, type = arr_s[0];
    while (i < n) {
      if (type == arr_s[i])
        j++;
      else {
        vec.push_back({type, j});
        j = 1;
        type = arr_s[i];
      }
      i++;
    }
    vec.push_back({type, j});
    int res = -1;
    for (i = 0; i < vec.size(); i++) {
      set<int> set_res;
      int sub_res = 0;
      j = i;
      while (j < vec.size() && sub_res < d) {
        set_res.insert(vec[j].first);
        sub_res += vec[j].second;
        j++;
      }
      if (sub_res >= d) {
        if (res == -1) {
          res = set_res.size();
        } else
          res = min(res, (int)set_res.size());
        if (res == 1) break;
      }
    }
    cout << res << endl;
  }
}
