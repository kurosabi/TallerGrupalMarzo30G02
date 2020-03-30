#include <stdio.h>

#define MAX_CAP 100;

typedef struct User User;
typedef enum BloodType BloodType;

enum BloodType
{
    a+,
    a-,
    b+,
    b-
    ab+,
    ab-,
    o+,
    o-
};

struct User
{
    char name[20];
    BloodType type;
    int donations;
};

void updateUser(User* u);

void addUser(User mat[][MAX_CAP], int* groupSizes, int cap);

void displayCounts(int* counts);

void searchByType(User mat[][MAX_CAP], int* groupSizes);

void makeDonation(User mat[][MAX_CAP], int *counts, int cap);