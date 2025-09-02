// Task 4 - Using Logic

#include <iostream>
using namespace std;

class Product{
    private:
        string productName;
        int stock;
        double price;
    public:
        void setProductName(string inputProductName){
            productName = inputProductName;
        }
        void setStock(int inputStock){
            if (inputStock >= 0)
            {
                stock = inputStock;
            }
            else
            {
                cout << "Invalid Input, Make sure the stock is bigger than equal 0!" << endl;
            }
        }
        void setPrice(double inputPrice){
            if (inputPrice > 0)
            {
                price = inputPrice;
            }
        }

        string getProductName(){
            return productName;
        }
        int getStock(){
            return stock;
        }
        double getPrice(){
            return price;
        }
};

int main(int argc, char const *argv[])
{
    string productName;
    int stock;
    double price;    

    Product product1;
    product1.setProductName("Milk");
    product1.setStock(-1);
    product1.setPrice(0);

    productName = product1.getProductName();
    stock = product1.getStock();
    price = product1.getPrice();

    cout << productName << " -- Stock: " << stock << " -- Price: " << price << endl;
    return 0;
}
