#include <iostream>
#include <cstdlib> //for free()

using namespace std;

//function declarations
void function_tree();



//Stack function and variables
void function_stack();
void push_stack();
void pop_stack();
void print_stack();
int *p;
int top,length;

//Linkedlist functions and variables
void function_linkedlist();

void function_singly_linkedlist();
void insert_singly_linkedlist();
void delete_singly_linkedlist();
void print_singly_linkedlist();

void function_doubly_linkedlist();
void insert_doubly_linkedlist();
void delete_doubly_linkedlist();
void print_doubly_linkedlist();

void function_circular_linkedlist();
void insert_circular_linkedlist();
void delete_circular_linkedlist();
void print_circular_linkedlist();

struct singly
{
	int data;
	struct singly* next;
}*SINGLY;

struct circular
{
	int data;
	struct circular* next;
}*CIRCULAR;

struct doubly
{
	int data;
	struct doubly* next;
	struct doubly* prev;
}*DOUBLY;

//QUEUE Functions and variables
void function_queue();
void insert_queue();
void delete_queue();
void print_queue();

int front = -1, rear = -1;
int MAX = 25;
int *array_q = new int [MAX];

//Search
void function_searching();
void binary_search();
void linear_search();

//SORT
void function_sorting();
void bubble_sort();
void insertion_sort();
void selection_sort();
void merge_sort();
void mergesort(int *a, int low, int high);
void merge(int *a, int low, int high, int mid);

//Graph
void function_graph();

int d_w = 0;
struct d_node
{
    char d_data;
    int d_st_time, d_lv_time;
}*d_p = NULL, *d_r = NULL;
struct d_stack
{
    d_node *d_pt;
    d_stack *d_next;
}*d_top = NULL, *d_q = NULL, *d_np= NULL;
void depth_first();
void d_push(d_node *d_ptr);
d_node *d_pop();
void d_create(int d_a[], int d_b[][7], int d_i, int d_j);

void breadth_first();
int c = 0, t = 0;
struct node_info
{
    int no;
    int st_time;
}*q = NULL, *z = NULL, *x = NULL;
struct node
{
    node_info *pt;
    node *next;
}*f = NULL, *r = NULL, *p1 = NULL, *np = NULL;
void bfs(int*,int am[][7],int i);
node_info * remove();
void push(node_info);

//Main function
int main()
{
	int n=1;
	while(n!=0)
	{	
		cout<<"Choose one Option.."<<endl;
		cout<<"1. Stack"<<endl<<"2. LinkedList"<<endl<<"3. Queue"<<endl<<"4. Tree"<<endl<<"5. Graph"<<endl<<"6. Searching"<<endl<<"7. Sorting"<<endl<<"0. Exit"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: function_stack();break;
			case 2: function_linkedlist();break;
			case 3: function_queue();break;
		/*	case 4: function_tree();break; */
			case 5: function_graph();break; 
			case 6: function_searching();break;
			case 7: function_sorting();break;
			default: cout<<"Choice does not exist";
		}
	}
	return 0;
}

void function_graph()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Graph.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Depth First Search"<<endl<<"2. Breadth First Search"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: depth_first();break;
			case 2: breadth_first();break;
		}
	}
}

void d_push(d_node *d_ptr)
{
    d_np = new d_stack;
    d_np->d_pt = d_ptr;
    d_np->d_next = NULL;
    if (d_top == NULL)
    {
        d_top = d_np;
    }
    else
    {
        d_np->d_next = d_top;
        d_top = d_np;
    }
}
d_node *d_pop()
{
    if (d_top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        d_q = d_top;
        d_top = d_top->d_next;
        return(d_q->d_pt);
        delete(d_q);
    }
}
void d_create(int d_a[], int d_b[][7], int d_i, int d_j)
{
    d_w++;
    d_p = new d_node;
    cout<<"enter data for new node\n";
    cin>>d_p->d_data;
    d_p->d_st_time = d_w;
    cout<<"start time for "<<d_p->d_data<<" is "<<d_w<<endl;
    d_a[d_i] = 1;
    d_push(d_p);
    while (d_j < 7)
    {cout<<".";
        if ((d_b[d_i][d_j] == 0) || (d_b[d_i][d_j] == 1 && d_a[d_j] == 1))
        {
            d_j++;
        }
        else if (d_b[d_i][d_j] == 1 && d_a[d_j] == 0)
        {       
            d_create(d_a,d_b,d_j,0);
        }
    }
    d_r = d_pop();
    cout<<"node popped\n";
    d_w++;
    cout<<"leave time for "<<d_r->d_data<<" is "<<d_w<<endl;
    return;
}

