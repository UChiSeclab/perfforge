#include <bits/stdc++.h>
using namespace std;

// Function to check if the range of divisors is large
void check_divisor_count_invariant(int p, int y) {
    if (sqrt(y) > p) {
        cerr << "Warning: Divisor count invariant triggered - large number of divisors to check!" << endl;
        abort();
    }
}

// Function to check if the map grows excessively
void check_occupation_map_invariant(const map<int, int>& a) {
    if (a.size() > 10000) {  // Arbitrary threshold for excessive map size
        cerr << "Warning: Occupation map invariant triggered - map is too large!" << endl;
        abort();
    }
}

// Function to check if the vector grows too large
void check_search_space_invariant(const vector<int>& ans) {
    if (ans.size() > 10000) {  // Arbitrary threshold for vector size
        cerr << "Warning: Search space invariant triggered - search space too large!" << endl;
        abort();
    }
}

int main() {
    int p, y;
    cin >> p >> y;
    
    // Check if the divisor range invariant is triggered
    check_divisor_count_invariant(p, y);
    
    map<int, int> a;
    for (int i = 2; i <= min((int)sqrt(y) + 1, p); i++) {
        if (y % i == 0 && i == 2) {
            a[i] = 1;
            a[y - (y % i)] = 1;
        } else if (i % 2 != 0) {
            a[i] = 1;
            a[y - (y % i)] = 1;
        }
    }
    
    // Check if the occupation map invariant is triggered
    check_occupation_map_invariant(a);
    
    vector<int> ans;
    for (auto it = a.begin(); it != a.end(); it++) {
        ans.push_back(it->first);
    }
    
    // Check if the search space invariant is triggered
    check_search_space_invariant(ans);
    
    if (ans.empty() || ans[max((int)((ans).size()) - 1, 0)] != y) {
        cout << y;
        return 0;
    }
    for (int i = (int)((ans).size()) - 1; i > 0; i--) {
        if (ans[i] - 1 > p) {
            for (int j = ans[i] - 1; j > ans[i - 1]; j--) {
                int flag = 1;
                for (int k = 2; k <= min((int)sqrt(j), p); k++) {
                    if (j % k == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    cout << j;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
}