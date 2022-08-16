#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    Node *head = NULL;
    Node *cur = NULL;

    Node *new_node = NULL;
    int readData;

    // Insert Datas
    while (1)
    {
        printf("Enter the Natural Number: ");
        scanf("%d", &readData);
        if (readData < 1)
            break;

        // Insert Node
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = readData;
        new_node->next = NULL;

        if (head == NULL)
            head = new_node;
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    printf("\n");

    // Print Datas
    printf("==Print the whole datas==\n");
    if (head == NULL)
        printf("    EMPTY!\n");
    else
    {
        cur = head;
        printf("%d", cur->data);
        while (cur->next != NULL)
        {
            cur = cur->next;
            printf(" -> %d", cur->data);
        }
    }
    printf("\n\n");

    // Free the memory
    if (head == NULL)
        return 0;

    Node *dN = head;
    Node *dNN = head->next;

    printf("Delete %d\n", dN->data);
    free(dN);

    while (dN->next != NULL)
    {
        dN = dNN;
        dNN = dN->next;

        printf("Delete %d\n", dN->data);
        free(dN);
    }

    return 0;
}
