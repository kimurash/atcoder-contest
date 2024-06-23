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

    i16 N, M, K;
    cin >> N >> M >> K;

    i16 C, key;
    vector<i16> A[M + 1];
    char R[M + 1];
    rep(i, 1, M){
        cin >> C;
        rep(j, 1, C){
            cin >> key;
            A[i].push_back(key);
        }
        cin >> R[i];
    }

    i32 ans = 0;
    for(int i = 0; i < (1 << N); i++){
        bitset<15> bs(i);

        bool ok = true;
        
        rep(j, 1, M){
            i32 cnt = 0;
            for(i16 key : A[j]){
                if(bs.test(key - 1)){
                    cnt++;
                }
            }

            if(K <= cnt){ // 開く
                if(R[j] != 'o'){
                    ok = false;
                    break;
                }
            } else{ // 開かない
                if(R[j] != 'x'){
                    ok = false;
                    break;
                }
            }
        }

        if(ok){
            ans++;
        }
    }

    cout << ans << endl;
    return(0);
}
