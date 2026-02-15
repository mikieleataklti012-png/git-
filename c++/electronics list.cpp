/*this program accept electrical devices their models and how much of that model 
you have and it can also search for a specific deivce and
substruct a device that have been sold from the store */
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
/*vector is used since it is more convinent than using dynamic arrays
which leads to memory leackage*/
using namespace std;

/*we use a structure to have the details of the electrical devices*/
struct device{
    string name,model;
    int amount;
    double price, totprice,selligPrice;
};

/* declaring the function prototypes*/
vector <device> accept(int);
void display(vector<device> &s);
void write(vector<device>& r);
void add(vector<device>& r);
int search(vector<device>& r);
void sub(vector<device>& r );
vector <device> calculate(vector<device> &s);
vector <device> read();



int main(){
    int size;
    cout<<"enter the number of devices like PC, Phone as 2 devices\n";
    cin>>size;
    vector <device> div(size);
    div = accept(size);/*assigning the details abt the devices to an  array div */
    div=calculate(div);
    write(div);
    display (div);
    char input;
    do{
       cout<<"choose course of action\n"
       <<" 'a' for adding a new devise\n"
       <<" 'b' for searching a devise from the list\n"
       <<" 'c' for substructing amount of a device in the list\n"
       <<" 'e' for no action needed\n";
       char choice;
       cin>>choice;
       switch(choice){
        case 'a': add(div);break;
        case 'b': search(div) ;break;
        case 'c': sub(div);break;
        case 'e': break;
        default: cout<<"wrong input\n";
       }
        cout<<"to go back to the choises press 'y' \n"
        <<"to exit press any other alphabet\n";
        cin>>input;     
    }while(input=='y');
    return 0;
}

    /*the function definiotions*/
    /*the function accept is used to accept the name of the electronic devices 
    along with their models and how many there are */

vector <device> accept(int n){
    vector <device> s(n);
    /*the for loop is used to get the details of the electronic devices*/
    for(int i=0;i<n;i++){
        cout<<"enter the name of device "<<i+1;
        cin>>s[i].name;
        cout<<"enter the amount of the "<<s[i].name<<" ";
        cin>>s[i].amount;
        cout<<"enter the model of the "<<s[i].name<<" ";
        cin>>s[i].model;
        cout<<"enter the price of the "<<s[i].name<<" ";
        cin>>s[i].price;
    }
    return s;    
}

void display(vector<device> &s){
    for(int i=0;i<s.size();i++){
        s=calculate(s);
        cout<<i+1<<" "<<s[i].name<<";\t amount "
        <<s[i].amount<<";\t model= "<<s[i].model
        <<";\t price= "<<s[i].price
         <<";\t total price= "<<s[i].totprice<<endl;
    }
}

/*the write function writes the items on a text file */
void write(vector<device>& r){
    fstream out;
    out.open("/home/mikieleataklti012/cpp_project/project.txt",ios::out);
    if(out.is_open()){
    for(int i=0; i< r.size();i++){
        out << r[i].name << "\t"
            <<r[i].amount<<"\t"
            <<r[i].model<<"\t"
            <<r[i].price<<"\t"
            <<r[i].totprice << endl;
    }
    cout<<"writing to file.....\n";
    }
   else{
    cout<<"file not opened succesfully \n";
   }
   out.close();
}


/*this function adds a new item on the already existed list of items*/
void add(vector<device>& r){
    device newdiv;
        cout<<"enter the name of the device to be added\n";
        cin>>newdiv.name;
        cout<<"enter the amount of the "<<newdiv.name<<"\n";
        cin>>newdiv.amount;
        cout<<"enter the model of the "<<newdiv.name<<"\n";
        cin>>newdiv.model;
        cout<<"enter the price of the "<<newdiv.name<<"\n";
        cin>>newdiv.price;
        r.push_back(newdiv);/*adds the element to the end of the list*/
         display (r);
        write(r);
}

/*this function will be searching for an item on the list by its name*/
int search(vector<device>& r){
    bool value= false;
    int index=0;
    string name;
    cout<<"Enter the name of the item you want to search\n";
    cin>>name;  
    for(int i=0; i<r.size();i++){
        if(r[i].name==name){
            value=true;
            index=i;
            break;
        } }
        if(value==true){
            cout<<"The item "<<name<<" has been found in the index; "<<index<<"\n";
        cout<<" the detail for the item are\n"<<
        r[index].name<<";\t amount "
        <<r[index].amount<<";\t model= "<<r[index].model<<endl;
        return index;
    
        }
        else{
            cout<<"the item "<<name<<" search is not found!\n";
        }
        return -1;
}


/*this function substructs the sold amount of the from the total amount */
void sub(vector<device>& r){
    int index=search(r);
    int substruct;
    /*checks if the search fucntion had found the item correctly*/
    if(index==-1){
        cout<<"your search has failed\n";
    }
    else{
    cout<<"how many have been sold and to be substructed from the total\n";
    cin>>substruct;
    /*check if the substructed number is not negative*/
    if(r[index].amount-substruct>0){
    r[index].amount-=substruct;
    display (r);
    write(r);
}
else{
    cout<<"sorry you cannot substruct the number you entered from the amount \n";
}
}
}


/*this function calculates the total price using the price and the 
amount of the item*/
vector <device> calculate(vector<device> &s){
    for(int i=0;i<s.size();i++){
        int total=0;
        total=s[i].amount*s[i].price;
        s[i].totprice=total;
    }
    return s;
}

/*this function reads the list of array if exists and send it to the main funtion*/
vector<device> read(){
    fstream in;
    in.open("/home/mikieleataklti012/cpp_project/project.txt",ios::in);
    if(in.is_open()){
        device temp;
        vector<device> r;
        while(in >> temp.name >> temp.amount >> temp.model >> temp.price>>
            temp.totprice){
            r.push_back(temp);
        }
        return r;
    }
    else{
        cout<<"file didnt open sucessfully \n";

    }
}

