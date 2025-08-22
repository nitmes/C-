#include <fstream>

enum class Format
{
    kText,
    kHTML,
    kJSON
};

class Printable
{
protected:
    std::string data_;

public:
    Printable(std::string data) : data_(std::move(data)) {};
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
    virtual std::string getData() const = 0;
    virtual Format getFormat() const = 0;
};

class TextData : public Printable {
public:
    TextData(std::string data) : Printable(data) {};

    std::string print() const override {
        return data_;
    }
    std::string getData() const override {
        return  data_;
    };
    Format getFormat() const {
        return Format::kText;
    }
};

class HTMLData : public Printable {
public:
    HTMLData(std::string data) : Printable(data) {};

    std::string print() const override {
        return "<html>" + data_ + "<html/>";
    }
    std::string getData() const override {
        return  data_;
    };
    Format getFormat() const {
        return Format::kHTML;
    }
};

class JSONData : public Printable {
public:
    JSONData(std::string data) : Printable(data) {};

    std::string print() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
    std::string getData() const override {
        return  data_;
    };
    Format getFormat() const {
        return Format::kJSON;
    }
};

void saveTo(std::ostream& stream, const Printable& printable) {
    stream << printable.print();
}


void saveToAsHTML(std::ostream& stream, const Printable& printable) {
    HTMLData data_string(printable.getData());
    saveTo(stream, printable);
}

void saveToAsJSON(std::ostream& stream, const Printable& printable) {
    JSONData data_string(printable.getData());
    saveTo(stream, printable);
}

void saveToAsText(std::ostream& stream, const Printable& printable) {
    TextData data_string(printable.getData());
    saveTo(stream, printable);
}
