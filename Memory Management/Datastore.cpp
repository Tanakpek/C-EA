//Tan Akpek (260849778)

#include <iostream> 
using namespace std;

// Store class, basically a node on linked list Datastore
class Store{
    public:
        int id;
        int ssize;
        Store *next = NULL; 
        int *store_data = new int;
        Store(int id, int ssize, Store *next);
        Store(int id, int ssize);
        int add_el(int idx, int el);
        int add_el(int el);
        void del_el_ix(int indx);
        void del_el_val(int val);

};
// can be initialized with next store pre-determined
Store::Store(int id, int ssize, Store *next){   
    this->id = id;
    this->ssize = ssize;
    this->store_data = new int[ssize];
    this->next = next;
    //initialize everything to zero w/ pointer notation
    for(int i = 0; i< ssize;i++){
        *((this->store_data) + i) = 0;
    }

    
}
//Same constructor but without next store determined
Store::Store(int id, int ssize){
    this->id = id;
    this->ssize = ssize;
    this->store_data = new int[ssize];;

    for(int i = 0; i< ssize;i++){
        *((store_data)+i) = 0;
    }
}
//These are some class methods I defined, I kept them just in case you wanted to see my process, didn't use them
int Store::add_el(int idx, int el){
    if(idx>=ssize){
        return -1;
    }
    else{
        int *ptt;
        ptt = (this->store_data + idx);
        *ptt = el;       
        return 0;
    }
}
int Store::add_el(int el){
    int *prr;
    int ret = 0;
    for(int i = 0; i < ssize;i++){
        prr = ((store_data) + i);
        if(*prr == 0){
            *prr = el;
            return ret;
            
        }
    }
    return -1;
}
void Store::del_el_ix(int indx){
    if(indx>=ssize){
        cout<<"index out of scope"<<endl;
        return;
    }
    *(store_data + indx) = 0;

}
void Store::del_el_val(int val){
    int *ptro;
    ptro = store_data;
    for(int i = 0; i< ssize; i++){
        if (*(ptro+i) == val){
            *(ptro+i) = 0;
            return;
        }
    }
}
//Linked List Datastore Constructor with all fields and methods
class Datastore{
    public:
        //int *store_data = new int[9]; 
        Store *head = NULL;
        int id_tracker;
        int n_of_stores;
        Store *tail;
        Datastore();
        int newstore(int size);
        void print_debug();
        void delete_element_from_store_by_index(int id, int indx);
        void delete_element_from_store_by_value(int id, int val);
        void which_stores_have_element(int val);
        void delete_store(int id);
        int add_element_to_store(int id, int val, int indx);
        int add_element_to_store(int id, int val);
        void resize_store(int id, int newsize);
        
        
};
// initially tail = head
Datastore::Datastore(){
    this->id_tracker = 0;
    this->n_of_stores = 0;
    this->tail = this->head;

}
//can be 3 cases
int Datastore::newstore(int size)
    {
            id_tracker++;
            n_of_stores++;
            //First node
            if(head == nullptr){
                Store *news = new Store(id_tracker-1,size);
                this->head = news;
                this->tail = head;
                tail->next = nullptr;
            }
            //Second node
            else if(tail == head){
                Store* pi = NULL;
                pi = new Store(id_tracker-1,size);
                head->next = pi;
                this->tail = head->next;
                this->tail->next= nullptr;
            }
            //n'th node
            else{
                Store* ptr;
                ptr = this->head;
                for(int i = 0; i< n_of_stores-2; i++){
                    ptr = &(*ptr->next);
                }
                Store* ne = new Store(id_tracker-1,size);
                Store *pointy = NULL;
                pointy = ne;

                this->tail->next = pointy;
                //ptr->next = tail;
                tail = tail->next;
                tail->next = nullptr;
        
            }
            return id_tracker-1;
     }
