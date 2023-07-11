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
    ll n,m; cin >> n >> m;
    vi b(m);
    vi h = {};
    for (ll &i : b) cin >> i;
    vi a = {};
    for (ll i = n; i >= 1; i--){
        a.pb(i);
    }
    map <ll,ll> removed;
    ll in = 0;
    for (ll i = 0; i < m; i++){
        if (in == n) break;
        if (!count(h.begin(),h.end(),b[i])){
            removed[a[in]] = i+1;
            in++;
        }
        h.push_back(b[i]);
    }
    reverse(a.begin(),a.end());
    for (ll i : a) {
        if (removed[i]) cout << removed[i] << " ";
        else cout << -1 << " ";
    }
    cout << endl;
    

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