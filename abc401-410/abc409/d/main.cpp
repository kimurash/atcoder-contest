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

    rep(t, 1, T){
        i32 N;
        string S;
        cin >> N >> S;

        i32 l = -1;
        rep(i, 0, N - 2){
            if(S[i] > S[i + 1]){
                l = i;
                break;
            }
        }

        if(l != -1){
            i32 r = N - 1;
            rep(i, l + 1, N - 2){
                if(S[l] < S[i + 1]){
                    r = i;
                    break;
                }
            }

            rotate(S.begin() + l, S.begin() + l + 1, S.begin() + r + 1);
        }

        cout << S << endl;
    }

    return(0);
}
