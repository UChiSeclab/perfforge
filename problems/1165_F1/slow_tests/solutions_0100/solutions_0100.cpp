#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int MAXN = 5e5 + 100;
int N, M;
int A[MAXN];
vector<pair<int, int> > vect;
int last[MAXN];
int sum = 0;
bool f(int mid) {
  for (int i = 0; i < MAXN; i++) last[i] = -1;
  for (int i = 0; i < vect.size(); i++) {
    if (vect[i].first > mid) continue;
    last[vect[i].second] = vect[i].first;
  }
  int arr[MAXN];
  for (int i = 0; i < MAXN; i++) arr[i] = 0;
  for (int i = 1; i <= N; i++) {
    if (last[i] != -1) arr[last[i]] += A[i];
  }
  int cont = 0;
  for (int i = 1; i <= mid; i++) {
    cont++;
    while (cont && arr[i]) cont--, arr[i]--;
  }
  int gasto = mid - cont;
  int falta = sum - gasto;
  if (falta * 2 <= cont) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  for (int i = 1; i <= M; i++) {
    int d, t;
    cin >> d >> t;
    vect.push_back({d, t});
  }
  sort(vect.begin(), vect.end());
  for (int i = 1; i < MAXN; i++) {
    if (f(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
