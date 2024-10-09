#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define endl "\n"
#define int long long
const int N = 2e9 + 128;
int n, x, y;

bool isOk(int mid)
{
    int cnt = 0;
    if(x > y) swap(x, y);
    if(x <= mid)
    {
        cnt += 1;
        mid -= x;
        cnt += mid / y;
        cnt += mid / x;
    }
    return cnt >= n;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    int l = 0, r = N, ans = INT_MAX;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
