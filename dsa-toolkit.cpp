#include <iostream>
using namespace std;

#define MAX 100

// ---------------- STACK ----------------
class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << "Pushed successfully!\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- QUEUE ----------------
class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Enqueued successfully!\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- LINKED LIST ----------------
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void displayList() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ---------------- SORTING ----------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ---------------- SEARCHING ----------------
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// ---------------- MAIN ----------------
int main() {
    Stack s;
    Queue q;

    int choice, x, n, key, arr[100];

    while (true) {
        cout << "\n===== DSA TOOLKIT =====\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "3. Linked List Operations\n";
        cout << "4. Sorting\n";
        cout << "5. Searching\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "1.Push  2.Pop  3.Display\n";
            cin >> x;
            if (x == 1) { cin >> n; s.push(n); }
            else if (x == 2) s.pop();
            else s.display();
            break;

        case 2:
            cout << "1.Enqueue  2.Dequeue  3.Display\n";
            cin >> x;
            if (x == 1) { cin >> n; q.enqueue(n); }
            else if (x == 2) q.dequeue();
            else q.display();
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> n;
            insertEnd(n);
            displayList();
            break;

        case 4:
            cout << "Enter size: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            bubbleSort(arr, n);
            cout << "Sorted: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;

        case 5:
            cout << "Enter size: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
            cout << "Enter key: ";
            cin >> key;
            x = linearSearch(arr, n, key);
            if (x == -1) cout << "Not Found!\n";
            else cout << "Found at index: " << x << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}
