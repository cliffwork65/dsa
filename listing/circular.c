#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *start = NULL;

void create() {
    char ch = 'y';
    struct node *temp, *p;

    while (ch == 'y' || ch == 'Y') {
        temp = (struct node *)malloc(sizeof(struct node));
        
        printf("\nEnter the data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
            temp->next = start;  // Pointing to itself
        } else {
            p = start;
            while (p->next != start) {
                p = p->next;
            }
            p->next = temp;
            temp->next = start;
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
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != start);
    printf("(back to start)\n");
}

void insert_begin() {
    struct node *temp, *p;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data for the first position: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        temp->next = start;
    } else {
        p = start;
        while (p->next != start) {
            p = p->next;
        }
        temp->next = start;
        p->next = temp;
        start = temp;
    }
}

void insert_last() {
    struct node *temp, *p;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data for the last position: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        temp->next = start;
    } else {
        p = start;
        while (p->next != start) {
            p = p->next;
        }
        p->next = temp;
        temp->next = start;
    }
}

void delete_first() {
    if (start == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct node *temp, *p;
    temp = start;

    if (start->next == start) {
        start = NULL;
    } else {
        p = start;
        while (p->next != start) {
            p = p->next;
        }
        start = start->next;
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

    struct node *temp, *p;
    temp = start;

    if (start->next == start) {
        start = NULL;
    } else {
        while (temp->next != start) {
            p = temp;
            temp = temp->next;
        }
        p->next = start;
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
        printf("Press 6: For delete the first node\n");
        printf("Press 7: For delete the last node\n");
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
