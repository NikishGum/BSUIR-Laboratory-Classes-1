#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "nikish_func.h"

using namespace std;

class Product {
public:
	int product_id;
	char product_name[20];
	char product_upc[12];
	char product_mfr[20];
	double product_price;
	unsigned int shelf_life;
	int product_quantity;

	Product() {
		product_id = 0;
		memset(product_name, 0, sizeof(product_name));
		memset(product_upc, 0, sizeof(product_upc));
		memset(product_mfr, 0, sizeof(product_mfr));
		product_price = 0.0;
		shelf_life = 0;
		product_quantity = 0;
	}
};

class Storage {
private:
	Product* products;
	char selected_name[20];
	unsigned int objNum;
	unsigned int selected_days;
	double selected_price;
	bool found;
	

public:
	Storage(int size) {
		products = new Product[size]();
		memset(selected_name, 0, sizeof(selected_name));
		objNum = size;
		selected_days = 0;
		selected_price = 0.0;
		found = false;
	}
	
	void solution(int objNum) {
		fillInfo();
		cout << "Given information:\n" << endl;
		peekData();

		cout << "\n\nOutput by name\n";
		cout << "\nEnter name: ";
		custom::getline(selected_name, 20);
		ouputName(selected_name);

		cout << "\n\nOutput by name and price(<= selected price)\n";
		cout << "\nEnter name: ";
		custom::getline(selected_name, 20);
		cout << "\nEnter price: ";
		selected_price = custom::get_double();
		outputNameByPrice(selected_name, selected_price);

		cout << "\n\nOutput by shelflife (>= selected selflife)\n";
		cout << "\nEnter number of days (shelflife): " << endl;
		selected_days = custom::get_int();
		outputByShelfLife(selected_days);

	}

	void objOutput(Product* prod) {
		const char separator = ' ';

		cout << prod->product_id << "\t";
		cout << left << setw(20) << setfill(separator) << prod->product_name;
		cout << left << setw(15) << setfill(separator) << prod->product_upc;
		cout << left << setw(20) << setfill(separator) << prod->product_mfr;
		cout << left << setw(15) << setfill(separator) << setprecision(3) << prod->product_price;
		cout << left << setw(25) << setfill(separator) << prod->shelf_life;
		cout << left << setw(8) << setfill(separator) << prod->product_quantity << endl;
	}

	void peekData() {
		/*Table-like output*/
		cout << "\n\nID\t";
		cout << left << setw(20) << setfill(' ') << "Product name";
		cout << left << setw(15) << setfill(' ') << "UPC";
		cout << left << setw(20) << setfill(' ') << "Manufacturer";
		cout << left << setw(15) << setfill(' ') << "Price";
		cout << left << setw(25) << setfill(' ') << "Shelflife (days)";
		cout << left << setw(8) << setfill(' ') << "Quantity" << endl << endl;
		/*---------------*/
		for (int i = 0; i < objNum; ++i) {
			objOutput(products + i);
		}
	}

	void fillInfo() {
		for (int i = 0; i < objNum; ++i) {
			cout << "\nObject number " << i << endl;
			products[i].product_id = i;

			cout << "\nProduct name:\n>>";
			while (custom::getline(products[i].product_name, 20) < 0 || products[i].product_name[0] == '\0') {
				cin.clear();
				cin.ignore(1000, '\n');
			}

			cout << "\nUPC\n>>";
			while (custom::getline(products[i].product_upc, 12) < 0 || products[i].product_upc[0] == '\0') {
				cin.clear();
				cin.ignore(1000, '\n');
			}

			cout << "\nManufacturer\n>>";
			while (custom::getline(products[i].product_mfr, 20) < 0 || products[i].product_mfr[0] == '\0') {
				cin.clear();
				cin.ignore(1000, '\n');
			}

			cout << "\nPrice\n>>";
			products[i].product_price = custom::get_double();

			cout << "\nShelf life (days)\n>>";
			products[i].shelf_life = custom::get_int();

			cout << "\nQuantity\n>>";
			products[i].product_quantity = custom::get_int();
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	void ouputName(char* selected_name) {
		cout << "\nFound items:\n" << endl;
		/*Table-like output*/
		cout << "\n\nID\t";
		cout << left << setw(20) << setfill(' ') << "Product name";
		cout << left << setw(15) << setfill(' ') << "UPC";
		cout << left << setw(20) << setfill(' ') << "Manufacturer";
		cout << left << setw(15) << setfill(' ') << "Price";
		cout << left << setw(25) << setfill(' ') << "Shelflife (days)";
		cout << left << setw(8) << setfill(' ') << "Quantity" << endl << endl;
		/*---------------*/
		for (int i = 0; i < objNum; ++i) {
			if (strcmp(products[i].product_name, selected_name) == 0) {
				objOutput(products + i);
				found = true;
			}
		}
		if (!found) cout << "\nNo objects found.\n";
		found = false;
	}

	void outputNameByPrice(char* selected_name, double selected_price) {
		cout << "\nFound items:\n" << endl;
		/*Table-like output*/
		cout << "\n\nID\t";
		cout << left << setw(20) << setfill(' ') << "Product name";
		cout << left << setw(15) << setfill(' ') << "UPC";
		cout << left << setw(20) << setfill(' ') << "Manufacturer";
		cout << left << setw(15) << setfill(' ') << "Price";
		cout << left << setw(25) << setfill(' ') << "Shelflife (days)";
		cout << left << setw(8) << setfill(' ') << "Quantity" << endl << endl;
		/*---------------*/
		for (int i = 0; i < objNum; ++i) {
			if (strcmp(products[i].product_name, selected_name) == 0 && products[i].product_price <= selected_price) {
				objOutput(products + i);
				found = true;
			}
		}

		if (!found) cout << "\nNo objects found.\n";
		found = false;
	}

	void outputByShelfLife(unsigned int days) {
		cout << "\nFound items:\n" << endl;
		/*Table-like output*/
		cout << "\n\nID\t";
		cout << left << setw(20) << setfill(' ') << "Product name";
		cout << left << setw(15) << setfill(' ') << "UPC";
		cout << left << setw(20) << setfill(' ') << "Manufacturer";
		cout << left << setw(15) << setfill(' ') << "Price";
		cout << left << setw(25) << setfill(' ') << "Shelflife (days)";
		cout << left << setw(8) << setfill(' ') << "Quantity" << endl << endl;
		/*---------------*/
		for (int i = 0; i < objNum; ++i) {
			if (products[i].shelf_life >= days) {
				objOutput(products + i);
				found = true;
			}
		}
		if (!found) cout << "\nNo objects found.\n";
		found = false;
	}

	~Storage() {
		delete[] products;
	}

};


int main() {
	int numObj;	
	while ((numObj = custom::get_int()) <= 0);
	Storage storage(numObj);
	storage.solution(numObj);
	return 0;
}