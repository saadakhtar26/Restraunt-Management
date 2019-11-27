/*
	Name: Hotel Management System
	Copyright: GNU General Public Liscence v3.0
	Author: Saad Rajpoot
	Date: 17/06/19 05:35
	Description: C++ code for Hotel Management System Program.
	
	Features:
	
		1.  Book Room
		2.  Use Room Service
		3.  Pay Bill
		4.  Display All Clients
		5.  Client Information
		6.  Clear Screen
		7.  Remove Client
		8.  Add Employee
		9.  Remove Employee
		10. Display Employee
		11. exit
*/

#include<iostream>
#include<fstream>
using namespace std;

struct clients{
	string name;
	int bill;
	int roomnumber;
};
clients cl[50];

struct employees{
	string name;
	int salary;
};
employees emp[50];

fstream file;

class restraunt{
	public:
		int bill,rmno,count=100;
		string name;
		
		void book(){
			int count=0;
			system("cls");
			
			file.open("restraunt.txt",ios::in);
			while(file>>rmno>>name>>bill){
				count++;
			}
			file.close();
			
			if(count<=4){
				file.open("restraunt.txt",ios::app);
				cout<<"Enter name : ";
				cin>>name;
				file<<count+101<<" "<<name<<" "<<2000<<"\n";
				cout<<"Client Added successfully !!";
				file.close();
			}
			else{
				cout<<"Rooms are full. Can not Book new Room\n";
			}
		}
		
		void pay(){
			system("cls");
			int i=0,pay=0,j=0;
			int rmno;
			
			cout<<"Enter the Room No : "<<endl;
			cin>>rmno;
			
			file.open("restraunt.txt",ios::in);
			while(file>>cl[i].roomnumber>>cl[i].name>>cl[i].bill){
				if(rmno==cl[i].roomnumber){
					cout<<"Room: "<<cl[i].roomnumber<<endl;
					cout<<"Name: "<<cl[i].name<<endl;
					cout<<"Bill: "<<cl[i].bill<<"\n"<<endl;
				}
				i++;
			}
			file.close();
			
			file.open("restraunt.txt",ios::in);
			int k=0;
			cout<<"Enter Payment Money :"<<endl;
			cin>>pay;
			while(file>>cl[k].roomnumber>>cl[k].name>>cl[k].bill){
				if(rmno==cl[k].roomnumber){
					cl[k].bill -= pay;
					cout<<"\nBill = " << cl[k].bill << "\n";
				}
				k++;
			}
			file.close();
			
			file.open("restraunt.txt",ios::out);
			while(j<i){
				file<<cl[j].roomnumber<<" "<<cl[j].name<<" "<<cl[j].bill<<"\n";
				j++;
			}
			file.close();
			cout<<"Bill Paid Successfully !!"<<endl;
		}
		
		void display(){
			system("cls");
			int rmno;
			file.open("restraunt.txt",ios::in);
			while(file>>rmno>>name>>bill){
				cout<<"Room No: "<<rmno<<endl;
				cout<<"Name: "<<name<<endl;
				cout<<"Bill: "<<bill<<"\n"<<endl;
			}
			file.close();
		}
		
		void info(){
			system("cls");
			int i=0;
			int rmno;
			file.open("restraunt.txt",ios::in);
			cout<<"Enter Room No : "<<endl;
			cin>>rmno;
			while(file>>cl[i].roomnumber>>cl[i].name>>cl[i].bill){
				if(rmno==cl[i].roomnumber){
					cout<<"Room Number: "<<cl[i].roomnumber<<endl;
					cout<<"Name: "<<cl[i].name<<endl;
					cout<<"Bill: "<<cl[i].bill<<"\n"<<endl;
				}
				i++;
			}
			file.close();
		}
		
		void billing(){
			system("cls");
			int i=0,j=0,rmno,billop,suits=0;
			file.open("restraunt.txt",ios::in);
			cout<<"Room Number : "<<endl;
			cin>>rmno;
			
			cout<<"1. Laundary"<<endl;
			cout<<"2. Breakfast"<<endl;
			cout<<"3. Lunch"<<endl;
			cout<<"4. Dinner"<<endl;
			cin>>billop;
			
			if(billop==1){
				cout<<"Enter Number of Suits: ";
				cin>>suits;
				bill = suits * 50;
			}
			else if(billop==2){
				bill = 200;
			}
			else if(billop==3){
				bill=300;
			}
			else if(billop==4){
				bill = 350;
			}
			else{
				cout<<"\nWrong Option !!\n";
			}
			
			while(file>>cl[i].roomnumber>>cl[i].name>>cl[i].bill){
				if(rmno==cl[i].roomnumber && bill>0){
					cl[i].bill+=bill;
				}
				else if(bill<=0){
					cout<<"Service Fee must be Greater than ZERO !!"<<endl;
				}
				i++;
			}
			file.close();
			
			file.open("restraunt.txt",ios::out);
			while(j<i){
				file<<cl[j].roomnumber<<" "<<cl[j].name<<" "<<cl[j].bill<<"\n";
				j++;
			}
			file.close();
			cout<<"Bill Added Successfully !!"<<endl;
		}
		
