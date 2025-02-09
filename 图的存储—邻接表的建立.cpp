#include <stdio.h>
#include <stdlib.h>

// �߽��Ķ���
typedef struct EdgeNode {
    int adjVertex;  // ���ڶ����λ��
    int weight;     // Ȩֵ
    struct EdgeNode* next;  // ָ����һ���߽���ָ��
} EdgeNode;

// ������Ķ���
typedef struct VertexNode {
    char data;           // ������Ϣ
    EdgeNode* firstEdge;  // ָ���һ���߽���ָ��
} VertexNode;

// ͼ�Ķ���
typedef struct {
    VertexNode* vertices;  // ��������
    int numVertices;       // ������
} Graph;

// ����һ��ͼ
Graph createGraph() {
    Graph graph;
    
    // ���붥����
    scanf("%d", &graph.numVertices);

    // ���䶥��������ڴ�
    graph.vertices = (VertexNode*)malloc(graph.numVertices * sizeof(VertexNode));

    // ���붥����Ϣ
    for (int i = 0; i < graph.numVertices; ++i) {
        scanf(" %c", &graph.vertices[i].data);
        graph.vertices[i].firstEdge = NULL;  // ��ʼ��������Ϊ��
    }

    // ����ߵ���Ϣ
    for (int i = 0; i < graph.numVertices; ++i) {
        int adjVertex, weight;
        // ��ȡ����Ϣ��ֱ������-1Ϊֹ
        while (1) {
            scanf("%d", &adjVertex);
            if (adjVertex == -1) {
                break;
            }

            scanf("%d", &weight);

            // �����߽��
            EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
            newEdge->adjVertex = adjVertex;
            newEdge->weight = weight;
            newEdge->next = graph.vertices[i].firstEdge;

            // ���߽����뵽����ı�������
            graph.vertices[i].firstEdge = newEdge;
        }
    }

    return graph;
}

// ���ͼ���ڽӱ�
void printGraph(const Graph* graph) {
	       	int j=0;
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%c  ", graph->vertices[i].data);

        EdgeNode* currentEdge = graph->vertices[i].firstEdge;

        while (currentEdge != NULL) {
            printf("(%d,%d)%d  ", j, currentEdge->adjVertex, currentEdge->weight);
            currentEdge = currentEdge->next;

        }

        printf("\n");
        j++;

    }
}


int main() {
    Graph graph = createGraph();
    printGraph(&graph);
    return 0;
}
