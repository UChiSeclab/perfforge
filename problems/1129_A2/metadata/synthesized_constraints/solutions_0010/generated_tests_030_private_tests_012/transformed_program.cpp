#include <bits/stdc++.h>
using std::abs;
using std::cin;
using std::cout;
using std::deque;
using std::vector;
using std::pair;
using std::max;
using std::cerr;
using std::endl;

using ll = long long;
constexpr ll magic_mod = 1000000007;
ll m_pluss(ll a, ll b) { return (a + b) % magic_mod; }
ll m_mul(ll a, ll b) { return (a * b) % magic_mod; }

int n, m;
deque<vector<int>> cc;

// Checker function for high number of stations
void check_high_stations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high number of stations!" << endl;
        abort();
    }
}

// Checker function for circular rotations and repeated computations
void check_circular_rotation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to circular rotations and repeated computations!" << endl;
        abort();
    }
}

// Checker function for sorting overhead
void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to repeated sorting!" << endl;
        abort();
    }
}

ll get_res() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        auto& cq = cc[i];
        if (cq.empty()) continue;
        res = max<int>(res, cq.front() + i + cq.size() * n - n);
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cout.precision(17);

    // Read input
    cin >> n >> m;
    cc.resize(n);
    vector<pair<int, int>> candies(m);
    for (auto& c : candies) {
        cin >> c.first >> c.second;
        cc[c.first - 1].push_back((c.second - c.first + n) % n);
    }

    // Check for potential bottlenecks before starting main computation
    check_high_stations_invariant(n > 1000); // Assuming a high threshold for n
    check_circular_rotation_invariant(m > 10000 && n > 1000); // High threshold for rotations
    check_sorting_invariant(m > 10000); // High threshold for number of sort operations

    // Sort the candies at each station
    for (int i = 0; i < n; ++i) {
        auto& cq = cc[i];
        if (cq.empty()) continue;
        std::sort(begin(cq), end(cq));
    }

    // Calculate result from each starting station
    for (int i = 0; i < n; ++i) {
        cout << get_res() << " ";
        auto x = cc.front();
        cc.pop_front();
        cc.push_back(x);
    }
    cout << std::endl;
    return 0;
}