#include<stdio.h>
#include<stdlib.h>

struct nodeLL{
	int val;
	struct nodeLL *prev, *next;
};
struct node{
	struct node *left , *right, *parent;
	struct nodeLL *num;
};

struct nodeLL* createLL(struct nodeLL* b , int k){//Creates Linked list
	if(b == NULL){
		struct nodeLL *temp = (struct nodeLL*)malloc(sizeof(struct nodeLL));
		temp ->val = k;
		temp -> prev = NULL;
		temp -> next = NULL;
		b = temp;
		
	}
	else{
		struct nodeLL *ref = b;
		struct nodeLL *g = (struct nodeLL*)malloc(sizeof(struct nodeLL));
		while(ref -> next!=NULL){
			ref = ref ->next;
		}
			g ->val = k;
			g ->prev = ref;
			ref ->next = g;
			g ->next = NULL;
		}
		return b;
	}
int compareLL(struct nodeLL* f, struct nodeLL* s){
	struct nodeLL* g = f;
	struct nodeLL* h = s;
    struct nodeLL *temp1, *temp2;
	int c1,c2;
	c1=c2=0;
	while(g!=NULL){    //To check which number is greater in number
		c1= c1 + 1;
		g= g->next;
	}
	while(h!=NULL){
		c2 = c2+1;
		h = h->next;
	}
	if(c1>c2){
		return 2;
	}
	else if(c1<c2){
		return 1;
	}
	else if(c1 == c2){ //I compared each value from units place.
		g = f;
		h = s;
		while(g!=NULL){
			if(g->val > h->val){
				return 2;
			}
			else if(g->val<h->val){
				return 1;
			}
			else{
                temp1 = g;
                temp2 = h;
                g = g->next;
				h = h->next;
				continue;
			}
		}
	    return 0;  
                
		
	}
}	


struct node* insertBST(struct node* a, struct node* b){
	int i;
	if(a == NULL){ // Base case
		a = b;
		return a;
	}
	else{
		i = compareLL(a->num,b->num);
		
		if(i == 1){ // If value is more it goes to right sub tree
			b->parent = a;
			a -> right = insertBST(a->right,b);			
					
		}
		else if(i== 2){
			b->parent = a;
			a ->left = insertBST(a->left,b);
		}
		else{
			return a;
		}
		
	}
}
struct node* createnode(struct node* root, struct nodeLL* key){ //To create a node with value key, head of the linked list of the number
	struct node* a = (struct node*)malloc(sizeof(struct node));
	a->num = key;
	a->parent = a->left = a -> right = NULL;
	return a;
}
void printLL(struct nodeLL* u){
	struct nodeLL *t = u;
	while(t!=NULL){
		printf("%d",t->val);
		t = t->next;
	}
}
struct nodeLL* deleteLL(struct nodeLL* b){
	while(b!=NULL){
	struct nodeLL * d = b->next;
	free(b);
	b = d;
		
	}
	return b;
	
}

struct node* deleteT(struct node* t){
	while(t!=NULL){
	struct node *l,*r;
	l = t->left;
	r = t->right;
	free(t);
	deleteT(l);
	deleteT(r);
	}
	return t;
}
struct nodeLL* s = NULL;
struct node* Search(struct node* t, struct nodeLL* k){
	int i;
	struct node* r = t;
	
	if(r == NULL){
		printf("%d\n", -1); //Tree is empty
		s = deleteLL(s);
		return r;
	}
	else if(k ==NULL){
		printf("No values to compare");
	}
	else{
		i = compareLL(r->num,k);// I compared an element with each node starting from root.If found, return the value.
		if(i == 0){
			return r;
		}
		else if(i == 1){ // If node value is lesser, search right sub tree
			s = createLL(s,1);
			Search(r->right,k);
		}
		else if (i == 2){ // Else left sub tree
			s = createLL(s,0);
			Search(r->left,k);
		}
	}
	
}


void preorderT(struct node* root){
	if(root!=NULL){
	
	printLL(root->num);
	printf(" ");
	preorderT(root->left);
	printf(" ");
	preorderT(root->right);
	}
	
}

struct node* successor(struct node* n,struct nodeLL* k){
  
