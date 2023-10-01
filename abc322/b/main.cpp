// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    string front = T.substr(0, N);
    string back = T.substr(M - N, N);
    
    if(front == S){
        if(back == S){
            cout << 0 << endl;
        } else{
            cout << 1 << endl;
        }
    } else{
        if(back == S){
            cout << 2 << endl;
        } else{
            cout << 3 << endl;
        }
    }

    return(0);
}