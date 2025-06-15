// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i16 N, M;
    cin >> N >> M;

    vector<i16> A(N), B(M), C(N + M);
    rep(i, 0, N - 1){
        cin >> A[i];
        C[i] = A[i];
    }
    rep(i, 0, M - 1){
        cin >> B[i];
        C[N + i] = B[i];
    }

    sort(all(C));

    bool cont = false;
    rep(i, 0, N + M - 1){
        if(find(all(A), C[i]) != A.end()){
            if(cont){
                cout << "Yes" << endl;
                return(0);
            }
            cont = true;
        } else{
            cont = false;
        }
    }

    cout << "No" << endl;

    return(0);
}
