//��Ҫʹ��Dijkstra�㷨

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


bool isVis[m];//����bool�����������˱���Ƿ�ڵ㱻���ʹ� 

I64 dist[m];//��¼���·��

I64 sum[m];//sum[i]�����¼�������·������i��β������С·�ĳ����ܺ� 


struct Node{//�ڵ�

	int number;//���ı��

	I64 minLength;//Դ�㵽������̾��� 


	Node(){}

	Node(int number,I64 minLength):number(number),minLength(minLength){}

	bool operator<(const Node &a)const
	{

		return minLength>a.minLength;

	} 

};

struct Edge//��
{ 

	int v,type;//type�ǵ�·������ 

	I64 length;//�����v�ľ���Ϊlength

	Edge(int v,int length,int type):v(v),length(length),type(type){}

}; 

vector<Edge>g[m];//ͼ���ڽӱ� 

 

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

		if(!isVis[number]){//������û�б����� 

			isVis[number]=true;//��Ϊ����

			int num=g[number].size();//��number�ڵ������Ľ���ж��ٸ� 

			for(int i=0;i<num;i++){//�����㱻�����˾����� 

			    int v=g[number][i].v;

				if(isVis[v])

				  continue;

				I64 cost=0;

				if(g[number][i].type){//���number��i��С�� 

				  I64 temp=sum[number]+g[number][i].length;

				  cost=dist[number]-sum[number]*sum[number]+temp*temp;

			    }

				else//number��i�Ǵ��

				  cost=dist[number]+g[number][i].length;

				if(cost<dist[v]){//��������ԭ��С�ͽ��и��²��� 

					dist[v]=cost;//�������·����i��β������С·����

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