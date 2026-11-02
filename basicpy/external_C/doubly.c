#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head = NULL;
void at_beg() {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to input at the beg: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    printf("Inserted at the beginning!\n");
}
void printing() {
    if (head == NULL) {
        printf("List is EMPTY!!\n");
    } else {
        struct node* temp = head;
        printf("List (Forward): NULL <-> ");
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void at_pos() {
    int pos;
    struct node* newnode;
    struct node* temp = head;
    printf("Enter the position to enter: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position! Position must be 1 or greater.\n");
        return;
    }
    if (pos == 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value to input: ");
        scanf("%d", &newnode->data);
        newnode->next = head;
        newnode->prev = NULL;
        if (head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
        printf("Inserted %d at first position..\n", newnode->data);
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range (list is too short)!\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("List is empty or is too short!\n");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to input: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    printf("Inserted %d at position %d.\n", newnode->data, pos);
}
void ending() {
    struct node* newnode;
    struct node* temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to input: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Inserted at the end.\n");
}
void del_beg() {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty. Nothing to delete!\n");
    } else {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Deleted the first node!!\n");
    }
}
void del_end() {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty. First insert some values!!\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted the last node!\n");
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("Deleted the last node!\n");
    }
}
void del_pos() {
    struct node* temp = head;
    int value;
    int pos, i = 1;
    printf("Enter the position of the value to delete: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position! Position must be 1 or greater.\n");
        return;
    }
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos == 1) {
        value = head->data;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("%d deleted from 1st position!!\n", value);
        return;
    }
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position %d is out of range!\n", pos);
        return;
    }
    value = temp->data;
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted %d from the %d position!!\n", value, pos);
}
int main() {
    int choice;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1-insert at begg\n");
        printf("2-insert at pos\n");
        printf("3-insert at end\n");
        printf("4-display\n");
        printf("5-del from end\n");
        printf("6-del from beg\n");
        printf("7-del from position\n");
        printf("8-exit\n");
        printf("---------------------------------\n");
        printf("Enter: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1:
                at_beg();
                break;
            case 2:
                at_pos();
                break;
            case 3:
                ending();
                break;
            case 4:
                printing();
                break;
            case 5:
                del_end();
                break;
            case 6:
                del_beg();
                break;
            case 7:
                del_pos();
                break;
            case 8:
                printf("exiting the program....\n");
                while(head != NULL) {
                    del_beg();
                }
                exit(0);
            default:
                printf("invalid choice! please provide a valid input!\n");
        }
    }
    return 0;
}
