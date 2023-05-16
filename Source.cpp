#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

#include "Characters.h"
#include "Arena.h"
#include "ASCII_Pics.h"

using namespace std;


int main() {
    system("chcp 65001");

    srand(time(NULL));

    // intro animation 
    for (int i = 0; i <= 4; i++) {

        std::cout << ascii_pics::tigerPic;
        Sleep(100);
        system("cls");
        Sleep(100);
    }
    std::cout << ascii_pics::logo;
    Sleep(500);
    system("cls");
    
    //side selection
    int side(0);
    do {
       
        cout << "\nВыбери сторону?\n";
        cout << "1 - хищник, 2 - жертва\n";
        cin >> side;

        if (side <= 2 && side >= 1) {
            break;
        }
        else cout << "Некорректный ввод, попробуй ещё раз \n";

    } while (true);



    Prey prey("prey", Point2D(5, 20), (side == 2));
    Predator predator("predator", Point2D(3, 10), (side == 1));

    Arena arena(40, 40, &prey, &predator);

    for (int i = 0; i <= 40; i++) {
        cout << arena;

        prey.autoMove();
        predator.autoMove();        
        
        if (arena.checkOverRun())
        {
            prey.moveTo(prey.getPastLocation());
            predator.moveTo(predator.getPastLocation());
        }

        arena.clearStep(prey.getPastLocation(), predator.getPastLocation());        
            
        system("cls");
    }
    

    //
    //cout << "Enter a name for your prey: ";    
    //cin >> prey_name;
    //cout << "Enter a name for your predator: ";
    //cin >> predator_name;
    //
    //cout << "За кого хотите играть? (0-жертва, 1-хищник)" << endl;
    //cin >> sideChoice;

    //bool preyNpc = true;
    //if (sideChoice == 0) preyNpc = false;

    //Prey prey(prey_name, Point2D(1, 1), preyNpc);
    //Predator predator(predator_name, Point2D(7, 1), !preyNpc);

    //prey.autoMove();
    //predator.autoMove();


    //Arena arena(10, 10, &prey, &predator);
    //cout << arena << endl;

    //while (1) {
    //    
    //    if (sideChoice == 0) {
    //        if (check(prey, predator)) {
    //            
    //            predator.MoveTo(prey.getx(), prey.gety());
    //            
    //            cout << arena;
    //            cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
    //            return 0;
    //        }
    //        else {
    //            prey.AutoMove(arena, sideChoice);
    //            predator.AutoMove(arena, sideChoice);
    //            cout << arena << endl;
    //        }
    //    }
    //    
    //    else {
    //        if (check1(prey, predator)) {
    //            cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
    //            return 0;
    //        }
    //        else {
    //            prey.AutoMove(arena, sideChoice);
    //            predator.AutoMove(arena, sideChoice);
    //            cout << arena << endl;
    //        }
    //    }
    //}

    return 0;
}