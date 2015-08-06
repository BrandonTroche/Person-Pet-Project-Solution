/*
Code by: Brandon Troche
Commented by: Brandon Troche
Submitted to MakeSchool for the readiness test.
Edited on: 4/26/2015
Edited on: 5/6/2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;            /*I have updated stylistically to your fancy, though to explain I am taught to always have header files*/
                                /*And even when I'm not using them (to make sure it compiles safely on another computer) it is force of*/
class Pet {                     /*habit that causes me to separately declare all methods of the class even when not using a header file.*/
    string name;
    string noise;
    bool canMakeNoise;
public:
    virtual void eat() {cout<<getName()<<" is eating...\n";};

    void makeNoise(int numTimes) {
        if(canMakeNoise){
        for(int i=0; i<numTimes; i++){
            cout<<getName()<<" says: "<<getNoise()<<endl;
        }
    }
    else{
            cout<<getName()<<" *remains silent*\n";
        }
    };

    Pet () {};
    Pet (string setName, bool setMakeNoise, string setNoise) : name(setName), canMakeNoise(setMakeNoise), noise(setNoise) {}

    string getName(){
        return name;
    };

    string getNoise(){
        return noise;
    };
};

class Dog : public Pet{
public:
    Dog (string petName, bool makeNoise ) : Pet(petName, makeNoise, "bark!") {}   /*Instead of taking the noise as input to the constructor it is now a constant value*/
    virtual void eat() {                                                        /*within the Pet constructor instead which cannot be modified in the main()*/
        Pet::eat();      /*I properly call the superclass function here*/
        };

};

class Cat : public Pet {
public:
    Cat (string petName, bool makeNoise) : Pet(petName, makeNoise, "*meow*") {}
    virtual void eat() {
        Pet::eat();
        cout<<"I'm still hungry, *meow*\n";  /*Once again I properly call the superclass function while also adding a line of code*/
        };


};

class Human {
    string name;            /*The friend declaration I had here was left over from the first draft, I didn't need it and I didn't intend it*/
    Pet* pet;
    static int populationSize;
public:
    void makePetMakeNoise(){
        int num;
        srand(time(NULL));
        num = rand() % 10;
        pet->makeNoise(num);
    };

    void feedPet(){
        pet->eat();
    };


    Human(string name, Pet* pet) : name(name), pet(pet) {populationSize++;}

    static int populationCount() {
        return populationSize;
    };          /*I have added the static method for populationCount and this can now be called without an object*/
};

int Human::populationSize = 0;

int main (){

    vector <Human> Human_List;

    Dog Fluffy ("Fluffy", 1);
    Dog Chewy("Chewy", 0);
    Cat Mittens("Mittens", 1);
    Cat Aries("Aries", 0);
                                        /*The pointer issue has been resolved. Pointers are pretty nifty for C so far as I've seen.*/
    Human Bob("Bob", &Fluffy);          /*Though if swift doesn't work with pointers as much or at all then that would be great.*/
    Human Jeff("Jeff", &Chewy);
    Human George("George", &Mittens);
    Human Will("Will", &Aries);

    Human_List.push_back(Bob);
    Human_List.push_back(Jeff);
    Human_List.push_back(George);
    Human_List.push_back(Will);

    for(int i=0; i<Human_List.size(); i++){
        Human_List[i].feedPet();
        Human_List[i].makePetMakeNoise();
    }

    cout<<"The total number of Humans is "<<Human::populationCount()<<endl;     /*Here, the static method is called without an object*/


};
