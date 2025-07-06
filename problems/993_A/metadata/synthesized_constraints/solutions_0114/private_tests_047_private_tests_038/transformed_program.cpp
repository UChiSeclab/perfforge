#include <bits/stdc++.h>
using namespace std;
const long double eps = 0.0000001;
const long long inf = 1e15;

struct point {
  long long x, y;
  point() {}
  point(long long a, long long b) {
    x = a;
    y = b;
  }
};

struct vec {
  point st, fin;
  vec() {}
  vec(point a, point b) {
    st = a;
    fin = b;
  }
};

long long norm(vec q, point a) {
  increment_norm_call_count(); // Increment norm call counter
  long long x1 = q.fin.x - q.st.x, x2 = a.x - q.st.x;
  long long y1 = q.fin.y - q.st.y, y2 = a.y - q.st.y;
  if (x1 * y2 - x2 * y1 < 0) return 1;
  if (x1 * y2 - x2 * y1 == 0) return 0;
  return -1;
}

// Function to check grid search invariant
void check_grid_search_invariant(int i_max, int j_max) {
    if (i_max > 200 && j_max > 200) {
        cerr << "Warning: Performance bottleneck condition triggered due to large grid search!" << endl;
        abort();
    }
}

// Function to check norm calls invariant
void check_norm_calls_invariant() {
    if (norm_call_count > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive norm function calls!" << endl;
        abort();
    }
}

// Function to check vector intersection invariant
void check_vector_intersection_invariant(int intersection_checks) {
    if (intersection_checks > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive vector intersection checks!" << endl;
        abort();
    }
}

signed main() {
  point A1, B1, C1, D1;
  point A2, B2, C2, D2;
  cin >> A1.x >> A1.y >> B1.x >> B1.y >> C1.x >> C1.y >> D1.x >> D1.y;
  cin >> A2.x >> A2.y >> B2.x >> B2.y >> C2.x >> C2.y >> D2.x >> D2.y;
  vec v11 = vec(A1, B1), v12 = vec(B1, C1), v13 = vec(C1, D1),
      v14 = vec(D1, A1);
  vec v21 = vec(A2, B2), v22 = vec(B2, C2), v23 = vec(C2, D2),
      v24 = vec(D2, A2);
  vector<vec> W1 = {v11, v12, v13, v14}, W2 = {v21, v22, v23, v24};

  // Check grid search invariant before loops
  check_grid_search_invariant(201, 201);

  for (long long i = -100; i < 101; ++i) {
    for (long long j = -100; j < 101; ++j) {
      point a = point(i, j);
      long long q1 = 0, q2 = 0;
      long long val1 = 0, val2 = 0;
      int intersection_checks = 0; // Counter for intersection checks

      for (auto u : W1) {
        long long b = norm(u, a);
        if (b == 0)
          q1++;
        else
          val1 += b;
        intersection_checks++; // Increment intersection check counter
      }

      for (auto u : W2) {
        long long b = norm(u, a);
        if (b == 0)
          q2++;
        else
          val2 += b;
        intersection_checks++; // Increment intersection check counter
      }

      // Check vector intersection invariant
      check_vector_intersection_invariant(intersection_checks);

      if (val1 < 0)
        val1 -= q1;
      else
        val1 += q1;
      if (val2 < 0)
        val2 -= q2;
      else
        val2 += q2;
      if (abs(val1) == 4 && abs(val2) == 4) {
        cout << "YES";
        return 0;
      }
    }
  }

  // Check norm calls invariant after loops
  check_norm_calls_invariant();

  cout << "NO";
  return 0;
}