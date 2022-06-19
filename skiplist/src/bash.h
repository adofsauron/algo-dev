#ifndef __BASE_H__
#define __BASE_H__

#include <stdlib.h>

void* __malloc(size_t size);
void* __realloc(void* ptr, size_t size);
void __free(void* ptr);

#define zmalloc __malloc
#define zcalloc __realloc
#define zfree __free

#endif // __BASE_H__