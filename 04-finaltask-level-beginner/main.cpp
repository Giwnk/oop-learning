#include <iostream>
using namespace std;

class Product {
    private:
        // Attributes
        string code,name;
        double price,resTotalPrice;
        int stock;

    public:
        void inputdata(string inputCode,string inputName,double inputPrice,int inputStock){ // Setter
            if (inputName.length() >= 0 && inputPrice >= 0 )
            {
                cout << "Input Success!!" << endl;
                code = inputCode;
                name = inputName;
                price = inputPrice;
                stock = inputStock;
            }
            else
            {
                cout << "Input Invalid!!" << endl;
            }
            
        }

        double calculateTotalPrice(double inputPrice,int inputStock){ // Method
            return inputPrice * inputStock;
        }

        Product (string inputCode,string inputName,double inputPrice, int inputStock){ // Constructor
            inputdata(inputCode,inputName,inputPrice,inputStock);
            resTotalPrice = calculateTotalPrice(inputPrice,inputStock);
        }


        void showData(){ // Getter
            cout << "========================" << endl;
            cout << "== Code: " << code << endl;
            cout << "== Name: " << name << endl;
            cout << "== Price: " << price << endl;
            cout << "== Stock: " << stock << endl;
            cout << "== Total Price: " << resTotalPrice << endl;
            cout << "========================" << endl;
        }

};

int main(int argc, char const *argv[])
{
    Product products[3] = { // Array Of Objects
        Product("ID033","Milk",4.5,40),
        Product("ID796","Egg",3.0,85),
        Product("ID5106","Rice",15.8,27),
    };

    for (Product product : products)
    {
        product.showData();
    }
    
    return 0;
}
