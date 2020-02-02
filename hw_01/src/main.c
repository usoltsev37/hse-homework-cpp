#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bmp.h"


int main(int argc, char **argv) {

    assert(argc == 8);

    bmp bmp_file;
    HEADER head;
    bmp_file.header = &head;

    if (strcmp(argv[1], "crop-rotate") == 0) {
        //load
        loadbmp(argv[2], &bmp_file);

        //assert
        int x = atoi(argv[4]);
        int y = atoi(argv[5]);
        int w = atoi(argv[6]);
        int h = atoi(argv[7]);

        assert(x >= 0);
        assert(y >= 0);
        assert(w >= 0);
        assert(h >= 0);
        assert(x <= bmp_file.header->biWidth);
        assert(y <= bmp_file.header->biHeight);
        assert(x + w <= bmp_file.header->biWidth);
        assert(y + h <= bmp_file.header->biHeight);

        //crop
        crop(x, y, w, h, &bmp_file);

        //rotate
        rotate(w, h, &bmp_file);

        //save
        save_bmp(argv[3], &bmp_file, w, h);

        //destroy
        destroy(&bmp_file);
    }
    return 0;
}
