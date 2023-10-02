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

pair<int,int> rectangles(pair<int,int> xs_1, pair<int,int> ys_1, pair<int,int> xs_2, pair<int,int>ys_2)
{
    
    //Координаты растут из нижнего левого угла, как на графиках (как в школе)


    int left = max(min(xs_1.first, xs_1.second), min(xs_2.first, xs_2.second)); //Берём левые границы обоих прямоугольников. Смотрим, что большще
    int top = min(max(ys_1.first, ys_1.second), max(ys_2.first,ys_2.second)); //Берём верхние границы. - и минимум из них
    int right = min(max(xs_1.first, xs_1.second), max(xs_2.first, xs_2.second)); //Право
    int bottom = max(min(ys_1.first, ys_1.second), min(ys_2.first, ys_2.second));//низ

    int width = right - left;
    int height = top - bottom;
    if (width < 0 || height < 0) return make_pair(-1, 0);
    return make_pair(1,width*height);
}
// точка, старт, финиш
double distance(double x_pos, double y_pos, pair<double, double> s, pair<double, double> f) {
    //Да, можно было и через уравнение прямой, но чёт лень стало
    double d_1 = sqrt(pow(x_pos - s.first, 2) + pow(y_pos - s.second, 2));
    double d_2 = sqrt(pow(x_pos - f.first, 2) + pow(y_pos - f.second, 2));
    double l = sqrt(pow(f.first - s.first, 2) + pow(f.second - s.second, 2));
    double p = (d_1 + d_2 + l) / 2;
    double S = sqrt(p * (p - l) * (p - d_1) * (p - d_2));
    if (l == 0) {
        //Случай вырожденного отрезка
        return d_1;
    }
    double h = 2 * S / l;
    //Заметим, что нам становится плохо в случае, если высота падает на прямую, но не отрезок, что соотв.случаю тупоугольного треугольника, и, как следсвтие, можем отельно проверить это
      //Нам не подходят те, у которых угол d1-l или l-d2 - тупой
    if (pow(max(d_2,d_1),2)> pow(max(d_2,d_1),2) + l * l) {
        return min(d_1, d_2);
     }
    return h;
}
int calc_days(int d, int m, int y) {
    int days = 365 + (y % 4 == 0);
    int q = 0;
    //Если breakнет, мы идм дальше без проверок
    switch (m)
    {
    case 12:
        q += 30;
    case 11:
        q += 31;
    case 10:
        q += 30;
    case 9:
        q += 31;
    case 8:
        q += 31;
    case 7:
        q += 30;;
    case 6:
        q += 31;
    case 5:
        q += 30;
    case 4:
        q += 31;
    case 3:
        q += 28 + (y % 4 == 0);
    case 2:
        q += 31;
    case 1:
        q += d;
    }
    cout << q << endl;

    return q;

}

signed solve() {
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    map<int, priority_queue<int>> mem;
    set<int> w;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mem[v[i]].push(-i);

        w.insert(v[i]);
    }
    
    int a;
    while (q--) {
        cin >> a;
        auto it = w.lower_bound(a);
        if (it == w.end()) {
            cout << -1 << endl;
        }
        else {
            a = *it;
            cout << ( - mem[a].top())+1 << endl;
            mem[a].pop();
            if (mem[a].size() == 0) {
                w.erase(it);
            }
        }
    }




    return 0;
}
signed main()
{




    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    //cin >> test;
    //while (test--) solve();
    //int d, y, m;   cin >> d >> m >> y;

    //calc_days(d, m, y);




    return 0;
}


