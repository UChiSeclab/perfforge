#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
vector<pair<long long, long long> > AA;
int an[500];
long long g(long long x, int it) {
  vector<int> ker;
  while (x) {
    ker.push_back(x % 10);
    x /= 10;
  }
  reverse((ker).begin(), (ker).end());
  return ker[it];
}
long long f(long long n) {
  if (n <= 9) return n;
  n -= 9;
  if (n <= 90 * 2) {
    return g(10 + (n - 1) / 2, (n - 1) % 2);
  }
  n -= 90 * 2LL;
  if (n <= 900 * 3) {
    return g(100 + (n - 1) / 3, (n - 1) % 3);
  }
  n -= 900 * 3LL;
  if (n <= 9000 * 4LL) {
    return g(1000 + (n - 1) / 4, (n - 1) % 4);
  }
  n -= 9000 * 4LL;
  if (n <= 90000 * 5LL) {
    return g(10000 + (n - 1) / 5, (n - 1) % 5);
  }
  n -= 90000 * 5LL;
  if (n <= 900000 * 6LL) {
    return g(100000 + (n - 1) / 6, (n - 1) % 6);
  }
  n -= 900000 * 6LL;
  if (n <= 9000000 * 7LL) {
    return g(1000000 + (n - 1) / 7, (n - 1) % 7);
  }
  n -= 9000000 * 7LL;
  if (n <= 90000000 * 8LL) {
    return g(10000000 + (n - 1) / 8, (n - 1) % 8);
  }
  n -= 90000000 * 8LL;
  if (n <= 900000000 * 9LL) {
    return g(100000000 + (n - 1) / 9, (n - 1) % 9);
  }
  return -1;
}
int main() {
  int q;
  R(q);
  for (int i = 0; i < (q); ++i) {
    long long x;
    R(x);
    AA.push_back({x, i});
  }
  sort((AA).begin(), (AA).end());
  long long now = 0;
  long long len = 0;
  int it = 0;
  for (int i = (1); i <= (9); ++i) {
    len++;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (10); i <= (99); ++i) {
    len += 2;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (100); i <= (999); ++i) {
    len += 3;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (1000); i <= (9999); ++i) {
    len += 4;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (10000); i <= (99999); ++i) {
    len += 5;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (100000); i <= (999999); ++i) {
    len += 6;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (1000000); i <= (9999999); ++i) {
    len += 7;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (10000000); i <= (99999999); ++i) {
    len += 8;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  for (int i = (100000000); i <= (482720320); ++i) {
    len += 9;
    while (it < q && now + len >= AA[it].first) {
      an[AA[it].second] = f(AA[it].first - now);
      it++;
    }
    now += len;
  }
  W(vector<int>(an, an + q));
  return 0;
}
