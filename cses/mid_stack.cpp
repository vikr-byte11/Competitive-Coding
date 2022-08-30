/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

class myStack
{
    struct Node
    {
        int num;
        Node *next;
        Node *prev;

        Node(int num)
        {
            this->num = num;
            next = NULL;
            prev = NULL;
        }
    };

    //Members of stack
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        size++;
        if (size % 2 == 1)
        {
            mid = mid->prev;
        }
    }

    void pop()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                if (size % 2 == 1)
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->num;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head->next = NULL;
                mid = head;
            }
            else
            {
                mid->prev->next = mid->next;
                mid->next->prev = mid->prev;
                if (size % 2 == 1)
                {
                    mid = mid->next;
                }
                else
                {
                    mid = mid->prev;
                }
            }
            size--;
        }
    }
};

int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    cout << st.findMiddle() << endl;

    st.pop();
    cout << st.findMiddle() << endl;

    st.pop();
    cout << st.findMiddle() << endl;

    st.pop();

    cout << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << st.findMiddle() << endl;

    return 0;
}