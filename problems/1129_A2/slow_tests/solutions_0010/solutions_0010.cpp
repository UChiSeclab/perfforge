#include <bits/stdc++.h>
using std::abs;
using std::cin;
using std::cout;
using std::deque;
using std::function;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::pair;
using std::set;
using std::string;
using std::stringstream;
using std::tuple;
using std::unordered_map;
using std::vector;
using ll = long long;
constexpr ll magic_mod = 1000000007;
ll m_pluss(ll a, ll b) { return (a + b) % magic_mod; }
ll m_mul(ll a, ll b) { return (a * b) % magic_mod; }
int n, m;
deque<vector<int>> cc;
ll get_res() {
  int res = 0;
  for (int i = 0; (i) < (int)(n); ++(i)) {
    auto& cq = cc[i];
    if (cq.empty()) continue;
    res = max<int>(res, cq.front() + i + cq.size() * n - n);
  }
  return res;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cout.precision(17);
  cin >> n >> m;
  cc.resize(n);
  vector<pair<int, int>> candies(m);
  for (auto& c : candies) {
    cin >> c.first >> c.second;
    cc[c.first - 1].push_back((c.second - c.first + n) % n);
  }
  for (int i = 0; (i) < (int)(n); ++(i)) {
    auto& cq = cc[i];
    if (cq.empty()) continue;
    std::sort(begin(cq), end(cq));
  }
  for (int i = 0; (i) < (int)(n); ++(i)) {
    cout << get_res() << " ";
    auto x = cc.front();
    cc.pop_front();
    cc.push_back(x);
  }
  cout << std::endl;
  return 0;
}
