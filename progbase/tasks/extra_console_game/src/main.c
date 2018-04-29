#include <progbase.h>
#include "interface.h"
#include "save.h"
#include "snake.h"
#include "tetrisnake.h"

int gameCycle(struct settings * setts);

int main() {

    int endFlag = 1;

    //main cycle
    while (endFlag) {
        struct settings setts = start();

        int score = gameCycle(&setts);

        save(setts.nickname, score, setts.leaderboard);
        free(setts.nickname);
        free(setts.leaderboard);
        endFlag = gameOver();
    }

    exitInter();
    return 0;
}
int gameCycle(struct settings * setts){
    if(setts->gameMode == EMPTY) return 0;
    else if(setts->gameMode == TETRIS) return tetris(setts);
    else if(setts->gameMode == SNAKE) return snake(setts);
    else if(setts->gameMode == TETRSNAKE) return tetrisnake(setts);
    else return 0;
}