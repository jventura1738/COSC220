#include <iostream>

template <class T>
class List {
private:
    typedef struct Node{
        T data;
        Node* next;
    }*nodeptr;
    nodeptr head, tail; // pointers to front and rear
    int listcount;
    void remove_tail() {
        nodeptr prev = head;
        while (prev->next->next != nullptr) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        prev->next = nullptr;
    }
    void remove_head() {
        nodeptr temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
public:
    List() {
        listcount = 0;
        head = nullptr;
        tail = nullptr;
    }
    List(const List& list) {
        listcount = 0;
        head = nullptr;
        tail = nullptr;
        if (list.list_count() == 0) {
            return;
        } else {
            int temp;
            nodeptr cursor = list.head;
            for (int i = 1; i <= list.list_count(); i++) {
                temp = cursor->data;
                append(temp);
                cursor = cursor->next;
            }
            cursor = nullptr;
        }
    }
    ~List() {
        while (listcount >= 1) {
            remove_at(listcount);
        }
        head = nullptr;
        tail = nullptr;
    }
    void prepend(T val) {
        nodeptr temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
        listcount++;
    }
    void append(T val) {
        nodeptr temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            tail->next = temp;
            tail = temp;
        }
        listcount++;
    }
    void remove_at(int pos) {
        if (pos <= 0) {
            std::cerr << "Error: not valid position.\n";
        }
        else if (head == nullptr) {
            std::cerr << "\nList is empty.\n";
            return;
        }
        else if (pos == 1) {
            listcount--;
            remove_head();
            return;
        }
        else if (pos == listcount) {
            listcount--;
            remove_tail();
            return;
        }
        else {
            listcount--;
            nodeptr curr = head;
            nodeptr prev = head;
            nodeptr temp;
            for (int i = 1; i < pos; i++) {
                if (i + 1 == pos)
                {
                    prev = curr;
                }
                curr = curr->next;
            }
            temp = curr;
            curr = curr->next;
            delete temp;
            prev->next = curr;
        }
    }
    void print_list() const {
        nodeptr temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
    int list_count() const {
        return listcount;
    }
};

int main() {

    List<int>linkedlist;
    int count;

    for (int i = 1; i <= 10; i++) {
        linkedlist.append(i);
    }

    linkedlist.remove_at(1);
    linkedlist.remove_at(3);
    linkedlist.remove_at(7);

    linkedlist.print_list();
    count = linkedlist.list_count();
    std::cout << "List size: " << count << "\n";

    List<int>linkedlist2(linkedlist);
    linkedlist2.print_list();
    return 0;
}
