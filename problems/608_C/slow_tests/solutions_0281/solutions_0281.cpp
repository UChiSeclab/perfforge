#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> positions_to_beacons;
  int max_pos = 0, n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int position, power;
    cin >> position;
    cin >> power;
    positions_to_beacons.insert(make_pair(position, power));
    max_pos = max(max_pos, position + 1);
  }
  int *saved_to = new int[max_pos + 1];
  for (int i = 0; i <= max_pos; ++i) {
    saved_to[i] = 0;
  }
  if (positions_to_beacons.find(0) != positions_to_beacons.end()) {
    saved_to[0] = 1;
  }
  int max_saved = 0;
  for (int i = 1; i <= max_pos; i++) {
    auto beacon_pair = positions_to_beacons.find(i);
    if (beacon_pair != positions_to_beacons.end()) {
      int power = beacon_pair->second;
      if (power - i >= 0) {
        saved_to[i] = 1;
      } else {
        saved_to[i] = saved_to[i - power - 1] + 1;
      }
    } else {
      saved_to[i] = saved_to[i - 1];
    }
    max_saved = max(saved_to[i], max_saved);
  }
  int destroyed = n - max_saved;
  cout << destroyed << endl;
  return 0;
}
