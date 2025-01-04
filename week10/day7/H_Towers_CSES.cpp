#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        auto it=mp.upper_bound(v[i]);
        if(it==mp.end()){
            mp[v[i]]++;
        }
        else{
            int val=it->first;
            mp[val]--;
            if(mp[val]==0) mp.erase(it);
            mp[v[i]]++;
        }
    }
    int cnt=0;
    for(auto [x,y]:mp){
        cnt+=y;
    }
    cout<<cnt<<endl;
    return 0;
}
/*
here they want to make minimum number of towers where the
values on the top must be lower than the value under it.
for given example: 
5
3 8 2 1 5
the towers are: 
1
2   5
3   8
answer: 2

so what we did here is we took a map & tracked the number of
towers. 
for 3: no upper_bound exists so mp=[3 ]
for 8: no upper_bound exists so mp=[3 8 ]
for 2: upper_bound is 3. So we'll do mp[3]-- which will make
       mp[3]==0 so we'll erase it & put 2 in. so mp=[2 8 ]
for 1: upper_bound is 2. So we'll do mp[2]-- which will make
       mp[2]==0 so we'll erase it & put 1 in. so mp=[1 8 ]
for 5: upper_bound is 8. So we'll do mp[8]-- which will make
       mp[8]==0 so we'll erase it & put 5 in. so mp=[2 5 ]

after that we'll just count the occurence of all mp's value. 
And that will be the answer.
*/

//this problem can be solved by vector more easily.
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, temp;
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		auto it = upper_bound(v.begin(),v.end(), temp);
		if (it == v.end())
		{
			v.push_back(temp);
		}
		else
        {
            *it = temp;
        }
	}
	cout << v.size() << endl;
    return 0;
}
*/