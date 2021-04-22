#pragma once
#include "Product.h"
#include <vector>
#include <fstream> 

using std::vector;
using std::ofstream;
using std::ifstream;
using std::string;

class Repository
{
private:
	vector <Product> ListOfProducts;
public:
	Repository() {}


	void add_new_product(const Product& product);
	void update_product(const Product& product);
	Product get_product_by_name(std::string& name);
	vector <Product> getListOfProducts() const {return ListOfProducts;}
	void delete_product_from_repository(const Product& product);

	int SearchByName(const std::string& name);
};


