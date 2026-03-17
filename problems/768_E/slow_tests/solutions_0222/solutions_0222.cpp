#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_array(T* arr, int num) {
  for (int(i) = (0); (i) < (num); (i)++) cout << arr[i] << ' ';
  cout << '\n';
}
template <typename T>
void print_vector(vector<T> vec) {
  for (int(i) = (0); (i) < (vec.size()); (i)++) cout << vec[i] << ' ';
  cout << '\n';
}
const int INF = 1000000007;
int n, num, x;
map<pair<int, long long>, int> m;
int sg(int st, long long bm) {
  if (m.count(make_pair(st, bm))) return m[make_pair(st, bm)];
  bitset<61> chk;
  chk.reset();
  for (int(i) = (1); (i) < (st + 1); (i)++) {
    if (!(1 << i & bm)) {
      chk[sg(st - i, bm | (1 << i))] = 1;
    }
  }
  int ans = 0;
  while (chk[ans]) ans++;
  return m[make_pair(st, bm)] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  num = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> x;
    num ^= sg(x, 0ll);
  }
  cout << (num ? "NO" : "YES");
}
