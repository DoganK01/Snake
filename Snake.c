#include <stdio.h>
//#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>


int saha[80][23]={0};
int kuyrukSutun[500];
int kuyrukSatir[500];
int maap[80][23]={0};

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void cerceve(int x1, int y1, int x2, int y2,int tur)
{
    int i;
    for(i=x1; i<=x2;i++)
    {
        saha[i][y1] = tur;

        saha[i][y2] = tur;

    }
    for(i=y1; i<=y2;i++)
    {
        saha[x1][i] = tur;

        saha[x2][i] = tur;

    }
}

void ekrani_bas()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+1,y+1);
            if(saha[x][y]==1)
            {
                printf("%c",219);
            }

            else if(saha[x][y]==2)
            {
                printf("%c",176);
            }
            else if(saha[x][y]==3)
                printf("%c",88);

        }
    }
}

int k,l;
randomAta()
{
    srand(time(NULL));  // her defasında farklı olsun diye bu kod kullanılır!!!
    k=4+rand()%65;
    l=4+rand()%15;


}

void main()
{
    randomAta();
    cerceve(0,0,79,22,2);
    ekrani_bas();
    int sx=40,sy=12;
    int dy=0,dx=0;
    unsigned char tus;
    int a=0;
    int devam=0;




    do
    {
        if(kbhit())
        {
            tus=getch(); //tuşu hafızayya alıyor
            if(tus==224) // tuş yön tuşları ise (alta bak)
            {
                tus=getch(); // yine hafızaya alıyor
                switch(tus)
                {
                    case 72:dy=-1; dx=0;
                        break;
                    case 80:dy=1; dx=0;
                        break;
                    case 77: dx=1; dy=0;
                        break;
                    case 75: dx=-1; dy=0;
                }
            }
        }

        sx=sx+dx;
        sy=sy+dy;
        if(sx>78)
            sx=2;
        if(sx<2)
            sx=78;
        if(sy>22)
            sy=2;
        if(sy<2)
            sy=22;

        kuyrukSutun[0]=sx;
        kuyrukSatir[0]=sy;
        int i;


        for(i=1;i<=a;i++)
        {
            if((sx==kuyrukSutun[i] && sy==kuyrukSatir[i]))
            {
                gotoxy(sx,sy);printf("--YANDINIZ--");
                getch();
                devam=1;
            }


        }

        gotoxy(sx,sy);printf("*");

        for(i=0;i<=a;i++)
        {
            gotoxy(kuyrukSutun[i],kuyrukSatir[i]);printf("*");

        }


        if(sx==k && sy==l)
        {
            randomAta();
            a++;
            gotoxy(2,2);printf("Puan: %d",a);
        }

        gotoxy(k,l);printf("A");

        Sleep(50);

        gotoxy(sx,sy);printf(" ");


        for(i=0;i<=a;i++)
        {
            gotoxy(kuyrukSutun[i],kuyrukSatir[i]);printf(" ");

        }


        for(i=a;i>0;i--)
        {
            kuyrukSutun[i]=kuyrukSutun[i-1];
            kuyrukSatir[i]=kuyrukSatir[i-1];
        }

    } while (devam==0);
}
