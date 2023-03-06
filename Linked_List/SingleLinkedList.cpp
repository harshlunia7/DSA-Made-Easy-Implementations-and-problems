#include<iostream>

using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        struct ListNode* next;
        ListNode(int p) {
            val = p;
            next = NULL;
        }
    };
    struct ListNode* head;
    struct ListNode* tmp;
public:
    MyLinkedList() {
       head = NULL; 
       tmp = NULL; 
    }
    
    int get(int index) {
        if (head == NULL) return -1;
        else {
            tmp = head;
            while (index > 0 && tmp != NULL) {
                tmp = tmp -> next;
                --index;
            }
            
            if (index > 0 || tmp == NULL) return -1;
            else return tmp -> val;
        }
    }
    
    void addAtHead(int val) {
        tmp = new ListNode(val);
        tmp -> next = head;
        head = tmp;
    }
    
    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }
        
        tmp = head;
        while (tmp -> next != NULL) tmp = tmp -> next;
        tmp -> next = new ListNode(val);
        return;
    }
    
    void addAtIndex(int index, int val) {
        // List is empty and addition is not at head
        if (head == NULL && index != 0) return;
        
        struct ListNode* newNode = new ListNode(val);
        
        // Add at head
        if (index == 0) {
            newNode -> next = head;
            head = newNode;
            return;
        }
        
        int i;
        tmp = head;
        for(i = index - 1; i > 0 && tmp != NULL; --i) tmp = tmp -> next;
        
        // i>0: check if index overshoots the length of the list 
        // tmp == NULL: tmp is null and i == 0 which will happen in case the insertion is to take place just at the endIndex + 2 position 
        if (i > 0 || tmp == NULL) return;
        else {
            newNode -> next = tmp -> next;
            tmp -> next = newNode;
            return; 
        }
    }
    
    void deleteAtIndex(int index) {
        // List is empty
        if (head == NULL) return;
        
        // Delete head
        if (index == 0) {
            tmp = head;
            head = head -> next;
            delete tmp;
            return;
        }
        
        int i;
        tmp = head;
        for(i = index - 1; i > 0 && tmp != NULL; --i) tmp = tmp -> next;
        
        // i>0:  check if the index is outside the list
        // or tmp == NULL: present node is null meaning the i == 0 but the node to be deleted and one before that is null
        // tmp -> next == NULL : the node to be deleted is not present 
        if (i > 0 || tmp == NULL || tmp -> next == NULL) return;
        else {
            struct ListNode* tmp2 = tmp -> next;
            tmp -> next = tmp2 -> next;
            delete tmp2;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */