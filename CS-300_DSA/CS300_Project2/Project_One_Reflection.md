# **Project One Runtime Complexity Evaluation**

Throughout this term, we have spent considerable time creating and analyzing various commonly used data structures and algorithms.<br>
As has been discussed at various points of the process, each action and computation utilize a set amount of memory as well as requiring <br>
a set amount of time to complete, known as its runtime complexity. Runtime complexity is typically dependent on the number of items being <br>
worked with as well as the depth of which the items are being computed. The runtime complexity that we have been working with is **“Big O”** notation.

Each module, we were tasked with taking in datasets in the form of a csv file and manipulating the data to store and sort each collection <br>
of associated data points into nodes. Each week we were given a different data structure to work with these nodes. With each program, after <br>
declaring the csv file-path, we were given a prewritten function call to an included file that takes in the csv file as an argument, and <br>
parses through the dataset taking each line into program memory, then breaking down each line of the file to separate and store associated <br>
data points and creating a new node from each line. As each data structure used throughout the term received nodes as its respective data <br>
type to store, we were able to utilize a common parsing function with each term, which means the same runtime complexities.

On the initial call to the file parsing function, the first operation is to read the file. This is done first by determining the file type then <br>
deciding which handling technique is most appropriate to read the dataset into memory. This is done with a set of nested **IF** loops. As **IF** <br>
loops are a one-to-one comparison with a true/false *(yes/no)* result, the runtime complexity is always **O(1)**. However, within these loops is <br>
also a nested **WHILE** loop. While loops have the potential to iterate a number of times equal to entirety of the number of items in the set. <br>
Therefore, the runtime of a while loop is **O(n)**. With this, the maximum runtime of reading in a dataset is **O(n)**.

After reading the dataset into memory, the next set is to parse the data into useable nodes. This again is done in two steps. Once for the file <br>
header, then for the file content. Parsing the header is performed with a standard **WHILE** loop on the first index of the parsed file *(index 0)*.<br>
Like previously, a while loops worse-case runtime is **O(n)** as potentially every item in the dataset will need to be iterated through. The second<br>
portion is parsing the content within the dataset. This is done by using nested **FOR** loops. The outer loop iterates through each parsed line item <br>
of data. The inner loop iterates through each additional index *(indexes 1...n)*. Since each individual **FOR** loop may iterate up to *n* amount of <br>
times, where *n* is the total number of items, the maximum runtime complexity while parsing the dataset content is **O(n*n)** or **O(n^2)**.

Once the dataset is parsed and next operating was a function call to take each node item and load it into the selected data structure. In cases <br>
where a vector structure was used, a *Try/Catch* block is implemented with a nested **FOR** loop. Try/Catch blocks, like an *IF* loops are a yes/no<br>
function. Therefore, the outer loop runtime is **O(1)**. The nested **FOR** loop iterates through each content item previously parsed, creating a <br>
new node and setting each node attribute appropriately. Alternately, when a hash table structure is used, inserting a new node is also relatively<br>
simple. A designated attribute of the previously parsed item is first hashed to retrieve the appropriate bucket to store the node. Once the hash <br>
value is determined, an **IF** loop is used to determine if bucket is empty or now. If empty, a new linked list item is created, if not, the new <br>
node is appended to the current linked list. With this simple function, the worst-case runtime of inserting a node into a hash table is **O(1)**.

The last insert function is when a binary search tree is used. On the surface, adding the nodes appears to be a list of **IF** loops. However, each <br>
**IF** loop makes a recursive call. In the first line of the function, a base case is used to determine if the tree is empty. If the tree root node is <br>
empty, the new node is set as the trees root node. If the tree is not empty, a second **IF** loop is used to compare the root node value to the new <br>
nodes value. If the new node is less than the current node, the function is called recursively passing the current nodes left child. Alternatively, <br>
if the new node is more than the current node, the function is called recursively passing the current nodes right child. The recursive calls are <br>
repeated, moving either higher or lower than the current node until an appropriate *nullptr* node is found. Where then the new node is added to<br>
the tree. Therefore, even when an **IF** loop runtime is **O(1)**, each recursive call splits the remaining potential nodes in half. Therefore, <br>
the runtime complexity of inserting a new node into a binary search tree is **O(logN)**.

When assessing the runtime complexities and the type of data that is being assessed, my recommendation for the most appropriate data <br>
structure to store the data would be a **binary search tree**. My first reasoning is due to the fact the course list is inherently sorted <br>
as it is. The lower-level courses have a lower course ID therefore will end up naturally towards the lower left side of the tree. Additionally,<br>
while working with the binary search tree, adding new nodes, removing existing nodes, and searching the tree for a matching node always <br>
averages a runtime complexity of **O(logN)**. In extreme cases, when the tree becomes extremely unbalanced, in which all the nodes are to <br>
one side of the tree root, the tree becomes essentially a linked list. In these extreme cases, the worst-case runtime becomes **O(n)**. <br>
However, in the situation we are given in which we are working with program courses that are unlikely to be removed, the potential of the <br>
binary search tree becoming extremely unbalanced is very low.