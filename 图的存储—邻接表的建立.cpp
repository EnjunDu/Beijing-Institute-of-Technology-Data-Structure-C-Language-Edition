#include <stdio.h>
#include <stdlib.h>

// 边结点的定义
typedef struct EdgeNode {
    int adjVertex;  // 相邻顶点的位置
    int weight;     // 权值
    struct EdgeNode* next;  // 指向下一个边结点的指针
} EdgeNode;

// 顶点结点的定义
typedef struct VertexNode {
    char data;           // 顶点信息
    EdgeNode* firstEdge;  // 指向第一个边结点的指针
} VertexNode;

// 图的定义
typedef struct {
    VertexNode* vertices;  // 顶点数组
    int numVertices;       // 顶点数
} Graph;

// 创建一个图
Graph createGraph() {
    Graph graph;
    
    // 输入顶点数
    scanf("%d", &graph.numVertices);

    // 分配顶点数组的内存
    graph.vertices = (VertexNode*)malloc(graph.numVertices * sizeof(VertexNode));

    // 输入顶点信息
    for (int i = 0; i < graph.numVertices; ++i) {
        scanf(" %c", &graph.vertices[i].data);
        graph.vertices[i].firstEdge = NULL;  // 初始化边链表为空
    }

    // 输入边的信息
    for (int i = 0; i < graph.numVertices; ++i) {
        int adjVertex, weight;
        // 读取边信息，直到输入-1为止
        while (1) {
            scanf("%d", &adjVertex);
            if (adjVertex == -1) {
                break;
            }

            scanf("%d", &weight);

            // 创建边结点
            EdgeNode* newEdge = (EdgeNode*)malloc(sizeof(EdgeNode));
            newEdge->adjVertex = adjVertex;
            newEdge->weight = weight;
            newEdge->next = graph.vertices[i].firstEdge;

            // 将边结点插入到顶点的边链表中
            graph.vertices[i].firstEdge = newEdge;
        }
    }

    return graph;
}

// 输出图的邻接表
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
