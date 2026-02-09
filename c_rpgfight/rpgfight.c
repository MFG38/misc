#include <stdio.h>
#include <stdbool.h>

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
    i = (i + 1) % 64;
    return rng[i];
}

void DoDamage(struct Character *source, struct Character *target)
{
    int damage = source->atk + (rng[i] % 5);
    target->curHP -= damage;

    fprintf(stdout, "%s hits %s for %i damage!\n", source->name, target->name, damage);
}

void DoHeal(struct Character *target)
{
    int heal = 4 + (rng[i] % 4);
    target->curHP += heal;

    if(target->curHP > target->maxHP) {
        target->curHP = target->maxHP;
    }

    fprintf(stdout, "%s heals for %i HP!\n", target->name, heal);
}

int main()
{
    char command[2];

    while(enemy.curHP > 0)
    {
        fprintf(stdout, "Your HP: %i\nEnemy's HP: %i\n", player.curHP, enemy.curHP);
        fprintf(stdout, "What do you wish to do? [A]ttack / [H]eal) / [S]kip turn / View [R]NG Table Index\n");
        scanf("%s", command);

        switch(command[0]) {
            case 'a':
                DoDamage(&player, &enemy);
                GetNextRNGIndex();
                DoDamage(&enemy, &player);
                GetNextRNGIndex();
                break;
            case 'h':
                DoHeal(&player);
                GetNextRNGIndex();
                DoDamage(&enemy, &player);
                GetNextRNGIndex();
                break;
            case 's':
                DoDamage(&enemy, &player);
                GetNextRNGIndex();
                break;
            case 'r':
                fprintf(stdout, "RNG table is at index %i\n", i);
                break;
        }

        if(enemy.curHP <= 0) fprintf(stdout, "You won!\n");
        else if(player.curHP <= 0) fprintf(stdout, "You lost...\n");
    }

    return 0;
}

