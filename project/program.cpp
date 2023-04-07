#include "splashkit.h"
using namespace std;

string read_string(string prompt)
{
   string name;
   write(prompt);
   name = read_line();
   return name;
}

int read_integer(string prompt)
{
   string line;
   line = read_string(prompt);
   return convert_to_integer(line);
}

// a sample c++ code for creating a Doubly Linked List  
  
// iostream is included to use the cout and cin objects for input and output operation from the user.  
 
using namespace std;  
    
// A struct named Node is created that will acts as a doubly-linked list node  
struct Node {  
   int data;  
   struct Node* next;  
   struct Node* prev;  
};
    
// a function named insert_front has created that inserts node at the front of the list  
void insert_front(struct Node** head, int new_data)  
{
   //allocate memory for New node  
   struct Node* newNode = new Node;  
    
   //assign data to new node  
   newNode->data = new_data;  
    
   //new node is head and previous is null, since we are adding at the front  
   newNode->next = (*head);  
   newNode->prev = NULL;  
    
   //previous of head is new node  
   if ((*head) != NULL)  
   (*head)->prev = newNode;  
    
   //head points to new node  
   (*head) = newNode;  
}

/* Given a node as prev_node,a fucntion named insert_After is created that insert a new node after the given node */  
void insert_After(struct Node* prev_node, int new_data)
{  
   //check if prev node is null  
   if (prev_node == NULL) 
   {  
      write_line("Previous node is required , it cannot be NULL");  
   return;  
   }
   //allocate memory for new node  
   struct Node* newNode = new Node;  
    
   //assign data to new node  
   newNode->data = new_data;  
    
   //set next of newnode to next of prev node  
   newNode->next = prev_node->next;  
    
   //set next of prev node to newnode  
   prev_node->next = newNode;  
    
   //now set prev of newnode to prev node  
   newNode->prev = prev_node;  
    
   //set prev of new node's next to newnode  
   if (newNode->next != NULL)  
   newNode->next->prev = newNode;  
}
    
//a function named insert_end is created that insert a new node at the end of the list  
void insert_end(struct Node** head, int new_data)  
{  
   //allocate memory for node  
   struct Node* newNode = new Node;  
    
   struct Node* last = *head; //set last node value to head  
    
   //set data for new node  
   newNode->data = new_data;  
    
   //new node is the last node , so set next of new node to null  
   newNode->next = NULL;  
    
   //check if list is empty, if yes make new node the head of list  
   if (*head == NULL) 
   {  
   newNode->prev = NULL;  
   *head = newNode;  
    return;  
   }
    
   //otherwise traverse the list to go to last node  
   while (last->next != NULL)  
   last = last->next;  
    
   //set next of last to new node  
   last->next = newNode;  
    
   //set last to prev of new node  
   newNode->prev = last;  
   return;  
}

//Delete the passed in node from its list.
void delete_node(Node current)
{
    if ( current == nullptr ) return;

    linked_list *list;
    Node before, after;

    list = current->in_list;
    before = current->prev;
    after = current->next;

    // is there something before this node?
    if (before != nullptr)
    {
        before->next = current->next;
    }
    else
    {
        // nothing before... so was first
        list->first = after;
    }

    // is there something after this node?
    if (after != nullptr)
    {
        after->prev = current->prev;
    }
    else
    {
        // nothing after... so was last
        list->last = before;
    }

    // now delete... and remove any links out to make sure
    current->prev = nullptr;
    current->next = nullptr;

    delete current;
}

    
// a fucntion named display is created that prints contents of linked list starting from the given node  
void displayList(struct Node* node) 
{  
   struct Node* last;  
     
   // until the last node is encountered the Linked List is traversed  
   while (node != NULL) {  
      write_line(to_string(node->data) + "<==>");  
      last = node;  
      node = node->next;  
   }  
   if(node == NULL)  
   write_line("NULL");  
}  
    
//main function starts  
int main() {  
  
   /* Start with the empty list */  
   struct Node* head = NULL;  
    
   char ch;  
   int data;  
   do{  
      // Menu  
      // Display messages  
      write_line("Please Choose one of the Operations::");  
      write_line("1. To Insert Data in the End of the Doubly Linked List.");  
      write_line("2. To Insert Data in the Front of the Doubly Linked List.");  
      write_line("3. To Insert Data aftere the head node in the Doubly Linked List.");  
      write_line("4. To Display Data in the Doubly Linked List.");  
      write(" "); 
                    
  
      // taaking input in the choice variable  
      int choice;  
      choice = read_integer("choice: ");  
      // Switch case  
      switch (choice) 
      {  
   
         case 1:  
         
         write_line("Enter the data that you want to add to the Doubly Linked List::");                          
         data = read_integer("Enter the value: ");  
         insert_end(&head,data);  
         write_line("Data Entered Successfully at the End of the Doubly Linked List.");   
         break;  
  
         
         case 2:  
  
         write_line("Enter the data that you want to add to the Doubly Linked List::");                          
         data = read_integer("Enter the value: ");   
         insert_front(&head,data);  
         write_line("Data Entered Successfully at the Front of the Doubly Linked List.");   
         break;  
  
         
         case 3:
      
         write_line("Enter the data that you want to add after the head node of the Doubly Linked List::");                          
         data = read_integer("Enter the value: ");  
         insert_After(head,data);  
         write_line("Data Entered Successfully after the head node of the Doubly Linked List.");
         break;  
  
         // Case 4  
         case 4:  
  
         write_line("Data in the Doubly Linked List is::");  
         displayList(head); 
         break;  
  
         default:  
         write_line("Please enter a valid option from the menu to proceed further.");  
         break;  
      }
      write_line("Type [N or n] to terminate the program.\nType [Y or y] to continue the program."); 
      ch = read_char();                
   } while (!(ch == 'N' || ch == 'n'));  
      
   return 0;  
}