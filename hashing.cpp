

#include <iostream>
#define SIZE 20

using namespace std;

class Node {
        string name;
        string telno;
        Node* next;
    public:
        Node() {
            name = "";
            telno = "";
            next = NULL;
        }

        friend class SeparateChaining;
};

class SeparateChaining {
        Node* head[SIZE];
        int tsize;
    public:
        SeparateChaining(int size) {
            tsize = size;
            for(int i = 0; i < tsize; i++)
                head[i] = nullptr;
        }
        
       
        void insert(string name, string tel);
        void display();
        void search(string name);
        int hashf(string name);
};


void SeparateChaining::insert(string name, string tel) {
    int index = hashf(name);
    cout << endl << "Index: " << index << endl;
    Node* p = new Node();   
    p -> name = name;
    p -> telno = tel;
    if(head[index] == nullptr) {
        head[index] = p;
        cout << "Record inserted" << endl;
    }
    else {
        p -> next = head[index];
        head[index] = p;
        cout << endl << "Record inserted";
    }
}

void SeparateChaining::display() {
    for(int i = 0; i < tsize; i++) {
        if(head[i] == nullptr)
            cout << endl
                 << i << "\tNULL";
        else {
            Node* temp;
            temp = head[i];
            cout << endl << i;
            while(temp != nullptr) {
                cout << "\t" << temp -> name << "," << temp -> telno;
                temp = temp -> next;
            }
        }
    }
}

void SeparateChaining::search(string name) {
    int index = hashf(name);
    Node* temp = head[index];

   
    while(temp != nullptr) {
        if(temp -> name == name) {
            cout << temp -> name << "," << temp -> telno << " found at index " << index;
            return;
        }
        temp = temp -> next;
    }
    
    if (temp == nullptr) { 
                            
        cout << name << " does not exist ";
    }
}

int SeparateChaining::hashf(string name) {
    int index, asciisum = 0;
    for(int i = 0; i < name.length(); i++)
        asciisum += name[i];
    

    index = asciisum % tsize;
    return index;
}

int main() {
    int size;
    string name;
    string tel;
    int ch;
    cout << "Enter Hash Table Size:" << endl;
    cin >> size;
    SeparateChaining obj(size);
    do
    {
        cout << endl << "---------------";
        cout << endl << "1. Insert"
             << endl << "2. Display"
             << endl << "3. Search"
             << endl << "4. Exit";
        
        cout << endl <<"Enter choice: ";
        cin >> ch;
        cout << endl << "---------------" << endl;
        
        switch (ch) {
            case 1:
                cout << "Enter Client's Name:" << endl;
                cin >> name;
                cout << "Enter Telephone no.:" << endl;
                cin >> tel;
                obj.insert(name, tel);
                break;
            case 2:
                obj.display();
                break;
            case 3:
                cout << endl << "Enter Client's name to be searched: ";
                cin >> name;
                obj.search(name);
                break;
            case 4:
                exit(0);
            default:
                cout << endl << "Invalid choice";
        }
    } while (ch != 4);

    return 0;
}
