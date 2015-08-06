/*
Code by: Brandon Troche
Commented by: Brandon Troche
Submitted to MakeSchool for the readiness test.
Edited on: 4/26/2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>                 /*All previous comments have been edited out and replaced by comments focusing on the areas I was told needed improvement*/
#include <time.h>                   /*All 5 points that were made to me in the follow-up email I have worked to incorporate and taken into consideration for future code designing*/
                                    /*The code was re-imagined and re-written almost entirely to be more professionally implemented*/
using namespace std;

class Pet {
friend class Human;
    string name;
    string noise;
    bool canMakeNoise;
public:
    virtual void eat() {cout<<getName()<<" is eating...\n";};          /*As changed from my first attempt, here I have incorporated polymorphism*/
    void makeNoise(int numTimes);                                      /*As well it should be noticed now all my variables are named accordingly*/

    Pet () {};
    Pet (string setName, string setNoise, bool setMakeNoise) : name(setName), noise(setNoise), canMakeNoise(setMakeNoise) {}
                                                                /*Every class now has a default and custom constructor and the setters are gone*/
    string getName();
    string getNoise();
};

class Dog : public Pet{
public:
    Dog (string petName, string setNoise, bool makeNoise ) : Pet(petName, setNoise, makeNoise) {}      /*The Cat and Dog classes call the Pet constructor*/
    virtual void eat() {cout<<getName()<<" is eating...\n";};

};

class Cat : public Pet {
public:
    Cat (string petName, string setNoise, bool makeNoise) : Pet(petName, setNoise, makeNoise) {}
    virtual void eat() {
        cout<<getName()<<" is eating...\n";
        cout<<"I'm still hungry, *meow*\n";
        };


};

class Human {
    string name;                  /*The Human class now only has 3 member variables as it should*/
    Pet* pet;                       /*This is a pointer to the pet of the Human so the eat() function can call correctly from the Dog and Cat classes*/
    static int populationSize;       /*This is still a static integer as before*/
public:
    void makePetMakeNoise();
    void feedPet();

    Human(string name, Pet* pet) : name(name), pet(pet) {populationSize++;}
                                    /*Human constructor takes a string and a pet object and increments population by 1 when called*/
    int populationCount();
};

int Human::populationSize = 0;

void Pet::makeNoise(int numTimes){

    if(canMakeNoise){
        for(int i=0; i<numTimes; i++){
            cout<<getName()<<" says: "<<getNoise()<<endl;
        }
    }
    else{
            cout<<getName()<<" *remains silent*\n";
        }
    }

string Pet::getName(){
    return name;
}

string Pet::getNoise(){
    return noise;
}

int Human::populationCount(){
    return populationSize;
}

void Human::feedPet(){
    pet->eat();
}
                            /*Both methods of Human that refer to the pet are pointers to make sure the right call executes.*/
void Human::makePetMakeNoise(){
    int num;
    srand(time(NULL));           /*Here I have got a small random number generator that should pick a different random number each time the program is run*/
    num = rand() % 10;          /*Although I made a design choice of limiting the random number to a maximum of 5 so execution was easier to read through*/
    pet->makeNoise(num);
}

int main (){

    vector <Human> Human_List;

    Dog Fluffy ("Fluffy", "*bark!*", 1);
    Dog Chewy("Chewy", "*bark*!", 0);
    Cat Mittens("Mittens", "*meow*", 1);
    Cat Aries("Aries", "*meow*", 0);

    Pet *pet1 = &Fluffy;
    Pet *pet2 = &Chewy;
    Pet *pet3 = &Mittens;
    Pet *pet4 = &Aries;

    Human Bob("Bob", pet1);
    Human Jeff("Jeff", pet2);
    Human George("George", pet3);
    Human Will("Will", pet4);

    Human_List.push_back(Bob);
    Human_List.push_back(Jeff);
    Human_List.push_back(George);
    Human_List.push_back(Will);

    for(int i=0; i<Human_List.size(); i++){
        Human_List[i].feedPet();
        Human_List[i].makePetMakeNoise();
    }

    cout<<"The total number of Humans is "<<Will.populationCount()<<endl;


};
