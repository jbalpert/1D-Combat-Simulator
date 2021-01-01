#include "Game.h"

/* In this 1D Combat Simulator the basic premise is 
skeletons fighting humans in two separate lines ssss <-> hhhh
the person who is first in the human line and the skelly who
is first in the skeleton line fights each other. Whoever survives,
the player battles the next opponent in the line. 

There are two required arguments: number of humans and number of skeletons
And there is one optional argument Quiet Mode which does not output any
of the battles
*/

bool isNumber(char number[])
{
    int i = 0;
    //checking for negative numbers
    if (number[0] == '-')
        return false;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

int population(char number[]){
    if(isNumber(number)){
        return atoi(number);
    }
    cerr << "Incorrect human/skeleton input\n";
    exit(0);
}

Game argCheck(int argc, char *argv[]){
    if(argc == 3){
        Game g(population(argv[1]), population(argv[2]));
        return g;
    }
    else if(argc == 4){
        if(argv[3][0] == 'q'){
            Game g(population(argv[1]), population(argv[2]), true);
            return g;
        }
        else{
            cerr << "Provided three arguments, but did not specify quiet mode\n";
            exit(0);
        }
    }
    else{
        cerr << "Did not provide proper arguments.\n";
        exit(0);
    }
    return 0;
}

int main(int argc, char **argv){
    Game g = argCheck(argc, argv);
    g.battle();
    return 0;
}