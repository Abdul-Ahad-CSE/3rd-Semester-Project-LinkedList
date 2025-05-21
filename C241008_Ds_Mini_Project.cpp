#include<bits/stdc++.h> 
using namespace std;
int n;

struct node{
    int data;
    node* link;
};

// Display function
void displayList(node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    node* temp = head;
    cout << "Linked list: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
} 

// Search function
void searchList(node* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to search." << endl;
        return;
    }

    int key;
    cout << "Please enter value for searching: ";
    cin >> key;

    node* temp = head;
    int pos = 1, flag = 0;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Value found at position " << pos << endl;
            flag = 1;
            break;
        }
        temp = temp->link;
        pos++;
    }
    if (flag == 0) {
        cout << "Value doesn't exist in the list." << endl;
    }
}

//Insert function
void insertList(node*& head){

    cout << "Enter a value for inserting: " << endl;
    int value;
    cin >> value;

    node* temp = head;
    int pos = 1, flag = 0;
    while (temp != nullptr) {
        if (temp->data >= value) {
            flag = 1;
            break;
        }
        temp = temp->link;
        pos++;
    }

    //Inserting at the beginning
    if( pos == 1 ){
 
    node* newnode = new(nothrow) node;
    if (!newnode) {      //Handaling Overflow Condition if memery alocation failed;
        cout << "Memory overflow. Node can't be inserted." << endl;
        return;
    }

    newnode->data = value;
 
    newnode->link = head;
    head = newnode;
    n++; //updating total elements after insertion;
    cout << value << " inserted at position " << pos << "." << endl;
    cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;

    }
 
    //Inserting at any position: 
    else if( pos!=1 && pos!=(n+1) ) {

    node* newnode = new(nothrow) node;
    if (!newnode) {      //Handaling Overflow Condition if memery alocation failed;
        cout << "Memory overflow. Node can't be inserted." << endl;
        return;
    }

        newnode->data = value;
 
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->link;
        }
 
        newnode->link = temp->link;
        temp->link = newnode;
        n++; //updating total elements after insertion;
        cout << value << " inserted at position " << pos << "." << endl;
        cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;

    }
 
    //Inserting at the end:
    else {
        node* newnode = new(nothrow) node;
        if (!newnode) {      //Handaling Overflow Condition if memery alocation failed;
        cout << "Memory overflow. Node can't be inserted." << endl;
        return;
    }

 
        newnode->data = value;
 
        newnode->link = nullptr;
        temp = head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        n++; //updating total elements after insertion;
        cout << value << " inserted at position " << pos << "." << endl;
        cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;
    }
 

}

//Delete function
void deleteList(node*& head){

    if (n == 0) {
    cout << "Underflow. The list is already empty." << endl;
    return;
    }

    cout << "Enter a value for deletion: ";
    int value;
    cin >> value;

    node* temp = head;
    int pos = 1, flag = 0, lastO=-1;
    while (temp != nullptr) {
        if (temp->data == value) {
            flag = 1;
            lastO = pos;
        }
        temp = temp->link;
        pos++;
    }

    pos = lastO;

    if( flag==0 ){
     cout << "Value doesn't exist" << endl;
        return;
    }

    //Deletion at the begining:
    if( pos == 1 ){
 
        temp = head;
        head = head -> link;
        delete temp;
        n--; //updating total elements after insertion;
        cout << value << " deleted at position " << pos << "." << endl;
        cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;
    }
 
    //Deletion at any position: 
    else if( pos!=1 && pos!=(n+1) ) {
        
        temp = head;
        for( int i=1 ; i<pos-1 ; i++ ){
            temp = temp->link;
        }
        node* nodeDelete = temp -> link;
        temp -> link = nodeDelete -> link;
        delete nodeDelete;

        n--; //updating total elements after insertion;
        cout << value << " deleted at position " << pos << "." << endl;
        cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;
    }
 
    //Deletion at the end:
    else if( pos==n ){
        temp = head;
        while (temp->link->link != nullptr)
        {
            temp = temp->link;
        }
        delete temp->link;
        temp -> link = nullptr;

        n--; //updating total elements after insertion;
        cout << value << " deleted at position " << pos << "." << endl;
        cout << "Updated Total elements : " << n << endl << "Type 1 to dislplay updated list" << endl;
    }


}

//Menu function
void menu(){

    srand(time(0));  // seed the random number generator with the current time

    // 4. Generate random numbers
    cout << "Enter Total Element: ";
    n; cin >> n;
    int arr[n+1];
    for (int i = 1; i <= n; ++i) {
        arr[i] = rand();
    }

    cout << "Generated randmom elements before sort: ";
    if( n==0 ) cout << "No item.";
    else{
    for (int i = 1; i <= n; ++i) {
       cout << arr[i] << " ";
    }
    }
    cout << endl;


    for( int i=1 ; i<=n-1 ; i++ ){
        for( int j=1 ; j<=n-i ; j++ ){
            if( arr[j]>arr[j+1] ){
                swap( arr[j],arr[j+1] );
            }
        }
    }

    node* head = nullptr;
    node* temp = nullptr;

    for(int i = 1; i <= n; i++) {
        node* newnode = new node;
        newnode->data = arr[i];
        newnode->link = nullptr;

        if (head == nullptr) {
            head = newnode; // First node
        }
        else {
            node* temp = head;
            while (temp->link != nullptr) {
                temp = temp->link;
            }
            temp->link = newnode; // Insert at end
        }
    }

    cout << "Generated Sorted Linked List: ";
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;

    int choice;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Display Linked List" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Insert a value" << endl;
        cout << "4. Delete a value" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                searchList(head);
                break;
            case 3:
                insertList(head);
                break;
            case 4:
                deleteList(head);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
}
while( choice!=5 );

}

//Main function
int main(){
    menu();
}