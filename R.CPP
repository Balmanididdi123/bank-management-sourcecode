
/* Bank Management System Project */


#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<ctype.h>
#include<stdio.h>
class Account
{
	private:
			int ano;
			char name[60];
			int balance;
			char type;
	public:
			void A_Create();
			void A_Display();
			void A_Deposit(int);
			void A_Withdraw(int);
			void A_Modify();
			void A_Report();

			int A_Return_Ano();
			int A_Return_Balance();
			char A_Return_Type();
};
void Account::A_Create()
{
	cout<<"\n\n********************************************************************************";
	cout<<"\n Enter the Account Number:";
	cin>>ano;
	cout<<"\n\n Enter the Name of the Account Holder:";
	cin>>name;
	cout<<"\n\nEnter Type of the Account(c:Current/s:Saving):";
	cin>>type;
	type=toupper(type);
	cout<<"\n\n Enter the Initial Amount(>=500 for Saving and >=1000 for Current):";
	cin>>balance;

}

void Account::A_Display()
{
	cout<<"\n********************************************************************************";
	cout<<"\n\t Account Number:\t"<<ano;
	cout<<"\n\n\t Account Holder List:\t"<<name;
	cout<<"\n\n\t Type of Account:\t"<<type;
	cout<<"\n\n\t Balance Amount:\t"<<balance<<"\n";
    //	cout<<"\n*************************************************************";

}



void Account::A_Deposit(int amount)
{
balance=balance+amount;
}


void Account::A_Withdraw(int amount)
{
balance=balance-amount;
}


void Account::A_Modify()
{
	cout<<"\n\tThe Account Number:"<<ano;
	cout<<"\n\n\tEnter the Name of the Account Holder:";
	cin>>name;
	cout<<"\n\n\tEnter Type of the Account(c:Current/s:Saving):";
	cin>>type;
	type=toupper(type);
	cout<<"\n\n\tEnter the Initial Amount(>=500 for Saving and >=1000 for Current):";
	cin>>balance;

}

void Account::A_Report()
{
	cout<<"\n\t"<<ano<<"\t\t"<<name<<"\t\t"<<type<<"\t\t"<<balance;
	//cout<<ano<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<balance;
}


int Account::A_Return_Ano()
{
	return ano;
}


int Account::A_Return_Balance()
{
	return balance;
}


char Account::A_Return_Type()
{
	return type;
}

//Function Declaration
void Introduction();
void Create_Account();
void Withdraw();
void Deposit();
void Balance_Enquiry();
void Display_Account_Holder_List();
void Modify_Account();
void Delete_Account();

//start of main function
int main()
{
	int num,ch;
	clrscr();
	Introduction();
	do
	{
		clrscr();
		cout<<"\n\t***********************************************************************";
		cout<<"\n\t     MENU    ";
		cout<<"\n\t***********************************************************************";
		cout<<"\n\t1.New Account";
		cout<<"\n\n\t2.Deposit Amount";
		cout<<"\n\n\t3.Withdraw Amount";
		cout<<"\n\n\t4.Balance Enquiry";
		cout<<"\n\n\t5.All Account Holder List";
		cout<<"\n\n\t6.modify an Account";
		cout<<"\n\n\t7.Close an Account";
		cout<<"\n\n\t8.Exit";
		cout<<"\n\t***********************************************************************";
		cout<<"\n\tEnter your choice:";
		cin>>ch;
		//cout<<"\n**************************************************************************************";
	       //	cin>>ch;
		clrscr();

		switch(ch)
		{
			case 1: Create_Account();
				break;
			case 2: Deposit();
				break;
			case 3:Withdraw();
			       break;
			case 4:Balance_Enquiry();
			       break;
			case 5:Display_Account_Holder_List();
			       break;
			case 6:	Modify_Account();
				break;
			case 7:Delete_Account();
				break;
			case 8: cout<<"\n\n\n\n********************************************************************************";
				cout<<"\n\n\t\t Thanks for Using Our Application";
				cout<<"\n\n\n********************************************************************************";
				break;
			default: cout<<"Please Enter Valid input";
		}
		getch();
	}while(ch!=8);
 return 0;
}
//end of main function
void Introduction()
{
	cout<<"\n\n\n\n\t*********************************************************************\n";

	cout<<"\n\t\t\t BANK MANAGEMENT SYSTEM \n";

	cout<<"\n\t*********************************************************************\n";

	cout<<"\n\t Project Guide:\t Prof.Patil.S.T \n";

	cout<<"\n\t*********************************************************************\n";

	cout<<"\n\t Project Partners:";
	cout<<"      1)Priyanka Shrinivas Diddi,Roll Number:12711";
	cout<<"\n\n\t\t\t\t2)Pooja Suryakant Paramshetti,Roll Number:12709";

	cout<<"\n\n\t*********************************************************************\n";

	getch();
}
void Create_Account()
{
	Account obj;
	ofstream outfile;
	outfile.open("account.dat",ios::binary | ios::app);
	if(!outfile)
	{
		cout<<"ERROR in file opening";
		return;
	}
	else
	{
	obj.A_Create();
	outfile.write((char*) &obj,sizeof(Account));
	cout<<"\n********************************************************************************";
	cout<<"\n\t                  Account Created Successfully                             ";
	cout<<"\n********************************************************************************";
	}
       outfile.close();
}

