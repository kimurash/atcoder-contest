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
typedef string str;

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 x;
    i32 A[N + 1];
    rep(i, 1, N){
        cin >> x;
        A[i] = x;
    }

    vec<i64> B;
    rep(i, 1, N){
        B.push_back(A[i]);
        i32 size = B.size();
        while(1 < size){
            i64 tail1 = B[size - 1];
            i64 tail2 = B[size - 2];
            if(tail1 != tail2){
                break;
            }
            B.pop_back();
            B.pop_back();
            B.push_back(tail1 + 1);

            size = B.size();
        }
        // vecout(B);
    }

    cout << B.size() << endl;
    return(0);
}
