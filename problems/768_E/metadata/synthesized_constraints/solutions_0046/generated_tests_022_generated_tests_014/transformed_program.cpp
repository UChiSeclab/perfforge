#include <bits/stdc++.h>
using namespace std;

void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
int n;
map<pair<int, long long>, int> grundy;

void check_recursion_depth_invariant(int cnt, long long state, int depth) {
    if (cnt > 50 && depth > 20) { // Example thresholds
        cerr << "Warning: Potential high recursion depth triggered!" << endl;
        abort();
    }
}

void check_cache_efficiency_invariant(const map<pair<int, long long>, int>& grundy) {
    if (grundy.size() > 10000) { // Example threshold for cache size
        cerr << "Warning: Cache inefficiency detected!" << endl;
        abort();
    }
}

void check_input_conditions_invariant(int n, const vector<int>& stones) {
    int highStoneCount = count_if(stones.begin(), stones.end(), [](int s) { return s > 50; });
    if (n > 100000 && highStoneCount > n / 2) { // Example conditions
        cerr << "Warning: Large input and high stone count detected!" << endl;
        abort();
    }
}

int solve(int cnt, long long state, int depth = 0) {
    check_recursion_depth_invariant(cnt, state, depth);

    if (grundy.find({cnt, state}) != grundy.end()) {
        return grundy[{cnt, state}];
    }
    vector<bool> encountered(65, false);
    for (int i = 1; i <= cnt; ++i) {
        if (state & (1ll << i)) {
            encountered[solve(cnt - i, state ^ (1ll << i), depth + 1)] = true;
        }
    }
    for (int i = 0; i < 65; ++i) {
        if (!encountered[i]) {
            return grundy[{cnt, state}] = i;
        }
    }
}

int main() {
    setIO("1");
    cin >> n;
    
    vector<int> stones(n);
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }
    
    check_input_conditions_invariant(n, stones);
    check_cache_efficiency_invariant(grundy);

    int val = 0;
    for (int i = 0; i < n; ++i) {
        val ^= (solve(stones[i], (1ll << 62) - 1));
    }
    cout << (val ? "NO" : "YES") << "\n";
    return 0;
}