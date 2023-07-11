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
    char d;
    cin >> n >> d;
    st s; cin >> s;
    bool flag = true;
    for (char i : s){
        if (i < d && flag){
            cout << d << i;
            flag = false;
        }
        else cout << i;
    }
    if (flag) cout << d;
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