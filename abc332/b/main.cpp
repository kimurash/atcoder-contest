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

    i32 K, G, M;
    cin >> K >> G >> M;

    i32 glass = 0, cup = 0;
    rep(i, 1, K){
        if(glass == G){
            glass = 0;
        } else if(cup == 0){
            cup = M;
        } else{
            if(G - glass < cup){
                cup -= G - glass;
                glass = G;
            } else{
                glass += cup;
                cup = 0;
            }
        }
    }

    printf("%d %d\n", glass, cup);
    return(0);
}