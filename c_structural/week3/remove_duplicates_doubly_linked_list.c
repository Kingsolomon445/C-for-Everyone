#include <stdio.h>
#include <stdlib.h>

/************************************************************
This program uses doubly list and populates it with randomly
generated numbers and then sort it and then remove the
duplicates
*************************************************************/

typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} list;

list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list *add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head -> next = h;
    return head;
}

int generate_num(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return (num);
}

list *store_to_list (void)
{
    list* head = create_list(generate_num(0, 49));
    int i;
    for (i = 1; i < 200; i++)
    {
        head = add_to_front(generate_num(0, 49), head);
    }
    return head;
}

list *sort_list(list* head)
{
    list *tmp;
    int  temp;
    tmp = head;
    while (head->next != NULL)
    {
        if (head->data > head->next->data)
        {
            temp = head->data;
            head->data = head->next->data;
            head->next->data = temp;
            head = tmp;
        }
        else
            head = head->next;
    }
    head = tmp;
    return (head);
}

void remove_duplicates(list* head)
{
    list* next_next;
    if (head == NULL)
        return;
    while (head->next != NULL)
    {
        if (head->data == head->next->data)
        {
            next_next = head->next->next;
            free(head->next);
            head->next = next_next;
        }
        else
        {
            head = head->next;
        }
    }
}

int main(void)
{
    list* result = store_to_list();
    int count = 0;

    printf("This below is the unsorted duplicated version of the list\n\n");
    while (result != NULL)
    {
        printf("%d ", result -> data);
        result = result -> next;
        count += 1;
        if (count % 25 == 0) // this is used to separate output into rows for neat output
            printf("\n\n");
    }
    list* final_result = sort_list(store_to_list());
    remove_duplicates(final_result);
    count = 0;
    printf("This below is the final sorted unduplicated version of the list\n\n");
    while (final_result != NULL)
    {
        printf("%d ", final_result -> data);
        final_result = final_result -> next;
        count += 1;
        if (count % 15 == 0)
            printf("\n\n");
    }

    return 0;
}