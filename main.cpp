#include <iostream>
#include <list>

#define COUNT 2

using namespace std;


class Node{
    public:
        int data;  
        Node *left, *right;

        Node(int value){ 
            data = value;
            left = NULL;
            right = NULL;
        }
};

class Graph{
    public:
        list<int> *adjlist;
        int n;
        
        Graph(int v){
            adjlist = new list<int> [v];
            n = v;
        }
        
        void addEdge(int u, int v, bool bi){
            adjlist[u].push_back(v);
            if(bi){
                adjlist[v].push_back(u);
            }
        }
        
        void print(){
            for(int i = 0; i < n; i++){
                cout<<i<<"-->";
                for(auto it:adjlist[i]){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};


int binarySearch(int arr[], int left, int right, int index);
int binarySearchOption();

int linearSearch(int arr[], int size, int index);
int linearSearchOption();

int fibonacciSeries(int number);
int fibonacciOption();

void printTreeUtil(Node *root, int space);
void printTree(Node *root);
void binaryTree();

void graph();

int main(){
    
    int option;
    char choice;
    
    do{
        
        cout<<"-----Algorithms-----\n";
        cout<<"\n1) Binary search algorithm\n";
        cout<<"2) Linear search algorithm\n";
        cout<<"3) Fibonacci series\n";
        
        cout<<"\n-----Data structures-----\n";
        cout<<"\n4) Binary tree data structure\n";
        cout<<"5) Graph data structure\n";
        
        cout<<"\nChoose your option.\n";
        cin>>option;
        
        switch(option){
            case 1:
                binarySearchOption();
                break;
            case 2:
                linearSearchOption();
                break;
            case 3: 
                fibonacciOption();
                break;
            case 4:
                binaryTree();
                break;
            case 5:
                graph();
                break;
            
            default:
                cout<<"There is no option as "<<option<<". Please try again.";
        }
        cout<<"\n\nIf you want to continue enter 'Y' or 'y'. Otherwise program will stop executing\n";
        cin>>choice;
        
    }while(choice == 'y' || choice == 'Y');
    
}

// binarySearch
int binarySearch(int arr[], int left, int right, int index){
   while (left <= right){
       int mid = left + (right - left) / 2;
       
       if(arr[mid] == index)
        return mid;
        
       if(arr[mid] < index)
        left = mid + 1;
        
       else
        right = mid - 1;
   }
   
   return -1;
}

int binarySearchOption(){
    int size;
    
    cout<<"Enter array size: ";
    cin>>size;
    
    int arr[size];
    
    for(int i = 0; i < size; i++){
        cout<<"Enter array "<<size<<" elements: ";
        cin>>arr[i];
    }
    
    int index;
    
    cout<<"Enter element you want to find: ";
    cin>>index;
    
    int result = binarySearch(arr, 0, size - 1, index);
    (result == -1) ? cout<<index<<" Element is not presented in array" : cout<<"Element is at "<<result<<" index";
    
    cout<<"\n\nTime Complexity: O(log N)\nAuxiliary Space: O(1)";

}

// linear search
int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++)
        if(arr[i] == element)
            return element;
    return -1;
}

int linearSearchOption(){
    
    int size;
    
    cout<<"Enter array size: ";
    cin>>size;
    
    int arr[size];
    
    for(int i = 0; i < size; i++){
        cout<<"Enter "<<size<<" array elements: ";
        cin>>arr[i];
    }
    
    int element;
    cout<<"Enter element you want to find: ";
    cin>>element;
    
    int result = linearSearch(arr, size, element);
    (result == -1) ? cout<<"\nYour element was not presented in the array" : cout<<"Your element in "<<result - 1<<" index";

    cout<<"\n\nWorst complexity: O(n)\nAverage complexity: O(n)\nSpace complexity: O(1)\nClass: Search algorithm";
}

// fibonacciSeries
int fibonacciSeries(int number){
    if(number <= 1)
        return number;
        
    return fibonacciSeries(number - 1) + fibonacciSeries(number - 2);
}

int fibonacciOption(){
    
    int number;

    cout<<"Enter a number: ";
    cin>>number;
    
    cout<<fibonacciSeries(number);
    cout<<"\n\nTime complexity: O(n^2)\n";
}

// binaryTree
void printTreeUtil(Node *root, int space){
    
    if(root == NULL)
        return;
    
    space += COUNT;
    
    printTreeUtil(root->right, space);
    
    cout<<endl;
    
    for(int i = COUNT; i < space; i++)
        cout<<" ";
    
    cout<<root->data<<"\n";
    
    printTreeUtil(root->left, space);
}

void printTree(Node *root){
    printTreeUtil(root, 0);
}

void binaryTree(){
    
    int rootVal;
    
    cout<<"Enter root value: ";
    cin>>rootVal;
    
    int nodes = 10;
    int values[nodes];
    
    for(int i = 0; i <= nodes; i++){
        cout<<"Enter "<<nodes<<" Node values: ";
        cin>>values[i];
    }   
    
    Node *root = new Node(rootVal);
    
    root->left = new Node(values[0]);
    root->right = new Node(values[1]);
    
    root->left->left = new Node(values[2]);
    root->left->right = new Node(values[3]);
    root->right->right = new Node(values[4]);
    root->right->left = new Node(values[5]);
    
    root->left->left->left = new Node(values[6]);
    root->left->right->right = new Node(values[7]);
    root->right->right->right = new Node(values[8]);
    root->right->left->left = new Node(values[9]);


    printTree(root);
    cout<<"\n\n(A) O(n) for all\nO(Logn) for all\nO(Logn) for search and insert, and O(n) for delete\nO(Logn) for search, and O(n) for insert and delete\n";
}

// Graph
void graph(){
    
    char option;
    int menu;
    int edges;
    int egdeElementSize = 2;
    int edgeElement[egdeElementSize];
    
    cout<<"Enter amount of edges: ";
    cin>>edges;
    
    Graph newGraph(edges);
    
    do{
        
        cout<<"\nEnter '1' to add new edges\n";
        cin>>menu;
        
        switch(menu){
            case 1:
                
                
                
                for(int j = 0; j < egdeElementSize; j++){
                cout<<"Enter "<<egdeElementSize<<" elements to edge: (list), (vertice)";
                cin>>edgeElement[j];
                }
                
                newGraph.addEdge(edgeElement[0], edgeElement[1], true);
        
                newGraph.print();
            break;
            
            default:
                cout<<"\nThere is no option as this.";
        }
        
        cout<<"If you want to continue type 'Y' or 'y': ";
        cin>>option;
        
    }while(option == 'Y' || option == 'y');
    
}




