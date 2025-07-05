#include <bits/stdc++.h>
using namespace std;
using uint32 = uint32_t;

// Checker functions
void check_large_input_invariant(int n, int m) {
    if (n > 50000 || m > 50000) {
        cerr << "Warning: Large input size invariant triggered - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_dense_extremes_invariant(const vector<int>& a, const vector<int>& b) {
    int extreme_count = 0;
    for (int x : a) {
        if (x == 0 || x == 1000000) ++extreme_count;
    }
    for (int y : b) {
        if (y == 0 || y == 1000000) ++extreme_count;
    }
    if (extreme_count > 10000) {
        cerr << "Warning: Dense segments at extremes invariant triggered - increased complexity!" << endl;
        abort();
    }
}

void check_long_segment_invariant(const vector<int>& a_segments, const vector<int>& b_segments) {
    int long_segments = 0;
    for (int r : a_segments) {
        if (r > 800000) ++long_segments;
    }
    for (int l : b_segments) {
        if (l < 200000) ++long_segments;
    }
    if (long_segments > 5000) {
        cerr << "Warning: Long segments invariant triggered - potential performance issue!" << endl;
        abort();
    }
}

template <typename T, class bit_array>
struct wavelet_matrix {
  using uT = typename make_unsigned<T>::type;
  wavelet_matrix() = default;
  wavelet_matrix(const vector<T> &data, uint32 m_level = 0) {
    n = data.size();
    max_value = (n == 0 ? 0UL : *max_element(data.begin(), data.end()));
    if (m_level == 0) do {
        ++m_level;
      } while ((static_cast<uT>(1) << m_level) <= max_value);
    max_level = m_level;
    bit_arrays.assign(max_level, bit_array(n));
    zero_cnt.assign(max_level, 0UL);
    vector<T> level = data, next_level = level;
    for (uint32 lvl = 0; lvl < max_level; ++lvl) {
      uT mask = static_cast<uT>(1) << (max_level - lvl - 1);
      uint32 &zeros = zero_cnt[lvl] = 0;
      for (uint32 i = 0; i < n; ++i) zeros += (level[i] & mask) == 0;
      bit_array &ba = bit_arrays[lvl];
      uint32 zero_pos = 0, one_pos = zeros;
      for (uint32 i = 0; i < n; ++i)
        if (level[i] & mask)
          ba.set_bit(i), next_level[one_pos++] = level[i];
        else
          next_level[zero_pos++] = level[i];
      ba.build();
      level.swap(next_level);
    }
  }
  T operator[](uint32 pos) const {
    T value = 0;
    for (uint32 lvl = 0; lvl < max_level; ++lvl) {
      const bit_array &ba = bit_arrays[lvl];
      const bool one = ba.get_bit(pos);
      value = value << 1 | one;
      pos = ba.rank(pos, one);
      if (one) pos += zero_cnt[lvl];
    }
    return value;
  }
  tuple<int, int, int> rank_all(T c, uint32 begin_pos, uint32 end_pos) const {
    if (c > max_value) return make_tuple(end_pos - begin_pos, 0UL, 0UL);
    uint32 more_and_less[2] = {0};
    for (uint32 lvl = 0; lvl < max_level; ++lvl) {
      const bit_array &ba = bit_arrays[lvl];
      const bool one = (c >> (max_level - lvl - 1)) & 1;
      more_and_less[one] += end_pos - begin_pos;
      begin_pos = ba.rank(begin_pos, one);
      end_pos = ba.rank(end_pos, one);
      if (one) begin_pos += zero_cnt[lvl], end_pos += zero_cnt[lvl];
      more_and_less[one] -= end_pos - begin_pos;
    }
    return make_tuple(more_and_less[1], end_pos - begin_pos, more_and_less[0]);
  }
  T quantile(uint32 begin_pos, uint32 end_pos, uint32 k) const {
    T value = 0;
    for (uint32 lvl = 0; lvl < max_level; ++lvl) {
      const bit_array &ba = bit_arrays[lvl];
      const uint32 zeros = ba.rank(end_pos, 0) - ba.rank(begin_pos, 0);
      const bool one = k >= zeros;
      value = value << 1 | one;
      begin_pos = ba.rank(begin_pos, one);
      end_pos = ba.rank(end_pos, one);
      if (one) begin_pos += zero_cnt[lvl], end_pos += zero_cnt[lvl], k -= zeros;
    }
    return value;
  }

 private:
  uint32 n;
  uint32 max_level;
  uint32 max_value;
  vector<bit_array> bit_arrays;
  vector<uint32> zero_cnt;
};

struct bit_array {
  bit_array() = default;
  bit_array(uint32 n, bool one = false) {
    blocks.assign((n + 31) / 32, one ? 0xffffffffUL : 0);
    rank_table.assign(blocks.size(), 0UL);
  }
  void build() {
    uint32 sum = 0;
    for (size_t i = 0; i < rank_table.size(); ++i)
      rank_table[i] = (sum += bit_count(blocks[i]));
  }
  uint32 rank(uint32 pos, bool one = true) const {
    uint32 block = pos >> 5;
    uint32 bit = pos & 31;
    uint32 sum = (block >= 1 ? rank_table[block - 1] : 0) +
                 bit_count(blocks[block] & ((1UL << bit) - 1));
    return one ? sum : pos - sum;
  }
  void set_bit(uint32 pos, bool one = true) {
    uint32 block = pos >> 5;
    uint32 bit = pos & 31;
    if (one)
      blocks[block] |= 1UL << bit;
    else
      blocks[block] &= ~(1ULL << bit);
  }
  bool get_bit(uint32 pos) const { return blocks[pos >> 5] >> (pos & 31) & 1; }

 private:
  static inline uint32 bit_count(uint32 x) {
    x -= (x >> 1) & 0x55555555UL;
    x = ((x >> 2) & 0x33333333UL) + (x & 0x33333333UL);
    x = ((x >> 4) + x) & 0x0f0f0f0fUL;
    x *= 0x01010101UL;
    return x >> 24;
  }
  vector<uint32> blocks;
  vector<uint32> rank_table;
};

struct bit_array_vec : vector<int> {
  bit_array_vec() = default;
  bit_array_vec(uint32 n, bool one = false) : vector<int>(n, one) {}
  void build() { partial_sum(this->begin(), this->end(), this->begin()); }
  inline uint32 rank(uint32 pos, bool one = true) const {
    uint32 sum = (pos >= 1 ? (*this)[pos - 1] : 0);
    return one ? sum : pos - sum;
  }
  inline void set_bit(uint32 pos, bool one = true) { (*this)[pos] = one; }
  inline bool get_bit(uint32 pos) const {
    return (*this)[pos] - (pos ? (*this)[pos - 1] : 0);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  // Check for large input size invariant
  check_large_input_invariant(n, m);

  const int N = 1e6;
  long long ans = 1;
  vector<int> a(N + 1, 0), b(N + 1, N + 1);
  for (int y, l, r, i = 0; i < n; ++i) {
    cin >> y >> l >> r;
    ans += l == 0 && r == N;
    if (l == 0) a[y] = r;
    if (r == N && l != 0) b[y] = l;
  }

  // Check for dense segments at extremes
  check_dense_extremes_invariant(a, b);

  wavelet_matrix<int, bit_array> wa(a), wb(b);
  for (int x, l, r, i = 0; i < m; ++i) {
    cin >> x >> l >> r;
    ans += l == 0 && r == N;
    if (l == 0) {
      ans += get<2>(wa.rank_all(x - 1, 0, r + 1));
      ans += get<0>(wb.rank_all(x + 1, 0, r + 1));
    }
    if (r == N && l != 0) {
      ans += get<2>(wa.rank_all(x - 1, l, N + 1));
      ans += get<0>(wb.rank_all(x + 1, l, N + 1));
    }
  }

  // Check for long segment invariant
  check_long_segment_invariant(a, b);

  cout << ans << "\n";
  return 0;
}