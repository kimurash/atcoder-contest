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

int main(){
    cin.tie(nullptr);

    i32 N, M;
    string S;
    cin >> N >> M >> S;

    i32 ans = 0;
    i32 plain = M, logo = 0;
    rep(i, 0, N - 1){
        if(S[i] == '0'){
            ans = max(ans, logo);
            logo = 0;
            plain = M;
        } else if(S[i] == '1'){
            if(0 < plain){
                plain--;
            } else{
                logo++;
            }
        } else if(S[i] == '2'){
            logo++;
        }
    }

    ans = max(ans, logo);
    cout << ans << endl;
    return(0);
}