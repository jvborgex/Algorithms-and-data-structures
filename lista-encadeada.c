#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    void *data;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node* createNode(void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um elemento no meio da lista
void insertMiddle(Node **head, void *data, int position) {
    if (position < 0 || (position > 0 && *head == NULL)) {
        printf("Posição inválida\n");
        return;
    }

    Node *current = *head;
    Node *newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        for (int i = 0; i < position - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Função para remover um elemento do meio da lista
void removeMiddle(Node **head, int position) {
    if (*head == NULL || position < 0) {
        printf("Lista vazia ou posição inválida\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    if (position == 0) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Posição fora dos limites da lista\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}

// Função para imprimir a lista (assume que os dados são do tipo int)
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", *(int *)head->data);
        head = head->next;
    }
    printf("\n");
}

// Função principal para demonstrar a lista
int main() {
    Node *head = NULL;

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    insertMiddle(&head, &data1, 0);
    insertMiddle(&head, &data2, 1);
    insertMiddle(&head, &data3, 2);

    printList(head);

    removeMiddle(&head, 1);

    printList(head);

    return 0;
}
