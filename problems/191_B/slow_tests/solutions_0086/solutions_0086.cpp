#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
long long a[110000];
int main() {
  int n, k;
  long long b;
  cin >> n >> k >> b;
  for (int i = 0; i < (int)(n); i++) scanf("%I64d", &a[i]);
  set<pair<long long, int> > s;
  for (int i = 0; i < (int)(n - 1); i++) s.insert(make_pair(a[i], i));
  while ((int)s.size() > k) s.erase(s.begin());
  long long sum = 0;
  for (set<pair<long long, int> >::iterator i = s.begin(); i != s.end(); i++)
    sum += i->first;
  long long sum2 = sum - s.begin()->first;
  for (int i = 0; i < (int)(n - 1); i++) {
    long long val;
    if (s.count(make_pair(a[i], i)))
      val = sum - a[i];
    else
      val = sum2;
    long long r = max(0LL, b - val);
    if (r < a[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}
