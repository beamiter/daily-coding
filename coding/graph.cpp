#include "pch.h"


void BFS(GraphNode* graph) {
	if (!graph || graph->vertexs.empty()) {
		return;
	}
	auto s = graph->vertexs.front();
	queue<VertexNode*> vertex_queue;
	vertex_queue.emplace(s);
	while (!vertex_queue.empty()) {
		auto head = vertex_queue.front();
		vertex_queue.pop();
		cout << head->data << endl;
		head->visited = true;
		for (auto adj : head->adj) {
			if (!adj->visited) {
				vertex_queue.push(adj);
			}
		}
	}
	return;
}

void graph_test() {
	GraphNode* graph_node = new GraphNode();
	VertexNode* v1 = new VertexNode(1);
	VertexNode* v2 = new VertexNode(2);
	VertexNode* v3 = new VertexNode(3);
	VertexNode* v4 = new VertexNode(4);
	VertexNode* v5 = new VertexNode(5);
	VertexNode* v6 = new VertexNode(6);
	VertexNode* v7 = new VertexNode(7);
	VertexNode* v8 = new VertexNode(8);
	v1->adj.push_back(v2);
	v2->adj.push_back(v1);
	v2->adj.push_back(v3);
	v3->adj.push_back(v2);
	v3->adj.push_back(v4);
	v4->adj.push_back(v3);
	v4->adj.push_back(v5);
	v4->adj.push_back(v6);
	v5->adj.push_back(v4);
	v5->adj.push_back(v6);
	v5->adj.push_back(v7);
	v6->adj.push_back(v4);
	v6->adj.push_back(v5);
	v6->adj.push_back(v7);
	v7->adj.push_back(v5);
	v7->adj.push_back(v6);
	v7->adj.push_back(v8);
	v8->adj.push_back(v7);
	v8->adj.push_back(v6);

	graph_node->vertexs.push_back(v1);
	graph_node->vertexs.push_back(v2);
	graph_node->vertexs.push_back(v3);
	graph_node->vertexs.push_back(v4);
	graph_node->vertexs.push_back(v5);
	graph_node->vertexs.push_back(v6);
	graph_node->vertexs.push_back(v7);
	graph_node->vertexs.push_back(v8);

	BFS(graph_node);
}