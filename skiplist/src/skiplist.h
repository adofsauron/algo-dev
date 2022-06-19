#ifndef __SKIPLIST_H__
#define __SKIPLIST_H__

#include <stdint.h>
#include <limits.h>

#include "bash.h"

#define ZSKIPLIST_MAXLEVEL 64 
#define ZSKIPLIST_P 0.25      

typedef struct zskiplistNode {
    char* ele;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned long span;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

typedef struct {
	double min, max;
	int minex, maxex;
} zrangespec;

typedef struct {
	char* min, max;     
	int minex, maxex;
} zlexrangespec;


struct sharedObjectsStruct {
    char* minstring, maxstring;
};

zskiplist* zslCreate(void);
void zslFree(zskiplist* zsl);

zskiplistNode* zslInsert(zskiplist* zsl, double score, const char* key);
zskiplistNode* zslFirstInRange(zskiplist* zsl, zrangespec* range);
zskiplistNode* zslLastInRange(zskiplist* zsl, zrangespec* range);
zskiplistNode* zslGetElementByRank(zskiplist* zsl, unsigned long rank);
unsigned long zslGetRank(zskiplist* zsl, double score, const char* key);
zskiplistNode* zslUpdateScore(zskiplist* zsl, double curscore, const char* key, double newscore);
int zslDelete(zskiplist* zsl, double score, const char* key, zskiplistNode** node);
void zslDeleteNode(zskiplist* zsl, zskiplistNode* x, zskiplistNode** update);

void zslDump(zskiplist* zsl);

#endif // __SKIPLIST_H__
