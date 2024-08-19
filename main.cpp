#include "reverse_iterator_for_sll.h"

int main() {
    List obj;
    obj.push_back(9);
    obj.push_back(8);
    obj.push_back(7);

    std::cout << "Forward traversal: ";
    obj.print();

    std::cout << "Reverse traversal: ";
    for (List::reverse_iterator it = obj.rbegin(); it != obj.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    List::reverse_iterator it = obj.rbegin();
    

    return 0;
}

