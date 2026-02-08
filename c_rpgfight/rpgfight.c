#include <stdio.h>

#define RNG_TABLE_SIZE  64

struct Character {
    char *name;
    int curHP;
    int maxHP;
    int atk;
};

struct Character player = {"Player", 50, 50, 6};
struct Character enemy = {"Bad Guy", 40, 40, 3};

int rng[RNG_TABLE_SIZE] = {
    46, 7,  55, 31, 27, 4,  52, 63,
    17, 2,  11, 5,  56, 18, 16, 42,
    38, 48, 28, 1,  15, 39, 44, 10,
    12, 33, 59, 30, 8,  3,  19, 20,
    6,  24, 47, 45, 54, 35, 25, 29,
    57, 21, 49, 58, 43, 53, 22, 32,
    64, 37, 41, 51, 50, 62, 13, 26,
    9,  40, 23, 60, 34, 36, 14, 61
};

int i = 0;

int GetNextRNGIndex()
{
    i++;
    return rng[i] % RNG_TABLE_SIZE;
}

void DoDamage(struct Character source, struct Character target)
{
    int damage;

    target.curHP -= (source.atk + (rng[i] % 5));
}

int main()
{
    return 0;
}
