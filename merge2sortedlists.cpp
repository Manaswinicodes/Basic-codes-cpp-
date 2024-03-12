#include <iostream>

using namespace std;

struct Node {
   int data;
   Node* next;
};

Node* createNode(int data) {
   Node* newNode = new Node();
   newNode->data = data;
   newNode->next = nullptr;
   return newNode;
}

void insertNode(Node** head, int data) {
   Node* newNode = createNode(data);
   if (*head == nullptr) {
       *head = newNode;
       return;
   }
   Node* current = *head;
   while (current->next != nullptr) {
       current = current->next;
   }
   current->next = newNode;
}

Node* mergeSortedLists(Node* a, Node* b) {
   
   Node* dummy = createNode(-1);
   Node* tail = dummy;

   while (a != nullptr && b != nullptr) {
       if (a->data <= b->data) {
           tail->next = a;
           a = a->next;
       } else {
           tail->next = b;
           b = b->next;
       }
       tail = tail->next;
   }

   
   tail->next = (a != nullptr) ? a : b;

   return dummy->next;
}


void printList(Node* head) {
   while (head != nullptr) {
       cout << head->data << " ";
       head = head->next;
   }
   cout << endl;
}

int main() {
   
   Node* a = nullptr;
   insertNode(&a, 10);
   insertNode(&a, 15);
   insertNode(&a, 20);
   insertNode(&a, 25);

   Node* b = nullptr;
   insertNode(&b, 2);
   insertNode(&b, 3);
   insertNode(&b, 5);
   insertNode(&b, 7);

   Node* mergedList = mergeSortedLists(a, b);

   cout << "Merged list: ";
   printList(mergedList);

   return 0;
}
