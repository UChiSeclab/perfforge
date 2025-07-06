#include <bits/stdc++.h>
using namespace std;

// Checker function for high iteration count
void check_iteration_invariant(long long n) {
    int threshold = 50000; // Set an arbitrary threshold for when the loop becomes too large
    int x = sqrt(n) + 1;
    if (x > threshold) {
        cerr << "Warning: High iteration count potential bottleneck triggered!" << endl;
        abort();
    }
}

// Checker function for large number of unique divisions
void check_unique_divisions_invariant(map<int, int>& mp) {
    int threshold = 10000; // Set an arbitrary threshold for the number of unique elements in the map
    if (mp.size() > threshold) {
        cerr << "Warning: Large number of unique divisions potential bottleneck triggered!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    long long n;
    while (t--) {
        int a;
        map<int, int> mp;
        mp[0] = 1;
        map<int, int>::iterator it;
        cin >> n;
        
        // Check for high iteration count before the loop begins
        check_iteration_invariant(n);
        
        int x = sqrt(n) + 1;
        for (int i = 1; i <= x; i++) {
            a = n / i;
            if (mp[a] == 0 && mp[i] == 0) {
                mp[a] = 1;
                mp[i] = 1;
            }
        }
        
        // Check the map size after the loop to ensure it hasn't grown too large
        check_unique_divisions_invariant(mp);
        
        cout << mp.size() << endl;
        for (it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " ";
        }
        cout << endl;
    }
    return 0;
}