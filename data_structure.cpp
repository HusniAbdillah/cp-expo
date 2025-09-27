#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void visualizeStack(stack<int> s, string action = "") {
    system("cls");
    cout << "Visualisasi Stack\n\n";
    cout << action << "\n\n";
    
    cout << "Top -> ";
    
    stack<int> temp = s;
    vector<int> elements;
    
    while (!temp.empty()) {
        elements.push_back(temp.top());
        temp.pop();
    }
    
    for (int i = 0; i < elements.size(); i++) {
        if (i == 0)
            cout << "\033[1;32m[" << elements[i] << "]\033[0m\n";
        else
            cout << "       [" << elements[i] << "]\n";
    }
    
    if (s.empty())
        cout << "Stack kosong\n";
        
    cout << "\nOperasi:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Ganti ke Queue\n";
    cout << "5. Keluar\n";
    
    Sleep(500);
}

void visualizeQueue(queue<int> q, string action = "") {
    system("cls");
    cout << "Visualisasi Queue\n\n";
    cout << action << "\n\n";
    
    cout << "Front -> ";
    
    queue<int> temp = q;
    
    if (q.empty())
        cout << "Queue kosong\n";
    else {
        while (!temp.empty()) {
            if (temp.size() == 1)
                cout << "\033[1;32m[" << temp.front() << "]\033[0m <- Rear";
            else
                cout << "[" << temp.front() << "] ";
                
            temp.pop();
        }
    }
    
    cout << "\n\nOperasi:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Front\n";
    cout << "4. Ganti ke Stack\n";
    cout << "5. Keluar\n";
    
    Sleep(500);
}

int main() {
    stack<int> s;
    queue<int> q;
    int choice, val;
    bool isStack = true;
    
    while (true) {
        if (isStack)
            visualizeStack(s);
        else
            visualizeQueue(q);
            
        cin >> choice;
        
        if (isStack) {
            switch (choice) {
                case 1:
                    cout << "Masukkan nilai untuk push: ";
                    cin >> val;
                    s.push(val);
                    visualizeStack(s, "Push " + to_string(val) + " ke stack");
                    break;
                case 2:
                    if (!s.empty()) {
                        val = s.top();
                        s.pop();
                        visualizeStack(s, "Pop " + to_string(val) + " dari stack");
                    } else {
                        visualizeStack(s, "Error: Stack underflow");
                    }
                    break;
                case 3:
                    if (!s.empty()) {
                        val = s.top();
                        visualizeStack(s, "Top element: " + to_string(val));
                    } else {
                        visualizeStack(s, "Error: Stack kosong");
                    }
                    break;
                case 4:
                    isStack = false;
                    break;
                case 5:
                    return 0;
                default:
                    visualizeStack(s, "Pilihan tidak valid");
            }
        } else {
            switch (choice) {
                case 1:
                    cout << "Masukkan nilai untuk enqueue: ";
                    cin >> val;
                    q.push(val);
                    visualizeQueue(q, "Enqueue " + to_string(val) + " ke queue");
                    break;
                case 2:
                    if (!q.empty()) {
                        val = q.front();
                        q.pop();
                        visualizeQueue(q, "Dequeue " + to_string(val) + " dari queue");
                    } else {
                        visualizeQueue(q, "Error: Queue kosong");
                    }
                    break;
                case 3:
                    if (!q.empty()) {
                        val = q.front();
                        visualizeQueue(q, "Front element: " + to_string(val));
                    } else {
                        visualizeQueue(q, "Error: Queue kosong");
                    }
                    break;
                case 4:
                    isStack = true;
                    break;
                case 5:
                    return 0;
                default:
                    visualizeQueue(q, "Pilihan tidak valid");
            }
        }
    }
    
    return 0;
}