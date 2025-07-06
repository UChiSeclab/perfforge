#include <bits/stdc++.h>
using ll = long long;
const ll maxSize = 200007;
using namespace std;
ll a[maxSize];
unordered_map<ll, set<pair<ll, ll>>> dexToLR;

// Checker functions
void check_map_lookup_invariant(size_t dexRange, size_t trapCount) {
    if (dexRange > 100000 && trapCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large map lookups!" << endl;
        abort();
    }
}

void check_overlapping_traps_invariant(size_t overlappingTraps) {
    if (overlappingTraps > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to overlapping traps!" << endl;
        abort();
    }
}

void check_binary_search_invariant(size_t dexteritySpan) {
    if (dexteritySpan > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large binary search space!" << endl;
        abort();
    }
}

void check_trap_selection_invariant(size_t selectedTraps) {
    if (selectedTraps > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive trap selection!" << endl;
        abort();
    }
}

ll minDisarmTime(const vector<pair<ll, ll>>& traps) {
    ll time = 0;
    auto it = traps.begin();
    ll st = 0;
    ll end = -1;
    size_t overlappingTraps = 0;
    while (it != traps.end()) {
        auto next = *it;
        if (next.first > end) {
            time += end - st + 1;
            st = next.first;
        }
        end = max(end, next.second);
        ++it;
        overlappingTraps++; // Count overlapping traps
    }
    time += end - st + 1;

    // Check overlapping traps invariant
    check_overlapping_traps_invariant(overlappingTraps);

    return 2 * time;
}

vector<pair<ll, ll>> chooseTrapsByDex(ll dex) {
    vector<pair<ll, ll>> result;
    result.reserve(maxSize);
    for (ll i = dex; i < maxSize; ++i) {
        if (dexToLR.find(i) != dexToLR.end()) {
            auto& toInsert = dexToLR.at(i);
            result.insert(result.end(), toInsert.begin(), toInsert.end());
        }
    }
    sort(result.begin(), result.end());

    // Check map lookup invariant
    check_map_lookup_invariant(maxSize - dex, result.size());

    return result;
}

bool solve(ll dex, ll maxTime) {
    auto traps = chooseTrapsByDex(dex);
    auto time = minDisarmTime(traps);

    // Check trap selection invariant
    check_trap_selection_invariant(traps.size());

    return time <= maxTime;
}

ll solve(ll maxTime) {
    ll minDex = 1;
    ll maxDex = maxSize;

    // Check initial binary search invariant
    check_binary_search_invariant(maxDex - minDex);

    while (minDex < maxDex) {
        ll mid = (minDex + maxDex) / 2 + 1;
        auto enoughTime = solve(mid, maxTime);
        if (enoughTime)
            maxDex = mid - 1;
        else
            minDex = mid;

        // Check binary search invariant at each step
        check_binary_search_invariant(maxDex - minDex);
    }
    auto enoughTime = solve(maxDex, maxTime);
    return (enoughTime ? maxDex : maxDex + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, t;
    cin >> m >> n >> k >> t;
    for (ll i = 0; i < m; ++i) cin >> a[i];
    for (ll i = 0; i < k; ++i) {
        ll l, d, r;
        cin >> l >> r >> d;
        dexToLR[d].emplace(l, r);
    }
    auto maxTime = t - n - 1;
    auto maxDexOfSoldier = solve(maxTime);
    ll answer = 0;
    for (ll i = 0; i < m; ++i)
        if (a[i] >= maxDexOfSoldier - 1) ++answer;
    cout << answer;
}