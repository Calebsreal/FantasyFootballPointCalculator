/*This is a program that will be used as a fantasy football point calculator. It will ask the user for their players name , then it will ask them for the weekly stats of that player. The program will then use this to calculate the individual points for each player store it and then combine all the players for a total amount. This will be done using a points per rececption (PPR) based system. As the name implies it means a player will be given 1 point for each reception that they have a game. I will be using arrays and functions to do this. */

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void GetWrPoints(int wrrec[], int wryds[], int wrtds[], float wrpoints[], int wrs);
void GetRbPoints(int rbrsyds[], int rbrtds[], int rbrec[], int rbrcyds[], int rbrctds[], float rbpoints[], int rbs);
void GetTePoints(int terec[], int teyds[], int tetds[], float tepoints[], int tes);
void GetQbPoints(int qbpyds[], int qbptds[], int qbryds[], int qbrtds[], float qbpoints[]);

int main() 
{
    // Creating variables that will be used later in the program
    int wrs, rbs, tes;
    double fantasy_total = 0;

    // I will be using parallel arrays to store the stats of the players in an organized way.

    // Creating arrays for the number of players in each position
    cout << "Enter the number of running backs, receivers, and tight ends you have separated by a space: " << endl;
    cin >> wrs >> rbs >> tes;

    // Adding user input validation
    while (wrs < 0 || wrs > 3 || rbs < 0 || rbs > 3 || tes < 0 || tes > 2) 
    {
        cout << "You have entered an invalid number of players. There should be no more than 3 running backs, 3 receivers, and 2 tight ends at one time. Please try again." << endl;
        cout << "Enter the number of running backs, receivers, and tight ends you have separated by a space: " << endl;
        cin >> wrs >> rbs >> tes;
    }

    // Creating arrays that will store the name of the players
    string wrfname[wrs], rbfname[rbs], tefname[tes], qbfname[1];
    string wrlname[wrs], rblname[rbs], telname[tes], qblname[1];

    // Creating arrays that will store the stats of the players
    int wrrec[wrs], rbrec[rbs], terec[tes];
    int wryds[wrs], rbrcyds[rbs], teyds[tes];
    int wrtds[wrs], rbrctds[rbs], tetds[tes];
    int rbrsyds[rbs], rbrtds[rbs];
    int qbpyds[1], qbptds[1], qbrtds[1], qbryds[1];
    float rbpoints[rbs], wrpoints[wrs], tepoints[tes], qbpoints[1];

    // Asking the user for the name of each of their players as well as their stats for the week.
    cout << "Enter the first and last name of your quarterback separated by a space: ";
    cin >> qbfname[0] >> qblname[0];
    cout << "Enter the number of passing yards, passing touchdowns, rushing yards, and rushing touchdowns " << qbfname[0] << " " << qblname[0] << " had this week separated by a space: ";
    cin >> qbpyds[0] >> qbptds[0] >> qbryds[0] >> qbrtds[0];

    for (int i = 0; i < rbs; i++)
    {
        cout << "Enter the first and last name of your running back " << i + 1 << " separated by a space: ";
        cin >> rbfname[i] >> rblname[i];
        cout << "Enter the amount of rushing yards, rushing touchdowns, receptions, receiving yards, and receiving touchdowns " << rbfname[i] << " " << rblname[i] << " had this week separated by a space: ";
        cin >> rbrsyds[i] >> rbrtds[i] >> rbrec[i] >> rbrcyds[i] >> rbrctds[i];
    }

    for (int i = 0; i < wrs; i++)
    {
        cout << "Enter the first and last name of your wide receiver " << i + 1 << " separated by a space: ";
        cin >> wrfname[i] >> wrlname[i];
        cout << "Enter the amount of receptions, receiving yards, and receiving touchdowns " << wrfname[i] << " " << wrlname[i] << " had separated by a space: ";
        cin >> wrrec[i] >> wryds[i] >> wrtds[i];
    }

    for (int i = 0; i < tes; i++)
    {
        cout << "Enter the first and last name of your tight end " << i + 1 << " separated by a space: ";
        cin >> tefname[i] >> telname[i];
        cout << "Enter the amount of receptions, receiving yards, and receiving touchdowns " << tefname[i] << " " << telname[i] << " had separated by a space: ";
        cin >> terec[i] >> teyds[i] >> tetds[i];
    }

    // Calling getter functions to calculate points for each player 
    GetQbPoints(qbpyds, qbptds, qbryds, qbrtds, qbpoints);
    GetRbPoints(rbrsyds, rbrtds, rbrec, rbrcyds, rbrctds, rbpoints, rbs);
    GetWrPoints(wrrec, wryds, wrtds, wrpoints, wrs);
    GetTePoints(terec, teyds, tetds, tepoints, tes);

    // Calculating the total points for the week
    for (int i = 0; i < rbs; i++)
        fantasy_total += rbpoints[i];
    for (int i = 0; i < wrs; i++)
        fantasy_total += wrpoints[i];
    for (int i = 0; i < tes; i++)
        fantasy_total += tepoints[i];
    fantasy_total += qbpoints[0];

    // Displaying the total points for the week
    cout << "Your total fantasy points for the week is " << fantasy_total << endl;

    // Displaying each player's stats and points for the week
    cout << "Here are your players and their stats for the week: " << endl;
    cout << "Quarterback: " << qbfname[0] << " " << qblname[0] << " scored " << qbpoints[0] << " points this week." << endl;

    for (int i = 0; i < wrs; i++)
    {
        cout << "Wide receiver " << i + 1 << ": " << wrfname[i] << " " << wrlname[i] << " scored " << wrpoints[i] << " points this week." << endl;
        cout << wrfname[i] << " " << wrlname[i] << " had " << wrrec[i] << " receptions, " << wryds[i] << " yards, and " << wrtds[i] << " touchdowns." << endl;
    }

    for (int i = 0; i < rbs; i++)
    {
        cout << "Running back " << i + 1 << ": " << rbfname[i] << " " << rblname[i] << " scored " << rbpoints[i] << " points this week." << endl;
        cout << rbfname[i] << " " << rblname[i] << " had " << rbrsyds[i] << " rushing yards, " << rbrtds[i] << " rushing touchdowns, " << rbrec[i] << " receptions, " << rbrcyds[i] << " receiving yards, and " << rbrctds[i] << " receiving touchdowns." << endl;
    }

    for (int i = 0; i < tes; i++)
    {
        cout << "Tight end " << i + 1 << ": " << tefname[i] << " " << telname[i] << " scored " << tepoints[i] << " points this week." << endl;
        cout << tefname[i] << " " << telname[i] << " had " << terec[i] << " receptions, " << teyds[i] << " yards, and " << tetds[i] << " touchdowns." << endl;
    }

    return 0;
}

