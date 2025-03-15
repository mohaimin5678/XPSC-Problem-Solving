#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=2e5+9;
ll a[maxN], t[4*maxN];
void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];      //node e a[b]/a[e] er value boshay dibo
        return;         
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=max(t[l],t[r]);     
    //we are holding the max value of the children on parent node
}

void update(int n,int b,int e,int i,int j){    
    if(e<i || b>j){   //"out of" segment
        return; 
    }
    if(t[n]<10) return;
    //proportionally this will work for max(l,r). Because if there
    //is a node which we need to change will go higher & it will
    //help us to do the operation more quickly than before

    if(b>=i && e<=j && b==e){   //"inside" segment
        int val=t[n];
        int res=0;
        while(val>0){
            res+=(val%10);
            val/=10;
        }
        t[n]=res;
        return;   
    }
    // if(b==e){
        
    // }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    t[n]=max(t[l],t[r]);
}

ll query(int n,int b,int e,int i){
    if(i<b || i>e){
        return 0;     //"out of" segment
    }
    if(b==e){
        return t[n];  //"inside" segment
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    if(i<=mid) return query(l,b,mid,i); 
    //since its a single index, so if its inside left portion then
    //we'll only go to the left part & this will reduce recursion calls
    return query(r,mid+1,e,i);
    //else we'll go to the right part
}
void mohaimin(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int ty;
        cin>>ty;
        if(ty==1){
            int l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else{
            int idx;
            cin>>idx;
            ll ans=query(1,1,n,idx);
            cout<<ans<<ln;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}