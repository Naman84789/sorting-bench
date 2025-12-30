#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sizes = {4, 8, 16, 32};
    const int trials = 200000;

    mt19937 rng(42);

    for (int n : sizes) {
        ll time_std = 0, time_ins = 0;

        for (int t = 0; t < trials; t++) {
            vector<int> a(n);
            for (int i = 0; i < n; i++)
                a[i] = rng() % 100000;

            vector<int> b = a;

            auto start = chrono::high_resolution_clock::now();
            sort(a.begin(), a.end());
            auto end = chrono::high_resolution_clock::now();
            time_std += chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            start = chrono::high_resolution_clock::now();
            insertion_sort(b);
            end = chrono::high_resolution_clock::now();
            time_ins += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        }

        cout << "N=" << n
             << " std::sort avg(ns)=" << time_std / trials
             << " insertion avg(ns)=" << time_ins / trials
             << "\n";
    }
    return 0;
}

