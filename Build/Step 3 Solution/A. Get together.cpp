#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5 + 128;
const double MX_TIME = 1e9 + 128;
int cur_pos[N], s[N], n;
double segment_left[N], segment_right[N];

bool isOk(double t)
{
    for(int i = 0; i < n; i++)
    {
        segment_left[i] = cur_pos[i] - t * s[i];
        segment_right[i] = cur_pos[i] + t * s[i];
    }
    double segment_left_max = -1e40;
    double segment_right_min = 1e40;
    for(int i = 0; i < n; i++)
    {
        segment_left_max = max(segment_left_max, segment_left[i]);
        segment_right_min = min(segment_right_min, segment_right[i]);
    }
    return segment_left_max <= segment_right_min;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> cur_pos[i] >> s[i];
    }
    double l = 0, r = MX_TIME, ans = 0;
    int it = 100;
    while(it--)
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
