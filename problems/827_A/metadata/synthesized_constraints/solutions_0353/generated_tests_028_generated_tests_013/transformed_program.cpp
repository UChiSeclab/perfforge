#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
char str[maxn];
char t[maxn];
int pos[maxn];

// Check for high frequency of substring overlaps
void check_overlap_invariant(int k, int len) {
    if (k * len > 100000) { // Assuming threshold based on constraints
        cerr << "Warning: High frequency of substring overlaps detected!" << endl;
        abort();
    }
}

// Check for large final string construction
void check_final_string_length(int d) {
    if (d > 1000000) { // Assuming threshold for large final string
        cerr << "Warning: Large final string construction detected!" << endl;
        abort();
    }
}

// Check for extensive nested loop iterations
void check_nested_loop_iterations(int k) {
    if (k > 1000) { // Assuming a threshold for extensive iterations
        cerr << "Warning: Extensive nested loop iterations detected!" << endl;
        abort();
    }
}

int main() {
    memset(str, 'a', sizeof(str));
    int n, k, m;
    int d = -1;
    cin >> n;
    while (n--) {
        cin >> t;
        cin >> k;
        int len = strlen(t);
        
        // Insert checker for substring overlaps
        check_overlap_invariant(k, len);
        
        for (int i = 1; i <= k; i++) cin >> pos[i];
        int cnt = 0, ctt = 0;

        // Insert checker for nested loop iterations
        check_nested_loop_iterations(k);
        
        for (int i = 1; i <= k; i++) {
            ctt = max(ctt, pos[i] + len - 1);
            int cnn = max(cnt + 1, pos[i]);
            for (int j = cnn; j < pos[i] + len; j++) {
                str[j] = t[j - pos[i]];
            }
            cnt = ctt;
        }
        d = max(d, ctt);
    }
    
    // Insert checker for final string length
    check_final_string_length(d);
    
    for (int i = 1; i <= d; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}