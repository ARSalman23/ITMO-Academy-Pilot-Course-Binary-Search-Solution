#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5 + 128, MX = 1e9 + 128;
int n, k, a[N];

bool isOk(int val)
{
    int x = a[0], cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] - x >= val)
        {
            cnt++;
            x = a[i];
        }
    }
    cnt++;
    return cnt >= k;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = MX, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
