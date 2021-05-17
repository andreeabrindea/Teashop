#include <fstream>
#include "../Exceptions/Exceptions.h"
#include "../Repository/Repository.h"
#include <iostream>
#include <string>
#include "../Product.h"

class Persistence : public Repository{
protected:
    Repository m_database;

private:
    string filename;
    vector<Product> assistantFiles;
    int positionOfTheCurrent;
    vector<string> convertLine(string Product, char Delimiter);
    vector<Product> readFromFile();


public:
    explicit Persistence(const string &filename);
    void addProduct(const Product& product);
    void deleteProduct(const Product& product);
    void updateProduct(const Product& product);
    vector<Product>getAllProduct();
    Product getNextFile();
    void addProductToFile(const Product& product);

    void writeToFile(const vector<Product>& products);
};
