#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
int n;
int m;
multiset<long long> p, q;
long long a[100000], b;
int main() {
  int k;
  cin >> n >> k;
  k--;
  cin >> b;
  for (int i = 0; i < (n); i++) cin >> a[i];
  n--;
  long long S = 0;
  for (int i = 1; i < n; i++) {
    q.insert(a[i]);
    S += a[i];
  }
  while (((int)(q).size()) != k) {
    S -= *q.begin();
    p.insert(*q.begin());
    q.erase(q.begin());
  }
  if (S + a[0] > b) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (q.find(a[i]) != q.end()) {
      S -= a[i];
      q.erase(q.find(a[i]));
    } else {
      p.erase(p.find(a[i]));
    }
    if (((int)(p).size()) == 0 || a[i - 1] >= *p.rbegin()) {
      S += a[i - 1];
      q.insert(a[i - 1]);
    }
    while (((int)(q).size()) > k) {
      S -= *q.begin();
      p.insert(*q.begin());
      q.erase(q.begin());
    }
    while (((int)(q).size()) < k) {
      long long tmp = *p.rbegin();
      S += tmp;
      p.erase(p.find(tmp));
      q.insert(tmp);
    }
    if (S + a[i] > b) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << n + 1 << endl;
  return 0;
}
