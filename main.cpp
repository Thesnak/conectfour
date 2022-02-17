#include <iostream>
#include <stdlib.h>
using namespace std;
int board[7][6];
int choice, player;
bool so= false;
int a=0;

void check(int x)
{
    if(board[x-1][a]!=0 && a<6)
    {
        a++;
        check(x);
    }   else if (player==1 && a<6)
            {
            system("CLS");
            board[x-1][a]=1;
            a=0;
            }
        else if (player==2 && a<6)
            {
            system("CLS");
            board[x-1][a]=2;
            a=0;
            }
        else
        {
        system("CLS");
        cout << "WRONG!" << endl;
        a=0;
        player++;
        }
}

int draw()
{
    for(int i = 0; i<9; i++)
    {
        if(i<2)
        {
        cout<<"<";
        } else if(i>7)
        {
        cout<<i-1<<">>"<<endl;
        } else {
        cout<<i-1<<"----";
        }
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            if(board[j][i]!=0)
            {
                if(board[j][i]==1)
                {
                cout<<"[ X ]";
                }else cout<<"[ O ]";
            }
            else cout<<"[   ]";
        } cout<<endl;
    }
    for(int i = 0; i<35; i++)
    {
        cout<<" ";
    } cout<<endl;
}

int win_check()
{
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
        if(i+3<6&&j+3<7&&board[j][i]==1 && board[j+1][i+1]==1 && board[j+2][i+2]==1 && board[j+3][i+3]==1)
            {
            so = true;
            cout << "\nPLAYER 1 WIN!" << endl;
            }
        if(j+3<7&&i>=3&&board[j][i]==1 && board[j+1][i-1]==1 && board[j+2][i-2]==1 && board[j+3][i-3]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            so = true;
            }
        if(j+3<7&&i>=3&&board[j][i]==2 && board[j+1][i-1]==2 && board[j+2][i-2]==2 && board[j+3][i-3]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            so=true;
            }
        else if(i+3<6&&j+3<7&&board[j][i]==2 && board[j+1][i+1]==2 && board[j+2][i+2]==2 && board[j+3][i+3]==2)
            {
            so= true;
            cout << "\nPLAYER 2 WIN!" << endl;
            }
        else if(i+3<6&&board[j][i]==1 && board[j][i+1]==1 && board[j][i+2]==1 && board[j][i+3]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            so= true;
            }
        else if(j+3<7&&board[j][i]==1 && board[j+1][i]==1 && board[j+2][i]==1 && board[j+3][i]==1)
            {
            cout << "\nPLAYER 1 WIN!" <<endl;
            so = true;
            }
        else if(i+3<6&&board[j][i]==2 && board[j][i+1]==2 && board[j][i+2]==2 && board[j][i+3]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            so = true;
            }
        else if(j+3<7&&board[j][i]==2 && board[j+1][i]==2 && board[j+2][i]==2 && board[j+3][i]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            so = true;
            }
        }
    }
}
int p_choice()
{
    player = 1;
    while(so!=true)
    {
    cout << "PLAYER " << player << ": ";
    cin >> choice;
        if (choice>0 && choice<8)
        {
            check(choice);
            draw();
            if (player == 1)
            {
                player++;
            }
            else
            {
                player--;
            }
        }
    else
        {
    cout << "WRONG CHOICE!" << endl;
        }
    win_check();
    }
}


int main()
{
cout<<"WELCOME IN CONNECT 4"<<endl;
draw();
p_choice();
return 0;
}
