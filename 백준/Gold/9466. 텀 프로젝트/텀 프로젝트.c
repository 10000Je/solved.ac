// no.9466: 텀 프로젝트

#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef struct Node
{
    int val;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
} Queue;

int inorder[MAX];
int graph[MAX];

/**
 * Topology sort with Kahn's algorithm
 */
void topology_sort(int n);

/**
 * Push data into queue
 */
void push(Queue* queue, int val);

/**
 * Get front data from queue
 */
int front(Queue* queue);

/**
 * pop front data from queue
 */
void pop(Queue* queue);

int main() 
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) 
    {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            inorder[i] = 0;
        
        for(int i=1; i<=n; i++) 
        {
            int j;
            scanf("%d", &j);
            graph[i] = j;
            inorder[j]++;
        }

        topology_sort(n);
        int count = 0;
        for(int i=1; i<=n; i++) 
        {
            if(inorder[i] == 0)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}

void topology_sort(int n) {
    Queue queue = {NULL};
    for(int i=1; i<=n; i++) 
    {
        if(inorder[i] == 0)
            push(&queue, i);
    }
    while(queue.front != NULL) 
    {
        int x = front(&queue);
        pop(&queue);
        int node = graph[x];
        inorder[node]--;
        if(inorder[node] == 0)
            push(&queue, node);
    }
}

Node* createNode(int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push(Queue* queue, int val)
{
    Node* newNode = createNode(val);
    if(queue->front == NULL)
    {
        queue->front = newNode;
        return;
    }
    Node* ptr = queue->front;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
}

int front(Queue* queue)
{
    if(queue->front == NULL)
        return -1;
    return queue->front->val;
}

void pop(Queue* queue)
{
    if(queue->front == NULL)
        return;
    Node* tmp = queue->front;
    queue->front = tmp->next;
    free(tmp);
}