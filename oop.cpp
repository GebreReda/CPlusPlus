#include<iostream>
using namespace std;

class Animal{
    private:
        int numChild;
    public:
        Animal() : numChild(0){
            //numChild = 2;
        }
        virtual int getChild(){
            cout<<"Animals: "<<endl;
            return numChild;
        }
        virtual void setChild(int nc){
            numChild = nc;
        }
};

class Mamals: public Animal{
    private:
        int numChild;
    public:
        Mamals() : numChild(0){}
        
        int getChild(){
            cout<<"Mamals: "<<endl;
            return numChild;
        }
        void setChild(int nc){
            numChild = nc;
        }
};


int main(){
    cout<<"Hello World!"<<endl;
    Animal p;
    cout<<p.getChild()<<endl;
    p.setChild(20);

    cout<<p.getChild()<<endl;

    Animal* pp;
    pp = &p;
    cout<<pp->getChild()<<endl;
    pp->setChild(40);
    cout<<pp->getChild()<<endl;

    Mamals m;
    cout<<m.getChild()<<endl;
    m.setChild(90);
    cout<<m.getChild()<<endl;

    pp = &m;
    cout<<pp->getChild()<<endl;
    pp->setChild(50);
    cout<<pp->getChild()<<endl;

    return 0;
}