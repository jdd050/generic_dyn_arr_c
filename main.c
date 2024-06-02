#include <stdio.h>
#include <stdlib.h>


#define make_wrapper(n, ty) \
typedef struct {            \
    ty *array;              \
    size_t used;            \
    size_t capacity;        \
} n;                        \
void init##n(n *a, size_t initialCapacity) { \
    a->array = malloc(initialCapacity * sizeof(ty)); \
    a->used = 0; \
    a->capacity = initialCapacity; \
} \
void insert##n(n *a, ty element) { \
    if (a->used == a->capacity) { \
        a->capacity *= 2; \
        a->array = realloc(a->array, a->capacity * sizeof(ty)); \
    } \
    a->array[a->used++] = element; \
} \
void free##n(n *a) { \
    free(a->array); \
    a->array = NULL; \
    a->used = a->capacity = 0; \
}

make_wrapper(IntArray, int)
make_wrapper(FloatArray, float)
make_wrapper(CharArray, char)
make_wrapper(DoubleArray, double)
make_wrapper(VoidPtrArray, void*)

void intArrayExample() 
{
    IntArray a;
    initIntArray(&a, 5);
    for (int i = 0; i < 10; i++) {
        insertIntArray(&a, i);
    }

    for (size_t i = 0; i < a.used; i++) {
        printf("%d ", a.array[i]);
    }
    printf("\n");
    freeIntArray(&a);
}

void floatArrayExample() 
{
    FloatArray a;
    initFloatArray(&a, 5);
    for (int i = 0; i < 10; i++) {
        insertFloatArray(&a, (float) i);
    }

    for (size_t i = 0; i < a.used; i++) {
        printf("%.7f ", a.array[i]);
    }
    printf("\n");
    freeFloatArray(&a);
}

void charArrayExample()
{
    CharArray a;
    initCharArray(&a, 5);
    for (int i = 97; i < 102; i++) {
        insertCharArray(&a, (char) i); // adds a,b,c,d,e by using ASCII
    }
    
    for (size_t i = 0; i < a.used; i++) {
        printf("%c ", a.array[i]);
    }
    printf("\n");
    freeCharArray(&a);
}

void doubleArrayExample()
{
    DoubleArray a;
    initDoubleArray(&a, 5);
    for (int i = 0; i < 10; i++) {
        insertDoubleArray(&a, (double) i);
    }

    for (size_t i = 0; i < a.used; i++) {
        printf("%.15f ", a.array[i]);
    }
    printf("\n");
    freeDoubleArray(&a);
}

void voidPtrArrayExample()
{
    VoidPtrArray a;
    initVoidPtrArray(&a, 5);
    for (int i = 0; i < 10; i++) {
        void *element;
        insertVoidPtrArray(&a, element);
    }

    for (size_t i = 0; i < a.used; i++) {
        printf("%p ", a.array[i]);
    }
    printf("\n");
    freeVoidPtrArray(&a);
}

int main()
{
    intArrayExample();
    floatArrayExample();
    charArrayExample();
    doubleArrayExample();
    voidPtrArrayExample();
    return 0;
}
