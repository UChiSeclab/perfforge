#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  long long int second;
  long long int length;
};
int main() {
  long long int n, i, a, b, val;
  cin >> n;
  cin >> a;
  queue<long long int> A, B;
  for (i = 0; i < a; i++) cin >> val, A.push(val);
  cin >> b;
  for (i = 0; i < b; i++) cin >> val, B.push(val);
  long long int count = 0, val1, val2;
  for (count = 0; !A.empty() && !B.empty() && count < 10000000; count++) {
    val1 = A.front(), val2 = B.front();
    A.pop(), B.pop();
    if (val1 > val2)
      A.push(val2), A.push(val1);
    else
      B.push(val1), B.push(val2);
  }
  if (count == 10000000)
    cout << "-1\n";
  else {
    if (A.empty())
      cout << count << " "
           << "2\n";
    else
      cout << count << " "
           << "1\n";
  }
  return 0;
}
