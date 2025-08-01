#include<iostream> 
using namespace std; 
class itemlist 
{ 
public: 
int nb=200,sk=200,gb=200,c=200,a4=200; 
int nbp=20,skp=50,gbp=75,cp=150,a4p=12; 
void printlist() 
{ 
cout<<"......WELCOME TO ABC STATIONERY STORE......\n\n"; 
cout<<"List of items in our shop:\n"; 
cout<<"S.NO \t PRODUCT NAME      \t PRICE\n"; 
cout<<"-----------------------------------\n"; 
cout<<"1.   \t Notebook          
\t 20rps\n"; 
cout<<"2.   \t Stationary kit    \t 50rps\n"; 
cout<<"3.   \t Geometry box      
\t 75rps\n"; 
cout<<"4.   \t Calculator        
\t 150rps\n"; 
cout<<"5.   \t A4 sheet(a dozen) \t 12 rps\n"; 
cout<<"-----------------------------------\n"; 
} 
}; 
class items: public itemlist 
{ 
protected: 
int n,*item, *count; 
public: 
void getdetails() 
{ 
cout<<"Enter the total number of items:"; 
cin>>n; 
cout<<"\nAvailable stock for each product is:200\n"; 
item=new (nothrow) int[n]; 
count=new (nothrow) int[n]; 
for(int i=0;i<n;i++) 
{ 
cout << "\nEnter s.no of the product that the customer bought:"; 
cin >> item[i]; 
cout<<"Enter the quantity of the items that the customer bought:"; 
cin>>count[i]; 
}  
} 
friend void stock(items); 
}; 
void stock(items it) 
{ 
for(int i=0;i<it.n;i++) 
{switch(it.item[i]) 
{ 
case 1: 
it.nb=it.nb-it.count[i];break; 
case 2: 
it.sk=it.sk-it.count[i];break; 
case 3: 
it.gb=it.gb-it.count[i];break; 
case 4: 
it.c=it.c-it.count[i];break; 
case 5: 
it.a4=it.a4-it.count[i];break; 
default: 
cout<<"Invalid number."; 
} 
} 
if(it.nb<5 || it.sk<5 || it.gb<5 || it.c<5 || it.a4<5) 
{cout<<"\n\nYou are out of stock. Please order the items for a restock.\n";} 
} 
class bill:public items 
{ 
public: 
int price=0; 
void printbill() 
{ 
cout<<"\n\n........ABC STATIONERY STORE.........."; 
cout << "\n-----------------------------------------------\n"; 
cout << "BILL\n"; 
cout << "-------------------------------------------------\n"; 
cout << "S.NO \t PRODUCT NAME \t QUANTITY \t PRICE\n"; 
cout << "-------------------------------------------------\n"; 
for (int i = 0; i < n; i++) { 
string productName; 
int productPrice; 
switch (item[i]) { 
case 1: 
productName = "Notebook"; 
productPrice = nbp*count[i]; 
price+=productPrice; 
break; 
case 2: 
productName = "Stationary kit"; 
productPrice = skp*count[i]; 
price+=productPrice; 
break; 
case 3: 
productName = "Geometry box"; 
productPrice = gbp*count[i]; 
price+=productPrice; 
break; 
case 4: 
productName = "Calculator"; 
productPrice = cp*count[i]; 
price+=productPrice; 
break; 
case 5: 
productName = "A4 sheet(a dozen)"; 
productPrice = a4p*count[i]; 
price+=productPrice; 
break; 
default: 
productName = "Invalid Product"; 
productPrice = 0; 
} 
cout << i + 1 << " \t     " << productName << "  \t     " << count[i] << " \t    " << 
productPrice << "rps\n"; 
} 
cout << "------------------------------------------\n"; 
cout << "TOTAL PRICE:" << price << "rps\n"; 
cout<<"\nTax(GST):5%\n"; 
double am=0.05*price; 
cout << "\nTOTAL AMOUNT:" << am+price << "rps\n"; 
} 
}; 
int main() 
{ 
bill i1; 
i1.printlist(); 
i1.getdetails(); 
stock(i1); 
i1.printbill(); 
return 0; 
}
