// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Function Declaration
void recursive_shuffle(CardDeck, char *, int , char *, int, int ); //Defined Helper Function.

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck) //Probable source of error 
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks

	// starting from i = 0 -> size-1 copying into upper deck and lower decks
  for (int i = 0; i < orig_deck.size - 1; ++i)//Check for Increment.
  {
    // For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
    // Update the size of the upper and lower decks after copying each element.
    // For example: upper_deck[i].size = i+1;
    strncpy((upper_deck[i]).cards, orig_deck.cards, i + 1);
    upper_deck[i].size =  i + 1;

    // Similarly perform the string copy, and size update operation on the lower deck.
    //For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
    // For example: lower_deck[i].size = orig_deck.size -i - 1;
    strncpy((lower_deck[i]).cards, orig_deck.cards + i +1,orig_deck.size -i-1);
    lower_deck[i].size = orig_deck.size - i - 1;

  }

  return;
}
#endif

#ifdef TEST_INTER
void interleave(CardDeck upper_deck, CardDeck lower_deck) //Check Interleave: 
{
  // Follow instructions in the README, to understand the working of the recursive function.
  //Create Shuffled deck to hold each shuffled permutation.

  CardDeck shuffled_deck;
  shuffled_deck.size = upper_deck.size + lower_deck.size; 
  
  for (int index = 0; index < shuffled_deck.size; ++index) //Initialize all elements to 0.
  {
    shuffled_deck.cards[index] = 0;
  }

  //Indecies for upper and lower decks.
  int upper_deck_index = upper_deck.size; //Stores the index of the largest card in the upper deck.
  int lower_deck_index = lower_deck.size; //Stores the index of the largest card in the lower deck.
  int shuffled_deck_index = 0; //Stores the index of the shuffled array where a card is to be placed.
  
  char * upper_deck_cards = NULL;
  char * lower_deck_cards = NULL;

  upper_deck_cards = malloc(upper_deck_index * sizeof(upper_deck.cards[0])); 
  lower_deck_cards = malloc(lower_deck_index * sizeof(lower_deck.cards[0]));

  for (int i = 0; i < upper_deck.size; ++i)
  {
    upper_deck_cards[i] = upper_deck.cards[i];
  }

  for (int i = 0; i < lower_deck.size; ++i)
  {
    lower_deck_cards[i] =  lower_deck.cards[i];
  }

  //Use print_deck(…) to print each resulting order.
  //Tip: There should be no uncertainty in this function.
  //If you think a random number generator is needed, you are on the wrong track.
  //Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
  //you could use memcpy(…).
  //The = operator will simply copy the address, not the elements themselves.

  recursive_shuffle(shuffled_deck, upper_deck_cards, upper_deck_index, lower_deck_cards, lower_deck_index, shuffled_deck_index);
  //free(upper_deck_cards);
  free(lower_deck_cards);
  return;
}

void recursive_shuffle(CardDeck shuffled_deck, char * upper_deck_cards, int upper_deck_index,  char * lower_deck_cards, int lower_deck_index, int shuffled_deck_index) //Check Recursive Shuffle: OK 
{
  //Terminating conditions
  if (upper_deck_index <= 0)
  {
    for (int i = 0; i < lower_deck_index; ++i)
    {
      shuffled_deck.cards[shuffled_deck_index] = lower_deck_cards[i];
      ++shuffled_deck_index;
    }
    print_deck(shuffled_deck);
    return;
  }
  if (lower_deck_index <= 0)
  {
    for (int i = 0; i < upper_deck_index; ++i)
    {
      shuffled_deck.cards[shuffled_deck_index] = upper_deck_cards[i];
      ++shuffled_deck_index;
    }
    print_deck(shuffled_deck);
    return;
  }

  //Recursive Function Calls
  shuffled_deck.cards[shuffled_deck_index] = lower_deck_cards[strlen(lower_deck_cards) - lower_deck_index]; //Pick Element from Lower Deck.
  recursive_shuffle(shuffled_deck, upper_deck_cards, upper_deck_index, lower_deck_cards + 1, lower_deck_index - 1, shuffled_deck_index + 1);

  shuffled_deck.cards[shuffled_deck_index] = upper_deck_cards[strlen(upper_deck_cards) - upper_deck_index]; //Pick Element from Upper Deck.
  recursive_shuffle(shuffled_deck, upper_deck_cards + 1, upper_deck_index - 1, lower_deck_cards, lower_deck_index, shuffled_deck_index + 1);

  
}
#endif

#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck) //Check Shuffle: OK
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
