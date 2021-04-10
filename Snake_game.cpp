#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<time.h>

#define MAXSIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x,int y)
{
    CursorPosition.X= x;
    CursorPosition.Y= y;
    SetConsoleCursorPosition(console,CursorPosition);
}

class Point
{
private:
    int x;
    int y;
public:
    Point()
    {
        x = y = 10;
    }
    Point(int x,int y)
    {
        this -> x = x;
        this -> y = y;
    }
    void SetPoint(int x,int y)
    {
        this -> x = x;
        this -> y = y;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void MoveUp()
    {
        y--;
    }
    void MoveDown()
    {
        y++;
    }
    void MoveLeft()
    {
        x--;
    }
    void MoveRight()
    {
        x++;
    }
    void Draw()
    {
        gotoxy(x,y);
        cout<<"*";
    }
    void Erase()
    {
        gotoxy(x,y);
        cout<<" ";
    }
    void CopyPos(Point *p)
    {
        p->x = x;
        p->y = y;
    }
    /*void Debug()
    {
        cout<<"("<<x<<","<<y<<") ";
    }*/
};

class Snake
{
private:
    Point *cell[MAXSIZE];
    int size;
    char dir;
    Point fruit;

public:
    Snake()
    {
        size = 1;
        cell[0] = new Point(20,20);
        for(int i=1; i<MAXSIZE; i++)
        {
            cell[i] = NULL;
        }
        fruit.SetPoint(rand()%50, rand()%25);
    }
    void AddCell(int x,int y)
    {
        cell[size++] = new Point(x,y);
    }
    void TurnUp()
    {
        dir= 'w';
    }
    void TurnDown()
    {
        dir= 's';
    }
    void TurnRight()
    {
        dir= 'd';
    }
    void TurnLeft()
    {
        dir= 'a';
    }
    void Move()
    {
        system("cls");

        for(int i=size-1; i>0; i--)
        {
            cell[i-1]->CopyPos(cell[i]);
        }

        switch(dir)
        {
        case 'w':
            cell[0]->MoveUp();
            break;
        case 's':
            cell[0]->MoveDown();
            break;
        case 'd':
            cell[0]->MoveRight();
            break;
        case 'a':
            cell[0]->MoveLeft();
            break;
        }

        if(fruit.GetX() == cell[0]->GetX() && fruit.GetY() == cell[0]->GetY())
        {
            AddCell(0,0);
            fruit.SetPoint(rand()%50, rand()%25);
        }

        for(int i=0; i<size; i++)
            cell[i]->Draw();

        fruit.Draw();

        Sleep(50);
    }

};

int main()
{
    system("Color B");
    int ch;

    cout<<"\n\n\t\t\t\t\tWelcome to Simple Snake game"<<endl;
    cout<<"\n\t\t\t\t\tCopyright © 2019 all rights reserved"<<endl<<endl<<endl;

    while(1)
    {
        cout<<"Press 1 to start the game"<<endl;
        cin>>ch;

        system("CLS");

        if(ch==1)
        {
            srand((unsigned)time(NULL));

            Snake snake;
            char op= '1';
            do
            {
                if(kbhit())
                {
                    op = getch();
                }
                switch(op)
                {
                case 'w':
                case 'W':
                    snake.TurnUp();
                    break;
                case 's':
                case 'S':
                    snake.TurnDown();
                    break;
                case 'd':
                case 'D':
                    snake.TurnRight();
                    break;
                case 'a':
                case 'A':
                    snake.TurnLeft();
                    break;
                }
                snake.Move();

            }
            while(op!= 'e');
        }

        else
            cout<<"Wrong input! try again!"<<endl;
    }

    return 0;
}
