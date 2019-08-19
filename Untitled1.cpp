#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std; 
int military[1004]={0};	
int cache[1004][1004]={0},certificate[1004][1004]={0}; 
vector<int> con,non_con;
vector<pair<int,int>> hole[1004];
int dfs(int x , int y)
{
	if(x>=y)swap(x,y);
	if(military[x]==1 && military[y]==1)return 1; 
	int &ret = cache[x][y];
	if(ret!=-1)return cache[x][y]; 
	ret=0; 
	for(int i=0; i<hole[x].size(); i++) 
	{
		for(int j=0; j<hole[y].size(); j++)
		{
			if(hole[x][i].second==hole[y][j].second)
			{
				ret=dfs(hole[x][i].first,hole[y][j].first);
				if(ret==1)break;   
			}
		}
		if(ret==1)break; 
	}
	return ret; 
}
int main()
{
	int n,w,c,h,m;
	scanf("%d %d %d %d %d\n",&n,&w,&c,&h,&m);
	int temp[1004]={0};
	for(int i=0; i<h; i++)
	{
		int a;
		scanf("%d",&a);
		temp[a]=1; 	
	}
	
	for(int i=0; i<n; i++)
	{
		if(temp[i]==1)con.push_back(i);
		else non_con.push_back(i); 
	}
	for(int i=0; i<m; i++)
	{
		int a;
		scanf("%d",&a);
		military[a]=1; 
	}
	memset(cache,-1,sizeof(cache)); 
	for(int i=0; i<w; i++)
	{
		int a,b,c; 
		scanf("%d %d %d",&a,&b,&c);
		hole[a].push_back(make_pair(c,b)); 
	}
	int x; 
	for(int i=0; i<con.size(); i++)
	{
		for(int j=0; j<non_con.size(); j++)
		{
			x = dfs(con[i],non_con[j]);
			if(x)break; 
		}
		if(x)break; 
	}
	if(x)printf("YES");
	else printf("NO");
}
