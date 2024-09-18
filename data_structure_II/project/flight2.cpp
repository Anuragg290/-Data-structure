
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<conio.h>
#define infinity 999999999

using namespace std;
int payment();
struct store
{
	long long int cost[20];
	int array[20];
}travel[15];

struct initialdata{
	long long int cost[20];
}ini[15];

class datamodule{
	public:
	string city[15];
	
	//datamodule() constructor is used to initialize values of cities...
	
	datamodule():city{"Delhi","Mumbai","Chennai","Kolkata","Kerala","Hyderabad","Pune","Goa","Bangalore","Amritsar","Jaipur","Patna","Puducherry","Srinagar","Bhopal"}{}
	
	void costdeclaration(){
		int N,i,j;
		N=15;
		
		//Ten different major cities are considered

		//The cost of travelling between any two cities in direct flight is initialized. In further steps the minimum fare will be calculated

		long long int arr[15][15]={{0,3500,2000,infinity,1000,infinity,infinity,infinity,infinity,7000,4000,1500,infinity,6500,infinity},
								   {3500,0,infinity,1520,infinity,infinity,infinity,2500,infinity,infinity,infinity,infinity,infinity,infinity,5000},
							       {2000,infinity,0,1500,infinity,3000,infinity,infinity,infinity,infinity,2000,1000,infinity,infinity,1500},
							       {infinity,1520,1500,0,infinity,1200,4500,infinity,6000,infinity,infinity,infinity,infinity,infinity,1000},
							       {1000,infinity,infinity,infinity,0,1500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,3000,1200,1500,0,1950,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,infinity,4500,infinity,1950,0,infinity,infinity,2050,infinity,infinity,infinity,infinity,infinity},
							       {infinity,2500,infinity,infinity,infinity,infinity,infinity,0,5000,infinity,infinity,infinity,infinity,infinity,infinity},
							       {infinity,infinity,infinity,6000,infinity,infinity,infinity,5000,0,7000,infinity,infinity,infinity,infinity,infinity},
							       {7000,infinity,infinity,infinity,infinity,infinity,2050,infinity,7000,0,infinity,infinity,infinity,infinity,infinity},
							       {4000,infinity,2000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity,infinity},
							       {1500,infinity,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity,infinity},
							       {infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity,infinity},
							       {6500,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0,infinity},
							       {infinity,5000,1500,1000,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity,0}};

	//the main array i.e. arr is not changed. Instead, the values are copied to structure and then the structure store with data member cost is changed. The structure store will hold the
	//minimum possible fare between any origin and destination

		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				travel[i].cost[j]=arr[i][j];
				travel[i].array[j]=j;
				ini[i].cost[j]=arr[i][j];
			}
		}
	}
};

class bellmanfordalgorithm:public datamodule{
	public:
	int N,i,j,k;
	bellmanfordalgorithm(){
		N=15;
	}
	void algorithmic_implementation(){
	
		//3 different loops are executed
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				for(k=0;k<N;k++){
					if(travel[i].cost[j]>travel[i].cost[k]+travel[k].cost[j])
					{
						//if low fare is found for the same origin and destination, the minimum possible fare is changed.
					
						travel[i].cost[j]=travel[i].cost[k]+travel[k].cost[j];
						travel[i].array[j]=k;
					}
				}
			}
		}
	}
};
class filehandlingmodule{
	public:
	
	void ticket(string firstname[],string lastname[],string sex[],int age[],string email[],string c_no[],string souce,string dist,int no){
		ofstream filewrite;
		filewrite.open("ticket.txt",ios::app);
		for(int i=0;i<no;i++){
			filewrite<<"firstname: "<<firstname[i]<<" "<<"lastname: "<<lastname[i]<<" "<<"sex: "<<sex[i]<<" "<<"age: "<<age[i]<<" "<<"email: "<<email[i]<<" "<<"contact_no: "<<c_no[i]<<" "<<"source: "<<souce<<" "<<"destination: "<<dist<<"\n";
		}
		filewrite.close();
	}
};

class inputmodule{
	public:
	string source,destination;
	void user_input(string userchoice[]){
		system("CLS");
		cout<<"\n\n                       ****************************        WELCOME TO FLIGHT RESERVATION SYSTEM       **************************"<<endl;
		cout<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 Enter Your City:";
		cin>>source;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 Enter Your Destination:";
		cin>>destination;
		cout<<"                 *****************************************"<<endl;
		userchoice[0]=source;
		userchoice[1]=destination;
	}
	
	
	int noofpassenger(){
		int no;
		cout<<endl<<"                 Enter the no of passengers:";
		cin>>no;
		return no;
	}
};

