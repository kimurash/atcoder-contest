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

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    i32 A[K + 1];
    rep(i, 1, K){
        cin >> A[i];
    }

    i64 ans = 0;
    if(K & 1){ // 奇数
        if(K != 1){
            vec<i32> fwd;
            for(int i = 1; i < K; i += 2){
                fwd.push_back(A[i + 1] - A[i]);
            }
            vec<i32> bwd;
            for(int i = K; i > 1; i -= 2){
                bwd.push_back(A[i] - A[i - 1]);
            }

            reverse(all(fwd));

            ans = accumulate(all(fwd), 0);
            i64 now = ans;
            for(int i = 0; i < fwd.size(); i++){
                now -= fwd[i];
                now += bwd[i];
                ans = min(ans, now);
            }
        }
    } else{ // 偶数
        ans = 0;
        for(int i = 1; i < K; i += 2){
            ans += A[i + 1] - A[i];
        }
    }

    cout << ans << endl;
    return(0);
}