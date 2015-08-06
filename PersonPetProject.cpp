#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pet {
friend class Human;
    string Pet_name, petNoise;
    bool canMakeNoise;
public:
    void makeNoise(int x);
    void setPetName(string x);
    void setMakeNoise(bool x);
    void setPetNoise(string x);

    string getPetName();
    string getPetNoise();
};

class Dog: public Pet {
friend class Human;
public:
    void setStats_Dog(string x, bool y);
    void eat();
};

class Cat: public Pet{
friend class Human;
public:
    void setStats_Cat(string x, bool y);
    void eat();
};

class Human {
    string Human_name, petType;
    Dog Human_petDog;
    Cat Human_petCat;
    static int populationSize;

public:
    void makePetMakeNoise(int x); //calls makeNoise
    void feedPet();
    void setStats(string x, string y, string z, bool w);
    string getPetType();
    int populationCount();

};

int Human::populationSize = 0;

void Pet::makeNoise(int x){

    if(canMakeNoise){
        for(int i=0; i<x; i++){
            cout<<getPetName()<<" says: "<<getPetNoise()<<endl;
        }
    }
    else{
            cout<<getPetName()<<" *remains silent*\n";
        }
    }


void Human::makePetMakeNoise(int x){
    if(getPetType() == "Dog"){
    Human_petDog.makeNoise(x);
    }   else if (getPetType()=="Cat"){
        Human_petCat.makeNoise(x);
        }
}

string Human::getPetType(){
    return petType;
}

void Human::setStats(string x, string y, string z, bool w){
    Human_name = x;
    petType = z;
    if(getPetType()=="Dog"){
    Human_petDog.setStats_Dog(y, w);
    }   else if(getPetType()=="Cat"){
        Human_petCat.setStats_Cat(y, w);
        }
    populationSize++;
}

int Human::populationCount(){
    return populationSize;
}

void Human::feedPet(){
    if(getPetType() == "Dog"){
    Human_petDog.eat();
    }   else if (getPetType()=="Cat"){
        Human_petCat.eat();
        }
}

void Pet::setPetName(string x){
    Pet_name = x;
}

void Pet::setMakeNoise(bool x){
    canMakeNoise = x;
}

void Pet::setPetNoise(string x){
    petNoise = x;
}

string Pet::getPetName(){
    return Pet_name;
}

string Pet::getPetNoise(){
    return petNoise;
}

void Dog::eat(){
        cout<<getPetName()<<" is eating...\n";
}

void Dog::setStats_Dog(string x, bool y){
    setPetName(x);
    setMakeNoise(y);
    setPetNoise("*bark!*");
}

void Cat::eat(){
    cout<<getPetName()<<" is eating...\n"<<"I'm still hungry, *meow*.\n";
}

void Cat::setStats_Cat(string x, bool y){
    setPetName(x);
    setMakeNoise(y);
    setPetNoise("*meow*");
}

int main(){

    vector <Human> Human_List;

    Human Jeff;
    Jeff.setStats("Jeff", "Fluffy", "Dog", 1);

    Human Bob;
    Bob.setStats("Bob", "Mittens", "Cat", 1);

    Human George;
    George.setStats("George", "Chewy", "Dog", 0);

    Human Will;
    Will.setStats("Will", "Aries", "Cat", 0);


    Human_List.push_back(Jeff);
    Human_List.push_back(Bob);
    Human_List.push_back(George);
    Human_List.push_back(Will);

    for(int i=0; i<Human_List.size(); i++){
        Human_List[i].feedPet();
        Human_List[i].makePetMakeNoise(2);
    }

    cout<<"The total number of Humans is "<<Will.populationCount()<<endl;

}
