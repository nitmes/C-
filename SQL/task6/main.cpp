#include <iostream>
#include <string>
#include <Wt/Dbo/Dbo.h>
#include <WT/Dbo/Backend/Postgres.h>

class Book;
class Stock;
class Sale;

class Publisher {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Book> > books;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book {
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock> > stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop {
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock> > stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock {
public:
    int count;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale> > sales;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    int price;
    std::string date;
    Wt::Dbo::ptr<Stock> stock;
    int count;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date, "date");
        Wt::Dbo::belongsTo(a, stock, "stock");
        Wt::Dbo::field(a, count, "count");
    }
};


void add_publisher(Wt::Dbo::Session& s, const std::string& name) {
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Publisher> publisher_ptr = s.find<Publisher>().where("name = ?").bind(name);
    if (!publisher_ptr) //если издателя не существует
    {
        std::unique_ptr<Publisher> publisher{ new Publisher() };
        publisher->name = name;
        Wt::Dbo::ptr<Publisher> tmp_ptr = s.add(std::move(publisher));
        transaction.commit();
    }
    else { //если издатель уже есть
        throw std::exception("Publisher already exist. ");
    };
}

void add_book(Wt::Dbo::Session& s, const std::string& title, const std::string& publisher_name) {
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Publisher> publisher_ptr = s.find<Publisher>().where("name = ?").bind(publisher_name);
    if (!publisher_ptr)
    {
        throw std::exception("Publisher not exist. ");
    }
    Wt::Dbo::ptr<Book> book_ptr = s.find<Book>().where("title = ?").bind(title).where("publisher_id = ?").bind(publisher_ptr.id());;
    if (!book_ptr)
    {
        std::unique_ptr<Book> book{ new Book() };
        book->title = title;
        book->publisher = publisher_ptr;
        Wt::Dbo::ptr<Book> tmp_ptr = s.add(std::move(book));
        transaction.commit();
    }
    else {
        throw std::exception("Book already exist. ");
    };
}

void add_shop(Wt::Dbo::Session& s, const std::string& name) {
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Shop> shop_ptr = s.find<Shop>().where("name = ?").bind(name);
    if (!shop_ptr)
    {
        std::unique_ptr<Shop> shop{ new Shop() };
        shop->name = name;
        Wt::Dbo::ptr<Shop> tmp_ptr = s.add(std::move(shop));
        transaction.commit();
    }
    else {
        throw std::exception("Shop already exist. ");
    }
}

void add_stock(Wt::Dbo::Session& s, const std::string& title_book, const std::string& shop_name, const int count) {
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Book> book_ptr = s.find<Book>().where("title = ?").bind(title_book);
    if (!book_ptr) {
        throw std::exception("Book not exist. ");
    }
    Wt::Dbo::ptr<Shop> shop_ptr = s.find<Shop>().where("name = ?").bind(shop_name);
    if (!shop_ptr) {
        throw std::exception("Shop not exist. ");
    }
    Wt::Dbo::ptr<Stock> stock_ptr = s.find<Stock>().where("book_id = ?").bind(book_ptr.id()).where("shop_id = ?").bind(shop_ptr.id());
    if (!stock_ptr)
    {
        std::unique_ptr<Stock> stock{ new Stock() };
        stock->book = book_ptr;
        stock->shop = shop_ptr;
        stock->count = count;
        Wt::Dbo::ptr<Stock> tmp_ptr = s.add(std::move(stock));
        transaction.commit();
    }
    else {
        stock_ptr.modify()->count = stock_ptr->count + count;
    }
}

void make_sale(Wt::Dbo::Session& s, const int price, const std::string& date, const std::string& title_book, const std::string& shop_name, const int count) {
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Book> book_ptr = s.find<Book>().where("title = ?").bind(title_book);
    if (!book_ptr) {
        throw std::exception("Book not exist. ");
    }
    Wt::Dbo::ptr<Shop> shop_ptr = s.find<Shop>().where("name = ?").bind(shop_name);
    if (!shop_ptr) {
        throw std::exception("Shop not exist. ");
    }
    Wt::Dbo::ptr<Stock> stock_ptr = s.find<Stock>().where("book_id = ?").bind(book_ptr.id()).where("shop_id = ?").bind(shop_ptr.id());
    if (stock_ptr->count >= count)
    {
        std::unique_ptr<Sale> sale{ new Sale() };
        sale->stock = stock_ptr;
        sale->price = price;
        sale->date = date;
        sale->count = count;
        Wt::Dbo::ptr<Sale> tmp_ptr = s.add(std::move(sale));
        stock_ptr.modify()->count = stock_ptr->count - count;
        transaction.commit();
    }
    else {
        throw std::exception("No stock book in shop. ");
    }
}

void print_shop(Wt::Dbo::Session& s, const int id_publisher) {
    std::set<std::string> shop;
    std::string publisher_name;
    Wt::Dbo::Transaction transaction{ s };
    Wt::Dbo::ptr<Publisher> publisher_ptr = s.find<Publisher>().where("id = ?").bind(id_publisher);
    if (!publisher_ptr) {
        throw std::exception("Publiusher not exist. ");
    }
    else {
        publisher_name = publisher_ptr->name;
    }
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stock_col_ptr = s.find<Stock>();
    for (auto scp : stock_col_ptr) {
        if (scp->book->publisher.id() == id_publisher && scp->count > 0) {
            shop.insert(scp->shop->name);
        }
    }
    std::cout << "Book publisher \"" << publisher_name << "\" are available in shop: " << std::endl;
    for (auto s : shop) {
        std::cout << s << std::endl;
    }
}

int main()
{
    try
    {
        auto connection = std::make_unique < Wt::Dbo::backend::Postgres>(
            "host=localhost port=5432 dbname=postgres user=postgres password="
        );
        Wt::Dbo::Session sess;
        sess.setConnection(std::move(connection));
        sess.mapClass<Publisher>("publisher");
        sess.mapClass<Book>("book");
        sess.mapClass<Shop>("shop");
        sess.mapClass<Stock>("stock");
        sess.mapClass<Sale>("sale");
        //Создаём таблицы
        try
        {
            sess.createTables();
        }
        catch (const std::exception& e) {
            std::cout << "Exeption create table: " << e.what() << std::endl;
        }
        //publisher
        try
        {
            add_publisher(sess, "Slovo");
            add_publisher(sess, "Booker");
            add_publisher(sess, "BestB");
        }
        catch (const std::exception& e) {
            std::cout << "Exeption publisher: " << e.what() << std::endl;
        };
        //books
        try
        {
            add_book(sess, "Pemelev | Dust", "Slovo");
            add_book(sess, "Robolev | Robots live", "Booker");
            add_book(sess, "Markes | Lychie dryzua", "BestB");
            add_book(sess, "Morgan | Red dead", "Booker");
            add_book(sess, "Red | Cyberpunk", "Booker");
        }
        catch (const std::exception& e) {
            std::cout << "Exeption book: " << e.what() << std::endl;
        }
        //shops
        try
        {
            add_shop(sess, "Global knigi");
            add_shop(sess, "Slovoed");
            add_shop(sess, "Books");
        }
        catch (const std::exception& e) {
            std::cout << "Exeption shop: " << e.what() << std::endl;
        }
        //books to shops
        try
        {
            add_stock(sess, "Pemelev | Dust", "Global knigi",3);
            add_stock(sess, "Robolev | Robots live", "Slovoed",1);
            add_stock(sess, "Markes | Lychie dryzua", "Gloval knigi",1);
            add_stock(sess, "Morgan | Red dead", "Slovoed",4);
            add_stock(sess, "Morgan | Red dead", "Books", 2);
            add_stock(sess, "Morgan | Red dead", "Global knigi", 5);
            add_stock(sess, "Red | Cyberpunk", "Books",3);
            add_stock(sess, "Red | Cyberpunk", "Slovoed", 3);
        }
        catch (const std::exception& e) {
            std::cout << "Exeption stock: " << e.what() << std::endl;
        }
        //make some money
        try
        {
            make_sale(sess, 299, "2023-03-01", "Morgan | Red dead", "Slovoed", 1);
            make_sale(sess, 749, "2023-05-24", "Red | Cyberpunk", "Books", 1);
            make_sale(sess, 1749, "2023-05-25", "Pemelev | Dust", "Global knigi", 1);
        }
        catch (const std::exception& e) {
            std::cout << "Exeption sales: " << e.what() << std::endl;
        }
        //Shoops that sales this publisher
        int input;
        do {
            std::cout << "Insert id publisher (or 0 for exit): ";
            std::cin >> input;
            if (input > 0) {
                print_shop(sess, input);
            }
        } while (input != 0);
    }
    catch (const std::exception& e) {
        std::cout << "Exeption: " << e.what() << std::endl;
    }
}