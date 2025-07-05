#include <bits/stdc++.h>
using namespace std;

void check_loop_invariant(int n) {
    if (n >= 45) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations." << endl;
        abort();
    }
}

void check_sort_invariant(int n) {
    if (n >= 45) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting operations in nested loops." << endl;
        abort();
    }
}

void check_pairing_invariant(int n) {
    if (n >= 45) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant pair operations likely." << endl;
        abort();
    }
}

int main() {
    int n, num, ans, sum;
    int a[110], b[110];
    
    ans = 0x3f3f3f3f;
    cin >> n;
    
    check_loop_invariant(n);  // Check the loop invariant
    check_sort_invariant(n);  // Check the sorting invariant
    check_pairing_invariant(n);  // Check the pairing invariant
    
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (i == j) continue;
            sum = 0;
            num = 0;
            memset(b, 0, sizeof(b));
            for (int k = 1; k <= 2 * n; k++) {
                if (k != i && k != j) {
                    num++;
                    b[num] = a[k];
                }
            }
            sort(b + 1, b + num + 1);
            for (int k = 1; k <= num; k += 2) {
                sum += (b[k + 1] - b[k]);
            }
            ans = min(ans, sum);
        }
    }
    cout << ans;
    return 0;
}