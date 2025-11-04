#include <bits/stdc++.h>
using namespace std;

void maximumBooks(vector<int>& books, int idx, int prev, int curr, int &res) {
    if (idx == books.size()) {
        res = max(res, curr);
        cout << res<<" ";
        return;
    }

    maximumBooks(books, idx + 1, 0, 0, res);

    for (int take = prev + 1; take <= books[idx]; take++) {
        maximumBooks(books, idx + 1, take, curr + take, res);
    }
}

int main() {
    int n ;
    cout << "Enter the number of shelves: ";
    cin >> n ;

    vector<int> books(n);
    cout << "Enter the books in each shelf: ";
    for (int i = 0; i < n; i++) cin >> books[i];

    int res = 0;
    for(int i=0 ; i<n ; i++){
        maximumBooks(books, i, 0, 0, res);
    }

    cout << "Maximum books you can take: " << res << endl;
    return 0;
}
