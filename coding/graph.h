#include<iostream>
#include<stdio.h>

#include<vector>
#include<queue>
#include<memory>
#include<deque>

using namespace std;


struct VertexNode
{
	bool visited;
	int d;
	int data;
	VertexNode* p;
	vector<VertexNode*> adj;

	VertexNode(int x):visited(false), d(0), data(x), p(NULL){
		adj.clear();
	}
	VertexNode():visited(false), d(0), data(0), p(NULL){}
};

struct GraphNode
{
	vector<VertexNode*> vertexs;
	GraphNode() {
		vertexs.clear();
	}
};

void BFS(GraphNode* graph, VertexNode* s = NULL);
void BFS_search(GraphNode* graph, int key, VertexNode* s = NULL);

void DFS(GraphNode* graph, VertexNode* s = NULL);
void DFS_search(GraphNode* graph, int key, VertexNode* s = NULL);

void reset_graph(GraphNode* graph);


void graph_test();