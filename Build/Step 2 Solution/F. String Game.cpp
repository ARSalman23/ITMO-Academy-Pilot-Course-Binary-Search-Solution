#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 2e5 + 128;
int a[N], n;
string t, p;

bool isOk(int x)
{
    vector<bool> alive(n, true);
    for(int i = 0; i < x; i++)
    {
        alive[a[i] - 1] = false;
    }
    int i, j;
    for(i = 0, j = 0; i < n; i++)
    {
        if(alive[i] and t[i] == p[j])
        {
            j++;
        }
        if(j == p.size()) break;
    }
    return (j == p.size());
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t >> p;
    n = t.size();
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
