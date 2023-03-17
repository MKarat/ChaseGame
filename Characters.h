#pragma once

#include "Point2D.h"

class Character {

private:

    string name;        // ��� ���������
    Point2D location;   // ������� ��������� ���������
    bool npc;           // ������� NPC

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : name(name), location(location), npc(npcFlag){   }

    //0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - �����-����� 
    //5 - �����-������ 6 - ����-������ 7 - ����-�����
    void moveTo(int direction, int steps) {
        
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

    virtual void autoMove() = 0; 

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

    const int maxRange = 1;

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0) : Character(name, location, npcFlag) {   }

    int askDirection() {
        int direction (0);
        cout << "���� ����?" << endl;
        cout << "0 - �����, 1 - ������, 2 - ����, 3 - �����," << endl;
        cout << "4 - ����� - �����, 5 - �����-������, 6 - ����-������, 7 - ����-�����" << endl;
        cin >> direction;
        //TODO: �������� ������������ �����
    }

    void autoMove() override {

        int direction = 0;

        if (isNPC()) {
            direction = rand() % 8;
        }
        else {
            direction = askDirection();
        }

        moveTo(direction, maxRange);
    }

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);

};

class Predator : Character{
private:
    //friend Prey;
    //friend class Arena;
    //friend ostream& operator<<(ostream&, const Arena&);

    const int maxRange = 5;
 
public:
    Predator(const std::string& name, const Point2D& location, bool npcFlag = 0) 
        : Character(name, location, npcFlag) {   }

    int askRange() {

        do {
            int range;
            cout << "�� �������? (1-5)" << endl;
            cin >> range;

            if (range >= 1 && range <= maxRange) {
                return range;     
            }
            else cout << "������������ ����, �������� ��� ��� " << endl;

        } while (true);
    }

    int askDirection() {
        int direction(0);
        cout << "���� ����?" << endl;
        cout << "0 - �����, 1 - ������, 2 - ����, 3 - �����," << endl;
        cin >> direction;
        //TODO: �������� ������������ �����
    }

    void autoMove() override {

        int direction = 0;
        int range = 0;

        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {

            direction = askDirection();
            range = askRange();
        }

        moveTo(direction, range);
    }

    //friend ostream& operator<<(ostream&, const Predator&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
};