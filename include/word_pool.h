#ifndef __WORD_POOL_H__
#define __WORD_POOL_H__
typedef struct word_pool_{
    char string[20];
}word_t;


#define WORD_LIST \
    WORD_LIST_FILL("COMPUTER"),\
    WORD_LIST_FILL("COOL"),\
    WORD_LIST_FILL("BATMAN"),\
    WORD_LIST_FILL("SCIENCE"),\
    WORD_LIST_FILL("STATION"),\
    WORD_LIST_FILL("SUBMISSION"),\
    WORD_LIST_FILL("FRICTIONAL"),\
    WORD_LIST_FILL("TUBELIGHT"),\
    WORD_LIST_FILL("TRANSMISSION"),\
    WORD_LIST_FILL("COORDINATION"),\


#endif //__WORD_POOL_H__

