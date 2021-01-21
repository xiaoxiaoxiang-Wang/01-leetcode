/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
using namespace std;
struct cmp {
	bool operator()(ListNode* &a, ListNode* &b) {
		return  a->val > b->val;  //Ð¡¶¥¶Ñ
	}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) {
            return NULL;
        }
        ListNode* rt = new ListNode(0);
        ListNode* p = rt;
        // ListNode** l = new ListNode*[size];
	    priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]){
                q.push(lists[i]);
            }
        }
        while(!q.empty()) {
            p->next = q.top();
            q.pop();
            if(p->next->next) {
                q.push(p->next->next);
            }
            p = p->next;
        }
             
        return rt->next;
    }
};