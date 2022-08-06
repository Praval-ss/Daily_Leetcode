// https://leetcode.com/problems/design-circular-deque/


class MyCircularDeque {
public:
    vector<int> q;
    int f,r,k;
    MyCircularDeque(int kk) {
        k=kk;
        q.resize(k,0);
        f=-1;
        r=0;
        
    }
    
    bool insertFront(int value) {
        
        if(isFull()){
            return false;
        }
        if(f==-1){
            f=0;
            r=0;
        }
        else if(f==0){
            f=k-1;
        }
        else{
            f--;
        }
        q[f]=value;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(f==-1){
            f=0;
            r=0;
        }
        else if(r==k-1){
            r=0;
        }
        else{
            r++;
        }
        q[r]=value;
        return true;
        
    }
    
    bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }
        
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            if(f==k-1){
                f=0;
            }
            else{
                f++;
            }
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            if(r==0){
                r=k-1;
            }
            else{
                r--;
            }
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[f];
        
       
    }
    
    int getRear() {
        if(isEmpty() || r<0){
            return -1;
        }
        return q[r];
       
    }
    
    bool isEmpty() {
        return f==-1;
    }
    
    bool isFull() {
        return ((r==k-1 && f==0) ||( f==r+1));
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */