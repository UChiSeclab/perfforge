#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_late_synchronize_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Late synchronization invariant triggered - excessive iterations without synchronization!" << endl;
        abort();
    }
}

void check_map_size_invariant(size_t mapSize, int iteration) {
    if (iteration == 1000000 && mapSize > 10000) { // Arbitrary threshold for map size
        cerr << "Warning: Map size invariant triggered - map growing excessively large!" << endl;
        abort();
    }
}

void check_arithmetic_pattern_invariant(int a, int c) {
    if (a == c) { // Simple case where increments are identical
        cerr << "Warning: Arithmetic pattern invariant triggered - identical increments lead to inefficient looping!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Check arithmetic pattern invariant before loop
    check_arithmetic_pattern_invariant(a, c);

    map<long long, bool> mp;
    for (int i = 0; i <= 1000000; i++) {
        int p = b + (a * i), q = d + (i * c);
        if (mp[p]) {
            cout << p << endl;
            return 0;
        }
        mp[p] = 1;
        if (mp[q]) {
            cout << q << endl;
            return 0;
        }
        mp[q] = 1;
        
        // Check the map size invariant within the loop
        check_map_size_invariant(mp.size(), i);
    }

    // Check if the loop reaches maximum iterations - potential late sync issue
    check_late_synchronize_invariant(true);

    cout << "-1";
    return 0;
}