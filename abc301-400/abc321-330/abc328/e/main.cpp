// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

class UnionFind{
private:
    static const int32_t MAX_NODE = 10; // Union-Find木の頂点数の上限
    int32_t parent[MAX_NODE]; // 各頂点の親
    int32_t size[MAX_NODE];   // 各頂点を根とする木の頂点数
public:
    UnionFind(int32_t N){
        rep(i, 1, N){
            this->parent[i] = -1; // 最初は親がない
            this->size[i] = 1;    // 最初はグループの頂点数が1
        }
    }

    // 節uと節vを統合する
    void unite(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        if(rootu == rootv){
            return;
        } else{
            if(this->size[rootu] < this->size[rootv]){
                this->parent[rootu] = rootv;
                this->size[rootv] += this->size[rootu];
            } else{
                this->parent[rootv] = rootu;
                this->size[rootu] += this->size[rootv];
            }
        }
    }

    // 節uと節vが同一のグループか判定する
    bool same(int32_t u, int32_t v){
        int32_t rootu = this->root(u);
        int32_t rootv = this->root(v);
        return(rootu == rootv);
    }

    // 頂点xの根を求める
    int32_t root(int32_t x){
        while(parent[x] != -1){
            x = parent[x];
        }
        return(x);
    }

    int32_t get_size(int32_t x){
        return(this->size[this->root(x)]);
    }
};

int main(){
    cin.tie(nullptr);

    i32 N, M;
    i64 K;
    cin >> N >> M >> K;

    i16 u[M + 1], v[M + 1];
    i64 w[M + 1];
    rep(i, 1, M){
        cin >> u[i] >> v[i] >> w[i];
    }

    i64 ans = INT64_MAX;

    // N - 1本の辺の組合せ
    vector<i16> choice(N - 1, 1);
    choice.resize(M, 0);
    sort(all(choice));

    do{
        vector<i16> edge;
        rep(i, 0, M - 1){
            if(choice[i] == 1){
                edge.push_back(i + 1);
            }
        }

        i64 sum = 0;
        UnionFind uf(N);
        for(i32 idx: edge){
            uf.unite(u[idx], v[idx]);
            sum = (sum + w[idx]) % K;
        }

        if(uf.get_size(1) == N){
            ans = min(ans, sum);
        }
    } while(next_permutation(all(choice)));

    cout << ans << endl;

    return(0);
}