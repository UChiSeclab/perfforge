#include <bits/stdc++.h>
using namespace std;

void check_large_matchboxes(long total_matchboxes, long m) {
    if (total_matchboxes > m * 5) { // Arbitrarily chosen threshold factor
        cerr << "Warning: Performance bottleneck condition triggered - too many matchboxes relative to capacity!" << endl;
        abort();
    }
}

void check_high_weight_first(long *ar, long *br, int n) {
    for (int i = 0; i < n; ++i) {
        if (ar[i] > 10000000 && br[i] > 7) { // Arbitrary thresholds for illustrative purposes
            cerr << "Warning: Performance bottleneck condition triggered - large matchboxes with high weight processed first!" << endl;
            abort();
        }
    }
}

void check_capacity_mismatch(long total_matchboxes, long m) {
    if (total_matchboxes > m * 10) { // Arbitrarily chosen threshold factor
        cerr << "Warning: Performance bottleneck condition triggered - mismatch between capacity and available matchboxes!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long m, n;
    cin >> m >> n;
    long ar[n], br[n];
    
    long total_matchboxes = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i] >> br[i];
        total_matchboxes += ar[i];
    }
    
    // Check for large number of matchboxes relative to capacity
    check_large_matchboxes(total_matchboxes, m);
    
    // Check for high weight matchboxes processed first
    check_high_weight_first(ar, br, n);
    
    // Check for mismatch between bag capacity and available matchboxes
    check_capacity_mismatch(total_matchboxes, m);

    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (br[j] < br[j + 1]) {
                tmp = br[j];
                br[j] = br[j + 1];
                br[j + 1] = tmp;
                tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }

    int cnt = 0, i = 0;
    long sum = 0;
    while (cnt != m && i < n) {
        while (ar[i] != 0) {
            sum += br[i];
            ar[i]--;
            cnt++;
            if (cnt == m) break;
        }
        i++;
    }
    
    cout << sum;
    return 0;
}