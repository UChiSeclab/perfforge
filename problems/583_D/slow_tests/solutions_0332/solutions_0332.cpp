#include <bits/stdc++.h>
using namespace std;
template <class T>
void print_array(T a[], int size) {
  for (int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}
template <class T>
void print_array_v(T &a) {
  int size = a.size();
  for (int i = 0; i < size; i++) cout << a[i] << " ";
  cout << endl;
}
int lisLength(int a[], int n, int mn, int mx) {
  vector<int> lis;
  for (int i = 0; i < n; i++)
    if (a[i] >= mn && a[i] <= mx) {
      vector<int>::iterator it = upper_bound(lis.begin(), lis.end(), a[i]);
      if (it == lis.end())
        lis.push_back(a[i]);
      else
        *it = a[i];
    }
  return lis.size();
}
int main() {
  int n, t;
  scanf("%d", &n);
  scanf("%d", &t);
  int a[110], b[20020];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < min(t, n); i++)
    for (int j = 0; j < n; j++) b[i * n + j] = a[j];
  if (t <= n)
    printf("%d\n", lisLength(b, t * n, INT_MIN, INT_MAX));
  else if (t <= 2 * n) {
    for (int i = n; i < t; i++)
      for (int j = 0; j < n; j++) b[i * n + j] = a[j];
    printf("%d\n", lisLength(b, t * n, INT_MIN, INT_MAX));
  } else {
    int cnt[330] = {0};
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, lisLength(b, n * n, INT_MIN, a[i]) +
                         cnt[a[i]] * (t - 2 * n) +
                         lisLength(b, n * n, a[i], INT_MAX));
    printf("%d\n", ans);
  }
  return 0;
}
