#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
int a[N];
int f[N];
int sumf[N];
long long sum;
long long best;
vector<int> freq;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    f[a[i]]++;
    sum += a[i];
  }
  if (f[1]) {
    printf("%lld\n", sum);
    return 0;
  }
  for (int i = 2; i < N; i++) {
    if (f[i]) freq.push_back(i);
    sumf[i] = f[i] + sumf[i - 1];
  }
  for (int i = 0; i < freq.size(); i++) {
    int leading = freq[i];
    long long total = 0;
    for (int j = leading; j < N; j += leading) {
      total += 1ll * (sumf[min(j + leading - 1, N - 1)] - sumf[j - 1]) * j;
    }
    best = max(best, total);
  }
  printf("%lld\n", best);
  return 0;
}
