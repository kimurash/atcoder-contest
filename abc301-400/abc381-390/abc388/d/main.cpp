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

    i32 A[N + 1];
    A[0] = 0;
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 acc[N + 2] = {0};

    i64 sum = 0;
    rep(i, 1, N){
        sum += acc[i];

        A[i] += sum;

        i32 num = min(A[i], N - i);
        acc[i + 1] += 1;
        acc[i + 1 + num] -= 1;
        A[i] -= num;
    }

    rep(i, 1, N){
        if(i != 1){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    return(0);
}
