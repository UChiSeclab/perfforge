#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int n;
  vector<int> vi;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vi.push_back(a);
    sum += a * (i + 1);
  }
  cout << sum;
  return 0;
}
