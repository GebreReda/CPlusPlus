#include<iostream>
using namespace std;
class Shape{
    private:
        double width;
        double height;
    public:
        Shape(): width(1),height(1){}
        Shape(double w, double h){
                height = h;
                width = w;
        }
        ~Shape(){
            cout<<"Destructor is executing"<<endl;
        }
        double getWidth(){
            return width;
        }
        double getHeight(){
            return height;
        }
        void setWidth(double w){
            width = w;
        }
        void setHeight(double h){
            height = h;
        }
        virtual double getArea(){
            return width * height;
        }
        virtual const char* print(){
            return "This is a Shape class";
        }
};
class Rectangle: public Shape{
    private:
    public:
        Rectangle():Shape(){}
        Rectangle(double w = 1.0, double h=1.0): Shape(w,h){}
        double getArea(){
            return getHeight()*getWidth();
        }
        virtual const char *print(){
          return "This is a rectangle class";
        }
};
class Triangle: public Shape{
    private:
    public:
        Triangle():Shape(){}
        Triangle(double w=1.0, double h=1.0): Shape(w,h){ }
        ~Triangle(){cout<<"Triangle destructor is executing"<<endl;}
        double getArea(){
            return this->getHeight() * this->getWidth() * 0.5;
        }
        virtual const char* print(){
            return "This is a triangle class";
        }
};

int main(){
    //Shape
    Shape S;
    cout<<S.print()<<endl;
    cout<<S.getHeight()<<":"<<S.getWidth()<<endl;
    cout<<"Area of Shape is: "<<S.getArea()<<endl;

    //Rectangle
    Rectangle R(2,2);
    cout<<R.print()<<endl;
    cout<<R.getHeight()<<":"<<R.getWidth()<<endl;
    cout<<"Area of Rectangle is: "<<R.getArea()<<endl;

     //Triangle
    Triangle T(8,4);
    cout<<T.print()<<endl;
    cout<<T.getHeight()<<":"<<T.getWidth()<<endl;
    cout<<"Area of Triangle is: "<<T.getArea()<<endl;
    cout<<"Polymorphism"<<endl;

    //polymorphism
    //Rectangle
    Shape *Ptr = &S;
    cout<<Ptr->print()<<endl;
    cout<<Ptr->getHeight()<<":"<<Ptr->getWidth()<<endl;
    cout<<Ptr->getArea()<<endl;

    //polymorphism on Rectangle
    Ptr = &R;
    cout<<Ptr->print()<<endl;
    cout<<Ptr->getHeight()<<":"<<Ptr->getWidth()<<endl;
    cout<<Ptr->getArea()<<endl;

    //polymorphism on Triangle
    Ptr = &T;
    cout<<Ptr->print()<<endl;
    cout<<Ptr->getHeight()<<":"<<Ptr->getWidth()<<endl;
    cout<<Ptr->getArea()<<endl;

    return 0;
}