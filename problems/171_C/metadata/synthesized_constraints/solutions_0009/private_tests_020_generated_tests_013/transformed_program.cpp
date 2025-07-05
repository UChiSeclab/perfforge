#include <bits/stdc++.h>
using namespace std;

// Checker for high input value for carrots
void check_carrots_invariant(int carrots) {
    if (carrots > 95) { // Arbitrary chosen threshold close to 100
        cerr << "Warning: Performance bottleneck condition triggered - high carrot value!" << endl;
        abort();
    }
}

// Checker for accumulated cost of stack operations
void check_stack_operations_invariant(int carrots) {
    if (carrots > 95) { // Same threshold as above, since they are related
        cerr << "Warning: Performance bottleneck condition triggered - excessive stack operations!" << endl;
        abort();
    }
}

int main() {
    stack<int> st;
    st.push(0);
    int carrots;
    cin >> carrots;

    // Check for performance bottlenecks before entering the loop
    check_carrots_invariant(carrots);
    check_stack_operations_invariant(carrots);

    int spread;
    int flour = 1;
    int egg = 1;
    while (carrots) {
        cin >> spread;
        st.push(spread);
        int t = st.top();
        st.pop();
        t *= flour;
        st.push(t);
        spread = st.top();
        st.pop();
        t = st.top();
        st.pop();
        t += spread;
        st.push(t);
        st.push(flour);
        t = st.top();
        ++t;
        st.pop();
        st.push(t);
        flour = st.top();
        st.pop();
        --carrots;
    }
    cout << st.top();
    return 0;
}