		void remove(){
			int rmno,bill,i=0,j=0,fix;
			string name;
			system("cls");
			cout<<"\nRoom no : ";
			cin>>rmno;
			
			file.open("restraunt.txt",ios::in);
			while(file>>cl[i].roomnumber>>cl[i].name>>cl[i].bill){
				if(rmno==cl[i].roomnumber){
					cout<<"Room Number: "<<cl[i].roomnumber<<endl;
					cout<<"Name: "<<cl[i].name<<endl;
					cout<<"Bill: "<<cl[i].bill<<"\n"<<endl;
					fix = i;
				}
				i++;
			}
			file.close();
			
			if(cl[fix].bill>0){
				cout<<"First Pay the Bills and then try Again\n";
			}
			else{
				file.open("restraunt.txt",ios::out);
				while(j<i){
					if(cl[j].roomnumber!=rmno){
						if(cl[j].roomnumber!=101){
							file<<cl[j].roomnumber-1<<" "<<cl[j].name<<" "<<cl[j].bill<<"\n";
						}
						else{
							file<<cl[j].roomnumber<<" "<<cl[j].name<<" "<<cl[j].bill<<"\n";
						}
					}
					j++;
				}
				file.close();
				cout<<"Client Deleted Successfully !!"<<endl;
			}
		}
		void empadd(){
			string empname;
			int empsalary;
			system("cls");
			file.open("employee.txt",ios::app);
			cout<<"Enter Name : ";
			cin>>empname;
			cout<<"Enter Salary : ";
			cin>>empsalary;
			file<<empname<<" "<<empsalary<<"\n";
			cout<<"Client Added successfully !!";
			file.close();
		}
		
		void emprem(){
			system("cls");
			int i=0;
			string empnm;
			
			file.open("employee.txt",ios::in);
			while(file>>emp[i].name>>emp[i].salary){
				i++;
			}
			file.close();
			
			cout<<"\nEnter Name: \n";
			cin>>empnm;
			
			int j=0;
			file.open("employee.txt",ios::out);
			while(j<i){
				if(emp[j].name!=empnm){
					file<<emp[j].name<<" "<<emp[j].salary<<"\n";
				}
				j++;
			}
			file.close();
			cout<<"Employee Deleted Successfully !!"<<endl;
		}
		
		void empdisplay(){
			system("cls");
			string name;
			int salary;
			file.open("employee.txt",ios::in);
			while(file>>name>>salary){
				cout<<"Name: "<<name<<endl;
				cout<<"Salary: "<<salary<<"\n"<<endl;
			}
			file.close();
		}
};

int main(){
 	restraunt obj;
	int op;
	cout<<"\n1.Book Room"<<endl;
	cout<<"2.Use Room Service"<<endl;
	cout<<"3.Pay Bill"<<endl;
	cout<<"4.Display All Clients"<<endl;
	cout<<"5.Client Information"<<endl;
	cout<<"6.Clear Screen"<<endl;
	cout<<"7.Remove Client"<<endl;
	cout<<"8.Add Employee"<<endl;
	cout<<"9.Remove Employee"<<endl;
	cout<<"10.Display Employee"<<endl;
	cout<<"11.exit"<<endl;
	cin>>op;
	
	if(op==1){
		obj.book();
		main();
	}
	else if(op==2){
		obj.billing();
		main();
	}
	else if(op==3){
		obj.pay();
		main();
	}
	else if(op==4){
		obj.display();
		main();
	}
	else if(op==5){
		obj.info();
		main();
	}
	else if(op==6){
		system("cls");
		main();
	}
	else if(op==7){
		obj.remove();
		main();
	}
	else if(op==8){
		obj.empadd();
		main();
	}
	else if(op==9){
		obj.emprem();
		main();
	}
	else if(op==10){
		obj.empdisplay();
		main();
	}
	else if(op==11){
		system("exit");
	}
	else{
		system("cls");
		cout<<"wrong option selected\n\n";
		main();
	}
	
	return 0;
}
