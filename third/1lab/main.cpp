#include <iostream>
#include <string>

using namespace std;

class Product
{
    string name;
    string producer;
    double price;
    int storage_time;
    int quantity;

public:
    Product(string name = "Sample Product", string producer = "Sample Producer", double price = 0.0, int storage_time = 0, int quantity = 0)
        : name(name), producer(producer), price(price), storage_time(storage_time), quantity(quantity) {}

    void show() const
    {
        cout << "> " << name << " by " << producer << ", Price: $" << price << "\n- Storage Time: " << storage_time << " days, Quantity: " << quantity << "\n\n";
    }

    Product &update_product_name(string new_name)
    {
        if (new_name.empty())
            return *this;

        name = new_name;
        return *this;
    }

    Product &update_product_producer(string new_producer)
    {
        if (new_producer.empty())
            return *this;

        producer = new_producer;
        return *this;
    }

    Product &update_product_price(double new_price)
    {
        if (new_price <= 0)
            return *this;

        price = new_price;
        return *this;
    }

    Product &update_product_storage_time(int new_storage_time)
    {
        if (new_storage_time <= 0)
            return *this;

        storage_time = new_storage_time;
        return *this;
    }

    Product &update_product_quantity(int new_quantity)
    {
        if (new_quantity < 0)
            return *this;

        quantity = new_quantity;
        return *this;
    }

    bool is_name_equal(string other_name) const
    {
        return name == other_name;
    }

    bool is_price_fit(double other_price) const
    {
        return price <= other_price;
    }

    bool is_storage_time_fit(int other_storage_time) const
    {
        return storage_time > other_storage_time;
    }
};

class Stock
{
    string company_name;
    int stock_count;
    double stock_price;
    double all_stock_price;

    double set_tot()
    {
        all_stock_price = stock_count * stock_price;
        return all_stock_price;
    }

public:
    Stock(string name = "Sample Company", int count = 0, double price = 0.0)
    {
        cout << "Constructor called for " << name << "\n";
        company_name = name;
        stock_count = count;
        stock_price = price;
        set_tot();
    }
    Stock &acquire(string name, int count, double price)
    {
        company_name = name;
        stock_count = count;
        stock_price = price;
        set_tot();
        return *this;
    }

    double buy(int count)
    {
        if (count <= 0)
            return 0;

        stock_count += count;
        set_tot();
        return count * stock_price;
    }

    double sell(int count)
    {
        if (stock_count <= 0 || count <= 0 || count > stock_count)
            return 0;

        stock_count -= count;
        set_tot();
        return count * stock_price;
    }

    double update(double newPrice)
    {
        if (newPrice <= 0)
            return all_stock_price;

        stock_price = newPrice;
        set_tot();
        return all_stock_price;
    }

    void show() const
    {
        cout << "> Company Name: " << company_name << "\n";
        cout << "- Stock Count: " << stock_count << "\n";
        cout << "- Stock Price: " << stock_price << "\n";
        cout << "- All Stock Price: " << all_stock_price << "\n\n";
    }

    ~Stock()
    {

        cout << "Destructor called for " << company_name << "\n";
    }
};

void full_stock_show(Stock *stock, int stock_count)
{
    for (int i = 0; i < stock_count; ++i)
    {
        stock[i].show();
    }
    cout << "-----\n";
}

void test_stock()
{
    const int stock_count = 5;
    Stock stock[stock_count] = {
        Stock("Company A", 100, 10.5),
        Stock("Company B", 200, 20.0),
        Stock("Company C", 300, 15.0),
        Stock("Company D", 250, 14.0),
        Stock("Company E", 150, 13.0)};

    cout << "\nInitial Stock Information:\n";
    full_stock_show(stock, stock_count);

    cout << "\nBuy test:\n";
    cout << "Try buying -1 stocks of Company A: $" << stock[0].buy(-1) << "\n";
    cout << "Buying 100 stocks of Company B: $" << stock[1].buy(100) << "\n";
    cout << "Buying 200 stocks of Company C: $" << stock[2].buy(200) << "\n";

    cout << "\nShow buy test results:\n";
    full_stock_show(stock, stock_count);

    cout << "\nSell test:\n";
    cout << "Selling 30 stocks of Company A: $" << stock[0].sell(30) << "\n";
    cout << "Try selling -1 stocks of Company B: $" << stock[1].sell(-1) << "\n";
    cout << "Selling 351 stocks of Company C: $" << stock[2].sell(351) << "\n";
    cout << "\n";

    cout << "Show sell test results:\n";
    full_stock_show(stock, stock_count);

    cout << "\nUpdate test:\n";
    cout << "Updating stock price of Company A to $12.0: New total value = $" << stock[0].update(12.0) << "\n";
    cout << "Updating stock price of Company B to $22.5: New total value = $" << stock[1].update(22.5) << "\n";
    cout << "Updating stock price of Company C to $18.0: New total value = $" << stock[2].update(18.0) << "\n";

    cout << "\nShow update test results:\n";
    full_stock_show(stock, stock_count);
}

void product_list_show(Product *products, int product_count, string filter_name = "", double price_limit = -1, int storage_time_limit = -1)
{
    for (int i = 0; i < product_count; ++i)
    {
        if (!filter_name.empty() && !products[i].is_name_equal(filter_name) || price_limit > 0 && !products[i].is_price_fit(price_limit) || storage_time_limit >= 0 && !products[i].is_storage_time_fit(storage_time_limit))
        {
            continue;
        }

        products[i].show();
    }
    cout << "-----\n";
}

void test_product()
{
    const int product_count = 5;
    Product products[product_count] = {
        Product("Product A", "Producer A", 10.5, 30, 100),
        Product("Product B", "Producer B", 20.0, 60, 200),
        Product("Product A", "Producer C", 15.0, 90, 300),
        Product("Product B", "Producer D", 14.0, 120, 250),
        Product("Product A", "Producer E", 13.0, 150, 150)};

    cout << "\nInitial Product Information:\n";
    product_list_show(products, product_count);

    cout << "\nUpdate test:\n";
    products[0].update_product_price(12.0).update_product_quantity(120);
    cout << "Updated Product A (index 0) price to $12.0 and quantity to 120.\n";
    products[1].update_product_name("Product C").update_product_producer("Producer C");
    cout << "Updated Product B (index 1) name to 'Product C' and producer to 'Producer C'.\n";
    products[2].update_product_storage_time(100);
    cout << "Updated Product A (index 2) storage time to 100 days.\n";

    cout << "\nShow update test results:\n";
    product_list_show(products, product_count);

    cout << "\nFilter test:\n";
    string name_filter = "Product A";
    double price_limit = 13.0;
    int storage_time_limit = 100;

    cout << "\nProducts with name '" << name_filter << "':\n";
    product_list_show(products, product_count, name_filter);

    cout << "\nProducts with name '" << name_filter << "' and price less than or equal to $" << price_limit << ":\n";
    product_list_show(products, product_count, name_filter, price_limit);

    cout << "\nProducts with fitting storage time limit (" << storage_time_limit << "):\n";
    product_list_show(products, product_count, "", -1, storage_time_limit);
}

int main()
{
    // test_stock();
    test_product();
    return 0;
}