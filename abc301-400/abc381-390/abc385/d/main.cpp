// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 20'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;


int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i64 x, y;
    cin >> x >> y;

    i32 hx, hy;
    map<i64, set<i64>> xmap;
    map<i64, set<i64>> ymap;
    rep(i, 1, N){
        cin >> hx >> hy;
        xmap[hx].insert(hy);
        ymap[hy].insert(hx);
    }

    char D;
    i32 C;
    i32 ans = 0;
    rep(i, 1, M){
        cin >> D >> C;
        if(D == 'U'){
            i64 ny = y + C;
            auto iter = xmap[x].lower_bound(y);

            while(iter != xmap[x].end() && *iter <= ny){
                ans++;
                ymap[*iter].erase(x);
                iter = xmap[x].erase(iter);
            }

            y = ny;

        } else if(D == 'D'){
            i64 ny = y - C;
            auto iter = xmap[x].lower_bound(ny);

            while(iter != xmap[x].end() && *iter <= y){
                ans++;
                ymap[*iter].erase(x);
                iter = xmap[x].erase(iter);
            }

            y = ny;

        } else if(D == 'L'){
            i64 nx = x - C;
            auto iter = ymap[y].lower_bound(nx);

            while(iter != ymap[y].end() && *iter <= x){
                ans++;
                xmap[*iter].erase(y);
                iter = ymap[y].erase(iter);
            }

            x = nx;

        } else if(D == 'R'){
            i64 nx = x + C;
            auto iter = ymap[y].lower_bound(x);

            while(iter != ymap[y].end() && *iter <= nx){
                ans++;
                xmap[*iter].erase(y);
                iter = ymap[y].erase(iter);
            }

            x = nx;
        }
    }

    printf("%lld %lld %d\n", x, y, ans);
    return(0);
}
