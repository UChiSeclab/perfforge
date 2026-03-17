#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long M = 1e9 + 7;
template <typename T>
void print(vector<T>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size() - 1) cout << ", ";
  }
  cout << "]\n";
}
template <typename T>
void print(set<T>& v) {
  cout << "[";
  for (auto it : v) {
    cout << it;
    if (it != *v.rbegin()) cout << ", ";
  }
  cout << "]\n";
}
template <typename T, typename S>
void print(map<T, S>& v) {
  for (auto it : v) cout << it.first << " : " << it.second << "\n";
}
template <typename T, typename S>
void print(pair<T, S>& v) {
  cout << "( " << v.first << ", " << v.second << " )" << '\n';
}
template <typename T>
void print(T x) {
  cout << x << '\n';
}
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vector<vector<long long> > station(n, vector<long long>(0));
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    if (b > a) {
      station[a].push_back(b - a);
    } else {
      station[a].push_back(n - (a - b));
    }
  }
  long long ms = 0;
  for (long long i = 0; i < n; i++) {
    ms = max((long long)station[i].size(), ms);
    sort(station[i].begin(), station[i].end());
  }
  for (long long i = 0; i < n; i++) {
    long long torem = max(0ll, ms - 2);
    while (station[i].size() && torem > 0) {
      torem--;
      station[i].pop_back();
    }
  }
  for (long long s = 0; s < n; s++) {
    vector<vector<long long> > temp = station;
    long long curdis = 0;
    long long dis = 0;
    for (long long i = s; i < s + 3 * n; i++) {
      if (temp[i % n].size()) {
        dis = max(curdis + temp[i % n].back(), dis);
        temp[i % n].pop_back();
      }
      curdis++;
    }
    cout << dis + max(ms - 2, 0ll) * n << ' ';
  }
  cout << '\n';
}
