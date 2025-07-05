#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;

const int MAXN = 100100;
set<pair<long long, int> > st[2];
long long b, a[MAXN], sum = 0;
int n, k;

void norm() {
    while ((int)st[0].size() > k) {
        pair<long long, int> t = *st[0].begin();
        st[1].insert(t);
        st[0].erase(t);
        sum -= t.first;
    }
    while ((int)st[0].size() < k && !st[1].empty()) {
        pair<long long, int> t = *st[1].rbegin();
        st[0].insert(t);
        st[1].erase(t);
        sum += t.first;
    }
}

void add(int v) {
    sum += a[v];
    st[0].insert(make_pair(a[v], v));
    norm();
}

void erase(int v) {
    if (st[0].count(make_pair(a[v], v))) sum -= a[v];
    st[0].erase(make_pair(a[v], v));
    st[1].erase(make_pair(a[v], v));
    norm();
}

void check_balancing_invariant(int set0Size, int set1Size, int k) {
    if (set0Size > k || set1Size > (set0Size + set1Size - k)) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive balancing of sets!" << endl;
        abort();
    }
}

void check_iteration_invariant(int currentIteration, int maxIterations) {
    if (currentIteration > maxIterations) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

void check_resource_invariant(long long sum, long long b, int k) {
    if (sum > b && k > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient resources for administration's actions!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k >> b;
    k--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i + 1 != n) add(i);
    }

    // Check balancing invariant after initialization
    check_balancing_invariant(st[0].size(), st[1].size(), k);
    
    for (int i = 0; i < n - 1; i++) {
        erase(i);
        if (b - sum < a[i]) {
            cout << i + 1 << endl;
            return 0;
        }
        add(i);

        // Check resource invariant after each operation
        check_resource_invariant(sum, b, k);

        // Check iteration invariant in the main loop
        check_iteration_invariant(i, n - 2);
    }
    cout << n << endl;
    return 0;
}