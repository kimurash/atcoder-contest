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

    i16 X, Y;
    cin >> X >> Y;

    i16 dlt = Y - X;
    if(dlt > 0){
        if(dlt <= 2){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }else{
        dlt = -dlt;
        if(dlt <= 3){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return(0);
}