/* HEADER FILES */ 
#include < fstream.h >
#include < iomanip.h >
#include < math.h >
#include < stdio.h >
#include < conio.h >
#include < string.h >
#include < process.h >
#include < ctype.h >

    /* Defining account class */
    class account {
	char name[30];
	char address[60];
	long acc_no;
	long phone_no;
	public: void add();
	void modify();
	void del();
	void display();
	void generate();
    };
account obj;
int bil_ctr = 1; //Counter variable for bill ID
/*Function for counting number of digits in an integer*/
int numdigits(long n) {
	return (log10(n) + 1);
    }

void main() {
	char ch1, ch2;
	while (1) {
	    clrscr();
	    gotoxy(30, 5);
	    cout << "VODAFONE";
	    gotoxy(30, 6);
	    cout << "______________________";
	    gotoxy(30, 8);
	    cout << "'M'anage Customer Records";
	    gotoxy(30, 10);
	    cout << "'D'isplay list of Customers";
	    gotoxy(30, 12);
	    cout << "'G'enerate Bill";
	    gotoxy(30, 14);
	    cout << "'E'xit";
	    gotoxy(30, 30);
	    cout << endl << "\t\t\tEnter Your Choice:";
	    ch1 = getch();
	    ch1 = toupper(ch1);
	    switch (ch1) {
		case 'D':
		    obj.display();
		    break;
		case 'G':
		    obj.generate();
		    break;
		case 'E':
		    clrscr();
		    exit(1);
		case 'M':
		    ch2 = 'A';
		    do {
			clrscr();
			gotoxy(30, 5);
			cout << "VODAFONE";
			gotoxy(30, 6);
			cout << "__________________________";
			gotoxy(30, 8);
			cout << "'A'dd new record";
			gotoxy(30, 10);
			cout << "'M'odify existing record";
			gotoxy(30, 12);
			cout << "'D'elete existing record";
			gotoxy(30, 14);
			cout << "'E'xit";
			gotoxy(30, 16);
			cout << "Enter your choice";
			ch2 = getch();
			ch2 = toupper(ch2);
			switch (ch2) {
			    case ('A'):
				obj.add();
				break;
			    case ('M'):
				obj.modify();
				break;
			    case ('D'):
				obj.del();
				break;
			    case ('E'):
				break;
			} //End of inner switch-case block
		    } while (ch2 != 'E'); //End of do-while block
	    } //End of outer switch-case block
	} //End of while block
    } //End of main()
    /*Function for adding a new customer record*/
void account::add() {
	char ch1;
	fstream fptr1;
	fptr1.open("db.dat", ios::app);
	if (!fptr1) {
	    cout << "Cannot open the db.dat file!";
	    getch();
	    return;
	}
	clrscr();
	gotoxy(30, 5);
	cout << "Enter the new customer's details..";
	while (1) {
	    gotoxy(30, 8);
	    cout << "Name : ";
	    gets(name);
	    if (strlen(name) == 0) {
		gotoxy(30, 30);
		clreol();
		cout << "Name cannot be left blank!";
	    } else {
		gotoxy(30, 30);
		clreol();
		break;
	    }
	}
	while (1) {
	    gotoxy(30, 10);
	    cout << "Adress : ";
	    gets(address);
	    if (strlen(address) == 0) {
		gotoxy(30, 30);
		clreol();
		cout << "Adress cannot be left blank";
	    } else {
		gotoxy(30, 30);
		clreol();
		break;
	    }
	}
	while (1) {
	    gotoxy(30, 12);
	    cout << "Ph. No : ";
	    cin >> phone_no;
	    if (numdigits(phone_no) != 7) {
		gotoxy(54, 12);
		clreol();
		gotoxy(30, 30);
		clreol();
		cout << "Phone no must be of seven digits";
	    } else {
		gotoxy(30, 30);
		clreol();
		break;
	    }
	}
	while (1) {
	    gotoxy(30, 14);
	    cout << "Acc no : ";
	    cin >> acc_no;
	    if (numdigits(acc_no) != 5) {
		gotoxy(54, 14);
		clreol();
		gotoxy(30, 30);
		clreol();
		cout << "Account no must be of five digits";
	    } else {
		gotoxy(30, 30);
		clreol();
		break;
	    }
	}
	gotoxy(30, 30);
	cout << "'S'ave and Exit";
	gotoxy(30, 32);
	cout << "'E'xit without saving";
	ch1 = getch();
	ch1 = toupper(ch1);
	switch (ch1) {
	    case ('S'):
		fptr1.write((char * ) this, sizeof(obj));
		fptr1.close();
		return;
	    case ('E'):
		fptr1.close();
		return;
	}
    } //End of add()
    /*Function for modifying a customer record*/
