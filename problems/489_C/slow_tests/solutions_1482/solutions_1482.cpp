#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int m, sum;
  cin >> m >> sum;
  vector<int> digitsMax;
  vector<int> digitsMin;
  if ((sum > 9 && m == 1) || (sum == 0 && m > 1)) {
    cout << -1 << " " << -1 << endl;
    return 0;
  } else if (sum == 0 && m == 1) {
    cout << 0 << " " << 0 << endl;
    return 0;
  } else if (sum <= 9 && m == 1) {
    cout << sum << " " << sum << endl;
    return 0;
  } else if (sum <= 9 && m > 1) {
    digitsMax.push_back(sum);
    for (int i = 0; i < m - 1; i++) {
      digitsMax.push_back(0);
    }
    digitsMin.push_back(1);
    for (int i = 0; i < m - 2; i++) {
      digitsMin.push_back(0);
    }
    digitsMin.push_back(sum - 1);
    for (int i = 0; i < digitsMin.size(); i++) {
      cout << digitsMin[i];
    }
    cout << " ";
    for (int i = 0; i < digitsMax.size(); i++) {
      cout << digitsMax[i];
    }
    return 0;
  } else if (sum > 9 && m >= 1) {
    int storeSum = sum;
    int storeSize = m;
    int storeSecond = m;
    int sumSecond = sum;
    while (storeSum > 0) {
      if (storeSum > 9) {
        digitsMax.push_back(9);
        storeSum -= 9;
      } else {
        digitsMax.push_back(storeSum);
        storeSum = 0;
      }
      m -= 1;
      if (m == 0 && storeSum > 0) {
        cout << -1 << " " << -1 << endl;
        return 0;
      }
    }
    while (m > 0) {
      digitsMax.push_back(0);
      m--;
    }
    m = storeSecond;
    sum = sumSecond;
    for (int i = 0; i < 10000000; i++) {
      if (sum > 9) {
        digitsMin.push_back(9);
        sum -= 9;
        m--;
      } else if (sum > 1 && m > 1) {
        digitsMin.push_back(sum - 1);
        sum = sum - (sum - 1);
        m--;
      }
      if (m == 0 || m == 1) break;
    }
    while (m - 1 > 0) {
      digitsMin.push_back(0);
      m--;
    }
    digitsMin.push_back(sum);
    reverse(digitsMin.begin(), digitsMin.end());
    for (int i = 0; i < digitsMin.size(); i++) {
      cout << digitsMin[i];
    }
    cout << " ";
    for (int i = 0; i < digitsMax.size(); i++) {
      cout << digitsMax[i];
    }
    return 0;
  } else {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
}
