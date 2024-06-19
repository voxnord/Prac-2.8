#include <iostream>
#include <Windows.h>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

bool areEqual(Node* head1, Node* head2) 
{
    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 != nullptr && current2 != nullptr) 
    {
        if (current1->data != current2->data) 
        {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Check if both lists are of the same length
    if (current1 == nullptr && current2 == nullptr) 
    {
        return true;
    }

    return false;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Пример использования функции areEqual

    // Создаем первый список: 1 -> 2 -> 3
    Node* head1 = new Node{ 1, nullptr };
    head1->next = new Node{ 2, nullptr };
    head1->next->next = new Node{ 3, nullptr };

    // Создаем второй список: 1 -> 2 -> 3
    Node* head2 = new Node{ 1, nullptr };
    head2->next = new Node{ 2, nullptr };
    head2->next->next = new Node{ 3, nullptr };

    if (areEqual(head1, head2)) 
    {
        cout << "Списки равны." << endl;
    }
    else 
    {
        cout << "Списки не равны." << endl;
    }

    // Освобождаем память
    delete head1->next->next;
    delete head1->next;
    delete head1;

    delete head2->next->next;
    delete head2->next;
    delete head2;

    return 0;
}
