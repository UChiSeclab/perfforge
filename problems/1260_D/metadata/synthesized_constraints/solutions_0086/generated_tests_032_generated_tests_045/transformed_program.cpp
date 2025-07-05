#include <bits/stdc++.h>
using namespace std;

struct soldier {
  long long location;
  long long disarm;
  long long danger;
};

vector<soldier> soldiers;
long long m, n, k, t;

bool success(long long agility) {
    const long long START = 0;
    const long long END = 1;
    vector<pair<long long, long long>> intervals;
    for (long long i = 0; i < k; i++) {
        struct soldier s = soldiers[i];
        if (s.danger > agility) {
            intervals.push_back(make_pair(s.location, START));
            intervals.push_back(make_pair(s.disarm, END));
        }
    }
    sort(intervals.begin(), intervals.end());
    long long result = 0;
    long long Counter = 0;
    for (unsigned i = 0; i < intervals.size(); i++) {
        if (Counter == 0) result++;
        if (Counter) result += (intervals[i].first - intervals[i - 1].first);
        (intervals[i].second) ? Counter-- : Counter++;
    }
    long long totaltime = n + 1 + 2 * result;
    return totaltime <= t;
}

// Phase 3: Checker for Trap Density and Soldier Agility Interaction
void check_trap_density_invariant(const vector<soldier>& soldiers, long long agility, long long threshold = 50) {
    long long countHighDangerTraps = 0;
    for (const auto& s : soldiers) {
        if (s.danger > agility) {
            countHighDangerTraps++;
        }
    }
    if (countHighDangerTraps > threshold) {
        cerr << "Warning: trap_density_invariant triggered - too many high danger traps for given agility" << endl;
        abort();
    }
}

// Phase 3: Checker for Number of Traps as a Bottleneck
void check_trap_count_invariant(long long k, long long threshold = 100) {
    if (k > threshold) {
        cerr << "Warning: trap_count_invariant triggered - excessive number of traps" << endl;
        abort();
    }
}

signed main() {
    cin >> m >> n >> k >> t;
    
    // Phase 4: Insert trap count invariant check after reading k
    check_trap_count_invariant(k);
    
    vector<long long> a(m, 0);
    long long maxAgil = 0;
    for (long long i = 0; i < m; i++) {
        cin >> a[i];
        maxAgil = max(maxAgil, a[i]);
    }
    for (long long i = 0; i < k; i++) {
        long long location, disarm, danger;
        cin >> location >> disarm >> danger;
        soldiers.push_back(
            {.location = location, .disarm = disarm, .danger = danger});
    }
    
    // Phase 4: Insert trap density invariant check before searching for the solution
    check_trap_density_invariant(soldiers, maxAgil);

    long long l = 0, r = maxAgil, mid, ans = 1e9;
    while (l <= r) {
        mid = (l + r) / 2;
        if (success(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    long long pass = 0;
    for (long long i = 0; i < m; i++) {
        if (a[i] >= ans) {
            pass++;
        }
    }
    cout << pass;
}