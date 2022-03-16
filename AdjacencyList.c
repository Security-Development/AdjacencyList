#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32

// 그래프란 요소들이 서로 복잡하게 연결 되어있는 것을 의미 하고 
// 그래프는 정점과 간선들의 집합으로 구성된다. 
// G = (V, E)

// vertex == node | 정점 == 노드 
// edge == link | 간선 == 연결 
typedef struct Node {
	int node;
	struct Node* link;
} Node;

// n => 노드의 갯수 | list => adjacency List(인접 리스트) 
typedef struct GraphNode {
	int n;
	Node* list[MAX_SIZE]; 	 
} GraphNode;

// 인접 리스트의 초기화 
void init(GraphNode* g) {
	for(int i = 0; i < MAX_SIZE; i++) 
		g->list[i] = NULL;
	
	g->n = 0;
	
}

// 인접 리스트 값 넣기 | 매계변수 (그래프, 노드, 거리) 
void setNode(GraphNode* g, int count) {
	
	if( (g->n + 1 ) > MAX_SIZE) {
		printf("그래프의 노드의 개수를 초과 하셨습니다.\n");
		return;
	}
	
	g->n = count;
	 
}

// ( 그래프, 노드, 번호(key) ) 
void pushLink(GraphNode *g, int node, int key)  {
	
	if( node >= g->n || key >= g->n ) {
		printf("그래프의 노드 번호 오류가 발생했습니다.\n");
		return;
	}
	
	Node *n = (Node * )malloc(sizeof(Node));
	
	n->node = key;
	n->link = g->list[node];
	g->list[node] = n;
	
	
}


// 연결 노드 출력 
void printList(GraphNode *g, int node) {
	
	if( node > g->n ) {
		printf("%d Node는 없습니다. 오류 발생\n", node);
		return;
	} 
	
	Node *n = g->list[node];
	
	printf("%d 번 Node의 연결 Node : ", node);
	while(n != NULL) {
		printf("-> %d", n->node);
		n = n->link;
	}
	printf("\n");
} 


int main() {
	// 그래프를 동적 할당으로 초기화 
	GraphNode *g = (GraphNode *)malloc(sizeof(GraphNode));
	// 그래프를 초기화 
	init(g);
	
	// 3개의 노드 생성 
	setNode(g, 3);
	
	
	//그래프 생성 stack 구조 처럼 FILO 구조를 가지고 있다. 
	pushLink(g, 0, 2);
	pushLink(g, 0, 1);
	pushLink(g, 1, 0);
	pushLink(g, 2, 0);
	
	
	// 연결 노드 출력 
	printList(g, 0);
	printList(g, 1);
	printList(g, 2);
	printList(g, 4);
	
	
	printf("노드의 총 갯수 : %d \n", g->n);
	 
	
	
	// 그래프의 동적 메모리 해제 
	free(g); 
	
	return 0;
}
