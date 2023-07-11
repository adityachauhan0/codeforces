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

bool ispalin(st s){
    st r = s;
    reverse(r.begin(),r.end());
    if (r == s) return true;
    else return false;
}

void solve () 
{
    st s; cin >> s;
    ll n = s.size();
    while (ispalin(s)){
        if (s.size() > 1)
        s.erase(s.begin());
        else break;
    }
    if (s.size() == 1) cout << -1 << endl;
    else cout << s.size() << endl;
    
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