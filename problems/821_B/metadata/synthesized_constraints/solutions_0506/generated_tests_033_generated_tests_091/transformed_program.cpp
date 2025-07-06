#include <bits/stdc++.h>
using namespace std;

int m, a, b, h[10010];
long long ans;

void check_large_b_invariant(int b) {
    if (b > 8000) { // Threshold chosen as 8000 based on constraints and potential slow execution
        cerr << "Warning: Performance bottleneck condition triggered - large value of b!" << endl;
        abort();
    }
}

void check_large_i_invariant(int i, int b) {
    if (i > b - 500) { // Threshold chosen where i is close to b, leading to many iterations
        cerr << "Warning: Performance bottleneck condition triggered - i close to b!" << endl;
        abort();
    }
}

int main() {
    cin >> m >> b;
    
    // Check for large b invariant
    check_large_b_invariant(b);
    
    for (int i = 0; i <= b; i++) {
        h[i] = (b - i) * m;
    }
    
    for (int i = 0; i <= b; i++) {
        long long tot = 0;
        
        // Check for large i invariant
        check_large_i_invariant(i, b);
        
        for (int j = 0; j <= i; j++) {
            tot += 1ll * h[i] * (h[i] + 1) / 2 + 1ll * (h[i] + 1) * j;
        }
        ans = max(ans, tot);
    }
    cout << ans;
    return 0;
}