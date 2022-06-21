#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "bash.h"
#include "skiplist.h"

#define TEST_SKIPLIST(func) \
    do { \
    zskiplist* zsl = zslCreate(); \
    func(zsl); \
    zslFree(zsl); \
    printf("------------------------\n");\
} while(0)

void testInsert(zskiplist* zsl)
{
	zslInsert(zsl, 1.1, "key_1");
	zslInsert(zsl, 1.2, "key_2");
	zslInsert(zsl, 1.3, "key_3");

    assert(3 == zsl->length);
	zslDump(zsl);
}

void testDeleteByScoreAndKey(zskiplist* zsl)
{
	zslInsert(zsl, 1.1, "key_1");
	zslInsert(zsl, 1.2, "key_2");
	zslInsert(zsl, 1.3, "key_3");
    
    const char* key = "key_1";
    double score = 1.1;
    
    int ret = zslDelete(zsl, score, key, NULL);
    assert(1 == ret);
    zslDump(zsl);
}

int	main(int argc, char **argv)
{
    srand((unsigned)time(NULL));

    {
		TEST_SKIPLIST(testInsert);
		TEST_SKIPLIST(testDeleteByScoreAndKey);
    }

    return 0;
}
