#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <fstream>

using namespace std;

class Habit_Tracker {
    public:
        Habit_Tracker();
        void start_habit();
    private:
        string start_screen();
        int water_intake_dialogue();
        int water_intake(bool water_done, int water_amount, int &water_goal, int amount_leftover);
        void end_dialogue();
        void save_habit(vector<string> name, vector<int> saved_values);
        vector<string> saved_inputs;
        vector<int>saved_values;
        string name;
        int water_amount;
        int water_goal;
        bool water_done;
        int amount_leftover;
        int habit_points = 0;
};
