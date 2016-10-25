/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {

    struct ListNode* t = A;
    struct ListNode* b = NULL;
    struct ListNode* st;
    struct ListNode* prev = NULL;
    struct ListNode* stinext = NULL;
    struct ListNode* bB;
    struct ListNode* justb;
    struct ListNode* ans =  A;
    struct ListNode* fg;

    bool fgf = false;

    while(t!=NULL){
        if (t->val==B){
            b = t;
            break;
        }
        if (!fgf && t->val>B){
            fg = t;
            fgf = true;
        }

        t = t->next;
    }

    if (b!=NULL){
        t = A;
        bB = b;
    }
    else{
        t = A;
        bB = fg;
        b = fg;
    }

    while(t!=NULL && t!=bB){
        if (t->val>B){
            if (prev==NULL){
                stinext = t->next;
                ans = stinext;
            }
            else{
                prev->next = t->next;
                stinext = prev->next;

            }
            st = b->next;
            b->next = t;
            t->next = st;
            t = stinext;
            b = b->next;
        }
        else{
            prev = t;
            t= t->next;
        }
    }

    // cout << " " << t->val << " \n";

    if (b!=NULL)
        t = b;
    else
        t = fg;


    justb = prev;
    prev = NULL;

    // cout << justb->val << " " << t->val << " \n";


    while(t!=NULL){
        if (t->val<=B && t!=bB){
            prev->next = t->next;

            if (justb!=NULL){
                st = justb->next;
                justb->next  = t;
                t->next = bB;
            }
            else{
                t->next = bB;
                ans = t;
            }

            justb = t;

            t = prev->next;
        }
        else{
            prev = t;
            t= t->next;
        }
    }



    return ans;



    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
