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

    i32 T;
    cin >> T;

    rep(i, 1, T){
        i32 N;
        string S;
        cin >> N >> S;

        bool is_all_zero = true;
        rep(j, 0, N - 1){
            if(S[j] == '1'){
                is_all_zero = false;
                break;
            }
        }
        if(is_all_zero){
            cout << 0 << endl;
            continue;
        }

        i32 acc0[N + 1] = {0};
        i32 acc1[N + 1] = {0};
        rep(j, 1, N){
            acc0[j] = acc0[j - 1] + (S[j - 1] == '0' ? 1 : 0);
            acc1[j] = acc1[j - 1] + (S[j - 1] == '1' ? 1 : 0);
        }

        i32 accr[N + 2];
        accr[N + 1] = N;
        for(i32 r = N; 0 < r; r--){
            accr[r] = min(accr[r + 1], acc0[r] - acc1[r]);
        }

        i32 ans = N;
        rep(l, 1, N){
            i32 cost = 0;
            cost += acc1[l - 1] - acc0[l - 1];
            cost += accr[l];
            cost += acc1[N];

            ans = min(ans, cost);
        }

        cout << ans << endl;
    }

    return(0);
}
