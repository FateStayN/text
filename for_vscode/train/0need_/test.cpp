#include <bits/stdc++.h>
using namespace std;
struct KMP
{
    string s;
    vector<int> kmp;
    void prefix_function()
    {
        int n = (int)s.length();
        kmp.resize(n);
        for (int i = 1; i < n; i++)
        {
            int j = kmp[i - 1];
            while (j > 0 && s[i] != s[j])
                j = kmp[j - 1];
            if (s[i] == s[j])
                j++;
            kmp[i] = j;
        }
    }

    int match(string &str)
    {
        // debug(kmp);
        // vector<int> ret;
        int ret = 0;
        int patlen = this->s.length();
        int matchlen = str.length(), j = 0;

        for (int i = 0; i < matchlen; ++i)
        {
            while (j && this->s[j] != str[i] && str[i] != '?')
            {
                j = kmp[j - 1];
            }
            if (this->s[j] == str[i] || str[i] == '?')
                ++j;
            if (j == patlen)
            {
                // ret.push_back(i - patlen + 1);
                // cerr << i - patlen + 1 << "\n";
                ++ret;
                j = kmp[j - 1];
            }
        }
        return ret;
    }

    KMP(string &str)
    {
        s = str;
        prefix_function();
    }

    void print()
    {
        cerr << "----------PREFIX ARRAY--------------\n";
        for (auto x : kmp)
            cerr << setw(4) << x;
        cerr << "\n";
        for (auto x : s)
            cerr << setw(4) << x;
        cerr << "\n------------------------------------\n";
    }
};


inline void solve()
{
    string match , pat;
    cin >> match >> pat;
    KMP k(pat);
    cout << k.match(match);

}

signed main()
{
#ifdef __LOCAL

    freopen("usrin.txt", "r", stdin);
    freopen("usrout.txt", "w", stdout);

#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int __T = 1;
    // cin >> __T;
    while (__T--)
    {
        solve();
        if(__T) cout << "\n";
    }
}