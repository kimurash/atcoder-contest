// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 109
#define INF 1e9

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

char adjmat[MAX][MAX];

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    rep(i, 1, N){
        rep(j, 1, N){
            cin >> adjmat[i][j];
        }
    }

    i32 A[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            if(i == j){
                A[i][j] = 0;
            } else{
                A[i][j] = INF;
            }
        }
    }

    queue<pi32> Q;
    rep(i, 1, N){
        Q.push({i, i});
    }

    rep(i, 1, N){
        rep(j, 1, N){
            if(i == j){
                continue;
            }
            if(adjmat[i][j] != '-'){
                A[i][j] = 1;
                Q.push({i, j});
            }
        }
    }

    while(!Q.empty()){
        pi32 p = Q.front();
        Q.pop();

        i32 u = p.first;
        i32 v = p.second;

        rep(i, 1, N){
            if(adjmat[i][u] != '-'){
                rep(j, 1, N){
                    if(adjmat[i][u] == adjmat[v][j]){
                        i32 len = A[u][v] + 2;
                        if(len < A[i][j]){
                            A[i][j] = len;
                            Q.push({i, j});
                        }
                    }
                }
            }
        }
    }

    rep(i, 1, N){
        rep(j, 1, N){
            if(j != 1){
                cout << " ";
            }
            if(A[i][j] == INF){
                cout << -1;
            } else{
                cout << A[i][j];
            }
        }
        cout << endl;
    }

    return(0);
}
