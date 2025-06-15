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

    i32 N;
    cin >> N;

    i64 ans = 0;
    i32 K[N + 1];
    rep(i, 1, N){
        cin >> K[i];
        ans += K[i];
    }

    for(int i = 0; i < (1 << 20); i++){
        bitset<20> bs(i);

        i64 A = 0, B = 0;
        for(int j = 0; j < N; j++){
            if(bs.test(j)) {
                A += K[j + 1];
            } else{
                B += K[j + 1];
            }
        }
        ans = min(ans, max(A, B));
    }

    cout << ans << endl;
    return(0);
}
