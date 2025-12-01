#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int item;
    struct Node* nextNode;
    struct Node* prevNode;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList createList() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;
    return list;
}

Node* createNode(int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item=item;
    newNode->nextNode = NULL;
    newNode-> prevNode = NULL;
    return newNode;
}

void insertFirst(LinkedList* list, int item){
    Node* newNode = createNode(item);

    newNode->nextNode = list->head;
    newNode->prevNode = NULL;

    if(list->head != NULL){
        list->head->prevNode = newNode;
    }

    list->head = newNode;
    list->size++;
}

void insertLast(LinkedList* list, int item){
    Node* newNode = createNode(item);

    if(list->head == NULL){
        list->head = newNode;
    }
    else{
        Node* temp = list->head;
        while(temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
        newNode->prevNode = temp;
    }
    list->size++;
}

void insertAtExactPosition(LinkedList* list, int item, int position){
    if (position==1){
        insertFirst(list, item);
        return;
    }

    Node* temp = list->head;
    for (int i = 1; temp != NULL && i < position - 1; i++){
        temp = temp->nextNode;
    }

    if (temp==NULL){
        printf("The position you are asking for is bigger than the size of nodes!\n");
        return;
    }

    Node*newNode = createNode(item);
    newNode->nextNode=temp->nextNode;
    newNode->prevNode=temp;

    if (temp->nextNode !=NULL){
        temp->nextNode->prevNode= newNode;
    }

    temp->nextNode = newNode;

    list->size++;
}

void deleteFirst(LinkedList*list){
    if(list->head==NULL){
        printf("List empty.\n");
        return;
    }
    
    Node* oldHead = list->head;
    list->head = oldHead->nextNode;

    if (list->head != NULL){
        list->head->prevNode=NULL;
    }

    list->size--;
}

void deleteLast(LinkedList* list){
    if(list->head==NULL){
        printf("List empty.\n");
        return;
    }

    Node* curr = list->head;
    Node* prev= NULL;

    while(curr->nextNode != NULL){
        prev = curr;
        curr = curr->nextNode;
    }

    if (prev!=NULL){
        prev->nextNode = NULL;
    }
    else{
        list->head = NULL;
    }

    list->size--;
}

void deleteAtExactPosition(LinkedList* list, int position){
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1){
        deleteFirst(list);
        return;
    }

    Node* temp = list->head;

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("The position you are asking for is bigger than the size of nodes!\n");
        return;
    }

    if (temp->nextNode != NULL){
        temp->nextNode->prevNode = temp->prevNode;
    }

    if(temp->prevNode!=NULL){
        temp->prevNode->nextNode = temp->nextNode;
    }

    list->size--;

}

void printList(LinkedList* list){
    Node* temp = list->head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Printing list!:");

    while (temp !=NULL){
        printf("%d ", temp->item);
        temp = temp->nextNode;
    }
    printf("\n");
}


int main(){
    LinkedList list = createList();

    insertFirst(&list, 5);
    printList(&list);
    insertFirst(&list, 2);
    printList(&list);
    insertLast(&list, 10);
    printList(&list);
    insertAtExactPosition(&list, 20, 2);

    printList(&list);

    deleteFirst(&list);
    printList(&list);

    deleteLast(&list);
    printList(&list);

    deleteAtExactPosition(&list, 2);
    printList(&list);

    return 0;

}