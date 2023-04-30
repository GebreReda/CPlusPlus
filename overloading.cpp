#include <iostream>
using namespace std;

class Box{
    private:
        double width;
        double height;
        double breadth;
    public:
        Box():width(1),height(1),breadth(1){}
        Box(double w, double h, double b){
            width = w;
            height = h;
            breadth = b;
        }
        ~Box(){
            cout<<"Box distructor is called"<<endl;
        }
        //Setters
        void setWidth(double w){
            width = w;
        }
        
        void setHeight(double h){
            height = h;
        }
        
        void setBreadth(double b){
            breadth = b;
        }
        //Getters
        double getWidth(){
            return width;
        }
        double getBreadth(){
            return breadth;
        }
        double getHeight(){
            return height;
        }
        double getVolume(){
            return height*width*breadth;
        }

        Box operator+(const Box& b){
            Box box;
            box.height = this->height+b.height;
            box.breadth = this->breadth+b.breadth;
            box.width = this->width + b.width;
            return box;
        }

        Box operator-(const Box& b){
            Box box;
            box.height = this->height - b.height;
            box.breadth = this->breadth - b.breadth;
            box.width = this->width - b.width;
            return box;
        }
         Box operator*(const Box& b){
            Box box;
            box.height = this->height * b.height;
            box.breadth = this->breadth * b.breadth;
            box.width = this->width * b.width;
            return box;
        }
         Box operator/(const Box& b){
            Box box;
            box.height = this->height / b.height;
            box.breadth = this->breadth / b.breadth;
            box.width = this->width / b.width;
            return box;
        }
        //++ operator overloading
        Box operator++(int){
           Box temp(*this);
            temp.height++;
            temp.width++;
            temp.breadth++;
            return temp;
        }
};

int main(){
    Box b1,b2,b3;
    b3=b1+b2;
    cout<<b1.getVolume()<<endl;
    cout<<b2.getVolume()<<endl;
    cout<<b3.getVolume()<<endl;

    //parametirized constructors
    Box b4(3,1,5);
    cout<<b4.getVolume()<<endl;
    //Box subtraction operations
    Box b5 = b4-b1;
    cout<<b5.getVolume()<<endl;

     //Box addition operations
    Box b6 = b4+b1;
    cout<<b6.getVolume()<<endl;

    //Box multiplication operations
    Box b7 = b4*b1;
    cout<<b7.getVolume()<<endl;
    //Box division operations
    Box b8 = b4*b1;
    cout<<b8.getVolume()<<endl;

     Box b9 = b4*b3*b2;
    cout<<b9.getVolume()<<endl;
    cout<<b9.getBreadth()<<": "<<b9.getWidth()<<": "<<b9.getHeight()<<endl;

    b9 = b9++;
    cout<<b9.getVolume()<<endl;


    return 0;
}