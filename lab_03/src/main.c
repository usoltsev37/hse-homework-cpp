#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clist.c"


struct point {
    int x, y;
    struct intrusive_node node;
} point;


void add_point(intrusive_list l, int x, int y) {
    point *new = malloc(sizeof(point));
    (*new).x = x; // new->x = x;
    (*new).y = y;
    add_node(&l, &(new->node));
}

void remove_point(intrusive_list l, int x, int y) {
    // removes all (x, y) pairs
    // free
    struct intrusive_node *now = *(l.head).next;
    if(container_of(l.head, point, node)->x == x && container_of(l.head, point, node)->y == y)
    {
        remove_node(&l, &(l.head));
    }
    now = *(now).next;
    while(*now) {
        if(container_of(l.head, point, node)->x == x && container_of(l.head, point, node)->y == y)
        {
            remove_node(&l, &(l.head));
        }
        now = *(now).next;
    }
}

void show_all_points(intrusive_list l) {
    intrusive_node *ptr = l->head.next;
    if(ptr == NULL)
        return;
    while (ptr->next) {
        point *item = container_of(ptr, point, node);
        printf("%c",'(');
        printf("%d", item->x);
        printf("%c",' ');
        printf("%d", item->y);
        printf("%s",") ");
        ptr = ptr->next;
    }
    point *item = container_of(ptr, point, node);
        printf("%c",'(');
        printf("%d", item->x);
        printf("%c",' ');
        printf("%d", item->y);
        printf("%c",')');
    }
}

void remove_all_points(struct intrusive_list *list) {
    struct intrusive_node *ptr = list->head.next;

    while (ptr) {
        point *item = container_of(ptr, point, node);
        delete_node(list, &(item->node));
        ptr = ptr->next;
        free(item);
    }
}

char act[7];

int main() {
    struct intrusive_list list;
    init_list (&list);
    
    int x, y;
    while (true) {
        scanf ("%6s", act);
        if (strcmp (act, "add") == 0) {
            scanf ("%d", &x);
            scanf ("%d", &y);
            add_point (&list, x, y);
        }
        else if (strcmp (act, "rm") == 0) {
            scanf ("%d", &x);
            scanf ("%d", &y);
            remove_point (&list, x, y);
        }
        else if (strcmp (act, "rma") == 0) {
            remove_all_points (&list);
        }
        else if (strcmp (act, "len") == 0) {
            printf ("%d", get_length (&list));
            printf ("\n");
        }
        else if (strcmp (act, "print") == 0) {
            show_all_points (&list);
            printf ("\n");
        }
        else if (strcmp (act, "exit") == 0) {
            remove_all_points (&list);
            return 0;
        }
        else {
            printf("Unknown command\n");
        }
    }
    
    
    return 0;
  
}


