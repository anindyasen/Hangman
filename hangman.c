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

//generate random index to select word
int gen_index(int low, int high) 
{ 
    srand(time(0));
    
    return ((rand() % (high - low + 1)) + low); 
} 

void display(uint8_t wg_cnt, int len){
    int i = 0;
    printf("\033[H\033[J ┏━━━┓\n");
    printf(" ┃   │\n");
    printf(" ┃   %c\n",   wg_cnt<1?' ':'O');
    printf(" ┃  %c%s%c\n",wg_cnt<3?' ':'/', wg_cnt<2?" ":"│", wg_cnt<4?' ':'\\');
    printf(" ┃  %c %c\n", wg_cnt<5?' ':'/',               wg_cnt<6?' ':'\\');
    printf(" ┃\n");
    printf("┏┻━━━━━━━┓\n┃   %d    ┗━┓\n┗━━━━━━━━━━┛\n",(WRONG_GUESS_CNT-wg_cnt));

    for(i=0; i<len;i++) {
        if(final_word[i] == 0){
            printf("_ ");
        }else {
            printf("%c ",final_word[i]);
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
    uint8_t c,i, wrg_guess_cnt = 0;
    uint32_t len = 0, idx = 0, gidx = 0;

    //Initialization
    //hash table
    ht = malloc(sizeof(hashtable_t));
    if (!ht){
        printf ("failed to malloc hash table\n");
    }
    //initialized with 0
    memset(guessed_letter, 0, (sizeof(uint8_t)*26));
    memset(final_word, 0, (sizeof(uint8_t)*26));
    
    //randomly generating index to select word
    gidx = gen_index(0/*low*/,9/*high*/);
    printf("%s\n", words[gidx].string);
    len = strlen(words[gidx].string);

    for(i=0; i<len; i++) {
        hash_insert(words[gidx].string[i], i);
    }

    wrg_guess_cnt = WRONG_GUESS_CNT;

    printf("\033[H\033[J \n");
    printf("GAME START\n");
    display(0, strlen(words[gidx].string));
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
        else {
            printf("WRONG GUESS...\n");
            if (wrg_guess_cnt != 0) {
                wrg_guess_cnt--;
            }
            else {
                printf("GAME OVER\n");
                return 0;
            }
        }
        display((WRONG_GUESS_CNT - wrg_guess_cnt),strlen(words[gidx].string));
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
