#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

// Checker functions
void check_unbalanced_happiness(int happyBoys, int totalBoys, int happyGirls, int totalGirls) {
    if (abs(happyBoys - happyGirls) > (totalBoys + totalGirls) / 4) {
        cerr << "Warning: Performance bottleneck due to unbalanced happiness distribution!" << endl;
        abort();
    }
}

void check_unnecessary_iterations(int iterationCount, int maxIterations, int progress) {
    if (iterationCount > maxIterations / 2 && progress < (iterationCount / 10)) {
        cerr << "Warning: Performance bottleneck due to insufficient progress in iterations!" << endl;
        abort();
    }
}

void check_initial_happiness_spread(int happyBoys, int happyGirls, int totalBoys, int totalGirls) {
    if (happyBoys < totalBoys / 4 && happyGirls < totalGirls / 4) {
        cerr << "Warning: Performance bottleneck due to insufficient initial happiness spread!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    bool z[n], z1[m];
    memset(z, 0, sizeof(z));
    memset(z1, 0, sizeof(z1));
    
    int k;
    cin >> k;
    int c = k;
    while (k--) {
        int i;
        cin >> i;
        z[i] = 1;
    }
    
    cin >> k;
    int cc = k;
    while (k--) {
        int i;
        cin >> i;
        z1[i] = 1;
    }

    // Check initial conditions
    check_unbalanced_happiness(c, n, cc, m);
    check_initial_happiness_spread(c, cc, n, m);
    
    int ctr = 0, cap = 100 * 100 * 100;
    int initialC = c, initialCC = cc;
    while (ctr < cap) {
        int i = ctr % n, ii = ctr % m;
        if (z[i] && !z1[ii]) {
            z1[ii] = 1;
            cc++;
        } else if (!z[i] && z1[ii]) {
            z[i] = 1;
            c++;
        }
        if (c == n && cc == m) break;
        ctr++;
        
        // Check progress during execution
        if (ctr % 1000 == 0) {
            check_unnecessary_iterations(ctr, cap, (c - initialC) + (cc - initialCC));
        }
    }
    
    if (c == n && cc == m)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}