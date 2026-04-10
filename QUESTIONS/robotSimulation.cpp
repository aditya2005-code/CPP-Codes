#include <bits/stdc++.h>
using namespace std;

class Robot {
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South
    int perimeter;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        if (perimeter == 0) return;
        
        num %= perimeter;

        // Correct handling of full cycle
        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 3; // South
            }
            return;
        }

        while (num--) {
            if (dir == 0) { // East
                if (x + 1 < w) x++;
                else {
                    dir = 1;
                    y++;
                }
            }
            else if (dir == 1) { // North
                if (y + 1 < h) y++;
                else {
                    dir = 2;
                    x--;
                }
            }
            else if (dir == 2) { // West
                if (x - 1 >= 0) x--;
                else {
                    dir = 3;
                    y--;
                }
            }
            else { // South
                if (y - 1 >= 0) y--;
                else {
                    dir = 0;
                    x++;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

int main() {
    Robot obj(4, 5);

    obj.step(44);
    obj.step(19);
    obj.step(8);
    obj.step(36);

    vector<int> pos = obj.getPos();
    cout << "Position: [" << pos[0] << ", " << pos[1] << "]\n";
    cout << "Direction: " << obj.getDir() << "\n";

    obj.step(17);
    obj.step(49);
    obj.step(14);
    obj.step(40);

    pos = obj.getPos();
    cout << "Position: [" << pos[0] << ", " << pos[1] << "]\n";
    cout << "Direction: " << obj.getDir() << "\n";

    obj.step(18);
    obj.step(7);

    pos = obj.getPos();
    cout << "Position: [" << pos[0] << ", " << pos[1] << "]\n";
    cout << "Direction: " << obj.getDir() << "\n";

    obj.step(8);
    obj.step(5);
    obj.step(2);
    obj.step(36);
    obj.step(22);

    pos = obj.getPos();
    cout << "Position: [" << pos[0] << ", " << pos[1] << "]\n";

    return 0;
}