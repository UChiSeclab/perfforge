#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, count0 = 0, sq = 0, unsq = 0, arr[200000];
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    cin >> arr[i];
    if (arr[i] == 0) count0++;
    if (sqrt(arr[i]) == (int)(sqrt(arr[i])))
      sq++;
    else
      unsq++;
  }
  if (sq == unsq) {
    cout << "0";
    return 0;
    ;
  }
  if (sq > unsq) {
    sq -= count0;
    long long a = 1;
    long long count = 0;
    while (unsq < n / 2) {
      if (sq == 0) {
        sq = count0;
        a = 2;
        continue;
      }
      sq--;
      unsq++;
      count += a;
    }
    cout << count;
    return 0;
    ;
  }
  long long temp[200000];
  long long v1, v2;
  for (i = 0; i < n; i++) {
    v1 = (int)(ceil(sqrt(arr[i])));
    v1 *= v1;
    v1 -= arr[i];
    v2 = (int)(sqrt(arr[i]));
    v2 *= v2;
    v2 -= arr[i];
    v2 *= -1;
    temp[i] = min(v1, v2);
  }
  sort(temp, temp + n);
  long long count = 0;
  i = 0;
  while (sq < n / 2) {
    if (temp[i] != 0) {
      count += temp[i];
      sq++;
    }
    i++;
  }
  cout << count;
  return 0;
}
