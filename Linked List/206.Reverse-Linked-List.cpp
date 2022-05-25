#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void printLinkedList(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        
        return prev;
    }


    ListNode* reverseListRecursion(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* nextNode = head->next;
        if(!nextNode) {
            return head;
        }
        
        ListNode* newHead = reverseListRecursion(nextNode);
        nextNode->next = head;
        head->next = NULL;

        return newHead;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    
    Solution obj;
    obj.printLinkedList(n1);

    ListNode* listReversed = obj.reverseListRecursion(n1);
    obj.printLinkedList(listReversed);

    return 0;
}