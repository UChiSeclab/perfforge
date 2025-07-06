#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
    out << a.first << " " << a.second;
    return out;
}

bool isSquare(long long i, long long j, vector<pair<long long, long long>>& points, long long side) {
    map<pair<long long, long long>, long long> mp;
    for (long long i = 0; i < (long long)((points).size()); i++) {
        mp[{points[i].first, points[i].second}] = i;
    }
    vector<bool> visited((long long)((points).size()), false);
    long long cnt = 0;
    for (long long x = i; x < i + side; x++) {
        if (mp.find({x, j}) != mp.end()) {
            visited[mp[{x, j}]] = true;
            cnt++;
        }
        if (mp.find({x, j + side - 1}) != mp.end()) {
            visited[mp[{x, j + side - 1}]] = true;
            cnt++;
        }
    }
    for (long long y = j + 1; y < j + side - 1; y++) {
        if (mp.find({i, y}) != mp.end()) {
            visited[mp[{i, y}]] = true;
            cnt++;
        }
        if (mp.find({i + side - 1, y}) != mp.end()) {
            visited[mp[{i + side - 1, y}]] = true;
            cnt++;
        }
    }
    if ((long long)((points).size()) - cnt != 1) {
        return false;
    }
    for (long long i = 0; i < (long long)((points).size()); i++) {
        if (visited[i] == false) {
            cout << points[i] << "\n";
        }
    }
    return true;
}

void solve() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> points(4 * n + 1);
    for (long long i = 0; i < (long long)((points).size()); i++) {
        cin >> points[i];
    }

    // Add check for potential excessive square checks
    check_square_checking_invariant(51, 51, 50);

    for (long long i = 0; i <= 50; i++) {
        for (long long j = 0; j <= 50; j++) {
            for (long long side = 2; side <= 51; side++) {
                if (isSquare(i, j, points, side)) {
                    return;
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    while (t--) solve();
    return 0;
}