// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 1009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

i32 di[] = {1, 0, -1, 0};
i32 dj[] = {0, 1, 0, -1};

char grid[MAX][MAX];
i32 dist[MAX][MAX];

int main(){
    cin.tie(nullptr);

    i32 H, W;
    cin >> H >> W;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            }else{
                cin >> grid[i][j];
            }
        }
    }

    i32 A, B, C, D;
    cin >> A >> B >> C >> D;

    deque<pi32> yet;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            dist[i][j] = INT32_MAX;
        }
    }

    yet.push_front({A, B});
    dist[A][B] = 0;

    while(!yet.empty()){
        pi32 now = yet.front();
        yet.pop_front();

        i32 i = now.first;
        i32 j = now.second;

        if(i == C && j == D){
            cout << dist[C][D] << endl;
            break;
        }

        rep(d, 0, 3){
            bool wall = false;
            rep(k, 1, 2){
                i32 ni = i + di[d] * k;
                i32 nj = j + dj[d] * k;

                if(ni < 1 ||  H < ni || nj < 1 || W < nj){
                    break;
                }

                if(grid[ni][nj] == '#'){
                    wall = true;
                }

                if(!wall){
                    if(k == 1){
                        if(dist[i][j] < dist[ni][nj]){
                            dist[ni][nj] = dist[i][j];
                            yet.push_front({ni, nj});
                        }
                    }
                } else{
                    if(dist[i][j] + 1 < dist[ni][nj]){
                        dist[ni][nj] = dist[i][j] + 1;
                        yet.push_back({ni, nj});
                    }
                }
            }
        }
    }

    return(0);
}
