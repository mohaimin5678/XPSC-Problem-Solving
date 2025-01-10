#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int h,n;
    cin>>h>>n;
    vector<ll> a(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>c[i];

    auto check=[&](ll turns){
        ll dam=0;
        for(int i=0;i<n;i++){
            ll cnt=ceil(turns*1.0/c[i]);
            if(cnt>=h) return true;
            dam+=(cnt*a[i]);
        }
        
        return dam>=h;
    };

    ll l=1,r=4e10,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
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
    return 0;
}
/*
at first I tried to jump based on when the next time a[i] will 
attack but that didn't help on this case: 
50 3
5 6 7
5 6 7
why? because when all 3 first attacked, I tried to jump on the
next time a[0] can attack but on that process I got lost when I
tried to jump on when a[1] can attack. So it was getting tricky. 

So the best way to solve this is going through only 1 loop inside
check function. 
using binary search on answer(which is not actually necessary for
this problem but still done that) I passed the turns on check 
function & if it returns true then I checked if its possible to
minimize the answer by going left. Else I went right. 

now inside check function, I calculated how many times the elements
of A will occure on the give turns number. 
We all know that on first turn we'll put all of our attack so 
except that part, based on the cooldown the attacks can be done
in different time. 
So what i did is: cnt= turns/c[i] & dam+=cnt*a[i]
suppose they provided me 15 then a[0] will appear on 1,6,11=3 times
all these 3 time it will damage 3*a[0]=15 
same for a[1], appearence: 1,7,13 = 3 times & damage=3*6=18
same for a[2], appearence: 1,8,15 = 3 times & damage=3*7=21
total damage= 15+18+21=54 > 50 
means boss can be beaten by these amount of turns. 
now 15/3=3 , ceil value of (15/6) & (15/7) are also 3
thats how we counted the amount of times a[i] can be used on these
turns. then if the damage>h then return true; 

*/
