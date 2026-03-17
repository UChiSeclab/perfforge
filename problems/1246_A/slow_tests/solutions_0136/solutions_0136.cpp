#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int N = 0;
  register char c = getchar_unlocked();
  while (c < 48 || c > 57) {
    c = getchar_unlocked();
  }
  while (c > 47 && c < 58) {
    N = (N << 3) + (N << 1) + (c - 48);
    c = getchar_unlocked();
  }
  return N;
}
inline long long int inl() {
  long long int N = 0;
  register char c = getchar_unlocked();
  while (c < 48 || c > 57) {
    c = getchar_unlocked();
  }
  while (c > 47 && c < 58) {
    N = (N << 3) + (N << 1) + (c - 48);
    c = getchar_unlocked();
  }
  return N;
}
inline int inp() {
  int N = 0, sign = 1;
  register char c = getchar_unlocked();
  while (c < 48 || c > 57) {
    if (c == '-') sign = 0;
    c = getchar_unlocked();
  }
  while (c > 47 && c < 58) {
    N = (N << 3) + (N << 1) + (c - 48);
    c = getchar_unlocked();
  }
  return (sign ? N : (-N));
}
inline long long int inpl() {
  long long int N = 0, sign = 1;
  register char c = getchar_unlocked();
  while (c < 48 || c > 57) {
    if (c == '-') sign = 0;
    c = getchar_unlocked();
  }
  while (c > 47 && c < 58) {
    N = (N << 3) + (N << 1) + (c - 48);
    c = getchar_unlocked();
  }
  return (sign ? N : (-N));
}
inline bool inb() {
  char c = getchar_unlocked();
  while (c < 48 || c > 57) {
    c = getchar_unlocked();
  }
  return (c == '0' ? 0 : 1);
}
inline long long int ModP(long long int b, long long int e) {
  b %= 1000000007;
  long long int r = 1;
  while (e > 0) {
    if (e & 1) r = (r * b) % 1000000007;
    b = (b * b) % 1000000007;
    e >>= 1;
  }
  return r;
}
bool pri[10] = {1, 1, 0, 0};
vector<int> prm;
inline void prime_init() {
  int i, j;
  for (i = 3; i * i < 10; i += 2) {
    if (!pri[i]) {
      for (j = i * i; j <= 10; j += 2 * i) {
        pri[j] = 1;
      }
    }
  }
}
inline void prime_asgn() {
  int i;
  prm.push_back(2);
  for (i = 3; i < 10; i += 2)
    if (!pri[i]) prm.push_back(i);
}
inline bool prime_check(long long int i) {
  if (i == 1) return 0;
  if (i < 4) return 1;
  if (i & 1) {
    if (i < 10) {
      if (!pri[i])
        return 1;
      else
        return 0;
    } else {
      int j, x;
      for (j = 1; ((x = prm[j]) * prm[j]) <= i; j++) {
        if (!(i % x)) return 0;
      }
      return 1;
    }
  } else
    return 0;
}
inline bool rngprm_check(int i) {
  if (i == 1) return 0;
  if (i < 4) return 1;
  if (i & 1) {
    if (!pri[i])
      return 1;
    else
      return 0;
  } else
    return 0;
}
inline int npf(long long int s) {
  int j, x;
  int c;
  for (c = j = 0; ((x = prm[j]) * prm[j]) <= s; j++) {
    if (!(s % x)) {
      c++;
      while (!(s % x)) {
        s /= x;
      }
    }
  }
  if (s > 1) c++;
  return (c);
}
inline int nf(long long int s) {
  if (s == 1) return 1;
  int j, x, f = 1;
  int c = 1;
  for (j = 0; ((x = prm[j]) * prm[j]) <= s; c = 1, j++) {
    if (!(s % x)) {
      while (!(s % x)) {
        s /= x;
        c++;
      }
      f = f * c;
    }
  }
  if (s > 1) {
    f = f << 1;
  }
  return (f);
}
vector<pair<int, int> > nfa;
inline void nfx(long long int s) {
  nfa.clear();
  if (s == 1) return;
  int j, x, c = 0;
  for (j = 0; ((x = prm[j]) * prm[j]) <= s; c = 0, j++) {
    if (!(s % x)) {
      while (!(s % x)) {
        s /= x;
        c++;
      }
      nfa.push_back(make_pair((x), (c)));
    }
  }
  if (s > 1) {
    nfa.push_back(make_pair((s), (1)));
  }
}
vector<long long int> factors;
inline void factr() {
  factors.clear();
  factors.push_back(1);
  long long int i, y, p, q, j;
  for (pair<int, int> x : nfa) {
    y = factors.size();
    p = x.first;
    q = x.second;
    for (j = 0; j < q; j++) {
      for (i = 0; i < y; i++) {
        factors.push_back(factors[i] * p);
      }
      p *= x.first;
    }
  }
}
long long int fc[10];
inline long long int InverseEuler(long long int n) {
  return ModP(n, 1000000007 - 2);
}
inline long long int nCr(int n, int r) {
  if (r > n) return 0;
  return (fc[n] *
          ((InverseEuler(fc[r]) * InverseEuler(fc[n - r])) % 1000000007)) %
         1000000007;
}
inline void facs() {
  fc[0] = fc[1] = 1;
  for (long long int i = 2; i < 10; i++) {
    fc[i] = (i * fc[i - 1]) % 1000000007;
  }
}
int main() {
  long long int n, p, i, x, y;
  cin >> n >> p;
  for (i = 1; i < 100000000; i++) {
    x = n - (i * p);
    if (x > 0) {
      if (__builtin_popcount(x) <= i && x >= i) {
        cout << i;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
