#include <bits/stdc++.h>
using namespace std;


int edgeScore(vector<int> &edges)
{
    int n = edges.size();
    long maxi = 0;
    vector<long> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        res[edges[i]] += i;
        maxi = max(maxi, res[edges[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (res[i] == maxi)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    vector<int> edge = {1, 0, 0, 0, 0, 7, 7, 5};
    int res = edgeScore(edge);
    cout<<"Maximum edge score is : "<<res<<endl;
    return 0;
}