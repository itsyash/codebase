#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL unsigned long long
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 100000000
using namespace std;
int N, K, M;
vector<pair<int, PII> > v;
int dp[22][54][102][2];
int next[22][54][102][2];
 
int solve(int day, int last, int money, int bit)
{
	if(day >= K)
	{
		return 0;
	}
	//cout<<day<<" "<<last<<" "<<money<<" "<<bit<<endl;
	int i, j, k;
	int &ret = dp[day][last][money][bit];
	if(ret != -1)
		return ret;
	ret = -1000000000;
	int &nxt = next[day][last][money][bit];
	for(i = 0; i < N; i++)
	{
		int cost = v[i].second.first;
		int benefit = v[i].second.second;
		//cout<<cost<<" "<<benefit<<endl;
		if(cost > money)
			break;
		int x;
		if(i != last)
		{
			x = solve(day + 1, i, money - cost, 0) + benefit;
		}
		else 
		{
			if(bit == 0)
			{
				x = solve(day + 1, i, money - cost, 1) + benefit / 2;
			}
			else
			{
				x = solve(day + 1, i, money - cost, 1);
			}
		}
		if(x > ret)
		{
			ret = x;
			nxt = i;
		}
	}
	return ret;
}
struct cmp
{
	bool operator()(pair<int, PII> p1, pair<int, PII> p2)
	{
		if(p1.second.first < p2.second.first)
			return true;
		else if(p1.second.first == p2.second.first && p1.second.second < p2.second.second)
			return true;
		return false;
	}
};
int main()
{
	while(1)
	{
		scanf("%d%d%d", &K, &N, &M);
		if(N == 0 && K == 0 && M == 0)
			break;
		CLRM(dp);
		CLRM(next);
		int i, j, k;
		v.clear();
		for(i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			pair<int, PII> p = MP(i, MP(a, 2 * b));
			v.PB(p);
		}
		sort(ALL(v), cmp());
		int ans = -1000000000;
		ans = solve(0, 53, M, 0);
		ans = max(0, ans);
		double a = ans / 2.0;
		printf("%0.1lf\n", a);		
		if(ans == 0)
		{
			continue;
		}
		int curd, curl, curm, curb;
		curd = 0, curl = 53, curm = M, curb = 0;
		while(next[curd][curl][curm][curb] != -1)
		{
			printf("%d ", v[next[curd][curl][curm][curb]].first + 1);
			int idx = next[curd][curl][curm][curb];
			int prel = curl;
			curd = curd + 1;
			curl = idx;
			curm = curm - v[idx].second.first;
			curb = (prel == idx? 1 : 0);
		}
		printf("\n");
	}
	return 0;
}
