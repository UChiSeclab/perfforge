#include <bits/stdc++.h>
using namespace std;

long long mem[100100];
long long nn = 100000;

void check_mem_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: mem_invariant triggered - too many non-zero entries in mem array" << endl;
        abort();
    }
}

void check_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: iteration_invariant triggered - large range of iteration in loops" << endl;
        abort();
    }
}

void check_vector_resize_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: vector_resize_invariant triggered - vectors resized too frequently" << endl;
        abort();
    }
}

void Set(long long n, long long r) {
    check_iteration_invariant(r > 50); // Check if the range of iteration is large
    for (long long i = 1; i <= r; i++) 
        mem[i]--, mem[n--]++;
    return;
}

void Set2(long long n, long long r) {
    check_iteration_invariant(r > 50); // Check if the range of iteration is large
    for (long long i = 1; i <= r; i++) 
        mem[i]++, mem[n--]--;
    return;
}

double calc() {
    vector<long long> a, b;
    for (long long i = nn; i >= 1; i--) {
        if (mem[i] > 0) {
            while (mem[i]--) a.push_back(i);
        } else if (mem[i] < 0) {
            mem[i] = -mem[i];
            while (mem[i]--) b.push_back(i);
        }
    }
    
    check_mem_invariant(a.size() + b.size() > 100); // Check if vectors grow too large
    
    double ret = 1.0;
    long long ia = 0, ib = 0, sa = a.size(), sb = b.size();
    while (ia < sa || ib < sb) {
        if (ia < sa) ret *= a[ia];
        if (ib < sb) ret /= b[ib];
        ia++, ib++;
    }
    return ret;
}

int main() {
    long long n, m, h;
    long long a[1010], sum = 0;
    scanf("%I64d %I64d %I64d", &n, &m, &h);
    for (long long i = 1; i <= m; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    }
    sum--;
    n--;
    a[h]--;
    long long x = sum - a[h];
    double ans = 0.0;
    for (long long i = 1; i <= n; i++) {
        if (i <= a[h] && n - i <= x) {
            memset(mem, 0, sizeof(mem));
            Set(a[h], i);
            Set(x, n - i);
            Set2(sum, n);
            ans += calc();
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}