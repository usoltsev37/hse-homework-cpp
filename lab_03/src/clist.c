#include <stdlib.h>
//#include "clist.h"

// интрузивный двусвязный список

void add_node(intrusive_list l, intrusive_node n) {
    intrusive_node *p = malloc(sizeof(intrusive_node)); //free
    if(l.head == NULL) {
        (*p).next == NULL;
        (*p).prev = NULL;
        l.head = p;
    }
    else {
        n.next = (*p).next;
        (*p).next = NULL;
        (*p).prev = n.prev;
    }
}

void remove_node(intrusive_list l, intrusive_node n) {
    if(n.next == NULL && n.prev == NULL){
        l.head = NULL;
    }
    else if(n.next == NULL) {
        *(n.prev).next = n.next;
    }
    else if(n.prev == NULL) {
        *(n.next).prev = n.prev;
    }
    else{
        *(n.prev).next = n.next;
        *(n.next).prev = n.prev;
    }
    //list
    //free
}

void init_list(intrusive_list l) {
    l.head = NULL;
}



int get_length(intrusive_list l) {
    if(l.head == NULL)
        return 0;
    int count = 1;
    struct intrusive_node *temp = *(l.head).next;
    //struct intrusive_node *temp = l.head; //struct ?????
    while(1) {
        if(temp == NULL) {
            return count;
        }
        else {
            count++;
            temp = (*temp).next;
        }
    }
}
