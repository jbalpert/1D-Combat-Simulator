#include "Fighter.h"

class Game{
    private: 
        vector<Fighter> s;
        vector<Fighter> h;
        int skeletons; 
        int humans;
        bool quiet; 

        void genArmies(){
            s.reserve(skeletons);
            h.reserve(humans);
            // Skeleton Army
            for(int i = 0; i < skeletons; i++){
                default_random_engine rg(time(0) + i % 2);
                Fighter f('s', rg);
                s.push_back(f);
            }
            for(int i = 0; i < humans; i++){
                default_random_engine rg(time(0) + i);
                Fighter f('h', rg);
                h.push_back(f);
            }
        }
    public: 
        Game(int i = 0, int j = 0, bool k = false):skeletons(i), humans(j), quiet(k) {
            genArmies();
        }  

        void battle(){
            char turn = 's';
            while(1){
                if(h.empty()){
                    cout << "Skeletons Won!\n";
                    cout << humans << " humans were killed while " << s.size() 
                            << " / " << skeletons << " are left!\n";
                    return;
                }
                else if(s.empty()){
                    cout << "Humans Won!\n";
                    cout << skeletons << " skeletons were killed while " << h.size() 
                            << " / " << humans << " are left!\n";
                    return;
                }
                if(turn == 's'){
                    int attack = s.back().hit();
                    if(!quiet){
                        cout << "Human was hit for " << attack << "\n";
                    }
                    h.back().attacked(attack);
                    if(!h.back().isAlive()){
                        h.pop_back();
                        if(!quiet){
                            cout << "Human has been killed " << h.size() << " humans left.\n";
                        }
                    }
                    turn = 'h';
                }
                else{
                    int attack = h.back().hit();
                    if(!quiet){
                        cout << "Skeleton was hit for " << attack << "\n";
                    }
                    s.back().attacked(attack);
                    if(!s.back().isAlive()){
                        s.pop_back();
                        if(!quiet){
                            cout << "Skeleton has been killed " << s.size() << " skeletons left.\n";
                        }
                    }
                    turn = 's';
                }
            }
        }
};
