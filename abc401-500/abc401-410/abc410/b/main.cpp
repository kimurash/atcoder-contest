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

    i16 N, Q;
    cin >> N >> Q;

    i32 X;
    i16 cnt[N + 1];
    i16 ans[Q + 1];

    rep(i, 1, N){
        cnt[i] = 0;
    }

    rep(i, 1, Q){
        cin >> X;
        if(0 < X){
            ans[i] = X;
            cnt[X]++;
        } else{
            i32 box = 1;
            i32 mincnt = cnt[1];
            rep(j, 2, N){
                if(cnt[j] < mincnt){
                    mincnt = cnt[j];
                    box = j;
                }
            }
            ans[i] = box;
            cnt[box]++;
        }
    }

    rep(i, 1, Q){
        if(i != 1){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return(0);
}
