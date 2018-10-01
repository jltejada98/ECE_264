// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Function Definitions
void recursive_shuffle(CardDeck, CardDeck , CardDeck, int, int);

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks

	// starting from i = 1 -> size-1 copying into upper deck and lower decks
  for (int i = 1; i <= orig_deck.size - 1; ++i)
  {
    // For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
    // Update the size of the upper and lower decks after copying each element.
    // For example: upper_deck[i].size = i+1;
    strncpy((upper_deck[i].cards), orig_deck.cards, i+1);
    upper_deck[i].size =  i+1;

    // Similarly perform the string copy, and size update operation on the lower deck.
    //For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
    // For example: lower_deck[i].size = orig_deck.size -i - 1;
    strncpy((lower_deck[i]).cards, (orig_deck.cards + i+1),(orig_deck.size - i-1));
    lower_deck[i].size = orig_deck.size - (i - 1);

  }
  return;
}
#endif

#ifdef TEST_INTER
void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
  // Follow instructions in the README, to understand the working of the recursive function.
  //Create Shuffled deck to hold each shuffled permutation.
  CardDeck shuffled_deck[MAX_SIZE];
  
  for (int index = 0; index < MAX_SIZE; ++index)
  {
    shuffled_deck->cards[index] = 0;
  }
  shuffled_deck->size = MAX_SIZE;

  //Indecies for upper and lower decks.
  int upper_deck_index = 0;
  int lower_deck_index = 0;

  recursive_shuffle(upper_deck, lower_deck, *shuffled_deck, lower_deck_index, upper_deck_index);

  // Use print_deck(…) to print each resulting order.
  // Tip: There should be no uncertainty in this function.
      //If you think a random number generator is needed, you are on the wrong track.
  // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
      //you could use memcpy(…).
      //The = operator will simply copy the address, not the elements themselves.
}
#endif

#ifdef TEST_RECURSIVESHUFFLE
void recursive_shuffle(CardDeck upper_deck, CardDeck lower_deck, CardDeck shuffled_deck, int lower_deck_index, int upper_deck_index)
{
  //Terminating condition 
  if((lower_deck_index >= lower_deck.size) || (upper_deck_index >= upper_deck.size))
  {
    
    if (lower_deck_index >= lower_deck.size)
    {
      for (int i = upper_deck_index; i < upper_deck.size; ++i)
      {
        shuffled_deck.cards[lower_deck_index + i] = upper_deck.cards[i];
      }
    }
    else
    {
      for (int i = lower_deck_index; i < lower_deck.size; ++i)
      {
        shuffled_deck.cards[upper_deck_index + i] = lower_deck.cards[i];
      }
    }

    print_deck(shuffled_deck);
    return;
  }

  if (lower_deck_index < lower_deck.size)
  {
    shuffled_deck.cards[lower_deck_index + upper_deck_index] = lower_deck.cards[lower_deck_index];
    recursive_shuffle(upper_deck, lower_deck, shuffled_deck, lower_deck_index + 1, upper_deck_index); 
  }

  if (upper_deck_index < upper_deck.size)
  {
    shuffled_deck.cards[lower_deck_index + upper_deck_index] = lower_deck.cards[upper_deck_index];
    recursive_shuffle(upper_deck, lower_deck, shuffled_deck, lower_deck_index, upper_deck_index + 1);
  }

  return;
}
#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
{
  // declare a variable to hold the number of pairs
  int numpairs = orig_deck.size - 1;  

  // we can say that we have only size-1 possibility of pairs
  // if number of pairs == 0; return;
  if(numpairs == 0)
  {
    return;
  }
  
	// instantiate pointers to hold both upper and lower decks (after division)
	// For example: CardDeck * upper_deck = NULL;
  CardDeck *upper_deck = NULL;
  CardDeck *lower_deck = NULL;

	// allocate memory based on number of pairs
	//For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
  upper_deck = malloc(numpairs*sizeof(CardDeck));
  lower_deck = malloc(numpairs*sizeof(CardDeck));

	// call divideDeck to fill upper_deck and lower_deck
  divide(orig_deck, upper_deck, lower_deck);


	//run a loop through all the pairs
  for (int i = 0; i < numpairs; ++i)
  {
    // for each pair of upper and lower deck call interleave()
    // For example: interleave(upper_deck[i],lower_deck[i]);
    interleave(upper_deck[i], lower_deck[i]);   
  }


  // free memory allocated to upper and lower deck. 
  free(upper_deck);
  free(lower_deck);
}
#endif
