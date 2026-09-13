#include<iostream>
#include<string>

using namespace std;

struct Book 
{
    string title;
    string author;
    int pages;
    float price;
};

int main() 
{
    
    Book my_book;

    cout<< "Enter Book Title: ";
    getline(cin, my_book.title);

    cout<< "Enter Author Name: ";
    getline(cin, my_book.author);

    cout<< "Enter Number of Pages: ";
    cin>>my_book.pages;

    cout<< "Enter Book Price: ";
    cin>>my_book.price;

    cout<<endl<< "Book Details:"<<endl;
    cout<<endl<< "Title: " <<my_book.title<<endl;
    cout<<endl<< "Author: " <<my_book.author<<endl;
    cout<<endl<< "Pages: " <<my_book.pages<<endl;
    cout<<endl<< "Price: RS." <<my_book.price<<endl;

    return 0;
}
