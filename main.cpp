/*
Author : Tushar Makkar (tusharmakkar08) 
*/

// Libraries 

#include <list>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>

// Definitions 

//Constants
#define mod 1000000007

// Input Output
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define pf printf
#define pl(n) 					printf("%lld\n",n)
#define pb push_back

// function Definition
#define maX(i,j) (i>j?i:j)
#define miN(i,j) (i<j?i:j)
#define mset(x,v) memset(x,v,sizeof(x))
#define FOR(i,a,b) for(LL i=(LL)(a);i<(LL)(b);i++)
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define REV(i,a,b) for(LL i=(LL)(a);i>=(LL)(b);i--)
#define foreach(v, c)     for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define checkbit(n,b)                ( (n >> b) & 1)

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

//Debugging
#define dbgarr(a,m,n)				FOR(i,m,n)pf("%lld ",a[i])
#define dbgmat(a,m,n,k,l)			FOR(i,m,n){FOR(j,k,l)pf("%lld ",a[i]);pf("\n")}

using namespace std;

// Variables type
#define LL long long int
typedef vector < LL > row;
typedef vector < row > matrix;

struct trie
{
	trie *next[10];
	bool end;
	trie()
	{
		for(int i=0;i<10;i++)
		next[i]=NULL;
		end=0;
	}
};

int main()
{
	LL T;
	bool flag;
	sl(T);
	char str[20];
	while(T--)
	{
		flag=1;
		LL N,i;
		trie *head,*tail;
		head=new trie;
		sl(N);
		while(N--)
		{
			ss(str);
			if(flag)
			{
				tail=head;
				for(i=0;i<strlen(str);i++)
				{
					if(tail->end)
					{
						flag=0;
						break;
					}
					LL p=str[i]-'0';
					if(tail->next[p]==NULL)
						tail->next[p]=new trie;
					tail=tail->next[p];
				}
				tail->end=1;
				for(i=0;i<10;i++)
				{
					if(tail->next[i])
					{
						flag=0;
						break;
					}
				}
			}
		}
		if(flag)
		pf("YES\n");
		else
		pf("NO\n");
	}
	return 0;
}
