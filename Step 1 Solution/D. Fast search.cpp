#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 2e5 + 128;
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int lo = lower_bound(a, a + n, l) - a;
        int up = upper_bound(a, a + n, r) - a;

        cout << up - lo << endl;
    }
    return 0;
}
