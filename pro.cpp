#include<iostream>

#include<conio.h>

#include<windows.h>

#include<string.h>

using namespace std;

class Bank{

	private: 

	    int total;

	    string id;

	    struct person{

	    	string name,ID,address;

	    	int contact,cash;

		}person[100];

	public:

		Bank(){

			total=0;

		}

		void choice();

		void inputData();

		void show();

		void update();

		void search();

		void transactions();

		void del();

};

int main(){

	Bank b;

	b.choice();

	return 0;

}

void Bank::choice(){

	char ch;

	while(1){

	cout<<"\n\nCHOOSE THE REQUIRED OPTION"<<endl;

	cout<<"1. Create new user account"<<endl;

	cout<<"2. View customers/users list"<<endl;

	cout<<"3. Update information of an existing account"<<endl;

	cout<<"4. Check the details of an existing account"<<endl;

	cout<<"5. For new transactions"<<endl;

	cout<<"6. Remove an existing account"<<endl;

	cout<<"7. Exit the bank"<<endl;

	 ch=getch();

	system("CLS");

	switch(ch){

		case '1':

			Bank::inputData();

			break;

		case '2':

			if(total==0){

				cout<<"No data is entered"<<endl;

			}else{

			Bank::show();

		   }

			break;

		case '3':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::update();

			break;

		case '4':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::search();

			break;

		case '5':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::transactions();

			break;

		case '6':

			if(total==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::del();

			break;

		case '7':

			exit(0);

			break;

		default:

			cout<<"Invalid input"<<endl;

			break;

	}

    }

}

void Bank::inputData(){

	cout<<"Enter the data of the person "<<total+1<<endl;

	cout<<"Enter name: ";

	getline(cin,person[total].name);

	cout<<"Enter ID (It should be unique for every person): ";

	getline(cin,person[total].ID);

	cout<<"Enter Address: ";

	getline(cin,person[total].address);

	cout<<"Enter Contact No.: ";

	cin>>person[total].contact;

	cout<<"Total Cash : ";

	cin>>person[total].cash;

	total++;

}

void Bank::show(){

	for(int i=0;i<total;i++){

		cout<<endl<<"Data of person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Cash: "<<person[i].cash<<endl<<endl;

	}

}

void Bank::update(){

	cout<<"Enter id of the person whose data you want to update"<<endl;

	getline(cin,id);

	for(int i=0;i<total;i++){

		if(id==person[i].ID){

		cout<<"Previous data"<<endl;

		cout<<"Data of the person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Cash: "<<person[i].cash<<endl;

		cout<<"\nEnter the new data"<<endl;

		cout<<"Enter name: ";

	getline(cin,person[i].name);

	cout<<"ID: ";

	getline(cin,person[i].ID);

	cout<<"Address: ";

	getline(cin,person[i].address);

	cout<<"Contact: ";

	cin>>person[i].contact;

	cout<<"Total Cash: ";

	cin>>person[i].cash;

	break;

		}

		if(i==total-1){

			cout<<"No such record is found"<<endl;

		}

	}

}

void Bank::search(){

cout<<"Enter id of the person whose data you want to search"<<endl;

getline(cin,id);

for(int i=0;i<total;i++){

	if(id==person[i].ID){

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Cash: "<<person[i].cash<<endl;

		break;

	}

	if(i==total-1){

		cout<<"No such record is found"<<endl;

	}

}

}

void Bank::transactions(){

	int cash;

	char ch;

	cout<<"Enter id of the person for transaction"<<endl;

     getline(cin,id);

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){

     		cout<<"Name: "<<person[i].name<<endl;

     	     cout<<"Address: "<<person[i].address<<endl;

		     cout<<"Contact: "<<person[i].contact<<endl;

		     cout<<"\nExisting Cash "<<person[i].cash<<endl;

		     cout<<"Press 1 to deposit"<<endl;

		     cout<<"Press 2 to withdraw"<<endl;

		     ch=getch();

		     switch(ch){

		     	case '1':

		     		cout<<"How much cash do you want to deposit??"<<endl;

		     		cin>>cash;

		     		person[i].cash+=cash;

		     		cout<<"Your new cash is "<<person[i].cash<<endl;

		     		break;

		     	case '2':

		     		back:

		     		cout<<"How much cash do you want to withdraw??"<<endl;

		     		cin>>cash;

		     		if(cash>person[i].cash){

		     			cout<<"Your existing cash is just "<<person[i].cash<<endl;

		     			Sleep(3000);

		     			goto back;

					 }

					 person[i].cash-=cash;

					 cout<<"Your new cash is "<<person[i].cash<<endl;

					 break;

				default:

					cout<<"Invalid input"<<endl;

					break;

			 }

			 break;

		 }

		 if(i==total-1){

		 	cout<<"No such record is found"<<endl;

		 }

	 }

}

void Bank::del(){

	char ch;

	cout<<"Press 1 to remove an specific record"<<endl;

	cout<<"Press 2 to remove the full record"<<endl;

	ch=getch();

	switch(ch){

		case '1':

	cout<<"Enter id of the person whose data you want to remove"<<endl;

     getline(cin,id);

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){

     		for(int j=i;j<total;j++){

     		person[j].name=person[j+1].name;

     		person[j].ID=person[j+1].ID;

     		person[j].address=person[j+1].address;

     		person[j].contact=person[j+1].contact;

     		person[j].cash=person[j+1].cash;

     		total--;

     		cout<<"Your entered data is deleted"<<endl;

     		break;

			 }

		 }

		 if(i=total-1){

		cout<<"No such record is found"<<endl;

		 }

	 }

	 break;

	 case '2':

	 	total=0;

	 	cout<<"All records are deleted"<<endl;

	 	break;

	default:

		cout<<"Invalid Input"<<endl;

		break;

	}

}
