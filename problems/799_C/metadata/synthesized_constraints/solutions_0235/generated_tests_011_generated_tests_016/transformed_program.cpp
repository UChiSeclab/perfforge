#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect performance bottlenecks
void check_large_iteration_invariant(int start, int end) {
    if (end - start > 50000) { 
        cerr << "Warning: Large iteration range may lead to performance issues." << endl;
        abort();
    }
}

void check_input_list_size_invariant(int listSize, const char* type) {
    if (listSize > 50000) {
        cerr << "Warning: Input list of type " << type << " is very large, leading to potential bottlenecks." << endl;
        abort();
    }
}

void check_repeated_updates_invariant(int updates) {
    if (updates > 50000) {
        cerr << "Warning: Excessive updates to the bestC or bestD arrays may degrade performance." << endl;
        abort();
    }
}

int n, c, d, b, p;
char x;
vector<pair<int, int> > cc, dd, ci, di;
pair<int, int> bestC[100010], bestD[100010];
int ans;
vector<pair<int, int> >::iterator it;

int main() {
  scanf("%d %d %d", &n, &c, &d);
  
  // Check input size
  check_input_list_size_invariant(n, "fountains");
  
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %c", &b, &p, &x);
    getchar();
    if (x == 'C') {
      cc.push_back({b, -p});
      ci.push_back({p, b});
    } else {
      dd.push_back({b, -p});
      di.push_back({p, b});
    }
  }
  
  sort(cc.begin(), cc.end(), greater<pair<int, int> >());
  sort(dd.begin(), dd.end(), greater<pair<int, int> >());
  sort(ci.begin(), ci.end());
  sort(di.begin(), di.end());
  
  for (int i = 0; i <= 100000; ++i)
    bestC[i] = bestD[i] = {-1000000000, -1000000000};
  
  if (ci.size() > 0) {
    int iterationCount = ci[0].first;
    for (int i = 0; i < iterationCount; ++i) bestC[i] = {-1000000000, -1000000000};
    check_large_iteration_invariant(0, iterationCount);  // Check large iteration range
    for (int i = ci[0].first; i <= 100000; ++i)
      bestC[i] = {ci[0].second, -1000000000};
  }
  
  if (ci.size() > 1) {
    for (int i = ci[0].first; i < ci[1].first; ++i)
      bestC[i] = {ci[0].second, -1000000000};
    for (int i = ci[1].first; i <= 100000; ++i)
      bestC[i] = {max(ci[0].second, ci[1].second), min(ci[0].second, ci[1].second)};
  }
  
  if (ci.size() > 2) {
    for (int i = 2; i < ci.size(); ++i) {
      pair<int, int> cur = bestC[ci[i - 1].first - 1];
      if (cur.first <= ci[i - 1].second)
        cur = {ci[i - 1].second, cur.first};
      else if (cur.second < ci[i - 1].second)
        cur.second = ci[i - 1].second;
      for (int j = ci[i - 1].first; j < ci[i].first; ++j) bestC[j] = cur;
    }
    pair<int, int> cur = bestC[ci.back().first - 1];
    if (cur.first <= ci.back().second)
      cur = {ci.back().second, cur.first};
    else if (cur.second < ci.back().second)
      cur.second = ci.back().second;
    for (int j = ci.back().first; j <= 100000; ++j) bestC[j] = cur;
  }
  
  if (di.size() > 0) {
    int iterationCount = di[0].first;
    for (int i = 0; i < iterationCount; ++i) bestD[i] = {-1000000000, -1000000000};
    check_large_iteration_invariant(0, iterationCount);  // Check large iteration range
    for (int i = di[0].first; i <= 100000; ++i)
      bestD[i] = {di[0].second, -1000000000};
  }
  
  if (di.size() > 1) {
    int updates = 0;
    for (int i = di[0].first; i < di[1].first; ++i) {
      bestD[i] = {di[0].second, -1000000000};
      updates++;
    }
    check_repeated_updates_invariant(updates);  // Check repeated updates
    for (int i = di[1].first; i <= 100000; ++i)
      bestD[i] = {max(di[0].second, di[1].second), min(di[0].second, di[1].second)};
  }
  
  if (di.size() > 2) {
    for (int i = 2; i < di.size(); ++i) {
      pair<int, int> cur = bestD[di[i - 1].first - 1];
      if (cur.first <= di[i - 1].second)
        cur = {di[i - 1].second, cur.first};
      else if (cur.second < di[i - 1].second)
        cur.second = di[i - 1].second;
      for (int j = di[i - 1].first; j < di[i].first; ++j) bestD[j] = cur;
    }
    pair<int, int> cur = bestD[di.back().first - 1];
    if (cur.first <= di.back().second)
      cur = {di.back().second, cur.first};
    else if (cur.second < di.back().second)
      cur.second = di.back().second;
    for (int j = di.back().first; j <= 100000; ++j) bestD[j] = cur;
  }
  
  for (int i = 0; i < ci.size(); ++i) {
    int res = c - ci[i].first;
    if (res <= 0) continue;
    pair<int, int> x = bestC[res];
    if (x.first == ci[i].second)
      ans = max(ans, ci[i].second + x.second);
    else
      ans = max(ans, ci[i].second + x.first);
  }
  
  for (int i = 0; i < di.size(); ++i) {
    int res = d - di[i].first;
    if (res <= 0) continue;
    pair<int, int> x = bestD[res];
    if (x.first == di[i].second)
      ans = max(ans, di[i].second + x.second);
    else
      ans = max(ans, di[i].second + x.first);
  }
  
  int cur = 0;
  for (int i = 0; i < cc.size(); ++i) {
    if (-cc[i].second <= c) {
      cur += cc[i].first;
      bool find = false;
      for (int j = 0; j < dd.size(); ++j) {
        if (-dd[j].second <= d) {
          cur += dd[j].first;
          ans = max(ans, cur);
          break;
        }
      }
      break;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}