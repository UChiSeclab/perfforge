#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_binary_search_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of binary search iterations!" << endl;
        abort();
    }
}

void check_dense_point_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - dense point distribution in sorted order!" << endl;
        abort();
    }
}

void check_large_number_of_combinations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of initial pair combinations!" << endl;
        abort();
    }
}

int main() {
    float n, ans = 0, x, y, a, b;
    int i, j, k, s, e, mid;
    cin >> n;
    vector<pair<long long, long long>> v;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    // Insert checkers before entering the nested loops
    check_large_number_of_combinations(n > 1000); // Example threshold for large combinations

    for (i = 0; i < (n - 2); i++) {
        for (j = i + 2; j < n; j++) {

            // Check for dense distribution based on sorted structure
            check_dense_point_distribution(j - i > 1500); // Example threshold for dense distribution

            a = (v[i].first + v[j].first) / 2.0;
            b = (v[i].second + v[j].second) / 2.0;
            s = i + 1;
            e = j - 1;

            int binary_search_count = 0; // Initialize counter for binary search iterations

            while (s <= e) {
                mid = (s + e) / 2;
                binary_search_count++; // Increment binary search iteration counter

                if (v[mid].first == a && v[mid].second == b) {
                    ans++;
                    break;
                } else if (v[mid].first > a)
                    e = mid - 1;
                else if (v[mid].first < a)
                    s = mid + 1;
                else if (v[mid].first == a) {
                    if (v[mid].second > b)
                        e = mid - 1;
                    else if (v[mid].second < b)
                        s = mid + 1;
                }
            }

            // Check for excessive binary search iterations
            check_binary_search_iterations(binary_search_count > 10); // Example threshold for binary search count
        }
    }
    cout << ans << endl;
    return 0;
}