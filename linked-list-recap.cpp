#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // Constructor Creating
    Node(int val)
    {
        // Initializing value and next member
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
int countLength(Node *&head);
void insertAtSpecificPosition(Node *&head, int pos, int value);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void insertAfterSpecificValueUnique(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int pos);
void deletionByValueUnique(Node *&head, int Value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    // 1st step: NewNode Creation
    Node *newNode = new Node(val);
    // 2nd step: Update
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void insertAtSpecificPosition(Node *&head, int pos, int value)
{
    int i = 0;
    Node *newNode = new Node(value);
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (head == NULL)
    {
        return -1;
    }

    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int size;
    size = countLength(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if (flag == 0)
    {
        cout << "The searched value is not yet in the list" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The Value is at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
                cout << ",";
        }
        cout << endl;
    }
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}

void insertAfterSpecificValueUnique(Node *&head, int searchValue, int value)
{
    // Step 1: Search the position of the search value
    int position;
    position = searchByValueUnique(head, searchValue);

    // Step 2: Insert the value of the position+1
    insertAtSpecificPosition(head, position + 1, value);
}

void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the Linked List" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
            cout << "There is no value in the Linked List" << endl;
        else
            deletionAtHead(head);
    }
}

void deletionAtSpecificPosition(Node *&head, int pos)
{
    if (pos <= countLength(head))
    {
        if (pos == 1)
        {
            deletionAtHead(head);
        }
        else if (pos == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            Node *temp = head;
            int i = 1;
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }
            Node *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Position Out of Bound" << endl;
    }
}

void deletionByValueUnique(Node *&head, int value)
{
    // Find the position of the value
    int position = searchByValueUnique(head, value);

    if (position == -1)
    {
        cout << "Value Not Found In The Linked List" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at head" << endl
         << "Choice 2: Insertion at tail" << endl
         << "Choice 3: Insertion at specific position" << endl
         << "Choice 4: Search a value (Unique List)" << endl
         << "Choice 5: Search a value (Duplication Enabled List)" << endl
         << "Choice 6: Insertion after a specific value (Unique List)" << endl
         << "Choice 7: Deletion at Head" << endl
         << "Choice 8: Deletion at Tail" << endl
         << "Choice 9: Deletion at Specific Position" << endl
         << "Choice 10: Deletion by Value" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value to Search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "The Number is at position " << position << endl;
            }
            else
            {
                cout << "The Number is not yet the list" << endl;
            }
            break;
        case 5:
            cout << "Enter the value to Search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.position[0] == 1)
            {
                cout << "The searched value is not yet in the list" << endl;
            }
            else
            {
                int size = T.position[0];
                cout << "The Value is at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.position[i];
                    if (i < size - 1)
                        cout << ",";
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the value to search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAfterSpecificValueUnique(head, searchValue, value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            if (head == NULL)
            {
                cout << "There is no value in the Linked List" << endl;
                break;
            }
            cout << "Enter the Desired Position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            cout << endl;
            display(head);
            break;
        case 10:
            cout << "Enter the value to Delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    cout << endl
         << "Linked List: ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}
