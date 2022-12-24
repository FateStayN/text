// 生成数据

#include <bits/stdc++.h>

std::mt19937_64 RNG(std::chrono::steady_clock::now().time_since_epoch().count());

int rng(int l , int r)
{
    return RNG()%( r - l  + 1) + l;
}


struct GENARATE
{
    void main();
    
};

void GENARATE::main()
{
    using namespace std;
    ofstream cout("usrin.txt"); 
    
    int n = rng(1,20) , k = rng(0,100);
    cout << n << " " << k << "\n";
    for(int i=1 ; i<=n ; ++i)
        cout << rng(-100,100) << " ";
    cout << "\n";
}

