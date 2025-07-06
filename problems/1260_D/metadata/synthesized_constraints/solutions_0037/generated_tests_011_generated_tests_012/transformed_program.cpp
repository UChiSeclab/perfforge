#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 * 2;
long long n, m, k, t, niz[MAXN + 5], r, najm, najv, br, nes[MAXN + 5];
pair<long long, pair<long long, long long> > niz1[MAXN + 5];

void check_trap_complexity_invariant(int activeTraps, int threshold) {
    if (activeTraps > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of active traps!" << endl;
        abort();
    }
}

void check_trap_range_invariant(int totalTrapRange, int threshold) {
    if (totalTrapRange > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large total trap range!" << endl;
        abort();
    }
}

void check_agility_threshold_invariant(int lowAgilityCount, int totalSoldiers, double threshold) {
    if ((static_cast<double>(lowAgilityCount) / totalSoldiers) > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of low agility soldiers!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k >> m >> t;
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
    sort(niz, niz + n);
    for (int i = 0; i < m; i++) {
        cin >> niz1[i].first >> niz1[i].second.first >> niz1[i].second.second;
    }
    
    // Checkers for performance bottlenecks
    int activeTraps = 0;
    int totalTrapRange = 0;
    int lowAgilityCount = 0;
    int agilityThreshold = 100000; // Example threshold, can be adjusted
    
    for (int i = 0; i < m; i++) {
        if (niz1[i].second.second > agilityThreshold) {
            activeTraps++;
        }
        totalTrapRange += (niz1[i].second.first - niz1[i].first);
    }
    
    for (int i = 0; i < n; i++) {
        if (niz[i] < agilityThreshold) {
            lowAgilityCount++;
        }
    }
    
    // Running checks
    check_trap_complexity_invariant(activeTraps, 100); // Example threshold
    check_trap_range_invariant(totalTrapRange, 1000); // Example threshold
    check_agility_threshold_invariant(lowAgilityCount, n, 0.5); // Example threshold proportion
    
    long long hi = n, mid, lo = 0;
    while (hi > lo) {
        najv = 0;
        mid = (hi + lo) / 2;
        r = niz[mid];
        for (int i = 0; i < m; i++) {
            if (r < niz1[i].second.second && niz1[i].second.first >= niz1[i].first) {
                nes[niz1[i].second.first]--;
                nes[niz1[i].first - 1]++;
            }
        }
        br = 0;
        for (int i = 0; i < MAXN + 3; i++) {
            br += nes[i];
            nes[i] = 0;
            if (br > 0) {
                najv += 2;
            }
        }
        if (najv + k + 1 <= t) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << n - hi;
    return 0;
}