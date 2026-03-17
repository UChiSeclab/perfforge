#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
map<int, vector<int> > mapV;
map<int, queue<int> > mapQ;
vector<pair<int, int> > pos[MAXN];
pair<int, int> res[MAXN];
struct Tri {
  int g, p, t, id;
} seq[MAXN];
bool operator<(const Tri &a, const Tri &b) { return a.p > b.p; }
int n, w, h;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++)
    cin >> seq[i].g >> seq[i].p >> seq[i].t, seq[i].id = i;
  sort(seq + 1, seq + n + 1);
  for (int i = 1; i <= n; i++) {
    if (seq[i].g == 1)
      pos[seq[i].p].push_back(make_pair(seq[i].id, seq[i].t));
    else {
      int T = seq[i].t - seq[i].p + 1;
      if (mapV.count(T) == 0) {
        mapV[T] = vector<int>();
        mapQ[T] = queue<int>();
      }
      mapV[T].push_back(seq[i].p);
      mapQ[T].push(seq[i].id);
    }
  }
  for (int i = 1; i <= w; i++) {
    if (pos[i].size() > 0) {
      for (vector<pair<int, int> >::iterator it = pos[i].begin();
           it != pos[i].end(); it++) {
        int T = it->second - i + 1;
        if (mapQ.count(T) != 0) {
          int id = mapQ[T].front();
          mapQ[T].pop();
          mapQ[T].push(it->first);
          res[id] = make_pair(i, h);
        } else
          res[it->first] = make_pair(i, h);
      }
    }
  }
  map<int, vector<int> >::iterator a = mapV.begin();
  map<int, queue<int> >::iterator b = mapQ.begin();
  for (; a != mapV.end() && b != mapQ.end(); a++, b++) {
    vector<int> &now = a->second;
    queue<int> &q = b->second;
    for (int i = 0; i < now.size(); i++) {
      res[q.front()] = make_pair(w, now[i]);
      q.pop();
    }
  }
  for (int i = 1; i <= n; i++)
    cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
