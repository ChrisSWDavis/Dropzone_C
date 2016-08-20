#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int energy = 10;

int armour = 9;

int N = 1;

int D = 6;

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

int storecombos(int *array, int iteration, int damage)
{
    int i;
    if(iteration<=N)
    {
        for(i = 1;i<=D;i++)
        {
            damage = DamageFromDice(i) + damage;
            storecombos(array, iteration+1,damage);
        }
    }
    else
    {
        array[damage]++;
    }
    return 0;
}

int countcombos(int *array)
{
    int iteration = 1;
    storecombos(array, iteration, 0);

    return 0;
}

int main()
{

     /*test function*/ printf("damage is %d\n", DamageFromDice(6));

    int *array;
    array = (int *)calloc((N*2+1), sizeof(int));
    countcombos(array);
    int i;
    for(i=0;i<=N*2;i++)
    {
        printf("damage from %d = %d\n", i, DamageFromDice(i));
        printf("number of %ds = %d\n", i, array[i]);
    }

    return 0;
}
