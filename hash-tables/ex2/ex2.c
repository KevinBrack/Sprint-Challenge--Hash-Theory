#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  char *start = "NONE";
  char *current_destination;
  int count = 0;

  // populate the hash table with tickets
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // start with source of NONE and loop through tickets
  // appending the route with each destination, until you
  // reach a destination of NONE

  while (strcmp(current_destination, "NONE") != 0)
  {
    if (count == 0)
    {
      current_destination = hash_table_retrieve(ht, start);
      route[count] = current_destination;
      count++;
    }
    else
    {
      current_destination = hash_table_retrieve(ht, current_destination);
      route[count] = current_destination;
      count++;
    }
  }

  // debugging
  for (int i = 1; i < length; i++)
  {
    printf("route %d %s\n", i, route[i]);
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
