#include <bits/stdc++.h>
using namespace std;

struct athlete {
    int l, r, t, c;
};

bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    if (get<0>(t1) < get<0>(t2)) {
        return 1;
    } else if (get<0>(t1) == get<0>(t2) && get<1>(t1) < get<1>(t2)) {
        return 1;
    }
    return 0;
}

// Checker functions
void check_large_vector_invariant(int vectorSize) {
    if (vectorSize > 20) { // Threshold based on experience, considering n, m <= 100
        cerr << "Warning: Performance bottleneck condition triggered - large vector size for sorting!" << endl;
        abort();
    }
}

void check_frequent_sorting_invariant(int sortCount) {
    if (sortCount > 10) { // Arbitrary threshold indicating frequent sorting for n sections
        cerr << "Warning: Performance bottleneck condition triggered - frequent sorting!" << endl;
        abort();
    }
}

void check_athlete_overlap_invariant(int overlapCount) {
    if (overlapCount > 30) { // Threshold for high athlete overlap
        cerr << "Warning: Performance bottleneck condition triggered - high athlete overlap!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    athlete arr[105];
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i].l >> arr[i].r >> arr[i].t >> arr[i].c;
    }

    vector<vector<tuple<int, int, int>>> v(102, vector<tuple<int, int, int>>());
    int totalOverlap = 0; // To track total athlete overlap

    for (int i = 1; i <= m; ++i) {
        for (int j = arr[i].l; j <= arr[i].r; ++j) {
            v[j].push_back(make_tuple(arr[i].t, i, arr[i].c));
        }
    }

    int sortCount = 0; // To track the number of sorting operations
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        int vectorSize = v[i].size();
        
        // Check for large vector size in each section
        check_large_vector_invariant(vectorSize);

        if (vectorSize == 0) {
            continue;
        }
        
        sort(v[i].begin(), v[i].end(), comp);
        sortCount++;

        // Check for frequent sorting operations
        check_frequent_sorting_invariant(sortCount);

        c += get<2>(v[i][0]);
        
        totalOverlap += vectorSize;
    }

    // Check for high athlete overlap across sections
    check_athlete_overlap_invariant(totalOverlap);

    cout << c << endl;
    return 0;
}