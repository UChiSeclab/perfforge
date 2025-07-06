#include <bits/stdc++.h>
using namespace std;

vector<int> V;
vector<int> T;
vector<int> N;

// Check if the number of operations to find the nearest square is excessive
void check_large_number_invariant(const vector<int>& V) {
    for (int i = 0; i < V.size(); ++i) {
        if (V[i] > 1000000) {  // Arbitrary threshold for "large" numbers
            if (sqrt(V[i]) > 1000) {  // If sqrt of a number is large, there are many iterations
                cerr << "Warning: Performance bottleneck condition triggered - excessive square root calculations." << endl;
                abort();
            }
        }
    }
}

// Check for imbalance in the distribution of squares and non-squares (indirect check)
void check_imbalance_invariant(int tak, int nie, int n) {
    if (abs(tak - nie) > n / 4) {  // A large imbalance can lead to more moves needed
        cerr << "Warning: Performance bottleneck condition triggered - imbalance between square and non-square piles." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    
    // Call checker for large numbers after input
    check_large_number_invariant(V);

    int tak = 0, nie = 0;
    sort(V.begin(), V.end());
    int p = 0;
    for (int i = 0; i < (int)V.size(); i++) {
        while ((p + 1) * (p + 1) <= V[i]) p++;
        int odl = min(V[i] - p * p, (p + 1) * (p + 1) - V[i]);
        if (odl == 0) {
            tak++;
            if (V[i] == 0)
                T.push_back(2);
            else
                T.push_back(1);
        } else {
            nie++;
            N.push_back(odl);
        }
    }

    // Call checker for imbalance after counting squares and non-squares
    check_imbalance_invariant(tak, nie, n);

    sort(T.begin(), T.end());
    sort(N.begin(), N.end());
    long long res = 0;
    if (tak > n / 2) {
        int zamien = tak - n / 2;
        for (int i = 0; i < zamien; i++) {
            res += (long long)T[i];
        }
    } else {
        int zamien = nie - n / 2;
        for (int i = 0; i < zamien; i++) {
            res += (long long)N[i];
        }
    }
    cout << res << endl;
}