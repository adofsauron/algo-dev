#include <assert.h>

#include "bash.h"

void* __malloc(size_t size) {
	void* ptr = malloc(size);
	assert(ptr != NULL);
	return ptr;
}

void* __realloc(void* ptr, size_t size) {
	void* nptr = realloc(ptr, size);
	assert(nptr != NULL);
	return nptr;

}

void __free(void* ptr) {
	if (!ptr) {
		return;
	}

	free(ptr);
	ptr = NULL;
}