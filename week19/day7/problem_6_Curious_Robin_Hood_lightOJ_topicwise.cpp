#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
int a[maxN], t[4*maxN];
void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];      //initially all 0 node e save hocche
        return;         
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=t[l]+t[r];     
}
void update(int n,int b,int e,int i,int v,int type){     //O(logN)
    if(i<b || i>e){
        return;     //"out of" segment
    }
    if(b==e){
        if(type==1) t[n]=0;
        else t[n]=t[n]+v;  
        return;  //"inside" segment
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,v,type);
    update(r,mid+1,e,i,v,type);
    t[n]=t[l]+t[r];
}
void find(int n,int b,int e,int i){
    if(i<b || i>e){
        return;     //"out of" segment
    }
    if(b==e){
        cout<<t[n]<<ln; 
        return;  //"inside" segment
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    find(l,b,mid,i);
    find(r,mid+1,e,i);
}
int query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return 0; 
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j);
}
void mohaimin(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int idx;
            cin>>idx;
            idx++;
            find(1,1,n,idx);    //direct a[idx] is not working so
            update(1,1,n,idx,0,1);  
            //after printing just make it 0
        }
        else if(t==2){
            int idx,v;
            cin>>idx>>v;
            idx++;
            update(1,1,n,idx,v,2);
        }
        else if(t==3){
            int l,r;
            cin>>l>>r;
            l++,r++;
            int ans=query(1,1,n,l,r);
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
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<ln;
        mohaimin();
    }
}