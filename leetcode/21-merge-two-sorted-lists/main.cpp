#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    // Below these are constructors, with different numbers of arguments passed
    // and therefore different results of initialization.
    // The first one initializes value as 0 and nullptr as the pointer to the next node.
    ListNode() : val(0), next(nullptr) {}
    // The second one initializes the argument passed as value and nullptr as the pointer to the next node.
    ListNode(int x) : val(x), next(nullptr) {}
    // The third one initializes the first argument passed as value and the second argument passed as the pointer to the next node.
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    std::cout << '{';
    ListNode* node = head;
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) { std::cout << ", "; }
        node = node->next;
    }
    std::cout << '}' << std::endl;
}

ListNode* constructLinkedList(std::vector<int> vec) {
    if (vec.size() == 0) { return nullptr; }
    ListNode* prev = new ListNode(vec.back());
    for (int i = vec.size()-2; i >= 0; i--) {
        ListNode* newNode = new ListNode(vec[i], prev);
        prev = newNode;
    }
    return prev;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // If both lists are empty return a nullptr
    if (list1 == nullptr && list2 == nullptr) { return nullptr; }
    // If only list1 is empty return list2 and vice versa
    if (list1 == nullptr) {
        return list2;
    } else if (list2 == nullptr) {
        return list1;
    }
    // Otherwise, neither list is empty
    
    ListNode* head;
    ListNode* merged;
    ListNode* other;
    if (list1->val < list2->val) {
        head = list1;
        merged = list1;
        other = list2;
    }
    else {
        head = list2;
        merged = list2;
        other = list1;
    }

    while (merged->next != nullptr && other != nullptr) {
        if (other->val < merged->next->val) {
            merged->next = new ListNode(other->val, merged->next);
            other = other->next;
        } else {
            merged = merged->next;
        }
    }

    // Deal with the leftovers in the other list
    if (other != nullptr) { merged->next = other; }
    
    return head;
}

int main() {
    ListNode* list1 = constructLinkedList({-10,-10,-9,-4,1,6,6});
    ListNode* list2 = constructLinkedList({-7});

    ListNode* list3 = mergeTwoLists(list1, list2);

    printList(list3);
}
