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

    i32 A[N], B[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }
    rep(i, 0, N - 2){
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N - 1);

    i32 ans = -1;
    i32 toy = N - 1;
    i32 box = N - 2;
    while(0 <= box && 0 <= toy){
        if(A[toy] <= B[box]){
            box--;
            toy--;
        } else{
            if(ans != -1){
                ans = -1;
                break;
            } else{
                ans = A[toy];
                toy--;
            }
        }
    }

    if(box < 0 && 0 <= toy){
        ans = A[toy];
    }

    cout << ans << endl;
    return(0);
}
