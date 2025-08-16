#include <iostream>
using namespace std;

class Film{
    private:
        string title,director;
        int year;
        double rating;
    public:
        Film(){
        title = "";
        director = "";
        year = 0;
        rating = 0;
        }

        void setDataFilm(string inputTitle, string inputDirector, int inputYear, double inputRating){
            title = inputTitle;
            director = inputDirector;
            year = inputYear;
            if (inputRating >= 0)
            {
                rating = inputRating;
            }
            else
            {
                rating = 0;
            }
        }

        Film(string inputTitle, string inputDirector, int inputYear, double inputRating){
            setDataFilm(inputTitle,inputDirector,inputYear,inputRating);
        }

        void getDataFilm(){
            cout << "=======================" << endl;
            cout << "Title : " << title << endl;
            cout << "Director : " << director << endl;
            cout << "Year: " << year << endl;
            cout << "Rating: " << rating << endl;
        }


        double getRating(){
            return rating;
        }

        bool isGoodRate(){
            if (rating >= 7.5)
            {
                return true;
            }
            return false;
        }

        int filmAge(int inputCurrentYear){
            return inputCurrentYear - year;
        }

        string getTitle(){
            return title;
        }

};

int main(int argc, char const *argv[])
{   
    int option;


    cout << "===== Welcome to the movie data management application ====" << endl;
    int numberOfFilms;
    cout << "How Many Films Do You want To Input? ";
    cin >> numberOfFilms;
    cin.ignore();

    Film films[numberOfFilms];
    for (int i = 0; i < numberOfFilms; i++)
    {
        string title,director;
        int year;
        double rating;
        
        cout << i+1 << " Film" << endl;
        cout << "Input Title Film: " << endl;
        getline(cin,title);
        cout << "Input Director Film: " << endl;
        getline(cin,director);
        cout << "Input Year Film: " << endl;
        cin >> year;
        cout << "Input Rating Film: " << endl;
        cin >> rating;
        cin.ignore();

        films[i] = Film(title,director,year,rating);

    }
    do {
        cout << "1. Show Data Film" << endl;
        cout << "2. Search Film With Highest Rate" << endl;
        cout << "3. Show Good Rate Film" << endl;
        cout << "4. Calculate Age Film" << endl;
        cout << "5. Exit " << endl;
        cout << "Choose the option";
        cin >> option;
        
        if (option == 1)
        {
            
            for (Film film : films)
            {
                film.getDataFilm();
            }
        }
        else if (option == 2)
        {
            int index = 0;
            for (int i = 1; i < numberOfFilms; i++)
            {
                if (films[i].getRating() > films[index].getRating())
                {
                    index = i;
                }
            }
            cout << " With Highest Rating is: " << endl;
            films[index].getDataFilm();
            /* code */
        }
        else if (option == 3)
        {
            /* code */
            for (int i = 0; i < numberOfFilms; i++)
            {
                if (films[i].isGoodRate())
                {
                    films[i].getDataFilm();
                }
            }
        }
        else if (option == 4)
        {
            /* code */
            int currentYear;
            cout << "Input The Current Year: ";
            cin >> currentYear;
            for (int i = 0; i < numberOfFilms; i++)
            {
                cout << films[i].getTitle() << " Movie is " << films[i].filmAge(currentYear) << " Years Old" << endl;
            }
        }
        
        else if (option == 5)
        {
            /* code */
            cout << "Exit From Program." << endl;
        }
        
        else
        {
            cout << "Input Invalid" << endl;
        }
        
    } while(option != 5);
    return 0;
}
