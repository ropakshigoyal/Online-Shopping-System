#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store product information
class Product
{
private:
    string category;
    string model;
    double price;

public:
    Product(string category, string model, double price)
    {
        this->category = category;
        this->model = model;
        this->price = price;
    }

    string getCategory() const
    {
        return category;
    }

    string getModel() const
    {
        return model;
    }

    double getPrice() const
    {
        return price;
    }
};

// Arrays to store product data
vector<Product> mobileProducts;
vector<Product> laptopProducts;
vector<Product> courseProducts;

// Function to initialize product data
void fillItems()
{
    mobileProducts.push_back(Product("Mobile", "Samsung", 15000));
    mobileProducts.push_back(Product("Mobile", "Redmi", 12000));
    mobileProducts.push_back(Product("Mobile", "Apple", 100000));

    laptopProducts.push_back(Product("Laptop", "HP", 40000));
    laptopProducts.push_back(Product("Laptop", "Lenovo", 35000));
    laptopProducts.push_back(Product("Laptop", "Macbook", 250000));

    courseProducts.push_back(Product("Course", "C", 1000));
    courseProducts.push_back(Product("Course", "C++", 3000));
    courseProducts.push_back(Product("Course", "Java", 4000));
    courseProducts.push_back(Product("Course", "Python", 3500));
}

// Function to convert string to uppercase

// Class customer to represent a customer
class Customer
{
    vector<Product> selectedItems;
    string name;

public:
    Customer()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "HI " << name << "\n\n\n";
    }

    void addToCart(Product &product)
    {
        selectedItems.push_back(product);
    }

    void printBill()
    {
        double totalAmount = 0;
        cout << "Category\tItem\tQuantity\tCost\n";
        for (Product &product : selectedItems) // For each loop
        {
            cout << product.getCategory() << "\t\t" << product.getModel() << "\t1\t\t" << product.getPrice() << endl;
            totalAmount += product.getPrice();
        }
        cout << "-------------------------------\n";
        cout << "Total amount:\t\t" << totalAmount << endl;
        cout << "-------------------------------\n";
        cout << "*****THANK YOU && HAPPY ONLINE SHOPPING*****";
    }
};

// Class shop to represent a shop
class Shop
{
public:
    virtual void show() {}
    virtual void select(Customer &obj) {}
};

// Class mobile inheriting properties from class shop
class Mobile : public Shop
{
public:
    void show() override
    {
        cout << "- - - - - - - - - - - - -\nItem\tCost\n";
        int count = 1;
        for (Product &product : mobileProducts) // For each loop
        {
            cout << count++ << ". " << product.getModel() << " --- Rs." << product.getPrice() << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(Customer &obj) override
    {
        cout << "These are the smartphone categories we have...\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > mobileProducts.size())
        {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! " << mobileProducts[num - 1].getModel() << " IS ADDED TO THE CART\n\n";
        obj.addToCart(mobileProducts[num - 1]);
    }
};

// Class laptop inheriting properties from class shop
class Laptop : public Shop
{
public:
    void show() override
    {
        cout << "- - - - - - - - - - - - -\nItem\tCost\n";
        int count = 1;
        for (Product &product : laptopProducts)
        {
            cout << count++ << ". " << product.getModel() << " --- Rs." << product.getPrice() << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }

    void select(Customer &obj) override
    {
        cout << "These are the laptop categories we have...\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > laptopProducts.size())
        {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! " << laptopProducts[num - 1].getModel() << " IS ADDED TO THE CART\n\n";
        obj.addToCart(laptopProducts[num - 1]);
    }
};

// Class courses inheriting properties from class shop
class Courses : public Shop
{
public:
    void show() override
    {
        cout << "- - - - - - - - - - - - -\nItem\tCost\n";
        int count = 1;
        for (Product &product : courseProducts) // For each loop
        {
            cout << count++ << ". " << product.getModel() << " --- Rs." << product.getPrice() << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }

    void select(Customer &obj) override
    {
        cout << "These are the courses categories we have...\n";
        int num;
        cout << "Enter your selection: ";
        cin >> num;
        if (num < 1 || num > courseProducts.size())
        {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! " << courseProducts[num - 1].getModel() << " IS ADDED TO THE CART\n\n";
        obj.addToCart(courseProducts[num - 1]);
    }
};

int main()
{
    fillItems();
    cout << "WELCOME TO OUR SHOP. WE ARE DELIGHTED THAT YOU ARE HERE. HOW CAN WE HELP YOU? WE DEAL IN ELECTRONIC GADGETS AND COURSES.\n";
    Customer c;
    Shop *s = nullptr;

    while (true)
    {
        cout << "Menu\n";
        cout << "-----------------------------------------\n";
        cout << "1. Mobile\n2. Laptop\n3. Programming Courses\n4. Checkout\n\n";
        cout << "-----------------------------------------\n";

        cout << "Please select an option to proceed further. If you choose to checkout, shopping will end, and a bill will be generated for the items bought so far...\n";
        int val;
        cin >> val;

        if (val == 1)
        {
            Mobile mobileShop;
            s = &mobileShop;
            s->show();
            s->select(c);
        }
        else if (val == 2)
        {
            Laptop laptopShop;
            s = &laptopShop;
            s->show();
            s->select(c);
        }
        else if (val == 3)
        {
            Courses coursesShop;
            s = &coursesShop;
            s->show();
            s->select(c);
        }
        else if (val == 4)
        {
            c.printBill();
            break;
        }
        else
        {
            cout << "Wrong Input. If you want to checkout, you can press 4\n\n";
        }
    }
}
