#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

void delay(unsigned int mSeconds)
{
    clock_t goal = mSeconds + clock();
    while(goal > clock());
}

void printScreen(char arr[8][8], int hit, int miss)
{
    cout << endl << endl << endl;
    cout << "\t\t _____________________________________________" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int a = 0; a < 8; a++)
        {
            if (a == 0)
            {
                cout << "\t\t( " << arr[i][a] << "     ";
            }
            else if (a == 7)
            {
                cout << arr[i][a] << " )";
            }
            else
            {
                cout << arr[i][a] << "     ";
            }
        }
        if (i == 7)
        {
            cout << endl <<"\t\t _____________________________________________" << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << endl << endl << endl << endl << endl;
    cout << "________________________________________________________________________________" << endl;
    cout << "\t\t\t HIT: " << hit << "\t \t MISS: " << miss;
    cout << endl << endl << endl;
}

char generateRandChar()
{
    char abc = rand() % 26 + 97;
    return abc;
}

int generateRandCol()
{
    int num = rand() % 8;
    return num;
}

void fallDown(char arr[8][8], int row, int &miss)
{
    int posCol = -1;
    int posRow = -1;

    if (row > 8)
        row = 8;
    for (int i = 0; i < row; i++)
    {
        for (int a = 0; a < 8; a++)
        {
            if (arr[i][a] != ' ')
            {
                if (i == posRow && a == posCol)
                {
                    posRow = -1;
                    posCol = -1;
                }
                else if(i == 7)
                {
                    arr[i][a] = ' ';
                    miss++;
                }
                else
                {
                    arr[i+1][a] = arr[i][a];
                    arr[i][a] = ' ';
                    posRow = i+1;
                    posCol = a;
                }
            }
        }
    }
}

void checkHit(char arr[8][8], char ch, int &hit)
{
    for (int i = 0; i < 8; i++)
    {
        for (int a = 0; a < 8; a++)
        {
            if (arr[i][a] == ch)
            {
                hit++;
                arr[i][a] = ' ';
                return;
            }
        }
    }
}

void game()
{
    srand(time(NULL));
    char arr[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int a = 0; a < 8; a++)
        {
            arr[i][a] = ' ';
        }
    }
    int hit = 0, miss = 0, counter = 0;
    arr[0][generateRandCol()] = generateRandChar();
    char ch;
    while (hit!= 10 && miss != 10)
    {
        system("cls");
        if (counter != 1)
        {
            fallDown(arr,counter, miss);
        }
        if(counter%3 == 0)
        {
            arr[0][generateRandCol()] = generateRandChar();
        }

        bool keepGoing = true;
        char key = ' ';
        while(keepGoing)
        {
            while(_kbhit())
            {
                ch = getch();
            }
            keepGoing = false;
        }
        if (ch == 27)
            break;
        checkHit(arr, ch, hit);
        printScreen(arr, hit, miss);
        delay(300);
        counter++;
    }
    if (hit == 10)
    {
        cout << "YOU WIN!!!" << endl;
    }
    else if(miss == 10)
    {
        cout << "YOU LOSE! boo hoo" << endl;
    }
    else
        cout << "YOU SURRENDERED!" << endl;
}

int main()
{
    game();
    return 0;
}