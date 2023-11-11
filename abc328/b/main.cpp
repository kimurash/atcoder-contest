// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 is_same_num(i16 n){
    i16 now = n % 10;
    i16 next;
    n /= 10;

    while(n > 0){
        next = n % 10;
        if(now != next){
            return(0);
        }
        n /= 10;
    }

    return(now);
}

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 D[N + 1];
    rep(i, 1, N){
        cin >> D[i];
    }

    i32 ans = 0;
    rep(month, 1, N){
        rep(day, 1, D[month]){
            i16 m = is_same_num(month);
            if(m == 0){
                continue;
            }
            i16 d = is_same_num(day);
            if(d == 0){
                continue;
            }
            if(m == d){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return(0);
}