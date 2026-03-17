#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[200003];
void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
}
class bit {
 public:
  unordered_map<int, unordered_map<int, int> > tr;
  void add(int a, int b) {
    a += n + 2;
    b += n + 2;
    for (int i = a; i < 3 * 200003; i += i & (-i))
      for (int j = b; j < 3 * 200003; j += j & (-j)) tr[i][j]++;
  }
  int get_prefix(int a, int b) {
    a += n + 2;
    b += n + 2;
    int ans = 0;
    for (int i = a; i > 0; i -= i & (-i))
      if (tr.count(i))
        for (int j = b; j > 0; j -= j & (-j))
          if (tr[i].count(j)) ans += tr[i][j];
    return ans;
  }
  int get(int a, int b) {
    return get_prefix(a, 3 * 200003) - get_prefix(a, b - 1);
  }
};
bit even, odd;
void solve() {
  for (int i = 1; i <= n; i++) {
    if (arr[i] < m)
      arr[i] = 0;
    else if (arr[i] == m)
      arr[i] = 1;
    else
      arr[i] = 2;
  }
  int a = 0, b = 0, c = 0;
  even.add(0, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0)
      a++;
    else if (arr[i] == 1)
      b++;
    else
      c++;
    if (i % 2 == 0) {
      int first = a + b - c;
      int second = a - b - c + 1;
      ans += even.get(first, second);
      first--;
      ans += odd.get(first, second);
      even.add(a + b - c, a - b - c);
    } else {
      int first = a + b - c;
      int second = a - b - c + 1;
      ans += odd.get(first, second);
      first--;
      ans += even.get(first, second);
      odd.add(a + b - c, a - b - c);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
