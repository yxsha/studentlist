//header that defines the standard input/output stream objects
#include <iostream>
//needed in order to use the string data type
#include <string>
//needed in order to construct lists
#include <list>

//make all the things under the std namespace available without having to prefix std:: before each of them
using namespace std;

//group of data about each entry grouped under "student"
struct student {
  char firstname[10];
  char lastname[10];
  int studentid;
  float gpa;
  student(){}
	~student(){}
	struct student *next;
};
student *head = NULL;

//prompts user to make a choice from the following
void mainmenu() {
  cout<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"            main menu             "<<endl;
	cout<<"    choose from the following:    "<<endl;
	cout<<"'A'dd a record                    "<<endl;
	cout<<"'P'rint a record                  "<<endl;
  cout<<"'D'elete a record                 "<<endl;
	cout<<"'Q'uit program                    "<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<endl;
}

//adds new entry
void add() {
  cout << "add entry: " << endl;
  struct student *temp, *alt;
  temp = new student;

  cout << "please enter the student's first name: ";
  cin >> temp-> firstname;
  cout << "please enter the student's last name: ";
  cin >> temp-> lastname;
  cout << "please enter the student's student id: ";
  cin >> temp-> studentid;
  cout << "please enter the student's gpa: ";
  cin >> temp-> gpa;
  temp->next = NULL;
  if(head == NULL)
		head = temp;
	else
	{
		alt = head;
		while(alt->next != NULL)
		{
			alt = alt->next;
		}
		alt->next = temp;
	}

}
//prints all the students currently stored
void print() {

	cout<<endl;
	cout<<"all entries:";
	cout<<endl;
	struct student *temp;
	temp = head;
	do
	{
    //if there are no entries
		if(temp == NULL)
			cout<<"nothing follows."<<endl;
		else
		{
		cout<<temp->firstname<<" "<<temp->lastname<<","<<temp->studentid<<","<<temp->gpa<<""<<endl;
		temp = temp->next;
		}
	}
	while(temp != NULL);
}
//prompts user for student id to delete, and removes student
void deleterecord() {
	cout<<endl;
	cout<<"delete record:"<<endl;
	cout<<endl;
	student *del;
	del = head;
	del = del->next;
	if(del->next == NULL)
		cout<<"end of the list."<<endl;
	else
		del = del->next;
	if(del == head)
		cout<<"beginning of list."<<endl;
	else
	{
		student *prev;
		prev = head;
		while(prev->next != del)
		{
			prev = prev->next;
		}
		del = prev;
	}
	cout<<endl;
	cout<<"please enter the student id you wish to delete: ";
	cin>>del->studentid;
	if(del->next == NULL)
		cout<<"nothing follows."<<endl;
	else
	{
		student *temp;
		temp = del->next;
		del->next = temp->next;
		delete temp;
	}
}
//decides what function to go to if user picks either add, print, delete, or quit
int main() {
  char choice;
  do {
    mainmenu();
    cout << "please enter either 'A', 'P', 'D', or 'Q': ";
    if (cin>> choice)
    switch(choice)
    {
      case 'A':
      add();
      break;

      case 'P':
      print();
      break;

      case 'D':
      deleterecord();
      break;

  }

}
//if user picks quit 
while(choice != 'Q'); 
cout << endl;
cout << "terminating.." << endl;

system("pause");
return 0;
}