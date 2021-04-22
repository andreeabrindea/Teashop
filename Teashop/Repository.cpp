#include "Repository.h"

void Repository::add_new_product(const Product& product)
{
	this->ListOfProducts.push_back(product);
}

void Repository::update_product(const Product& product)
{
	int index;
	vector<Product>::iterator it;
	
	if (it != ListOfProducts.end())
	{
		index = distance(ListOfProducts.begin(), it);
	}
	this->ListOfProducts[index] = product;
}

Product Repository::get_product_by_name(std::string& name)
{
	for (auto i : ListOfProducts)
		if (i.getName() == name)
			return i;
	return Product();
}

void Repository::delete_product_from_repository(const Product& product)
{
	int index;
	vector<Product>::iterator it;

	if (it != ListOfProducts.end())
	{
		index = distance(ListOfProducts.begin(), it);
	}
	this->ListOfProducts.erase(this->ListOfProducts.begin() + index);
}

int Repository::SearchByName(const std::string& name)
{
	int found = 0;
	vector<Product>::iterator it = ListOfProducts.begin() - 1;
	if (it != ListOfProducts.begin() - 1)
		found = 1;
	return found;
}
