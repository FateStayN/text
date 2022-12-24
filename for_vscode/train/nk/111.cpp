#pragma optomize(3)
#pragma optimize("Ofast")
#include <bits/stdc++.h>
using ll = long long int;
#define int ll
constexpr int N = 2e5+10;
constexpr int mod = 1e9+7;
constexpr double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
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
    int n, m; cin >> n >> m;
    vector <int> a(512, 0);
    for (int i = 0; i < n; ++i)
    {
        int tmp; cin >> tmp;
        int ans = 0;
        for (int j = 0; j < tmp; ++j)
        {
            int tmpp; cin >> tmpp;
            tmpp--;
            ans += (1 << tmpp);
        }
        // cout << ans << endl;
        a[ans]++;
        // cout << a[ans] << endl;
    }
    vector <pair<int, int>> b(512);
    vector <pair<int, int>> c(512);
    for (int i = 0; i < 512; ++i)
    {
        b[i].first = inf;
        c[i].first = inf;
        b[i].second = -1;
        c[i].second = -1;
    }
    for (int i = 0; i < m; ++i)
    {
        int pp; cin >> pp;
        int ans = 0;
        int tmp; cin >> tmp;
        for (int i = 0; i < tmp; ++i)
        {
            int need; cin >> need;
            need--;
            ans += (1 << need);
        }
        // cout << ans << " " << b[ans].first << endl;
        if (pp < b[ans].first)
        {
            c[ans].first = b[ans].first;
            c[ans].second = b[ans].second;
            b[ans].first = pp;
            b[ans].second = i + 1;
        }
        else if (pp < c[ans].first)
        {
            c[ans].first = pp;
            c[ans].second = i + 1;
        }
    }
    // for (int i = 0; i < 512; ++i)
    // {
    //     cout << i << " " << b[i].first << " " << b[i].second << "<----->" << c[i].first << " " << c[i].second << endl;
    // }
    int ans1 = 0, ans2 = 0;
    int prizes = inf;
    int persons = -1;
    for (int i = 1; i <= 511; ++i)
    {
        for (int j = 1; j <= 511; ++j)
        {
            // int now;
            int aa, bb;
            int prize = 0;
            if (i != j)
            {
                if (b[i].second == -1 || b[j].second == -1) continue;
                aa = b[i].second;
                bb = b[j].second;
                prize = b[i].first + b[j].first;
                // now = i | j;
            }
            if (i == j)
            {
                if (b[i].second == -1 || c[i].second == -1) continue;
                aa = b[i].second;
                bb = c[i].second;
                prize = b[i].first + c[i].first;
            }
            // cerr << i << " " << j << endl;
            // if (b[i].second == -1 || c[i].second == -1) continue;
            // cout << i << " " << j << " " << prize << endl;
            int now = i | j;
            int person = 0;
            for (int kk = 1; kk <= 511; ++kk)
            {
                if (a[kk] == 0) continue;
                // cout << a[kk] << "<--" << endl;
                if ((now & kk) == kk) person += a[kk];
                // cout << i << " " << j << " " << kk << endl;
            }
            // cout << person << " " << persons << endl;
            if (person > persons)
            {
                ans1 = aa;
                ans2 = bb;
                persons = person;
                prizes = prize;
            }
            else if (person == persons && prize < prizes)
            {
                ans1 = aa;
                ans2 = bb;
                prizes = prize;
            }
            // cout << ans1 << " " << ans2 << " " << prizes << " " << persons << endl;
        }
        // cerr << ans1 << endl;
    }
    cout << ans1 << " " << ans2 << endl;
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