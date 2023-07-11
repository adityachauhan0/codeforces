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
    ll a,b; cin >> a >> b;
    
    if (__gcd(a,b) == 1){
        cout << 1 << endl;
        cout << a << " " << b << endl;
    }
    else {
        cout << 2 << endl;
        ll x = 1000000, y = 1000000;
        while (__gcd(x,y) != 1 && __gcd(a-x,b-y) != 1) {
            y--;
        }
        cout << x << " " << y << endl;
        cout << a << " " << b << endl;
    }
    
    
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