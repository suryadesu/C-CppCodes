//code to implement red black trees
#include<bits/stdc++.h>
using namespace std;
struct node{//structure of nodes of red black trees
    long int val;
    bool isred;
    struct node* left;
    struct node* right;
    struct node* parent;
};
struct node* Nil;//sentinal node
void createNil();
struct node* createnode(long int d);
struct node* insertRBT(struct node* root,struct node* n);
struct node* Successor(struct node* root,long int key);
struct node* Predecessor(struct node* root,long int key);
struct node* Search(struct node*root,long int key,bool ch,vector<int>&path);
void printC(struct node* loc);
void preorderT(struct node* root);
struct node* deleteN(struct node* root,struct node* node);
struct node* deleteT(struct node* t);
int main(){
    createNil();
    int digit;
    struct node* root = Nil;
    long int t;
    vector<int>path;
    while((digit = fgetc(stdin))!=EOF){
        if(digit == 'N'){
            root = deleteT(root);
            while((digit = fgetc(stdin))!='\n'){
                fscanf(stdin,"%ld",&t);
                struct node* temp = createnode(t);
                root = insertRBT(root,temp);
            }
        }
        else if(digit == '+'){
            fscanf(stdin,"%ld",&t);
            struct node* temp = createnode(t);
            root = insertRBT(root,temp);
        }
        else if(digit == '<'){
            fscanf(stdin,"%ld",&t);
            struct node* res = Predecessor(root,t);
            if(res!=Nil){
                cout<<res->val<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(digit == '>'){
            fscanf(stdin,"%ld",&t);
            struct node* res = Successor(root,t);
            if(res!=Nil){
                cout<<res->val<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(digit == 'S'){
            fscanf(stdin,"%ld",&t);
            Search(root,t,true,path);
        }
        else if(digit == 'C'){
            fscanf(stdin,"%ld",&t);
            struct node* loc = Search(root,t,false,path);
            printC(loc->left);
            cout<<" ";
            printC(loc->right);
            cout<<"\n";
        }
        else if(digit == 'P'){
            preorderT(root);
            cout<<"\n";
        }
        else if(digit == '-'){
            fscanf(stdin,"%ld",&t);
            struct node* n = Search(root,t,false,path);
            if(n!=Nil){
                root = deleteN(root,n);
            }
        }
    }
    cout<<"\n";
    return 9;
}
void createNil(){
    Nil = (struct node*)malloc(sizeof(struct node));
    Nil->isred = false;
    Nil->parent = Nil;
    Nil->left = Nil->right = Nil;    
}
struct node* createnode(long int d){
	struct node* a = (struct node*)malloc(sizeof(struct node));
	a->val = d;
    a->isred = true;//initially red colored nodes are created
	a->parent = a->left = a -> right = Nil;
	return a;
}
struct node* Uncle(struct node* n){//To find the uncle of a node
    struct node* temp = n->parent->parent;
    if(temp->left == n->parent){
        return temp->right;
    }
    else if(temp->right == n->parent){
        return temp->left;
    }
    return Nil;
}
void recolor(struct node* n){
    if(n->isred){
        n->isred = false;
    }
    else{
        n->isred = true;
    }
}
struct node* Leftrotate(struct node* root,struct node* k){//Considering X as our node.
	if(k != Nil){// If node exist
		if(k->right != Nil){// If right child exist, only then it is possible to left rotate.
			struct node* temp = k->right;//Y is right of X
			struct node* temp2 = temp->left;//Z is left of Y
			struct node* p = k->parent;//P is parent of X
			temp->left = k;//left of Y->X
			k->right = temp2;//right of X->Z
			temp->parent = p;//parent of Y->P
			k->parent = temp;//parent of X->Y
			if(temp2 != Nil){
				temp2->parent = k;//If Z exists, parent of Z->X
			}
			if(p!=Nil){//parent of X exists
				if(p->left == k){//if X is left child of P
					p->left = temp;
				}
				else if(p->right == k){
					p->right = temp;
				}
			}
			else if(p == Nil){//P is Nil
				root = temp;//root->Y
			}
			
		}
		return root;
	}
	else{
		return root;
	}
}
struct node* Rightrotate(struct node* root,struct node* k){
	if(k != Nil){
		if(k->left != Nil){
			struct node* temp = k->left;
			struct node* temp2 = temp->right;
			struct node* p = k->parent;
			temp->right = k;
			k->left = temp2;
			temp->parent = p;
			k->parent = temp;
			if(temp2 != Nil){
				temp->parent = k;
			}
			if(p!=Nil){
				if(p->right == k){
					p->right = temp;
				}
				else if(p->left == k){
					p->left = temp;
				}
			}
			else if(p == Nil){
				root = temp;
			}
			
		}
		return root;
	}
	else{
		return root;
	}
}
struct node* insertBST(struct node** root,struct node* n){
    if(*root == Nil){
        *root = n;
        return n;
    }
    else{
        if((*root) -> val < n->val){
            (*root)->right = insertBST(&(*root)->right,n);
            (*root)->right->parent = *root;
        }
        else if((*root)->val > n->val){
            (*root)->left = insertBST(&(*root)->left,n);
            (*root)->left->parent = *root;
        }
    }
    return *root;
}
void Fixinsert(struct node** root,struct node* n){
    struct node* par = n->parent;
    struct node* grandparent = par->parent;
    while(par->isred){
        struct node* uncle = Uncle(n);
        if(uncle->isred){//If parent and uncle are red, implies grandparent is black 
            recolor(par);
            recolor(grandparent);
            recolor(uncle);//parent,uncle,grandparent are recolored so that from grandparent of the node, everything satisfies red black tree properties
            n = grandparent;//Since color of grandparent is changed to red, Fixinsert is called on grandparent
        }
        else{//If uncle of node is black,if above procedure is followed, then black height may not be the same on either side of grandparent
            if(par == grandparent->left){//Hence rotation needs to be done
                if(n == par->right){//Left right case
                    n = par;
                    *root = Leftrotate(*root,n);//converted to left,left case
                }
                else{
                    recolor(par);//Parent colored black, grandparent red
                    recolor(grandparent);
                    *root = Rightrotate(*root,grandparent);//then right rotate at grandparent will result in a red black tree
                    break;
                }
            }
            else{
                if(n == par->left){//Symmetric case
                    n = par;
                    *root = Rightrotate(*root,n);
                }
                else{
                    recolor(par);
                    recolor(grandparent);
                    *root = Leftrotate(*root,grandparent);
                    break;
                }
            }
        }
        par = n->parent;
        grandparent = par->parent;
    }
    (*root)->isred = false;
}
struct node* insertRBT(struct node* root,struct node* n){
    root = insertBST(&root,n);//Node is first inserted as in a BST
    Fixinsert(&root,n);//Then Fixinsert is called on the node inserted to satisfy the properties of a red black tree
    return root;
}
struct node* Successor(struct node* root,long int key){
    if(root == Nil){
        return Nil;
    }
    struct node* r = root;
    if(key>=r->val){
        if(r->right !=Nil){
            return Successor(r->right,key);
        }
        else{
            struct node* t = r;
            struct node* z = r->parent;
            while(t != z->left){
                t = z;
                z = t->parent;
                if(z == Nil){
                    return z;
                }
            }
            return z;
        }
    }
    else{
        if(r->left == Nil){
            return r;
        }
        else{
            return Successor(r->left,key);
        } 
    } 
}
struct node* Predecessor(struct node* root,long int key){
    if(root == Nil){
        return Nil;
    }
    struct node* r = root;
    if(key<=r->val){
        if(r->left !=Nil){
            return Predecessor(r->left,key);
        }
        else{
            struct node* t = r;
            struct node* z = r->parent;
            while(t != z->right){
                t = z;
                z = t->parent;
                if(z == Nil){
                    return z;
                }
            }
            return z;
        }
    }
    else{
        if(r->right == Nil){
            return r;
        }
        else{
            return Predecessor(r->right,key);
        } 
    } 
}
struct node* Search(struct node* root,long int key,bool ch,vector<int>&path){
    struct node* r = root;
	if(r == Nil){
		cout<<"-1\n";
        path.clear();
        return r;
	}
	else{
		if(root->val == key){
            if(ch){//in case of search,path is needed to be printed, while in other places of the code it need not be printed
			    if(!path.empty()){//Hence ch value is used to decide if path needs to be printed
                    for(auto it = path.begin();it!=path.end();++it){
                        cout<<*it;
                    }
                }
                if(root->isred){
                    cout<<" "<<"R\n";
                }
                else{
                    cout<<" "<<"B\n";
                }
            }
            path.clear();
            return root;   
		}
		else if(key>root->val){
            path.push_back(1);//1 indicates right and 0 indicates left
			Search(r->right,key,ch,path);
		}
		else{
            path.push_back(0);
			Search(r->left,key,ch,path);
		}
	}
}
void printC(struct node* loc){//To print the children of nodes
    if(loc == Nil){
        cout<<"L B";
    }
    else{
        cout<<loc->val<<" ";
        if(loc->isred){
            cout<<"R";
        }
        else{
            cout<<"B";
        }
    }
}
struct node* sibling(struct node* n){//To access the sibling of a node of the tree
    struct node* p = n->parent;
    if(p!=Nil){
        if(p->left == n){
            return p->right;
        }
        else{
            return p->left;
        }
    }
}
void preorderT(struct node* root){
	if(root!=Nil){
        cout<<root->val<<" ";
        preorderT(root->left);
        preorderT(root->right);
	}
}
void splice(struct node** root,struct node* a,struct node* b){
    struct node* p = a->parent;
    if(p!=Nil){
        if(p->left == a){
            p->left = b;
        }
        else{
            p->right = b;
        }
    }
    else{
        *root = b;
    }
    if(b !=Nil){
        b->parent = p;
    }
}
void Fixtoken(struct node** root,struct node* n,struct node* s){//Fixtoken implies that the node n has a black token on it
    if(n->isred){//if it is red, token is dissolved into the node
        n->isred = false;//n becomes black
    }
    else{//else it depends on the sibling of n to fix the token
        struct node* p = n->parent;
        if(s->isred){//This results in a case where sibling has two black children,which is fixed below
            recolor(s);
            recolor(p);
            if(p->right == s){
                *root = Leftrotate(*root,p);
            }
            else{
                *root = Rightrotate(*root,p);
            }
            Fixtoken(root,n,s);
        }
        else{
            if(!(s->left->isred) && !(s->right->isred)){//If sibling has two black children and sibling is also black
                recolor(s);
                p->isred = false;//blackness of both sibling and the node is transferred to parent
            }
            else if(s->left->isred){//s has left child red while black right child
                recolor(s);//this case is converted to the case, s has left black and right red
                recolor(s->left);
                *root = Rightrotate(*root,s);
                Fixtoken(root,n,s);
            }
            else{
                recolor(s->right);//right of s is colored black
                s->isred = p->isred;//s inherits the color of parent
                p->isred = false;//Left rotate at parent will fix the issue as s goes to parents place, extra black height
                *root = Leftrotate(*root,p);//is given by coloring parent black and pushing it into its left subtree
                (*root)->isred = false;//and token transferred to root
            }
        }
    }
}
struct node* deleteN(struct node* root,struct node* node){
    if(node->left != Nil && node->right != Nil){//If the node has two children, then its value is replaced by its predecessor and then predecessor is deleted
        struct node* temp = Predecessor(root,node->val);
        node->val = temp->val;
        deleteN(root,temp);
    }
    else{
        struct node* child;
        if(node->left != Nil){
            child = node->left;
        }
        else{
            child = node->right;
        }
        struct node* s = sibling(node);
        splice(&root,node,child);//node is removed from the tree
        free(node);//then the memory is cleared
        if(child != Nil){
            Fixtoken(&root,child,s);
        }
    }
    return root;
}
struct node* deleteT(struct node* t){//to delete the whole tree
	if(t!=Nil){
        struct node *l,*r;
        l = t->left;
        r = t->right;
        free(t);
        deleteT(l);
        deleteT(r);
	}
	return Nil;
}