void account::modify() {
	char ch;
	long input_no;
	int flag = 0;
	fstream fptr1, fptr2;
	fptr1.open("db.dat", ios:: in );
	if (!fptr1) {
	    cout << "Cannot open the db.dat file";
	    getch();
	    return;
	}
	fptr2.open("dbtemp.dat", ios::out);
	if (!fptr2) {
	    cout << "Cannot open the dbtemp.dat file!";
	    getch();
	    return;
	}
	clrscr();
	gotoxy(20, 3);
	cout << "Enter the phone no whose record is to be modified: ";
	cin >> input_no;
	while (fptr1.read((char * ) this, sizeof(obj))) {
	    if (input_no == phone_no) {
		flag = 1;
		gotoxy(20, 5);
		cout << "Name        " << name;
		gotoxy(20, 6);
		cout << "Address     " << address;
		gotoxy(20, 7);
		cout << "Acc No    " << acc_no;
		gotoxy(20, 10);
		cout << "Modify this cutomer record (Y/N) ";
		ch = getch();
		ch = toupper(ch);
		if (ch == 'Y') {
		    gotoxy(20, 14);
		    cout << "Enter the customer's modified details..";
		    while (1) {
			gotoxy(20, 16);
			cout << "Name  : ";
			gets(name);
			if (strlen(name) == 0) {
			    gotoxy(30, 30);
			    clreol();
			    cout << "Name cannot be left blank!";
			} else {
			    gotoxy(30, 30);
			    clreol();
			    break;
			}
		    }
		    while (1) {
			gotoxy(20, 18);
			cout << "Address : ";
			gets(address);
			if (strlen(address) == 0) {
			    gotoxy(30, 30);
			    clreol();
			    cout << "Address cannot be left blank";
			} else {
			    gotoxy(30, 30);
			    clreol();
			    break;
			}
		    }
		    while (1) {
			gotoxy(20, 20);
			cout << "Ph. No. : ";
			cin >> phone_no;
			if (numdigits(phone_no) != 7) {
			    gotoxy(44, 20);
			    clreol();
			    gotoxy(30, 30);
			    clreol();
			    cout << "Phone no must be of seven digits";
			} else {
			    gotoxy(30, 30);
			    clreol();
			    break;
			}
		    }
		    while (1) {
			gotoxy(20, 22);
			cout << "Acc no : ";
			cin >> acc_no;
			if (numdigits(acc_no) != 5) {
			    gotoxy(44, 22);
			    clreol();
			    gotoxy(30, 30);
			    clreol();
			    cout << "Account no must be of five digits";
			} else {
			    gotoxy(30, 30);
			    clreol();
			    break;
			}
		    }
		}
	    }
	    fptr2.write((char * ) this, sizeof(obj));
	}
	fptr1.close();
	fptr2.close();
	if (ch == 'N') return;
	if (flag == 0) {
	    gotoxy(20, 5);
	    clreol();
	    cout << "Record for telephone number " << input_no << " does not exist";
	    getch();
	    return;
	} else {
	    gotoxy(20, 30);
	    cout << "Customer record modified and updated successfully";
	    getch();
	}
	fptr1.open("db.dat", ios::out);
	fptr2.open("dbtemp.dat", ios:: in );
	while (fptr2.read((char * ) this, sizeof(obj))) fptr1.write((char * ) this, sizeof(obj));
	fptr1.close();
	fptr2.close();
    } //End of Modify()
    /* Function for deleting a customer record */
void account::del() {
	char ch;
	long input_no;
	int flag = 0;
	fstream fptr1, fptr2;
	fptr1.open("db.dat", ios:: in );
	if (!fptr1) {
	    cout << "Cannot open the db.dat file!";
	    getch();
	    return;
	}
	fptr2.open("dbtemp.dat", ios::out);
	if (!fptr2) {
	    cout << "Cannot open the dbtemp.dat file";
	    getch();
	    return;
	}
	clrscr();
	gotoxy(20, 3);
	cout << "Enter phone whose record is to be deleted: ";
	cin >> input_no;
	while (fptr1.read((char * ) this, sizeof(obj))) {
	    if (input_no == phone_no) {
		flag = 1;
		gotoxy(20, 5);
		cout << "Name " << name;
		gotoxy(20, 6);
		cout << "Address " << address;
		gotoxy(20, 7);
		cout << "Acc No " << acc_no;
		gotoxy(20, 10);
		cout << "Delete this customer record (Y/N) ";
		ch = getch();
		ch = toupper(ch);
		if (ch == 'N') fptr2.write((char * ) this, sizeof(obj));
	    } else fptr2.write((char * ) this, sizeof(obj));
	}
	fptr1.close();
	fptr2.close();
	if (ch == 'N') return;
	if (flag == 0) {
	    gotoxy(20, 5);
	    cout << "Record for telephone number " << input_no << " does not exist";
	    getch();
	    return;
	} else {
	    gotoxy(20, 12);
	    cout << "Customer record for " << input_no << " deleted successfully";
	    getch();
	}
	fptr1.open("db.dat", ios::out);
	fptr2.open("dbtemp.dat", ios:: in );
	while (fptr2.read((char * ) this, sizeof(obj))) fptr1.write((char * ) this, sizeof(obj));
	fptr1.close();
	fptr2.close();
    }
    //End of del()
    /* Function for displaying Customer Records */