int Datastore::add_element_to_store(int id, int val, int indx){
    Store *ptr5 = this->head;
    
    int *ptr6 = NULL;
    //Iterated through all nodes to find matching id, return -1 if failed
    for(int i = 0; i< n_of_stores; i++){
        if(ptr5 == 0){
            return -1;
        }
        if(ptr5->id == id){
            if(ptr5->ssize<= indx){
                return -1;
            }
            // set a pointer address equal to head address + index, I used this method for everything else
            ptr6 = ptr5->store_data + indx;
            *ptr6 = val;
            return 0;
        }
        ptr5 = &(*ptr5->next);
    }
    return -1;
}
int Datastore::add_element_to_store(int id, int val){
    Store *ok = NULL;
    //Store *ok1 = NULL;
    //ok1 = this->head;
    ok = this->head;
    int *pr2= NULL;

    //Same method just puts the value in first 0 found
    for(int i = 0; i< n_of_stores; i++){
        if(ok == 0){
            return -1;
        }
        if(ok->id == id){
            pr2 = ok->store_data;
            for(int j = 0;j<ok->ssize;j++){
                if(*pr2 == 0){
                    *pr2 = val;
            
                    return 0;
                }
                pr2++;
            }
            return -1;
        }
        //iterating
        ok = &(*ok->next);
    }
    return -1;
}
void Datastore::print_debug(){
    cout<<"Datastore:   ";
    Store *ar = NULL;
    ar = this->head;
    
    int *pt = NULL;
    for(int i = 0; i<n_of_stores;i++){
        if(ar == 0){
            break;
        }
        // iterated using ssize
        pt = ar->store_data;
        for(int j=0;  j< ar->ssize ; j++){
            cout<<*(pt+j);
            cout<<" ";
        }
        ar = &(*ar->next);
    }
    cout<<"\n"<<endl;
    ar = head;
    for(int i = 0; i<n_of_stores;i++){
        cout<<"Store ";
        cout<<i;
        cout<<": ";
        if(ar == 0){
            cout<<"\n";
            cout<<endl;
            break;
        }
        for(int j=0; j<ar->ssize; j++){
            pt = ar->store_data + j;
            cout<<*pt;
            cout<<" ";
        }
        ar = &(*ar->next);
        cout<<"\n";
        cout<<endl;
    }
    cout<<"############################\n"<<endl;
    //delete ar;
    //delete pt;
}
//  essentially same method as add by index, but just sets the pointer value to 0
void Datastore::delete_element_from_store_by_index(int id, int indx){
    Store *ptr4 = NULL;
    ptr4 = head;

    int *u = NULL;
    for(int i = 0; i< n_of_stores; i++){
        if(ptr4->id == id){
            if(indx<ptr4->ssize){
                u = ptr4->store_data;
                u[indx] = 0;
                return;
            }
        }
        else ptr4 = ptr4->next;
    }
    delete ptr4;
}


void Datastore::delete_element_from_store_by_value(int id, int val){
    Store *ptr = NULL;
    ptr = head;
    int *ptr2 = NULL;
    //iterate id
     for(int i = 0; i< n_of_stores; i++){
         //find value
        if(ptr->id == id){
            for(int j = 0; j< ptr->ssize ; j++){
                if( *(ptr->store_data + j) == val){
                    //set to zero
                    *(ptr->store_data + j) = 0;
                }
            }
        }
    }
    delete ptr2;

}

void Datastore::which_stores_have_element(int val){
    Store *pnt;
    pnt = head;
    //arr will be an arraylist of store ids
    int arr[this->n_of_stores];
    bool has = false;
    for(int t = 0; t < this->n_of_stores;t++){
        //instantiateed to -1 so that we can distinguish when value is in store with id 0
        arr[t] = -1;
    }

    int *ptr2 = NULL;
    //same iteration process as before
     for(int i = 0; i< this->n_of_stores; i++){
        ptr2 = pnt->store_data;
        for(int j = 0; j<pnt->ssize ; j++){
            if( *(ptr2 + j) == val){
                arr[i] = pnt->id;
                has = true;
                continue;
            }
        }
        pnt = pnt->next;
    }
    if(has){
        cout<<"Element "<<val<<" is in stores: "<<endl;
    }
    else{
        cout<<"Element is not in any store"<<endl;
        cout<<"\n";
        return;
    }
    for (int f = 0; f<n_of_stores; f++){
        if(arr[f]!= -1){
            cout<<arr[f]<<"  ";
        }
    }
    cout<<endl;
    cout<<"\n";
}



