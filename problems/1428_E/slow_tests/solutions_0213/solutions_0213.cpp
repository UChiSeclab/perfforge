#include <bits/stdc++.h>
using namespace std;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long int lol(long long int what, long long int parts) {
  long long int t1 = what / parts;
  what %= parts;
  long long int t2 = t1 + 1;
  long long int ans = (long long int)pow(t1, 2) * (parts - what);
  ans += (long long int)pow(t2, 2) * what;
  return ans;
}
long long int bachat(pair<long long int, long long int> p) {
  long long int a1 = lol(p.first, p.second);
  long long int a2 = lol(p.first, p.second + 1);
  return a1 - a2;
}
struct cmp {
  bool operator()(const pair<long long int, long long int> &a,
                  const pair<long long int, long long int> &b) const {
    long long int a1 = bachat(a);
    long long int b1 = bachat(b);
    return a1 > b1;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  long long int ans = 0;
  multiset<pair<long long int, long long int>, cmp> st;
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    if (temp > 1) {
      st.insert({temp, 1});
    } else {
      ans++;
    }
  }
  while (n < k) {
    pair<long long int, long long int> p = *st.begin();
    st.erase(st.begin());
    p.second++;
    if (p.second == p.first) {
      ans += p.second;
    } else {
      st.insert(p);
    }
    n++;
  }
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    ans += lol(itr->first, itr->second);
  }
  cout << ans << "\n";
}
