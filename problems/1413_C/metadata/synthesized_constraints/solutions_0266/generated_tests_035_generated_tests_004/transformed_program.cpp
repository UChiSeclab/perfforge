#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, a[7], b[100010], c[100010][7];
map<long long, vector<long long>> h;

void check_sort_invariant(int n, int sortCount) {
    if (n > 10000 && sortCount > n / 10) {
        cerr << "Warning: sort_invariant triggered - sorting fret differences too frequently!" << endl;
        abort();
    }
}

void check_multiset_invariant(int multisetOperations, int threshold) {
    if (multisetOperations > threshold) {
        cerr << "Warning: multiset_invariant triggered - excessive multiset operations!" << endl;
        abort();
    }
}

void check_iteration_invariant(int numNotes, int numFretPossibilities) {
    if (numNotes > 10000 && numFretPossibilities > numNotes * 6) {
        cerr << "Warning: iteration_invariant triggered - excessive fret calculations!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (long long i = 1; i <= 6; i++) {
        cin >> a[i];
    }
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> b[i];
    }

    set<long long> s;

    int sortCount = 0;
    int numFretPossibilities = 0;

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= 6; j++) {
            c[i][j] = b[i] - a[j];
            s.insert(c[i][j]);
            numFretPossibilities++;
        }
    }

    check_iteration_invariant(n, numFretPossibilities);

    for (long long i = 1; i <= n; i++) {
        sort(c[i] + 1, c[i] + 7);
        sortCount++;
        for (long long j = 1; j <= 6; j++) {
            h[c[i][j]].push_back(c[i][j]);
            h[c[i][j - 1]].push_back(-c[i][j]);
        }
    }

    check_sort_invariant(n, sortCount);

    auto it = s.end();
    it--;
    long long mn = 1e17;
    multiset<long long> ms;
    int multisetOperations = 0;
    const int multisetThreshold = 100000; // Example threshold, adjust as needed

    while (true) {
        long long x = *it;
        for (long long i = 0; i < h[x].size(); i++) {
            if (h[x][i] < 0) {
                auto it2 = ms.find(-h[x][i]);
                if (it2 != ms.end()) {
                    ms.erase(it2);
                }
            } else {
                ms.insert(h[x][i]);
            }
            multisetOperations++;
        }

        if (ms.size() == n) {
            auto it2 = ms.end();
            it2--;
            mn = min(*it2 - (*ms.begin()), mn);
        }
        if (it == s.begin()) {
            break;
        }
        it--;
    }

    check_multiset_invariant(multisetOperations, multisetThreshold);

    cout << mn;
    return 0;
}