#include "Product.h"

Product::Product(std::string name)
{
    this->name = name;
}
Product::Product(const std::string& name)
{
}
std::string Product::getName()
{
    return this->name;
}

bool Product::operator==(const Product& product)
{
   // if (this->name == product.getName())
        return true;
   // else return false;
}

void Product::operator=(const Product& product)
{
    //this->name = product.getName();
}


