#include <iostream>
using namespace std;

class Flashlight {
private:
    int id;
public:
    Flashlight(int i) : id(i) {
        cout << "Flashlight " << id << " created." << endl;
    }
    ~Flashlight() {
        cout << "Flashlight " << id << " destroyed." << endl;
    }
};

void useLight() {
    Flashlight f2(2);
}

int main() {
    Flashlight f1(1);
    {
        Flashlight f3(3);
    }
    useLight();
    Flashlight f4(4);
    return 0;
}
