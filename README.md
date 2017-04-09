I. File list
------------
AVLTNode.cc		AVL tree node (AVLTNode) implementation
AVLTNode.h		AVLTNode header
AVLTree.cc		AVL tree (AVLTree) implementation
AVLTree.h		AVLTree header
BinarySearchTree.cc	Binary search tree (BinarySearchTree) implementation
BinarySearchTree.h	BinarySearchTree header
BSTNode.cc		Binary search tree node (BSTNode) implementation
BSTNode.h		BSTNode header
main.cc			driver for word-count
Makefile		Makefile to build word-count
MaxHeap.cc		Specialized max binary heap (MaxHeap) implementation
MaxHeap.h		MaxHeap header
README			This file
SplayTree.cc		Splay tree (SplayTree) implementation
SplayTree.h		SplayTree header
TemplateInst.cc		Instantiation file for all templated classes
heapsort.ps             Plot file for heapsort w/ splay tree on 10 files
quicksort.ps            Plot file for quicksort w/ splay tree on 10 files
selectionsort.ps        Plot file for selection sort w/ splay tree on 10 files


Program can be built using default make arguments.



II. Design
----------
A. Program design

1. Style
Code given by CSE326 staff was treated as though it was written by a team
member.  Naming conventions of pre-existing code was changed to match the
team's preferred style for member functions.

2. Collision handling
It seemed apparent that because we were generalizing through templates, to have
the result of doing an operation on some key that already existed be hardcoded
was not in good form.  This is where the collision policy idea came to bear.
The general principal is that the end-programmer using a tree should be able to
specify what happens as a result of a collision by supplying a function to
handle this event.  In case the end-programmer does not know about function
pointers, or has no desire to specialize the trees by supplying a collision
function, a default must be set up.  This directly translates to the
unparameterized constructor (default), the parameterized constructor (with
collision function) and the setCollisionPolicy function (in case they need to
change).

3. bool <function>(param& , param&) signatures
We wanted to have a way to notify the user of invalid find operations.  Since
the code is templatized we dont know what type to return for the function.  Thus
the bool return.  Essentially, if the operation is successful, return true and
modify the appropriate parameter that was passed in by reference.  If the
operation fails, return false, and leave the parameter alone.  With this design
decision made, other similar functions needed to have similar feels to maintain
a consistant API.


B. AVL Tree

1. Insertion
An interative insert function was written to give better performance because
recursive functions has to allocate/deallocate multiple stack frames.

2. AVLTNode
Because an AVL tree is a self-balancing tree, the node structure needs to be
extended to handle height information.


C. Splay Tree

1. Iteration vs. Recursion
Iteration was chosen specifically for code reuse purposes. The general algorithm
for any splay tree operation was to perform the operation then splay at that
particular node. Using the provided functions from the binary search tree code
allowed finding a particular node easy. Then once found, it was a matter of
simply splaying it to the root (while its not the root, splay it). The specific
algorithm for inserting was taken directly from the BST code, with only small
modifications for splaying and personal preferences on handling returns (try to
have return keyword in only one place).  

2. Small functions
They are easier to test, easier to code, easier to read,and definitely easier to
understand. The general concept is to minimize the syntax baggage for public
interface functions, letting them act as drivers, and have protected functions
do the gruntwork.

3. zig, zigZig, zigZag
Named after the operations that we discussed in class, these are the driver
functions for rotation.  Their names attempt to describe the general pattern
(although each describes two different symmetrical patterns) of a
node-parent-grandparent relationship.  In each function, there are calls to the
appropriate hanging function to simulate the rotation (see 5 for more
information).  Because of the binary ordering properties of a splay tree, each
function could make a set of assumptions on the data as to how to rotate, or
hang parent nodes.

4. hangPLeft, hangPRight 
The heart of rotation, these functions perform the basic operation of "hanging"
a parent (P) off of its child in a function name specified direction.  They
handle all of the pointer manipulation that maintains proper tree structure.
Although synonymous with rotation to some degree, it was felt that "hanging" and
direction gave a more complete and accurate description of what the function was
doing compared to "rotating".  Specifically, a rotation is nothing more than
hanging a parent off of its child, and a double rotation is nothing more than a
strictly ordered coupling of these hang operations.




Class Hierachy

		|-------------------------|             |------------|
                |     BinarySearchTree    |--has-a----->|   BSTNode  |
                |-------------------------|             |------------|
                           ^    ^                           ^  ^
                          /      \                          |  |
                       is-a     is-a                        |  |
                        /          \                        |  |
                       /           |--------------|         |  |
                      /            |  SplayTree   |-has-a---|  |
                     /             |--------------|            |
                    /                                        is-a 
                   /                                           |
    |----------------|                                  |------------|
    |     AVLTree    |--has-a-------------------------->| AVLNode    |
    |----------------|                                  |------------|
   