    if(n == NULL || k == NULL){
        return NULL;
    }
    int i;
    struct node* r = n;
    i = compareLL(r->num,k);
    if(i == 0 || i == 1){
        if(r->right != NULL){
            return successor(r->right,k);
        }
        else if(r->right == NULL){
            struct node* t = r;
            struct node* z = r->parent;
            while(t != z->left){
                t = z;
                z = t->parent;
                if(z == NULL){
                    printf("-1");
                    return z;
                }
                else{
                    continue;
                }

        }
    	return z;
        }
    }
    else if(i == 2){
        if(r->left == NULL){
            return r;
        }
        else{
            return successor(r->left,k);
        } 
    } 
}
void deleteN(struct node* n,struct nodeLL* k){
    if(n == NULL || k == NULL){
        return;
    }
    int i;
    struct node* r = n;
    i = compareLL(r->num,k);
    if(i == 1){
        deleteN(r->right,k);
    }
    else if(i == 2){
        deleteN(r->left,k);
    }
    else if(i == 0){
        struct node* z = r->parent;
        if(r->right == NULL){
            if(r->left != NULL){
                r->left->parent = z;
            }
            if(z->left == r){
                z->left = r->left;
            }
            else{
                z->right = r->left;
            }
            free(r);
        }
        else if(r->left == NULL){
            if(r->right != NULL){
                r->right->parent = z;
            }
            if(z->left == r){
                z->left = r->right;
            }
            else{
                z->right = r->right;
            }
            free(r);
        }
        else{
            struct node* p = successor(r,r->num);
            r->num = p->num;
            deleteN(p,p->num);
        }
    }
}
struct node* Uncle(struct node* root,struct node* k){
	if(k->parent != NULL && k->parent != root){// Where uncle exist.
		struct node* p = k->parent; 
		if(p->parent->left == p){//if parent is on left
			p = p->parent->right; // Uncle will be at right
			if(p!= NULL){
				printLL(p->num);
			}
			else{
				printf("-1\n");
			}
		}
		else{
			p=p->parent->left;
			if(p!= NULL){
				printLL(p->num);
			}
			else{
				printf("-1\n");
			}
		}
	}
	else{
		printf("-1\n");
	}
}
struct node* Left_rotate(struct node* root,struct node* k){//Considering X as our node.
	if(k != NULL){// If node exist
		if(k->right != NULL){// If right child exist, only then it is possible to left rotate.
			struct node* temp = k->right;//Y is right of X
			struct node* temp2 = temp->left;//Z is left of Y
			struct node* p = k->parent;//P is parent of X
			temp->left = k;//left of Y->X
			k->right = temp2;//right of X->Z
			temp->parent = p;//parent of Y->P
			k->parent = temp;//parent of X->Y
			if(temp2 != NULL){
				temp2->parent = k;//If Z exists, parent of Z->X
			}
			if(p!=NULL){//parent of X exists
				if(p->left == k){//if X is left child of P
					p->left = temp;
				}
				else if(p->right == k){
					p->right = temp;
				}
			}
			else if(p == NULL){//P is NULL
				root = temp;//root->Y
			}
			
		}
		return root;
	}
	else{
		return root;
	}
}
struct node* Right_rotate(struct node* root,struct node* k){
	if(k != NULL){
		if(k->left != NULL){
			struct node* temp = k->left;
			struct node* temp2 = temp->right;
			struct node* p = k->parent;
			temp->right = k;
			k->left = temp2;
			temp->parent = p;
			k->parent = temp;
			if(temp2 != NULL){
				temp->parent = k;
			}
			if(p!=NULL){
				if(p->right == k){
					p->right = temp;
				}
				else if(p->left == k){
					p->left = temp;
				}
			}
			else if(p == NULL){
				root = temp;
			}
			
		}
		return root;
	}
	else{
		return root;
	}
}
        
        