void Deposit()
{
	int amount,accountno;
	int found=0;
	Account obj;
	fstream file;
	file.open("account.dat",ios::binary | ios::in | ios::out);
	if(!file)
	{
		cout<<"\nERROR in File Opening";
		return;
	}
	else
	{
			cout<<"\n********************************************************************************";

		cout<<"\n\t Please Enter Account Number:";
		cin>>accountno;
		while(file.read((char*)&obj,sizeof(Account)))
		{
				/*file.seekg(0,ios::beg);
				while(!file.eof())
				{*/
			if(obj.A_Return_Ano()==accountno)
			{
				obj.A_Display();
				found=1;
				cout<<"\n\n Please Enter the Amount to be deposited:";
				cin>>amount;
				obj.A_Deposit(amount);
				int pos=(-1)*sizeof(Account);
				file.seekp(pos,ios::cur);
				file.write((char*)&obj,sizeof(Account));
			}
		}
	}
		if(found==0)
		{
		  cout<<"\n********************************************************************************";

			cout<<"\n \tAccount Number Does not Exists";

		  cout<<"\n\n********************************************************************************";


		}
		else
		{
	cout<<"\n********************************************************************************";

		cout<<"\n\tAmount Deposited Successfully";

	cout<<"\n\n********************************************************************************";

		}
	/*file.seekp(sizeof(Account));*/


	file.close();
}


void Withdraw()
{
	int amount,accountno;
	int found=0;
	Account obj;
	fstream file;
	file.open("account.dat",ios::binary | ios::in | ios::out);
	if(!file)
	{
		cout<<"\nERROR in File Opening";
		return;
	}
	else
	{
		cout<<"\n********************************************************************************";

		cout<<"\n\t Please Enter Account Number:";
		cin>>accountno;
       //	cout<<"\n********************************************************************************";

		while(file.read((char*)&obj,sizeof(Account)))
		{
		// file.seekg(0,ios::beg);
		//while(!file.eof())
		//{
			if(obj.A_Return_Ano()==accountno)
			{

				//obj.A_Display();
				cout<<"\n\t Please Enter Amount to be Withdraw:";
				cin>>amount;
				int currentbal=obj.A_Return_Balance();
			    int bal=currentbal-amount;
				if((bal<500 && obj.A_Return_Type()=='S') || (bal<1000 && obj.A_Return_Type()=='C'))
				{
	cout<<"\n********************************************************************************";

					cout<<"\n \t  Insufficient Balance";
	cout<<"\n********************************************************************************";

					return;
				}
				else
				{
				found=1;
				obj.A_Withdraw(amount);
				}
			int pos=(-1)*sizeof(Account);
			file.seekp(pos,ios::cur);
			file.write((char*)&obj,sizeof(Account));
		      }
		}
	}
		if(found==0)
		{

   //  cout<<"\n********************************************************************************";

			cout<<"\n \tAccount Number Does not Exists";

	cout<<"\n\n********************************************************************************";


		}
		else
		{
	cout<<"\n********************************************************************************";

		cout<<"\n\tAmount Withdrawal done Successfully";

	cout<<"\n\n********************************************************************************";

		}
	file.close();
}

