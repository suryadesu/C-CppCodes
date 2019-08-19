#include<bits/stdc++.h>
using namespace std;
struct node{ //stored adjacency list of vertices,weights as a linked list
    int v;
    int w;
    struct node* next;
};

struct vertex{
    int its;
    struct node* val;
    long int dist;
    int p;
};
class Minq{//Class for priority queue
    int top = -1;//top points to recently added element
    vector<struct vertex>v;//v is the priority queue
    public:
        void insert(struct vertex r){
            v.push_back(r);//r is added to last position of the queue
            top++;      //index 0 contains the first element of the queue    
            heapify(top);//then heapify is called from the bottom
        }
        bool empty(){
            return v.empty();
        }
        void heapify(int t){
            if(!v.empty()){
                int root;
                int temp = t;
                while(temp != 0){
                    if(temp%2 == 0){
                        if(v[temp-1].dist > v[temp].dist){
                            struct vertex b = v[temp-1];//If left child is more than the right child,they are swapped
                            v[temp-1] = v[temp];
                            v[temp] = b;
                        }
                        temp--;
                    }
                    else{
                        root = temp/2;//root is the position of parent of temp
                        if(v[temp].dist<v[root].dist){//Priority queue is made using distance as the key
                            struct vertex f = v[temp];//If child's key value is more than the parent they are swapped
                            v[temp] = v[root];
                            v[root] = f;
                        }
                    temp--;
                    }
                }
            }
        }
        struct vertex pop(){
            struct vertex r = v.front();
            v.erase(v.begin());//Elements are removed from the front of the priority queue
            top-=1;
            return r;
        }
        void decrease_key(int n,long int key){
            for(int i = 0;i<=top;i++){
                if(v[i].its == n){
                    v[i].dist = key; //Since key value is the distance 
                }
            }
            heapify(top);           
        }
};
struct node* createLL(struct node* b , int k,int f){
	if(b == NULL){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp ->v = k;
        temp->w = f;
		temp -> next = NULL;
		b = temp;
		
	}
	else{
		struct node *ref = b;
		struct node *g = (struct node*)malloc(sizeof(struct node));
		while(ref -> next!=NULL){
			ref = ref ->next;
		}
			g ->v = k;
            g->w = f;
			ref ->next = g;
			g ->next = NULL;
		}
		return b;
}
int Search(struct node* r,int g){
    struct node* temp = r;
    while(temp!=NULL){
        if(temp->v == g){
            return temp->w;
        }
        else{
            temp = temp->next;
            continue;
        }
    }
    return -1;
}   
void dijkstra(struct vertex a[],int n,int r,vector<int> &q){
    q.clear();
    a[r].dist = 0;
    Minq pq;
    for(int i=1;i<n+1;i++){
        pq.insert(a[i]);//priority queue is initialized with all the vertices.
    }
    while(!pq.empty()){//Visited vertices are pushed to the queue and distances of all the vertices adjacent to the vertex are updated if they can be reached by a shorter path. 
        struct vertex u = pq.pop();
        int k = u.its;
        q.push_back(k);
        q.push_back(a[k].dist);
        struct node* h = a[k].val;
        while(h!=NULL){
            int ve = h->v;
            if(a[k].dist + h->w < a[ve].dist){
                a[ve].dist = a[k].dist + h->w;
                pq.decrease_key(ve,a[ve].dist);
                a[ve].p = k;
            }
            h = h->next;
        }
    }
}
int main(){
    int digit,k,i,t;
    int n = 0;
    digit = fgetc(stdin);
    while(digit != EOF){
        if(digit == 'N'){
            fscanf(stdin,"%d",&n); // n stores the cardinality of vertex set
        }
        struct vertex arr[n+1]; //Array of vertices, indexing starting from 1.
        for(int j = 1;j<n+1;j++){    
            arr[j].its = j;
            arr[j].dist = n*1000000;//Initializing the vertices values.Assuming n*1000000 to be infinity
            arr[j].p = 0;
            arr[j].val = NULL;
        }
        vector<int>result; // this stores the result of dijkstra of a vertex
        while((digit = fgetc(stdin))!= 'N' && digit != EOF){
            if(digit == 'E'){
                fscanf(stdin,"%d",&k);
                struct node* h = NULL;
                while((digit = fgetc(stdin))!='\n'){
                    fscanf(stdin,"%d %d",&i,&t);
                    h = createLL(h,i,t);
                }
                arr[k].val = h; // Storing the adjaceny list 
            }
            if(digit == '?'){
                int a,b;
                fscanf(stdin,"%d %d",&a,&b);
                int t = Search(arr[a].val,b);//(u,v) edge exists if adjacency list of u has the vertex v. Here adjacency list of vertex a is searched for b 
                cout<<t<<"\n";
            }
            if(digit == 'D'){
                for(int j = 1;j<=n;j++){ 
                    arr[j].dist = n*1000000;
                    arr[j].p = 0;
                }
                int s;
                fscanf(stdin,"%d",&s);
                dijkstra(arr,n,s,result); // result consists the list of numbers in the order they are visited in bfs.
                int h = 0;
                for(auto it = result.begin();it!=result.end();++it){
                    if(h%2 == 0){
                        cout<<*it<<" ";
                    }
                    else{
                        if(*it == n*1000000){
                            cout<<"-1";
                        }
                        else{
                            cout<<*it;
                        }
                        cout<<"\n";
                    }
                    h++;
                }
            }
            if(digit == 'P'){
                int a,b;
                vector<int>path;
                fscanf(stdin,"%d %d",&a,&b);
                if(arr[a].dist != 0){
                    for(int j = 1;j<n+1;j++){
                        arr[j].dist = n*1000000;
                        arr[j].p = 0;
                    }
                    dijkstra(arr,n,a,result);
                }
                int tr = 0;
                for(int j=0;j<2*n;j+=2){
                    if(result.at(j)== b){
                        tr = 1;
                    }
                }
                if(tr == 0){
                    cout<<"-1\n";
                }
                else{
                    int pa;
                    long int d;
                    d = arr[b].dist;
                    pa = arr[b].p;
                    if(d == n*1000000){
                        cout<<"-1";
                    }
                    else{
                        path.insert(path.begin(),b);
                        while(pa!=0){
                            path.insert(path.begin(),pa);
                            pa = arr[pa].p;
                        }
                        cout<<d<<" ";
                        for(auto i=path.begin();i!=path.end();++i){
                            cout<<*i<<" ";
                        }
                    }
                    cout<<"\n";
                }
            }    
            
            fflush(stdin);
        }            
    }
    cout<<"\n";
    return 9;            
}