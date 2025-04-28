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

    i32 N, M, Q;
    cin >> N >> M >> Q;

    bool can_view_all[N + 1];
    rep(i, 1, N){
        can_view_all[i] = false;
    }

    set<i32> page_set[N + 1];

    i16 query;
    rep(i, 1, Q){
        cin >> query;
        if(query == 1){
            i32 X, Y;
            cin >> X >> Y;
            page_set[X].insert(Y);

        } else if(query == 2){
            i32 X;
            cin >> X;
            can_view_all[X] = true;

        } else if(query == 3){
            i32 X, Y;
            cin >> X >> Y;
            if(can_view_all[X]){
                cout << "Yes" << endl;
            } else{
                if(0 < page_set[X].count(Y)){
                    cout << "Yes" << endl;
                } else{
                    cout << "No" << endl;
                }
            }
        }
    }

    return(0);
}
