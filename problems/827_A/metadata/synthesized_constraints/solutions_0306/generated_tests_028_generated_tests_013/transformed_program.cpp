#include <bits/stdc++.h>
using namespace std;

// Check for large gaps between consecutive starting positions
void check_repeated_output_invariant(int currentPos, int nextPos) {
    if (nextPos - currentPos > 1000) { // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - large gap between positions leading to repeated character output!" << endl;
        abort();
    }
}

// Check for excessive string insertions
void check_string_insertion_invariant(int insertions, int length) {
    if (insertions * length > 5000) { // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - excessive string insertions due to overlapping or contiguous segments!" << endl;
        abort();
    }
}

int main() {
    int n, i, j, k, l, now, next, m, pos;
    scanf("%d", &n);
    string str[n + 5];
    vector<pair<int, int> > vec;
    for (i = 0; i < n; i++) {
        cin >> str[i];
        l = str[i].length();
        l--;
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &pos);
            pos--;
            vec.push_back({pos, i});
        }
    }
    now = 0;
    sort(vec.begin(), vec.end());
    m = vec.size();
    for (k = 0; k < m; k++) {
        next = vec[k].first;
        pos = vec[k].second;
        l = str[pos].length();
        
        // Place the check for large gaps before entering the loop
        check_repeated_output_invariant(now, next);
        
        if (now <= next) {
            for (i = now; i < next; i++) {
                printf("a");
                now++;
            }
            now = i;
            j = 0;
            for (i = next; i < next + l; i++) {
                cout << str[pos][j];
                j++;
            }
            now = i;
        } else {
            j = now - next;
            for (i = now; i < next + l; i++) {
                cout << str[pos][j];
                j++;
            }
            now = i;
        }
        
        // Check for excessive string insertions after handling string insertion
        check_string_insertion_invariant(j, l);
    }
    return 0;
}