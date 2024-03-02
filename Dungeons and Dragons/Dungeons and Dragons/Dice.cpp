#include "Dice.h"

int Dice::roll()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    return rand() % 20 + 1;
}
