#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;
int n, num, x;
map<pair<int, long long>, int> m;

void check_recursion_depth(int stones) {
    if (stones > 30) { // Arbitrarily chosen threshold for high recursion depth
        cerr << "Warning: Recursion depth may be excessive due to high stone count." << endl;
        abort();
    }
}

void check_memorization_state_size(int uniqueStates) {
    if (uniqueStates > 100000) { // Threshold for an excessive number of states
        cerr << "Warning: Memorization may become inefficient due to many unique states." << endl;
        abort();
    }
}

void check_bitmask_complexity(int stones) {
    if (stones > 40) { // Threshold for complex bitmask operations
        cerr << "Warning: Bitmask operations may be complex due to high stone count." << endl;
        abort();
    }
}

int sg(int st, long long bm) {
    if (m.count(make_pair(st, bm))) return m[make_pair(st, bm)];
    bitset<61> chk;
    chk.reset();
    for (int(i) = (1); (i) < (st + 1); (i)++) {
        if (!(1 << i & bm)) {
            chk[sg(st - i, bm | (1 << i))] = 1;
        }
    }
    int ans = 0;
    while (chk[ans]) ans++;
    return m[make_pair(st, bm)] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    num = 0;
    for (int(i) = (0); (i) < (n); (i)++) {
        cin >> x;
        check_recursion_depth(x); // Check for recursion depth issues
        check_bitmask_complexity(x); // Check bitmask complexity
        num ^= sg(x, 0ll);
    }
    check_memorization_state_size(m.size()); // Check memoization state size
    cout << (num ? "NO" : "YES");
}