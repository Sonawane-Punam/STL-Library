/************************************************************
                Structure of Singly LL And CL
 ***********************************************************/

using namespace std;
#include<iostream>

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

/************************************************************
                Class of Singly LL
 ***********************************************************/

template <class T>
class singlyLL
{
private:
    struct node<T> *Head;
    struct node<T> *Tail;
    int iSize;

public:
    singlyLL();
    ~singlyLL();
    void Display();
    int count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T,T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(T);

};

/************************************************************
                Function of Singly LL 
 ***********************************************************/

template <class T>
singlyLL <T>::singlyLL()
{
    Head = NULL;
    Tail=NULL;
    iSize=0;
}
template <class T>
singlyLL <T>::~singlyLL()
{
    struct node<T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
void singlyLL <T>::InsertFirst(T iNo)
{
    struct node<T> *newn= new struct node<T> ;
    newn->data=iNo;
    newn->next=NULL;

    newn->next=Head;
    Head=newn;
    iSize++;

}
template <class T>
int singlyLL <T>::count()
{
    return iSize;
}
template <class T>
void singlyLL<T>::Display()
{
    struct node <T>*temp=Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" "<<"->"<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}
template <class T>
void singlyLL<T>::InsertLast(T iValue)
{
    struct node <T>  *newn = NULL;
    newn = new  struct node<T>;
    newn->data = iValue;
    newn->next = NULL;
    
     struct node<T> *temp = Head;
    if(Head == NULL)    // LL is empty
    {
        Head = newn;
    }
    else    // LL contains atleast one node
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iSize++;
}
template <class T>    
void singlyLL<T>::DeleteFirst()
{
        if(Head != NULL)
        {
            struct node<T> *temp = Head;
            Head = Head -> next;
            delete temp;
            iSize--;
        }
}
template <class T>    
void singlyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    else if (Head -> next == NULL)
    {
        delete Head;
        Head = NULL;
        iSize--;
    }
    else
    {
        struct node<T> *temp = Head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        iSize--;
    }
}
template <class T>
void singlyLL<T>::InsertAtPosition(T iValue,T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    else if(iPos == 1)                   // First poistion
    {
        InsertFirst(iValue);
    }
    else if(iPos == iSize+1)    // Last position
    {
        InsertLast(iValue);
    }
    else    // LL contains atleast one node
    {
        newn = new struct node<T>;
        newn->data = iValue;
        newn->next = NULL;
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
        iSize++;
    }
}
template <class T>
void singlyLL<T>::DeleteAtPosition(T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    struct node<T> *Target=NULL;
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    else if(iPos == 1)                   // First poistion
    {
        DeleteFirst();
    }
    else if(iPos == iSize)    // Last position
    {
        DeleteLast();
    }
    else    // LL contains atleast one node
    {
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        Target = Temp -> next;
        Temp->next = Target -> next;
        delete Target;
        iSize--;
    }
}

/************************************************************
                Class of Singly CL 
 ***********************************************************/

template <class T>
class SinglyCL
{
private:
    struct node<T> *Head;
    struct node<T> *Tail;
    int iSize;
public:
    SinglyCL();
    ~SinglyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T,T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(T);
}; 
/************************************************************
                Function of Singly CL 
 ***********************************************************/
template <class T>
SinglyCL <T>::SinglyCL()
{
    Head = NULL;
    Tail=NULL;
    iSize=0;
}
template <class T>
SinglyCL <T>::~SinglyCL()
{
    struct node<T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    if((Head==NULL) &&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    iSize++;
    Tail->next=Head;
}   
template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    if((Head==NULL) &&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->next=newn;
        Tail=Tail->next;
    }
    iSize++;
    Tail->next=Head;
}
template <class T>
int SinglyCL<T>::Count()
{
    return iSize;
}
template <class T>
void SinglyCL<T>::Display()
{
    struct node<T> *Temp=Head;
    int i=0;
    for(i=1;i<=iSize;i++)
    {
        cout<<Temp->data<<" "<<"->"<<"\t";
        Temp=Temp->next;
    }
    cout<<"\n";
}
template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(iSize==0)
    {
        return;
    }
    else if(iSize==1)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
        iSize--;
    }
    else
    {
        Head=Head->next;
        delete(Tail->next);
        Tail->next=Head;
        iSize--;
    }
    
}
template <class T>
void SinglyCL<T>::DeleteLast()
{
    if(iSize==0)
    {
        return;
    }
    else if(iSize==1)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
        iSize--;
    }
    else
    {
        struct node<T> *Temp=Head;
        int i=0;
        for(i=1;i<iSize-1;i++)
        {
            Temp=Temp->next;
        }
        delete Tail;
        Tail=Temp;
        Tail->next=Head;
        iSize--;
    }
    
}
template <class T>
void SinglyCL<T>::InsertAtPosition(T iNo, T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;

    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }

    if(iPos == 1)                   // First poistion
    {
        InsertFirst(iNo);
    }
    else if(iPos == iSize+1)    // Last position
    {
        InsertLast(iNo);
    }
    else        // In between fisrst and last position
    {
        newn = new struct node<T>;
        newn->data = iNo;
        newn->next = NULL;
        
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
    iSize++;
}
template <class T>
void SinglyCL<T>::DeleteAtPosition( T iPos)
{
    int i = 0;
    struct node<T> *Temp = Head;
    struct node<T> *Target = NULL;

    if((iPos < 1) || (iPos > iSize))      // Invalid position
    {
        return;
    }
    if(iPos == 1)                   // First poistion
    {
        DeleteFirst();
    }
    else if(iPos == iSize)    // Last position
    {
        DeleteLast();
    }
    else        // In between fisrst and last position
    {
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        Target = Temp -> next;
        
        Temp->next = Target -> next;
        delete Target;
    }
    iSize--;
}

