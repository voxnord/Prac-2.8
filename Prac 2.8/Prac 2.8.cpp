#include <iostream>
#include <Windows.h>
#include <climits>


using namespace std;

// Структура узла списка
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Класс очереди на основе однонаправленного списка
class Queue {
private:
    Node* front;  // Указатель на начало очереди
    Node* rear;   // Указатель на конец очереди

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Метод добавления элемента в очередь
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Метод удаления элемента из очереди
    void dequeue() {
        if (front == nullptr) {
            cerr << "Очередь пустая" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Метод получения первого элемента очереди
    int peek() const {
        if (front != nullptr) {
            return front->data;
        }
        throw runtime_error("Очередь пустая");
    }

    // Метод проверки, пуста ли очередь
    bool isEmpty() const {
        return front == nullptr;
    }

    // Метод очистки очереди
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Деструктор для очистки памяти
    ~Queue() {
        clear();
    }

    // Метод поиска минимального элемента в очереди
    int findMin() const {
        if (isEmpty()) {
            throw runtime_error("Очередь пустая");
        }
        int min = INT_MAX;
        Node* current = front;
        while (current != nullptr) {
            if (current->data < min) {
                min = current->data;
            }
            current = current->next;
        }
        return min;
    }

    // Метод печати элементов очереди
    void print() const {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Тестирование
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Практика: 10 \n\rВариант 8\r\n\r\n";

    Queue q;

    // Добавление элементов в очередь
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(1);
    q.enqueue(4);

    // Печать элементов очереди
    cout << "Очередь: ";
    q.print();

    // Поиск минимального элемента
    try {
        int minElement = q.findMin();
        cout << "Минимальный элемент очереди: " << minElement << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
