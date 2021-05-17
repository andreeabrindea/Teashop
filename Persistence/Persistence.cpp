#include "Persistence.h"
#include <cstring>
#include <sstream>
#include <fstream>

Persistence::Persistence(const std::string &filename){
    this->m_database = Repository();
    this->filename = filename;
    this->positionOfTheCurrent = 0;
}

void Persistence::addProduct(const Product &product) {
    vector<Product> products = this->readFromFile();
    products.push_back(product);
    this->writeToFile(products);
}

void Persistence::deleteProduct(const Product &product) {
    vector<Product> products = this->readFromFile();

    auto it = find(products.begin(), products.end(), product);

    if (it != products.end()) {
        products.erase(it);
    }

    this->writeToFile(products);
}

void Persistence::updateProduct(const Product &product) {

    vector<Product> products = this->readFromFile();
    auto it = find(products.begin(), products.end(), product);

    if (it != products.end()) {
        *it = product;
    }
    this->writeToFile(products);
}

vector <Product> Persistence::getAllProduct() {
    vector<Product> products = this->readFromFile();
    return products;
}

Product Persistence::getNextFile() {
    return this->assistantFiles[this->positionOfTheCurrent];
}

void Persistence::addProductToFile(const Product &product) {
    this->assistantFiles.push_back(product);
}

vector <string> Persistence::convertLine(string Product, char Delimiter) {
    stringstream stringProduct(Product);
    std::string fieldOfProduct;
    vector<std::string> product;

    while (getline(stringProduct, fieldOfProduct, Delimiter))
        product.push_back(fieldOfProduct);
    return product;
}

vector <Product> Persistence::readFromFile() {
    std::string product;

    ifstream fin;
    fin.open(this->filename);

    vector<std::string> Products;
    vector<Product> allProducts;
    Product newReadProduct;

    while (fin >> product) {
        Products = this->convertLine(product, ',');
        newReadProduct = Product(stoi(Products[0]), Products[1], Products[2] == "TEA" ? ProductType::TEA : ProductType::ACCESORY);
        allProducts.push_back(newReadProduct);
    }

    fin.close();
    return allProducts;
}

void Persistence::writeToFile(const vector <Product>& products) {
    ofstream fout(this->filename);
    for (auto item : products) {
        fout << item.getId() << "," << item.getName() << "," << (item.getTypeProduct() == ProductType::TEA ? "TEA" : "ACCESSORY") << "\n";
    }
    fout.close();
}
