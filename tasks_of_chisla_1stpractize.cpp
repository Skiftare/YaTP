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
    
    
    int n, x, y;
    cin >> n >> x >> y;
    //x,y - простые. Надо найти числа [1...n], которые делятся либо на x, либо на y
    cout << (n / x) + (n / y) - 2*(n / (x * y)) << endl;
    //Сколько делится на x, сколько делится на y. Мы дважды посчитали те, кто и на x, и на y делятся. А их мы не должны учитывать
    //Дважды сосчитали - дважды и убираем.



    

    return 0;
}
signed main()   
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    int test = 1;
    //cin>>test;
    while (test--) solve();



    return 0;
}


