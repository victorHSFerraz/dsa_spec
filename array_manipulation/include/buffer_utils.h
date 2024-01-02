#ifndef BUFFER_UTILS_H
#define BUFFER_UTILS_H

#include <stdio.h>

typedef int (*GetCharFunc)();

static int call_count = 0;

void clean_buffer(GetCharFunc getCharFunc);

int actual_getchar();

#endif