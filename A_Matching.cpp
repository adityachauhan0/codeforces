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
    st s;
    cin >> s;
    ll n = s.size();
    ll ans = 1;
    for (ll i = 1; i < n; i++){
        if (s[i] == '?') {
            ans *= 10;
            }
    }
    if (s[0] == '?'){
        ans *= 9;
        }
    if (s[0] == '0') cout << 0 << endl;
    else  cout << ans << endl;
    
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