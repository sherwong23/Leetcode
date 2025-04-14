#include <iostream> 
using namespace std; 

class MyLinkedList {
    public:
    //define list
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    //add a first
    MyLinkedList(){
        _head = new LinkedNode(0);
        _size = 0;
    }

    //functions
    int get(int index) {
        if ((index > (_size - 1)) || index < 0){
            return -1;
        }

        LinkedNode* cul = _head->next;
        while(index--) {
            cul = cul->next;
        };
        return cul->val;
    }

    void addAtHead(int val) {
        LinkedNode* new_head = new LinkedNode(val);
        new_head->next = _head->next;
        _head->next = new_head;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* new_tail = new LinkedNode(val);
        LinkedNode* cul = _head;
        while(cul->next != nullptr){
            cul = cul->next;
        };
        cul->next = new_tail;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0){index = 0;};
        if (index > _size - 1)return;

        LinkedNode* newnode = new LinkedNode(val);
        LinkedNode* cul = _head;
        while(index--) {
            cul = cul->next;
        };
        newnode->next = cul->next;
        cul->next = newnode;
        _size++;
    }
            
    void deleteAtIndex(int index) {
        if (index < 0 || index > _size - 1){return;};
        LinkedNode* cul = _head;
        while(index--) {
            cul = cul->next;
        };
        LinkedNode* temp = cul->next;
        cul->next = temp->next;
        delete temp;
        _size--;
    }

    void printLinkedList() {
        LinkedNode* cur = _head;
        while (cur->next != nullptr){
            cur = cur->next;
            cout << cur->val << " -> ";
        };
        cout << "null" << endl;
    }

    void reverseList() {
        LinkedNode* cur = _head->next;
        LinkedNode* tem = NULL;
        LinkedNode* pre = NULL;
        while (cur != nullptr){
            //update cur  
            tem = cur;
            cur = cur->next;
            //work with tem to reverse
            tem->next = pre;
            pre = tem;
        }
        _head->next = pre;
    }

            
private:
    int _size;
    LinkedNode* _head;

};

// 上記の MyLinkedList クラスがここにあると仮定します（省略）

int main() {
    MyLinkedList list;

    cout << "== 添加节点 ==" << endl;
    list.addAtHead(10);
    list.addAtHead(20);
    list.addAtTail(5);
    list.addAtIndex(1, 15);  // 在下标1插入15
    list.printLinkedList(); // 预期输出: 20 15 10 5
    list.reverseList();
    list.printLinkedList();

    cout << "== 获取节点 ==" << endl;
    cout << "index 0: " << list.get(0) << endl; // 20
    cout << "index 2: " << list.get(2) << endl; // 10
    cout << "index 4: " << list.get(4) << endl; // -1（越界）

    cout << "== 删除节点 ==" << endl;
    list.deleteAtIndex(1); // 删除值为15的节点
    list.printLinkedList(); // 预期输出: 20 10 5

    list.deleteAtIndex(0); // 删除头部节点（20）
    list.printLinkedList(); // 预期输出: 10 5

    list.deleteAtIndex(5); // 越界，无操作
    list.printLinkedList(); // 仍是: 10 5

    return 0;
}






