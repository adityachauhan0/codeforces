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
    ll n;
    cin >> n;
    st s; cin >> s; 
    char a = s[0];
    vector<st> ans = {};
    for (ll i = 1; i < n; i++){
        st as = "";
        as += a;
        as += s[i];
        ans.push_back(as);
        a = s[i];
    }
    sort( ans.begin(), ans.end() );
    ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
    cout << ans.size() << endl;

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