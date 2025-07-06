#include <bits/stdc++.h>
using namespace std;

int a, l[100009], r[100009], z[100009 * 10], b, c;
long long sm;
vector<int> v;

// Checker for consecutive overlaps
void check_overlap_invariant(int count_consecutive_overlap) {
    if (count_consecutive_overlap > 1000) { // Arbitrary threshold based on problem context
        cerr << "Warning: Performance bottleneck condition triggered - extensive consecutive overlaps!" << endl;
        abort();
    }
}

// Checker for span between b and c
void check_span_invariant(int b, int c) {
    if ((c - b) > 1000) { // Arbitrary threshold for potentially large span
        cerr << "Warning: Performance bottleneck condition triggered - large span between b and c!" << endl;
        abort();
    }
}

int main() {
    cin >> a;
    for (int i = 1; i <= a; i++) cin >> l[i] >> r[i], z[l[i]]++, z[r[i]]--;
    for (int i = 1; i <= 1000000; i++) z[i] += z[i - 1];

    // Check for consecutive overlaps
    int count_consecutive_overlap = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (z[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
        if (z[i] == 2) {
            count_consecutive_overlap++;
        } else {
            check_overlap_invariant(count_consecutive_overlap);
            count_consecutive_overlap = 0; // Reset count when no overlap
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        if (z[i] == 2) {
            b = i;
            break;
        }
    }
    if (b == 0) {
        cout << a << endl;
        for (int i = 1; i <= a; i++) cout << i << ' ';
        return 0;
    }

    for (int i = 1000000; i >= 1; i--) 
        if (z[i] == 2) {
            c = i;
            break;
        }
    c++;
    
    // Check for large span between b and c
    check_span_invariant(b, c);

    for (int i = 1; i <= a; i++)
        if (l[i] <= b and r[i] >= c) sm++, v.push_back(i);

    cout << sm << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    return 0;
}