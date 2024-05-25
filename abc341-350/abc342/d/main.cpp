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

i32 reduce(i32 n);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 zero_cnt = 0;
    i64 ans = 0;
    map<i32, i32> mp;
    rep(i, 1, N){
        if(A[i] == 0){
            ans += (N - 1) - zero_cnt;
            zero_cnt++;
        } else{
            i32 rem = reduce(A[i]);
            mp[rem]++;
        }
    }

    for(auto p : mp){
        i32 cnt = p.second;
        if(1 < cnt){
            ans += 1LL * cnt * (cnt - 1) / 2;
        }
    }

    cout << ans << endl;
    return(0);
}

i32 reduce(i32 n){
    i32 rem = 1;
    for(i32 p = 2; p * p <= n; p++){
        i32 cnt = 0;
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        if(cnt & 1){ // 奇数
            rem *= p;
        }
    }

    if(1 < n){
        rem *= n;
    }

    // 素数が最後に残ることがある
    if(rem == 1){
        // 元から平方数
        return(0);
    } else{
        return(rem);
    }
}