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

map<i64, i64> memo;

i64 recur(i64 N);

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    i64 ans = recur(N);
    cout << ans << endl;
    return(0);
}

i64 recur(i64 N){
    if(N == 1){
        return 0;
    }

    if(memo.count(N) != 0){
        return memo[N];
    }

    memo[N] = N + recur(N / 2) + recur((N + 1) / 2);
    return memo[N];
}