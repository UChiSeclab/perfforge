#include <bits/stdc++.h>
using namespace std;
long long int a[(int)1e5];

long long int f(int i, int d) {
    if (a[i] == 1) return 0;
    long long int mn = a[i] / d;
    long long int mx = mn + !!(a[i] % d);
    long long int cur = mn * mn * (d - a[i] % d);
    cur += mx * mx * (a[i] % d);
    d++;
    mn = a[i] / d;
    mx = mn + !!(a[i] % d);
    cur -= mn * mn * (d - a[i] % d);
    cur -= mx * mx * (a[i] % d);
    return cur;
}

struct st {
    int i, d;
    bool operator<(const st& o) const { return f(i, d) < f(o.i, o.d); }
};

// Checker functions
void check_high_division_count(int n, int k) {
    if (k > 2 * n) { // Condition: k significantly exceeds n
        cerr << "Warning: Performance bottleneck condition triggered - high division count!" << endl;
        abort();
    }
}

void check_frequent_function_evaluation(int functionCalls, int threshold) {
    if (functionCalls > threshold) { 
        cerr << "Warning: Performance bottleneck condition triggered - frequent function evaluation!" << endl;
        abort();
    }
}

void check_priority_queue_stress(int pqOperations, int threshold) {
    if (pqOperations > threshold) { 
        cerr << "Warning: Performance bottleneck condition triggered - priority queue stress!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    // Insert check after reading inputs
    check_high_division_count(n, k);

    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    priority_queue<st> pq;
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        pq.push({i, 1});
        ans += a[i] * a[i];
    }

    int functionCalls = 0;  // Track function calls to f
    int pqOperations = 0;  // Track priority queue operations

    for (int i = n; i < k; i++) {
        auto t = pq.top();
        pq.pop();
        ans -= f(t.i, t.d);
        pq.push({t.i, t.d + 1});

        functionCalls++;
        pqOperations++;

        // Optionally check the function call frequency and priority queue stress
        check_frequent_function_evaluation(functionCalls, 1000000);  // Example threshold
        check_priority_queue_stress(pqOperations, 1000000);  // Example threshold
    }
    cout << ans << "\n";
}