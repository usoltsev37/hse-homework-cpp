#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "point_list.h"
#include "clist.h"


void print_point(intrusive_node *node, void *format) {
    point_node *pnode = get_point(node);
    printf((char *) format, pnode->x, pnode->y);
}

void inc_count(intrusive_node *unusedNODE, void *count) {
    (void) unusedNODE;
    (*(int *) count)++;
}

int main(int argc, char **argv) {

    assert(argc >= 4);
    assert(argc <= 5);

    intrusive_list list;
    intrusive_list *l = &list;
    init_list(l);
    

    if (strcmp(argv[1], "loadtext") == 0) {
        FILE *read_f = fopen(argv[2], "r");
        assert(read_f);

        int x = 0, y = 0;
        while (fscanf(read_f, "%d %d", &x, &y) == 2) {
            add_point(l, x, y);
        }
        fclose(read_f);
    } else if (strcmp(argv[1], "loadbin") == 0) {

        FILE *read_f = fopen(argv[2], "rb");
        assert(read_f);

        unsigned char buffer[3];

        while (fread(buffer, sizeof(unsigned char), 3, read_f)) {
        	int x = 0, y = 0;
            x = buffer[2] << 16;
            x += buffer[1] << 8;
            x += buffer[0];

            fread(buffer, sizeof(unsigned char), 3, read_f);
            y = buffer[2] << 16;
            y += buffer[1] << 8;
            y += buffer[0];
            add_point(l, x, y);
        }

        fclose(read_f);
    } else
        assert(!"Unknown command");

    


    if (strcmp(argv[3], "print") == 0) {
        apply(l, print_point, (void *) argv[4]);
        printf("\n");
    } else if (strcmp(argv[3], "savetext") == 0) {
        FILE *write_f = fopen(argv[4], "w");
        assert(write_f);

        intrusive_node *head = &list.head;
        for (intrusive_node *node = head->next; node != head; node = node->next) {
            point_node *pnode = get_point(node);
            fprintf(write_f, "%d %d\n", pnode->x, pnode->y);
        }

        fclose(write_f);
    } else if (strcmp(argv[3], "savebin") == 0) {

        FILE *write_f = fopen(argv[4], "wb");
        assert(write_f);

        intrusive_node *head = &list.head;
        for (intrusive_node *node = head->next; node != head; node = node->next) {
            point_node *pnode = get_point(node);
            int x = pnode->x, y = pnode->y;
            unsigned char data[] = {
                    x & 0xFF,
                    (x >> 8) & 0xFF,
                    (x >> 16) & 0xFF,
                    y & 0xFF,
                    (y >> 8) & 0xFF,
                    (y >> 16) & 0xFF,
            };

            assert(fwrite(data, sizeof(unsigned char), 6, write_f) == 6);
        }

        fclose(write_f);
    } else if (strcmp(argv[3], "count") == 0) {
        int count = 0;
        apply(l, inc_count, &count);
        printf("%d\n", count);
    } else
        assert(!"Unknown command");

    return 0;
}
