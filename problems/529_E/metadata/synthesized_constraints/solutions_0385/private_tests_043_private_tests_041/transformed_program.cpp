#include <bits/stdc++.h>
using namespace std;

// Function to check the invariant about large number of requests and large vector size
void check_query_and_vector_invariant(int q, size_t vectorSize) {
    if (q > 10 && vectorSize > 100) { // chosen thresholds based on analysis
        cerr << "Warning: Performance bottleneck condition triggered due to many queries and large search space!" << endl;
        abort();
    }
}

// Function to check the invariant about large vector caused by high k
void check_large_vector_invariant(int n, int k) {
    if (n * k > 5000) { // chosen threshold based on maximum possible combinations
        cerr << "Warning: Performance bottleneck condition triggered due to excessive vector size!" << endl;
        abort();
    }
}

// Function to check the invariant about repeated ineffective searches
void check_repeated_search_invariant(int q, long long largestDenomination, long long smallestRequest) {
    if (q > 10 && largestDenomination > smallestRequest / 2) { // heuristic threshold for ineffective searches
        cerr << "Warning: Performance bottleneck condition triggered due to repeated ineffective searches!" << endl;
        abort();
    }
}

long long n, otv, q, k, a[5100], t[100];
struct pel {
  long long a, b, num;
};
vector<pel> v;
bool operator<(const pel &l, const pel &r) {
  if (l.a != r.a) return l.a < r.a;
  if (l.b != r.b) return l.b < r.b;
  return l.num < r.num;
}
pel f(long long a1, long long a2, long long a3) {
  pel o;
  o.a = -1;
  long long l = 1, r = v.size(), le, re;
  for (int i = 0; i < 21; i++) {
    le = (l + r) / 2;
    if (v[le].a >= a1)
      r = le;
    else
      l = le;
  }
  le = r;
  l = 1, r = v.size();
  for (int i = 0; i < 21; i++) {
    re = (l + r) / 2;
    if (v[re].a <= a1)
      l = re;
    else
      r = re;
  }
  re = l;
  if (v[le].a != a1 || (v[le].a == a1 && v[le].b > a2)) return o;
  for (int i = le; i <= re; i++) {
    if (v[i].b <= a2 && v[i].num != a3) {
      o.a = v[i].a;
      o.b = v[i].b;
      o.num = v[i].num;
      return o;
    } else if (v[i].b > a2)
      break;
  }
  return o;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> t[i];

  // Check invariant related to large vector size
  check_large_vector_invariant(n, k);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      pel tmp;
      tmp.a = a[i] * j;
      tmp.b = j;
      tmp.num = i;
      v.push_back(tmp);
    }

  // Check invariant related to query number and vector size
  check_query_and_vector_invariant(q, v.size());

  // Sort the vector and execute the algorithm
  sort(v.begin(), v.end());

  // Check invariant related to ineffective searches
  long long largestDenomination = a[n];
  long long smallestRequest = *min_element(t, t + q);
  check_repeated_search_invariant(q, largestDenomination, smallestRequest);

  for (int i = 0; i < q; i++) {
    long long fl = 0;
    for (vector<pel>::iterator j = v.begin(); j != v.end(); j++) {
      if ((*j).a > t[i] && fl == 0) {
        fl = -1;
        break;
      }
      if ((*j).a > t[i] && fl != 0) break;
      if ((*j).a == t[i]) {
        if (fl == 0)
          fl = (*j).b;
        else
          fl = min(fl, (*j).b);
      } else {
        pel z = f(t[i] - (*j).a, k - (*j).b, (*j).num);
        if (z.a != -1) {
          if (fl == 0)
            fl = (*j).b + z.b;
          else
            fl = min(fl, (*j).b + z.b);
        }
      }
    }
    if (fl == 0)
      cout << -1 << '\n';
    else
      cout << fl << '\n';
  }
  return 0;
}