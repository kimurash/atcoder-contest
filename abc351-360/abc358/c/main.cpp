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

    i16 N, M;
    cin >> N >> M;

    bool menu[N + 1][M + 1];
    char sell;
    rep(i, 1, N){
        rep(j, 1, M){
            cin >> sell;
            menu[i][j] = (sell == 'o');
        }
    }

    i16 ans = INT16_MAX;
    for(int i = 0; i < (1 << N); i++){
        bitset<10> store(i);
        bitset<10> popcorn(0);
        
        for(int j = 0; j < N; j++){
            if(store.test(j)) {
                rep(k, 1, M){
                    if(menu[j + 1][k]){
                        popcorn.set(k - 1);
                    }
                }
            }
        }

        i16 cnt = popcorn.count();
        if(M <= cnt){
            cnt = store.count();
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
    return(0);
}
