#include <bits/stdc++.h>
int MOD = 1000000007;
long long inf = 1e18;
using namespace std;
vector<int> A, B, C;
int as, bs, cs;
int a, b, c;
int k, n1, n2, n3, t1, t2, t3;
bool ok(int t) {
  if (a == n1) return false;
  int cntb = 0;
  for (int i = bs; i < B.size(); i++) {
    if (t + t1 < B[i] + t2) {
      cntb++;
    }
  }
  for (int i = as; i < A.size(); i++) {
    if (t + t1 < A[i] + t1 + t2) {
      cntb++;
    }
  }
  if (cntb >= n2) return false;
  int cntc = 0;
  for (int i = cs; i < C.size(); i++) {
    if (t + t1 + t2 < C[i] + t3) {
      cntc++;
    }
  }
  for (int i = bs; i < B.size(); i++) {
    if (t + t1 + t2 < B[i] + t2 + t3) {
      cntc++;
    }
  }
  for (int i = as; i < A.size(); i++) {
    if (t + t1 + t2 < A[i] + t1 + t2 + t3) {
      cntc++;
    }
  }
  if (cntc >= n3) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  int t, x;
  bool cont;
  for (t = 1; t <= 30000001; t++) {
    if (k == 0 && c == 0 && b == 0 && a == 0) {
      break;
    }
    cont = true;
    while (c != 0 && cont) {
      x = C[cs];
      cont = false;
      if (x + t3 == t) {
        cs++;
        c--;
        cont = true;
      }
    }
    cont = true;
    while (b != 0 && cont) {
      x = B[bs];
      cont = false;
      if (x + t2 == t) {
        bs++;
        b--;
        cont = true;
        C.push_back(t);
        c++;
      }
    }
    cont = true;
    while (a != 0 && cont) {
      x = A[as];
      cont = false;
      if (x + t1 == t) {
        as++;
        a--;
        cont = true;
        B.push_back(t);
        b++;
      }
    }
    cont = true;
    while (k != 0 && cont) {
      x = t;
      cont = false;
      if (ok(t)) {
        A.push_back(x);
        a++;
        cont = true;
        k--;
      }
    }
  }
  cout << t - 2;
  return 0;
}
