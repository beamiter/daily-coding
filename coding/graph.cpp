#include "pch.h"


void BFS(GraphNode* graph, VertexNode* s) {
	if (!graph || graph->vertexs.empty()) {
		return;
	}
	if (s == NULL) {
		s = graph->vertexs.front();
	}

	queue<VertexNode*> vertex_queue;
	vertex_queue.emplace(s);
	s->visited = true;
	s->p = NULL;
	while (!vertex_queue.empty()) {
		auto head = vertex_queue.front();
		vertex_queue.pop();
		cout << "---> " << head->data << endl;
		cout << "-------- " << head->data << endl;
		for (auto adj : head->adj) {
			if (!adj->visited) {
				vertex_queue.emplace(adj);
				adj->visited = true;
				adj->p = head;
				cout << "<--- " << adj->data << endl;
			}
		}
		/*cout << "##################" << endl;*/
	}
	return;
}

void BFS_search(GraphNode* graph, int key, VertexNode* s){
	if (!graph || graph->vertexs.empty()) {
		return;
	}
	if (s == NULL) {
		s = graph->vertexs.front();
	}

	queue<VertexNode*> vertex_queue;
	vertex_queue.emplace(s);
	s->visited = true;
	s->p = NULL;
	VertexNode* answer = NULL;
	while (!vertex_queue.empty()){
		auto head = vertex_queue.front();
		vertex_queue.pop();
		if (head->data == key) {
			answer = head;
			break;
		}
		for (auto adj : head->adj) {
			if (!adj->visited) {
				vertex_queue.emplace(adj);
				adj->visited = true;
				adj->p = head;
			}
		}
	}

	while (answer) {
		cout << answer->data << "  ";
		answer = answer->p;
		if (answer == s) {
			cout << answer->data << "  ";
			break;
		}
	}
	cout << endl;

	return;
}

void BFS_search(GraphNode graph, int key, VertexNode s) {
	if (graph.vertexs.empty()) {
		return;
	}

	queue<VertexNode> vertex_queue;
	vertex_queue.emplace(s);
	s.visited = true;
	s.p = NULL;
	VertexNode answer;
	while (!vertex_queue.empty()) {
		auto head = vertex_queue.front();
		vertex_queue.pop();
		if (head.data == key) {
			answer = head;
			break;
		}
		for (auto adj : head.adj) {
			if (!adj->visited) {
				vertex_queue.emplace(*adj);
				adj->visited = true;
				adj->p = &head;
			}
		}
	}

	while (answer) {
		cout << answer->data << "  ";
		answer = answer->p;
		if (answer == &s) {
			cout << answer->data << "  ";
			break;
		}
	}
	cout << endl;

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
	v6->adj.push_back(v8);
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

	//BFS(graph_node, v3);
	BFS_search(*graph_node, 5, *v1);
	BFS_search(graph_node, 5, v2);
	BFS_search(graph_node, 5, v3);
	BFS_search(graph_node, 5, v4);
	BFS_search(graph_node, 5, v5);
	BFS_search(graph_node, 5, v6);
	BFS_search(graph_node, 5, v7);
	BFS_search(graph_node, 5, v8);
	
}