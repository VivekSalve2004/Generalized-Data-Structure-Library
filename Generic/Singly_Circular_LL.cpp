// Singly Circular LL using Template 
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
    struct node <T> * first;
    struct node <T> * last;
    int Count;

    public:
    SinglyCL();    
    void InsertFirst(T no);    
    void InsertLast(T no);   
    void Display();    
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int ipos);
    void DeleteAtPos(int ipos);
    
};

    template <class T>
    SinglyCL<T>::SinglyCL()
    {
        first = NULL;
        last = NULL;
        Count = 0;
    }

    template <class T>
    void SinglyCL<T>::InsertFirst(T no)
    {
        struct node <T> * newn = NULL;
        newn = new struct node <T>;
        newn->data = no;
        newn->next = NULL;

        if((first == NULL) || (last == NULL))     // if(Count == 0)  
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        last->next = first;
        Count++;
    }
    template <class T>
    void SinglyCL<T>::InsertLast(T no)
    {
        struct node <T> * newn = NULL;
        newn = new struct node <T>;
        newn->data = no;
        newn->next = NULL;

        if((first == NULL) || (last == NULL))     // if(Count == 0)  
        {
            first = newn;
            last = newn;
        }
        else
        {
           // newn->next = first;
            //first = newn;
            last->next = newn;
            newn->next = first;
            last = newn;
        }
        Count++;
    }
    template <class T>
    void SinglyCL<T>::Display()
    {
        if(first != NULL && last != NULL)
        {
            cout<<"Linked list is : "<<endl;
            do
            {
                cout<<" | "<<first->data<<" | ->";
                first = first->next;
            }while(first != last->next);
            cout<<"Address of first node "<<endl;
        }
    }

    template <class T>
    int SinglyCL<T>::CountNode()
    {
        return Count;
    }

    template <class T>
    void SinglyCL<T>::DeleteFirst()
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
            delete last->next;
            last->next = first;
        }
        Count--;
    }

    template <class T>
    void SinglyCL<T>::DeleteLast()
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
            struct node <T> * temp = first;
            while(temp->next != last)
            {
                temp = temp->next;
            }
            temp->next = first;
            delete last;
            last = temp;
        }
        Count--;
    }

    template <class T>
    void SinglyCL<T>::InsertAtPos(T no,int ipos)
    {
        
        if(ipos < 1 || ipos > Count+1)
        {
            cout<<"Invalid input "<<endl;
            return;
        }

        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == Count+1)
        {
            InsertLast(no);
        }
        else
        {
            struct node <T> * newn = new struct node <T>;
            newn->next = NULL;
            newn->data = no;
            struct node <T> * temp = first;
            for(int i=1;i <ipos-1;i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            Count++;
        }

    }

    template <class T>
    void SinglyCL<T>::DeleteAtPos(int ipos)
    {
        if(ipos < 1 || ipos > Count)
        {
            cout<<"Invalid input "<<endl;
            return;
        }

        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == Count)
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
            struct node <T> * target = temp->next;
            temp->next = temp->next->next;
            delete target;
            Count--;
        }
        
    }

int main()
{
    SinglyCL <int>obj;
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