void Datastore::delete_store(int id){
    Store *ptr = NULL;
    ptr = head;
    
    //if head
    if(head->id == id){
        head = head->next;
        n_of_stores --;
        return;
    }
    //exception haandling for when iterator pointer reaches tail
     for(int i = 0; i< n_of_stores; i++){
        if(ptr->next == tail){
            if(id == tail->id){
                this->tail = ptr;
                tail->next = nullptr;
                n_of_stores --;
                return;
            }
            return;
        }
        //deletion
        if(ptr->next->id == id){
            Store *store;
            store = ptr->next;
            ptr->next = ptr->next->next;
            store->next = nullptr;
            this->n_of_stores --;
            delete store;
            return;

        }
        else{
            ptr = ptr->next;
        }
     }
     delete ptr;
}
// 2 possibilities
void Datastore::resize_store(int id, int newsize){
    Store *pointer = NULL;
    pointer = head;

    for(int i = 0; i< n_of_stores; i++){
        //null exception
        if(pointer == 0){
            break;
        }
        if(pointer->id == id){
            int tmp [newsize];
            
            int zeroes = 0;
            int count = 0;
            int *newinv =  new int[newsize];
            // adding nonzero values to an array to align them, also keeping track of zeros
            for(int j = 0; j < pointer->ssize; j++){
                if(pointer->store_data[j] != 0){
                    tmp[count] = pointer->store_data[j];
                    count++;
                }
                else{
                    zeroes++;
                }
            }
            //newsize smaller
            if(newsize<= pointer->ssize){
                int end = 0;
                for(int a = 0; a<count; a++){
                    //adding non-zeros
                    newinv[a] = tmp [a];
                    end++;
                    if(a == newsize -1){
                        break;
                    }
                }
                //adding zeros
                for(int h = 0;h< newsize - count; h++){
                    newinv[end+h] = 0;
                }
                pointer->store_data = newinv;
                pointer->ssize = newsize;
                return;
            }
            // newsize larger
            else{
                int end = 0;
                for(int a = 0; a<count; a++){
                    newinv[a] = tmp [a];
                    end++;
                }
                for(int h = 0; h< newsize - count; h++){
                    newinv[end+h] = 0;
                }
                pointer->store_data = newinv;
                pointer->ssize = newsize;
                return;

            }
        }
        pointer = pointer->next;
    }
}

int main(){
    Datastore mystore= Datastore();
    int s1 = mystore.newstore(3);
    int s2 = mystore.newstore(5);

    if (s1 != -1){
        mystore.add_element_to_store(s1,13);
        mystore.add_element_to_store(s1,15);
        mystore.add_element_to_store(s1,21);
        mystore.add_element_to_store(s1,42);
    }
    
    if(s2 != -1){
        mystore.add_element_to_store(s2,7,2);           //in HW1 7 ended up being deleted but not here
        mystore.add_element_to_store(s2,15,0);          //since it actually has index 1 when added to 
        mystore.add_element_to_store(s2,22,1);          //linked list, kept the index par. for size checking
    }                                                   //if you were to give indx larger than size
    mystore.print_debug();

    mystore.delete_element_from_store_by_value(s1,13);
    mystore.delete_element_from_store_by_value(s1,71);
    mystore.delete_element_from_store_by_index(s1,2);
    mystore.delete_element_from_store_by_index(s1,5);
    mystore.print_debug();

    mystore.which_stores_have_element(15);
    mystore.which_stores_have_element(29);

    mystore.delete_store(s1);
    mystore.print_debug();

    mystore.resize_store(s2,20);
    int s3 = mystore.newstore(40);
    mystore.print_debug();

    s3 = mystore.newstore(30);
    mystore.add_element_to_store(s3,7,29);
    
    mystore.print_debug();



    
}
