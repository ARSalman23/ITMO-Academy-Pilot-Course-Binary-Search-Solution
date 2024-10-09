#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e4 + 128, MX = 1e7;
int t[N], y[N], z[N], ballon[N];
int m, n;

bool isOk(int total_time)
{
    long long total_ballon = 0;
    long long ballon_left = m;
    for(int i = 1; i <= n; i++)
    {
        int time_for_1_block = t[i] * z[i] + y[i];
        int cur_block = total_time / time_for_1_block;
        long long cur_ballons = 1LL * cur_block * z[i];
        int rem_time = total_time % time_for_1_block;
        cur_ballons += min(z[i], (rem_time / t[i]));
        total_ballon += cur_ballons;
        ballon[i] = min(ballon_left, cur_ballons);
        ballon_left -= ballon[i];
    }
    return total_ballon >= m;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }
    int l = 0, r = MX, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    isOk(ans);
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << ballon[i] << ' ';
    }
    cout << endl;
    return 0;
}
