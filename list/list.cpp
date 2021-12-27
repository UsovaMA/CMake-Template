#include "list.h"

Node::Node(DataType d, Node* n) : data(d), next(n) {
}

Node::Node(const Node& node2) {
    data = node2.data;
}

bool Node::operator==(const Node& node2) const {
    return (data == node2.data);
}

List::List() {
    head = nullptr;
}



List::~List() {
    Node* tmp, * tmp1; 
    tmp = head;
    tmp1 = tmp;
    while (tmp1 != nullptr)
    {
        tmp1 = tmp->next;
        delete tmp;
        tmp = tmp1;
    }
}


void List::InsertToHead(const DataType& d)
{
    if (isEmpty())
    {
        head = new Node(d, nullptr); 
    }
    else
    {
        head = new Node(d, head);
    }
}

void List::InsertToTail(const DataType& d)
{
    if (isEmpty())
    {
        head = new Node(d, nullptr); 
    }
    else
    {
        Node* p = new Node(d, nullptr);
        Node* tmp; 
        tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        
        tmp->next = p;
    }
}

void List::DeleteToTail()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        throw std::exception("Error");
    }
    else
    {
        bool b = true;
        Node* tmp1;
        Node* tmp2;
        tmp1 = head;
        tmp2 = tmp1->next;
        if (head->next == nullptr)
        {
            head = head->next;
            delete head;
        }
        else
        {
            while (tmp1->next != nullptr && b==true)
            {
                if (tmp2->next != nullptr)
                {
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                else
                {
                    b = false;
                }
            }
            tmp1->next = nullptr;
        }
    }
}

void List::Clean()
{
    Node* tmp;
    if (isEmpty())
        return;

    while (head->next != nullptr)
    {
        tmp = head->next;
        head->next = tmp->next; // head->next->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

void List::Delete(const DataType& d)
{
    
    Node* prev = head;
    Node* tmp;
    bool find = false;

    
    if (head->data == d)
    {
        head = head->next;
        delete prev; 
        find = true;
    }

    while (!find && (prev->next != nullptr))
    {
        if (prev->next->data == d)
        {
            // prev->next 
            tmp = prev->next;
            prev->next = prev->next->next; // tmp->next
            delete tmp;
            find = true;
        }
        else
            prev = prev->next;
    }
}


List::List(DataType* arr, int size) {
    if (arr != nullptr) {
        head = new Node(arr[0], nullptr);
        Node* tmp = head;                             
        for (int i = 1; i < size; i++) {
            Node* elem = new Node(arr[i], nullptr);      
            tmp->next = elem;                            
            tmp = tmp->next;                             
        }
    }
    else {
        throw std::exception("Empty Input Data!");
    }
}

void List::DeleteHead() {
    if (!isEmpty()) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void List::print(char* direction = "->") {    
    if (!isEmpty()) {
        Node* tmp = head;
        while (tmp->next != nullptr) {
            std::cout << "(" << tmp->data << ")" << direction;                   // (1)->(3)->(2)->
            tmp = tmp->next;                                                     
        }
        std::cout << "(" << tmp->data << ")" << direction;
    }
    std::cout << "NULL" << std::endl;                                        // (1)->(3)->(2)->NULL
}