void depth_first()
{
	int d_a[7];
    for (int d_i = 0; d_i < 7; d_i++)
    {
        d_a[d_i] = 0;
    }
    int d_b[7][7];
    cout<<"enter values for adjacency matrix only ( 1 or 0 )"<<endl;
    for (int d_i = 0 ; d_i < 7 ; d_i++ )
    {
        cout<<"enter values for "<<(d_i+1)<<" row"<<endl;
        for (int d_j = 0; d_j < 7; d_j++)
        {
            cin>>d_b[d_i][d_j];
        }
    }
    d_create(d_a,d_b,0,0);
    return;
}

void breadth_first()
{
	int v[7], am[7][7];
    for (int i = 0; i < 7; i++)
        v[i] = 0;
    for (int i = 0; i < 7; i++)
    {
        cout<<"enter the values for adjacency matrix row:"<<i+1<<endl;
        for (int j = 0; j < 7; j++)
        {
            cin>>am[i][j];
        }
    }
    bfs(v, am, 0);
}
void push(node_info *ptr)
{
    np = new node;
    np->pt = ptr;
    np->next = NULL;
    if (f == NULL)
    {
        f = r = np;
        r->next = NULL;
    }
    else
    {
        r->next = np;
        r = np;
        r->next = NULL;
    }
}
node_info *remove()
{
    if (f == NULL)
    {
        cout<<"empty queue\n";
    }
    else
    {
        p1 = f;
        x = p1->pt;
        f = f->next;
        delete(p1);
        return(x);
    }
}
void bfs(int *v,int am[][7],int i)
{ 
    if (c == 0)
    {
        q = new node_info;
        q->no = i;
        q->st_time = t++;
        cout<<"time of visitation for node "<<q->no<<":"<<q->st_time<<"\n\n";
        v[i] = 1;
        push(q);
    }
    c++;
    for (int j = 0; j < 7; j++)
    {
        if (am[i][j] == 0 || (am[i][j] == 1 && v[j] == 1))
            continue;
        else if (am[i][j] == 1 && v[j] == 0)
        {
            z = new node_info;
            z->no = j;
            z->st_time = t++;
            cout<<"time of visitation for node "<<z->no<<":"<<z->st_time<<"\n\n";
            v[j] = 1;
            push(z);
        }
    }
    remove();
    if (c <= 6 && f != NULL)
        bfs(v, am, remove()->no);
}  

/**********************************************SORT FUNCTIONS BELOW******************************************************************************/
void function_sorting()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Sorting.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Bubble Sort"<<endl<<"2. Insertion Sort"<<endl<<"3. Selection Sort"<<endl<<"4. Merge Sort"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: bubble_sort();break;
			case 2: insertion_sort();break;
			case 3: selection_sort();break;
			case 4: merge_sort();break;
		}
	}
}

