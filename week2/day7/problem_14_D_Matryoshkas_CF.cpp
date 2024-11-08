#include<bits/stdc++.h>
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
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[v[i]]!=0){
                int cur=v[i];
                while(mp[cur]>0){
                    // cout<<cur<<" ";
                    mp[cur]--;
                    cur++;
                }
                ans++;
            }
            // cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
testcase:
8
5 15 6 14 8 12 9 11

after sorting:
5 6 8 9 11 12 14 15
inside map: 
5-1
6-1
8-1
9-1
11-1
12-1
14-1
15-1

for(int i=0;i<n;i++){
    if(mp[v[i]]!=0){
        int cur=v[i];
        while(mp[cur]>0){

            mp[cur]--;
            cur++;
        }
        ans++;
    }
}

cur=v[0] means cur=5 & mp[cur]>0 so mp[cur]-- 
now mp[5]=0 & cur++(cur==6)
mp[cur]>0 so mp[cur]-- now mp[6]=0 & cur++(cur==7)
since 7 doesn't exist so mp[cur]==0 & inner loop is done
ans++ because {5,6} is the first set. 

now cur=v[1] means cur=6 but mp[cur]==0 
(because we already used it with 5) so if condition mismatched

now cur=v[2] means cur=8 & mp[cur]>0 so mp[cur]--
now mp[8]=0 & cur++(cur==9)
mp[cur]>0 so mp[cur]-- now mp[9]=0 & cur++(cur==10)
since 10 doesn't exist so mp[cur]==0 & inner loop is done
ans++ because {8,9} is the second set. 

now cur=v[3] means cur=9 but mp[cur]==0 
(because we already used it with 8) so if condition mismatched

now cur=v[4] means cur=11 & mp[cur]>0 so mp[cur]--
now mp[11]=0 & cur++(cur==12)
mp[cur]>0 so mp[cur]-- now mp[12]=0 & cur++(cur==13)
since 13 doesn't exist so mp[cur]==0 & inner loop is done
ans++ because {11,12} is the third set.

now cur=v[5] means cur=12 but mp[cur]==0 
(because we already used it with 11) so if condition mismatched

now cur=v[6] means cur=14 & mp[cur]>0 so mp[cur]--
now mp[14]=0 & cur++(cur==15)
mp[cur]>0 so mp[cur]-- now mp[15]=0 & cur++(cur==16)
since 16 doesn't exist so mp[cur]==0 & inner loop is done
ans++ because {14,15} is the fourth set.

thus the answer is 4. 
*/