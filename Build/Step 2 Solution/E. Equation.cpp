#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX = 1e6;
double c;

bool isOk(double x)
{
    return (x * x) + sqrt(x) >= c;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c;
    double l = 0, r = MX, ans = 0;
    int tc = 100;
    while(tc--)
    {
        double mid = (l + r) / 2;
        if(isOk(mid))
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
