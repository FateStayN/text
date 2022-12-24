#pragma optomize(3)
#pragma optimize("Ofast")
#include <bits/stdc++.h>
using ll = long long int;
#define int ll
constexpr int N = 2e5+10;
constexpr int mod = 1e9+7;
constexpr double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
#define f(a,b,c) for (auto a = (b); a <= (c); ++a)
#define fn(a,b,c,d) for (auto a = b; a <= c; a += d)
#define df(a,b,c) for (auto a = (b); a >= (c); --a)
#define dfn(a,b,c,d) for (auto a = (b); a >= (c); a -= d)
#define rep(a,b) for (auto a = 0; a < (b); ++a)
#define vi vector <int>
#define mii map <int, int>
#define pii pair <int, int> 
#define all(a) a.begin(), a.end()
#define endl '\n'
using namespace std;

void solve()
{   
    int n; cin >> n;
    vi a(n);
    int ans = 0;
    vector <vector <int>> mp(64);
    rep(i, n)
    {
        cin >> a[i];
        ans ^= a[i];
        int cnt = 0, k = a[i];
        while (k)
        {
            k /= 2;
            cnt++;
        }
        mp[cnt-1].push_back(a[i]);
    }
    // for(int i = 0 ; i<60 ; ++i)
    // {
    //     if(mp[i].empty()) continue;
    //     cout << i << " : ";
    //     for (auto tmp : mp[i]) cout << tmp << " ";
    //     cout << endl;
    // }
    // cout << ans << endl;
    vector <int> anss;
    for (int j = 0; j < n; ++j)
    {
        int ok = 0 ;
        for (int i = 0; i <= 61; ++i)
        {
            // cout << (1 << i) << "<-----" << endl;
            if ((1LL << i) & ans)
            {
                // cout << i << endl;
                if (mp[i].empty()) continue;
                
                // cout << mp[i].back() << endl;
                ans ^= mp[i].back();
                anss.push_back(mp[i].back());
                mp[i].pop_back();
                ok = 1;
                break;
            }
            
        }
        if(!ok)
        {
            cout << "No\n";
            return;
        }
    }
    reverse(all(anss));
    cout << "Yes\n";
    for (auto i : anss) cout << i << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1; //cin >> t;
    while (t--)
    {
        solve();
    }
}