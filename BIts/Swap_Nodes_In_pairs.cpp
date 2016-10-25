/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {

    if (A->next==NULL){
        return A;
    }
    else if (A==NULL){
        return NULL;
    }

    struct ListNode* temp = A;
    struct ListNode* ans;
    struct ListNode* prev = NULL;
    struct ListNode * t1 = A->next;

    struct ListNode* store = NULL;
    bool first = true;
    while(t1!=NULL){
        store = t1->next;
        t1->next = temp;

        if (first){
            ans = t1;
            first = false;
        }
        else{
            prev ->next = t1;
        }

        prev = temp;
        temp->next = store;

        temp= temp->next;
        if (temp==NULL){
            t1=NULL;
        }
        else{
            t1 = temp->next;
        }


    }

    prev->next = temp;

    return ans;

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
