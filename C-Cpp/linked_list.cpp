#include<bits/stdc++.h>
struct node{
	int v;
	struct node* ptr;
};
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* head3 = NULL;
int l=0;

void insert(int a,int list){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if(list == 1){
		if(head1 == NULL){
		p -> v = a;
		p -> ptr = head1;
		head1 = p;
	}
	else{
		struct node* temp = head1;
		struct node* q = temp;
		while(temp!=NULL){
			q = temp;
			temp = temp ->ptr;
		}
		p -> v = a;
		q -> ptr = p;
		p -> ptr = NULL;
	}
	}
	else if (list==2){
		if(head2 == NULL){
		p -> v = a;
		p -> ptr = head2;
		head2 = p;
	}
	else{
		struct node* temp = head2;
		struct node* q = temp;
		while(temp!=NULL){
			q = temp;
			temp = temp ->ptr;
		}
		p -> v = a;
		q -> ptr = p;
		p -> ptr = NULL;
	}
	}
	else{
		if(head3 == NULL){
		p -> v = a;
		p -> ptr = head3;
		head3 = p;
	    }
	    else{
		struct node* temp = head3;
		struct node* q = temp;
		while(temp!=NULL){
			q = temp;
			temp = temp ->ptr;
		}
		p -> v = a;
		q -> ptr = p;
		p -> ptr = NULL;
	}
	
	}
}
void intersection(){
	if(head1 == NULL || head2 == NULL){
		printf("One of the lists is empty, final linked list is empty\n");
	}
	else{
		int k;
		struct node* i = head1;
		struct node* j = head2;
		while( i!= NULL && j != NULL){
			struct node* c = j;
			while(c != NULL){
				if(i->v == c->v){
				k = i ->v;
				insert(k,3);	
				i = i->ptr;
				j = c->ptr;
				break;
				}
				else{
					c = c->ptr;
					
				}
				i = i->ptr;
				j = j->ptr;
			}
			
			
			}
			}
}
void traverse(struct node* g){
	struct node* u = g;
	int f;
	if(g == NULL){
		printf("The list is empty\n");
		
	}
	else{
		while(u != NULL){
		f = u->v;
		printf("The value is:%d\n",f);
		printf("The address of the node is:%p\n",u);
		u = u ->ptr;
	    }
	}
}
void deleteLL(struct node* head){
	struct node*p = head;
	
	while(p!=NULL){
	struct node*q = p-> ptr;
	free(p);
	p = q;	
	}	
}
int main(){
	int n,b;
	
	printf("Enter the number of values of first linked lsit:\n");
	scanf("%d",&n);
	l = n;
	printf("Enter the values:\n");
	while(n>0){
	scanf("%d",&b);
	insert(b,1);
	n--;
    }
    printf("Enter the number of values of second linked list:\n");
    scanf("%d",&n);
    printf("Enter the values:\n");
    
	while(n>0){
    	scanf("%d",&b);
    	insert(b,2);
    	n--;
	}
	intersection();
	traverse(head1);
	traverse(head2);
	traverse(head3);
	
	deleteLL(head1);
	deleteLL(head2);
	deleteLL(head3);
	return 9;



}	
