#include <bits/stdc++.h>
using namespace std;

void check_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations!" << endl;
        abort();
    }
}

void check_boundary_checks_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant boundary checks!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;

    vector<pair<long long, long long>> p(4 * n + 1);
    for (long long i = 0; i < 4 * n + 1; i++)
        cin >> p[i].first >> p[i].second;

    // Check added before the loops to prevent excessive iterations
    check_loop_invariant(n > 10); // Though n is guaranteed to be <= 10, this serves as a guard

    for (long long x = 0; x <= 50; x++) {
        for (long long y = 0; y <= 50; y++) {
            for (long long side = 1; side <= 100; side++) {
                
                // Checking if the side is unnecessarily large given constraints
                check_boundary_checks_invariant(side > 50); // Typically, a side larger than 50 should not be needed.

                vector<pair<long long, long long>> out;
                for (auto pt : p) {
                    if (pt.first != x && pt.first != x + side && pt.second != y &&
                        pt.second != y + side)
                        out.push_back(pt);
                    else if (pt.first < x || pt.first > x + side || pt.second < y ||
                             pt.second > y + side)
                        out.push_back(pt);
                }
                if (out.size() == 1) {
                    cout << out[0].first << " " << out[0].second << "\n";
                    return 0;
                }
            }
        }
    }
}