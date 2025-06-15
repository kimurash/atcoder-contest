// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 300'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    // K[i]: 料理iで使う材料の数
    i32 K[M + 1];
    // dish[j]: 材料jを使う料理の番号
    set<i32> dish[N + 1];

    rep(i, 1, M){ // 料理
        cin >> K[i];

        i32 A;
        rep(k, 1, K[i]){ // 材料
            cin >> A;
            dish[A].insert(i);
        }
    }

    i32 B;
    i32 ans = 0;
    rep(i, 1, N){
        cin >> B;
        for(i32 d : dish[B]){ // 料理
            K[d]--;
            if(K[d] == 0){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return(0);
}
