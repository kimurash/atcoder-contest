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

    i32 N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<i32> zero, one;

    i32 idx = 0;
    i32 one_cnt = 0;
    while(idx < N){
        char num = S[idx];
        i32 run_len = 0;
        while(idx < N && S[idx] == num){
            run_len++;
            idx++;
        }

        if(num == '0'){
            if(one_cnt == K){
                zero[zero.size() - 1] += run_len;
            } else{
                zero.push_back(run_len);
            }
        }else{
            one_cnt++;
            if(one_cnt == K){
                one[one.size() - 1] += run_len;
            } else{
                one.push_back(run_len);
            }
        }
    }

    uint32_t i = 0;
    uint32_t j = 0;
    char now = S[0];
    while(i < zero.size() || j < one.size()){
        if(now == '0'){
            rep(k, 1, zero[i]){
                cout << '0';
            }
            i++;
            now = '1';
        } else{
            rep(k, 1, one[j]){
                cout << '1';
            }
            j++;
            now = '0';
        }
    }
    cout << endl;

    return(0);
}
