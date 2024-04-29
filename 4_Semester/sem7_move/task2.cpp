#include <iostream>
#include <string>
#include <vector>

class StringStack {
private:
    std::vector<std::string> str_vec;

public:
    void push(const std::string& str) {
        str_vec.push_back(str);
    }

    void push(std::string&& str) {
        str_vec.push_back(std::move(str));
    }

    void print() const {
        std::cout << "(";
        if (str_vec.empty()) {
            std::cout << ")" << std::endl;
            return;
        }
        for (int i = 0; i < str_vec.size() - 1; ++i)
            std::cout << str_vec[i] << ", ";
        std::cout << str_vec[str_vec.size() - 1] << ")" << std::endl;
    }

    std::string pop() {
        if (str_vec.empty())
            return "";
        std::string top = std::move(str_vec.back());
        str_vec.pop_back();
        return top;
    }
};

int main() {

    StringStack ss;
    std::string a {"Cat"};

    ss.push(a);                    // должен скопировать строку a внутрь объекта ss
    ss.push(std::string{"Mouse"}); // должен переместить временную строку внутрь объекта ss
    ss.print();                    // печатает  (Cat, Mouse)
    std::cout << a << std::endl;             // печатает  Cat

    ss.push(std::move(a));         // должен переместить строку a внутрь объекта ss
    ss.print();                    // печатает  (Cat, Mouse, Cat)
    std::cout << a << std::endl;             // скорее всего напечатает  пустую строку 
                               // ( зависит от длины строки и компилятора )

    std::cout << ss.pop() << std::endl;       // печатает  Cat
    ss.print();                    // печатает  (Cat, Mouse)
    std::cout << ss.pop() << std::endl;       // печатает  Mouse
    std::cout << ss.pop() << std::endl;       // печатает  Cat
    ss.print();                    // печатает  ()
}