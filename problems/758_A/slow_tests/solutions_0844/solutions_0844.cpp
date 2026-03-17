#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, counter = 0;
  int sum = 0;
  cin >> n;
  int temp;
  vector<int> a;
  while (n--) {
    cin >> temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i) {
    while (a[i] < a[a.size() - 1]) {
      ++counter;
      a[i]++;
    }
  }
  cout << counter;
}
