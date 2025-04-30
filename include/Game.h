#ifndef GAME_H
#define GAME_H
#include<string>

using namespace std;


class Game
{
    public:
        Game();
        bool queen_attack(int p, char pos_x, int pos_y);
        virtual ~Game();


    private:
        string pos_Reina_blanca;
        string pos_Reina_negra;
};

#endif // GAME_H