class outputmodule{
	public:
	string source,destination;
	void initial(){
		system("CLS");
		cout<<"\n\n                       *********************        WELCOME TO FLIGHT RESERVATION SYSTEM      **********************"<<endl;
		cout<<"\n\n";
		cout<<"                 ***************************"<<endl;
		cout<<"                 *  Facilities Available:  *"<<endl;
		cout<<"                 ***************************"<<endl;
		cout<<"\n\n";
		cout<<"                 ENTER                     "<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   1. To Display List of Cities  ****"<<endl;
		cout<<"                 *****************************************"<<endl;
		cout<<"                 ****   2. To Book Ticket             ****"<<endl;
		cout<<"                 *****************************************"<<endl;
	
	}
	void list_cities(int N){
		datamodule o;
		cout<<endl;
		system("CLS");
		cout<<"\n\n                                             ****************************        WELCOME TO FLIGHT RESERVATION SYSTEM       **************************"<<endl;
		cout<<"\n\n";
		cout<<"                 The listed cities are:"<<endl;
		cout<<"                 *****************************************"<<endl;
		for(int i=0;i<N;i++){
		cout<<"                 *          "<<o.city[i]<<"            "<<endl;
		cout<<"                 *"<<endl;
		}
		cout<<"                 *****************************************"<<endl;
	}
	
	void ticket(int total_price,int no,string source,string destination){
		system("CLS");
		cout<<"\n\n                                     ****************************       E-TICKET       **************************"<<endl;
		
		cout<<endl<<"                                     Source:"<<source<<endl;
		cout<<endl<<"                                     Destination:"<<destination<<endl;
		cout<<endl<<"                                     Total No of Passengers:"<<no<<endl;
		cout<<endl<<"                                     Total Cost:"<<total_price<<endl;
		cout<<"\n\n                                     ****************************************************************************"<<endl;
	}
	
	void passengerdetailedticket(int no,string firstname[],string lastname[],string sex[],int age[],string email[], string c_no[]){
		for(int i=0;i<no;i++){
			cout<<"                                     Passenger "<<(i+1)<<" Details:"<<endl<<endl;
			cout<<"                                     First Name: "<<firstname[i]<<endl;
			cout<<"                                     Last Name: "<<lastname[i]<<endl;
			cout<<"                                     Sex: "<<sex[i]<<endl;
			cout<<"                                     Age: "<<age[i]<<endl;
			cout<<"                                     Email: "<<email[i]<<endl;
			cout<<"                                     Contact No: "<<c_no[i]<<endl;
			cout<<"\n\n                                     ****************************************************************************"<<endl;
		}
		int ch;
		cout<<endl<<"                                     Enter 1 to continue:";
		cin>>ch;
		if(ch==1){
			initial();
		}
	}
	
