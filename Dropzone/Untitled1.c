#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int energy = 10;

int armour = 9;

int N = 3;

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
        //printf("roll for 0 damage is %d\n", roll);
        return 0;
    }
    else if(rollneeded()<=roll)
    {
        if(roll>=rollneeded()+2)
        {
            //printf("roll for 2 damage is %d\n", roll);
            return 2;
        }
        else
        {
            //printf("roll for 1 damage is %d\n", roll);
            return 1;
        }
    }
}

int storecombos(int *array, int iteration, int damage)
{
    int i;
    int newdamage;
    if(iteration<=N)
    {
        for(i = 1;i<=D;i++)
        {
            newdamage = DamageFromDice(i) + damage;
            storecombos(array, iteration+1,newdamage);
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

    // /*test function*/ printf("damage is %d\n", DamageFromDice(6));

    int *array;
    array = (int *)calloc((N*2+1), sizeof(int));
    countcombos(array);
    int i;
    for(i=0;i<=N*2;i++)
    {
        printf("probability of %d = %lf\n", i, ((double)array[i])/pow(6,N));
    }

    return 0;
}
