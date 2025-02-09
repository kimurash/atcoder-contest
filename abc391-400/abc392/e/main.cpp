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

typedef struct cable{
    i32 no;
    i32 A;
    i32 B;
} Cable;

class UnionFind{
public:
    // Union-Find木の頂点数の上限
    static const int32_t MAX_NODE = 200'009;
    // 各頂点の親
    int32_t parent[MAX_NODE];
    // 各頂点を根とする木の頂点数
    int32_t size[MAX_NODE];

    // 頂点xの根を求める
    int32_t root(int32_t x){
        while(parent[x] != -1){
            x = parent[x];
        }
        return(x);
    }
    
    UnionFind(int32_t N){
        rep(i, 1, N){
            // 最初は親がない
            this->parent[i] = -1;
            // 最初はグループの頂点数が1
            this->size[i] = 1;
        }
    }

    // 節uと節vが属するグループを統合する
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
};


int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    UnionFind uf(N);

    vector<Cable> rem;
    rep(i, 1, M){
        i32 A, B;
        cin >> A >> B;

        if(uf.same(A, B)){
            rem.push_back({i, A, B});
        } else{
            uf.unite(A, B);
        }
    }

    set<i32> leaders;
    rep(i, 1, N){
        if(uf.parent[i] == -1){
            leaders.insert(i);
        }
    }

    cout << leaders.size() - 1 << endl;
    while(1 < leaders.size()){
        Cable cable = rem.back();
        rem.pop_back();

        i32 u = uf.root(cable.A);
        leaders.erase(u);

        i32 v = *leaders.begin();
        leaders.erase(v);

        uf.unite(cable.A, v);
        leaders.insert(uf.root(u));

        printf("%d %d %d\n", cable.no, cable.A, v);
    }

    return(0);
}
