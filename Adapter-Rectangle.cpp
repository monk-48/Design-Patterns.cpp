#include <bits/stdc++.h>
using namespace std;

class LegacyRectange {
public:
    void draw (int x1, int y1, int x2, int y2){
        cout<<"Legacy Rectangle: Drawing from ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<")"<<endl;
        return;
    }
};

class IRectangle {
public:
    virtual void draw() = 0;
};

class RectangleAdapter : public IRectangle {
private:
    LegacyRectange* Lr;
    int x1, x2, y1, y2;
public:
    RectangleAdapter (int x1, int y1, int h, int w){
        // this is a pointer, so we need to use the arrow operator "->"
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = this->x1 + h;
        this->y2 = this->y1 + w;
    }
    
    void draw() override {
        Lr->draw(x1, y1, x2, y2);
    }
};

int main() {
    IRectangle *Rectangle = new RectangleAdapter (10, 20, 5, 10);
    Rectangle->draw();
}
