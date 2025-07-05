#include <bits/stdc++.h>
using namespace std;

// Phase 3: Invariant Check Function
void check_nested_loop_invariant(int n, const map<int, int>& frequencyMap) {
    int maxFrequency = 0;
    for (const auto& entry : frequencyMap) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
        }
    }
    if (n > 50 && maxFrequency > (n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered due to high value repetitions across nested loops!" << endl;
        abort();
    }
}

int main() {
    int n, k = 0;
    cin >> n;
    int a[n], b[n];

    if (n == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Create a frequency map to track occurrences of each value
    map<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        frequencyMap[a[i]]++;
    }

    // Phase 4: Insert invariant check
    check_nested_loop_invariant(n, frequencyMap);

    for (int i = 0; i < n; i++) {
        k++;
        b[k - 1] = 0;
        for (int j = 0; j < n; j++)
            if (a[i] == a[j]) b[k - 1]++;
    }

    int max = b[0];
    for (int i = 0; i < n; i++)
        if (b[i] > max) max = b[i];
    
    cout << max;
    return 0;
}