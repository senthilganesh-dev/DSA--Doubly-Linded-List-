#include<iostream>
#include<stdio.h>
#include <cstdlib>
using namespace std;
static int len_node=0;
class node{  //Node creation.
	public:
	int data;
	node *next,*prev;
	node(int a){
		this->data=a;
		this->next=nullptr;
		this->prev=nullptr;
		
	}
};
//insert function.
void insert(node *&head,node *&tail){ //head parameter.

	int val,i;
	cout<<"Enter the value of element: ";
	cin>>val;

	int inx;
	cout<<"Enter the index: ";
	cin>>inx;
	bool notfound=true;
	node *h_temp=head,*t_temp=tail;
	cout<<h_temp<<"  "<<t_temp<<endl;
	for(i=0;i<len_node;i++){
		
		if(i==inx)
		{
			notfound=false;
			break;
		}
		
		h_temp=h_temp->next;
		
		
					
	}
	if(notfound){
		
	cout<<"Not found 404\n";
		
	}
	
	else{
	cout<<i<<"<="<<len_node<<endl;
	cout<<h_temp<<"  "<<t_temp<<endl;
	node *newnode=new node(val);//creating the new value.
	cout<<"newnode created"<<endl;
	
	newnode->next=h_temp;//link newnode next->indexed node
	cout<<"newnodes->next=indexed data assign  "<<h_temp<<endl;

	
	if(h_temp->prev!=nullptr){
		h_temp->prev->next=newnode; //link between indexed previous node -> newnode
		cout<<"previous index of head updated"<<endl;
	}
	else{
		if(inx==0){
			head=newnode;
			cout<<"Head updated"<<endl;
		}
	}
	newnode->prev=h_temp->prev; //link btw newnode prev->indexed node previous
	h_temp->prev=newnode;
	cout<<"newnodes prev assign"<<endl;
	
	h_temp->prev=newnode;
	printf("newnode val=%x\n",newnode);
	cout<<"Inserted....\n";
}
len_node++;
	return;
	
	
}
//delete function with tail parameter.
void del(node *&head,node *&tail){
	
	
	int val;
	cout<<"Enter the value to delete:";
	cin.ignore();
	cin>>val;
	node *temp=tail;
	while(temp!=nullptr && temp->data!=val){
		temp=temp->prev;
	}
	if(temp==nullptr){
		cout<<"Element not found 404...\n";
		return;
	}
	else{
	if(len_node==1){
		head=nullptr;
		tail=nullptr;
	}
	else if(temp->prev==nullptr){
		
		head->next->prev=nullptr;
		head=head->next;
		
		
	}
	else if(temp->next==nullptr){
		tail->prev->next=nullptr;
		tail=tail->prev;
			
		
	}
	else{
	
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
}
	
	cout<<"Deleted..."<<endl;
	len_node--;
}
	return;
}
void append(node *&tail){
	int val;
	cout<<"Enter the data to append:";
	cin>>val;
	node *newnode=new node(val);
	newnode->prev=tail;
	newnode->next=tail->next;
	tail->next=newnode;
	tail=newnode;
	len_node++;
	return;
}
void extend(node *&tail){
	int n;
	cout<<"Enter the data size:";
	cin>>n;
	len_node+=n;
	int val;
	cout<<"Enter the datas:"<<endl;
	for(int i=0;i<n;i++){
		cin>>val;
		node *newnode=new node(val);
		newnode->prev=tail;

		tail->next=newnode;
		tail=newnode;
	}
	
}
int main(){
	create: //creation 
	int n;
	cout<<"Limit:";
	cin>>n;
	len_node=n;

	
	int val;
	node *head=nullptr,*tail=nullptr; //head and tail instialisation.
	for(int i=0;i<n;i++){  
		cin>>val;
		if(head==nullptr && tail==nullptr){  //checking for first enterance.
			head=new node(val);
			tail=head;
			continue;
		}
		tail->next=new node(val);
		tail->next->prev=tail;
		tail=tail->next;
	}
	//cout<<sizeof(node)<<" "<<sizeof(head->next)<<" "<<sizeof(head->data)<<endl;
	char con='y';
	while(con!='n'){
		printf("Value of head=%p  Value of tail=%p\n",head,tail);
		printf("Node length =%d\n",len_node);
	//Insert and deletion operations
	cout<<"1.Insert\n2.Delete\n3.Append\n4.Extend\n\n";
	cin.ignore();
	int ch;
	cout<<"Choice?";
	cin>>ch;
	switch(ch){
		case 1:
			insert(head,tail);
			break;
		case 2:
			del(head,tail);
			
			break;
			
		case 3:
			append(tail);
			break;
		case 4:
			extend(tail);
			break;
		default:
			;
	}

	if(len_node==0){
		cout<<"Empty list.."<<endl;
		cout<<"create a new list"<<endl;
		goto create;
	}
	
  cout << "\nDisplay Forward...\n";
    node *h_temp=head;
    while (h_temp != nullptr) {
        cout << h_temp->data <<" ";
        h_temp = h_temp->next;
    }

    cout << "\nDisplay Reverse...\n";
    printf("tail val=%x\n",tail);
    node *t_temp=tail;
    while (t_temp != nullptr) {
        cout << t_temp->data <<" ";
        t_temp = t_temp->prev;
    }
	
    cout << "\n\nContinue? (y/n): ";
    cin >> con;

}
	return 0;
}