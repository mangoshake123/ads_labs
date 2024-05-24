#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteFromBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    if (*headRef != NULL) {
        (*headRef)->prev = NULL;
    }
    free(temp);
}

void deleteFromEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *headRef = NULL;
    }
    free(temp);
}

void deleteNode(struct Node** headRef, struct Node* delNode) {
    if (*headRef == NULL || delNode == NULL) {
        printf("The given node cannot be deleted\n");
        return;
    }
    if (*headRef == delNode) {
        *headRef = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    printf("List after inserting at beginning: ");
    printList(head);

 
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printf("List after inserting at end: ");
    printList(head);

    insertAfter(head->next, 6);
    printf("List after inserting after the second node: ");
    printList(head);

    deleteFromBeginning(&head);
    printf("List after deleting from beginning: ");
    printList(head);

    deleteFromEnd(&head);
    printf("List after deleting from end: ");
    printList(head);

    deleteNode(&head, head->next);
    printf("List after deleting the second node: ");
    printList(head);

    return 0;
}
