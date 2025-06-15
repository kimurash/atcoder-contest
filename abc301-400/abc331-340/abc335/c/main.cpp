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

typedef pair<int32_t, int32_t> pi32;

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N, Q;
    cin >> N >> Q;

    deque<pi32> pos;
    rep(i, 1, N){
        pos.push_back(make_pair(i, 0));
    }

    i32 qno;
    rep(i, 1, Q){
        cin >> qno;
        if(qno == 1){
            char dir;
            cin >> dir;

            pi32 head = pos.front();
            switch(dir){
                case 'R':
                    head.first++;
                    break;
                case 'L':
                    head.first--;
                    break;
                case 'U':
                    head.second++;
                    break;
                case 'D':
                    head.second--;
                    break;
            }
            pos.push_front(head);
            pos.pop_back();
        } else{
            i32 p;
            cin >> p; p--;
            printf("%d %d\n", pos[p].first, pos[p].second);
        }
    }

    return(0);
}