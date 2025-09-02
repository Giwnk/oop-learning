#include <iostream>
using namespace std;

class Media {
    private:
    string title;
    int year;

    public:
    Media(string inputTitle, int inputYear){
        title = inputTitle;
        year = inputYear;
    }

    string getTitle(){
        return title;
    }

    int getYear(){
        return year;
    }

    virtual void displayInfo(){
        cout << "Title: " << getTitle() << endl;
        cout << "Year: " << getYear() << endl;
    }
};

class Book : public Media{
    private:
    string author;

    public:
    Book(string inputTitle, int inputYear, string inputAuthor)
    : Media(inputTitle,inputYear){
        author = inputAuthor;
    }

    string getAuthor(){
        return author;
    }

    void displayInfo(){
        cout << "Title: " << getTitle() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Author: " << getAuthor() << endl; 
    }
};

class Comic : public Media{
    private:
    int volume;

    public:
    Comic(string inputTitle, int inputYear, int inputVolume)
    : Media(inputTitle,inputYear){
        volume = inputVolume;
    }

    int getVolume(){
        return volume;
    }

    void displayInfo(){
        cout << "Title: " << getTitle() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Volume: " << getVolume() << endl; 
    }
};

int main(int argc, char const *argv[])
{
    
    Book book1("Laut Bercerita",2005,"Lela S. Chudori");
    Book book2("Overthingkin Is My Hobby",2024,"Adi Syauqi");
    Comic comic1("Naruto",2009,100);
    Comic comic2("Attack On Titan",2010,76);
    
    Media* medias[4] = {&book1,&book2,&comic1,&comic2} ;

    for (Media* media : medias)
    {
        media->displayInfo();
    }
    
    return 0;
}
