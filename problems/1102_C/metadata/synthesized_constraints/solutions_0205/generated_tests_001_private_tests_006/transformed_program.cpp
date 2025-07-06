#include <bits/stdc++.h>
using namespace std;

// Function to check sorting overhead
void check_sorting_overhead(bool condition) {
    if (condition) {
        cerr << "Warning: sorting_overhead triggered - repeatedly sorting due to x <= y with low durability doors!" << endl;
        abort();
    }
}

// Function to check loop iterations
void check_loop_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: loop_iterations triggered - excessive iterations with x <= y and similar low durability!" << endl;
        abort();
    }
}

// Function to check initial conditions
void check_initial_conditions(bool condition) {
    if (condition) {
        cerr << "Warning: initial_conditions triggered - low initial durability with x <= y leading to repeated adjustments!" << endl;
        abort();
    }
}

int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    // Check initial conditions
    int low_durability_count = count_if(vec.begin(), vec.end(), [&](long long durability) { return durability <= 2 * y; });
    check_initial_conditions(x <= y && low_durability_count > n / 2);
    
    sort(vec.begin(), vec.end());
    if (x > y) {
        cout << n;
    } else {
        int i = 0;
        int count = 0;
        long long zero = 0;
        
        while (i < n) {
            vec[i] = max(zero, vec[i] - x);
            if (vec[i] == 0 && (i + 1 < n || n == 1)) {
                vec[i + 1] += y;
                i++;
                count++;
                sort(vec.begin(), vec.end());
                
                // Check sorting overhead and loop iterations
                check_sorting_overhead(true);
                check_loop_iterations(true);
                
            } else {
                vec[i] += y;
                break;
            }
        }
        cout << count;
    }
}