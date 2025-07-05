#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::set;
using std::vector;

// Checker functions
void check_maxx_invariant(int maxx) {
    if (maxx >= 100000) {
        cerr << "Warning: Performance bottleneck triggered - maxx value is very high!" << endl;
        abort();
    }
}

void check_divisor_count_invariant(int divisorCount) {
    if (divisorCount > 1000) {
        cerr << "Warning: Performance bottleneck triggered - large number of divisors!" << endl;
        abort();
    }
}

void check_prime_factorization_invariant(int primeFactorizationCount) {
    if (primeFactorizationCount > 1000000) {
        cerr << "Warning: Performance bottleneck triggered - excessive prime factorization computations!" << endl;
        abort();
    }
}

void check_occur_usage_invariant(int occurWrites) {
    if (occurWrites > 100000) {
        cerr << "Warning: Performance bottleneck triggered - excessive writes to occur array!" << endl;
        abort();
    }
}

int maxx;
int n;
const int MAXN = 100004;
bool P[MAXN];
vector<int> primes;
set<int> A[MAXN];
struct Node {
    int x, y;
};
vector<Node> xys;
int occur[MAXN];

void init_P() {
    for (int i = 0; i < maxx; i++) {
        P[i] = true;
    }
    P[0] = P[1] = false;
    int i1 = sqrt(maxx) + 1;
    for (int i = 2; i < i1; i++) {
        if (P[i]) {
            int j = i * i;
            while (j < maxx) {
                P[j] = false;
                j += i;
            }
        }
    }
    for (int i = 2; i < maxx; i++)
        if (P[i]) {
            primes.push_back(i);
        }
}

void init_A() {
    for (int i = 2; i < maxx; i++) {
        if (P[i]) {
            A[i].insert(1);
            A[i].insert(i);
        } else {
            int mi = 0;
            while (i % primes[mi] != 0) mi++;
            int m = primes[mi];
            int j = i / m;
            A[i] = A[j];
            for (set<int>::iterator it = A[j].begin(); it != A[j].end(); it++)
                A[i].insert(m * (*it));
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > maxx) maxx = x;
        xys.push_back(Node());
        xys.back().x = x;
        xys.back().y = y;
    }
    maxx += 1;

    // Check for high maxx values
    check_maxx_invariant(maxx);

    init_P();
    init_A();
    for (int i = 0; i < maxx; i++) {
        occur[i] = -1;
    }

    int occurWrites = 0; // To track occur array writes
    for (int i = 0; i < n; i++) {
        int x, y;
        x = xys[i].x;
        y = xys[i].y;
        int dds = 0;
        int divisorCount = 0; // Track number of divisors processed
        for (set<int>::iterator it = A[x].begin(); it != A[x].end(); it++) {
            int p = *it;
            if (occur[p] < i - y) dds++;
            occur[p] = i;
            occurWrites++;
            divisorCount++;
        }

        // Check for large number of divisors
        check_divisor_count_invariant(divisorCount);

        cout << dds << '\n';
    }

    // Check for excessive writes to occur array
    check_occur_usage_invariant(occurWrites);

    return 0;
}