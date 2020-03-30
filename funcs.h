#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

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

void updateMatrix(User mat[][MAX_COL], int row, int col);

void displayCounts(int* counts);

void makeDonation(User mat[][MAX_COL], int row, int col, int* counts);

