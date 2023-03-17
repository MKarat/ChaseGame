#pragma once

#include "Point2D.h"

class Character {

private:

    string name;
    Point2D location;
    bool npc;

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : name(name), location(location), npc(npcFlag){   }

    //0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - �����-����� 
    //5 - �����-������ 6 - ����-������ 7 - ����-�����
    void MoveTo(int direction, int steps) {
        
        int deltaX(0), deltaY(0);

        switch (direction)
        {
        case 0:
            deltaY = 1;
            break;
        case 1:
            deltaX = 1;
            break;
        case 2:
            deltaY = -1;
            break;
        case 3:
            deltaX = -1;
            break;
        case 4:
            deltaX = -1;
            deltaY = 1;            
            break;
        case 5:
            deltaX = 1;
            deltaY = 1;
            break;
        case 6:
            deltaX = 1;
            deltaY = -1;            
            break;
        case 7:
            deltaX = -1;
            deltaY = -1;            
            break;
        default:
            break;
        }

        location.setPoint(location.getX() + deltaX*steps, location.getY() + deltaY*steps);
    }

    Point2D getLocation() {
        return location;
    }

    bool isNPC() { return npc; }

    virtual void AutoMove() = 0;

    //ostream& operator<<(ostream& out, const Character& p) {
    //    out << "��� ��������� - " << p.name << "���������� ��������� - " << p.location << endl;
    //    return out;
    //}
};


class Prey : Character {

private:

    //friend ostream& operator<<(ostream&, const Arena&);
    //friend Predator;
    //friend class Arena;

    const int range = 1;

public:
    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0) : Character(name, location, npcFlag) {   }

    void AutoMove() override;

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);

};



class Predator : Character{
private:
    //friend Prey;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);

    int range;

public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag), range(0) {   }


    void AskRange() {
        do {
            cout << "�� �������? (1-5)" << endl;
            cin >> range;
            if (1 <= range && range <= 5) break;
        } while (true);
    }

    void AutoMove();

    //friend ostream& operator<<(ostream&, const Predator&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
};




void Prey::AutoMove() {
    
    int direction;

    if (isNPC()) {
        direction = rand() % 8;        
    }
    else {
        cout << "���� ����?\n0-�����-����� 1-����� 2-�����-������ 3-����� 4-������ 5-����-����� 6-���� 7-����-������" << endl;
        cin >> direction;
    }
    
    MoveTo(direction, range);   
}



void Predator::AutoMove() {
    
    int direction;

    if (isNPC()) {
        direction = rand() % 4;
        SetRange(rand() % 5 + 1);
    }
    else {
        int s = 0;
        cout << "���� ����?\n0-����� 1-������ 2-���� 3-�����" << endl;
        cin >> direction;
    }

    switch (q) {
    case 0:
        if (location.y >= (a)) {
            location.y -= a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 1:
        if (location.x <= (ar.w - a)) {
            location.x += a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 2:
        if (location.y <= (ar.l - a)) {
            location.y += a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 3:
        if (location.x >= (a)) {
            location.x -= a;
        }
        else cout << "����� �� �������" << endl;
        break;
    }
}
