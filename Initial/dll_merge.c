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


struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL;

    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    struct Node* mergedTail = mergedHead;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            head1->prev = mergedTail;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2->prev = mergedTail;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    if (head1 != NULL) {
        mergedTail->next = head1;
        head1->prev = mergedTail;
    } else if (head2 != NULL) {
        mergedTail->next = head2;
        head2->prev = mergedTail;
    }

    return mergedHead;
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
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 5);


    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 6);

    printf("First Sorted List: ");
    printList(head1);

    printf("Second Sorted List: ");
    printList(head2);

    struct Node* mergedHead = mergeSortedLists(head1, head2);

    printf("Merged Sorted List: ");
    printList(mergedHead);

    return 0;
}
