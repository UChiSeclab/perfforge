#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

class matrix {
public:
    int row, col;
    std::vector<std::vector<int>> num;
    matrix(int row, int col, int defaultValue = 0) {
        this->num = std::vector<std::vector<int>>(row, std::vector<int>(col, defaultValue));
        this->row = row;
        this->col = col;
    }
    matrix(std::vector<std::vector<int>> num) {
        this->num = num;
        this->row = this->num.size();
        this->col = this->num[0].size();
    }
    matrix operator*(matrix &another) {
        if (this->col != another.row) {
            printf("Wrong size: %d*%d X %d*%d\n", this->row, this->col, another.row, another.col);
            throw "Wrong size";
        }
        matrix newone(this->row, another.col);
        for (int r = 0; r < newone.row; r++) {
            for (int c = 0; c < newone.col; c++) {
                for (int k = 0; k < this->col; k++) {
                    newone.num[r][c] += 1ll * this->num[r][k] * another.num[k][c] % (mod - 1);
                    newone.num[r][c] %= mod - 1;
                }
            }
        }
        return newone;
    }
    matrix operator^(long long x) {
        if (x == 0) {
            printf("Not implemented yet.\n");
            throw "Not implemented";
        } else if (x == 1) {
            return *this;
        } else {
            matrix halfpower = (*this) ^ (x / 2);
            if (x % 2 == 0)
                return halfpower * halfpower;
            else
                return halfpower * halfpower * (*this);
        }
    }
};

std::vector<int> primeDecomposition(int x) {
    std::vector<int> answer;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            answer.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) answer.push_back(x);
    return answer;
}

int power(int a, long long b) {
    if (b == 0) return 1;
    int half = power(a, b / 2);
    if (b % 2 == 0)
        return 1ll * half * half % mod;
    else
        return 1ll * half * half % mod * a % mod;
}

// Inserted checkers for performance invariants

void check_matrix_exponentiation_invariant(long long n) {
    if (n > 1e17) {
        cerr << "Warning: Potential slowdown due to large matrix exponentiation." << endl;
        abort();
    }
}

void check_prime_decomposition_invariant(int c, int f1, int f2, int f3) {
    int factors[] = {c, f1, f2, f3};
    for (int factor : factors) {
        int count = 0;
        for (int i = 2; i <= 1000 && factor > 1; ++i) {
            while (factor % i == 0) {
                factor /= i;
                count++;
            }
        }
        if (count > 10) {
            cerr << "Warning: Potential slowdown due to many small prime factors." << endl;
            abort();
        }
    }
}

void check_combined_complexity_invariant(long long n, int c, int f1, int f2, int f3) {
    if (n > 1e17 && (c % 2 == 0 || f1 % 3 == 0 || f2 % 5 == 0 || f3 % 7 == 0)) {
        cerr << "Warning: Combined complexity conditions triggered slowdown." << endl;
        abort();
    }
}

int main() {
    long long n;
    int f[4], c, answer(1);
    scanf("%lld%d%d%d%d", &n, &f[1], &f[2], &f[3], &c);

    // Perform checks based on the performance-characterizing invariants
    check_matrix_exponentiation_invariant(n);
    check_prime_decomposition_invariant(c, f[1], f[2], f[3]);
    check_combined_complexity_invariant(n, c, f[1], f[2], f[3]);

    matrix baseMatrix({{1, 1, 1}, {1, 0, 0}, {0, 1, 0}});
    baseMatrix = baseMatrix ^ (n - 3);

    std::set<int> primeSet;
    for (int t : primeDecomposition(c)) primeSet.insert(t);
    for (int i = 1; i <= 3; i++)
        for (int t : primeDecomposition(f[i])) primeSet.insert(t);
    for (int t : primeSet) {
        matrix countMatrix(3, 1);
        for (int i = 0; i < 3; i++) {
            for (int k = f[i + 1]; k % t == 0; k /= t)
                countMatrix.num[3 - i - 1][0]++;
            for (int k = c; k % t == 0; k /= t)
                countMatrix.num[3 - i - 1][0] += i + 1;
        }
        countMatrix = baseMatrix * countMatrix;
        answer = 1ll * answer * power(t, countMatrix.num[0][0]) % mod;
    }
    answer = 1ll * answer * power(power(c, mod - 2), n) % mod;
    printf("%d\n", answer);
    return 0;
}