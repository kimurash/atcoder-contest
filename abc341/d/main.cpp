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

i64 gcd(i64 N, i64 M);
i64 lcm(i64 N, i64 M);

int main(){
    cin.tie(nullptr);

    i64 N, M, K;
    cin >> N >> M >> K;

    if(N < M){
        swap(N, M);
    }
    i64 l = lcm(N, M);

    i64 low = 0, high = 1e18;
    while(low + 1 < high){
        i64 mid = (low + high) / 2;
        i64 L = (mid / N) + (mid / M) - 2 * (mid / l);
        if(L < K){
            low = mid;
        } else{
            high = mid;
        }
    }

    cout << high << endl;
    return(0);
}

i64 lcm(i64 N, i64 M){
    return N / gcd(N, M) * M ;
}

i64 gcd(i64 N, i64 M){ // N > Mを仮定
    if (M == 0) {
        return N;
    } else {
        return gcd(M, N % M);
    }
}