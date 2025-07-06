#include <bits/stdc++.h>
using ll = long long;
const ll maxSize = 200007;
using namespace std;
ll a[maxSize];
unordered_map<ll, set<pair<ll, ll>>> dexToLR;

void check_map_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to wide dexterity range in map iteration!" << endl;
        abort();
    }
}

void check_trap_processing_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to excessive trap processing!" << endl;
        abort();
    }
}

void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to sorting large data sets multiple times!" << endl;
        abort();
    }
}

void check_conditional_checks_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to excessive conditional checks!" << endl;
        abort();
    }
}

ll minDisarmTime(const vector<pair<ll, ll>>& traps) {
    ll time = 0;
    auto it = traps.begin();
    ll st = 0;
    ll end = -1;
    while (it != traps.end()) {
        auto next = *it;
        if (next.first > end) {
            time += end - st + 1;
            st = next.first;
        }
        end = max(end, next.second);
        ++it;
    }
    time += end - st + 1;
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
    
    // Check if the number of elements in the result is large, which would affect sorting performance
    check_sorting_invariant(result.size() > 10000); // Example threshold

    sort(result.begin(), result.end());
    return result;
}

bool solve(ll dex, ll maxTime) {
    auto traps = chooseTrapsByDex(dex);
    
    // Check if traps size indicates excessive processing
    check_trap_processing_invariant(traps.size() > 10000); // Example threshold
    
    auto time = minDisarmTime(traps);
    return time <= maxTime;
}

ll solve(ll maxTime) {
    ll minDex = 1;
    ll maxDex = maxSize;
    while (minDex < maxDex) {
        ll mid = (minDex + maxDex) / 2 + 1;
        
        // Check for wide dexterity range iteration
        check_map_iteration_invariant(mid - minDex > 10000); // Example threshold
        
        auto enoughTime = solve(mid, maxTime);
        if (enoughTime)
            maxDex = mid - 1;
        else
            minDex = mid;
    }
    auto enoughTime = solve(maxDex, maxTime);
    return (enoughTime ? maxDex : maxDex + 1);
}

int main() {
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