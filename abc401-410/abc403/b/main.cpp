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

int main(){
    cin.tie(nullptr);

    string T, U;
    cin >> T >> U;

    for(i32 i = 0; i <= T.size() - U.size(); i++){
        bool contain = true;
        rep(j, 0, U.size() - 1){
            if(T[i + j] != U[j]){
                if(T[i + j] != '?'){
                    contain = false;
                    break;
                }
            }
        }
        if(contain){
            cout << "Yes" << endl;
            return(0);
        }
    }

    cout << "No" << endl;
    return(0);
}