void bubble_sort()
{
	int n;
	cout<<"Enter size of array to be sorted"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements of array"<<endl;
	for(int k=0; k<n; k++)
	{
		cin>>a[k];
	}
	
	for (int i = 0; i < n; ++i)
    {
		for (int j = 0; j < n - i - 1; ++j)
     	{
			if (a[j] > a[j + 1])
	    	 {
	        int temp = a[j];
	        a[j] = a[j + 1];
	        a[j + 1] = temp;
	     	 }
  		}
   }
   
   cout<<"Bubble Sorted array is"<<endl;
   for (int i = 0; i < n; ++i)
    {
		cout << a[i] << " ";
	}
	cout<<endl;
}
void insertion_sort()
{
	int n;
	cout<<"Enter size of array to be sorted"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements of array"<<endl;
	for(int k=0; k<n; k++)
	{
		cin>>a[k];
	}
	
	for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
            else
                break;
        }
    }
    cout<<"Insertion sorted array is"<<endl;
    for (int k = 0; k < n; k++)
    {
	cout<<a[k]<<" ";
    }
    cout<<endl;
}

void selection_sort()
{
	int n;
	cout<<"Enter size of array to be sorted"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements of array"<<endl;
	for(int k=0; k<n; k++)
	{
		cin>>a[k];
	}
	
	  int min_ele_loc;
	  for (int i = 0; i < n-1; ++i)
	  {
	    //Find minimum element in the unsorted array
	    //Assume it's the first element
	    min_ele_loc = i;
	 
	    //Loop through the array to find it
	    for (int j = i + 1; j < n; ++j)
	    {
	      if (a[j] < a[min_ele_loc])
	      {
	        //Found new minimum position, if present
	        min_ele_loc = j;
	      }
	    }
	 
	    //Swap the values
	    swap (a[i], a[min_ele_loc]);
	  }	
	cout<<"Selection sorted array is"<<endl;
    for (int k = 0; k < n; k++)
    {
	cout<<a[k]<<" ";
    }
    cout<<endl;
}

void merge_sort()
{
	int n;
	cout<<"Enter size of array to be sorted"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements of array"<<endl;
	for(int k=0; k<n; k++)
	{
		cin>>a[k];
	}
	
	mergesort(a,0,n-1);
	
	cout<<"Selection sorted array is"<<endl;
    for (int k = 0; k < n; k++)
    {
	cout<<a[k]<<" ";
    }
    cout<<endl;
	
}

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

/**********************************************Search FUNCTIONS BELOW******************************************************************************/
void function_searching()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Searching.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Binary Search"<<endl<<"2. Linear Search"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: binary_search();break;
			case 2: linear_search();break;
		}
	}
}

void binary_search()
{
	int n,item;
	cout<<"Enter size of array to be searched"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements in sorted order"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter item to be searched in this array"<<endl;
	cin>>item;
	
	int low = 1, hi = n,mid;
	while(low <= hi)
	{
		mid = low + (hi - low)/2;
		if(a[mid] == item)
		{
			cout<<"Element found at position "<<mid+1<<endl;
			return;
		}
		else if(a[mid] < item)
		{
			low = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	cout<<"Element not in the array"<<endl;
}
void linear_search()
{
	int n,item,flag = 0,pos;
	cout<<"Enter size of array to be searched"<<endl;
	cin>>n;
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements for array"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter item to be searched in this array"<<endl;
	cin>>item;
	
	for(int j = 0; j<n;j++)
	{
		if(a[j] == item)
		{
			flag = 1;
			pos = j+1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"Element not in the array"<<endl;
	}
	else
	{
		cout<<"Element found at position "<<pos<<endl;
	}
}

/**********************************************QUEUE FUNCTIONS BELOW******************************************************************************/
void function_queue()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Circular Queue.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Print"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: insert_queue();break;
			case 2: delete_queue();break;
			case 3: print_queue();break;
		}
	}
}

