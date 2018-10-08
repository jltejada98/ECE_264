// Please modify this file as required

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// You can add more functions, structures, and variables to this file.  
// Helper functions must start with '_'.
void _recursive_shuffle(CardDeck, CardDeck, int , CardDeck, int, int, int); //Defined Helper Function.

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck* upper_deck, CardDeck* lower_deck)
{
  //Dividing the desks into the way mentioned in the document - as lower and upper
  //Use a loop from index i to orig_deck.size - 1
  //starting from 1 -> size-1 copying into upper deck and lower decks
  for (int i = 0; i < orig_deck.size - 1; ++i)
  {
    //strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
    //update size of upper deck
    //For example: upper_deck[i].size = i+1;
    //update size of lower deck:
    //For example: lower_deck[i].size = orig_deck.size -i -1;

    strncpy((upper_deck[i]).cards, orig_deck.cards, i + 1);
    upper_deck[i].size =  i + 1;
    
    strncpy((lower_deck[i]).cards, orig_deck.cards + i +1,orig_deck.size -i-1);
    lower_deck[i].size = orig_deck.size - i - 1;
  }

  return;
}
#endif

#ifdef TEST_INTER
//repeat holds the number of shuffles yet to be performed.
//after the interleave operation has been completed, you will recursively call
//repeat_shuffle(...) with a decremented value of repeat.
void interleave(CardDeck upper_deck, CardDeck lower_deck, int repeat)
{
  // Follow instructions in the README, to understand the working of the recursive function.
  // when the newly shuffled deck is complete:
  //you will perform another k-1 rounds of shuffling with the new deck

  // Tip: There should be no uncertainty in this function.
  //If you think a random number generator is needed, you are on the wrong track.
  // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
  //you could use memcpy(…).
  //The = operator will simply copy the address, not the elements themselves.
  CardDeck shuffled_deck;
  shuffled_deck.size = upper_deck.size + lower_deck.size; 
  
  for (int index = 0; index < shuffled_deck.size; ++index) //Initialize all elements to 0.
  {
    shuffled_deck.cards[index] = 0;
  }

  //Indecies for upper and lower decks.
  int upper_deck_index = 0; //Stores the index of the largest card in the upper deck.
  int lower_deck_index = 0; //Stores the index of the largest card in the lower deck.
  int shuffled_deck_index = 0; //Stores the index of the shuffled array where a card is to be placed.

  _recursive_shuffle(shuffled_deck, upper_deck, upper_deck_index, lower_deck, lower_deck_index, shuffled_deck_index, repeat);
  return;
}

void _recursive_shuffle(CardDeck shuffled_deck, CardDeck upper_deck, int upper_deck_index, CardDeck lower_deck, int lower_deck_index, int shuffled_deck_index, int repeat) //Check Recursive Shuffle: OK 
{
  //Terminating conditions
  if (upper_deck_index >= upper_deck.size)
  {
    for (int i = lower_deck_index; i < lower_deck.size; ++i)
    {
      shuffled_deck.cards[shuffled_deck_index] = lower_deck.cards[i];
      ++shuffled_deck_index;
    }
    repeat_shuffle(shuffled_deck, repeat-1);
    return;
  }
  if (lower_deck_index >= lower_deck.size)
  {
    for (int i = upper_deck_index; i < upper_deck.size; ++i)
    {
      shuffled_deck.cards[shuffled_deck_index] = upper_deck.cards[i];
      ++shuffled_deck_index;
    }
    repeat_shuffle(shuffled_deck, repeat-1);
    return;
  }

  //Recursive Function Calls
  shuffled_deck.cards[shuffled_deck_index] = lower_deck.cards[lower_deck_index]; //Pick Element from Lower Deck.
  _recursive_shuffle(shuffled_deck, upper_deck, upper_deck_index, lower_deck, lower_deck_index + 1, shuffled_deck_index + 1, repeat);

  shuffled_deck.cards[shuffled_deck_index] = upper_deck.cards[upper_deck_index]; //Pick Element from Upper Deck.
  _recursive_shuffle(shuffled_deck, upper_deck, upper_deck_index + 1, lower_deck, lower_deck_index, shuffled_deck_index + 1, repeat);
}
#endif

#ifdef TEST_SHUF
//repeat holds the number of shuffles that are yet to be performed.
void shuffle(CardDeck orig_deck, int repeat)
{
  // declare a variable to hold the number of pairs
  // we can say that we have only size-1 possibility of pairs
  int numpairs = orig_deck.size - 1;

  // if number of pairs == 0; return;
  if (numpairs <= 0)
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
  // for each pair of upper and lower deck call interleave()
  // For example: interleave(upper_deck[i],lower_deck[i]);
  for (int i = 0; i < numpairs; ++i)
  {
    interleave(upper_deck[i], lower_deck[i], repeat);
  }

  // free memory allocated to upper and lower deck.
  free(upper_deck);
  free(lower_deck);

  return;
}
#endif

#ifdef TEST_RSHUF
void repeat_shuffle(CardDeck orig_deck, int k)
{
	//orig_deck contains a deck of cards, and it's size.
	//If (k ≤ 0), no shuffling, print the only possible outcome.
	//printDeck(orig_deck); and return
  if (k <= 0)
  {
    printDeck(orig_deck);
    return;
  }
  //TIP: Print only the results obtained after k rounds of shuffling
	// call shuffle(orig_deck);
  // TIP: In interleave(…), when the newly shuffled deck is complete, 
  //you will perform another k-1 rounds of shuffling with the new deck.
	shuffle(orig_deck, k);
  return;
}
#endif
