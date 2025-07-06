#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_frequency_invariant(int max_frequency, int n) {
    if (max_frequency > n / 2) {  // Using n/2 as a threshold for high frequency
        cerr << "Warning: High frequency invariant triggered - excessive repetitions of a single value!" << endl;
        abort();
    }
}

void check_large_input_repeated_elements(int n, int unique_elements) {
    if (n > 50 && unique_elements < n / 2) {  // Assumption: less than half of elements are unique
        cerr << "Warning: Large input with repeated elements invariant triggered - potential performance degradation!" << endl;
        abort();
    }
}

int main() {
    vector<int> v;
    int n, i, j, c, c1;
    c1 = 0;
    vector<int>::iterator it, it2;
    
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> j;
        v.push_back(j);
    }

    it = v.begin();
    it2 = v.end();

    // Count frequency of each element
    map<int, int> frequency_map;
    for (i = 0; i < n; i++) {
        frequency_map[v[i]]++;
    }
    
    int max_frequency = 0;
    for (auto &entry : frequency_map) {
        if (entry.second > max_frequency) {
            max_frequency = entry.second;
        }
    }
    
    int unique_elements = frequency_map.size();

    // Performance invariant checks
    check_high_frequency_invariant(max_frequency, n);
    check_large_input_repeated_elements(n, unique_elements);

    // Calculate the minimum number of pockets needed
    cout << max_frequency;
}