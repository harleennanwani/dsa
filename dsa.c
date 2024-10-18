

 Implementation of Stack Data Structure using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    struct Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    return 0;
}
Conversion of Infix Expression to Postfix Expression Using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char value) {
    if (isFull(s)) return;
    s->arr[++(s->top)] = value;
}

char pop(struct Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->arr[(s->top)--];
}

char peek(struct Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->arr[s->top];
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
Implementation of Linear Queue Data Structure using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front element is %d\n", peek(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    return 0;
}
Implementation of Circular Queue Data Structure using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front element is %d\n", peek(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    return 0;
}
Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void initList(struct LinkedList* list) {
    list->head = NULL;
}

void insertAtEnd(struct LinkedList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList list;
    initList(&list);
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    displayList(&list);
    return 0;
}
 Implementation of Circular Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

void initList(struct CircularLinkedList* list) {
    list->head = NULL;
}

void insertAtEnd(struct CircularLinkedList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // Points to itself

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = list->head; // Complete the circle
}

void displayList(struct CircularLinkedList* list) {
    if (list->head == NULL) return;
    struct Node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(head)\n");
}

int main() {
    struct CircularLinkedList list;
    initList(&list);
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    displayList(&list);
    return 0;
}
Implementation of Circular Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct CircularDoublyLinkedList {
    struct Node* head;
};

void initList(struct CircularDoublyLinkedList* list) {
    list->head = NULL;
}

void insertAtEnd(struct CircularDoublyLinkedList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* tail = list->head->prev;
        tail->next = newNode;
        newNode->prev = tail;
    }
    newNode->next = list->head; // Complete the circle
    list->head->prev = newNode;
}

void displayList(struct CircularDoublyLinkedList* list) {
    if (list->head == NULL) return;
    struct Node* temp = list->head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(head)\n");
}

int main() {
    struct CircularDoublyLinkedList list;
    initList(&list);
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    displayList(&list);
    return 0;
}
Implementation of Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
Implementation of AVL Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at leaf
    return newNode;
}

int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int value) {
    if (node == NULL) return createNode(value);
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node; // Duplicate values are not allowed
    }

    node->height = 1 + max(height(node->left), height(node->right)));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }
    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);
    printf("\n");
    return 0;
}
Implementation of BFS and DFS on a Directed Graph using an Adjacency Matrix
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
};

void initGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
}

void BFS(struct Graph* g, int start) {
    bool visited[MAX] = { false };
    int queue[MAX], front = -1, rear = -1;
    
    visited[start] = true;
    queue[++rear] = start;

    while (front < rear) {
        int current = queue[++front];
        printf("%d ", current);
        
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

void DFS(struct Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

int main() {
    struct Graph g;
    initGraph(&g, 5);
    
    addEdge(&g, 0, 1);
Implementation of Binary Search in Real-Life Application
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
Implementation of Menu Driven Selection Sort, Bubble Sort, Insertion Sort
#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(arr, n);
            printf("Sorted array (Selection Sort): ");
            break;
        case 2:
            bubbleSort(arr, n);
            printf("Sorted array (Bubble Sort): ");
            break;
        case 3:
            insertionSort(arr, n);
            printf("Sorted array (Insertion Sort): ");
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
    printArray(arr, n);
    return 0;
}
Implementation of Menu Driven Merge Sort and Quick Sort
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            mergeSort(arr, 0, n - 1);
            printf("Sorted array (Merge Sort): ");
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            printf("Sorted array (Quick Sort): ");
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
    printArray(arr, n);
    return 0;
}
