#include <bits/stdc++.h>
using namespace std;

struct A {
    int start, finish;
    int time, coin;
    A() {}
    A(int s, int f, int t, int c) { start = s, finish = f, time = t, coin = c; }
} a[105];

// Checker for high number of participants
void check_participant_invariant(int m) {
    if (m > 80) {  // Arbitrary threshold chosen well below the problem constraint
        cerr << "Warning: Performance bottleneck condition triggered - too many participants!" << endl;
        abort();
    }
}

// Checker for heavy use of data structures during overlapping sections
void check_overlap_invariant(int maxConcurrentParticipants) {
    if (maxConcurrentParticipants > 50) {  // Arbitrary threshold to detect overlap pressure
        cerr << "Warning: Performance bottleneck condition triggered - heavy overlap in sections!" << endl;
        abort();
    }
}

// Checker for high event complexity due to many start and finish events
void check_event_complexity_invariant(int eventCount) {
    if (eventCount > 180) {  // Assume eventCount = 2 * m, set threshold
        cerr << "Warning: Performance bottleneck condition triggered - high event complexity!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Check for high number of participants
    check_participant_invariant(m);

    multimap<pair<int, int>, int> s;
    for (int i = 0; i < m; i++) {
        cin >> a[i].start >> a[i].finish >> a[i].time >> a[i].coin;
        s.insert(make_pair(make_pair(a[i].start, 0), i));
        s.insert(make_pair(make_pair(a[i].finish, 1), i));
    }

    // Check for high event complexity
    check_event_complexity_invariant(2 * m);

    a[101].coin = 0;
    set<pair<int, int>> p;
    int last = 0, ans = 0;
    int maxConcurrentParticipants = 0;

    for (multimap<pair<int, int>, int>::iterator i = s.begin(); i != s.end(); i++) {
        int t = i->first.first, o = i->first.second, id = i->second;
        if (o == 0) {
            int dif = t - last - 1;
            last = t - 1;
            int winner = (p.size() ? p.begin()->second : 101);
            ans += a[winner].coin * dif;
            p.insert(make_pair(a[id].time, id));
        } else {
            int dif = t - last;
            last = t;
            int winner = (p.size() ? p.begin()->second : 101);
            ans += a[winner].coin * dif;
            p.erase(make_pair(a[id].time, id));
        }

        // Update max concurrent participants during overlap
        maxConcurrentParticipants = max(maxConcurrentParticipants, (int)p.size());
    }

    // Check for heavy overlap in sections
    check_overlap_invariant(maxConcurrentParticipants);

    cout << ans << "\n";
    return 0;
}