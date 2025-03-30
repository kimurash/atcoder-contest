// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

int main(){
    cin.tie(nullptr);

    i32 T;
    cin >> T;

    rep(i, 1, T){
        i32 N;
        cin >> N;

        i32 A[2 * N + 1];
        rep(i, 1, 2 * N){
            cin >> A[i];
        }

        vi32 pos[N + 1];
        rep(i, 1, 2 * N){
            pos[A[i]].push_back(i);
        }

        set<pi32> cand;
        rep(i, 1, 2 * N - 1){
            i32 x = A[i];
            i32 y = A[i + 1];
            if(x == y){
                continue;
            } else if(x > y){
                swap(x, y);
            }
            cand.insert({x, y});
        }

        i64 ans = 0;
        for(auto p : cand){
            i32 x = p.first;
            i32 y = p.second;

            i32 xl = pos[x][0];
            i32 xr = pos[x][1];
            i32 yl = pos[y][0];
            i32 yr = pos[y][1];

            if(xl + 1 == xr){
                continue;
            }
            if(yl + 1 == yr){
                continue;
            }
            if(abs(xl - yl) == 1 && abs(xr - yr) == 1){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return(0);
}
