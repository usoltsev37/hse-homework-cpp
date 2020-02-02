#pragma once

#include <stdint.h>

typedef uint32_t DWORD;   // DWORD = unsigned 32 bit value
typedef uint16_t WORD;    // WORD = unsigned 16 bit value
typedef uint8_t BYTE;     // BYTE = unsigned 8 bit value
typedef int INT;     // INT = 32 bit value

#pragma pack(push, 1)
typedef struct tagRGBTRIPLE {
    BYTE red;
    BYTE green;
    BYTE blue;
} RGBTRIPLE;

typedef struct HEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;

    DWORD biSize;
    INT biWidth;
    INT biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    INT biXPelsPerMeter;
    INT biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} HEADER;

typedef struct bmp {
    HEADER *header;
    RGBTRIPLE **bitmap;
} bmp;
#pragma pack(pop)

void loadbmp(char *name, bmp *bmp_file);

void crop(int x, int y, int w, int h, bmp *bmp_file);

void rotate(int column, int row, bmp *bmp_file);

void save_bmp(char *out_name, bmp *bmp_file, int column, int row);

void destroy(bmp *bmp_file);