/************************************************************
                Class of Doubly LL 
 ***********************************************************/
template <class T>
class DoublyLL
{
    private:
        struct node<T> *Head;
        int iSize;
        
    public:
    DoublyLL();
    ~DoublyLL();
    int Count();
    void Display();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T,T);
    void DeleteAtPosition(T);
    void DeleteFirst();
    void DeleteLast();

};

/************************************************************
                Function of Doubly LL 
 ***********************************************************/
template <class T>
DoublyLL <T>::DoublyLL()
{
    Head = NULL;
    iSize=0;
}
template <class T>
DoublyLL <T>::~DoublyLL()
{
    struct node<T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
int DoublyLL<T>::Count()
{
    return iSize;
}

template <class T>
void DoublyLL<T>::Display()
{
   struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" "<<"->"<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
void DoublyLL<T>::InsertFirst(T iValue)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = iValue;
    newn->next = NULL;
    
    if(Head == NULL)    // LL is empty
    {
        Head = newn;
    }
    else    // LL contains atleast one node
    {
        newn->next=Head;
        Head->prev=newn;              
        Head=newn;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertLast(T iValue)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = iValue;
    newn->next = NULL;
    
    struct node<T> *temp = Head;
    if(Head == NULL)    // LL is empty
    {
        Head = newn;
    }
    else    // LL contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newn;
        newn -> prev = temp;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head != NULL)
    {
        Head=(Head)->next;
        delete((Head)->prev);      
        (Head)->prev=NULL; 
        iSize--;
    }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    else if (Head -> next == NULL)
    {
        delete Head;
        Head = NULL;
        iSize--;
    }
    else
    {
        struct node<T> *temp = Head;
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp->next);
        temp->next = NULL;
        iSize--;
    }
}
template <class T>
void DoublyLL<T>::InsertAtPosition(T iValue,T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    
    iSize = Count();
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    else if(iPos == 1)                   // First poistion
    {
        InsertFirst(iValue);
        //iSize++;
    }
    else if(iPos == iSize+1)    // Last position
    {
        InsertLast(iValue);
        //iSize++;
    }
    else    // LL contains atleast one node
    {
        newn =new struct node<T>;
        newn->data=iValue;
        newn->prev=NULL;
        newn->next=NULL;
        for(i=1;i<iPos-1;i++)
        {
            Temp=Temp->next;
        }
        newn->next=Temp->next;
        Temp->next->prev=newn;
        Temp->next=newn;
        newn->prev=Temp;
    }
    iSize++;
}
template <class T>
void DoublyLL<T>::DeleteAtPosition(T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    struct node<T> *Target=NULL;
    iSize = Count();
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    else if(iPos == 1)                   // First poistion
    {
        DeleteFirst();
        //iSize--;
    }
    else if(iPos == iSize)    // Last position
    {
        DeleteLast();
        //iSize--;
    }
    else    // LL contains atleast one node
    {
        for(i = 1; i< iPos-1 ; i++)
    {
        Temp = Temp -> next;
    }
    Temp->next=Temp->next->next;
    delete(Temp->next->prev);
    Temp->next->prev=Temp;
    }
    iSize--;
}

/************************************************************
                Class of Doubly CL 
 ***********************************************************/
template <class T>
class DoublyCL
{
    private:
        struct node<T> *Head;
        struct node<T> *Tail;
        int iSize;
        
    public:
    DoublyCL();
    ~DoublyCL();
    int Count();
    void Display();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T,T);
    void DeleteAtPosition(T);
    void DeleteFirst();
    void DeleteLast();

};

