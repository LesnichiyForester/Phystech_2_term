#include <iostream>
#include <memory>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(const T& data): data(data), next(nullptr) {}
    };

    std::unique_ptr<Node> head_node;

public:
    void print() const {
        Node* new_node = head_node.get();
        while (new_node != nullptr) {
            std::cout << new_node->data << " ";
            new_node = new_node->next.get();
        }
        std::cout << std::endl;
    }

    void push_front(const T& elem) {
        std::unique_ptr<Node> new_head_node = std::make_unique<Node>(elem);
        new_head_node->next = std::move(head_node);
        head_node = std::move(new_head_node);
    }

    void push_back(const T& elem) {
        Node* new_node = head_node.get();
        if (!new_node) {
            head_node = std::make_unique<Node>(elem);
            return;
        }
        while (new_node->next)
            new_node = new_node->next.get();
        new_node->next = std::make_unique<Node>(elem);
    }

    std::unique_ptr<T> pop_front() {
        if (!head_node)
            return nullptr;
        std::unique_ptr<T> front_value = std::make_unique<T>(std::move(head_node->data));
        head_node = std::move(head_node->next);
        return front_value;
    }

    std::unique_ptr<T> pop_back() {
        if (!head_node)
            return nullptr;
        Node* prev_node = nullptr;
        Node* new_node = head_node.get();
        std::string type = static_cast<std::string>(typeid(new_node->next).name());
        while (new_node->next) {
            prev_node = new_node;
            new_node = new_node->next.get();
        }
        std::unique_ptr<T> back_value = std::make_unique<T>(std::move(new_node->data));
        if (prev_node)
            prev_node->next = nullptr;
        else
            head_node = nullptr;
        return back_value;
    }

    void clear() {
        head_node = nullptr;
    }

    template <typename F>
    void foreach(F f) {
        Node* new_node = head_node.get();
        while (new_node != nullptr) {
            f(new_node->data);
            new_node = new_node->next.get();
        }
    }

    void swap(ForwardList& fl) {
        head_node.swap(fl.head_node);
    }

    ForwardList copy() const {
        ForwardList newList;
        Node* new_node = head_node.get();
        while (new_node != nullptr) {
            newList.push_back(new_node->data);
            new_node = new_node->next.get();
        }
        return newList;
    }
};

int main() {
    ForwardList<std::string> fl;
    fl.push_front("a");
    fl.push_front("b");
    fl.push_front("c");
    fl.push_back("d");
    fl.push_front("e");

    std::cout << "Forward list: ";
    fl.print();

    auto pop = fl.pop_front();
    std::cout << "Popped front element: " << *pop << std::endl;

    pop = fl.pop_back();
    std::cout << "Popped back element: " << *pop << std::endl;

    ForwardList<std::string> fl_copy = fl.copy();
    std::cout << "Copied list: ";
    fl_copy.print();

    fl.foreach([] (std::string& elem) { elem = elem + "f"; });
    std::cout << "Updated list: ";
    fl.print();

    fl.swap(fl_copy);
    std::cout << "Swapped lists: " << std::endl;
    std::cout << "Original list: ";
    fl.print();
    std::cout << "Copied list: ";
    fl_copy.print();

    fl.clear();
    fl_copy.clear();
    std::cout << "Cleared list: ";
    fl.print();
    fl_copy.clear();
}