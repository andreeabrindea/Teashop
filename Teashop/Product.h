#pragma once
#include <string>
#include <string.h>

class Product
{private:
	std::string name;
	enum type {tea, accesory};
public:
	Product(std::string name = "");
	Product(const std::string& name);
	std::string getName();
	bool operator==(const Product& product);
	
	void operator=(const Product& product);

	std::string TransformToString() const {
		//return std::string(name) + " "+ type;
	}
	
};

