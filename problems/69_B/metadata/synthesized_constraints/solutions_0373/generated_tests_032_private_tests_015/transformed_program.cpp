#include <bits/stdc++.h>
using namespace std;

struct Competitor {
    int start;
    int end;
    int time;
    int profit;
    int timeNow;
    int secNow;
    int id;
    bool finished;
};

struct Section {
    int compid;
};

Competitor comp[102];
Section sec[102];

// Checker Function for Performance Bottlenecks
void check_competitor_range_invariant(int startSection, int endSection, int totalSections) {
    if (startSection <= 10 && (endSection - startSection + 1) >= totalSections / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - competitor covers a large range starting early!" << endl;
        abort();
    }
}

int main() {
    int n, m, i, j, finM(0), s(0);
    cin >> n >> m;

    // Add a check for performance bottleneck based on competitor ranges
    for (i = 1; i <= m; i++) {
        cin >> comp[i].start >> comp[i].end >> comp[i].time >> comp[i].profit;
        comp[i].timeNow = 0;
        comp[i].secNow = comp[i].start;
        comp[i].id = i;
        comp[i].finished = false;

        // Check for performance bottleneck conditions
        check_competitor_range_invariant(comp[i].start, comp[i].end, n);
    }

    comp[m + 1].start = 0;
    comp[m + 1].end = 0;
    comp[m + 1].time = 1001;
    comp[m + 1].profit = 0;
    comp[m + 1].timeNow = 0;
    comp[m + 1].secNow = 0;
    comp[m + 1].id = m + 1;
    comp[m + 1].finished = true;

    for (i = 1; i <= n; i++) {
        sec[i].compid = m + 1;
    }

    while (finM < m) {
        for (i = 1; i <= m; i++) {
            comp[i].timeNow++;
            if (comp[i].timeNow > comp[i].time && !comp[i].finished) {
                comp[i].timeNow = 1;
                if ((comp[i].time < comp[sec[comp[i].secNow].compid].time ||
                     comp[i].time == comp[sec[comp[i].secNow].compid].time &&
                     i < sec[comp[i].secNow].compid) &&
                    sec[comp[i].secNow].compid && comp[i].secNow <= n) {
                    sec[comp[i].secNow].compid = i;
                }
                comp[i].secNow++;
                if (comp[i].secNow > comp[i].end) {
                    comp[i].finished = true;
                    finM++;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        s += comp[sec[i].compid].profit;
    }
    cout << s << endl;
    return 0;
}