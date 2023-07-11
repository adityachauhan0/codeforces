#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define st string
#define vi vector<ll>
#define li list<ll>
#define pb push_back
#define endl "\n"
#define vp vector<pair<ll,ll>>
using namespace std;

void solve () 
{
    ll x,y; cin >> x >> y;
    ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    ll moves1 = 4, moves2 = 4;
    if (min(x1-1, x - x1) == 0) moves1--;
    if (min(y1-1,y-y1) == 0) moves1--;
    if (min(x2-1, x - x2) == 0) moves2--;
    if (min(y2-1,y-y2) == 0) moves2--;
    cout << min(moves1,moves2) << endl;
}

int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) 
        solve(); 
    return 0;
}  