#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;


Grid::Grid(int n,int w, int h){
this->rows = n;
this->cols = n;
this->w = w;
this->h = h;
for (int i=0;i<this->rows;i++)
    {
        mapa.push_back({});
        for (int j=0;j<this->cols;j++)
        {
            mapa[i].push_back(0);
        }
    }
this->next = vector<vector <int>>(rows,vector<int>(cols,0));
}

Grid::Grid(int cols, int rows){
    this->rows = rows;
    this->cols = cols;
    for (int i=0;i<this->rows;i++)
    {
        mapa.push_back({});
        for (int j=0;j<this->cols;j++)
        {
            mapa[i].push_back(0);
        }
    }
    this->next = vector<vector <int>>(rows,vector<int>(cols,0));
}
void Grid::create(int x,int y){

}

void Grid::drawTo(RenderWindow &window){
    int Xx = this->w/this->rows;
    int Yy = this->h/this->cols;
    for (int i=0;i<this->rows;i++)
    {
        for (int j=0;j<this->cols;j++)
        {
            RectangleShape rect(Vector2f(Xx,Yy));
            rect.setPosition(Vector2f(j*Xx,i*Yy));
            rect.setOutlineThickness(0);
            rect.setFillColor(Color::Black);
            rect.setOutlineColor(Color::Black);
            if (mapa[j][i]==1){
            rect.setFillColor(Color::Magenta);
            /*    int n=(rand()%5);
                switch(n){
                    case 0:
            rect.setFillColor(Color::Magenta);
                    break;
                    case 1:
            rect.setFillColor(Color::Cyan);
                    break;
                    case 2:
            rect.setFillColor(Color::Black);
                    break;
                    case 3:
            rect.setFillColor(Color::Blue);
                    break;
                    case 4:
            rect.setFillColor(Color::White);
                    break;
                }*/
            
            }
            window.draw(rect);
        }
    }
}
void Grid::toggle(int x,int y){
int sizeX= this->w/ this->cols;
int sizeY = this->h/ this->rows;

    int indexX = x/sizeX;
    int indexY = y/sizeY;

    this->mapa[indexX][indexY] = 1;
}

int Grid::calcularVecinos(int i, int j){
    int vecinos = 0;
     if (i>0 && j>0 && this->mapa[i-1][j-1] == 1){
         vecinos++;
     }
     if (j>0 && this->mapa[i][j-1] == 1){
         vecinos++;
     }
     if (i<this->rows-1 && j>0 && this->mapa[i+1][j-1] == 1){
         vecinos++;
     }
     if (i>0 && this->mapa[i-1][j] == 1){
         vecinos++;
     }
     if (i<this->rows-1 && this->mapa[i+1][j] == 1){
         vecinos++;
     }
     if (i>0 && j<this->cols-1 && this->mapa[i-1][j+1] == 1){
         vecinos++;
     }
     if (j<this->cols-1 && this->mapa[i][j+1] == 1){
         vecinos++;
     }
     if (i<this->rows-1 && j<this->cols-1 && this->mapa[i+1][j+1] == 1){
         vecinos++;
     }
    return vecinos;
}

void Grid::update(){
for (int i=0;i<this->rows;i++){
        for (int j=0;j<this->cols;j++){
        if (this->mapa[i][j]==1 && j!=cols-1){
            if (mapa[i][j+1]==0){
                this->next[i][j+1]=1;
                this->next[i][j]=0;
            }else{
                if (mapa[i-1][j+2]==0 && j<cols-2 && i!=1){
                    this->next[i-1][j+2]=1;
                    this->next[i][j]=0;
                }else {
                    if (mapa[i+1][j+2]==0 && j<cols-2 && i!=rows-1){
                    this->next[i+1][j+2]=1;
                    this->next[i][j]=0;
                    }else {
                    
                    this->next[i][j]=1;
                    
                    }
                }
            }
        }else {
            if (mapa[i][j]==1){
            this->next[i][j]=1;
            }else {
                this->next[i][j]==0;
            }
        }
        }
    }
    this->mapa=this->next;
}