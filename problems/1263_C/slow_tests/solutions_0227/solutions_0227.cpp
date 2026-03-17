#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> ans;
    set<long long> used;
    ans.insert(0);
    ans.insert(1);
    ans.insert(n);
    long long curr = 2;
    while (used.find(curr) == used.end() && curr <= n / 2) {
      long long aux = n / curr;
      long long aux2 = n / aux;
      ans.insert(aux);
      ans.insert(aux2);
      used.insert(curr);
      used.insert(aux);
      curr++;
    }
    cout << ans.size() << "\n";
    for (auto e : ans) {
      cout << e << " ";
    }
    cout << "\n";
  }
  return 0;
}
