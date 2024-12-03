#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> dis(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            dis[i]=abs(v[i]-(i+1));
        }
        // for(int x:dis) cout<<x<<" ";
        int k=dis[0];
        for(int i=1;i<n;i++){
            k=__gcd(k,dis[i]);
            if(k==1) break;
        }
        cout<<k<<endl;
    }
    return 0;
}
/*
so we need to find the difference of v[i] & i(for 1 base index)/
i+1(for 0 base index)
that distance vector will have every difference. Now we need to
find the k value which can be find by the GCD value of all 
element of the vector. 
suppose: 
n->  7
v->  4 2 6 7 5 3 1
idx->1 2 3 4 5 6 7
dis->3 0 3 3 0 3 6

in that distance vector [3 0 3 3 0 3 6],
we can see that every 0 means they got their original place where
they should stay. others need to be move around to become 0. 
now if we move 7th index to 4th index, then it's value will be 
decreased & 4th index to 7th, that will also decrease. 
new vector will be [3 0 3 '3' 0 3 '0']
now if we switch 1st with 4th & 3rd with 6th, we will get
['0' 0 '0' '0' 0 '0' 0]
hence the whole distance become 0. now we saw 3,6 as distance
vector's element(apart from 0). And the divisible of this 
vector is 3(which is the switching gap that we took!). 
So this is the K's value & this is why we needed GCD.
*/