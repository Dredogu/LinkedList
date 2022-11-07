#include <iostream>

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node<T> *next;
public:
    Node(T data){
        this->data = data;
        this->next = nullptr;
    }
};

template<class T>
class LinkedList{
private:
    Node<T> *first = nullptr;
public:
    void Append(T data){
        Node<T> *node = new Node<T>(data);
        node->next = nullptr;

        if(first == nullptr){
            first = node;
        }
        else{
            Node<T> *last = first;
            while(last->next){
                last = last->next;
            }
            last->next = node;
        }
    }

    void InsertFirst(T data){
        Node<T> *node = new Node<T>(data);
        node->next = nullptr;

        if(first == nullptr){
            first = node;
        }
        else{
            node->next = first;
            first = node;
        }
    }

    void Insert(int pos, T data){
        if(pos < 1){
            return;
        }
        else if(pos == 1){
            this->InsertFirst(data);
        }
        else{
            Node<T> *node = new Node<T>(data);
            node->next = nullptr;
            Node<T> *p = first;

            for(int i = 1; i < pos-1 && p->next; i++){
                p = p->next;
            }

            node->next = p->next;
            p->next = node;
        }
    }

    T DeleteFirst(){
        T temp;
        if(first){
            Node<T> *node = first;
            temp = node->data;
            first = first->next;
            delete node;
        }

        return temp;
    }

    T Delete(int pos){
        T temp;
        if(pos == 1){
            temp = this->DeleteFirst();
        }
        else{
            Node<T> *prev = first;
            Node<T> *curr = first;
            for(int i = 1; i < pos && curr->next; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            temp = curr->data;
            delete curr;
        }

        return temp;
    }

    void Print(){
        Node<T> *p = first;
        while(p){
            cout << p->data << endl;
            p = p->next;
        }
    }

    ~LinkedList(){
        Node<T> *current = first;
        Node<T> *p;
        while(current){
            p = current->next;
            delete current;
            current = p;
        }
        first = nullptr;
        this->Print();
    }
};


int main(){

    LinkedList<string> list;
    
    list.Append("Dre");
    list.Append("Memo");
    list.Append("Musti");
    list.Append("Atakan");

    list.InsertFirst("Nihat");

    list.Insert(2, "Asim");
    list.Insert(1, "Feride");
    //list.DeleteFirst();
    cout << "Delete: " << list.Delete(2) << endl;

    list.Print();

    return 0;
}