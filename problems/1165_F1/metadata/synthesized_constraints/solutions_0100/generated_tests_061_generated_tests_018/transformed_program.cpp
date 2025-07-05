#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int MAXN = 5e5 + 100; // Large constant for array size
int N, M;
int A[MAXN];
vector<pair<int, int>> vect;
int last[MAXN];
int sum = 0;

// Checker functions for performance invariants
void check_repeated_initialization(int maxN, int threshold) {
    if (maxN > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated initialization of large arrays!" << endl;
        abort();
    }
}

void check_nested_loops(int mid, int maxIterations) {
    if (mid > maxIterations) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in nested loops!" << endl;
        abort();
    }
}

void check_frequent_function_calls(int functionCallCount, int threshold) {
    if (functionCallCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent function calls in loop!" << endl;
        abort();
    }
}

bool f(int mid) {
    check_repeated_initialization(MAXN, 1000); // Assuming repetitive large initialization as a bottleneck
    
    for (int i = 0; i < MAXN; i++) last[i] = -1;
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i].first > mid) continue;
        last[vect[i].second] = vect[i].first;
    }
    int arr[MAXN];
    for (int i = 0; i < MAXN; i++) arr[i] = 0;
    for (int i = 1; i <= N; i++) {
        if (last[i] != -1) arr[last[i]] += A[i];
    }
    int cont = 0;
    
    check_nested_loops(mid, 100); // Assuming excessive iterations as a bottleneck

    for (int i = 1; i <= mid; i++) {
        cont++;
        while (cont && arr[i]) cont--, arr[i]--;
    }
    int gasto = mid - cont;
    int falta = sum - gasto;
    if (falta * 2 <= cont) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 1; i <= M; i++) {
        int d, t;
        cin >> d >> t;
        vect.push_back({d, t});
    }
    sort(vect.begin(), vect.end());

    int functionCallCount = 0;
    for (int i = 1; i < MAXN; i++) {
        functionCallCount++;
        if (f(i)) {
            cout << i << '\n';
            return 0;
        }
    }
    
    check_frequent_function_calls(functionCallCount, 5000); // Assuming too many function calls as a bottleneck
    
    return 0;
}