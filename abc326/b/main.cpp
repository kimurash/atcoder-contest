// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 ans = N;
    i16 d1, d2, d3;
    while(true){
        d1 = ans / 100;
        d2 = (ans / 10) % 10;
        d3 = ans % 10;

        if(d1 * d2 == d3){
            break;
        }

        ans++;
    }

    cout << ans << endl;
    return(0);
}