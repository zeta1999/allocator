#ifndef CHUNK_H
#define CHUNK_H

#include <stddef.h>
#include <stdint.h>

#define CHUNK_SIZE ((size_t)4096 * 1024)
#define CHUNK_MASK ((size_t)(CHUNK_SIZE - 1))
// Return the smallest chunk size multiple that is >= s.
#define CHUNK_CEILING(s) (((s) + CHUNK_MASK) & ~CHUNK_MASK)

/* Return the chunk address for allocation address a. */
#define CHUNK_ADDR2BASE(a) ((void *)((uintptr_t)(a) & ~CHUNK_MASK))

void chunk_init(void);
void *chunk_alloc(void *new_addr, size_t size, size_t alignment);
void chunk_free(void *chunk, size_t size);

#endif
