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

bool G[10][10];
bool H[10][10];

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 M;
    cin >> M;

    i16 u, v;
    rep(i, 1, M){
        cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }

    i16 L;
    cin >> L;

    rep(i, 1, L){
        cin >> u >> v;
        H[u][v] = H[v][u] = true;
    }

    i32 A[N + 1][N + 1];
    rep(i, 1, N - 1){
        rep(j, i + 1, N){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    i16 vmap[N + 1];
    rep(i, 1, N){
        vmap[i] = i;
    }

    i64 ans = INT64_MAX;
    do{
        i64 total_cost = 0;
        rep(i, 1, N - 1){
            rep(j, i + 1, N){
                i32 k = vmap[i];
                i32 l = vmap[j];
                if(H[i][j]){ // Hに存在する
                    if(!G[k][l]){ // Gに存在しない
                        total_cost += A[i][j];
                    }
                } else{ // Hに存在しない
                    if(G[k][l]){ // Gに存在する
                        total_cost += A[i][j];
                    }
                }
            }
        }

        ans = min(ans, total_cost);

    } while(next_permutation(vmap + 1, vmap + N + 1));

    cout << ans << endl;
    return(0);
}
