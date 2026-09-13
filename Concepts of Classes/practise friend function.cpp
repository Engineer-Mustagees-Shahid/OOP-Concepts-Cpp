#include <iostream>
using namespace std;
class beta; // Forward declaration
class alpha {
private:
int data1;
public:
alpha() {
data1 = 3;
}
~alpha() {
// Destructor
}
// Friend function declaration
friend int function1(alpha, beta);
};
class beta {
private:
int data1;
public:
beta() {
data1 = 7;
}
~beta() {
// Destructor
}

// Friend function declaration
friend int function1(alpha, beta);
};
// Friend function definition
int function1(alpha a, beta b) {
int temp;
temp = a.data1 + b.data1;
return temp;
}
int main() {
alpha aa;
beta bb;
cout << "Sum using friend function: " << function1(aa, bb) << endl;
// Pause the program so the output stays visible (optional)
cin.get();
return 0;
}