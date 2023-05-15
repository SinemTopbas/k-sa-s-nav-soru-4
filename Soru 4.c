#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void addNode(int value);
void removeNode(int value);
void displayList();

int main() {
    int choice = 0;
    int value = 0;
    
    while (1) {
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
        printf("1-Ekleme\n");
        printf("2-Silme\n");
        printf("3-Goruntuleme\n");
        printf("4-Cikis\n");
        printf("Seciniz: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz:");
                scanf("%d", &value);
                addNode(value);
                break;
            case 2:
                printf("Silmek istediginiz degeri giriniz:");
                scanf("%d", &value);
                removeNode(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim.Lutfen tekrar deneyin.\n");
                break;
        }
    }
    return 0;
}

void addNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("%d degeri basariyla eklendi.\n", value);
}

void removeNode(int value) {
    struct Node *current = head;
    struct Node *previous = NULL;
    
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("%d degeri listede bulunamadi.\n", value);
    }
    else if (previous == NULL) {
        head = current->next;
        free(current);
        printf("%d degeri listeden silindi.\n", value);
    }
    else {
        previous->next = current->next;
        free(current);
        printf("%d degeri listeden silindi.\n", value);
    }
}

void displayList() {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    printf("Listedeki elemanlar: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
