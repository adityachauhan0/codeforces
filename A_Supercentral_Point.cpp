#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define st string
#define vi vector<ll>
#define li list<ll>
using namespace std;

void solve () 
{
    ll n;
    cin >> n;
    vector<vi> points = {};
    for (ll i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        points.push_back({x,y});
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++){
        vi l1 = points[i]; //1 1
        bool up = false;
        bool low = false;
        bool right = false;
        bool left = false;
        for (ll j = 0; j < n; j++){
            if (i != j){
                if (points[i][0] == points[j][0]){
                    if (points[i][1] < points[j][i]){
                        up = true;
                    }
                    else if (points[i][1] > points[j][i]){
                        low = true;
                    }
                }
                else if (points[i][1] == points[j][1]){
                    if (points[i][0] < points[j][0]){
                        right = true;
                    }
                    else if (points[i][1] > points[j][i]){
                        left = true;
                    }
                }
            }
        }
        if (up && low && right && left){
            cnt ++;
        }

    }
    cout << cnt << endl;
    
}

int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // ll tt;
    // cin >> tt;
    // while (tt--) 
    solve(); 
    return 0;
}  