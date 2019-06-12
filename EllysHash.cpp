#include <bits/stdc++.h>
using namespace std;
// https://community.topcoder.com/stat?c=problem_statement&pm=15435 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end() 
#define allr(v) v.rbegin(),v.rend() 
#define endl '\n'  
typedef  long long ll; 
typedef  unsigned long long ull; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=1000000000000037;
const ll inf=1000000000000037;


class 	EllysHash
{
public:

	long long getHash(int N, string A, string B, string C)
	{
		vector<ll> left;
		if(N==1)
		{
			ll ans=0;
			ans=min({A[0]-'A'+65,B[0]-'A'+65,C[0]-'A'+65});
			return ans;
		}
		string a,b,c;
		a=A.substr(0,N/2);
		b=B.substr(0,N/2);
		c=C.substr(0,N/2);
		A=A.substr(N/2);
		B=B.substr(N/2);
		C=C.substr(N/2);	
		ll j=a.size();
		ll mask=1;
		while(j--) mask*=3;
		ll pwr=1;
		j=A.size();
		while(j--)
		{
			pwr*=127;
			pwr%=mod;
		}
		for(ll i=0;i<mask;i++)
		{
			ll temp=0;
			ll now=i;
			for( j=0;j<(ll)a.size();j++)
			{
				if(now%3 == 0)
				{
					
					temp=((temp*127)%mod+((a[j]-'A'+65)*pwr)%mod)%mod;
				}
				else if(now%3 == 1)
				{
					
					temp=((temp*127)%mod+((b[j]-'A'+65)*pwr)%mod)%mod;
				}
				else if(now%3 == 2)
				{
					
					temp=((temp*127)%mod+((c[j]-'A'+65)*pwr)%mod)%mod;
				}	
				now/=3;							
			}
			left.pb(temp);
		}
		//check(A);check(a);
		sort(all(left));
		j=A.size();
		mask=1;
		while(j--) mask*=3;
		ll ans=inf;
		for(ll i=0;i<mask;i++)
		{
			ll temp=0;
			ll now=i;
			for( j=0;j<(ll)A.size();j++)
			{
				if(now%3 == 0)
				{
					temp=((temp*127)%mod+(A[j]-'A'+65))%mod;
				}
				else if(now%3 == 1)
				{
					temp=((temp*127)%mod+(B[j]-'A'+65))%mod;
				}
				else if(now%3 == 2)
				{
					temp=((temp*127)%mod+(C[j]-'A'+65))%mod;
				}	
				now/=3;							
			}

			ll temp2=(mod-1ll-temp);
			auto it=upper_bound(all(left),temp2);
			if(it!=left.end()) ans=min(ans,(temp+(*it))%mod);
			else ans=min(ans,(temp+(left[0]))%mod);
		}		
		return ans;

	}
	
};

int main()
{
	boost;
	EllysHash c1;
	ll x;
	string a,b,c;
	cin>>x>>a>>b>>c;
	cout<<c1.getHash(x,a,b,c)<<endl;

  	return 0;
}  
