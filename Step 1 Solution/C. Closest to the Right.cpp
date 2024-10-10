#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5 + 128;
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while(k--)
    {
        int x; cin >> x;
        int ans = INT_MAX;
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(a[mid] >= x)
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ans == INT_MAX) ans = n + 1;
        cout << ans << endl;
    }
    return 0;
}

