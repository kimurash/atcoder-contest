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

    i32 N, Q;
    cin >> N >> Q;

    // pigeon[i]: i番目の鳩がいる巣の番号
    i32 pigeon[N + 1];
    // cnt[i]: i番目の巣の匹数
    i32 cnt[N + 1] = {0};

    rep(i, 1, N){
        pigeon[i] = i;
        cnt[i] = 1;
    }

    // 複数の鳩がいる巣の総数
    i32 ans = 0;

    i16 query;
    rep(i, 1, Q){
        cin >> query;
        if(query == 1){
            i32 P, H;
            cin >> P >> H;

            i32 hole = pigeon[P];
            cnt[hole]--;
            if(cnt[hole] == 1){
                ans--;
            }
            
            cnt[H]++;
            if(cnt[H] == 2){
                ans++;
            }
            pigeon[P] = H;

        } else if(query == 2){
            cout << ans << endl;
        }
    }

    return(0);
}
