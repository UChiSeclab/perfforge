#include <bits/stdc++.h>
using namespace std;
int debug_num = 0;
const int maxn = 20;
struct node {
  char mapp[maxn][maxn];
};
node sta;
node ans;
int n;
bool check(node a) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (ans.mapp[i][j] != a.mapp[i][j]) return false;
    }
  }
  return true;
}
node fun1(const node &a) {
  node temp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      temp.mapp[i][j] = a.mapp[n + 1 - j][i];
    }
  }
  return temp;
}
node fun2(const node &a) {
  node temp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      temp.mapp[i][j] = a.mapp[n + 1 - j][n + 1 - i];
    }
  }
  return temp;
}
node fun3(const node &a) {
  node temp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      temp.mapp[i][j] = a.mapp[j][n + 1 - i];
    }
  }
  return temp;
}
node fun4(const node &a) {
  node temp;
  temp = a;
  for (int i = 1; i <= n / 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      swap(temp.mapp[i][j], temp.mapp[n + 1 - i][j]);
    }
  }
  return temp;
}
node fun5(const node &a) {
  node temp;
  temp = a;
  for (int i = 1; i <= n / 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      swap(temp.mapp[j][i], temp.mapp[j][n + 1 - i]);
    }
  }
  return temp;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> sta.mapp[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> ans.mapp[i][j];
    }
  }
  int flag = 0;
  string s = "12345";
  do {
    node now = sta;
    if (check(now)) {
      flag = 1;
      break;
    }
    for (int i = 1; i <= 5; ++i) {
      int id = s[i] - '0';
      if (id == 1) {
        now = fun1(now);
      } else if (id == 2) {
        now = fun2(now);
      } else if (id == 3) {
        now = fun3(now);
      } else if (id == 4) {
        now = fun4(now);
      } else {
        now = fun5(now);
      }
      if (check(now)) {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  } while (next_permutation(s.begin(), s.end()));
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
