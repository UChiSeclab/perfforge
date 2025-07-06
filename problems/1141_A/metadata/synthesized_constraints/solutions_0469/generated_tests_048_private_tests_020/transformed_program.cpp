#include <bits/stdc++.h>
using namespace std;

map<long long int, int> level;

// Checker functions for performance invariants
void check_search_space_expansion(long long n, long long m, int operations) {
    if (m > n && operations > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space expansion!" << endl;
        abort();
    }
}

void check_frequent_queue_operations(size_t queueSize) {
    if (queueSize > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent queue operations!" << endl;
        abort();
    }
}

void check_repeated_level_processing(int levelCount) {
    if (levelCount > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated level processing!" << endl;
        abort();
    }
}

long long bfs(long long n, long long m) {
    int cnt = 0;
    set<long long> Q;
    set<long long>::iterator it;
    Q.insert(n);
    level[n] = 0;

    while (!Q.empty()) {
        it = Q.begin();
        cnt++;
        long long frnt = *it;
        Q.erase(it);

        // Check for frequent queue operations
        check_frequent_queue_operations(Q.size());

        long long f = 2 * frnt, s = 3 * frnt;
        if (f > m && s > m) {
            return -1;
        }
        Q.insert(f);
        Q.insert(s);
        level[f] = level[frnt] + 1;
        level[s] = level[frnt] + 1;

        // Check for repeated level processing
        check_repeated_level_processing(level[f]);

        if (f == m || s == m) {
            return level[f];
        }

        // Check for search space expansion
        check_search_space_expansion(n, m, cnt);
    }
    return -1;
}

void solve() {
    long long n, m;
    cin >> n >> m;
    if (n == m) {
        cout << 0 << endl;
        return;
    }
    cout << bfs(n, m) << endl;
    return;
}

int main() {
    solve();
    return 0;
}