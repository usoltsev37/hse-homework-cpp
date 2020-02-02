#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bmp.h"


void loadbmp(char *name, bmp *bmp_file) {
    FILE *read_f = fopen(name, "rb");
    assert(read_f);

    assert(fread(bmp_file->header, sizeof(BYTE), sizeof(HEADER), read_f) == sizeof(HEADER));

    int width = bmp_file->header->biWidth, height = bmp_file->header->biHeight;
    assert(width >= 0);
    assert(height >= 0);
    RGBTRIPLE **arr_pointers = (RGBTRIPLE **) malloc(height * sizeof(RGBTRIPLE * ));
    RGBTRIPLE *arrs = (RGBTRIPLE *) malloc(height * width * sizeof(RGBTRIPLE));
    assert(arr_pointers != NULL);
    assert(arrs != NULL);

    for (int i = 0; i < height; ++i) {
        arr_pointers[i] = arrs + width * i;
    }

    bmp_file->bitmap = arr_pointers;

    RGBTRIPLE rgb_colors;
    RGBTRIPLE *rgb = &rgb_colors;
    for (int h = height - 1; h >= 0; h--) {
        for (int w = 0; w < width; w++) {
            assert(fread(rgb, sizeof(BYTE), 3, read_f) == 3);
            bmp_file->bitmap[h][w] = rgb_colors;
        }
        unsigned int ost = 3 * width % 4;
        if (ost) {
            ost = 4 - ost;
            assert(fread(rgb, sizeof(BYTE), ost, read_f) == ost);
        }
    }

    fclose(read_f);
}

void crop(int x, int y, int w, int h, bmp *bmp_file) {
    RGBTRIPLE **arr_pointers = (RGBTRIPLE **) malloc(h * sizeof(RGBTRIPLE * ));
    RGBTRIPLE *arrs = (RGBTRIPLE *) malloc(w * h * sizeof(RGBTRIPLE));
    for (int i = 0; i < h; ++i) {
        arr_pointers[i] = arrs + w * i;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr_pointers[i][j] = bmp_file->bitmap[y + i][x + j];
        }
    }
    free(bmp_file->bitmap[0]);
    free(bmp_file->bitmap);

    bmp_file->bitmap = arr_pointers;

    //обновляем заголовки
    bmp_file->header->biHeight = h;
    bmp_file->header->biWidth = w;
    if (w % 4) {
        bmp_file->header->biSizeImage = (DWORD) h * (3 * w + 4 - (3 * w) % 4);
        bmp_file->header->bfSize = bmp_file->header->biSizeImage + sizeof(HEADER);
    } else {
        bmp_file->header->biSizeImage = (DWORD) 3 * h * w;
        bmp_file->header->bfSize = bmp_file->header->biSizeImage + sizeof(HEADER);
    }
}


void rotate(int column, int row, bmp *bmp_file) {
    RGBTRIPLE **arr_pointers = (RGBTRIPLE **) malloc(column * sizeof(RGBTRIPLE * ));
    RGBTRIPLE *arrtemp = (RGBTRIPLE *) malloc(column * row * sizeof(RGBTRIPLE));
    for (int i = 0; i < column; ++i) {
        arr_pointers[i] = arrtemp + row * i;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            arr_pointers[j][row - i - 1] = bmp_file->bitmap[i][j];
        }
    }

    free(bmp_file->bitmap[0]);
    free(bmp_file->bitmap);
    bmp_file->bitmap = arr_pointers;

    //  обновляем заголовки
    bmp_file->header->biSizeImage = 3 * column * (row % 4 + row);
    bmp_file->header->biHeight = column;
    bmp_file->header->biWidth = row;

    if (row % 4) {
        bmp_file->header->biSizeImage = (DWORD) column * (3 * row + 4 - (3 * row) % 4);
        bmp_file->header->bfSize = bmp_file->header->biSizeImage + sizeof(HEADER);
    } else {
        bmp_file->header->biSizeImage = (DWORD) 3 * column * row;
        bmp_file->header->bfSize = bmp_file->header->biSizeImage + sizeof(HEADER);
    }
}


void save_bmp(char *out_name, bmp *bmp_file, int column, int row) {
    FILE *write_f = fopen(out_name, "wb");
    assert(write_f);

    assert(fwrite(bmp_file->header, sizeof(BYTE), sizeof(HEADER), write_f) == sizeof(HEADER));

    uint8_t zero = 0;
    for (int i = column - 1; i >= 0; i--) {
        for (int j = 0; j < row; j++) {
            assert(fwrite(&bmp_file->bitmap[i][j], sizeof(BYTE), 3, write_f) == 3);
        }
        if (3 * row % 4) {
            int temp_count = 4 - (3 * row) % 4;
            while (temp_count) {
                assert(fwrite(&zero, sizeof(BYTE), 1, write_f) == 1);
                temp_count--;
            }
        }
    }
    fclose(write_f);
}


void destroy(bmp *bmp_file) {
    free(bmp_file->bitmap[0]);
    free(bmp_file->bitmap);
}
