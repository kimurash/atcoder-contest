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
    string S;

    cin >> N >> S;

    rep(i, 0, N - 2){
        if(S[i] == 'a' && S[i + 1] == 'b'){
            cout << "Yes" << endl;
            return(0);
        }
        if(S[i] == 'b' && S[i + 1] == 'a'){
            cout << "Yes" << endl;
            return(0);
        }
    }

    cout << "No" << endl;
    return(0);
}