	int display_price(string source,string destination,int N){
		source=source;
		destination=destination;
		datamodule o;
		inputmodule in;
		int i,j,choiceofpassenger;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(source==o.city[i] && destination==o.city[j]){
					cout<<endl;
					if(ini[i].cost[j]==infinity){
						cout<<"                 There is no direct flight from "<<source<<" to "<<destination<<". So, Travel via other cities is only possible."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"					The Route is:"<<source;
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]==travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" . And,it is cheapest among all other paths..."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl;
					}
					else if((ini[i].cost[j]!=infinity)&&(ini[i].cost[j]>travel[i].cost[j])){
						cout<<"                 There is direct flight available from "<<source<<" to "<<destination<<" ."<<endl;
						cout<<"                 The Price is:"<<ini[i].cost[j]<<endl<<endl;
						cout<<"                 *****************************************"<<endl<<endl;
						cout<<"                 You can go via other cities that will cost you less than direct flight."<<endl;
						cout<<"                 The Price is:"<<travel[i].cost[j]<<endl<<endl;
						cout<<"					The Route is:"<<source;
						int c1=i,c2=j;
						while(c1!=c2){
							cout<<"-->"<<o.city[travel[c1].array[j]];
							c1=travel[c1].array[j];
						}
						cout<<endl<<endl;
						cout<<"                 Press 1 to go by direct flight and Press 2 to go via other cities: ";
						cin>>choiceofpassenger;
					}
					char c;
					cout<<endl;
					cout<<"                 Do You want to Continue(Y/N)?";
					cin>>c;
					if(c=='Y'){
						int no=in.noofpassenger();
						string firstname[no],lastname[no],sex[no],email[no];
						int age[no];
						string c_no[20];
						for(int i=0;i<no;i++){
							cout<<endl;
							cout<<"                 *****************************************"<<endl;
							cout<<"                                    Passenger "<<(i+1)<<":"<<endl<<endl;
							cout<<endl<<"                         First Name:";
							cin>>firstname[i];
							cout<<endl<<"                         Last Name:";
							cin>>lastname[i];
							cout<<endl<<"                         Sex(Male/Female/Other):";
							cin>>sex[i];
							cout<<endl<<"                         Age:";
							cin>>age[i];
							cout<<endl<<"                         Email Id:";
							cin>>email[i];
                          
                             cout<<endl<<"                        Contact no.(6 digits):";
                             cin>>c_no[i];
						}
						int total_price;
						if(choiceofpassenger==1){
							total_price=no*ini[i].cost[j];
						}
						else{
							total_price=no*travel[i].cost[j];
						}
						cout<<endl<<"                 The total Price is:"<<total_price<<endl;
						char y;
						cout<<"                 Do You want to confirm Your Ticket(Y/N)?";
						cin>>y;
						
						if(y=='Y'){
							filehandlingmodule f;
							payment();
							f.ticket(firstname,lastname,sex,age,email,c_no,source,destination,no);
							ticket(total_price,no,source,destination);
							passengerdetailedticket(no,firstname,lastname,sex,age,email,c_no);
						}
						else{
							cout<<endl<<"                 Thank You For choosing Us...";
							cout<<endl<<"                 Do You Want to Continue(Y/N)?";
							char ch;
							cin>>ch;
							if(ch=='Y'){
								initial();
							}
						return 0;
						}
					}
					else{
						cout<<endl<<"                 Thank You For choosing Us...";
						cout<<endl<<"                 Do You Want to Continue(Y/N)?";
						char ch;
						cin>>ch;
						if(ch=='Y'){
							initial();
						}
					}
					return 0;
				}
			}
		}
		cout<<"                 Sorry, There are no flights available connecting the cities..."<<endl;
		cout<<endl<<"                 Do You Want to Continue(Y/N)?";
		char ch;
		cin>>ch;
		if(ch=='Y'){
			initial();
		}
		return 0;
	}
};

int payment()//class for payment
{
  int choice1,bank,card,date,cvv,user_id;
    char password[10];

    //function declaration and definition for payment method
	showMenu:
        cout << "\n\n\nHow would you like to pay?:\n";
        cout << "\n\1.Debit Card(1) \n\2.Credit Card(2) \n\3.Net Banking(3)";
        cout << "\n\nEnter your choice";
        cin >> choice1;
        switch(choice1)//switch case
        {
        case 1://condition
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter CVV no.:";
            cin >> cvv;
            cout << "\nTransaction Successful\n";
			getch();
            break;
        case 2://condition
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
			getch();
            break;
        case 3://condition
            cout << "Banks Available: \1.Indian Bank(1) \2.Nabil Bank(2) \3.HDFC Bank(3) \4.ICICI Bank(4) \5.UPI(5)";
            cout << "\nSelect your bank:";
            cin >> bank;
            cout << "\nYou have selected:" << bank;
            cout << "\nEnter user no:";
            cin >> user_id;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
			getch();
            break;
        default://condition
            cout << "\nWrong input entered.\nTry again\n\n";
			goto showMenu;
           
        }
    }





int main(){
	int N;
	N=15;
string first[10],last[10],se[10],emal[15];
						int ag[10],n;
string c[20];	//Creating object for datamodule class
	
	datamodule obj;
	obj.costdeclaration();
	
	//Creating object for bellmanfordalgorithm class
	
	bellmanfordalgorithm ob;
	ob.algorithmic_implementation();
	
	string userchoice[2];
	
	//Creating object for inputmodule class
	inputmodule obj1;
	
	//Creating object for outputmodule
	outputmodule object;
	
	object.initial();
		
	while(1){
		int choice;
		cout<<"\n                 Enter Your Choice:";
		cin>>choice;
		switch(choice){
			case 1:
				object.list_cities(N);
				cout<<"\n\n                 Press 1 to Continue...";
				int cont;
				cin>>cont;
				if(cont==1){
					object.initial();
				}
				break;
			case 2:
				obj1.user_input(userchoice);
				//passing user inputted source and destination to display_price function of outputmodule
				object.display_price(userchoice[0],userchoice[1],N);
				break;
			case 3:
			object.passengerdetailedticket(n,first,last,se,ag,emal,c);
			break;	     
		}
		int n,ag,c;
		string first,last,se,emal;
	}
return 0;
}
