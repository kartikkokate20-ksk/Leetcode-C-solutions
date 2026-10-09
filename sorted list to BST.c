struct TreeNode* build(struct ListNode** curr, int n) {
    if (n <= 0)
        return NULL;

    struct TreeNode* left = build(curr, n / 2);

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = (*curr)->val;
    root->left = left;

    *curr = (*curr)->next;

    root->right = build(curr, n - n / 2 - 1);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int n = 0;
    struct ListNode* temp = head;

    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    return build(&head, n);
}