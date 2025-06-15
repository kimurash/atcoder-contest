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

    string S;
    cin >> S;

    i32 i = 0;

    while(i < S.size() - 1){
        if(S[i] == 'W' && S[i + 1] == 'A'){
            S[i] = 'A';
            S[i + 1] = 'C';

            i32 j = i;
            while(0 < j){
                if(S[j - 1] == 'W' && S[j] == 'A'){
                    S[j - 1] = 'A';
                    S[j] = 'C';
                    j--;
                }else{
                    break;
                }
            }
        }
        i++;
    }

    cout << S << endl;

    return(0);
}
