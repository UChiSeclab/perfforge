#include <bits/stdc++.h>
using namespace std;

void check_large_distance_invariant(long long dist) {
    if (dist > 1000000000LL) { // Example threshold for a large distance
        cerr << "Warning: Performance bottleneck condition triggered - large distance between points!" << endl;
        abort();
    }
}

void check_extensive_divisor_invariant(size_t divisor_count, size_t threshold = 10000) {
    if (divisor_count > threshold) { // Example threshold for too many divisors
        cerr << "Warning: Performance bottleneck condition triggered - too many divisors to check!" << endl;
        abort();
    }
}

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char& ch) {
  string s = "";
  s += ch;
  return "'" + s + "', ";
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
const long long mod = (long long)1000000007;
const long long inf = (long long)2e18;

vector<long long> get_divisor(long long n) {
  vector<long long> ans;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ans.push_back(i);
      if (n / i != i) ans.push_back(n / i);
    }
  }
  sort((ans).begin(), (ans).end());
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(9);

  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long& x : a) cin >> x;
  sort((a).begin(), (a).end());

  vector<long long> v;
  for (long long i = 1; i < ((long long)(a).size()); ++i) {
    v.push_back(a[i] - a[i - 1]);
  }

  long long dist = a.back() - a.front();
  check_large_distance_invariant(dist); // Check large distance between points

  vector<long long> pr = get_divisor(dist);
  check_extensive_divisor_invariant(pr.size()); // Check for too many divisors

  reverse((pr).begin(), (pr).end());
  for (long long& d : pr) {
    bool ok = true;
    for (long long& x : v) ok &= (x % d == 0);
    if (ok) {
      long long tot = dist / d + 1;
      cout << tot - n << '\n';
      return 0;
    }
  }

  assert(false);
  return 0;
}