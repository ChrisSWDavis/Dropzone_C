#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int energy = 10;

int armour = 9;

int N = 1;

// function to find the necessary minimum roll needed for a given armour and energy
int rollneeded()
{
    return armour - energy + 5;
}

int DamageFromDice(int roll)
{
    if(rollneeded()>roll)
    {
        return 0;
    }
    else if(rollneeded()<=roll)
    {
        if(roll>=rollneeded()+2)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}

int main()
{

    // /*test function*/ printf("damage is %d\n", DamageFromDice(3));

    return 0;
}
