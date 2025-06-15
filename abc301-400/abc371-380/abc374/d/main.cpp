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

typedef struct coord{
    i32 x;
    i32 y;
} Coord;

typedef struct line{
    Coord edge1;
    Coord edge2;
    double draw_time;
} Line;

i32 N, S, T;
double ans = 20000 * 6;
vector<Line> lines;

i32 perm[10];

void draw(i32 idx, Coord *pos, double time);
double dist(Coord *a, Coord *b);

int main(){
    cin.tie(nullptr);

    cin >> N >> S >> T;

    i32 A, B, C, D;
    rep(i, 1, N){
        cin >> A >> B >> C >> D;
        Coord edge1 = {A, B};
        Coord edge2 = {C, D};
        double draw_time = dist(&edge1, &edge2) / T;
        lines.push_back({edge1, edge2, draw_time});
    }

    rep(i, 0, N - 1){
        perm[i] = i;
    }

    Coord start = {0, 0};
    do{
        draw(0, &start, 0.0);
    } while(next_permutation(perm, perm + N));

    cout << fixed << setprecision(10) << ans << endl;
    return(0);
}

void draw(i32 depth, Coord *pos, double total_time){
    if(N <= depth){
        ans = min(ans, total_time);
        return;
    }

    i32 idx = perm[depth];
    Coord edge1 = lines[idx].edge1;
    Coord edge2 = lines[idx].edge2;

    total_time += lines[idx].draw_time;

    // 端点1に移動
    double move_time = dist(pos, &edge1) / S;
    draw(depth + 1, &edge2, total_time + move_time);

    // 端点2に移動
    move_time = dist(pos, &edge2) / S;
    draw(depth + 1, &edge1, total_time + move_time);

    return;
}

double dist(Coord *a, Coord *b){
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