// Function Definitions to calculate each player's points and place them within an array
void GetWrPoints(int wrrec[], int wryds[], int wrtds[], float wrpoints[], int wrs)
{
    for (int i = 0; i < wrs; i++) 
    {
        wrpoints[i] = wrrec[i] + wryds[i] * 0.1 + wrtds[i] * 6;
    }
}

void GetRbPoints(int rbrsyds[], int rbrtds[], int rbrec[], int rbrcyds[], int rbrctds[], float rbpoints[], int rbs)
{
    for (int i = 0; i < rbs; i++)
    {
        rbpoints[i] = rbrsyds[i] * 0.1 + rbrtds[i] * 6 + rbrec[i] + rbrcyds[i] * 0.1 + rbrctds[i] * 6;
    }
}

void GetTePoints(int terec[], int teyds[], int tetds[], float tepoints[], int tes)
{
    for (int i = 0; i < tes; i++)
    {
        tepoints[i] = terec[i] + teyds[i] * 0.1 + tetds[i] * 6;
    }
}

void GetQbPoints(int qbpyds[], int qbptds[], int qbryds[], int qbrtds[], float qbpoints[])
{
    for (int i = 0; i < 1; i++)
    {
        qbpoints[i] = qbpyds[i] * 0.04 + qbptds[i] * 4 + qbrtds[i] * 6 + qbryds[i] * 0.1;
    }
}