// 暴力求解
#include <bits/stdc++.h>


struct BRUTEFORCE
{
    void main();
    
};

void BRUTEFORCE::main()
{   
    using namespace std;
    ifstream cin("usrin.txt");
    ofstream cout("brute.txt");

    int n , s;
    cin >> n >> s;
    vector<int> vec( n + 1);
    for(int i=1 ; i<=n ; ++i)
        cin >> vec[i];

    
    auto func = [&](int l)
    {
        int sum = 0;
        for(int i=l ; i<=n ; ++i)
        {
            if(sum + vec[i] < 0) return i-1;
            sum += vec[i];
        }
        return n;
    };


    int maxlen = 0  , ansl , ansr;

    for(int i=1 ; i<=n ; ++i)
    {
        int pos = func(i);
        if(pos == -1) continue;
        if(maxlen < (pos - i + 1))
        {
            maxlen = pos - i + 1;
            ansl = i , ansr = pos;
        }
    }
    if(maxlen == 0) cout << -1 << "\n";
    else cout << ansl << " " << ansr << "\n";
}   

#ifndef __USER__MAIN
int main()
{
    BRUTEFORCE b;
    b.main();
}
#endif