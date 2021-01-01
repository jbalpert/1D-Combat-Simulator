#include <vector>
#include <random>
#include <ctime>
#include <iostream>


using namespace std;

class Fighter{
    private:
        double critical;
        int health;
        int attack;
        int defense;
        
        void generateStats(char character, default_random_engine randGen){
            int hb = 1;
            if(character == 'h'){
                hb = 1.5;
            }
            int shl = 10, shh = 25, sal = 3, sah = 7, sdl = 0, sdh = 2;
            double scl = 1, sch = 1.5;
            uniform_int_distribution<int> sh(shl * hb, shh * hb);
            uniform_int_distribution<int> sa(sal * hb, sah * hb);
            uniform_int_distribution<int> sd(sdl * hb, sdh * hb);
            uniform_real_distribution<double> sc(scl * hb, sch * hb);

            critical = sc(randGen);
            health = sh(randGen);
            attack = sa(randGen);
            defense = sd(randGen);
        }
        
    public:
        Fighter(char character, default_random_engine randGen){
            generateStats(character, randGen);
        } 

        int hit(){
            default_random_engine randGen(time(0));
            uniform_int_distribution<int> cc(1,5);
            if(cc(randGen) == 1){
                return attack * critical;
            }
            return attack;
        }

        int attacked(int hit){
            health -= (hit - defense);
            return health;
        }

        bool isAlive(){
            if(health > 0){
                return true;
            }
            return false;
        }
};