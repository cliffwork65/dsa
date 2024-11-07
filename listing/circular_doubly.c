#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

void create() {
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        struct node *temp, *p;
        temp = (struct node *)malloc(sizeof(struct node));
        
        printf("\nEnter the data: ");
        scanf("%d", &temp->data);
        temp->prev = temp->next = NULL;
        
        if (start == NULL) {
            start = temp;
            start->next = start;
            start->prev = start;
        } else {
            p = start->prev; // last node
            temp->next = start;
            temp->prev = p;
            p->next = temp;
            start->prev = temp;
        }
        
        printf("\nDo you want to create another node? (Press y): ");
        scanf(" %c", &ch);  
    }
}

void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node *p = start;
    printf("The Circular Linked List: ");
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != start);
    printf("...\n");
}

void insert_begin() {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    
    printf("\nEnter the data for the first position: ");
    scanf("%d", &temp->data);
    temp->prev = temp->next = NULL;
    
    if (start == NULL) {
        start = temp;
        start->next = start;
        start->prev = start;
    } else {
        p = start->prev; // last node
        temp->next = start;
        temp->prev = p;
        p->next = temp;
        start->prev = temp;
        start = temp;
    }
}

void insert_last() {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    
    printf("\nEnter the data for the last position: ");
    scanf("%d", &temp->data);
    temp->prev = temp->next = NULL;
    
    if (start == NULL) {
        start = temp;
        start->next = start;
        start->prev = start;
    } else {
        p = start->prev; // last node
        temp->next = start;
        temp->prev = p;
        p->next = temp;
        start->prev = temp;
    }
}

void delete_first() {
    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct node *temp = start;
    
    if (start->next == start) {
        start = NULL;
    } else {
        struct node *p = start->prev;
        start = start->next;
        start->prev = p;
        p->next = start;
    }
    
    printf("\nData deleted = %d\n", temp->data);
    free(temp);
}

void delete_last() {
    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct node *temp = start->prev;
    
    if (start->next == start) {
        start = NULL;
    } else {
        struct node *p = temp->prev;
        p->next = start;
        start->prev = p;
    }
    
    printf("\nData deleted = %d\n", temp->data);
    free(temp);
}

void count_node() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct node *temp = start;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != start);
    
    printf("\nNumber of nodes in the list = %d\n", count);
}

int main() {
    int ch;
    
    while (1) {
        printf("\nPress 1: For create a list\n");
        printf("Press 2: For display a list\n");
        printf("Press 3: For insert at the beginning\n");
        printf("Press 4: For insert at the end\n");
        printf("Press 5: For count total nodes\n");
        printf("Press 6: For delete first node\n");
        printf("Press 7: For delete last node\n");
        printf("Press 8: End Program\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_begin(); break;
            case 4: insert_last(); break;
            case 5: count_node(); break;
            case 6: delete_first(); break;
            case 7: delete_last(); break;
            case 8: exit(0);
            default: printf("Wrong choice.\n");
        }
    }
}
