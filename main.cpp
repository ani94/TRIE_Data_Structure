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
	/* Structure of Trie Consisting of consisting of 26 pointers ,
	 *  one for each charachter and end denoting whether it is end or not
	 */
	trie *next[26];
	bool end;
	trie()
	{
		for(int i=0;i<26;i++)
		next[i]=NULL;
		end=0;
	}
};

int main()
{
	LL T;
	LL N,i,L,flag;
	char str[20];
	while(1)
	{
		trie *head,*tail;
		head=new trie;
		pf("Enter number of words or -1 to exit\n");
		sl(N);
		if(N<=0)
		break;
		while(N--)
		{
			ss(str);
			for(i = 0; str[i]; i++)
			{
				str[i] = tolower(str[i]);
			}
			L=strlen(str);
			tail=head;
			for(i=0;i<L;i++)
			{
				char p=str[i]-'a';	
				if((tail->next[p])==NULL)	// Making a new trie if no branch exists
				{
					tail->next[p]=new trie;
				}
				if(i==L-1)
				{
					tail->end=1;
				}
				tail=tail->next[p];
			}
		}
		while(1)
		{
			pf("Enter the word you want to search or -1 to exit\n");
			ss(str);
			if((str[0]=='-')&&(str[1]=='1'))
			break;
			for(i = 0; str[i]; i++)
			{
				str[i] = tolower(str[i]);
			}
			tail=head;
			for(i=0;i<strlen(str);i++)
			{
				flag=0;
				char p=str[i]-'a';
				if(tail->next[p]==NULL)
				{
					flag=-1;
					break;
				}
				if(tail->end)	// Checking whether word found or not
				{
					flag=1;
				}
				tail=tail->next[p];
			}
			if(flag==1)
			pf("String found\n");
			else
			pf("String Not found\n");
		}
	}
	return 0;
}
