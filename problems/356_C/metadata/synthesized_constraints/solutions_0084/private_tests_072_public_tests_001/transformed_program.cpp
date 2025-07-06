#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 4000000 + 10;
int ans, sum;
int a[5];  // Adjusted index to match 1-based access, hence size 5
int b[5];

// Phase 3 Checkers
void check_high_iteration_invariant(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations!" << endl;
        abort();
    }
}

void check_compartment_configuration_invariant(int oneOrTwoCount, int n) {
    if (oneOrTwoCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - many compartments with 1 or 2 students!" << endl;
        abort();
    }
}

void check_distribution_complexity_invariant(int imbalanceScore, int threshold) {
    if (imbalanceScore > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - significant imbalance in distribution!" << endl;
        abort();
    }
}

void solve() {
    ans = 0;
    
    if (sum == 0) {
        cout << 0 << endl;
        return;
    }
    
    if (sum == 1 || sum == 2 || sum == 5) {
        cout << -1 << endl;
        return;
    }
    
    int x;
    int res = 0x3f3f3f3f;
    int last = 0;
    bool ok = 1;
    int iterationCount = 0;
    
    while (ok) {
        for (int i = last;; i++) {
            iterationCount++;
            if (3 * i > sum) {
                ok = 0;
                break;
            }
            if ((sum - 3 * i) % 4 == 0) {
                x = i;
                last = x + 1;
                break;
            }
        }
        
        check_high_iteration_invariant(iterationCount, 1000);  // Example threshold
        
        if (!ok) break;
        
        for (int i = 1; i <= 4; i++) a[i] = b[i];
        
        ans = 0;
        int y = (sum - 3 * x) / 4;
        int xx = min(a[3], x);
        x -= xx;
        a[3] -= xx;
        int yy = min(a[4], y);
        y -= yy;
        a[4] -= yy;
        
        if (x) {
            if (y) {
                int tmp = min(a[2], a[1] / 2);
                tmp = min(tmp, y);
                y -= tmp;
                ans += 2 * tmp;
                a[2] -= tmp;
                a[1] -= 2 * tmp;
                tmp = min(x, a[2]);
                tmp = min(tmp, a[1]);
                x -= tmp;
                ans += tmp;
                a[1] -= tmp;
                a[2] -= tmp;
                tmp = min(y, a[2] / 2);
                ans += tmp * 2;
                a[2] -= tmp * 2;
                y -= tmp;
                tmp = a[2] / 3;
                ans += tmp * 2;
                x -= tmp * 2;
                ans += y * 3;
                ans += x * 2;
            } else {
                ans += a[4];
                int free = a[4];
                x -= a[4];
                a[4] = 0;
                int tmp = min(a[2], free);
                a[2] -= tmp;
                free -= tmp;
                x -= tmp;
                tmp = min(a[2], a[1]);
                ans += tmp;
                a[2] -= tmp;
                a[1] -= tmp;
                x -= tmp;
                if (a[2]) {
                    x -= a[2] / 3 * 2;
                    ans += a[2] / 3 * 2;
                    a[2] = 0;
                }
                ans += 2 * x - free;
            }
        } else if (y) {
            if (a[3] < a[1]) {
                a[1] -= a[3];
                y -= a[3];
                ans += a[3];
                a[3] = 0;
                int tmp = a[1] / 2;
                int can = min(tmp, a[2]);
                a[2] -= can;
                a[1] -= can * 2;
                ans += can * 2;
                y -= can;
                if (a[2]) {
                    ans += a[2];
                } else if (a[1]) {
                    ans += a[1] / 4 * 3;
                }
            } else {
                a[3] -= a[1];
                ans += a[1];
                a[1] = 0;
                if (a[2] >= a[3] / 2) {
                    ans += a[3];
                    a[2] -= a[3] / 2;
                    a[3] = 0;
                    ans += a[2];
                } else {
                    ans += a[2] * 2;
                    a[3] -= a[2] * 2;
                    a[2] = 0;
                    ans += a[3];
                }
            }
        }
        
        res = min(res, ans);
    }
    cout << res << endl;
}

int main() {
    ans = 0;
    cin >> n;
    sum = 0;
    int oneOrTwoCount = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
        sum += x;
        
        if (x == 1 || x == 2) {
            oneOrTwoCount++;
        }
    }
    
    check_compartment_configuration_invariant(oneOrTwoCount, n);
    
    int imbalanceScore = abs(b[1] - b[3]) + abs(b[2] - b[4]);
    check_distribution_complexity_invariant(imbalanceScore, 50);  // Example threshold
    
    solve();
    return 0;
}