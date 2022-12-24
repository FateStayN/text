#define __USER__MAIN

#include <bits/stdc++.h>
#include <windows.h>
#include "bruteforce.cpp"
#include "genarate.cpp"
#include "usrans.cpp"

int main() {
    int cnt = 0;
    while (true) {

        GENARATE generate;
        generate.main();

        BRUTEFORCE bruteforce;
        bruteforce.main();

        USERANS usrans;
        usrans.main();

        if(system("fc usrout.txt brute.txt")) break;
        cnt++;
        std::cout << cnt << " case AC\n";
        // Sleep(100);
        if(cnt == 1000) break;
    }
    system("pause");
    return 0;
}