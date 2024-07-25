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

i64 pow10(int x) {
    return x == 0 ? 1 : pow10(x - 1) * 10;
}

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    if(N == 1){
        cout << 0 << endl;
        return(0);
    }

    N--;

    i64 digit = 1;
    while(true){
        i64 x = (digit - 1) / 2;
        i64 total = 9 * pow10(x);
        if(total < N){
            N -= total;
            digit++;
        } else{
            string left = to_string(pow10(x) + (N - 1));

            i64 len = left.size();
            if(digit & 1){ // 奇数桁
                len--;
            }
            string right = left.substr(0, len);
            reverse(all(right));

            cout << left + right << endl;
            break;
        }
    }

    return(0);
}
