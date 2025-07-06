#include <bits/stdc++.h>
using namespace std;

// Function to check for high density of queens causing multiple attacks
void check_high_density_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: high_density_invariant triggered - multiple queens on same attack lines" << endl;
        abort();
    }
}

// Function to check for frequent sorting of large attack lines
void check_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sort_invariant triggered - frequent sorting of large attack lines" << endl;
        abort();
    }
}

// Function to check if there are too many queens relative to the board size
void check_queen_board_ratio_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: queen_board_ratio_invariant triggered - large number of queens relative to board size" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<long long, vector<long long>> p, s, r, d;
    long long n, m, i, u, v;
    cin >> n >> m;

    // Check for a large number of queens relative to board size
    check_queen_board_ratio_invariant(m > n * 0.1); // assuming 10% is a high density

    vector<pair<long long, long long>> queen;

    for (i = 0; i < m; i++) {
        cin >> u >> v;
        queen.push_back(make_pair(u, v));
        p[u - v].push_back(u);
        s[u + v].push_back(u);
        r[u].push_back(v);
        d[v].push_back(u);
    }

    // Check if any diagonal or row has too many queens, which would imply high density
    for (const auto& line : {p, s, r, d}) {
        for (const auto& entry : line) {
            check_high_density_invariant(entry.second.size() > 5); // arbitrary threshold for high density
        }
    }

    for (auto &i : p)
        sort(i.second.begin(), i.second.end(), greater<long long>());
    for (auto &i : s)
        sort(i.second.begin(), i.second.end(), greater<long long>());
    for (auto &i : r)
        sort(i.second.begin(), i.second.end(), greater<long long>());
    for (auto &i : d)
        sort(i.second.begin(), i.second.end(), greater<long long>());

    // Check for frequent sorting if size of any line exceeds a certain threshold
    check_sort_invariant(p.size() > 50 || s.size() > 50 || r.size() > 50 || d.size() > 50); // arbitrary choice

    sort(queen.begin(), queen.end());
    map<pair<long long, long long>, long long> count;
    long long ans[9] = {0};

    for (i = 0; i < m; i++) {
        u = queen[i].first;
        v = queen[i].second;
        p[u - v].pop_back();
        s[u + v].pop_back();
        r[u].pop_back();
        d[v].pop_back();

        if (p[u - v].size()) {
            count[make_pair(u, v)]++;
            count[make_pair(*p[u - v].rbegin(), *p[u - v].rbegin() - u + v)]++;
        }
        if (s[u + v].size()) {
            count[make_pair(u, v)]++;
            count[make_pair(*s[u + v].rbegin(), -1 * (*s[u + v].rbegin()) + u + v)]++;
        }
        if (r[u].size()) {
            count[make_pair(u, v)]++;
            count[make_pair(u, *r[u].rbegin())]++;
        }
        if (d[v].size()) {
            count[make_pair(u, v)]++;
            count[make_pair(*d[v].rbegin(), v)]++;
        }
        ans[count[make_pair(u, v)]]++;
    }
    for (i = 0; i < 9; i++) cout << ans[i] << " ";
    return 0;
}