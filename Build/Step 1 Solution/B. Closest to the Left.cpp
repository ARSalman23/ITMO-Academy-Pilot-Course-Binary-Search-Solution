#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int MX_R = 1e14;
int w, h, n;
bool give_me(int mid)
{
    int a1 = mid / w;
    int a2 = mid / h;
    if(a2 == 0) return false;
    return (1.0 * a1) >= (1.0 * n / a2);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> w >> h >> n;
    int ans = MX_R;
    int l = 1, r = MX_R;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(give_me(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}

