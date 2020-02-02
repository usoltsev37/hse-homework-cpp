#ifndef CLIST_H_
#define CLIST_H_
#define container_of(ptr, type, member) ((type*)((char*)(ptr) - offsetof(type, member)))

//попробуй

typedef struct intrusive_node {
    struct intrusive_node *next;
    struct intrusive_node *prev;
} intrusive_node;

typedef struct intrusive_list {
    struct intrusive_node *head;
} intrusive_list;

void init_list(intrusive_list l);
void add_node(intrusive_list l, intrusive_node n);
void remove_node(intrusive_list l, intrusive_node n);

int get_length(intrusive_list l);

#endif