/************************************************************
                Function of Doubly CL 
 ***********************************************************/
template <class T>
DoublyCL<T>::DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    iSize=0;
}
template <class T>
DoublyCL <T>::~DoublyCL()
{
    struct node<T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
int DoublyCL<T>::Count()
{
    return iSize;
}

template <class T>
void DoublyCL<T>::Display()
{
    struct node<T> *Temp=Head;
    int i=0;
    for(i=1;i<=iSize;i++)
    {
        cout<<Temp->data<<" "<<"->"<<"\t";
        Temp=Temp->next;
    }
    cout<<"\n";
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;
    if((Head==NULL) &&(Tail==NULL))    //if(iSize==0)
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
    Tail->next=Head;
    Head->prev=Tail;
    iSize++;
}   

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct node<T> *newn=NULL;
    newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    if((Head==NULL) &&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->next=newn;
        newn->prev=Tail;
        Tail=newn;
    }
    Tail->next=Head;
    Head->prev=Tail;
    iSize++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(iSize==0)
    {
        return;
    }
    else if(iSize==1)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
        iSize--;
    }
    else
    {
        Head=Head->next;
        delete(Tail->next);
        Tail->next=Head;
        Head->prev=Tail;
        iSize--;
    }

}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(iSize==0)
    {
        return;
    }
    else if(iSize==1)
    {
        delete Tail;
        Head=NULL;
        Tail=NULL;
        iSize--;
    }
    else
    {
        Tail->prev=Tail;
        delete(Tail->next);
        Tail->next=Head;
        Head->prev=Tail;
        iSize--;
    }
        
}
template <class T>
void DoublyCL<T>::InsertAtPosition(T iNo, T iPos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *Temp = Head;
    
    //isize = Count();
    
    if((iPos < 1) || (iPos > iSize+1))      // Invalid position
    {
        return;
    }
    
    if(iPos == 1)                   // First poistion
    {
        InsertFirst(iNo);
    }
    else if(iPos == iSize+1)    // Last position
    {
        InsertLast(iNo);
    }
    else        // In between fisrst and last position
    {
        newn = new struct node<T>;
        newn->data = iNo;
        newn->next = NULL;
        newn->prev=NULL;
        
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        newn->next = Temp->next;
        newn->next->prev=Temp;
        Temp->next = newn;
        newn->prev=Temp;
        iSize++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPosition( T iPos)
{
    int i = 0;
    struct node<T> *Temp = Head;
    struct node<T> *Target = NULL;
    
    if((iPos < 1) || (iPos > iSize))      // Invalid position
    {
        return;
    }
    if(iPos == 1)                   // First poistion
    {
        DeleteFirst();
    }
    else if(iPos == iSize)    // Last position
    {
        DeleteLast();
    }
    else        // In between fisrst and last position
    {
        for(i = 1; i< iPos-1 ; i++)
        {
            Temp = Temp -> next;
        }
        Temp -> next=Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev=Temp;
        iSize--;
    }
}

/************************************************************
                Class of Stack 
 ***********************************************************/
template <class T>
class stack
{
    private:
    struct node<T> *Head;
    int isize;

    public:
    stack();                 //constructor
    ~stack();               //distructor
    void Push(T);         //void InsertFirst(int);
    int Pop();              //void DeleteFirst();
    void Display();
    int Count(); 
    int Peek();             //just return value withot removing
};

/************************************************************
                Function of Stack 
 ***********************************************************/
template <class T>
stack <T>::stack()
{
    Head=NULL;  
    isize=0;
}
template <class T>
stack <T>::~stack()
{
    struct node<T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
void stack <T>::Push(T iNo)
{
    struct node<T> *newn=NULL;
    newn= new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;

    newn->next=Head;
    Head=newn;
    isize++;
}
template <class T>
int stack <T>::Pop()
{
    int iret=-1;
    if(isize==0)
    {
        cout<<"stack is Empty\n";
        return iret;
    }
    else
    {
        struct node<T> *temp=Head;
        Head=Head->next;
        iret=temp->data;
        delete temp;
        isize--;
        return iret;
    }
    
}
template <class T>
int stack <T>::Peek()
{
    
    int iret=-1;
    if(isize==0)
    {
        cout<<"stack is Empty\n";
        return iret;
    }
    else
    {
        return Head->data;
    }
}
template <class T>
void stack <T>::Display()
{
    struct node<T> *temp=Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" "<<"->"<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}
template <class T>
int stack <T>::Count()
{
   return isize;
}

/************************************************************
                Class of Queue  
 ***********************************************************/
template <class T>
class Queue
{
    private:
    struct node<T> *Head;
    int isize;

    public:
    Queue();                
    ~Queue();               
    void Enqueue(T);       
    int Dequeue();              
    void Display();
    int Count(); 
};

/************************************************************
                Function of Queue  
 ***********************************************************/
template <class T>
Queue <T>::Queue()
{
    Head=NULL;   //Head=NULL;
    isize=0;
}
template <class T>
Queue <T>::~Queue()
{
    struct node <T> *temp=NULL;
    while(Head != NULL)
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}
template <class T>
void Queue <T>::Enqueue(T iNo)
{
    struct node<T> *newn=NULL;
    struct node<T> *temp=Head;
    newn= new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    isize++;
}
template <class T>
int Queue <T>::Dequeue()
{
    int iret=-1;
    if(isize==0)
    {
        cout<<"Queue is Empty\n";
        return iret;
    }
    else
    {
        struct node<T> *temp=Head;
        Head=Head->next;
        iret=temp->data;
        delete temp;
        isize--;
        return iret;
    }
    
}
template <class T>
void Queue<T>::Display()
{
    struct node<T> *temp=Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" "<<"->"<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}
template <class T>
int Queue <T>::Count()
{
   return isize;
}

int main()
{
    int iNo=0,iChoice=1,ipos=0,ret=0;
    singlyLL <int>obj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;
    stack <int>sobj;
    Queue <int>obj;


    while(iChoice != 0)
    {
        cout<<"1 : Singly Linear linked list\n";
        cout<<"2 : Singly circular linked list\n";
        cout<<"3 : Doubly Linear linked list\n";
        cout<<"4 : Doubly Circular linked list\n";
        cout<<"5 : Stack\n";
        cout<<"6 : Queue\n";
        cout<<"0 : Exit the application\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertFirst(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertLast(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                cout<<"Enter position\n";
                cin>>ipos;
                obj1.InsertAtPosition(iNo,ipos);
               
                obj1.DeleteFirst();
                
                obj1.DeleteLast();
                
                cout<<"Enter position\n";
                cin>>ipos;
                obj1.DeleteAtPosition(ipos);
                
                obj1.Display();
               
                iNo = obj1.count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;
                

            case 2:
                cout<<"Enter number\n";
                cin>>iNo;
                obj2.InsertFirst(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                obj2.InsertLast(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                cout<<"Enter position\n";
                cin>>ipos;
                obj2.InsertAtPosition(iNo,ipos);
               
                obj2.DeleteFirst();
                
                obj2.DeleteLast();
                
                cout<<"Enter position\n";
                cin>>ipos;
                obj2.DeleteAtPosition(ipos);
                
                obj2.Display();
               
                iNo = obj2.Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;

            case 3:
                cout<<"Enter number\n";
                cin>>iNo;
                obj3.InsertFirst(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                obj3.InsertLast(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                cout<<"Enter position\n";
                cin>>ipos;
                obj3.InsertAtPosition(iNo,ipos);
               
                obj3.DeleteFirst();
                
                obj3.DeleteLast();
                
                cout<<"Enter position\n";
                cin>>ipos;
                obj3.DeleteAtPosition(ipos);
                
                obj3.Display();
               
                iNo = obj3.Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;

            case 4:
                cout<<"Enter number\n";
                cin>>iNo;
                obj4.InsertFirst(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                obj4.InsertLast(iNo);

                cout<<"Enter number\n";
                cin>>iNo;
                cout<<"Enter position\n";
                cin>>ipos;
                obj4.InsertAtPosition(iNo,ipos);
               
                obj4.DeleteFirst();
                
                obj4.DeleteLast();
                
                cout<<"Enter position\n";
                cin>>ipos;
                obj4.DeleteAtPosition(ipos);
                
                obj4.Display();
               
                iNo = obj4.Count();
                cout<<"Number of elements are : "<<iNo<<"\n";
                break;

            case 5 :
                cout<<"Enter the element\n";
                cin>>iNo;
                sobj.Push(iNo);
               
                ret=sobj.Pop();
                cout<<"Poped element is : "<<ret<<"\n";
               
                cout<<"Element of stack are\n";
                sobj.Display();

                ret=sobj.Count();
                cout<<"Number of element are : "<<ret<<"\n";
              
                ret=sobj.Peek();
                cout<<"value of top element is : "<<ret<<"\n";

                break;

            case 6 :
                cout<<"Enter the element\n";
                cin>>iNo;
                obj.Enqueue(iNo);
               
                ret=obj.Dequeue();
                cout<<"Remove  element is : "<<ret<<"\n";
               
                cout<<"Element of Queue are\n";
                obj.Display();
                
                ret=obj.Count();
                cout<<"Number of element are : "<<ret<<"\n";
                break;

            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please Enter proper option\n";
                break;
        }

    }
    
    return 0;
}