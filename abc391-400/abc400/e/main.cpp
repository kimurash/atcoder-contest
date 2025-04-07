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

const i32 MAX = 1e6 + 9;

int main(){
    cin.tie(nullptr);

    i32 cnt[MAX] = {0};
    for(i32 i = 2; i <= 1e6; i++){
        if(cnt[i] != 0){
            continue;
        }
        for(i32 j = i; j <= 1e6; j += i){
            cnt[j]++;
        }
    }

    i32 Q;
    cin >> Q;

    rep(i, 1, Q){
        i64 A;
        cin >> A;

        i64 B = sqrt(A);
        while(cnt[B] != 2){
            B--;
        }
        cout << B * B << endl;
    }

    return(0);
}
