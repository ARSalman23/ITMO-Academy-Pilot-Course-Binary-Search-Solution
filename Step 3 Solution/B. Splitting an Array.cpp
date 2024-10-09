#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
const int N = 1e5 + 128;
const ll MX = 1e14 + 128;
int n, k, a[N];

bool isOk(ll val)
{
    int cnt = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum + a[i] <= val)
        {
            sum += a[i];
        }
        else
        {
            if(a[i] > val) return false;
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt <= k;
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
    ll l = 1, r = MX, ans = 0;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
