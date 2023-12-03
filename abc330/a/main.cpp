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

    i16 N, L;
    cin >> N >> L;

    i16 cnt = 0;
    i16 A;
    rep(i, 1, N){
        cin >> A;
        if(L <= A){
            cnt++;
        }
    }

    cout << cnt << endl;
    return(0);
}