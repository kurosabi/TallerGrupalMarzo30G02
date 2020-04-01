#include <stdio.h>
#include <string.h>

#define MAX_CAP 100
#define GROUP 8

typedef struct User User;
typedef enum BloodType BloodType;

enum BloodType
{
    ap,
    am,
    bp,
    bm,
    abp,
    abm,
    op,
    om
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

void infoDonation(int n);

void showMaxDonation(User mat[][MAX_CAP], int *groupSizes);