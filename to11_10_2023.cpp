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

#define int long long

using namespace std;

int fst_task(double a, double x, double y) {
    if (abs(x) <= a / 2 && abs(y) <= a / 2) return 1;
    if ((abs(x) <= a / 2 && abs(y) == a / 2) or (abs(y) <= a / 2 && abs(x) == a / 2)) return 0;
    return -1;
}
int sec_task(int a, int b) {
    int i = 2;
    for (i = 2; i * i <= a && a % i; i++);
    if (!(a % i) && a != i) return -1;
    for (i = 2; i * i <= b && b % i; i++);
    if (!(b % i) && b != i) return -1;
    return (abs(a - b) == 2 ? 1 : -1);

}
bool third_task(int a, int b) {
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            sum1 += i + (a / i);
    }
    for (int i = 2; i * i <= b; i++) {
        if (b % i == 0)
            sum2 += i + (b / i);
    }
    return (sum1 == b && sum2 == a);
}
int fouth_task() {
    return 25;
}

signed solve() {
    
    
    
    
    
    return 0;
}
signed main()
{

   



    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) solve();
   
    return 0;
}


