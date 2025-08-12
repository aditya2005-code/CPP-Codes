#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }


    bool operator<(const Student& other) const {
        return marks < other.marks;  
    }
};

int main() {
    priority_queue<Student> pq;

    Student s1("Alice", 85);
    Student s2("Bob", 92);
    Student s3("Charlie", 78);

    pq.push(s1);
    pq.push(s2);
    pq.push(s3);

    while (!pq.empty()) {
        cout << pq.top().name << " -> " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
