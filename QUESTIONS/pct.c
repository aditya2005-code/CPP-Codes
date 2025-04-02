#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void bubbleSort(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* i;
    struct Node* j = NULL;
    int flag;

    do {
        flag = 0;
        i = head;

        while (i->next != j) {
            if (i->data > i->next->data) {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
                flag = 1;
            }
            i = i->next;
        }
        j = i;
    } while (flag);
}

int main() {
    struct Node* head = NULL;

    Push(&head, 4);
    Push(&head, 2);
    Push(&head, 5);
    Push(&head, 1);
    Push(&head, 3);

    printf("Original List:\n");
    printList(head);

    bubbleSort(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
