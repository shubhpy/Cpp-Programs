/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {


    if (A->next==NULL){
        return A;
    }
    else if (A==NULL){
        return NULL;
    }

    struct ListNode* t = A;
    struct ListNode* prev = NULL;
    struct ListNode* last;
    struct ListNode* ans =  NULL;
    int count = 1;

    bool first = true;

    while(t!=NULL){
        if (prev==NULL){
            prev = t;
            last = t;
        }
        else if (prev->val == t->val){
            count++;
            prev = prev->next;
        }
        else{
            if (count<2){
                last  = prev;
                prev = t;
                if (first){
                    ans = last;
                    first = false;
                }

            }
            else{
                last->next  = t;
                count = 1;
                prev = t;
            }
        }

        t = t->next;
    }
    if (count>=2){
        last->next = t;
    }

    return ans;

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

