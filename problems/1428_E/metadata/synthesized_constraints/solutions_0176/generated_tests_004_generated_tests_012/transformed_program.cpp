#include <bits/stdc++.h>
using namespace std;

void mycode();
const long long int infLL = (1LL << 62);
const long long int mod = 998244353;
long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }

long long int f(long long int v, long long int a) {
    if (v % a == 0)
        return (v / a) * v;
    else
        return (v % a) * ceil(v, a) * ceil(v, a) + (a - v % a) * (v / a) * (v / a);
}

// Invariant checkers
void check_high_multiset_operations(int n, int k) {
    if (k > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - high multiset operations!" << endl;
        abort();
    }
}

void check_frequent_function_calls(int callCount) {
    if (callCount > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent calls to 'f' function!" << endl;
        abort();
    }
}

void check_heavy_comparator_usage(int comparatorInvocations) {
    if (comparatorInvocations > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - heavy comparator usage!" << endl;
        abort();
    }
}

bool cmp2(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    long long int p1 = f(a.second, a.first), p2 = f(b.second, b.first);
    for (int i = 1; i < 5; i++)
        return (p1 - f(a.second, a.first + i)) < (p2 - f(b.second, b.first + i));
    return 0;
}

void mycode() {
    long long int n, k, x;
    cin >> n >> k;

    // Checking high multiset operations before entering the loop
    check_high_multiset_operations(n, k);

    auto cmp = [](pair<long long int, long long int> left, pair<long long int, long long int> right) {
        return cmp2(right, left);
    };

    multiset<pair<long long int, long long int>, decltype(cmp)> q(cmp);
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.insert({1, x});
    }

    unsigned long long int ans = 0, aa, bb, cc, a, b;
    int functionCallCount = 0;
    int comparatorInvocationCount = 0;

    while (k != n) {
        n++;
        bb = (*q.begin()).first;
        cc = (*q.begin()).second;
        q.erase(q.begin());
        q.insert({bb + 1, cc});
    }

    while (!q.empty()) {
        bb = (*q.begin()).first;
        cc = (*q.begin()).second;
        ans += f(cc, bb);
        q.erase(q.begin());
        
        // Increment function call count
        functionCallCount++;
    }
    
    // Check for frequently called function
    check_frequent_function_calls(functionCallCount);

    // Check comparator usage
    comparatorInvocationCount = std::distance(q.begin(), q.end()); // Simplified demonstration of comparison checking
    check_heavy_comparator_usage(comparatorInvocationCount);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mycode();
    return 0;
}