#include<iostream>
#include <queue>
using namespace std;
class Graph{
	public:
		int adjmatrix[20][20];
		int vertices;
		
		Graph()
		{
			cout<<"\n enter the no of vertices:";
			cin>>vertices;
			if(vertices>20)
			cout<<"\n out of limit";
			else
			{
				for(int i=0;i<=vertices;i++)
				{
					for(int j=0;j<=vertices;j++)
					adjmatrix[i][j]=0;
				}
			}
		}
		void insertedge();
		void bfs(int start);
		void dfs(int start);
};
void Graph::dfs(int start)
{
	
     
    static int visited[20];

	int j;
	if(visited[start]==0)
	{
		cout<<start<<" ";
		visited[start]=1;
		for(j=1;j<=vertices;j++)
		{
			if(adjmatrix[start][j]==1 && visited[j]==0)
			dfs(j);
		}
	}
}
void Graph::insertedge()
{
	int v1;
	int v2;
	cout<<"\n enter the vertex:";
	cin>>v1;
	cout<<"\n enter adjacency vertex:";
	cin>>v2;
	adjmatrix[v1][v2]=1;
	cout<<"\n edge is created"<<endl;
}
void Graph::bfs(int start)
{
	queue<int> myQueue;
	int i=start,j;
	int visited[vertices+1]={0};
	cout<<i<<" ";
	visited[i]=1;
	myQueue.push(i);
	while(!myQueue.empty())
	{
		i=myQueue.front();
        myQueue.pop();
		for(j=1;j<=vertices;j++)
		{
			if(adjmatrix[i][j]==1&&visited[j]==0)
			{
				cout<<j<<" ";
				visited[j]=1;
				myQueue.push(j);
			}
		}
	}
}
int main()
{
	Graph g;
	cout<<"\n 1.insert a edge"<<endl;
	cout<<"\n 2.breadth first search"<<endl;
	cout<<"\n 3.depth first search"<<endl;
	int m=1,choice;
	while(m)
	{
		cout<<"\nenter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: g.insertedge();
			        break;
			case 2:int v;
			       cout<<"\n enter start vertex:";
			       cin>>v;
			       g.bfs(v);
			       break;
			case 3:int k;
			       cout<<"\n enter start vertex:";
			       cin>>k;
			       g.dfs(k);
			       break;
			case 4:cout<<"\n exiting the program";
			       m=0;
			       break;
		}
	}
	
 return 0;
 	
}
