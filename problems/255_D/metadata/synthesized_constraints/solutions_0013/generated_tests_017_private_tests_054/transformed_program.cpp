#include <iostream>
using namespace std;

void check_boundary_closeness_invariant(int n, int x, int y) {
    if (n > 1000000 && (x <= 10 || x >= n - 10 || y <= 10 || y >= n - 10)) {
        cerr << "Warning: Boundary closeness invariant triggered - initial point is near boundary in a large grid!" << endl;
        abort();
    }
}

void check_expansion_direction_convergence_invariant(int n, int x, int y) {
    if (n > 1000000 && (x <= 10 && y >= n - 10)) {
        cerr << "Warning: Expansion direction convergence invariant triggered - inefficient expansion due to boundary proximity!" << endl;
        abort();
    }
}

void check_quadrant_overlap_inefficiency_invariant(int n, int x, int y) {
    if (n > 1000000 && x <= n / 2 && y <= n / 2) {
        cerr << "Warning: Quadrant overlap inefficiency invariant triggered - potential redundant coverage!" << endl;
        abort();
    }
}

int main(int argc, char const *argv[]) {
    int n, x, y, c;
    std::cin >> n >> x >> y >> c;
    ++n;

    // Inserted checkers to detect performance bottlenecks
    check_boundary_closeness_invariant(n, x, y);
    check_expansion_direction_convergence_invariant(n, x, y);
    check_quadrant_overlap_inefficiency_invariant(n, x, y);

    bool topLeft = true, topRight = true, bottomLeft = true, bottomRight = true;
    int counter = 1, timer = 0, arm = 1, up = 0, left = 0, down = 0, right = 0;
    int xiterator, yiterator;

    while (counter < c) {
        if (topLeft) {
            xiterator = x - up;
            yiterator = y + arm;
            if (yiterator >= n) {
                yiterator = n - 1;
                ++up;
                --xiterator;
            }
            while (xiterator > 0 && yiterator > y) {
                if (xiterator == 1 && yiterator == n - 1) topLeft = false;
                ++counter;
                --xiterator;
                --yiterator;
            }
        }
        if (bottomLeft) {
            xiterator = x - arm;
            yiterator = y - left;
            if (xiterator <= 0) {
                xiterator = 1;
                ++left;
                --yiterator;
            }
            while (xiterator < x && yiterator > 0) {
                if (xiterator == 1 && yiterator == 1) bottomLeft = false;
                ++counter;
                ++xiterator;
                --yiterator;
            }
        }
        if (bottomRight) {
            xiterator = x + down;
            yiterator = y - arm;
            if (yiterator <= 0) {
                yiterator = 1;
                ++down;
                ++xiterator;
            }
            while (xiterator < n && yiterator < y) {
                if (xiterator == n - 1 && yiterator == 1) bottomRight = false;
                ++counter;
                ++xiterator;
                ++yiterator;
            }
        }
        if (topRight) {
            xiterator = x + arm;
            yiterator = y + right;
            if (xiterator >= n) {
                xiterator = n - 1;
                ++right;
                ++yiterator;
            }
            while (xiterator > x && yiterator < n) {
                if (xiterator == n - 1 && yiterator == n - 1) topRight = false;
                ++counter;
                --xiterator;
                ++yiterator;
            }
        }
        ++arm;
        ++timer;
    }
    std::cout << timer << endl;
    return 0;
}