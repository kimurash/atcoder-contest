// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 1'414'214

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;


int main(){
    cin.tie(nullptr);

    i64 D;
    cin >> D;

    i64 ans = INT64_MAX;
    rep(x, 0, MAX){
        i64 C = 1LL * x * x - D;
        if(C > 0){
            ans = min(ans, C);
        } else{
            i64 y;
            y = ceil(sqrt(-C));
            ans = min(ans, abs(y * y + C));

            y = floor(sqrt(-C));
            ans = min(ans, abs(y * y + C));
        }
    }

    cout << ans << endl;
    return(0);
}