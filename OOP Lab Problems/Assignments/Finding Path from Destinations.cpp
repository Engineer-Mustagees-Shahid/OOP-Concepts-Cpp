#include<iostream>
using namespace std;

const int rows=5;
const int cols=5;

int count_paths(char **maze, int rows,int cols, int x, int y, int dest_x, int dest_y, bool **visited) 
{
    
    if (x<0 || y<0 || x>=rows || y>=cols  || visited[x][y]) 
	{
        return 0;
    }

   
    if (x==dest_x && y==dest_y) 
	{
        return 1;
    }

    
    visited[x][y]=true;


    int total_paths=0;
    total_paths +=count_paths(maze,rows,cols, x + 1, y, dest_x, dest_y, visited); 
    total_paths +=count_paths(maze,rows,cols, x - 1, y, dest_x, dest_y, visited); 
    total_paths +=count_paths(maze,rows,cols, x, y + 1, dest_x, dest_y, visited); 
    total_paths +=count_paths(maze,rows,cols, x, y - 1, dest_x, dest_y, visited); 

    visited[x][y]=false;

    return total_paths;
}

int main() 
{
    
    char **maze=new char*[rows];
    maze[0]=new char[cols]{'.', '.', '#', '.', '.'};
    maze[1]=new char[cols]{'#', '.', '#', '.', '#'};
    maze[2]=new char[cols]{'.', '#', '.', '#', '.'};
    maze[3]=new char[cols]{'.', '#', '.', '.', '.'};
    maze[4]=new char[cols]{'.', '.', '#', '.', '.'};

    bool **visited=new bool*[rows];
    for (int i=0; i<rows; i++)
	 {
        visited[i]=new bool[cols]{false};
    }

    int start_x=0, start_y = 0;
    int dest_x=4, dest_y = 4;

    int total_paths=count_paths(maze,rows,cols,start_x,start_y,dest_x,dest_y,visited);

    cout<<"Total paths from start to destination: "<<total_paths<<endl;
    
     for (int i=0; i<rows; i++) 
	 {
        delete[] maze[i];
        delete[] visited[i];
    }
    delete[] maze;
    delete[] visited;

    return 0;
}
