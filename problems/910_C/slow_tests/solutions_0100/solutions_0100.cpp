#include <bits/stdc++.h>
using namespace std;
int ct[10][10];
bool lead[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> in(n);
  for (int i = 0; i < n; i++) {
    cin >> in[i];
    lead[in[i][0] - 'a'] = true;
    reverse(in[i].begin(), in[i].end());
    for (int j = 0; j < in[i].length(); j++) {
      ct[in[i][j] - 'a'][j]++;
    }
  }
  vector<int> v(10);
  for (int i = 0; i < 10; i++) v[i] = i;
  long long minsum = 1e15;
  do {
    int zloc = find(v.begin(), v.end(), 0) - v.begin();
    if (lead[zloc]) continue;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      int p10 = 1;
      for (int j = 0; j < 6; j++) {
        sum += p10 * v[i] * ct[i][j];
        p10 *= 10;
      }
    }
    minsum = min((long long)sum, minsum);
  } while (next_permutation(v.begin(), v.end()));
  cout << minsum << endl;
  return 0;
}
