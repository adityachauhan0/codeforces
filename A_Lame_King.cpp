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
    ll a = min(abs(x),abs(y)), b = max(abs(x),abs(y));
    ll mov = 0;
    mov += 2*a;
    b -= a;
    if (b != 0) mov++,b--;
    mov += 2*b;
    
    cout << mov << endl;
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