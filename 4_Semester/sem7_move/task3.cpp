#include <iostream>
#include <string>
#include <vector>

class CategorySeparator {
private:
    std::vector<std::string> str_vec;
    std::vector<bool> ctgry_vec;  // 0 - lvalue, 1 - rvalue

public:
    void push(const std::string& str) {
        str_vec.push_back(str);
        ctgry_vec.push_back(0);
    }

    void push(std::string&& str) {
        str_vec.push_back(std::move(str));
        ctgry_vec.push_back(1);
    }

    void printLvalues() const {
        std::cout << "(";
        if (str_vec.empty()) {
            std::cout << ")" << std::endl;
            return;
        }
        for (int i = 0; i < str_vec.size() - 1; ++i) {
            if (ctgry_vec[i] == 0)
                std::cout << str_vec[i] << ", ";
        }
        std::cout << str_vec[str_vec.size() - 1] << ")" << std::endl;
    }

    void printRvalues() const {
        std::cout << "(";
        if (str_vec.empty()) {
            std::cout << ")" << std::endl;
            return;
        }
        for (int i = 0; i < str_vec.size() - 1; ++i) {
            if (ctgry_vec[i] == 1)
                std::cout << str_vec[i] << ", ";
        }
        std::cout << str_vec[str_vec.size() - 1] << ")" << std::endl;
    }
};

int main() {

    CategorySeparator cs;
    std::string a {"Cat"};
    std::string b {"Dog"};

    cs.push(a);                     // должен скопировать строку a внутрь объекта cs
    cs.push(std::string{"Mouse"});  // должен переместить временную строку внутрь объекта cs
    cs.push(a + b);                 // должен переместить временну строку a + b внутрь объекта cs
    cs.push(b);                     // должен скопировать строку b внутрь объекта cs
    cs.push(std::move(b)); 	        // должен переместить строку b внутрь объекта cs

    std::cout << a << std::endl;    // печатает "Cat"
    std::cout << b << std::endl;    // скорей всего напечатает  пустую строку 
                                // ( зависит от длины строки и компилятора )

    cs.printLvalues();              // печатает  "(Cat, Dog)"
    cs.printRvalues();              // печатает  "(Mouse, CatDog, Dog)"
}