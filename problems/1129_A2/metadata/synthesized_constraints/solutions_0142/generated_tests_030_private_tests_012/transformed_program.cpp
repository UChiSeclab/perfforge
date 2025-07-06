#include <bits/stdc++.h>

// Function declarations for invariant checks
void check_sort_invariant(int n);
void check_loop_invariant(int n, int m);
void check_candy_distribution_invariant(const std::vector<std::vector<int>>& g);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    // Perform invariant checks
    check_sort_invariant(n);
    check_loop_invariant(n, m);

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    // Check candy distribution before proceeding
    check_candy_distribution_invariant(g);

    for (int i = 0; i < n; ++i) {
        std::sort(g[i].begin(), g[i].end(), [&](const int &a, const int &b) {
            return a - i + (i > a ? n : 0) < b - i + (i > b ? n : 0);
        });
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = std::max(mx, (int)(g[i]).size());
    }

    int todo = 0;
    int add = 0;
    add += n * std::max(0, mx - 3);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (mx - 3); ++j) {
            if (g[i].empty()) break;
            g[i].pop_back();
        }
        todo += (int)(g[i]).size();
    }

    std::vector<int> kt(n);
    for (int s = 0; s < n; ++s) {
        for (int i = 0; i < n; ++i) kt[i] = (int)(g[i]).size() - 1;
        int td = todo;
        int cnt = 0;
        int mxwait = 0;
        int ps = s;
        while (td > 0 || mxwait > 0) {
            if (kt[ps] >= 0) {
                mxwait = std::max(mxwait, g[ps][kt[ps]] - ps + (g[ps][kt[ps]] < ps ? n : 0));
                kt[ps]--;
                td--;
            }
            ps = (ps + 1) % n;
            mxwait = std::max(0, mxwait - 1);
            cnt++;
        }
        std::cout << cnt + add << " ";
    }
    return 0;
}

// Definition of invariant checks

void check_sort_invariant(int n) {
    if (n > 4000) { // Threshold chosen considering n's upper limit
        std::cerr << "Warning: sort_invariant triggered - potentially expensive sorting due to large number of stations" << std::endl;
        abort();
    }
}

void check_loop_invariant(int n, int m) {
    if (n > 4000 && m > 15000) { // Threshold to ensure large station and candy counts
        std::cerr << "Warning: loop_invariant triggered - extensive looping due to large station and candy distribution" << std::endl;
        abort();
    }
}

void check_candy_distribution_invariant(const std::vector<std::vector<int>>& g) {
    for (const auto& station : g) {
        if (station.size() > 50) { // Arbitrary threshold for many candies at a single station
            std::cerr << "Warning: candy_distribution_invariant triggered - many candies at a station may cause slow delivery" << std::endl;
            abort();
        }
    }
}