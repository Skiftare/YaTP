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
#include <iomanip>

#define int long long

using namespace std;



signed solve() {
   
    int a, b, c;
    int x, y;
    int buf;
    cin >> a >> b >> c;
    cin >> x >> y;
    if (x > y) {
        buf = x;
        x = y;
        y = buf;
    }
    //x<=y на этом этапе
    int s = a + b + c;
    buf = min(a, min(b, c));
    c = max(a, max(b, c));
    b = s - c - buf;
    a = buf;
    //a <= b<= c
    if (a <= x and b <= y)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
signed main()   
{
    
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    int test = 1;
    cin>>test;
    while (test--) solve();
    



    return 0;
}


