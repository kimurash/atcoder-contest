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

    i32 N, M;
    cin >> N >> M;

    char grid[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            cin >> grid[i][j];
        }
    }

    set<string> count;

    rep(i, 1, N - M + 1){
        rep(j, 1, N - M + 1){
            string pattern = "";

            rep(k, 0, M - 1){
                rep(l, 0, M - 1){
                    pattern += grid[i + k][j + l];
                }
            }
            
            count.insert(pattern);
        }
    }

    cout << count.size() << endl;

    return(0);
}
