// 求解

#include <bits/stdc++.h>
struct USERANS
{
    void main();
    
};

void USERANS::main()
{   
    using namespace std;
    ifstream cin("usrin.txt");
    ofstream cout("usrout.txt");

    int n , s; 
    cin >> n >> s;
    vector<int> vec(n + 1);
    for(int i=1 ; i<=n ; ++i)
        cin >> vec[i];
    vector <int> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) a[i] = vec[i] + a[i-1]; 
    int l = 1, r = 1, ansl = 0, ansr = -1;
    while (r <= n)
    {
        while (r <= n && a[r] - a[l-1] + s >= 0) r++;
        r--;
        if (r - l + 1 > ansr - ansl + 1)
        {
            ansr = r;
            ansl = l;
        }
        //cout << ansl << "  " << ansr << endl;
        if (r == n) break;
        r++; l++;
        while (l <= r && a[r] - a[l-1] + s >= 0) l++;
        if (l > r) r = l;
        //cout << l << " " << r << endl;
        //system("pause");
    }

    if(ansl == 0) cout << -1 << "\n";
    else cout << ansl << " " << ansr << "\n";


}
