#include <bits/stdc++.h>
using namespace std;

template <class T>
constexpr T lcm(T m, T n) {
    return m / __gcd(m, n) * n;
}

const long long int mod = 1e9 + 7;

long long int power(long long int n, long long int p, long long int m) {
    long long int ret = 1;
    while (p > 0) {
        if (p & 1) (ret *= n) %= m;
        (n *= n) %= m;
        p /= 2;
    }
    return ret;
}

long long int mod_inv(long long int n, long long int p) {
    return power(n, p - 2, p);
}

vector<long long int> prime_factorize_unique(long long int n) {
    vector<long long int> res;
    for (long long int i = 2LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

template <typename T>
class Matrix {
private:
    int _row, _col;
    vector<vector<T>> _mat;

public:
    Matrix() : _row(0), _col(0), _mat() {}
    Matrix(int _row, int _col)
        : _row(_row), _col(_col), _mat(_row, vector<T>(_col)) {}
    Matrix(int _row, int _col, const T &val)
        : _row(_row), _col(_col), _mat(_row, vector<T>(_col, val)) {}
    Matrix(const vector<vector<T>> &m)
        : _row(m.size()), _col(m[0].size()), _mat(m) {}
    int row() const { return _row; }
    int col() const { return _col; }
    const vector<T> &operator[](size_t i) const { return _mat[i]; }
    vector<T> &unsafe_row(size_t i) { return _mat[i]; }
    T &at(size_t r, size_t c) { return _mat[r][c]; }
    Matrix operator*(const Matrix &a) const {
        Matrix<T> ret(_row, a.col());
        for (long long int i = 0; i < _row; ++i)
            for (long long int j = 0; j < a.col(); ++j)
                for (long long int k = 0; k < _col; ++k)
                    ret.at(i, j) += _mat[i][k] * a[k][j];
        return ret;
    }
};

template <typename T>
Matrix<T> unit(int size) {
    Matrix<T> ret(size, size);
    for (long long int i = 0; i < size; ++i) ret.at(i, i) = 1;
    return ret;
}

template <typename T>
Matrix<T> power(const Matrix<T> &a, long long int k) {
    Matrix<T> ret;
    if (k <= 0) return unit<T>(a.row());
    if (k == 1) return a;
    Matrix<T> temp = power(a, k / 2);
    ret = temp * temp;
    if (k % 2) ret = ret * a;
    return ret;
}

template <uint32_t M>
class mod_int_64 {
public:
    uint64_t val;
    mod_int_64() : val(0) {}
    mod_int_64(int64_t n) : val(n % M) {}
    const mod_int_64 operator*(const mod_int_64 &a) const {
        return mod_int_64((val * a.val) % M);
    }
    const mod_int_64 &operator+=(const mod_int_64 &a) {
        (val += a.val) %= M;
        return *this;
    }
};

const long long int M = mod - 1;
using mint = mod_int_64<M>;

long long int count_prime(long long int n, int p) {
    long long int ret = 0;
    while (n % p == 0) {
        n /= p;
        ++ret;
    }
    return ret;
}

// Checker functions
void check_prime_factorization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Prime factorization invariant triggered - complex factorization" << endl;
        abort();
    }
}

void check_exponentiation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Exponentiation invariant triggered - large exponents involved" << endl;
        abort();
    }
}

void check_matrix_multiplication_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Matrix multiplication invariant triggered - heavy operations" << endl;
        abort();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long int n, f1, f2, f3, c;
    while (cin >> n >> f1 >> f2 >> f3 >> c) {
        vector<int> ps;
        auto pc = prime_factorize_unique(c);
        auto p1 = prime_factorize_unique(f1);
        auto p2 = prime_factorize_unique(f2);
        auto p3 = prime_factorize_unique(f3);

        // Check for complex prime factorization
        check_prime_factorization_invariant(pc.size() + p1.size() + p2.size() + p3.size() > 100);

        for (auto x : pc) ps.push_back(x);
        for (auto x : p1) ps.push_back(x);
        for (auto x : p2) ps.push_back(x);
        for (auto x : p3) ps.push_back(x);

        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());

        ((void)0);
        long long int ans = 1;
        Matrix<mint> m({{1, 1, 1}, {1, 0, 0}, {0, 1, 0}});

        // Check for heavy matrix operations
        check_matrix_multiplication_invariant(n > 1e6);

        auto mm = power(m, n - 3);

        for (auto p : ps) {
            long long int x = count_prime(c, p) * 3 % M + count_prime(f3, p) % M;
            long long int y = count_prime(c, p) * 2 % M + count_prime(f2, p) % M;
            long long int z = count_prime(c, p) * 1 % M + count_prime(f1, p) % M;
            (x *= mm[0][0].val) %= M;
            (y *= mm[0][1].val) %= M;
            (z *= mm[0][2].val) %= M;
            (ans *= power(p, (x + y + z) % M, mod)) %= mod;
        }

        // Check for large exponents in exponentiation
        check_exponentiation_invariant(n > 1e6);

        (ans *= mod_inv(power(c, n, mod), mod)) %= mod;
        cout << ans << endl;
    }
    return 0;
}