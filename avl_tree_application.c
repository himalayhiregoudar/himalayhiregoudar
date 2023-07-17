#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    int taskID;
    int priority;
} Task;

typedef struct Node {
    Task task;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(Task task) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insertTask(Node* node, Task task) {
    if (node == NULL)
        return createNode(task);

    if (task.taskID < node->task.taskID)
        node->left = insertTask(node->left, task);
    else if (task.taskID > node->task.taskID)
        node->right = insertTask(node->right, task);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && task.taskID < node->left->task.taskID)
        return rightRotate(node);

    if (balance < -1 && task.taskID > node->right->task.taskID)
        return leftRotate(node);

    if (balance > 1 && task.taskID > node->left->task.taskID) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && task.taskID < node->right->task.taskID) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("Task ID: %d, Priority: %d\n", node->task.taskID, node->task.priority);
        inorderTraversal(node->right);
    }
}

int main() {
    Node* root = NULL;
    int numTasks, i;

    printf("Enter the number of tasks: ");
    scanf("%d", &numTasks);

    Task* tasks = (Task*)malloc(numTasks * sizeof(Task));

    printf("Enter task details (Task ID and Priority):\n");
    for (i = 0; i < numTasks; i++) {
        printf("Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].taskID, &tasks[i].priority);
        root = insertTask(root, tasks[i]);
    }

    printf("Scheduled Tasks:\n");
    inorderTraversal(root);

    free(tasks);
    return 0;
}
