#ifndef __HANGMAN_H__
#define __HANGMAN_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "hash_table.h"

#define TRUE 1
#define FALSE 0

//Global Variables

//Hash Table
hashtable_t  *ht;
//Array to store words already guessed
uint8_t guessed_letter[26];
//Array to store the guessed word
uint8_t final_word[26];

#endif //__HANGMAN_H__
