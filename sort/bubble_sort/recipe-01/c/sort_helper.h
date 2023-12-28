#pragma once

#include <stdio.h>
#include <stdlib.h>

static void print(int* lyst, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lyst[i]);
    }
    printf("]\n");
}

static int* range(int n) {
    int* arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}


