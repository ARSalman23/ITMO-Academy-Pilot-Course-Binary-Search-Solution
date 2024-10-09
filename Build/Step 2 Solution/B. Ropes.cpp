#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int N = 1e5 + 128;
int a[N];
int n, k;
bool give_me(double mid)
{
    int total_ropes = 0;
    for(int i = 0; i < n; i++)
    {
        total_ropes += floor(a[i] / mid);
        if(total_ropes >= k) return true;
    }
    return false;
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
    double ans = 0;
    double l = 0, r = 1e7 + 128;
    while(r - l > 1e-7)
    {
        double mid = (l + r) / 2.0;
        if(give_me(mid))
        {
            ans = max(ans, mid);
            l = mid;
        }
        else r = mid;
    }
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}

