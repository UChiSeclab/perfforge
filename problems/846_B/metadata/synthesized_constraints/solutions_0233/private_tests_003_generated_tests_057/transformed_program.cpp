#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
priority_queue<int, vector<int>, greater<int> > pq;
int n, k, m, t[MAXN], s, c, ans;

void check_nested_loop_invariant(int n, int k) {
    if (n > 40 && k > 40) {
        cerr << "Warning: Performance bottleneck condition triggered due to high n and k, leading to excessive nested loop operations!" << endl;
        abort();
    }
}

void check_time_constraint_invariant(int M, int s) {
    if (M > 100 * s) {
        cerr << "Warning: Performance bottleneck condition triggered due to large M relative to s, causing extensive while loop operations!" << endl;
        abort();
    }
}

void check_task_completion_invariant(int n, int k, int M, int s) {
    if ((n * (k + 1)) > M && s < k * 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to trying to complete many full tasks!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &t[i]);
        s += t[i];
    }
    
    // Inserting invariant checks after input processing
    check_nested_loop_invariant(n, k); // Check for excessive nested loops
    check_time_constraint_invariant(m, s); // Check for large M relative to s
    check_task_completion_invariant(n, k, m, s); // Check for strategy of completing many full tasks
    
    for (int i = 0; i <= n && i * s <= m; i++) {
        pq = priority_queue<int, vector<int>, greater<int> >();
        int res = (k + 1) * i;
        for (int j = 1; j <= k; j++)
            for (int l = 1; l <= n - i; l++) pq.push(t[j]);
        c = s * i;
        while (!pq.empty() && c + pq.top() <= m) {
            c += pq.top();
            res++;
            pq.pop();
        }
        ans = max(ans, res);
    }
    printf("%d\n", ans);
}