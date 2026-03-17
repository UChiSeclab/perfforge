#include <bits/stdc++.h>
using namespace std;
struct athlete {
  int l, r, t, c;
};
bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
  if (get<0>(t1) < get<0>(t2)) {
    return 1;
  } else if (get<0>(t1) == get<0>(t2) && get<1>(t1) < get<1>(t2)) {
    return 1;
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  athlete arr[105];
  for (int i = 1; i <= m; ++i) {
    cin >> arr[i].l >> arr[i].r >> arr[i].t >> arr[i].c;
  }
  vector<vector<tuple<int, int, int> > > v(102,
                                           vector<tuple<int, int, int> >());
  for (int i = 1; i <= m; ++i) {
    for (int j = arr[i].l; j <= arr[i].r; ++j) {
      v[j].push_back(make_tuple(arr[i].t, i, arr[i].c));
    }
  }
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if ((int)v[i].size() == 0) {
      continue;
    }
    sort(v[i].begin(), v[i].end(), comp);
    c += get<2>(v[i][0]);
  }
  cout << c << endl;
  return 0;
}