int main(){
	struct node* root = NULL;
	int digit,z;
	struct nodeLL* p = NULL;
	while((digit = fgetc(stdin))!= EOF){
		int j = 0;
		int  c = 0;
		if(digit == 'N' || digit == 'B'){//Since pre order traversal of a BST is unique.
			root = NULL;
			struct nodeLL *t = NULL;
			struct node* a = NULL;
			int l = 0;
			while((digit = fgetc(stdin))!='\n'){
				
				if(digit == ' ' ){
					a = createnode(a,t);
					root = insertBST(root,a);
					t = NULL;
					j = 0;
					
					continue;
				}
				else{
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
					t = createLL(t,z);
					j = 1;
					l = 1;
					continue;
					}
				}
				
				
			}
			a = createnode(a,t);
			root = insertBST(root,a);
			continue;
		}
		else if(digit == 'S'){
			
			while((digit = fgetc(stdin)) != '\n'){
				if(digit == ' '){
					p = deleteLL(p);
					c = 0;
					//printf("%p",p);
					continue;
				}
				else{
					z = digit - 48;
					if(z == 0 && c == 0){
						continue;
					}
					else{
					p = createLL(p,z);
					c = 1;
					continue;
					}
				}
				
			}
			struct node* t = Search(root,p);
			if(t != NULL){
				struct nodeLL* m = s->next;
				printLL(m);
				printf("\n");
				s = deleteLL(s);
			}
			continue;
			
		}
		else if(digit == 'P'){
			preorderT(root);
			continue;
		}
	 	else if(digit == '+'){
				struct nodeLL *add = NULL;
				struct node* a = NULL;
				j=0;			
				while((digit = fgetc(stdin))!='\n'){
					if(digit == ' '){
						add = deleteLL(add);
						j=0;						
						continue;
					}
					else{					
						z = digit - 48;
						if(z==0 && j == 0){
							continue;
						}
						else{
						add = createLL(add,z);
						j = 1;
						continue;
						}
					}	
				}
			a = createnode(a,add);
			root = insertBST(root,a);
		}
		else if(digit == '>'){
                        struct nodeLL *sc = NULL;
			struct node* a = NULL;
			j=0;			
			while((digit = fgetc(stdin))!='\n'){
				if(digit == ' '){
					sc = deleteLL(sc);
					j=0;						
					continue;
				}
				else{					
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
                    	sc = createLL(sc,z);
                    	j = 1;
                        continue;
					}
				}	
			}
            struct node* h = successor(root,sc);
            if(h != NULL){
            printLL(h->num);
               }
            }
                        
                    
		else if(digit == '-'){
		
            struct nodeLL *del = NULL;
        	struct node* a = NULL;
            j=0;
            while((digit = fgetc(stdin))!='\n'){
                if(digit == ' '){
                    del = deleteLL(del);
                    j=0;
                    continue;
                }
                else{
                    z = digit - 48;
          	        if(z == 0 && j == 0){
                       continue;
                	}
                	else{
                        del = createLL(del,z);
                        j=1;
                        continue;
                    }
                }
            }
            deleteN(root,del);
        }
		else if(digit == 'C'){
			struct nodeLL *t = NULL;
			struct node* a = NULL;
			j=0;
			while((digit = fgetc(stdin))!= '\n'){
				if(digit == ' '){
					t = deleteLL(t);
					j=0;
					continue;
				}
				else{
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
						t = createLL(t,z);
						j = 1;
					}
				}
			}
			a = Search(root,t);
			if(a->left == NULL){
				printf("Nil");
				
			}
			else{
				printLL(a->left->num);
			}
			printf(" ");
			if(a->right == NULL){
				printf("Nil");
			}
			else{
				printLL(a->right->num);
			}
			
		}
		else if(digit == 'U'){
			struct nodeLL *t = NULL;
			struct node* a = NULL;
			j=0;
			while((digit = fgetc(stdin))!= '\n'){
				if(digit == ' '){
					t = deleteLL(t);
					j=0;
					continue;
				}
				else{
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
						t = createLL(t,z);
						j = 1;
					}
				}
			}
			a = Search(root,t);
			s = deleteLL(s);
			Uncle(root,a);
			
		}
		else if(digit == 'L'){
			struct nodeLL *t = NULL;
			struct node* a = NULL;
			j=0;
			while((digit = fgetc(stdin))!= '\n'){
				if(digit == ' '){
					t = deleteLL(t);
					j=0;
					continue;
				}
				else{
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
						t = createLL(t,z);
						j = 1;
					}
				}
			}
			a = Search(root->right,t);
			s = deleteLL(s);
			root = Left_rotate(root,a);
		}
		else if(digit == 'R'){
			struct nodeLL *t = NULL;
			struct node* a = NULL;
			j=0;
			while((digit = fgetc(stdin))!= '\n'){
				if(digit == ' '){
					t = deleteLL(t);
					j=0;
					continue;
				}
				else{
					z = digit - 48;
					if(z==0 && j == 0){
						continue;
					}
					else{
						t = createLL(t,z);
						j = 1;
					}
				}
			}
			a = Search(root,t);
			s = deleteLL(s);
			root = Right_rotate(root,a);
		}
	}
	printf("\n");
	return 9;
}

