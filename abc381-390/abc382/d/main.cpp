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

i32 N, M;
vector<vi32> ans;

void recur(vi32 cur);

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    rep(i, 1, M){
        if(M < i + 10 * (N - 1)){
            break;
        }
        recur({i});
    }

    cout << ans.size() << endl;
    for(vi32 seq : ans){
        rep(i, 0, N - 1){
            if(i != 0){
                cout << " ";
            }
            cout << seq[i];
        }
        cout << endl;
    }

    return(0);
}

void recur(vi32 cur){
    i32 base = cur.back();

    if(cur.size() == N && base <= M){
        ans.push_back(cur);
        return;
    }

    i32 rem = N - cur.size();

    for(i32 i = 0; base + i + 10 * rem <= M; i++){
        cur.push_back(base + 10 + i);
        recur(cur);
        cur.pop_back();
    }

    return;
}
