#ifndef Grid_h
#define Grid_h

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid{
    private:
vector<vector<int>> mapa;
vector<vector<int>> next;
int rows;
int cols;
int w;
int h;
    public:
Grid(int n,int w, int h);//WASA
Grid(int cols, int rows);
void update();
void create(int x,int y);
int calcularVecinos(int i, int j);
void drawTo(RenderWindow &window);
void toggle(int x,int y);
};

#endif