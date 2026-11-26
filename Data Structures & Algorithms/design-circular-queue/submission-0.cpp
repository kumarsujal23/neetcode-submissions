class Node{
    public:
        Node* next;
        int val;
        Node(int val)
        {
            this->next=nullptr;
            this->val=val;
        }
};
class MyCircularQueue {
public:
    Node* left;
    Node* right;
    int space;
    MyCircularQueue(int k) {
        space=k;
        left=new Node(0);
        right=left;
    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;
        Node* curr=new Node(value);
        if(isEmpty())
        {
            left->next=curr;
            right=curr;
        }
        else
        {
            right->next=curr;
            right=curr;
        }
        space--;
        return true;
    }
    bool deQueue() {
        if(isEmpty())
        return false;
        Node* temp=new Node(0);
        temp=left->next;
        left->next=left->next->next;
        delete temp;
        if(!left->next)
        right=left;
        space++;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:left->next->val;
    }
    
    int Rear() {
        return isEmpty()?-1:right->val;
    }
    
    bool isEmpty() {
        if(!left->next)
        return true;
        return false;
    }
    bool isFull() {
        return space==0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */