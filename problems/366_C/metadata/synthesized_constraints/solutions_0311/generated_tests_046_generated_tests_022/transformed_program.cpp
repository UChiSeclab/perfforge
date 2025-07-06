#include <bits/stdc++.h>
using namespace std;

void check_map_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - frequent map operations detected!" << endl;
        abort();
    }
}

void check_large_data_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - sorting large data structures!" << endl;
        abort();
    }
}

void check_large_combination_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - high density of valid combinations!" << endl;
        abort();
    }
}

struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i].second;
    v[i].second *= k;
    v[i].second -= v[i].first;
  }
  vector<pair<int, int> > pos;
  vector<pair<int, int> > neg;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i].second < 0) {
      v[i].second = -v[i].second;
      pos.push_back(v[i]);
    } else if (v[i].second > 0) {
      neg.push_back(v[i]);
    } else {
      res += v[i].first;
    }
  }

  // Check large data before sorting
  check_large_data_sorting_invariant(pos.size() > 75 || neg.size() > 75);

  sort(pos.begin(), pos.end(),
       [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });
  sort(neg.begin(), neg.end(),
       [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

  map<int, int> dppos;
  map<int, int> dpneg;
  dppos[0] = 0;
  dpneg[0] = 0;

  for (int i = 0; i < (int(pos.size())); ++i) {
    vector<pair<int, int> > new_v;
    for (auto j : dppos) {
      if (dppos.find(j.first + pos[i].second) == dppos.end() ||
          j.second + pos[i].first > dppos[j.first + pos[i].second]) {
        new_v.push_back({j.first + pos[i].second, j.second + pos[i].first});
      }
    }
    for (auto j : new_v) {
      dppos[j.first] = j.second;
    }
  }

  // Check map operations invariant
  check_map_operations_invariant(dppos.size() > 5000);

  vector<int> pos_res(100001);
  for (auto i : dppos) {
    pos_res[i.first] = i.second;
  }
  for (int i = 0; i < (int(neg.size())); ++i) {
    vector<pair<int, int> > new_v;
    for (auto j : dpneg) {
      if (dpneg.find(j.first + neg[i].second) == dpneg.end() ||
          j.second + neg[i].first > dpneg[j.first + neg[i].second]) {
        new_v.push_back({j.first + neg[i].second, j.second + neg[i].first});
      }
    }
    for (auto j : new_v) {
      dpneg[j.first] = j.second;
    }
  }

  // Check map operations invariant
  check_map_operations_invariant(dpneg.size() > 5000);

  vector<int> neg_res(100001);
  for (auto i : dpneg) {
    neg_res[i.first] = i.second;
  }

  int max_res = res;
  int valid_combinations = 0;
  for (int i = 0; i < 100001; ++i) {
    if (pos_res[i] != 0 && neg_res[i] != 0) {
      max_res = max(res + pos_res[i] + neg_res[i], max_res);
      valid_combinations++;
    }
  }

  // Check large combination invariant
  check_large_combination_invariant(valid_combinations > 500);

  cout << (max_res != 0 ? max_res : -1);
}