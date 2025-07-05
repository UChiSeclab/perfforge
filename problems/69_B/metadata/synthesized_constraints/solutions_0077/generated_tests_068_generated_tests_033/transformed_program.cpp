#include <bits/stdc++.h>
using namespace std;

// Checker functions as defined above
void check_participants_invariant(int m) {
    if (m > 80) {
        cerr << "Warning: Performance bottleneck triggered - too many participants!" << endl;
        abort();
    }
}

void check_section_range_invariant(int l, int r) {
    if ((r - l + 1) > 15) {
        cerr << "Warning: Performance bottleneck triggered - extensive section coverage!" << endl;
        abort();
    }
}

void check_sorting_invariant(int vectorSize) {
    if (vectorSize > 10) {
        cerr << "Warning: Performance bottleneck triggered - sorting large section list!" << endl;
        abort();
    }
}

void check_participant_density_invariant(int participantsInSection) {
    if (participantsInSection > 10) {
        cerr << "Warning: Performance bottleneck triggered - high participant density in section!" << endl;
        abort();
    }
}

int32_t main() {
  int64_t n, m;
  cin >> n >> m;

  // Check the number of participants
  check_participants_invariant(m);

  map<int64_t, vector<pair<int64_t, pair<int64_t, int64_t> > > > mp;
  int64_t idx = 0;
  while (m--) {
    int64_t l, r, t, c;
    cin >> l >> r >> t >> c;

    // Check the range of sections each participant covers
    check_section_range_invariant(l, r);

    for (int64_t i = l; i <= r; i++) {
      mp[i].push_back(make_pair(t, make_pair(idx++, c)));
    }
  }

  int64_t profit = 0;
  for (int64_t i = 1; i <= n; i++) {
    if (mp[i].size() > 0) {
      // Check the participant density in each section before sorting
      check_participant_density_invariant(mp[i].size());

      // Check if sorting on large data sets might be costly
      check_sorting_invariant(mp[i].size());

      sort(mp[i].begin(), mp[i].end());
      profit += mp[i][0].second.second;
    }
  }
  cout << profit << "\n";
  return 0;
}