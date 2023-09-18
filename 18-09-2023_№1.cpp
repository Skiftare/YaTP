#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;


signed solve() {
    
    
    int Hours;
    cin >> Hours;
    Hours %= 12;
    //Т.к. у нас часы стандартные, не арктические, с 12-числовым циферблатом, то 13.00 == 1.00
    cout << 30*min(Hours, 12 - Hours) << endl;



    

    return 0;
}
signed main()   s
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    int test = 1;
    //cin>>test;
    while (test--) solve();



    return 0;
}


