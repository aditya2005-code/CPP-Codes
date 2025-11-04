#include <bits/stdc++.h>
using namespace std;

double computeArea(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += X[i] * Y[j] - X[j] * Y[i];
    }
    return abs(area) / 2.0;
}

double computePerimeter(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    double peri = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        peri += abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
    }
    return peri;
}

int computeMinEdge(const vector<int>& X, const vector<int>& Y) {
    int n = X.size();
    int minEdge = INT_MAX;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (Y[i] == Y[j])
            minEdge = min(minEdge, abs(X[i] - X[j]));
        else
            minEdge = min(minEdge, abs(Y[i] - Y[j]));
    }
    return minEdge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];

    double area = computeArea(X, Y);
    double peri = computePerimeter(X, Y);
    int minEdge = computeMinEdge(X, Y);

    double maxVol = 0.0;
    for (double h = 0.1; h < minEdge; h += 0.1) {
        double vol = area * h - peri * h * h + 4.0 * h * h * h;
        if (vol > maxVol) maxVol = vol;
        else break;
    }

    cout << fixed << setprecision(2) << maxVol << "\n";
    return 0;
}
