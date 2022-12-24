#pragma optomize(3)
#pragma optimize("Ofast")
#include <bits/stdc++.h>
using ll = long long int;
#define int ll
constexpr int N = 3e5+10;
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
int a[N];
int b[N];
int tmp[N];
int cnt = 0;

void merge_sort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int pl = l, pr = mid + 1, tmpp = 0;
	while(pl <= mid && pr <= r) {
		if (a[pl] <= a[pr]) tmp[tmpp++] = a[pl++];
		else tmp[tmpp++] = a[pr++], cnt += mid - pl + 1;
	}
	while(pl <= mid) tmp[tmpp++] = a[pl++];
	while(pr <= r) tmp[tmpp++] = a[pr++];
	for (int i = 0; i < tmpp; i++) a[i + l] = tmp[i];
}

void solve()
{   
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        a[i] = b[i];
    }
    cnt = 0;
    merge_sort(1, n);
    int ans = cnt;
    int ans_num = 0;
    for (int i = 30; i >= 0; --i)
    {
        ans_num |= (1 << i);
        for (int i = 1; i <= n; ++i) a[i] = b[i] ^ ans_num;
        cnt = 0;
        merge_sort(1, n);
        if (cnt >= ans) ans_num ^= (1 << i);
        else ans = cnt;
        // cout << ans_num << " " << cnt << endl;
    }
    cout << ans << " " << ans_num << endl;
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