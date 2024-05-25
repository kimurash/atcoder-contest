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
typedef string str;

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 X[M + 1];
    rep(i, 1, M){
        cin >> X[i];
    }

    i64 cnt[N + 1] = {0};
    rep(i, 1, M - 1){
        i32 crnt = X[i];
        i32 next = X[i + 1];

        if(crnt < next){
            // 右回り
            i32 right = next - crnt;
            // 左回り
            i32 left = (N - next) + crnt;
            
            cnt[crnt] += left;
            cnt[next] -= left;

            cnt[1] += right;
            cnt[crnt] -= right;
            cnt[next] += right;

        } else{ // next < crnt
            // 右回り
            i32 right = (N - crnt) + next;
            // 左回り
            i32 left = crnt - next;
            
            cnt[1] += left;
            cnt[next] -= left;
            cnt[crnt] += left;

            cnt[next] += right;
            cnt[crnt] -= right;
        }
    }

    i64 ans = INT64_MAX;
    i64 acc[N + 1] = {0};
    rep(i, 1, N){
        acc[i] = acc[i - 1] + cnt[i];
        ans = min(ans, acc[i]);
    }

    cout << ans << endl;
    return(0);
}