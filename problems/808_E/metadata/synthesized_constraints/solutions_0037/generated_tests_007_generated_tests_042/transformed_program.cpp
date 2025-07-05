#include <bits/stdc++.h>
using namespace std;

class input {
 private:
  bool fail;
  istream* stream;

 public:
  input(istream& stream_ = cin) { stream = &stream_; }
  istream& getStream() { return *stream; }
  template <typename T = int>
  T read() {
    T value;
    if (*stream >> value) {
      fail = false;
    } else {
      fail = true;
    }
    return value;
  }
  template <typename T = int>
  vector<T> readArray() {
    size_t size = read<size_t>();
    return readArray<T>(size);
  }
  template <typename T = int>
  vector<T> readArray(size_t size) {
    vector<T> v(size);
    for (size_t i = 0; i < size; i++) {
      if (*stream >> v[i]) {
        fail = false;
      } else {
        fail = true;
      }
    }
    return v;
  }
  bool isFailed() { return fail; }
  static input& getStdin() {
    static input in(cin);
    return in;
  }
};

class output {
 private:
  ostream* stream;

 public:
  output(ostream& stream_ = cout) { stream = &stream_; }
  ostream& getStream() { return *stream; }
  template <typename T>
  output& put(T& value) {
    *stream << value;
    return *this;
  }
  template <typename T>
  output& put(T& value, int precision) {
    *stream << setprecision(precision) << value;
    return *this;
  }
  template <typename T>
  output& write(const T& value) {
    *stream << value << endl;
    return *this;
  }
  template <typename T>
  output& write(T& value, int precision) {
    *stream << setprecision(precision) << fixed << value << endl;
    return *this;
  }
  template <typename T>
  output& writeArray(const vector<T>& v, bool appendSize = true) {
    if (appendSize) {
      write(v.size());
    }
    for (auto& x : v) {
      *stream << x << " ";
    }
    *stream << endl;
    return *this;
  }
  output& writeLine() {
    *stream << endl;
    return *this;
  }
  output& getStdout() {
    output out(cout);
    return out;
  }
  output getStderr() {
    output err(cerr);
    return err;
  }
};

input in(cin);
output out(cout);
output err(cerr);

// Checker functions to detect performance bottlenecks
void check_combination_invariant(int t1, int t2, int t3) {
    int range = 3; // We iterate from t1-3 to t1+3, similarly for t2 and t3
    int combination_limit = 1000; // arbitrary threshold to detect too many combinations
    if ((2 * range + 1) * (2 * range + 1) * (2 * range + 1) > combination_limit) {
        cerr << "Warning: combination_invariant triggered - too many combinations being explored!" << endl;
        abort();
    }
}

void check_loop_intensity_invariant(int t1, int t2, int t3) {
    int deviation_threshold = 5; // threshold for deviation from initial topCnt values
    if (abs(t1) > deviation_threshold || abs(t2) > deviation_threshold || abs(t3) > deviation_threshold) {
        cerr << "Warning: loop_intensity_invariant triggered - excessive deviation in loops!" << endl;
        abort();
    }
}

void check_weight_utilization_invariant(int current_weight, int max_weight) {
    if (current_weight > 0.9 * max_weight) { // arbitrary threshold of 90% capacity
        cerr << "Warning: weight_utilization_invariant triggered - weight limit near capacity!" << endl;
        abort();
    }
}

void solve() {
  auto n = in.read();
  auto m = in.read();
  vector<pair<long long, long long>> items;
  for (auto i = 0; i < n; i++) {
    auto w = in.read<long long>();
    auto c = in.read<long long>();
    items.push_back(make_pair((c * 6) / w, w));
  }
  sort(items.begin(), items.end());
  reverse(items.begin(), items.end());
  vector<int> topCnt(3);
  vector<int> allCnt(3);
  int ws = 0;
  for (auto p : items) {
    if (p.second <= m - ws) {
      topCnt[p.second - 1]++;
      ws += p.second;
    }
    allCnt[p.second - 1]++;
  }
  auto t1 = topCnt[0];
  auto t2 = topCnt[1];
  auto t3 = topCnt[2];
  
  // Check combination invariant before entering nested loops
  check_combination_invariant(t1, t2, t3);

  auto tt = 3;
  long long ans = 0;
  vector<int> rtmp(3);

  for (auto i1 = t1 - 3; i1 <= t1 + 3; i1++) {
    for (auto i2 = t2 - 3; i2 <= t2 + 3; i2++) {
      for (auto i3 = t3 - 3; i3 <= t3 + 3; i3++) {
        rtmp[0] = i1;
        rtmp[1] = i2;
        rtmp[2] = i3;

        // Check loop intensity invariant
        check_loop_intensity_invariant(i1, i2, i3);

        auto w = m;
        long long nans = 0;
        for (auto& x : items) {
          if (rtmp[x.second - 1] > 0 && x.second <= w) {
            rtmp[x.second - 1]--;
            w -= x.second;
            nans += (x.first * x.second) / 6;

            // Check weight utilization invariant
            check_weight_utilization_invariant(w, m);
          }
        }
        if (nans > ans) ans = nans;
      }
    }
  }
  out.write(ans);
}

int main() {
  while (true) {
    auto startT = clock();
    solve();
    auto endT = clock();
    cerr << endl;
    cerr << "Working time: " << (endT - startT) << " ms" << endl;
    cerr << "-------------------------" << endl;
    bool ok = false;
    while (!in.isFailed() && !ok) {
      ok = in.read<char>() == '$';
    }
    if (!ok) {
      break;
    }
  }
}