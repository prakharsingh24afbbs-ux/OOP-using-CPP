#include <iostream>
#include <cstring>
#include <cctype>

class MyString {
private:
    char* str;
    int len;

public:
    MyString() {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* val) {
        if (val == nullptr) {
            len = 0;
            str = new char[1];
            str[0] = '\0';
        } else {
            len = std::strlen(val);
            str = new char[len + 1];
            std::strcpy(str, val);
        }
    }

    MyString(const MyString& source) {
        len = source.len;
        str = new char[len + 1];
        std::strcpy(str, source.str);
    }

    ~MyString() {
        delete[] str;
    }

    int length() const {
        return len;
    }
    // = operator (String copy)
    MyString& operator=(const MyString& rhs) {
        if (this == &rhs) {
            return *this; 
        }

        delete[] str;

        len = rhs.len;
        str = new char[len + 1];
        std::strcpy(str, rhs.str);

        return *this;
    }

    // + operator (Concatenation)
    MyString operator+(const MyString& rhs) const {
        int totalLen = this->len + rhs.len;
        char* tempBuf = new char[totalLen + 1];
        
        std::strcpy(tempBuf, this->str);
        std::strcat(tempBuf, rhs.str);

        MyString tempObj(tempBuf);
        delete[] tempBuf;

        return tempObj;
    }

    // <= operator (Comparison)
    bool operator<=(const MyString& rhs) const {
        return std::strcmp(this->str, rhs.str) <= 0;
    }

    // lowercase letters to uppercase
    void toLower() {
        for (int i = 0; i < len; i++) {
            str[i] = std::tolower(static_cast<unsigned char>(str[i]));
        }
    }

    // uppercase letters to lowercase
    void toUpper() {
        for (int i = 0; i < len; i++) {
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
        }
    }

    // overload stream insertion operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj) {
        os << obj.str;
        return os;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(" World");
    std::cout << "s1: " << s1 << " (Length: " << s1.length() << ")\n";
    std::cout << "s2: " << s2 << " (Length: " << s2.length() << ")\n\n";

    MyString s3 = s1 + s2;
    std::cout << "Concatenated s3 (s1 + s2): " << s3 << "\n\n";

    MyString s4;
    s4 = s1;
    std::cout << "Copied s4 (s4 = s1): " << s4 << "\n\n";

    s3.toUpper();
    std::cout << "s3 in UpperCase: " << s3 << "\n";
    s3.toLower();
    std::cout << "s3 in LowerCase: " << s3 << "\n\n";

    MyString alpha("Apple");
    MyString beta("Banana");
    
    std::cout << "Comparing \"" << alpha << "\" <= \"" << beta << "\": " 
              << (alpha <= beta ? "True" : "False") << "\n";
              
    std::cout << "Comparing \"" << beta << "\" <= \"" << alpha << "\": " 
              << (beta <= alpha ? "True" : "False") << "\n";

    return 0;
}
