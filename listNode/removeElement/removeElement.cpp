#include <iostream>
using namespace std;

//define the ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

//print the listnode
void printList(ListNode* head){
    while(head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
    public:
        ListNode* removeListNode(ListNode* head, int val) {
            ListNode* first = new ListNode(0);
            first->next = head;
            ListNode* cul = first;
            while (cul->next != nullptr) {
                if (cul->next->val == val){
                    cul->next = cul->next->next;}
                else {cul = cul->next;}
            }
            head = first->next;
            return head;
        }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);

    cout << "origin: ";
    printList(head);

    Solution sol;
    ListNode* newhead = sol.removeListNode(head, 1);

    cout << "new list: ";
    printList(newhead);

    return 0;
}
