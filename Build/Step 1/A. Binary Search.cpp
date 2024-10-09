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
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    while(k--)
    {
        int x; cin >> x;
        bool isOk = false;
        int l = 0, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(a[mid] == x)
            {
                isOk = true;
                break;
            }
            if(a[mid] > x)
            {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << (isOk ? "YES" : "NO") << endl;
    }
    return 0;
}

