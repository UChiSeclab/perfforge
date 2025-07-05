#include <bits/stdc++.h>
using namespace std;

int n, m, ans, temp;
set<int> st;

// Invariant checkers
void check_large_iterations_with_set(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large iterations with set operations" << endl;
        abort();
    }
}

void check_set_size_invariant(bool condition, int setSize) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large unique set size: " << setSize << endl;
        abort();
    }
}

void check_loop_set_interaction(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to loop and set interaction" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ans = n + m;

    // Check for potential bottlenecks before loops
    check_large_iterations_with_set(m > 100000);  // Check for large number of iterations
    temp = 2;
    
    while (n) {
        n -= (temp % 6 != 0);
        st.insert(temp);
        temp += 2;
    }
    
    temp = 3;
    while (m) {
        m -= (temp % 6 != 0);
        st.insert(temp);
        temp += 3;

        // Check for large set size during iterations
        check_set_size_invariant(st.size() > 1000000, st.size());
    }

    // Check loop and set interaction
    check_loop_set_interaction(st.size() > 1000000);

    for (auto i : st) {
        ans--;
        if (!ans) return cout << i << "\n", 0;
    }

    return 0;
}