#include<iostream>
#include<ctime>

using namespace std;

void display(char grid[30][30])
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

void redraw(char grid[30][30])
{
    char newgrid[30][30];

    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            int neighbors = 0;

            for(int k=-1;k<=1;k++)
            {
                for(int l=-1;l<=1;l++)
                {
                    if(k!=0 || l!=0)
                    {
                        int r=i+k;
                        int c=j+l;

                        if(r>=0 && r<30 && c>=0 && c<30 && grid[r][c]=='*')
                        {
                            neighbors++;
                        }
                    }
                }
            }

            if(grid[i][j]=='*')
            {
                if(neighbors==2||neighbors==3)
                {
                    newgrid[i][j]='*';
                }
                else
                {
                    newgrid[i][j]=' ';
                }
            }
            else
            {
                if(neighbors==3)
                {
                    newgrid[i][j] = '*';
                }
                else
                {
                    newgrid[i][j]=' ';
                }
            }

        }
    }

    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            grid[i][j] = newgrid[i][j];
        }
    }
}

int main()
{
    char grid[30][30];
    srand(time(0));

    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(rand()%2==0)
            {
                grid[i][j] = '*';
            }
            else
            {
                grid[i][j] = ' ';
            }
        }
    }

    while(true)
    {
        display(grid);
        redraw(grid);
        cin.get();
    }


    return 0;
}