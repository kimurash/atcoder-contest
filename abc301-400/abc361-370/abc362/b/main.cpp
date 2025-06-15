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

i32 calc_len(i32 x1, i32 y1, i32 x2, i32 y2){
    i32 dx = abs(x1 - x2);
    i32 dy = abs(y1 - y2);
    return(dx * dx + dy * dy);
}

int main(){
    cin.tie(nullptr);

    i32 x1, y1;
    i32 x2, y2;
    i32 x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    i32 len1 = calc_len(x1, y1, x2, y2);
    i32 len2 = calc_len(x2, y2, x3, y3);
    i32 len3 = calc_len(x3, y3, x1, y1);

    if(len1 + len2 == len3 || len2 + len3 == len1 || len3 + len1 == len2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return(0);
}
