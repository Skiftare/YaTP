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
#include <numeric>

signed solve() {
    
    int n; cin >> n;
    int cnt = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) 
            cnt += (n - a - b >= 0 and n - a - b <= 9);
        
    }
    cout << cnt << endl;
    

    return 0;
}
signed main()
{




    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) solve();
   
    return 0;
}
