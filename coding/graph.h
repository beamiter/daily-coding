#include<iostream>
#include<stdio.h>

#include<vector>
#include<queue>
#include<memory>

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
};

struct GraphNode
{
	vector<VertexNode*> vertexs;
	GraphNode() {
		vertexs.clear();
	}
};

void BFS(GraphNode* graph);


void graph_test();