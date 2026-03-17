#include <bits/stdc++.h>
using namespace std;
int degr[17] = {1,   2,    4,    8,    16,   32,    64,    128,  256,
                512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
int get_byte(int a, int k) { return a & degr[k]; }
int main() {
  int n, k;
  cin >> n >> k;
  bool answer = false;
  int n_masks = degr[k];
  vector<int> masks(n_masks, 0);
  for (int i = 0; i < n; i++) {
    int current_mask = 0;
    for (int j = 0; j < k; j++) {
      int bit;
      cin >> bit;
      current_mask += bit * degr[j];
    }
    masks[current_mask]++;
  }
  int max_bust = degr[n_masks];
  for (int i = 0; i < max_bust; i++) {
    int alls = 0;
    vector<int> n_task(k, 0);
    for (int j = 0; j < n_masks; j++) {
      if (masks[j] == 0) continue;
      if (!get_byte(i, j)) continue;
      alls++;
      for (int l = 0; l < k; l++) {
        if (get_byte(j, l)) n_task[l]++;
      }
    }
    if (!alls) continue;
    bool this_answer = true;
    for (int l = 0; l < k; l++) {
      if (2 * n_task[l] > alls) this_answer = false;
    }
    if (this_answer) {
      answer = true;
      break;
    }
  }
  if (answer)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
