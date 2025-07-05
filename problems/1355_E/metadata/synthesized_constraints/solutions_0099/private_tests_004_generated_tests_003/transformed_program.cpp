#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, c, h[500005], s1[500005], s2[500005], ans = ((long long)1e18);

void chk(int i, long long x) {
    if (i > n) return;
    long long t1 = x * i - s1[i], t2 = s2[i + 1] - x * (n - i);
    long long s = min(t1, t2) * c;
    if (t1 > t2)
        s += (t1 - t2) * a;
    else
        s += (t2 - t1) * b;
    ans = min(ans, s);
}

// Check for excessive while loop iterations
void check_while_loop_invariant(long long t, long long maxHeight) {
    if (t > maxHeight) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive while loop iterations!" << endl;
        abort();
    }
}

// Check for homogeneous or similar pillar heights
void check_homogeneous_heights(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - homogeneous or similar pillar heights!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> a >> b >> c;
    c = min(c, a + b);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
    }
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + h[i];
    for (int i = n; i >= 1; i--) s2[i] = s2[i + 1] + h[i];
    for (int i = 1; i <= n; i++) chk(i, h[i]);
    
    long long t = s1[n] / n;
    int p = lower_bound(h + 1, h + n + 1, t) - h - 1;
    chk(p, t);
    
    // Check homogeneous heights where all are equal
    bool allEqual = (h[1] == h[n]);
    check_homogeneous_heights(allEqual);
    
    // Check excessive loop iteration condition before the while loop
    check_while_loop_invariant(t, h[n]);
    
    while (t + 1 > h[p]) p++; 
    if (t < h[p]) p--;
    chk(p, t + 1);
    
    cout << ans << endl;
    return 0;
}