// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 3009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, vi32> piv32;

bool checked[MAX][MAX];

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 H[N + 1];
    rep(i, 1, N){
        cin >> H[i];
    }

    i32 ans = 1;
    rep(i, 1, N){
        rep(d, 1, N - 1){
            if(checked[i][d]){
                continue;
            }

            i32 h = H[i];

            int cnt = 1;
            for(int j = i + d; j <= N; j += d){
                if(h == H[j]){
                    cnt++;
                    checked[j][d] = true;
                } else{
                    break;
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    return(0);
}
