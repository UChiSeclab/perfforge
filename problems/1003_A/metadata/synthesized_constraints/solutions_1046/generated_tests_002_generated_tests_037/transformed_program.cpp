#include <bits/stdc++.h>
using namespace std;

// Checker for high frequency of duplicate values
void check_duplicate_values(int n, const vector<int>& freq) {
    int maxFrequency = 0;
    for (int f : freq) {
        if (f > maxFrequency) {
            maxFrequency = f;
        }
    }
    if (maxFrequency > n / 2) { // Arbitrary threshold based on observation
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of duplicate values!" << endl;
        abort();
    }
}

// Checker for excessive number of pockets
void check_number_of_pockets(int expectedPockets, int n) {
    if (expectedPockets > n / 2) { // Arbitrary threshold assuming more than half are duplicates
        cerr << "Warning: Performance bottleneck condition triggered - excessive number of pockets!" << endl;
        abort();
    }
}

// Checker for excessive iteration over pockets
void check_iteration_over_sets(int numberOfChecks, int n) {
    if (numberOfChecks > n * (n / 4)) { // Arbitrary threshold to detect excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration over sets!" << endl;
        abort();
    }
}

int main() {
    int n, val;
    vector<int> v;
    vector<set<int>> s;
    cin >> n;
    vector<int> frequency(101, 0); // Frequency array for coins
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
        frequency[val]++;
    }

    // Check for high frequency of duplicate values
    check_duplicate_values(n, frequency);

    int numberOfChecks = 0;
    for (int i = 0; i < n; i++) {
        bool test = false;
        for (auto& a : s) {
            numberOfChecks++; // Track the number of checks made
            if (a.count(v[i])) {
                // do nothing
            } else {
                test = true;
                a.insert(v[i]);
                break;
            }
        }
        if (!test) {
            set<int> ss;
            ss.insert(v[i]);
            s.push_back(ss);
        }
    }

    // Check for excessive number of pockets
    check_number_of_pockets(s.size(), n);

    // Check for excessive iteration over pockets
    check_iteration_over_sets(numberOfChecks, n);

    cout << s.size() << endl;
    return 0;
}