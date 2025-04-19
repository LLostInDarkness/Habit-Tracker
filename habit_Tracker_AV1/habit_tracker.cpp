#include "habit_functions.h"
#include <iostream>

Habit_Tracker::Habit_Tracker() {  // Constructs tracker
    start_screen();
    water_done = false;
}

string Habit_Tracker::start_screen() {

    cout << "Enter Your Name To Begin: " ;
    cin >> name;
    
    saved_inputs.push_back(name);

    return name;
    
}

void Habit_Tracker::start_habit() {
    if(name.length() != 0) {
        cout << endl;
        cout << "ฅ /ᐠ•ヮ•マ Ⳋ" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "Hello there " << name << "! I'm Chiara, your personal habit tracking helper." << endl;
        cout << "Your task is simple, complete your positve habits, and earn habit points." << endl;
        cout << "Let's get started with our new habit!" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        sleep(7);
        cout << endl;
        cout << "/ᐠ•ヮ•マ Ⳋ" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "CHIARA:" << endl;
        cout << "Today we will focus on Drinking Water for today's goal" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
        water_intake_dialogue();
        water_intake(water_done, water_amount, water_goal, amount_leftover);
        end_dialogue();
        save_habit(saved_inputs, saved_values);

    }else{
        cout << "Reload and try again" << endl;
    }
}

int Habit_Tracker::water_intake_dialogue() {
    sleep(4);
    cout << "/ᐠ•ヮ•マ Ⳋ" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "CHIARA:" << endl;
    cout << "How many ounces water do you want to drink today? ";
    cin >> water_goal;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
    
    while (water_goal <= 0) {
        cout << "/ᐠ•ヮ•マ Ⳋ" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "CHIARA:" << endl;
        cout << "Please input your water goal using postive integers." << endl;
        cout << "How many ounces water do you want to drink today? ";
        cin >> water_goal;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << endl;
    }

    saved_values.insert(saved_values.end(), water_goal);
    return water_goal;
}

int Habit_Tracker::water_intake(bool water_done, int water_amount, int &water_goal, int amount_leftover) {
    while(water_done == false) {
        sleep(2);
        cout << "/ᐠ•ヮ•マ" << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cout << "CHIARA:" << endl;
        cout << "How many ounces of water did you drink recently? ";
        cin >> water_amount;
        cout << "-------------------------------------------------------------------------------" << endl;

        saved_values.insert(saved_values.end(), water_amount);
 
        if(water_amount == 0) {
            cout << endl;
            cout << "/ᐠ•ヮ•マ" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "CHIARA:" << endl;
            cout << "Let's try to drink some water right now." << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
        }else if(water_amount < water_goal) {
            amount_leftover = water_goal - water_amount;
            water_goal = amount_leftover;

            cout << endl;
            cout << "/ᐠ˵- ⩊ -˵マ" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "CHIARA:" << endl;
            cout << "Good job " << name << "!" << endl;
            cout << "You are making great progress on your water intake goal!" << endl;
            sleep(1);
            cout << "Amount left before reaching goal: " << amount_leftover << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << endl;
        }else if(water_amount == amount_leftover || water_amount >= water_goal) {
            cout << endl;
            cout << "ฅ/ᐠ˶>ﻌ<˶ᐟ\\ฅ" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "CHIARA:" << endl;
            cout << "Woah! Stellar job " << name << " for drinking your water goal!" << endl;
            habit_points++;
            cout << "You have earned: " << habit_points << " habit point(s)!" << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << endl;
            return true;
        }else{
            cout << "Please input the amount of water you drank using integers" << endl;
        }
        
    }

    return habit_points;
    
}

void Habit_Tracker::end_dialogue() {
    // Used as a teaser for the future shop section in future versions
    sleep(4);
    cout << "/ᐠ•ヮ•マ" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "CHIARA:" << endl;
    cout << "Congrats "<< name << " for completing a habit!" << endl;
    cout << "You have " << habit_points << " habit point(s) to spend at the store" << endl;
    sleep(3);
    cout << "Unfortunately the shop is closed right now, but in the future it will open." << endl;
    cout << "Keep collecting habit points and you'll be able to spend them at the shop." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

void Habit_Tracker::save_habit(vector<string> name, vector<int> saved_values) {
    // Used to print vertically
    fstream fin;
    ofstream fout;
    fout.open("habit.txt");
    for(int i = 0; i < name.size(); i++) {
        fout << "Name: ";
        fout << name[i] << endl;
    }
    for(int i = 0; i < saved_values.size(); i++) {
        if(i == 0) {
            fout << "Water Goal: ";
            fout << saved_values[i] << endl;
            fout << "Values Inputted: ";
        }else{
            fout << saved_values[i] << ", ";
        }
    }
    fout.close();

}
