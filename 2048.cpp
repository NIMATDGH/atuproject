#include <bits/stdc++.h>

#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int num2(int q)
{
    if (q == 0)
    {
        return 1;
    }

    int v = 0;

    while (q > 0)
    {
        q = q / 10;
        v++;
    }
    return v;
}
void equal(int array[][4], int x[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = x[i][j];
        }
    }
}

void showmax(int max, int score)
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (i == 1 || i == 5)
            {
                if (j == 10)
                {
                    cout << " ";
                }
                else
                {
                    cout << char(254);
                }
            }
            else if (i == 2 || i == 4)
            {
                if (j == 1 || j == 9 || j == 11 || j == 19)
                {
                    cout << char(219);
                }
                else
                {
                    cout << " ";
                }
            }
            else if (i == 3)
            {
                if (j == 1 || j == 9 || j == 11 || j == 19)
                {
                    cout << char(219);
                }

                else if (j == 5 - num2(score) / 2)
                {
                    cout << score;
                    j += num2(score) - 1;
                }
                else if (j == 15 - num2(max) / 2)
                {
                    cout << max;
                    j += num2(max) - 1;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
int num(int q)
{
    if (q == 0)
    {
        return 0;
    }
    else
    {
        int v = 0;

        while (q > 0)
        {
            q = q / 10;
            v++;
        }
        return v;
    }
}
int max(int array[])
{
    int maxim = 0;
    for (int i = 0; i < 100; i++)
    {
        if (array[i] > maxim)
        {
            maxim = array[i];
        }
    }
    return maxim;
}
void zero(int array[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = 0;
        }
    }
}
bool checkwin(int array[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] == 64)
            {
                return true;
            }
        }
    }
    return false;
}
void randomvalue(int array[][4])
{
    int cordinatex, cordinatey, value;
    srand(time(0));
    while (true)
    {
        cordinatex = rand() % 4;
        cordinatey = rand() % 4;
        if (array[cordinatex][cordinatey] == 0)
        {
            value = (rand() % 2 + 1) * 2;
            array[cordinatex][cordinatey] = value;
            break;
        }
    }
}
void show(int x[][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "[";
        for (int j = 0; j < 4; j++)
        {
            if (x[i][j] != 0)
            {
                cout << x[i][j];
            }
            int space = 4 - num(x[i][j]);
            for (int z = 1; z <= space; z++)
            {
                cout << " ";
            }
            if (j != 3)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}
int movew(int array[][4])
{
    int s = 0;
    int x, y;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] != 0)
            {
                x = i;
                y = j;
                while (array[x - 1][y] == 0 && x > 0)
                {
                    array[x - 1][y] = array[x][y];
                    array[x][y] = 0;
                    x = x - 1;
                }

                if (array[x][y] == array[x - 1][y])
                {
                    array[x - 1][y] = array[x][y] + array[x][y];
                    s += array[x][y] + array[x][y];
                    array[x][y] = 0;
                }
            }
        }
    }
    return s;
}
int movea(int array[][4])
{
    int s = 0;
    int x, y;
    for (int j = 1; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (array[i][j] != 0)
            {
                x = i;
                y = j;

                while (array[x][y - 1] == 0 && y > 0)
                {
                    array[x][y - 1] = array[x][y];
                    array[x][y] = 0;
                    y = y - 1;
                }

                if (array[x][y] == array[x][y - 1])
                {
                    array[x][y - 1] = array[x][y] + array[x][y];
                    s += array[x][y] + array[x][y];
                    array[x][y] = 0;
                }
            }
        }
    }
    return s;
}
int moves(int array[][4])
{
    int s = 0;
    int x, y;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] != 0)
            {
                x = i;
                y = j;
                while (array[x + 1][y] == 0 && x < 3)
                {
                    array[x + 1][y] = array[x][y];
                    array[x][y] = 0;
                    x = x + 1;
                }

                if (array[x][y] == array[x + 1][y])
                {
                    array[x + 1][y] = array[x][y] + array[x][y];
                    s += array[x][y] + array[x][y];
                    array[x][y] = 0;
                }
            }
        }
    }
    return s;
}
int moved(int array[][4])
{
    int s = 0;
    int x, y;
    for (int j = 2; j >= 0; j--)
    {
        for (int i = 0; i < 4; i++)
        {
            if (array[i][j] != 0)
            {
                x = i;
                y = j;

                while (array[x][y + 1] == 0 && y < 3)
                {
                    array[x][y + 1] = array[x][y];
                    array[x][y] = 0;
                    y = y + 1;
                }

                if (array[x][y] == array[x][y + 1])
                {
                    array[x][y + 1] = array[x][y] + array[x][y];
                    s += array[x][y] + array[x][y];
                    array[x][y] = 0;
                }
            }
        }
    }
    return s;
}
bool checkdirection(int array[][4], char c)
{
    int array2[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array2[i][j] = array[i][j];
        }
    }
    if (c == 'w')
    {
        movew(array2);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (array2[i][j] != array[i][j])
                {
                    return true;
                }
            }
        }
    }
    else if (c == 's')
    {
        moves(array2);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (array2[i][j] != array[i][j])
                {
                    return true;
                }
            }
        }
    }
    else if (c == 'a')
    {
        movea(array2);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (array2[i][j] != array[i][j])
                {
                    return true;
                }
            }
        }
    }
    else if (c == 'd')
    {
        moved(array2);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (array2[i][j] != array[i][j])
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool checklose(int array[][4])
{
    if (checkdirection(array, 'w') || checkdirection(array, 's') || checkdirection(array, 'a') || checkdirection(array, 'd'))
    {
        return false;
    }
    return true;
}

int main()
{
    int array[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int array2[4][4];
    int history[100];
    int komaki = -1, komaki2 = -1, round = 0;
    char di = 'u';
    int score = 0;
    int maximum = 0;

    for (int i = 0; i < 100; i++)
    {
        history[i] = 0;
    }

    while (true)
    {

        if (round == 0)
        {
            cout << "are you ready to start the game?" << endl;
        }
        else
        {
            cout << "do you wanna play again?" << endl;
        }

        while (komaki2 == -1)
        {

            cout << "enter 1 to start the game or enter 0 or any char to finish the program" << endl;
            cin >> komaki;
            if (komaki == 0)
            {
                cout << "GOODBYE!!";
                return 0;
            }
            if (komaki == 1)
            {
                komaki2 = 0;
            }
        }

        while (komaki2 == 0)
        {

            system("cls");
            randomvalue(array);
            showmax(maximum, score);
            show(array);
            cout << "enter w,a,s,d to move numbers,0 to end program,r to restart and h to watch your history:" << endl;
            while (komaki2 == 0)
            {
                if (checkwin(array))
                {
                    cout << "YOU WOOOOOON!!" << endl;
                    komaki2 = -1;
                    komaki = -1;
                    zero(array);
                    continue;
                }
                else if (checklose(array))
                {
                    cout << "YOU LOSE\n";
                    komaki2 = -1;
                    komaki = -1;
                    zero(array);
                    continue;
                }
                cin >> di;
                if (di == '0')
                {
                    cout << "goodbbye";
                    return 0;
                }
                else if (di == 'r')
                {
                    komaki2 = -1;
                    komaki = -1;
                    zero(array);
                }
                else if (di == 'h')
                {
                    string s;
                    ifstream myfile("myfile.txt");
                    while (getline(myfile, s))
                    {
                        cout << s << endl;
                    }
                    myfile.close();
                }
                  else if (di == 'u')
                {
                    equal(array,array2 );
                    system("cls");
                    showmax(maximum,score);
                    show(array);
                }
                else if (di == 'w' || di == 'a' || di == 's' || di == 'd')
                {
                    if (checkdirection(array, di))
                    {
                        equal(array2,array);
                        if (di == 'w')
                        {
                            system("cls");
                            score += movew(array);
                            randomvalue(array);
                            showmax(maximum, score);
                            show(array);
                        }
                        else if (di == 's')
                        {
                            system("cls");
                            score += moves(array);
                            randomvalue(array);
                            showmax(maximum, score);
                            show(array);
                            
                        }
                        else if (di == 'a')
                        {
                            system("cls");
                            score += movea(array);
                            randomvalue(array);
                            showmax(maximum, score);
                            show(array);
                           
                        }
                        else if (di == 'd')
                        {
                            system("cls");
                            score += moved(array);
                            randomvalue(array);
                            showmax(maximum, score);
                            show(array);
                           
                        }
                    }
                    else
                    {
                        system("cls");
                        showmax(maximum, score);
                        show(array);
                        cout << "you cant go this direction choose another one" << endl;
                    }
                }
                else
                {
                    cout << "pleas choose between w,a,s,d,r,h,0" << endl;
                }
            }
        }
        history[round] = score;
        maximum = max(history);
        score = 0;
        ofstream myfile("myfile.txt");
        myfile << "ten previous match score :" << endl;
        for (int i = round; i >= 0; i--)
        {
            myfile << "round " << i + 1 << " = " << history[i] << endl;
        }
        myfile.close();
        round++;
    }
}
