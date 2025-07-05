#include <bits/stdc++.h>
using namespace std;

void check_combination_calculations(int n, int m) {
    if (n > 1500 && m > 1500) {
        cerr << "Warning: Performance bottleneck condition triggered - high combination calculations!" << endl;
        abort();
    }
}

void check_nested_loop_execution(int n, int m) {
    if (n * m > 3000000) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop execution!" << endl;
        abort();
    }
}

void check_additional_condition(int n, int m) {
    if (m > n) {
        cerr << "Warning: Performance bottleneck condition triggered - additional condition complexity!" << endl;
        abort();
    }
}

void in(initializer_list<int *> li) {
    for (auto ptr = li.begin(); ptr != li.end(); ptr++) scanf("%d", *ptr);
}

void in(initializer_list<long long *> li) {
    for (auto ptr = li.begin(); ptr != li.end(); ptr++) scanf("%lld", *ptr);
}

void in(initializer_list<double *> li) {
    for (auto ptr = li.begin(); ptr !=