//
// Update this file as indicated.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "shuffle.h"

#ifdef TEST_MAIN
int main(int argc, char ** argv) //Check Main: OK
{
	char deck[MAX_SIZE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	
	// Check for missing inputs
  if (argc != 2)
  {
    return EXIT_FAILURE;
  }

	// Create a structure variable (corresponding to the original deck)
  CardDeck orig_deck;

  // Ensure you initialize the srtuct variable "size" with MAX_SIZE (declared in utility.h)
  orig_deck.size = strtol(argv[1], NULL, 10); 

  // initialize cards to 0 since it will be populated using memcpy(..)
  for (int index = 0; index < orig_deck.size; ++index)
  {
    orig_deck.cards[index] = 0;
  }

  // Use memcpy(),
  //For example: memcpy(orig_deck.cards, deck, MAX_SIZE * sizeof(orig_deck.cards[0]));
  // Read the number of cards from the terminal input
  // For example orig_deck.size = strtol(argv[1], NULL, 10);
  memcpy(orig_deck.cards, deck, orig_deck.size*sizeof(orig_deck.cards[0])); //Test using orig_deck.size

	//call shuffle(orig_deck);
  shuffle(orig_deck); 

	return EXIT_SUCCESS;
}
#endif
