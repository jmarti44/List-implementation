#include "Linkedlist.h"


Linkedlist::Linkedlist()
{
    
    
}

Linkedlist :: ~Linkedlist()
{
     
}

Linkedlist::Linkedlist(unsigned int n)
{
    //First Node initilization
    head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    //creating nodes based on n intalized with values n-1 [0 1 2 3 ]
    for (int i = 1; i < n; i++)
    {
        
        Node* node = new Node();
        node->prev = tail;
        node->elem = i;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

}
void Linkedlist::check()const
{
    Node* current = head; //fixed--->to start outputting from the end
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    cout << "----------Check---------" << endl;
    /*commented out for clarity of elem values-->used for error checking address and values of the nodes in the linked list
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }*/

    //ouputting values from the beginning-head and updating next
    while (current != NULL) 
    {
        cout <<  current->elem << " ";
        current = current->next;
        i++;
    }
    cout << endl;
    
}



void Linkedlist :: rcheck() const
{
    Node* current = tail; //fixed--->to start outputting from the end
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    cout << "----------Reverseheck---------" << endl;



    
    /*commented out for clarity of elem values-->used for error checking address and values of the nodes in the linked list
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current-> prev;
        i++;
    }*/
   
    //Similar logic to above, but only outputting elem elements and updating current prev
    while (current != NULL) 
    {
       
        cout << current->elem << " ";
            
        current = current-> prev;
        i++;
    }
    cout << endl;
}
//adds element before head and head is updated to new node
void Linkedlist:: push_front (const element_type& x)
{
    Node * newNode =  new Node();
    newNode->prev = NULL;
    newNode->elem = x;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

}
//adds specified x to the tail because it adds to the end of the list and tail is updated to new node
void Linkedlist :: push_back ( const element_type &x)
{
    Node * newNode = new Node();
    newNode->next = NULL;
    newNode->elem = x;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;

}

void Linkedlist :: insert( unsigned int pos, const element_type& x)
{
 
    
    int count = 0;
    Node * find = head;
    Node * size = head;
     while (size!=NULL)
    {
       
        count  = count  + 1;
        size = size->next;
    
    }

    if (pos == 1)
        this->push_front(x);
    else if (pos > count)
        this->push_back(x);


    else
    {
        //naviation through the linked list specified by pos
        for ( int i = 1; i<pos; i++)
        {
            find = find->next;
        }
        if (find == tail)
            this->push_back(x);
        else
        {   
        //New node is made for insertion with specfied value of x, where connections between prev and next are updated
            Node * newNode = new Node();
            newNode->elem = x;
            newNode->next = find;
            newNode-> prev = find->prev;
            find->prev->next= newNode;
            find->prev = newNode;
         }
    }

}
void Linkedlist:: erase(unsigned int pos)
{
    //Node pointers defined-one for navigating and one for getting the size of the linked list
    //tmp node for deletion
    Node * tmp = new Node();
    Node * search = head;
    Node * size = head;
    int count = 0;
    while (size!=NULL)
    {
       
        count  = count  + 1;
        size = size->next;
    
    }
    //condtional statements to account for different cases of indicated pos
 

    //remove first element
    if (pos == 1)
       this->pop_front();

    //remove last element when pos is grater than size of the list
    else if ( pos > count)
        this->pop_back();
  

    //navigating through the list occurs here
    else
    {
        for (int i = 1; i < pos; i++)
        {
            search = search->next;
        }
        // a case where pos is the tail
        if (search == tail)
            this->pop_back();
        
        //setting tmp node equal to search node
        //breaking and updating connections between next and prev 
        else
        {
        tmp = search;
        search->prev->next = tmp;
        search->next->prev = tmp;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    
        delete search;
        }
    }

    }

//Pop front and pop back involve using tmp node to store head and tail info||next and prev are updated to null
void Linkedlist :: pop_front()
{
    Node * tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
}

void Linkedlist :: pop_back()
{
    Node * tmp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete tmp;

}

Linkedlist :: reference Linkedlist ::front()
{
    return head->elem;
}

Linkedlist :: reference Linkedlist :: back()
{
    return tail->elem;

}

void Linkedlist :: sort()
{
  if (head ==NULL)
    cout << "list is empty" << endl;
    Node * tmp = head;
    element_type max = 0;   //max is initalized

    while (tmp->next != NULL)   //navigations through the linked list
    {
        if (tmp->elem > tmp->next->elem)        //comparision based on elem value--would execute if the current element is bigger than the next
        {
            max = tmp->elem;
            tmp->elem = tmp->next->elem;
            tmp->next->elem = max;
        }

      tmp = tmp->next;// tmp is updated to the next node for continuous comparison
    
        
    }    
}

bool Linkedlist :: empty() const
{
    Node * current = head;  

    if (current == NULL)
    {
        return true;
    }
    return false;
    
}

void Linkedlist :: clear()
{
    Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
}


Linkedlist& Linkedlist:: operator = (const Linkedlist&list)
{
    

    //List is cleared
    if (&list != this)
    {
        Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;

    
        //head is updated to the new list
        this->head = list.head;
        this->tail = list.tail;

   
    }
    return *this;


}

