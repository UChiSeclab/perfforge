#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance-characterizing invariants
void check_server_utilization(int n, int ki, int di) {
    if (ki > n * 0.9 && di > 500) { // 90% of servers and long duration
        cerr << "Warning: High server utilization invariant triggered!" << endl;
        abort();
    }
}

void check_task_rescheduling(int last_t, int current_t, int di) {
    if (current_t <= last_t + di) { // Overlapping task times
        cerr << "Warning: Frequent task rescheduling invariant triggered!" << endl;
        abort();
    }
}

void check_rapid_task_arrival(int n, int ki, int prev_t, int current_t) {
    if (ki > n * 0.8 && (current_t - prev_t) < 10) { // 80% of servers and rapid arrival
        cerr << "Warning: Task timing and resource saturation invariant triggered!" << endl;
        abort();
    }
}

int n, q;
set<int> a;
vector<int> t, k, d;
vector<set<int> > s;
set<pair<int, int> > task;

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) a.insert(i + 1);
    k.resize(q);
    t = d = k;
    int last_t = 0;

    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &t[i], &k[i], &d[i]);
        
        // Insert checkers at strategic points to avoid tight loops
        check_server_utilization(n, k[i], d[i]);
        if (i > 0) {
            check_task_rescheduling(last_t, t[i], d[i - 1]);
            check_rapid_task_arrival(n, k[i], t[i - 1], t[i]);
        }
        
        task.insert(pair<int, int>(t[i], i));
        last_t = t[i];
    }
    
    s.resize(q);
    while (((int)task.size())) {
        int u = task.begin()->second;
        task.erase(task.begin());
        if (u >= 0) {
            if (((int)a.size()) < k[u]) {
                printf("-1\n");
                continue;
            }
            int sum = 0;
            for (int i = 0; i < k[u]; ++i) {
                sum += *a.begin();
                s[u].insert(*a.begin());
                a.erase(a.begin());
            }
            printf("%d\n", sum);
            task.insert(pair<int, int>(t[u] + d[u], -u - 1));
        } else {
            u = -u - 1;
            a.insert(s[u].begin(), s[u].end());
            s[u].clear();
        }
    }
    return 0;
}