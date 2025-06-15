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

typedef uint32_t uint32_t;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    uint32_t N;
    cin >> N;

    i32 H[N + 1];
    rep(i, 1, N){
        cin >> H[i];
    }

    if(N == 1){
        cout << 0 << endl;
        return(0);
    }

    stack<i32> ans;
    ans.push(0);
    ans.push(1);

    stack<i32> J;
    J.push(N);

    for(int i = N - 2; 1 <= i; i--){
        while(!J.empty()){
            if(H[J.top()] < H[i + 1]){
                J.pop();
            }else{
                break;
            }
        }
        J.push(i + 1);
        ans.push(J.size());
    }

    while(!ans.empty()){
        if(ans.size() != N){
            cout << " ";
        }
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    return(0);
}