void Balance_Enquiry()
{
	Account obj;
	int flag=0,num;
	ifstream infile;
	infile.open("account.dat",ios::binary);
	if(!infile)
	{
		cout<<"File could not be open!!!";
		return;
	}
       //	cout<<"\n********************************************************************************";

		cout<<"\n\n\tPlease Enter the Account Number:";
		cin>>num;
	cout<<"\n********************************************************************************";


		while(infile.read((char*) &obj,sizeof(Account)))
		{
			if(obj.A_Return_Ano()==num)
			{
				cout<<"\n\tBALANCE DETAILS:\n";
				obj.A_Display();
				cout<<"\n********************************************************************************";

				flag=1;
			 }
		}
		infile.close();
		if(flag==0)
		{
     //	cout<<"\n********************************************************************************";

			cout<<"\n \tAccount Number Does not Exists";

	cout<<"\n\n********************************************************************************";

		}


}
void Display_Account_Holder_List()
{
	Account obj;
	ifstream infile;
	infile.open("account.dat",ios::binary);
	    if(!infile)
		{
		cout<<"file could not be open";
		return;
		}
	cout<<"\n********************************************************************************";

		cout<<"\n\t Account Holders List:";
		cout<<"\n\t=======================================================\n";
		cout<<"\tA/C no.      NAME               TYPE         BALANCE";
		cout<<"\n\t=======================================================\n";
		while(infile.read((char*) &obj,sizeof(Account)))
		{
		   obj.A_Report();
		}
	cout<<"\n\n********************************************************************************";


      infile.close();
}

void Delete_Account()
{
	int num;
	Account obj;
	ifstream infile;
	ofstream outfile;
	infile.open("account.dat",ios::binary | ios::in);
	if(!infile)
	  {
	       cout<<"file could not be open!!!";
		return;
	   }
	cout<<"\n********************************************************************************";

	       cout<<"\nPlease Enter the Account Number:";
	       cin>>num;
      //	cout<<"\n********************************************************************************";

		outfile.open("temp.dat",ios::binary | ios::out);
		infile.seekg(0,ios::beg);
		while(infile.read((char*) &obj,sizeof(Account)))
		{
		   if(obj.A_Return_Ano()!=num)
		     {
		      outfile.write((char*)&obj,sizeof(Account));
		      }
		}
	       outfile.close();
	       infile.close();
		remove("account.dat");
		rename("temp.dat","account.dat");
	cout<<"\n********************************************************************************";

	       cout<<"\n\tAccount Deleted Successfully";
	cout<<"\n\n********************************************************************************";

}

void Modify_Account()
{
	int found=0,accountno;
	Account obj;
	fstream file;
	file.open("account.dat",ios::binary | ios::in | ios::out);
	if(!file)
	{
		cout<<"\n file could not be open";
		return;
	}
	cout<<"\n********************************************************************************";

	cout<<"\n\n\t Please Enter Account Number:";
	cin>>accountno;
       //	cout<<"\n********************************************************************************";

	       while(file.read((char*)&obj,sizeof(Account)) && found==0)
		{

			if(obj.A_Return_Ano()==accountno)
			{
				obj.A_Display();
      //	cout<<"\n********************************************************************************";

				cout<<"\n\t Please Enter the New Details for an Existing Account: ";
				obj.A_Modify();
				int pos=(-1)*sizeof(Account);
				file.seekp(pos,ios::cur);
				file.write((char*)&obj,sizeof(Account));
				found=1;
			}
		}
	file.close();

		if(found==0)
		{
	cout<<"\n********************************************************************************";

			cout<<"\n\tAccount Does not Exists";
	cout<<"\n********************************************************************************";

		}
		else
		{
	cout<<"\n********************************************************************************";

		cout<<"\n\t Account Modified Successfully";
	cout<<"\n\n********************************************************************************";

		}


}