void account::display() {
	fstream fptr1;
	int count;
	fptr1.open("db.dat", ios:: in );
	if (!fptr1) {
	    cout << "Cannot open the db.dat file!";
	    getch();
	    return;
	}
	clrscr();
	gotoxy(2, 2);
	cout << "Name";
	gotoxy(2, 3);
	cout << "____";
	gotoxy(30, 2);
	cout << "Phone no";
	gotoxy(30, 3);
	cout << "_________";
	gotoxy(55, 2);
	cout << "Account Number";
	gotoxy(55, 3);
	cout << "____________";
	count = 4;
	while (fptr1.read((char * ) this, sizeof(obj))) {
	    gotoxy(2, count);
	    cout << name;
	    gotoxy(30, count);
	    cout << phone_no;
	    gotoxy(60, count);
	    cout << acc_no;
	    count++;
	}
	gotoxy(22, 30);
	cout <<endl<<endl<< "Press any key to go back the previous menu ";
	getch();
	fptr1.close();
    } //End of display()
    /*Function for generating telephone bill*/
void account::generate() {
	long input_no;
	char choice;
	int flag = 0;
	int lcalls, tcalls, icalls;
	float bill, tbill;
	float rental = 145.82;
	fstream fptr1;
	fptr1.open("db.dat", ios:: in );
	if (!fptr1) {
	    cout << "Cannot open the db.dat file!";
	    getch();
	    return;
	}
	clrscr();
	gotoxy(2, 2);
	cout << "Enter the telephone number:  ";
	cin >> input_no;
	flag = 0;
	while (fptr1.read((char * ) this, sizeof(obj))) {
	    if (flag == 1) break;
	    if (phone_no == input_no) {
		clrscr();
		gotoxy(30, 2);
		cout << "VODAFONE";
		gotoxy(2, 5);
		cout << "Name  :   " << name;
		gotoxy(40, 5);
		cout << "Address   :  " << address;
		gotoxy(2, 7);
		cout << "Account No.  :  " << acc_no;
		gotoxy(40, 7);
		cout << "Telephone No. :  " << phone_no;
		gotoxy(2, 9);
		cout << "Bill No.  : _" << bil_ctr;
		bil_ctr++;
		gotoxy(40, 9);
		cout << "Number of local Calls: ";
		gotoxy(65, 16);
		cin >> lcalls;
		gotoxy(2, 18);
		cout << "Number of trunk Calls: ";
		gotoxy(65, 18);
		cin >> tcalls;
		gotoxy(2, 20);
		cout << "Number of ISD Calls: ";
		gotoxy(65, 20);
		cin >> icalls;
		bill = lcalls * 0.25 + tcalls + icalls * 5;
		gotoxy(2, 32);
		cout << "Total Call Charges : ";
		gotoxy(65, 32);
		cout << setprecision(2);
		cout << bill;
		gotoxy(2, 33);
		cout << "Monthly Charges : ";
		gotoxy(65, 33);
		cout << rental;
		gotoxy(2, 34);
		cout << "Service tax (12.36%) : ";
		gotoxy(65, 34);
		cout << (bill + rental) * 0.1236;
		tbill = bill + rental + (bill + rental) * 0.1236;
		gotoxy(2, 36);
		cout << tbill;
		gotoxy(2, 37);
		cout << tbill + 110;
		gotoxy(55, 45);
		cout <<endl<<endl<< "Press any key to continue";
		getch();
		flag = 1;
	    }
	}
	if (flag == 0) {
	    gotoxy(2, 4);
	    cout << "Record for telephone number " << input_no << " does not exist";
	    getch();
	}
	fptr1.close();
    } //End of generate()

