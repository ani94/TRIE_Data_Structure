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

vector<string> cache;  // Assuming Average Length to be 8 we will be 
					  //taking maximum length of cache as 10

/* Using cache so that in the case when string length is 20 or something 
 * and is called recently then still it should give result in 
 * O(10) that is constant which makes it independent of the the length
 * of the string. In Cache I am storing only those string whose length 
 * are greater than the average length because otherwise trie would 
 * be a better choice*/

int main()
{
	LL T;
	LL N,i,L,flag;
	char str[20];
	pf("Enter number of test cases\n");
	sl(T);
	while(T--)
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
			/* Converting string to Lower case */
			{
				str[i] = tolower(str[i]);
			}
			L=strlen(str);
			tail=head;
			for(i=0;i<L;i++) 
			/* Using L instead of strlen(str) to make code faster else 
			 * it need to compute string length again and again */
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
		cache.clear(); // Clearing out the cache
		LL cachelen=1;
		LL search;
		pf("Enter number of searches\n");
		sl(search);
		while(search--)
		{
			pf("Enter the word you want to search\n");
			ss(str);
			for(i = 0; str[i]; i++)
			/* Converting string to Lower case */
			{
				str[i] = tolower(str[i]);
			}
			string st=str;
			tail=head;
			L=strlen(str); // Length of string
			flag=0; // Initializing Flag value
			if(L>=10)
			{
				if(cache.size()<10)
				{
					cache.pb(st);
					cachelen+=1;
					cachelen%=10;
				}
				else
				{
					cache[cachelen]=st;
					cachelen+=1;
					cachelen%=10;
				}
				ITER(i,cache)
				{
					if(*i==str)
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
			{
				for(i=0;i<L;i++)
				/* Using L instead of strlen(str) to make code faster else 
				* it need to compute string length again and again */
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
			}
			if(flag==1)
			pf("String found\n");
			else
			pf("String Not found\n");
		}
	}
	return 0;
}
