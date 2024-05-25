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

    i16 N;
    cin >> N;

    rep(i, 0, N){
        rep(j, 0, N){
            rep(k, 0, N){
                if(i + j + k <= N){
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }
    return(0);
}