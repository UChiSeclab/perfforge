#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> q1, q2;
int gethash(vector<int>::iterator begin, vector<int>::iterator end) {
  int ret = 0;
  for (vector<int>::iterator it = begin; it != end; it++) {
    ret = (ret * 10 + *it) % 10000019;
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  time_t t1 = time(NULL);
  cin >> n;
  int cnt1, cnt2;
  cin >> cnt1;
  for (int i = 0; i < cnt1; ++i) {
    int x;
    cin >> x;
    q1.push_back(x);
  }
  cin >> cnt2;
  for (int i = 0; i < cnt2; ++i) {
    int x;
    cin >> x;
    q2.push_back(x);
  }
  int cnt = 0;
  while (!q1.empty() && !q2.empty()) {
    ++cnt;
    int x1 = q1.front();
    int x2 = q2.front();
    q1.erase(q1.begin());
    q2.erase(q2.begin());
    if (x1 > x2) {
      q1.push_back(x2);
      q1.push_back(x1);
    } else {
      q2.push_back(x1);
      q2.push_back(x2);
    }
    time_t t2 = time(NULL);
    if (t2 - t1 >= 2) break;
  }
  if (q1.empty())
    cout << cnt << " 2" << endl;
  else if (q2.empty())
    cout << cnt << " 1" << endl;
  else
    cout << "-1" << endl;
  return 0;
}
