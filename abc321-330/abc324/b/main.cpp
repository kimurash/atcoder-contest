// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX2 54
#define MAX3 36

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    while(N % 2 == 0){
        N /= 2;
    }

    while(N % 3 == 0){
        N /= 3;
    }

    if(N == 1){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return(0);
}