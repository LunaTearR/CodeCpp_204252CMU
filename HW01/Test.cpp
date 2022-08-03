// Card *head;
    // Card *prev_last;
    // int size = 0;
    // CardList()
    // {
    //     prev_last = NULL;
    //     head = NULL;
    // }

    // void pop_back()
    // {
    //     Card *curr;
    //     Card *pre = head;
    //     if (size == 1)
    //     {
    //         size--;
    //         curr = head;
    //         head = head->next;
    //         delete curr;
    //         curr = NULL;
    //     }
    //     else if (size > 1)
    //     {
    //         size--;
    //         while (pre->next->next != NULL)
    //         {
    //             pre = pre->next;
    //         }
    //         curr = pre->next;
    //         pre->next = NULL;
    //         delete curr;
    //         curr = NULL;
    //     }
    // }

    // void insert_back(string newItem)
    // {
    //     size++;
    //     Card *newcard = new Card;
    //     Card *curr = head;
    //     newcard->name = newItem;
    //     if (size == 1)
    //     {
    //         head = newcard;
    //     }
    //     else 
    //     {
    //         prev_last = head->next;
    //         while (curr->next != NULL)
    //         {
    //             curr = curr->next;
    //         }
    //         curr->next = newcard;
    //     }
    // }

    // void shuffle(int pos)
    // {
    //     Card *curr;
    //     Card *pre = head;
    //     Card *first = head;
    //     Card *Last = head;
    //     if (pos >= 1 && size - 1 >= pos)
    //     {
    //         // find last node & find pre
    //         int i = 0;
    //         while (Last->next != NULL)
    //         {
    //             Last = Last->next; 
    //             if (size - 1 == pos)
    //             {
    //                 if (i < size - 3)
    //                 {
    //                     pre = pre->next;
    //                     i++;
    //                 }
    //             }
    //             else if (i < pos-1)
    //             {
    //                 pre = pre->next;
    //             }
    //             i++;
    //         }
    //         if (size == 2)
    //         {
    //             head = Last;
    //             head->next = first;
    //             head->next->next = NULL;
    //         }
    //         else if (size - 1 == pos)
    //         {
    //             head = Last;
    //             curr = Last;
    //             curr->next = first;
    //             if (pos >= 4)
    //             { 
    //                 pre = pre->next;
    //                 for ( i = 0; i < pos-4; i++);
    //                 {
    //                     pre = pre->next;
    //                 }
    //                 pre->next = NULL;
                    
    //             }
    //             else
    //             {
    //                 pre->next->next = NULL;
    //             }
    //         }
    //         else
    //         {
    //             curr = pre->next;
    //             head = curr;
    //             pre->next = NULL;
    //             Last->next = first;
    //         }
    //     }
    // }