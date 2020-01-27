#include<stdlib.h>

#include "hangman.h"
#include "word_pool.h"

#ifdef WORD_LIST_FILL
#undef WORD_LIST_FILL
#endif
#define WORD_LIST_FILL( str_ ) {\
    .string = str_, \
} \

word_t words[] = {
   WORD_LIST
};

void display(int len){
    int i = 0;
    for(i=0; i<len;i++) {
        if(final_word[i] == 0){
            printf("_");
        }else {
            printf("%c",final_word[i]);
        }
    }
    printf("\n");
}
#if 0
void display(const Game *game, const char *guess){
    int wg=game->wg;
    printf("\033[H\033[J ┏━━━┓\n");
    printf(" ┃   │\n");
    printf(" ┃   %c\n",   wg<1?' ':'O');
    printf(" ┃  %c%s%c\n",wg<3?' ':'/', wg<2?" ":"│", wg<4?' ':'\\');
    printf(" ┃  %c %c\n", wg<5?' ':'/',               wg<6?' ':'\\');
    printf(" ┃\n");
    printf("┏┻━━━━━━┓\n┃       ┗━┓\n┗━━━━━━━━━┛\n");
    printf("wrong guesses %d: %s\n", wg, game->ws);
    printf("word: %s\n",guess);
}
#endif
int main(){
    uint8_t c,i;
    uint32_t len = 0, idx = 0;
    printf("%s\n", words[0].string);

    //Initialization
    //hash table
    ht = malloc(sizeof(hashtable_t));
    if (!ht){
        printf ("failed to malloc hash table\n");
    }
    //initialized with 0
    memset(guessed_letter, 0, (sizeof(uint8_t)*26));
    memset(final_word, 0, (sizeof(uint8_t)*26));

    len = strlen(words[0].string);

    for(i=0; i<len; i++) {
        hash_insert(words[0].string[i], i);
    }

    printf("GAME_START\n");
    while(len != 0){
        printf("Guess the word\n");
        c = getc(stdin);
        c = tolower(c);
        if (c < 'a' || c > 'z'){
            printf("Type letters...\n");
            continue;
        } 
        if(guessed_letter[c-97] == TRUE){
            printf("Letter Already guessed\n");
            continue;
        } else {
            guessed_letter[c-97] = TRUE;
        }

        //check wheather letter present in hash table
        if(TRUE == hash_search(c)){
            while(!is_empty(c)){
              idx = hash_del(c);
              final_word[idx] = c;
              len--;
            }
        }
        display(strlen(words[0].string));
    }
#if 0
    hash_insert(ht, 'C', 0);
    hash_insert(ht, 'O', 1);
    hash_insert(ht, 'O', 2);
    hash_insert(ht, 'L', 3);

    printf("%d\n",ht->tbl[2].head->idx);
    printf("%d\n",ht->tbl[14].head->idx);
    printf("%d\n",((index_list_t*)(ht->tbl[14].head->next))->idx);
    printf("%d\n",ht->tbl[11].head->idx);
    //printf("Idx:%d:%d:%d:%d", ht->tbl[2].head->idx,ht->tbl[14].head->idx, ht->tbl[14].head->next->idx, ht->tbl[11].head->idx);
//    guess_arr
  //  word_hash
#endif
    return 0;
}
