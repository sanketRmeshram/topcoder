#include <bits/stdc++.h>
using namespace std;
typedef  long long ll; 
// https://community.topcoder.com/stat?c=problem_statement&pm=2013
class 	Deranged
{
public:
	ll numDerangements(vector<int> nums)
	{
		ll n=nums.size();
		std::vector<ll> v(n,0);
		for(ll i=0;i<n;i++) v[nums[i]]++;
		ll fact[n+1];
		fact[0]=1;
		for(ll i=1;i<=n;i++) fact[i]=i*fact[i-1];
		ll ans=0;
		ll mask=(1ll<<n);
		for(ll i=1;i<mask;i++)
		{
			std::vector<ll> temp(n,0);
			ll k=0;
			for(ll j=0;j<n;j++)
			{
				if(i & (1ll<<j))
				{
					temp[nums[j]]++;
					k++;
				}
			}
			ll count=fact[n-k];
			for(ll j=0;j<n;j++)
			{
				count/=fact[v[j]-temp[j]];
				//count*=((fact[v[j]]/fact[temp[j]])/fact[v[j]-temp[j]]);
			}

			if(k%2)
			{
				ans+=count;
			}
			else
			{
				ans-=count;
			}

		}
		for(ll i=0;i<n;i++) fact[n]/=fact[v[i]];
		return fact[n]-ans;	
	}
	
};
