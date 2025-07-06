#include <bits/stdc++.h>
using namespace std;

struct tri {
    int b, e, s;
};

bool operator<(tri an, tri ath) { return an.b < ath.b; }

// Checker functions for performance bottlenecks

void check_high_frequency_large_ranges(int ki, int rangeLength) {
    if (ki > 1000 && rangeLength > 100) {
        cerr << "Warning: High frequency and large range detected!" << endl;
        abort();
    }
}

void check_overlapping_positions_and_sorting(int overlappingCount) {
    if (overlappingCount > 500) {
        cerr << "Warning: Excessive overlapping positions leading to sorting overhead!" << endl;
        abort();
    }
}

void check_large_cumulative_length(int totalLength) {
    if (totalLength > 1000000) {
        cerr << "Warning: Large cumulative input length detected!" << endl;
        abort();
    }
}

int main() {
    int n, a[2000000] = {}, k, sup = 0;
    string y;
    cin >> n;
    vector<tri> vec;
    vector<string> st;

    int totalLength = 0; // To compute total cumulative length of strings
    for (int i = 0; i < n; i++) {
        cin >> y >> k;
        st.push_back(y);
        
        int rangeLength = y.size(); // Length of the current string
        totalLength += rangeLength * k; // Accumulate total length
        
        for (int j = 0; j < k; j++) {
            tri z;
            cin >> z.b;
            z.b--;
            z.e = y.size() + z.b - 1;
            z.s = i;
            vec.push_back(z);
        }
        
        // Check for high frequency and large ranges
        check_high_frequency_large_ranges(k, rangeLength);
    }

    // Check for large cumulative length
    check_large_cumulative_length(totalLength);

    sort(vec.begin(), vec.end());

    // Assuming a separate mechanism to count overlapping positions
    int overlappingCount = 0; // Placeholder for actual overlapping count
    check_overlapping_positions_and_sorting(overlappingCount);

    for (int i = vec[0].b; i <= vec[0].e; i++)
        a[i] = st[vec[0].s][i - vec[0].b] - 'a' + 1;

    sup = vec[0].e;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].e <= sup) continue;
        for (int j = max(sup + 1, vec[i].b); j <= vec[i].e; j++)
            a[j] = st[vec[i].s][j - vec[i].b] - 'a' + 1;
        sup = vec[i].e;
    }

    for (int i = 0; i <= sup; i++) {
        if (a[i] == 0)
            cout << 'a';
        else
            cout << (char)(a[i] - 1 + 'a');
    }
}