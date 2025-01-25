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

i16 N;
i64 A[20];
i64 B[20];
unordered_set<i64> st;

void dfs(i32 size, i32 depth);
void calc_xor_sum();

int main(){
    cin.tie(nullptr);

    cin >> N;

    rep(i, 1, N){
        cin >> A[i];
    }

    dfs(0, 1);

    cout << st.size() << endl;

    return(0);
}

void dfs(i32 size, i32 depth){
    rep(i, 1, size + 1){
        B[i] += A[depth];
        if(N <= depth){
            calc_xor_sum();
        } else{
            if(i == size + 1){
                dfs(size + 1, depth + 1);
            } else{
                dfs(size, depth + 1);
            }
        }
        B[i] -= A[depth];
    }

    return;
}

void calc_xor_sum(){
    i64 sum = 0;
    rep(i, 1, N){
        sum ^= B[i];
    }
    if(st.count(sum) == 0){
        st.insert(sum);
    }
    return;
}
