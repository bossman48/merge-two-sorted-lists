

#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 // A simple C++ program for traversal of a linked list


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;

    // if list2 happen to be NULL
    // we will simply return list1.
    if(list2 == NULL)
        return list1;

    ListNode* result=NULL;
    result = new ListNode();
    ListNode* temp=NULL;
    temp=result;
    cout<<endl;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<list2->val){
            result->val=list1->val;
            list1=list1->next;
            if(list1==NULL || list1->val<list2->val ){
                result->next = new ListNode(list2->val);
                result=result->next;
            }
            else{
                result->next = new ListNode(list2->val);
                result=result->next;
            }
        }
        else{
            result->val= list2->val;
            list2=list2->next;
            if(list2==NULL || list1->val<list2->val ){
                result->next = new ListNode(list1->val);
                result=result->next;
            }
            else{
                result->next = new ListNode(list2->val);
                result=result->next;
            }
        }
    }
    while(list1!=NULL){
        result->val=list1->val;
        list1=list1->next;
        if(list1!=NULL) {
            result->next = new ListNode(list1->val);
            result = result->next;
        }
    }
    while(list2!=NULL){
        result->val=list2->val;
        list2=list2->next;
        if(list2!=NULL) {
            result->next = new ListNode(list2->val);
            result = result->next;
        }
    }

    return temp;
}
 void printList(ListNode* n)
 {
   cout<<endl;
     while (n != NULL) {
         cout << n->val << " ";
         n = n->next;
     }
 }

 // Driver code
 int main()
 {

     ListNode* bir=NULL;
     bir= new ListNode(1);

     ListNode* iki=NULL;
     iki= new ListNode(2);
     bir->next = iki;

     ListNode* uc=NULL;
     uc= new ListNode(4);
     iki->next = uc;

     printList(bir);

     ListNode* first=NULL;
     first= new ListNode(1);

     ListNode* second=NULL;
     second= new ListNode(3);
     first->next = second;

     ListNode* third=NULL;
     third= new ListNode(4);
     second->next = third;

     printList(first);
     ListNode* result=mergeTwoLists(bir,first);
     printList(result);
     ListNode* deneme=NULL;
     ListNode* deneme1=NULL;
     printList(mergeTwoLists(deneme,deneme1));

     return 0;
 }

 // This is code is contributed by rathbhupendra

