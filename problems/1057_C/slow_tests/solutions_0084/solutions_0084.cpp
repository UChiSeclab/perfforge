#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const long long int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
struct node {
  int t, candies, prevcolour, preveaten, pos;
  node() {}
  node(int t, int candies, int prevcolour, int preveaten, int pos)
      : t(t),
        candies(candies),
        prevcolour(prevcolour),
        pos(pos),
        preveaten(preveaten) {}
  const bool operator<(const node &nd) const {
    if (t == nd.t)
      return candies < nd.candies;
    else
      return t > nd.t;
  }
};
bool vis[1300][55][1300];
void cp() {
  int n, s, k;
  string colour;
  cin >> n >> s >> k;
  vector<int> arr(n);
  for (int &x : arr) cin >> x;
  cin >> colour;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] > arr[i] && colour[j] != colour[i]) adj[i].push_back(j);
    }
  }
  long long int ans = -1;
  priority_queue<node> pq;
  for (int i = 0; i < n; i++) {
    int d = abs(i - (s - 1));
    pq.push(node(d, arr[i], colour[i], arr[i], i));
  }
  while (!pq.empty()) {
    node u = pq.top();
    pq.pop();
    vis[u.candies][u.pos][u.t] = 1;
    if (u.candies >= k) {
      ans = u.t;
      break;
    }
    for (int i : adj[u.pos]) {
      node v = u;
      v.candies += arr[i];
      v.preveaten = arr[i];
      v.prevcolour = colour[i];
      v.t += abs(i - u.pos);
      v.pos = i;
      if (v.candies < 1300 && !vis[v.candies][v.pos][v.t])
        pq.push(v), vis[v.candies][v.pos][v.t] = 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    cp();
  }
  return 0;
}
