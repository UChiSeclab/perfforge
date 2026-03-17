#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<pair<long long, long long>, long long>& a,
          const pair<pair<long long, long long>, long long>& b) {
  if (a.first.first == b.first.first)
    return a.first.second < b.first.second;
  else
    return a.first.first < b.first.first;
}
int main() {
  long long n, width, height;
  cin >> n >> width >> height;
  vector<pair<long long, long long>> go;
  vector<pair<pair<long long, long long>, long long>> h, v;
  unordered_map<long long, vector<long long>> vc, hc;
  for (int i = 0; i < n; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (x == 1) {
      go.push_back({y, 1});
      v.push_back({{z - y, y}, i});
      vc[i].push_back(y);
      vc[i].push_back(height);
    } else {
      go.push_back({y, 2});
      h.push_back({{z - y, y}, i});
      hc[i].push_back(width);
      hc[i].push_back(y);
    }
  }
  sort(v.begin(), v.end(), comp);
  sort(h.begin(), h.end(), comp);
  int i1 = 0, j1 = 0, i2 = 0, j2 = 0, siz1 = v.size(), siz2 = h.size();
  while (i1 < siz1 && i2 < siz2) {
    if (v[i1].first.first < h[i2].first.first)
      i1++;
    else if (v[i1].first.first > h[i2].first.first)
      i2++;
    else {
      j1 = i1;
      j2 = i2;
      i1++;
      i2++;
      while (i1 < siz1 && v[i1].first.first == v[i1 - 1].first.first) i1++;
      while (i2 < siz2 && h[i2].first.first == h[i2 - 1].first.first) i2++;
      for (int i = j1; i < i1; i++) {
        long long curr = i1 - i;
        if (curr > i2 - j2) {
          vc[v[i].second][0] = v[i + i2 - j2].first.second;
        } else {
          vc[v[i].second][1] = h[j2 + i1 - i - 1].first.second;
          vc[v[i].second][0] = width;
        }
      }
      for (int i = j2; i < i2; i++) {
        long long curr = i2 - i;
        if (curr > i1 - j1) {
          hc[h[i].second][1] = h[i + i1 - j1].first.second;
        } else {
          hc[h[i].second][0] = v[j1 + i2 - i - 1].first.second;
          hc[h[i].second][1] = height;
        }
      }
      j1 = i1;
      j2 = i2;
    }
  }
  for (int i = 0; i < go.size(); i++) {
    if (go[i].second == 1) {
      cout << vc[i][0] << " " << vc[i][1] << endl;
    } else {
      cout << hc[i][0] << " " << hc[i][1] << endl;
    }
  }
}
