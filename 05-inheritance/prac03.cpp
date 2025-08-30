#include <iostream>
using namespace std;

class Book {
    private:
    string title,author;
    int publicationYear;

    public:
    Book(string inputTitle,string inputAuthor,int inputPublicationYear){
        title = inputTitle;
        author = inputAuthor;
        publicationYear = inputPublicationYear;
    }

    // Setter
    void setTitle(string inputTitle){
        title = inputTitle;
    }
    void setAuthor(string inputAuthor){
        author = inputAuthor;
    }
    void setPublicationYear(int inputPublicationYear){
        publicationYear = inputPublicationYear;
    }

    // Getter
    string getTitle(){return title;}
    string getAuthor(){return author;}
    int getPublicationYear(){return publicationYear;}

    // Methods
    void showData(){
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Publicatioon Year: " << getPublicationYear() << endl;
    }
};

class Magazine : public Book{
    private:
    int edition,publicationMonth;

    public:
    Magazine(string inputTitle,string inputAuthor,int inputPublicationYear,int inputEdition, int inputpublicationMonth)
    : Book(inputTitle,inputAuthor,inputPublicationYear){
        edition = inputEdition;
        publicationMonth = inputpublicationMonth;
    }

    void setEdition(int inputEdition){
        edition = inputEdition;
    }
    void setPublicationMonth(int inputPublicationMonth){
        publicationMonth = inputPublicationMonth;
    }

    int getEdition(){return edition;}    
    int getPublicationMonth(){return publicationMonth;}

    void showMagazineData(){
        showData();
        cout << "Edition: " << getEdition() << endl;
        cout << "Publication Month: " << getPublicationMonth() << endl;
    }   
};

class Comic : public Book{
    private:
    int volume;

    public:
    Comic(string inputTitle,string inputAuthor,int inputPublicationYear,int inputVolume)
    : Book(inputTitle,inputAuthor,inputPublicationYear){
        volume = inputVolume;
    }

    void setVolume(int inputVolume){
        volume = inputVolume;
    }

    int getVolume(){return volume;}

    void showComicData(){
        showData();
        cout << "Volume: " << getVolume() << endl;
    }
};

int main(int argc, char const *argv[])
{
    Magazine magazines[3] = {
        Magazine("National Geographic","John Smith",2022,155,01),
        Magazine("TIME","Sarah Johnson",2021,95,03),
        Magazine("Forbes","Michael Brown",2023,210,07)
    };

    Comic comics[3] = {
        Comic("One Piece","Eiichiro Oda",1999,101),
        Comic("Naruto","Masashi Kishimoto",2002,172),
        Comic("Attack On Titan","Hajime Isayama",2009,34)
    };

    cout << "\n===== Magazines Data ======" << endl;
    for (auto magazine : magazines)
    {
        magazine.showMagazineData();
        cout << "-----------------" << endl;
    }


    cout << "\n===== Comics Data ======" << endl;
    for (auto comic : comics)
    {
        comic.showComicData();
        cout << "-----------------" << endl;
    }
    
    
    return 0;
}
