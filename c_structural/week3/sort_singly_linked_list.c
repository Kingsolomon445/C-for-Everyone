#include <stdio.h>
#include <stdlib.h>

typedef struct list{int data; struct list *next;} list;

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
    list* head = create_list(generate_num(1, 1000));
    int i;
    for (i = 1; i < 100; i++)
    {
        head = add_to_front(generate_num(1, 1000), head);
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


int main()
{
    list* result = store_to_list();
    int count = 0;

    printf("This below is the unsorted version of the list\n\n");
    while (result != NULL)
    {
        printf("%d ", result -> data);
        result = result -> next;
        count += 1;
        if (count % 20 == 0)
            printf("\n\n");
    }
    list* sorted_result = sort_list(store_to_list());
    count = 0;
    printf("\n\n");
    printf("This below is the sorted version of the list\n\n");
    while (sorted_result != NULL)
    {
        printf("%d ", sorted_result -> data);
        sorted_result = sorted_result -> next;
        count += 1;
        if (count % 20 == 0)
            printf("\n\n");
    }

    return 0;
}