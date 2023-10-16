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

int hw11_1(double a, double x, double y) {
    if (abs(x) < a / 2 && abs(y) < a / 2) return 1;
    if ((abs(x) <= a / 2 && abs(y) == a / 2) or (abs(y) <= a / 2 && abs(x) == a / 2)) return 0;
    return -1;
}
int hw11_2(int a, int b) {
    int i = 2;
    for (i = 2; i * i <= a && a % i; i++);
    if (!(a % i) && a != i) return -1;
    for (i = 2; i * i <= b && b % i; i++);
    if (!(b % i) && b != i) return -1;
    return (abs(a - b) == 2 ? 1 : -1);

}
bool hw11_3(int a, int b) {
    int sum1 = 1;
    int sum2 = 1;
    int i;
    for (i = 2; i * i <= a; i++) {
        if (a % i == 0) 
            sum1 += i + (a / i);  
    }
    if (i * i == a) sum1 -= i;

    for (i = 2; i * i <= b; i++) {
        if (b % i == 0) 
            sum2 += i + (b / i);  
    }

    if (i * i == b) sum2 -= i;


    return (sum1 == b && sum2 == a);
}
int hw11_4(int countOfFishermen) {
    //return -2;
    int fishs = 1;
    while (1) {
        bool f = false;
        int c = fishs;
        for (int i = 0; i < countOfFishermen and !f; i++) {
            f = (c % 3 != 1);
            if (((c - 1) / 3) <= 0) f = true;
            c = (c - 1) - ((c - 1) / 3);
        }
        if (f == false) return fishs;
        fishs++;
    }
}
signed practise_1(int n) {
    int l = 0;
    int buf = n;
    while (buf) {
        l = l * 10 + (buf % 10);
        buf /= 10;
    }
    while (n) {
        if (n % 10 != l % 10) return 0;
      
        n /= 10;
        l /= 10;
    }
    return 1;
}
signed practise_2(int n) {
    vector<int> times_of_visit(10);
    int len = 0;
    int buf = n;
    while (buf) {
        times_of_visit[buf % 10]++;
        buf /= 10;
        len++;
    }
    int s = 0;
    for (int i = 0; i < 10; i++) {
        if (times_of_visit[i]) {
            s = s + pow(i, len);
        }
    }
    return s==n;
}
signed hw18_1(int n) {
    int buf = n;
    while (buf) {
        if (buf % 10 != 0) {
            if (n % (buf % 10) == 0) return 1;
        }
        buf /= 10;
    }
    return 0;
}
long long hw18_2(int n) {
    int res = 0;
    int maxiNum, maxiPos, buf, l;
    int length_of_n = 0;
    for(buf = n;buf>0;buf/=10, length_of_n++);
    while(n){
        for(buf = n, l = 0, maxiNum = -1, maxiPos = -1;buf>0;buf/=10, l++){
            if(buf%10 > maxiNum){
                maxiNum = buf%10;
                maxiPos = l;
            }
        }
        for(buf = n, l = 0;buf>0;buf/=10, l++) {
            if(l == maxiPos) {
                res = res * 10 + buf%10;
                break;
            }
        }
        for(buf = 0, l = 0;n>0;n/=10, l++){
            if(l != maxiPos){
                buf = buf*10+(n%10);
            }
        }
        n = buf;
    }
    int lengh_of_res = 0;
    for(buf = res;buf>0;buf/=10, lengh_of_res++);
    while(lengh_of_res<length_of_n){
        res*=10;
        lengh_of_res++;
    }
    return res;
}
int hw18_3(int p) {
    int l = 1;
    int a = 1;
    int b = 1;
    int d = 10;
    int c;
    if (p <= 0) return -1;
    if (p <= 2) return 1;
    p -= 2;
    while (1) {
        c = a + b;
        a = b;
        b = c;
        while (c > d) {
            d *= 10;
            l += 1;
        }
        p -= l;
        if (p <= 0) {
            if (p < 0)
                p += l;
            for (; c; c /= 10) {
                if (p == 0) return c % 10;
                p -= 1;
            }
            return -1;
        }
    }
    return -1;
}

signed main()
{

    cout << practise_2(154);

    

   

    return 0;
}

