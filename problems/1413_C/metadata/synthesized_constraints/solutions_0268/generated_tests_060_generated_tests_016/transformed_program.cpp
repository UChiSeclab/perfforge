#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;

// Checker functions
void check_binary_search_repetition(int loopCount, int threshold) {
    if (loopCount > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive binary search repetitions!" << endl;
        abort();
    }
}

void check_similar_notes(int similarCount, int threshold) {
    if (similarCount >= threshold) {
        cerr << "Warning: Performance bottleneck due to large number of similar note values!" << endl;
        abort();
    }
}

void check_inefficient_range_reduction(int rangeSize, int threshold) {
    if (rangeSize > threshold) {
        cerr << "Warning: Performance bottleneck due to inefficient range reduction in binary search!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 6;
    int ary[n];
    for (int i = 0; i < n; ++i) {
        cin >> ary[i];
    }
    sort(ary, ary + n);

    int m;
    cin >> m;
    vector<int> note;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        note.push_back(a);
    }
    sort(note.begin(), note.end());

    // Check for large number of similar notes
    int similarNoteCount = 0, prevNote = -1;
    for (int i = 0; i < m; ++i) {
        if (note[i] == prevNote) {
            similarNoteCount++;
        } else {
            similarNoteCount = 0;
            prevNote = note[i];
        }
        check_similar_notes(similarNoteCount, 5); // Assuming threshold for similar notes
    }

    int ans = inf + 10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int mn = note[j] - ary[i];
            int lo = 0;
            int hi = 1e9;
            int binarySearchLoopCount = 0;
            while (hi > lo) {
                binarySearchLoopCount++;
                check_binary_search_repetition(binarySearchLoopCount, 1000); // Check binary search repetition count

                int mid = (hi + lo) / 2;
                int curl = 0;
                int curh = 0;
                int f = 0;
                for (int k = 0; k < n; ++k) {
                    int l = ary[k] + mn;
                    int h = l + mid;
                    if (l > curh) {
                        auto it = upper_bound(note.begin(), note.end(), curh);
                        if (it != note.end() && (*it) < l) {
                            f = 1;
                            break;
                        }
                        curl = l;
                        curh = h;
                    } else {
                        curh = h;
                    }
                }
                auto it = upper_bound(note.begin(), note.end(), curh);
                if (it != note.end()) {
                    f = 1;
                }
                if (f != 1) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
                
                // Check inefficient range reduction
                check_inefficient_range_reduction(hi - lo, 10000); // Assuming threshold for inefficient range reduction
            }
            ans = min(ans, lo);
        }
    }
    cout << ans << "\n";
    return 0;
}