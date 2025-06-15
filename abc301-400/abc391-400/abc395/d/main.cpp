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

    i32 N;
    cin >> N;

    // ps[i] = ハトiが属する集合
    i32 ps[N + 1];
    rep(i, 1, N){
        ps[i] = i;
    }
    // sn[i] = 集合iと対応する巣の番号
    i32 sn[N + 1];
    rep(i, 1, N){
        sn[i] = i;
    }
    // ns[i] = 巣iと対応する集合の番号
    i32 ns[N + 1];
    rep(i, 1, N){
        ns[i] = i;
    }

    i32 Q;
    cin >> Q;

    rep(i, 1, Q){
        i32 query;
        cin >> query;

        if(query == 1){
            i32 a, b;
            cin >> a >> b;
            
            i32 s = ns[b];
            ps[a] = s;

        } else if(query == 2){
            i32 a, b;
            cin >> a >> b;

            i32 s1 = ns[a];
            i32 s2 = ns[b];

            sn[s1] = b;
            sn[s2] = a;

            ns[a] = s2;
            ns[b] = s1;

        } else if(query == 3){
            i32 a;
            cin >> a;

            i32 s = ps[a];
            i32 n = sn[s];
            cout << n << endl;
        }
    }

    return(0);
}
