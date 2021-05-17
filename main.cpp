#include <iostream>
#include "Product.h"
#include "Tests/Tests.h"
#include "Persistence/Persistence.h"
#include "Utils.h"

int main() {
    Persistence p("products.csv");
    vector <Product> produse;
    std::cout<<"Enter 6 products: ";
    int id;
    std::string name, type;
    for(size_t i=0; i<7; i++){
        std::cout<<i<<") id: ";
        std::cin>>id;
        std::cout<<i<<") name: ";
        std::cin>>name;
        std::cout<<i<<") product type: //ACCESORY or TEA ";
        std::cin>>type;
        produse.push_back(Product(id, name, type == "TEA" ? ProductType::TEA : ProductType::ACCESORY));
    }
    p.writeToFile(produse);
    return 0;
}
