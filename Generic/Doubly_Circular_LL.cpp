// Doubly circular
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    private:
    struct node <T> * first;
    struct node <T> * last;
    int Count;

    public:
    DoublyCL();    
    void InsertFirst(T no);    
    void InsertLast(T no);   
    void Display();    
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int ipos);
    void DeleteAtPos(int ipos);
    
};

    template<class T>
    DoublyCL<T>::DoublyCL()
    {
        first = NULL;
        last = NULL;
        Count = 0;
    }

    template<class T>
    void DoublyCL<T>::InsertFirst(T no)
    {
        struct node <T> * newn = new struct node <T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if(first == NULL && last == NULL)
        {
            last = newn;
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        last->next = first;
        first->prev = last;
        Count++;
    }

    template<class T>
    void DoublyCL<T>::InsertLast(T no)
    {
        struct node <T> * newn = new struct node <T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if(first == NULL && last == NULL)
        {
            last = newn;
            first = newn;
        }
        else
        {
            last->next = newn;
            newn->prev = last;
            last = newn;
        }
        last->next = first;
        first->prev = last;
        Count++;
    }

    template<class T>
    void DoublyCL<T>::Display()
    {
        struct node <T> * temp = first;
        if((first != NULL) && (last != NULL))
        {
            cout<<"Address of last node ";
            cout<<" <=> ";
            do
            {
                cout<<" | "<<temp->data<<" | <=>";
                temp = temp->next;

            }while(temp != last->next);
            cout<<"Address of first node ";
            cout<<endl;
        }
    }

    template<class T>
    int DoublyCL<T>::CountNode()
    {
        return Count;
    }

    template<class T>
    void DoublyCL<T>::DeleteFirst()
    {
        if(first == NULL && last == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete first->prev;
            first->prev = last;
            last->next = first;
        }
        Count--;
    }

    template<class T>
    void DoublyCL<T>::DeleteLast()
    {
        if(first == NULL && last == NULL)
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            last = last->prev;
            delete last->next;
            first->prev = last;
            last->next = first;
        }
        Count--;
    }

    template<class T>
    void DoublyCL<T>::InsertAtPos(T no,int ipos)
    {
        if((ipos < 1) || (ipos > Count+1))
        {
            cout<<"Invalid input "<<endl;
            return;
        }

        if(ipos==1)
        {
            InsertFirst(no);
        }
        else if(ipos==Count+1)
        {
            InsertLast(no);
        }
        else
        {
            struct node <T> * temp = first;
            struct node <T> * newn = new struct node <T>;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            for(int i=1;i<ipos-1;i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
            Count++;
        }
    }

    template<class T>
    void DoublyCL<T>::DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > Count))
        {
            cout<<"Invalid input "<<endl;
            return;
        }

        if(ipos==1)
        {
            DeleteFirst();
        }
        else if(ipos==Count)
        {
            DeleteLast();
        }
        else
        {
            struct node <T> * temp = first;
            for(int i=1;i<ipos-1;i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
            Count--;
        }
    }

int main()
{
    DoublyCL <int> obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in Linked List are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in Linked List are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in Linked List are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in Linked List are : "<<iRet<<"\n";

    return 0;
}