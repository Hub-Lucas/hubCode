//主要使用Dijkstra算法

/*
input
6 7
1 1 2 3
1 2 3 2
0 1 3 30
0 3 4 20
0 4 5 30
1 3 5 6
1 5 6 1
output
76
*/
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

typedef __int64 I64;

const int m=120;

I64 INF=1e18;


bool isVis[m];//声明bool类型数组用了标记是否节点被访问过 

I64 dist[m];//记录最短路径

I64 sum[m];//sum[i]数组记录的是最短路径中以i结尾的连续小路的长度总和 


struct Node{//节点

	int number;//结点的编号

	I64 minLength;//源点到结点的最短距离 


	Node(){}

	Node(int number,I64 minLength):number(number),minLength(minLength){}

	bool operator<(const Node &a)const
	{

		return minLength>a.minLength;

	} 

};

struct Edge//边
{ 

	int v,type;//type是道路的类型 

	I64 length;//到结点v的距离为length

	Edge(int v,int length,int type):v(v),length(length),type(type){}

}; 

vector<Edge>g[m];//图的邻接表 

 

void Dijkstra(int s,int n)

{

	priority_queue<Node>q;

	memset(isVis,false,sizeof(isVis));

	memset(sum,0,sizeof(sum));

	for(int i=1;i<=n;i++)

	  dist[i]=INF;

	dist[0]=dist[s]=0;

	q.push(Node(s,0));

	while(!q.empty()){

		Node e=q.top();

		q.pop();

		int number=e.number;

		if(!isVis[number]){//如果结点没有被访问 

			isVis[number]=true;//改为访问

			int num=g[number].size();//和number节点相连的结点有多少个 

			for(int i=0;i<num;i++){//如果结点被访问了就跳过 

			    int v=g[number][i].v;

				if(isVis[v])

				  continue;

				I64 cost=0;

				if(g[number][i].type){//如果number到i是小道 

				  I64 temp=sum[number]+g[number][i].length;

				  cost=dist[number]-sum[number]*sum[number]+temp*temp;

			    }

				else//number到i是大道

				  cost=dist[number]+g[number][i].length;

				if(cost<dist[v]){//如果距离比原来小就进行更新操作 

					dist[v]=cost;//更新最短路中以i结尾的连续小路长度

					if(g[number][i].type) 

					  sum[v]=sum[number]+g[number][i].length;

					else

					  sum[v]=0;

					q.push(Node(v,cost));

				}

			}

		}

	}

}

 

int main()

{

	int n,m,t,a,b,c;

	scanf("%d%d",&n,&m);

	while(m--){

		scanf("%d%d%d%d",&t,&a,&b,&c);

		g[a].push_back(Edge(b,c,t));

		g[b].push_back(Edge(a,c,t));

	}

	Dijkstra(1,n);

	printf("%I64d\n",dist[n]);

	return 0;

}