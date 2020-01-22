# 解题要点

链表的操作一般会引入辅助节点, 这样可以简化操作. 因为链表操作大多会围绕
某个支点(pivot)性质节点进行. 创建一个新节点作为支点, 比从原链表中选取
支点更方便得多. 因为如果从原链表中选取的话, 需要单独遍历, 或者在正常操
作时选取. 前者增加了遍历次数(时间复杂度), 后者增加代码复杂度让遍历操作
产生两个分支(一个是已选取, 一个是未选取).

另外一个要点是遍历时的指针到底是指向符合条件的节点, 还是符合条件的前一
个节点? 如果是指向符合条件的节点, 那么需要在遍历的过程额外维护该节点的
前节点指针; 如果是指向前节点, 则在遍历时少维护一个指针.

# Breaking Point

Operations on Linked List usually needs a pivot node, this
pivot node can be chosen from original list, or newly
created. Creating a new node as pivot could make things much
more easier. Because to chose a pivot node needs to iterate
over the list, or during operation iterating procedure. The
first choice increase time complexity, while the second
choice increase code complexity as two condition branches
during iterating(one for pivot being set, one for not set).

Next is should we make the iterator pointing to the node
that needs to be operated on, or to the previous node before
that? If the iterator is pointing to the target node, we
need to keep track of previous node as well; If pointing to
the previous node before target node, we use only one
pointer while iterating.
