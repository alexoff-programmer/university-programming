#include <iostream>
#define N 100
using namespace std;

struct club {
    string name;
    int league;
    int points;
};

string league_tl(int league) {
    switch (league) {
    case 0:
        return "Высшая";
        break;
    case 1:
        return "Первая";
        break;
    case 2:
        return "Вторая";
        break;
    default:
        return "error";
        break;
    }
}

void make_clubs(club* clubs, int num) {
    for (int i = 0; i < num; i++) {
        cin >> clubs[i].name;
        cin >> clubs[i].league;
        cin >> clubs[i].points;
    }
}

void show(club club, int i) {
    cout << i + 1 << ": " << club.name << ", лига = " << league_tl(club.league) << ", очки = " << club.points << endl;
}

void show(club* clubs, int num) {
    cout << "Участники:" << endl;
    for (int i = 0; i < num; i++) {
        show(clubs[i], i);
    }
    cout << endl;
}

void sort_club(club* clubs, int num) {
    int max;
    club temp;
    for (int i = 0; i < num; i++) {
        max = i;
        for (int j = i + 1; j < num; j++) {
            if (clubs[j].league < clubs[max].league || clubs[j].league == clubs[max].league && clubs[j].points > clubs[max].points) {
                max = j;
            }
        }
        temp = clubs[max];
        clubs[max] = clubs[i];
        clubs[i] = temp;
    }
    
}

void league_selection(int league, club* clubs, int num) {
    cout << "Лига " << league_tl(league) << ":" << endl;
    for (int i = 0; i < num; i++) {
        if (clubs[i].league == league)
            show(clubs[i], i);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    club* clubs = new club[5];
    make_clubs(clubs, 5);
    show(clubs, 5);
    sort_club(clubs, 5);
    show(clubs, 5);
    league_selection(0, clubs, 5);
}