void insert_queue()
{
	//insertion at rear
	int item;
	cout<<"Enter item to be inserted"<<endl;
	cin>>item;
			if ((front == 0 && rear == MAX-1) || (front == rear+1))
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                if (rear == MAX - 1)
                    rear = 0;
                else
                    rear = rear + 1;
            }
            array_q[rear] = item ;
}
void delete_queue()
{
			//delete from front
			if (front == -1)
            {
                cout<<"Queue is empty already"<<endl;
                return ;
            }
            cout<<"Element deleted from queue is : "<<array_q[front]<<endl;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                if (front == MAX - 1)
                    front = 0;
                else
                    front = front + 1;
            }
}
void print_queue()
{
	int front_pos = front, rear_pos = rear;
            if (front == -1)
            {
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Queue elements :\n";
            if (front_pos <= rear_pos)
            {
                while (front_pos <= rear_pos)
                {
                    cout<<array_q[front_pos]<<"  ";
                    front_pos++;
                }
            }
            else
            {
                while (front_pos <= MAX - 1)
                {
                    cout<<array_q[front_pos]<<"  ";
                    front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                    cout<<array_q[front_pos]<<"  ";
                    front_pos++;
                }
            }
            cout<<endl;
}


/**********************************************LINKEDLIST FUNCTIONS BELOW******************************************************************************/
void function_linkedlist()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Linkedlist.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Singly Linkedlist"<<endl<<"2. Doubly Linkedlist"<<endl<<"3. Circular Linkedlist"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: function_singly_linkedlist();break;
			case 2: function_doubly_linkedlist();break;
			case 3: function_circular_linkedlist();break;
		}
	}
	
}

void function_singly_linkedlist()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Singly Linkedlist"<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Print"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: insert_singly_linkedlist();break;
			case 2: delete_singly_linkedlist();break;
			case 3: print_singly_linkedlist();break;
		}
	}
}
void function_doubly_linkedlist()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen doubly Linkedlist"<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Print"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: insert_doubly_linkedlist();break;
			case 2: delete_doubly_linkedlist();break;
			case 3: print_doubly_linkedlist();break;
		}
	}
}
void function_circular_linkedlist()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen circular Linkedlist"<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Print"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: insert_circular_linkedlist();break;
			case 2: delete_circular_linkedlist();break;
			case 3: print_circular_linkedlist();break;
		}
	}
}

