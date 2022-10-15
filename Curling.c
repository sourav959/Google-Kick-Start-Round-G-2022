#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
const ll N=1e5; 
ll sz[N]; 
ll parent[N]; 
void make(ll n) 
{ 
    sz[n]=1; 
    parent[n]=n; 
} 
ll find(ll n) 
{ 
    if(parent[n]==n) 
    { 
        return parent[n]; 
    } 
    else 
    { 
        return parent[n]=find(parent[n]); 
    } 
} 
void Union(ll a,ll b) 
{ 
    a=find(a); 
    b=find(b); 
    if(a!=b) 
    { 
        // if(sz[a]<sz[b]) 
        // { 
        //     swap(a,b); 
        // } 
        parent[b]=a; 
        sz[a]+=sz[b]; 
    } 
} 
int main() 
{ 
    ll tcg; 
    cin>>tcg; 
    for(ll k=1;k<=tcg;k++) 
    { 
        ll hgh1=0,hgh2=0; 
        ll rad1,rad2; 
        ll n; 
        ll m; 
        cin>>rad1>>rad2; 
        cin>>n; 
        vector<ll> vall1; 
        vector<ll> vall2; 
        // vector<pair<ll,ll>>arr(n); 
        for(ll i=0;i<n;i++) 
        { 
            ll x,y; 
            cin>>x>>y; 
            ll g1=x*x,g2=y*y,g3=(rad1+rad2); 
            ll val1=g1+g2; 
            ll val2=g3*g3; 
            if(val1<=val2) 
            { 
                vall1.push_back(val1); 
            } 
        } 
        cin>>m; 
        for(ll i=0;i<m;i++) 
        { 
            ll x,y; 
            cin>>x>>y; 
            ll val1=x*x+y*y; 
            ll val2=(rad1+rad2)*(rad1+rad2); 
            if(val1<=val2) 
            { 
                vall2.push_back(val1); 
            } 
        } 
        sort(vall1.begin(),vall1.end()); 
        sort(vall2.begin(),vall2.end()); 
        if(vall2.size()==0) 
        { 
            cout<<"Case #"<<k<<": "<<vall1.size()<<" "<<vall2.size()<<'\n'; 
        } 
        else if(vall1.size()==0) 
        { 
            cout<<"Case #"<<k<<": "<<vall1.size()<<" "<<vall2.size()<<'\n'; 
        } 
        else 
        { 
            for(ll i=0;i<vall1.size();i++) 
            { 
                int lwd1 =lower_bound(vall2.begin(),vall2.end(),vall1[i])-vall2.begin(); 
                if(lwd1==0) 
                { 
                    // cout<<lwd1<<'\n'; 
                    hgh1++; 
                } 
            } 
            for(ll i=0;i<vall2.size();i++) 
            { 
                int lwd1 =lower_bound(vall1.begin(),vall1.end(),vall2[i])-vall1.begin(); 
                // cout<<lwd1<<'\n'; 
                if(lwd1==0) 
                { 
                    hgh2++; 
                } 
            } 
            cout<<"Case #"<<k<<": "<<hgh1<<" "<<hgh2<<'\n'; 
        } 
        // cout<<"Case #"<<k<<": "<<cnt<<'\n'; 
    }     
}
