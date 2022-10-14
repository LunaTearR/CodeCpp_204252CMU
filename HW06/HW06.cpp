#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Team {
    public:
        int ID;
        int GD;  // Goal Difference = Goal score - Goal conced
        int PTS; // Point (win = 3, draw = 1, lose = 0)

        // Constructor
        Team(int x, int y, int z) : ID(x), GD(y), PTS(z) {}

};

class Scoreboard{
    public:
        vector<Team> T;
        int numberOfTeams = 0;

        Scoreboard(int n){
            numberOfTeams = n;
            for (int i = 0; i < n; i++){
                Team x(i, 0, 0);
                T.push_back(x);
            }
        }

        void match(int ID1, int ID2, int G1, int G2){
            //set position ID
            int k,j;
            for(int i = 0;i < T.size();i++){
                if(T[i].ID == ID1){
                    k = i;
                }
                if(T[i].ID == ID2){
                    j = i;
                }
            }
            // cal score
            if(G1 > G2){
                T[k].PTS += 3;
                T[k].GD += G1 - G2;
                T[j].GD += G2 - G1;
            }
            else if(G1 < G2){
                T[j].PTS += 3;
                T[j].GD += G2 - G1;
                T[k].GD += G1 - G2;
            }
            else{
                T[j].PTS += 1;
                T[k].PTS += 1;
            }
            //sort Table
            update_table();
            
        }
        void showTeamAtRank(int i){
            i--;
            //Show
            cout << T[i].ID << " " << T[i].PTS << " " << T[i].GD << endl;
        }
        void update_table(){
            //bubble sort
            int i,j,temp_pts,temp_gd,temp_id;
            for(i = (T.size() - 1);i >= 0;i--){
                for(j = 1;j <= i;j++){
                    //check score
                    if(T[j-1].PTS == T[j].PTS){
                        //check different goal
                        if(T[j-1].GD < T[j].GD){
                            temp_pts = T[j-1].PTS;
                            temp_gd = T[j-1].GD;
                            temp_id = T[j-1].ID;
                            T[j - 1] = T[j];
                            T[j].PTS = temp_pts;
                            T[j].ID = temp_id;
                            T[j].GD = temp_gd;
                        }
                        else if(T[j-1].GD == T[j].GD){
                            //check id
                            if(T[j-1].ID > T[j].ID){
                                temp_pts = T[j-1].PTS;
                                temp_gd = T[j-1].GD;
                                temp_id = T[j-1].ID;
                                T[j - 1] = T[j];
                                T[j].PTS = temp_pts;
                                T[j].ID = temp_id;
                                T[j].GD = temp_gd;
                            }
                            else{
                                continue;
                            }
                        }
                        else{
                            continue;
                        }
                    }
                    else if(T[j-1].PTS < T[j].PTS){
                        temp_pts = T[j-1].PTS;
                        temp_gd = T[j-1].GD;
                        temp_id = T[j-1].ID;
                        T[j - 1] = T[j];
                        T[j].PTS = temp_pts;
                        T[j].ID = temp_id;
                        T[j].GD = temp_gd;
                    }
                }
            }
        }
};