void insert_singly_linkedlist()
{
	//Insert at the end
	int data;
	cout<<"Enter data to be inserted in singly linkedllist"<<endl;
	cin>>data;
	
	struct singly* new_node = new(struct singly);	//Allocate memory for New node 
	if(SINGLY == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	else
	{
		new_node->data = data;
		new_node->next = SINGLY;
	}
	SINGLY = new_node;	
}

void delete_singly_linkedlist()
{
	int pos;
	struct singly* temp;
	temp = SINGLY;
	if(SINGLY == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		cout<<"Enter position of the value to be deleted"<<endl;
		cin>>pos;
		if(pos == 1)
		{
			SINGLY = temp->next;
		}
		else
		{
			while(pos != 0)
			{
				temp = temp->next;
				pos--;
			}
			SINGLY = temp;
		}
	}
	cout<<"Item Deleted"<<endl;
}

void print_singly_linkedlist()
{
	struct singly* temp = SINGLY;
	if(temp == NULL)
	{
		cout<<"Singly Linked List is Empty"<<endl;
	}
	else
	{
		
		while(temp->next != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
}

void insert_doubly_linkedlist()
{
	//Insert at the end
	int data;
	cout<<"Enter data to be inserted in doubly linkedllist"<<endl;
	cin>>data;
	
	struct doubly* new_node = new(struct doubly);	//Allocate memory for New node 
	if(DOUBLY == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;
		DOUBLY = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = DOUBLY;
		DOUBLY->next = new_node;
		DOUBLY = new_node;
	}
}
void delete_doubly_linkedlist()
{
	//SAME AS SINGLY LinkedList
	int pos;
	struct doubly* temp;
	temp = DOUBLY;
	if(DOUBLY == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		cout<<"Enter position till where you want to delete the list"<<endl;
		cin>>pos;
		if(pos == 1)
		{
			DOUBLY = temp->next;
		}
		else
		{
			while(pos != 0)
			{
				temp = temp->prev;
				pos--;
			}
			DOUBLY = temp;
		}
	}
	cout<<"Item Deleted"<<endl;
}

void print_doubly_linkedlist()
{
	//SAME AS SINGLY LinkedList
	struct doubly* temp = DOUBLY;
	if(temp == NULL)
	{
		cout<<"Singly Linked List is Empty"<<endl;
	}
	else
	{
		
		while(temp->prev != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->prev;
		}
		cout<<temp->data<<endl;
	}
}

void insert_circular_linkedlist()
{
	//Insert at the begining
	int data;
	cout<<"Enter data to be inserted in circular linkedllist"<<endl;
	cin>>data;
	
	struct circular* new_node = new(struct circular);	//Allocate memory for New node 
	if(CIRCULAR == NULL)
	{
		cout<<"List is empty"<<endl;
		new_node->data = data;
		new_node->next = new_node;
		CIRCULAR = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = CIRCULAR->next;
		CIRCULAR->next = new_node;
		CIRCULAR = new_node;
	}
}
void delete_circular_linkedlist()
{
	int value;
	cout<<"Enter value to be deleted"<<endl;
	cin>>value;
	struct circular *temp, *s;
	
	s = CIRCULAR->next;
	if(CIRCULAR->next == CIRCULAR && CIRCULAR->data == value)	//Only one element in the list
	{
		temp = CIRCULAR;
		CIRCULAR = NULL;
		free(temp);
		cout<<"Element "<<value;
        cout<<" deleted from the list"<<endl;
		return;
	}
	if(s->data == value) //First element deletion
	{
		temp = s;
		CIRCULAR->next = s->next;
		free(temp);
		cout<<"Element "<<value;
        cout<<" deleted from the list"<<endl;
		return;
	}
	
	//Elements somewhere in between the list
	while(s->next != CIRCULAR)
	{
		if (s->next->data == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
	}
	//Last element deletion
	if (s->next->data == value)    
    {
        temp = s->next;
        s->next = CIRCULAR->next;
        free(temp);		
        CIRCULAR = s;
        cout<<"Element "<<value;
        cout<<" deleted from the list"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
	
}
void print_circular_linkedlist()
{
	struct circular *s;
    if (CIRCULAR == NULL)
    {
        cout<<"CIRCULAR List is empty, nothing to display"<<endl;
        return;
    }
    s = CIRCULAR->next;
    cout<<"Circular Link List: "<<endl;
    while (s != CIRCULAR)
    {
        cout<<s->data<<"-->";
        s = s->next;
    }
    cout<<s->data<<endl;
}

/**************************************************STACK FUNCTIONS BELOW*******************************************************************************/
void function_stack()
{
	int n=1;
	while(n!=0)
	{
		cout<<"You have chosen Stack.."<<endl<<"Next Options are.."<<endl<<"0. Exit"<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Print"<<endl;
		cin>>n;
		switch(n)
		{
			case 0: break;
			case 1: push_stack();break;
			case 2: pop_stack();break;
			case 3: print_stack();break;
		}
	}
}

void push_stack()
{
	
	if(p == 0)                //If the stack size is zero, allow user to mention it at runtime
    {
        cout<<"Stack of zero size"<<endl;
        cout<<"Enter a size for stack : ";
        cin >> length;
        p=new int[length];
    }
    int elem;
    cout<<"Enter element to be pushed..";
    cin>>elem;
    if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        cout<<"\nCannot push "<<elem<<", Stack full"<<endl;
        return;
    }
    else
    {    	
        top++;
        p[top]=elem;		//Push in stack
    }
}

void pop_stack()
{
	if(p==0 || top==-1)
    {
        cout<<"Stack empty!";       
    }
    else
    {
	    int ret=p[top];
    	top--;
    	cout<<"Item popped is "<<ret<<endl;
	}
}

void print_stack()
{
	for(int i = 1; i <= top; i++)
        cout<<p[i]<<" "<<endl;
}

