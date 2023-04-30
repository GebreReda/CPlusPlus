#include<iostream>
using namespace std;

class Shape{
    private:
        int width;
        int height;
    public:
        Shape(): width(1),height(1){}
        Shape(const Shape& S) : width(S.width), height(S.height){}
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }
        int getWidth(){
            return height;
        }
        int getHeight(){
            return width;
        }
        virtual int getArea(){
            cout<<"Area from Shape is: ";
            return getWidth() * getHeight();
        }
        friend void shapeFriend(const Shape& ss);
        ~Shape(){
            cout<<"This is destructor for the Shape class"<<endl;
        }
};

void shapeFriend(const Shape& ss){
         cout<<"I am a freind function in Shape class"<<endl;   //return width;
         cout<<ss.width <<" "<<ss.height<<endl;
}

class Rectangle: public Shape{
    private:
    public:
        int getArea(){
            cout<<"Area from Rectangle is: ";
            return getWidth() * getHeight();
        }
};

#define pi 3.14

class Circle{
    private: 
        int radius;
    public:
        Circle(): radius(1){}
        Cirlcle(const  Circle& C1){
            radius = C1.radius;
            cout<<"Copy constructor is called: "<<endl;
        }
        int getRadius(){
            return radius;
        }
        void setRadius(int r){
            radius = r;
        }
        int getArea(){
            return pi*radius*radius;
        }
        
};

// class PaintArea{
//     private:
//     public:
//     int PaintArea(){
//         return (getArea() * 70);
//     }
// }

int main(){
    cout<<"Hello World"<<endl;
    Shape S;
    cout<<S.getWidth()<<endl;
    S.setWidth(2);
    S.setHeight(2);
    cout<<S.getWidth()<<endl;

    Rectangle R;
    cout<<R.getArea()<<endl;

    Shape* SS = &R;
    cout<<SS->getArea()<<endl;

    //Class
    Circle C;
    cout<<C.getArea()<<endl;
    C.setRadius(4);
    cout<<C.getArea()<<endl;

    //Copy constructor for Shape
    Shape S2(S);
    cout<<"Area of copied object is: "<<S2.getArea()<<endl;

    //Copy constructor for Circle
    Circle C2(C);
    cout<<C2.getRadius()<<endl;
     cout<<C2.getArea()<<endl;

     //friend function of Shape
    shapeFriend(S2);
    return 0;
}