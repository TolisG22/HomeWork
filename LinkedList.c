#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {

    int item;

    struct Node* nextNode;
    

} Node;
 
typedef struct LinkedList {

    Node* head;

    int size;

} LinkedList;
 
LinkedList create_list() {

    LinkedList list;

    list.head = NULL;

    list.size = 0;

    return list;

}
 
void insert_left(LinkedList* list, int item) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->item = item;

    if (list->head == NULL) {

        list->head = newNode;

        newNode->nextNode = NULL;

    }

    else {

        newNode->nextNode = list->head;

        list->head = newNode;

    }

    list->size++;

}
 
void insert_right(LinkedList* list, int item) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->item = item;

    newNode->nextNode = NULL;

    if (list->head == NULL) {

        list->head = newNode;

    }

    else {

        Node* lastNode = list->head;


        for (int i = 0; i < list->size - 1; i++) {

            lastNode = lastNode->nextNode;

        }

        lastNode->nextNode = newNode;

    }

    list->size++;

}
 
Node* findNode(LinkedList* list, int item) {

    Node* currentNode = list->head;

        for (int i = 0; i < list->size; i++) {

            if (currentNode->item == item) {

                return currentNode;

            }

            currentNode = currentNode->nextNode;

        }

        return NULL;

}
 
Node* remove_left(LinkedList* list) {

    if (list->head == NULL) {       

        return NULL;

    }

    Node* oldHead = list->head;

    list->head = oldHead->nextNode;

    list->size--;

    return oldHead;

}
 
Node* remove_right(LinkedList* list) {

    if (list->head == NULL) {       

        return NULL;

    }

    Node* parentNode = list->head;

    Node* childNode = parentNode->nextNode;

    while (childNode->nextNode != NULL) {

        parentNode = childNode;

        childNode = parentNode->nextNode;

    }

    parentNode->nextNode = NULL;

    list->size--;

    return childNode;

}
 
Node* remove_item(LinkedList* list, int item) {
    Node* prev = NULL;
    Node* cur = list->head;
    while (cur != NULL && cur->item != item) {
        prev = cur;
        cur = cur->nextNode;
    }
    if (cur == NULL) return NULL;
    if (prev == NULL) {
        list->head = cur->nextNode;
    } else {
        prev->nextNode = cur->nextNode;
    }
    list->size--;
    return cur;
}

 
int main()

{

    LinkedList list = create_list();

    insert_right(&list, 3);

    printf("list.head = %d\n", list.head->item);

    insert_left(&list, 2);

    printf(

        "list.head = %d, list.head.nextNode = %d", 

        list.head->item, 

        list.head->nextNode->item

    );

    insert_right(&list, 6);

    printf(

        "list.head = %d, list.head.nextNode = %d, list.head.nextNode.nextNode = %d\n", 

        list.head->item, 

        list.head->nextNode->item,

        list.head->nextNode->nextNode->item

    );

    Node* n = findNode(&list, 99);

    if (n == NULL) {

        printf("Node not found\n");

    }

    else {

        printf("Node found\n");

    }


    n = remove_item(&list, 3);

    n = findNode(&list, 3);

    if (n == NULL) {

        printf("Node not found\n");

    }

    else {

        printf("Node found\n");

    }

    return 0;

}
 