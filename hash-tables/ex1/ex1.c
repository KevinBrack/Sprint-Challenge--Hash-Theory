#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "hashtable.h"
#include "ex1.h"

// Changing name of struct to not conflict with
// the function name

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));

  // test code to see what I am working with
  printf("ARRAY LENGTH %d\n", length);
  printf("weights = [");
  for (int i = 0; i < length; i++)
  {
    // printf("WEIGHT %d\n", weights[i]);
    printf("%d,", weights[i]);
    hash_table_insert(ht, weights[i], i);
  }
  printf("]\n");

  // loop over the origional array and check if there is a
  // valid response from the HT for the index of the difference

  for (int i = 0; i < length; i++)
  {
    if (hash_table_retrieve(ht, limit - weights[i]) != -1)
    {
      int ht_response = hash_table_retrieve(ht, limit - weights[i]);
      answer->index_1 = i;
      answer->index_2 = ht_response;
      printf("%d + %d meet the limit %d\n", weights[answer->index_1], weights[answer->index_2], limit);
      return answer;
    }
  }

  // WORKING RESPONSE LOOP SHOWING THE INDEX OF EACH ITEM IN THE ARR//
  // for (int i = 0; i < length; i++)
  // {
  //   // printf("WEIGHT %d\n", weights[i]);
  //   int ht_response = hash_table_retrieve(ht, weights[i]);
  //   printf("HT RESPONSE %d\n", ht_response);
  // }

  // WORKING LOOP GETTING ALL THE RESULTS FROM HT//
  // for (int i = 0; i < ht->capacity; i++)
  // {
  //   if (ht->storage[i] != NULL)
  //   {
  //     printf("HASH TABLE INDEX %d KEY %d VALUE %d\n", i, ht->storage[i]->key, ht->storage[i]->value);
  //   }
  // }

  // for (int i = 0; weights[i] != NULL; i++)
  // {
  //   hash_table_insert(ht, weights[i], i);
  // }
  // for (int i = 0; i < ht->capacity - 1; i++)
  // {
  //   if (ht->storage[i] != NULL)
  //   {
  //     printf("HASH TABLE INDEX %d KEY %s VALUE %s\n", ht->storage[i], ht->storage[i]->key, ht->storage[i]->value);
  //   }
  // }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif
