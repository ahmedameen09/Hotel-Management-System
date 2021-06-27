#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;

	// Hotel Managment system //
	
struct room 
{
	string no;
	string degree;
	string beds;
	string date;
	string time;
	string period;
	string client;
	string id;
	string cost;
	string phone;
}r1;
	// /////////////////
	
int choose ;
string back ;
	// /////////////////
	
void screen ();
void roomreservation ();
void checkout ();
void Reservedrooms ();
void availableroom ();
void customerinformation () ;
	// /////////////////
	
int main ()
{
	M :
	screen();
	cin >> choose ;
	switch (choose)
	{
		case 1 : 
					roomreservation();
					cout << "Do you want to back menu , Y or N : " ; 
					cin >> back ;
					if ( back == "Y" || back == "y" )
					{
						goto M ;
					}
					else {
						cout << "\n\t\tProgram Finished\n";
						exit(1);
					}
					break ;
		
		case 2 : 	checkout ();
					cout << "\nDo you want to back menu , Y or N : " ; 
					cin >> back ;
					if ( back == "Y" || back == "y" )
					{
						goto M ;
					}
					else {
						cout << "\n\t\tProgram Finished\n";
						exit(1);
					}
					
					break ;
		
		case 3 : 	Reservedrooms() ;
					cout << "\nDo you want to back menu , Y or N : " ; 
					cin >> back ;
					if ( back == "Y" || back == "y" )
					{
						goto M ;
					}
					else {
						cout << "\n\t\tProgram Finished\n";
						exit(1);
					}
					
					break ;
		
		case 4 : 	availableroom();
					cout << "\nDo you want to back menu , Y or N : " ; 
					cin >> back ;
					if ( back == "Y" || back == "y" )
					{
						goto M ;
					}
					else {
						cout << "\n\t\tProgram Finished\n";
						exit(1);
					}
					
					break ;
		
		
		case 5 : 	customerinformation () ;
					cout << "\nDo you want to back menu , Y or N : " ; 
					cin >> back ;
					if ( back == "Y" || back == "y" )
					{
						goto M ;
					}
					else {
						cout << "\n\t\tProgram Finished\n";
						exit(1);
					}
					
					break ;
					
		case 6 : 
					cout << "\n\t\tProgram Finished\n";
					exit(1);
					break ;
		
		default : 
					break ;
	}

}

void screen()
{
	system ("cls");
	cout << endl ;
	cout << "\t\t - Hotel Managment System -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	cout << "\t\t(1) Reserve Room             " << endl ;
	cout << "\t\t(2) Checkout Room            " << endl ;
	cout << "\t\t(3) The Reserved Rooms       " << endl ;
	cout << "\t\t(4) Availble Rooms           " << endl ;
	cout << "\t\t(5) Customer Information     " << endl ;
	cout << "\t\t(6) EXIT 					  " << endl ;
	cout << "\t\t=============================" << endl << endl ;
	cout << "\t\tChoose : " ;
}

void roomreservation ()
{
	ofstream outfile ;
	system ("cls");
	cout << endl ;
	cout << "\t\t  -     Reserve Room      -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	cout << "\t\tRoom no (From 1 to 100) : ";
	cin >> r1.no ;
	cout << "\n\t\tDegree : ";
	cin >> r1.degree;
	cout << "\n\t\tNumber of Beds : ";
	cin >> r1.beds ;
	cout << "\n\t\tDate : ";
	cin >> r1.date ;
	cout << "\n\t\tTime : ";
	cin >> r1.time ; 
	cout << "\n\t\tPeriod in days : ";
	cin >> r1.period ;
	cout << "\n\t\tClient Name : ";
	cin >> r1.client ;
	cout <<"\n\t\tNational ID : ";
	cin >> r1.id;
	cout <<"\n\t\tPhone : ";
	cin >> r1.phone;
	cout << "\n\t\tCost : ";
	cin >> r1.cost ;
	cout << "\n\t\t=============================" << endl << endl ;
	outfile.open (r1.no);
	outfile << r1.no << " " << "Reserved" << endl ;
	outfile << r1.client << " " << r1.id << " " << r1.phone << endl ;
	outfile << r1.period << " " << r1.date << " " << r1.time << endl ;
	outfile << r1.degree << " " << r1.beds << " " << r1.cost <<endl ;
	outfile.close();
}

void checkout ()
{
	int i ;
	string no2 , no1 , statue ;
	ifstream infile ;
	ofstream outfile;
	system ("cls");
	cout << endl ;
	cout << "\t\t  -     Checkout Room     -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	cout << "\t\tAll Rooms :-           " << endl << endl ;
	
	for ( i = 0 ; i <= 100 ; i++ )
	{
		no1 = i ;
		infile.open(no1);
		if (!infile)
		{
			infile.close();
		}
		else 
		{
			infile >> no1 >> statue ;
			cout << "\t\tRoom no : " << no1 << "\t " << statue << endl ;
			infile.close();
		}
	}
	
	k :
	cout <<"\n\t\tEnter Room Number : " ;
	cin >> no2 ;
	infile.open(no2) ;
	if (!infile)
	{
		cout << "\n\t\tYou Entered invalid number" << endl ;
		infile.close();
		goto k ;
	}
	else 
	{
		infile.close();
		outfile.open(no2);
		outfile << no2 << " " << "Empty" << endl ;
		cout << "\n\t\tRoom Checked out ..\n" ;
		cout << "\t\t=============================" << endl ;
		outfile.close();
	}
	
}
void Reservedrooms ()
{
	ifstream infile ;
	ofstream ofstream ;
	int i ;
	string no1 , statue , client , period ;
	system ("cls");
	cout << endl ;
	cout << "\t\t  -    Reserved Rooms     -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	
	for ( i = 0 ; i <= 100 ; i++ )
	{
		no1 = i ;
		infile.open(no1);
		if (!infile)
		{
			infile.close();
		}
		else 
		{
			infile >> no1 >> statue >> client >> period >> period >> period ;
			if (statue == "Empty")
			{
				infile.close();
			}
			else if (statue == "Reserved")
			{
			cout << "\t\tRoom no : " << no1 << "\tReserved " << "for " << period << " Days" << endl ;
			infile.close();
			}
		}
	}
	cout << "\n\t\t=============================" << endl ;
	
}

void availableroom ()
{
	ifstream infile ;
	ofstream ofstream ;
	int i ;
	string no1 , statue , client , period ;
	system ("cls");
	cout << endl ;
	cout << "\t\t  -    Availble Rooms     -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	
	for ( i = 0 ; i <= 100 ; i++ )
	{
		no1 = i ;
		infile.open(no1);
		if (!infile)
		{
			infile.close();
		}
		else 
		{
			infile >> no1 >> statue ;
			if (statue == "Reserved")
			{
				infile.close();
			}
			else if (statue == "Empty")
			{
			cout << "\t\tRoom no : " << no1 << "\tEmpty "<< endl ;
			infile.close();
			}
		}
	}
	cout << "\n\t\t=============================" << endl ;
	
}

void customerinformation ()
{
	ifstream infile ;
	ofstream outfile ;
	int i ;
	string no1 , statue , client , period , roomno , phone , id , cost , ch ;
	system ("cls");
	cout << endl ;
	cout << "\t\t  -  Customer Information  -\n" << endl ;
	cout << "\t\t=============================" << endl << endl ;
	cout << "\t\tReserved Rooms :-            " << endl << endl ;
	
	for ( i = 0 ; i <= 100 ; i++ )
	{
		no1 = i ;
		infile.open(no1);
		if (!infile)
		{
			infile.close();
		}
		else 
		{
			infile >> no1 >> statue >> client >> period >> period >> period ;
			if (statue == "Empty")
			{
				infile.close();
			}
			else {
			cout << "\t\tRoom no : " << no1 << "\tReserved " << "for " << period << " Days" << endl ;
			infile.close();
			}
		}
	}
	infile.close();
	cout << "\n\t\t=============================" << endl ;
	j :
	cout << "\n\t\tEnter Room Number : " ;
	cin >> roomno;
	infile.open(roomno) ;
	if (!infile)
		{
			cout << "\n\t\tYou Entered invalid Number" << endl ;
			infile.close();
			goto j ;
		}
	else 
		{
			infile >> no1 >> statue >> client ;
			infile >> id >> phone >> period ;
			infile >> cost >> cost >> cost >> cost >> cost ;
			if (statue == "Empty")
			{
				infile.close();
				cout << "\n\t\tRoom Is Empty\n";
			}
			else {
			cout << "\n\t\tMR : " << client << "\n\t\tID : " << id << "\n\t\tPhone : " << phone << endl ;
			cout << "\t\tPaid : " << cost ;
			infile.close();
			}
		}
	infile.close();
	cout << "\n\n\t\t=============================\n" << endl ;
	cout << "Export Customer Information ? Y or N : " ;
	cin >> ch ;
	if ( ch == "Y" || ch == "y" )
	{
		outfile.open("Exported Customer.txt");
		outfile << "\n\t\tMR : " << client << "\n\t\tID : " << id << "\n\t\tPhone : " << phone << endl ;
		outfile << "\t\tPaid : " << cost ;
		outfile.close();
		cout << "\n\t\tFile Exported" ;
	}
	else {
		
	}
	cout << endl ;
}