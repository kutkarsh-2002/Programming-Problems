// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
static bool cmp(Node* a, Node* b){
    return a->data<b->data;
}
Node *flatten(Node *root)
{
   // Your code here
   
   vector<Node*>v;
   Node* curr=root;
   
   while(curr!=NULL){
       v.push_back(curr);
       Node* temp=curr;
       
       if(temp->bottom!=NULL){
           temp=temp->bottom;
           while(temp!=NULL){
               v.push_back(temp);
               temp=temp->bottom;
           }
       }
       
       curr=curr->next;
   }
   
   sort(v.begin(), v.end(), cmp);
   //cout<<v.size()<<endl;
   
   Node *tail=NULL;
   root=NULL;
   
   for(int i=0; i<v.size(); i++){
       //Node* temp=new Node(v[i]);
       Node* temp=v[i];
       if(root==NULL){
           root=temp;
           tail=root;
       }
       else{
           tail->bottom=temp;
           tail=tail->bottom;
       }
   }
   
   tail->next=NULL;
   return root;
}

