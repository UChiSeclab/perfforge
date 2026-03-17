#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1)
      cout << "FastestFinger" << endl;
    else if (n == 2)
      cout << "Ashishgup" << endl;
    else if (n % 2 != 0)
      cout << "Ashishgup" << endl;
    else {
      set<int> s;
      for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
          if (i % 2 != 0) s.insert(i);
          if ((n / i) % 2 != 0) s.insert(n / i);
        }
      }
      if (s.size() == 0) {
        cout << "FastestFinger" << endl;
      } else {
        auto it = s.end();
        it--;
        long long k = n / (*it);
        if (k == 2 && isPrime(*it) == true)
          cout << "FastestFinger" << endl;
        else
          cout << "Ashishgup" << endl;
      }
    }
  }
}
