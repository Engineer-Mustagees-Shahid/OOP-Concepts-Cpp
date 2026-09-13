#include <iostream>
using namespace std;

// ===================== Animal Base Class =====================
class Animal {
protected:
    string name;
    int age;
    string gender;
    string animalType;

public:
    Animal(string animalType, string name, int age, string gender)
        : animalType(animalType), name(name), age(age), gender(gender) {}

    virtual string getName() const { return name; }
    virtual int getAge() const { return age; }
    virtual string getGender() const { return gender; }
    virtual void makeSound() = 0; // Pure virtual function
    virtual void display() const {
        cout << "Animal Type: " << animalType << ", Name: " << name
             << ", Age: " << age << ", Gender: " << gender << endl;
    }
};

// ===================== Bird Derived Class =====================
class Bird : public Animal {
private:
    string color;

public:
    Bird(string name, int age, string gender, string color)
        : Animal("Bird", name, age, gender), color(color) {}

    void makeSound() override {
        cout << name << " chirps!" << endl;
    }

    void display() const override {
        Animal::display();
        cout << "Color: " << color << endl;
    }
};

// ===================== Mammal Derived Class =====================
class Mammal : public Animal {
private:
    float weight;

public:
    Mammal(string name, int age, string gender, float weight)
        : Animal("Mammal", name, age, gender), weight(weight) {}

    void makeSound() override {
        cout << name << " roars!" << endl;
    }

    void display() const override {
        Animal::display();
        cout << "Weight: " << weight << " kg" << endl;
    }
};

// ===================== Reptile Derived Class =====================
class Reptile : public Animal {
private:
    float length;

public:
    Reptile(string name, int age, string gender, float length)
        : Animal("Reptile", name, age, gender), length(length) {}

    void makeSound() override {
        cout << name << " hisses!" << endl;
    }

    void display() const override {
        Animal::display();
        cout << "Length: " << length << " ft" << endl;
    }
};

// ===================== Zookeeper Class =====================
class Zookeeper {
private:
    string zookeeperType;
    string name;
    int age;
    string gender;

public:
    Zookeeper(string zookeeperType, string name, int age, string gender)
        : zookeeperType(zookeeperType), name(name), age(age), gender(gender) {}

    string getZookeeperType() const { return zookeeperType; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }

    void feedAnimal(const Animal &animal) const {
        cout << name << " feeds " << animal.getName() << "." << endl;
    }
};

// ===================== Enclosure Class =====================
class Enclosure {
private:
    string enclosureType;
    int capacity;
    int currentCount;
    Animal **animals;
    Zookeeper *zookeeper;

public:
    Enclosure(string enclosureType, int capacity, Zookeeper *zookeeper)
        : enclosureType(enclosureType), capacity(capacity), currentCount(0) {
        animals = new Animal *[capacity];
    }

    ~Enclosure() {
        delete[] animals;
    }

    string getEnclosureType() const { return enclosureType; }
    int getCapacity() const { return capacity; }
    int getCurrentAnimalCount() const { return currentCount; }

    void addAnimal(Animal *animal) {
        if (currentCount < capacity) {
            animals[currentCount++] = animal;
        } else {
            cout << "Enclosure is full!" << endl;
        }
    }

    void displayAnimals() const {
        cout << "-- Animals in " << enclosureType << " --" << endl;
        for (int i = 0; i < currentCount; ++i) {
            animals[i]->display();
        }
    }
};

// ===================== Main Function =====================
int main() {
    Zookeeper birdKeeper("BirdKeeper", "Alice", 30, "Female");
    Zookeeper mammalKeeper("MammalKeeper", "John", 35, "Male");
    Zookeeper reptileKeeper("ReptileKeeper", "Emma", 28, "Female");

    Enclosure birdEnclosure("BirdEnclosure", 2, &birdKeeper);
    Enclosure mammalEnclosure("MammalEnclosure", 2, &mammalKeeper);
    Enclosure reptileEnclosure("ReptileEnclosure", 2, &reptileKeeper);

    Bird *parrot = new Bird("Parrot", 2, "Male", "Green");
    Mammal *tiger = new Mammal("Tiger", 4, "Female", 200.5);
    Reptile *snake = new Reptile("Cobra", 3, "Male", 5.4);

    birdEnclosure.addAnimal(parrot);
    mammalEnclosure.addAnimal(tiger);
    reptileEnclosure.addAnimal(snake);

    birdEnclosure.displayAnimals();
    mammalEnclosure.displayAnimals();
    reptileEnclosure.displayAnimals();

    birdKeeper.feedAnimal(*parrot);
    mammalKeeper.feedAnimal(*tiger);
    reptileKeeper.feedAnimal(*snake);

    delete parrot;
    delete tiger;
    delete snake;
    return 0;
}
