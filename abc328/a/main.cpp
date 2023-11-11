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

    i16 N, X;
    cin >> N >> X;
    
    i16 S;
    i32 sum = 0;
    rep(i, 1, N){
        cin >> S;
        if(S <= X){
            sum += S;
        }
    }

    cout << sum << endl;
    return(0);
}