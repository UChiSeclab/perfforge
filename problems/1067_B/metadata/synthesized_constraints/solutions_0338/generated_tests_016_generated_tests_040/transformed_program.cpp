#include <bits/stdc++.h>
using namespace std;

class Adj {
 public:
  set<int> list;
  int id;
};

void check_sort_invariant(int sortCount) {
    if (sortCount > 10) { // Arbitrary threshold for frequent sorts
        cerr << "Warning: sort_invariant triggered - repeatedly sorting data" << endl;
        abort();
    }
}

void check_map_invariant(int mapSize) {
    if (mapSize > 10000) { // Arbitrary threshold for map operations
        cerr << "Warning: map_invariant triggered - excessive map updates or iterations" << endl;
        abort();
    }
}

void check_loop_invariant(int loopIterations) {
    if (loopIterations > 1000) { // Arbitrary threshold for loop iterations
        cerr << "Warning: loop_invariant triggered - too many loop iterations" << endl;
        abort();
    }
}

void check_degree_invariant(int degree) {
    if (degree > 3) {
        cerr << "Warning: degree_invariant triggered - high degree connectivity" << endl;
        abort();
    }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (k > 13) {
    cout << "No" << endl;
    return 0;
  }
  Adj adj[n + 1];
  adj[n].id = n;
  for (int x, y, i = 1; i < n; i++) {
    adj[i].id = i;
    cin >> x >> y;
    adj[x].list.insert(y);
    adj[y].list.insert(x);
  }
  int i = 1, depth = 0;
  bool flag = true;
  
  // Counter for sort operation
  int sortCount = 0;
  
  while (i < n) {
    sort(adj + i, adj + n + 1, [](Adj &lhs, Adj &rhs) { return lhs.list.size() < rhs.list.size(); });
    sortCount++;
    check_sort_invariant(sortCount); // Check for sort operation frequency
    
    map<int, int> ref;
    int mapSize = 0; // Track map size for invariant
    
    for (int j = i; j <= n; j++) {
      ref[adj[j].id] = j;
      mapSize++;
    }
    check_map_invariant(mapSize); // Check for map update frequency
    
    int j = i;
    int loopIterations = 0;
    
    while (adj[i].list.size() == 1) {
      i++;
      loopIterations++;
    }
    check_loop_invariant(loopIterations); // Check loop execution frequency
    
    map<int, int> mp;
    for (; j < i; j++) {
      int x = adj[j].id;
      int y = *(adj[j].list.begin());
      mp[y]++;
      adj[ref[y]].list.erase(x);
    }
    
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      check_degree_invariant(it->second); // Check vertex degree constraints
      if (it->second < 3) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
    depth++;
  }
  
  if (flag && depth == k && i == n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}