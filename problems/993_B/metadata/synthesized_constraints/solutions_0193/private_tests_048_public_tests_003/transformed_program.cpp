#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

void check_large_pairs(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of pairs!" << endl;
        abort();
    }
}

void check_common_elements(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - many common elements!" << endl;
        abort();
    }
}

void check_ambiguity_resolution(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - resolving ambiguity!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<pair<int, int>> z[2];
    int roz[2];
    for (int i = 0; i < 2; i++) cin >> roz[i];
    
    // Check invariant for large pairs
    check_large_pairs(roz[0] > 10 && roz[1] > 10); // Check if both sets have a large number of pairs

    for (int i = 0; i < 2; i++) {
        while (roz[i]--) {
            int a, b;
            cin >> a >> b;
            z[i].insert(make_pair(a, b));
            z[i].insert(make_pair(b, a));
        }
    }
    set<int> dobre;
    bool zle = false;
    for (int h = 0; h < 2; h++) {
        for (auto& it : z[h]) {
            vector<int> jed = {it.first, it.second};
            set<int> jdob;
            for (auto& it2 : z[h ^ 1]) {
                vector<int> dwa = {it2.first, it2.second};
                set<int> to_samo;
                for (int j : jed)
                    for (int d : dwa)
                        if (j == d) to_samo.insert(d);
                
                // Check for excessive common elements
                check_common_elements(to_samo.size() > 5); // Check if many common elements are found

                if ((int)to_samo.size() == 1) {
                    const int x = *to_samo.begin();
                    dobre.insert(x);
                    jdob.insert(x);
                }
            }
            // Check ambiguity resolution
            check_ambiguity_resolution(jdob.size() > 3); // Check if resolving ambiguity becomes extensive

            if ((int)jdob.size() > 1) {
                zle = true;
            }
        }
    }
    if ((int)dobre.size() == 1)
        cout << *dobre.begin() << endl;
    else if (zle)
        cout << -1 << endl;
    else
        cout << 0 << endl;
    return 0;
}