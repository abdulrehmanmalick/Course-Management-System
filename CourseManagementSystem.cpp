
/*     
Project Outline : 

The Project you are about to see is based On C++ Basic Programming. Only basic Functions are used. 
This is a program on Course Management System. Around 10 to 12 external files are added in this program. 
Yes I took help from some people but I made sure they didnt have the same project. Few of the things such as trim function is commented out. As it was copied from Google. The Concepts I have used in this program are either from my own thinking or from the help of google or some friends. The Program was entirely designed by me by some external help. Sir Raja Hashim also talked to me about my project a lot of times and helped me.
This Project has a lot of libraries and a lot of variables declared in it. 
File Handling was the one thing that gave me a hard time. But after a thorough research and a lot of practice.I find Filehandling the easiest part of C++.
I have used the remove and rename function to Remove the main Files and replace them with temporary files by changing their name. 

User Defined Functions have not been used in my program. 
Arrays, FileHandling, For Loop, While Loop, Switch-Case, Different Libraries, Strings, Windows Clearscreen function, Rename,Remove, goto function, these things are used in my program

New things learned : goto function , filehandling , stdlib.h(header File), fstream header file, renaming and replacing File, knowledge about functions, benifits of using functions, proper debugging line by line, system cls and pause, ios::app,in,out,trunch  ,eof(), proper looping,trimming, compareing strings, checking the length of strings

PS : The instructions were not very clear to me as the Project was divided into 3 parts. And with every part a new thing was asked. If those things were mentioned at the top and this project would be done in a lot more efficient way.
*/
//You will find a lot of places Not commented. But I have tried to make sure that the admin section is thoroughly commented as most of the admin's logic is used in the rest of the program.

//Code

///////////////////////////////HeaderFiles////////////////////////////////////
#include <iostream> //INPUT OUTPUT STREAM
#include <stdlib.h> //To use the clear screen function
#include <string>	//String helps us with getine function
#include <fstream>	//Gives access to the files
// #include <errno.h> //This Was added to check some errors. but since the checking error is commented out
// #include <string.h>

using namespace std;

/*//trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std:
:string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}*/

int main()
{
	//Declaring Variables
	int choice;	 //Main Menu choice
	int choice2; //Admin menu choice
	int choice3; //inst edit choice
	int i;		 //UsedInForLoop
	char ans;	 //To give Yes or No answer
	//Inructor
	string inst_name[30]; //Name
	string inst_id[30];	  //ReggistrationId
	string inst_fac[30];  //faculty
	string i_id;		  //This is to compare the stored and entered name to delete the record

	//Student
	string std_name[30]; //Name
	string std_reg[30];	 //ReggistrationId
	string std_fac[30];	 //faculty
	string studentid;	 //This is to compare the stored and entered name to delete the record
	string s_id;

	//NewPassword
	//admin username and pass
	string ad_username; //AdminUsername to Login
	string ad_pw;		//AdminPassword to Login
	string ad_pwNew;	//Incase admin wants to change the password
	string Temp;
	string admin;	 //To Compare the stored and entered admin username
	string password; //To Compare the stored and entered admin password

	int attempt = 0; //To Give the number of tries incase user enters the wrong username and password

	//Instructor username and pass
	string inst_username; //Instructor username to login
	string inst_pw;		  //Instructor password to login
	string instructor;	  //To Compare the stored and entered instructor username
	string password2;	  //To Compare the stored and entered instructor password
	string inst_pwNew;	  //Incase instructor wants to change the password

	//Student username and pass
	string std_username; //Student username to login
	string std_pw;		 //Student password to login
	string student;		 //To Compare the stored and entered instructor password
	string password3;	 //To Compare the stored and entered instructor password
	string std_pwNew;	 //Incase student wants to change the password

	string course[100] = {"0"}; //To Register Courses
	string coursename;			//To Compare the Stored coursed and entered course
	string data;				//Used to Cout the uploaded assignments,quizes etc..
	string data2;				//Used to Cout the marks for assignments,quizes etc..

	///////////////////////////////TitlePage//////////////////////////////
	system("CLS"); //clearscreen so that a new page is shown after every step
	cout << "\n\n\n";
	cout << "\t\t\t\t\tCOURSE MANAGEMENT SYSTEM" << endl;
	cout << endl
		 << endl;
	cout << endl
		 << endl;
	cout << endl
		 << endl;
	cout << "\t\tDesigned by : Abdul-Rehman" << endl;
	cout << "\t\tRegistration Number : 2020015" << endl;
	cout << "\t\tFaculty : BS-AI" << endl;
	system("PAUSE"); //if we dont add the pause the program will directly clear the screen therefore we wont be able to see anything.
	system("CLS");

	//All the external files that have been used in this program
	fstream indata;		 //InstructorRecord
	fstream sndata;		 //StudentRecord
	fstream courses;	 //CoursesAvailable/Registered
	fstream assignment;	 //AssignmentUploaded by teacher
	fstream quizes;		 //QuizUploaded by Teacher
	fstream mid;		 //MidUploaded by Teacher
	fstream final;		 //FinalUploaded by Teacher
	fstream lec;		 //LecturesUploaded by Teacher
	fstream asgn;		 //AssignmentMarks Uploaded by Teacher
	fstream q_marks;	 //QuizMarks Uploaded by Teacher
	fstream mid_marks;	 //MidMarks Uploaded by Teacher
	fstream final_marks; //FinalMarks Uploaded by Teacher
	ofstream tdata;		 //This is a temporary file used in alot of plaes like deletion of a record or editing a record or changing the passwords
	fstream subdata;	 //Course Subsribe File
						 // Student Message
	ofstream SendStudentMsg;
	SendStudentMsg.open("StudentMsg.txt", ios::out | ios::app);  //app means append(prevents ovwerwriting while writing in external file,out menas writing in external file)
	string StdntMessage;

	ifstream RecieveMsg;
	RecieveMsg.open("StudentMsg.txt", ios::in | ios::app); //in means reading from a file
	string RecMsg;

	system("CLS");
main:
	system("CLS");

	////////////Start of the Main Program
	system("CLS");
	cout << "Press 1 for Admin console" << endl;	  //Gives access to admin console
	cout << "Press 2 for Instructor console" << endl; //Gives access to instructor console
	cout << "Press 3 for Student console" << endl;	  ////Gives access to student console
	cout << "Press 4 to Exit" << endl;				  //Closes the program

	cin >> choice;
	//system ("PAUSE");
	system("CLS");

	if (choice == 1)
	{ //ifStarted
		/////AdminPortal
		system("CLS");

		cout << "Welcome to the Admin Portal of GIKI-CMS" << endl;
		cout << endl
			 << endl;
		cout << endl
			 << endl;

		ifstream in("adminusrpw.txt"); //FileHanding. Ifstream means Input Fstream. In is just a declared variable
		in >> admin;				   //A variable to compare the entered username and pw to the stored username and pw
		in >> password;

		// cout << admin << password << endl; //This is just to check the admin and password

	pass:

		//ad_username = giki
		//ad_pw = pw

		cout << "Enter Username" << endl;
		cin >> ad_username; //adminUsername

		cout << "Enter password" << endl;
		cin >> ad_pw;

		while (attempt < 3)								   //WhileLoop here is used just incase admin enters the wrong username and password
		{												   //whileStarted
			if (ad_username == admin && ad_pw == password) //Comparison of stored usrname and pw and the usr and pw entered
			{
				cout << "Access Granted" << endl;
				system("PAUSE");
				break;
			}
			if (ad_username != admin || ad_pw != password) //IfUsrPwNotEqual then TryAgain. 3 tries allowed
			{
				cout << "Try Again!" << endl;
				attempt++;
				if (attempt < 3)
				{
					goto pass; //GoTofunction here is used to take the program back to where it asks for usr and pw
				}

				if (attempt >= 3)
				{
					cout << "You have reached your limit of trying the username and password" << endl;
					system("PAUSE");
					exit(0); //IfUserEnters the usr pw wrong 3 times then the program will end
				}
			}
		} //whileEnded
		system("CLS");

		system("CLS");
	start:
		system("CLS");

		system("CLS");
		cout << "Press 1 to add a new instructor" << endl;		//Instructor Details
		cout << "Press 2 to add a new student" << endl;			//Student Details
		cout << "Press 3 to delete a teacher's record" << endl; //Delete Teacher Details
		cout << "Press 4 to delete a student's record" << endl; //Delete Student Records
		cout << "Press 5 to change your password" << endl;		//Change admin password
		cout << "Press 6 to logout" << endl;					//To go back to the main page

		cin >> choice2;
		system("CLS");

		switch (choice2)
		{ //switchStartedChoice2
		case 1:
				//ADDING A NEW INSTRUCTOR
			indata.open("inst_rec.txt", ios::app); //inst_rec is a txt file. and we are reading and writing all the data from and in this file.
			for (i = 0; i < 30; i++)
			{ //forLoop started
				system("CLS");
			con:
				system("CLS");
				//ADDING AN INSTRUCTOR'S RECORD
				system("CLS");
				cout << "To add a new instructor you should give all the necessary information" << endl;
				cout << endl;

				cout << "Enter the name of the instructor" << endl;
				cin.ignore(); //To Ignore the Junk value
				getline(cin, inst_name[i]); //Getline is used so that we can add space in name.
				cout << endl;

				cout << "Enter the instructor id" << endl;
				cin >> inst_id[i];
				cout << endl;

				cout << "Enter the faculty" << endl;
				cin.ignore();
				getline(cin, inst_fac[i]);
				//cin >> inst_fac[i];
				cout << endl;

				//These are all the details that were required for the instructor

				cout << " Instructor Name : " << inst_name[i] << "\n Instructor Registration Number : " << inst_id[i]
					 << "\n Instructor Faculty : " << inst_fac[i] << endl;

				indata << inst_name[i] << endl; //Writing the data in external file
				indata << inst_id[i] << endl;	//Writing the data in external file
				indata << inst_fac[i] << endl;	//Writing the data in external file

				cout << endl
					 << endl;
				cout << "Admin has added a new instructor" << endl;
				cout << endl;
				cout << "Do you want to add more? (Y/N)" << endl;
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					i++; //Since I have used the goto function so all my data was being saved at array[0]. This is why there is an increament in i over here so that data is saved in different arrays.
					goto con;
				}
				if (ans == 'N' || ans == 'n')
				{
					goto start;
				}
				system("CLS");
				break;
			} //forLoop ended
			indata.close();

		case 2:
			//Adding a New Student
			sndata.open("std_rec.txt", ios::app);
			for (i = 0; i < 30; i++)
			{ //forLoop started
				system("CLS");
			con1:
				system("CLS"); ///We Are adding new students to the file over here.

				system("CLS");
				cout << "To add a new student, you should provide all the necessary information" << endl;
				cout << endl;

				cout << "Enter the student name" << endl;
				cin.ignore();
				getline(cin, std_name[i]);
				cout << endl;

				cout << "Enter student's registration number" << endl;
				cin >> std_reg[i];
				cout << endl;

				cout << "Enter the student's faculty" << endl;
				cin.ignore();
				getline(cin, std_fac[i]);
				cout << endl;

				cout << " Student Name : " << std_name[i] << "\n Student Registion Number : " << std_reg[i]
					 << "\n Student Faculty : " << std_fac[i] << endl; //Displaying Registered Student

				sndata << std_name[i] << endl;
				sndata << std_reg[i] << endl;
				sndata << std_fac[i] << endl; //Writing Data to the File

				cout << endl;
				cout << "Admin has added a new student" << endl;
				cout << endl;

				cout << "Do you want to add more students? (Y/N)" << endl; //If admin wants to add more.
				cin >> ans;

				if (ans == 'Y' || ans == 'y')
				{
					i++;
					goto con1;
				}
				if (ans == 'N' || ans == 'n')
				{
					goto start;
				}
				system("CLS");
				break;
			}				//forLoop ended
			sndata.close(); //FileClosed

		case 3:
			//Deleting a teacher's record
			system("CLS");
			cout << "Are you sure you want to delete a teacher's record? (Y/N)" << endl;
			cin >> ans;

			if (ans == 'Y' || ans == 'y')
			{
				cout << "Enter Instructor's ID" << endl;
				cin >> i_id;
				/*cin.ignore();
                    getline(cin, studentid);*/
				//cout<<studentid<<endl;
				indata.open("inst_rec.txt");
				tdata.open("temp1.txt");

				for (i = 0; i < 30; i++)
				{
					getline(indata, inst_name[i]);
					getline(indata, inst_id[i]); //Reading Data
					getline(indata, inst_fac[i]);

					//i_id=trim(i_id);
					//inst_id[i]=trim(inst_id[i]);
					//cout << studentid.compare(std_reg[i]);
					if (inst_id[i] != i_id)
					{
						//cout << inst_id[i] << endl;
						tdata << inst_name[i] << endl; //Writing Data in Temp File
						tdata << inst_id[i] << endl;
						tdata << inst_fac[i] << endl;
					}
					else if (inst_id[i] == i_id)
					{
						cout << "Record Deleted" << endl; //If Id matches that record wont be printed
					}

					if (indata.eof())
					{
						break; //If The Whole File is READ then break the loop
					}
				}
				indata.close(); //ClosingFile
				tdata.close();

				remove("inst_rec.txt"); //removing the main file
				rename("temp1.txt", "inst_rec.txt"); //renaming the temporary file to the main file

				system("PAUSE");
				goto start;

				if (ans == 'N' || ans == 'n')
				{
					goto start;
				}
			}
			system("CLS");
			break;

		case 4:
			//Deleting a student's record
			system("CLS");
			cout << "Are you sure you want to delete a student's record? (Y/N)" << endl;
			cin >> ans;

			if (ans == 'Y' || ans == 'y') //Deleting A Student's Record
			{
				cout << "Enter Student's ID" << endl;
				cin >> studentid;
				/*cin.ignore();
                    getline(cin, studentid);*/
				//cout<<studentid<<endl;
				sndata.open("std_rec.txt");
				tdata.open("temp1.txt"); //Files Open

				for (i = 0; i < 30; i++)
				{

					getline(sndata, std_name[i]); //ReadingData
					getline(sndata, std_reg[i]);
					getline(sndata, std_fac[i]);

					// studentid=trim(studentid);
					// std_reg[i]=trim(std_reg[i]);
					//cout << studentid.compare(std_reg[i]);
					if (std_reg[i] != studentid)
					{
						//cout << std_reg[i] << endl;
						tdata << std_name[i] << endl;
						tdata << std_reg[i] << endl;
						tdata << std_fac[i] << endl; //Writing Data in Temporary File
					}
					else if (std_reg[i] == studentid)
					{
						cout << "Record Deleted" << endl; //If ID entere matches to the stored ID it wont print. as we are deleting the entered Id's record
					}

					if (sndata.eof())
					{
						break;
					}
				}
				sndata.close(); //File CLosed
				tdata.close();

				remove("std_rec.txt");

				// if (remove("std_rec.txt") == 0)
				// {
				// 	// success, print something
				// }
				// else
				// {
				// 	// failure, much more interesting
				// 	cout << "Can't remove " <<  ": "
				// 		 << strerror(errno) << endl;
				// }
				rename("temp1.txt", "std_rec.txt");

				system("PAUSE");
				goto start;
			}
			if (ans == 'N' || ans == 'n')
			{
				goto start;
			}

			system("CLS");
			break;

		case 5:
			//ChangingPassword
			system("CLS");
			cout << "Are you sure you want to change your password? (Y/N)" << endl;
			cin >> ans;

			if (ans == 'Y' || ans == 'y')
			{
				tdata.open("temp1.txt");
				system("CLS");
				cout << "Kindly enter your old password " << ad_username << endl;
				cin >> ad_pw;
				cout << "Enter your new password" << endl;
				cin >> ad_pwNew;
				cout << "Re-enter your new password" << endl;
				cin >> ad_pwNew;

				cout << "Your Old Password = " << ad_pw << endl;
				Temp = ad_pwNew; //Swapping Password using Temp as a variable
				ad_pwNew = ad_pw;
				ad_pw = Temp;

				cout << "Your New password = " << ad_pw << endl;

				tdata << ad_username << endl; //Writing the new password in a new file
				tdata << ad_pw << endl;

				cout << "You have successfuly changed your password " << ad_username << endl;

				tdata.close(); //Closing Files
				in.close();

				remove("adminusrpw.txt"); //removing the old file
				rename("temp1.txt", "adminusrpw.txt"); //renaming the temp file to main file where new pasword with id is stored

				system("PAUSE");
				goto start;
				system("CLS");  //I could also make a UserDefined Function and then call it by name wnv I wanted to change the password. But again the use of function in this program is minimal.
			}
			if (ans == 'N' || ans == 'n')
			{
				goto start;
				break;
			}
			system("CLS");

			break;

		case 6:
			//Logout
			system("CLS");
			cout << "You have successfully logged out." << endl;
			system("PAUSE");
			goto main;

		} //switchEndedChoice2

	} //Ifended

	if (choice == 2)
	{ //ifStartedChoice2

		//Instructor Portal
		system("CLS");
		cout << "Welcome to the Instructor Portal of GIKI-CMS" << endl;
		cout << endl
			 << endl;
		cout << endl
			 << endl;

		ifstream in("instusrpw.txt"); //ReadingFile
		in >> instructor;
		in >> password2;

		cout << instructor << password2 << endl;

	pass2:

		//inst_username = inst
		//inst_pw = pass

		cout << "Enter Username" << endl;
		cin >> inst_username; //InstructorUsername

		cout << "Enter password" << endl;
		cin >> inst_pw; //InstructorPassword

		while (attempt < 3) //WhileLoop here is used just incase user enters the wrong username and password
		{					//whileStarted
			if (inst_username == instructor && inst_pw == password2) //Comparison of entered and stored data
			{
				cout << "Access Granted" << endl;
				system("PAUSE");
				break;
			}
			if (inst_username != instructor || inst_pw != password2) //Comparison of entered data and stored data
			{
				cout << "Try Again!" << endl;
				attempt++; //3tries are given if user enters wrong username and password after that program exits
				if (attempt < 3)
				{
					goto pass2;
				}

				if (attempt >= 3)
				{
					cout << "You have reached your limit of trying the username and password" << endl;
					system("PAUSE");
					goto main;
				}
			}
		} //whileEnded
		system("CLS");

		system("CLS");
	start2:
		system("CLS");

		system("CLS");
		cout << "Press 1 to View and Edit your details" << endl;							 //EditYourDetails
		cout << "Press 2 to Add A New Course" << endl;										 //Add a new course
		cout << "Press 3 to Approve A Course Join Request" << endl;							 //StudentRequest
		cout << "Press 4 to Upload Quiz,Assignment,Lecture or Exam" << endl;				 //Upload Work
		cout << "Press 5 to Upload Marks of Students in Quiz,Assignments and Exams" << endl; //UploadStudentMark
		cout << "Press 6 to Change Your Password" << endl;									 //Change your password
		cout << "Press 7 to Send/Recieve Message" << endl;									 //Logout
		cout << "Press 8 to logout" << endl;												 //Logout

		cin >> choice2;
		system("CLS");

		switch (choice2)
		{ //SwitchChoice2Started
		case 1:
				//ViewYOurDetails
			system("PAUSE");
			cout << "You can view and edit your details on this page" << endl;
			cout << endl
				 << endl;

			system("CLS");
			cout << "Press 1 to View your details" << endl;
			cout << "Press 2 to Edit your details" << endl;
			cin >> choice2;

			indata.open("inst_rec.txt", ios::app | ios::in); //Opening a file to read data. 

			if (choice2 == 1)
			{
				//Viewing Details
				cout << "Enter your registration number" << endl;
				cin >> i_id; //EnteringID to compare

				for (i = 0; i < 30; i++)
				{
					getline(indata, inst_name[i]);  //Getline is used to take the whole data from file. we can also use a string named data and read the file from couting that string only.
					getline(indata, inst_id[i]);
					getline(indata, inst_fac[i]);

					if (inst_id[i] == i_id) //Comparison of stored and entered data
					{
						cout << inst_name[i] << endl;
						cout << inst_id[i] << endl;
						cout << inst_fac[i] << endl;

						system("PAUSE");
						goto start2;
					}

					if (indata.eof())
					{
						break;
					}
				}
			}
			if (choice2 == 2)
			{
				//Editing Details
				system("CLS");
				cout << "Enter your registration number" << endl;
				cin >> i_id;

				tdata.open("temp1.txt"); //Opening a File

				for (i = 0; i < 30; i++)
				{
					getline(indata, inst_name[i]);
					getline(indata, inst_id[i]);
					getline(indata, inst_fac[i]); //Reading Data

					if (inst_id[i] == i_id) 
					{
						system("CLS");
						cout << inst_name[i] << endl;
						cout << inst_id[i] << endl;
						cout << inst_fac[i] << endl;
						cout << endl
							 << endl;
						system("PAUSE");

						system("CLS");
						cout << "Press 1 to Edit Your Name" << endl;
						cout << "Press 2 to Edit Your Faculty" << endl;
						cout << "Press 3 to Return to Instructor Portal's mainpage" << endl;
						cout << "The ID given to you is registered by the admin and can not be changed." << endl;
						cin >> choice3;

						system("CLS");
						if (choice3 == 1)
						{
							//To Edit Your Name
							cout << "Enter New Name" << endl;
							cin.ignore();
							getline(cin, inst_name[i]);
						}
						else if (choice3 == 2)
						{
							//To Edit your Faculty
							cout << "Enter Faculty" << endl;
							cin.ignore();
							getline(cin, inst_fac[i]);
						}
						else if (choice3 == 3)
						{
							goto start2; //Takes back to Instructor Portal
						}

						tdata << inst_name[i] << endl; //Writing Data in Temporary file
						tdata << inst_id[i] << endl;
						tdata << inst_fac[i] << endl;
					}

					indata.close(); //Closing File
					tdata.close();

					remove("inst_rec.txt"); //Removing and Replacing with a new file which has updated DATA
					rename("temp1.txt", "inst_rec.txt");

					goto start2;
					break;
				}
			}

		case 2:
				//Adding A New Course
			system("CLS");
			cout << "You can add new course on this page" << endl;
			cout << endl
				 << endl;

			courses.open("course.txt", ios::app | ios::out); //opening a file
			
			//BasicCourses that each and every student have.
			cout << "Calculus"
				 << "\nFundamental of Computer Science"
				 << "\nEnglish Language and Communication"
				 << "\nAre the basic courses. If you(instructor) want to teach other courses. Kindly add those courses only" << endl;
			system("PAUSE");

			for (i = 0; i < 100; i++)
			{
				system("CLS");
			c_reg:
				system("CLS");
				cout << "Kindly enter the course you want to add" << endl;
				cin.ignore();
				getline(cin, course[i]);

				courses << course[i] << endl; //Writing The Data Entered in the External File

				system("CLS");
				cout << "Do you want to add more courses?(Y/N)" << endl;
				cin >> ans;

				if (ans == 'Y' || ans == 'y')
				{
					i++; //Since we are using the GoTo Function so every data will be saved in array[0] if we dont Increament.
					goto c_reg;
				}
				if (ans == 'N' || ans == 'n')
				{
					goto start2;
				}
			}
			courses.close();
			break;
		case 3:
			//Approve a Course Join Request.
			system("CLS");
			cout << "You can Approve a Course Join Request from a Student on this Page" << endl;
			cout << endl
				 << endl;

			system("CLS");
		back:
			system("CLS");
			//This is a Course Join Request From a Student. If the Instructor Approves then file wont be changed but if the instructor Declines. He/She will Decline the request by deleting the student's request.
			cout << "Press 1 to See Student Who wants to join the course" << endl;
			cout << "Press 2 to Accept The Request" << endl;
			cout << "Press 3 to Decline The Request" << endl;
			cin >> choice3;

			subdata.open("coursesub.txt", ios::app | ios::in); //FileIn

			system("CLS");
			if (choice3 == 1)
			{
				while (getline(subdata, data2))
				{
					cout << data2 << endl; //Reading Data
				}

				system("PAUSE");
				goto back;
			}
			if (choice3 == 2)
			{
				cout << "Request Accepted" << endl;

				system("PAUSE");
				goto start2;
			}
			if (choice3 == 3)
			{
				tdata.open("temp1.txt");
				cout << "Enter student's Registration Number" << endl;
				cin >> s_id;

				for (i = 0; i < 30; i++)
				{
					if (std_reg[i] != s_id)
					{
						tdata << std_name[i] << endl; //Writing File in Temp File
						tdata << std_reg[i] << endl;
						tdata << std_fac[i] << endl;
						tdata << course[i] << endl;
					}
				}
				subdata.close();
				tdata.close();

				remove("coursesub.txt");			  //Deleting the main file
				rename("temp1.txt", "coursesub.txt"); //Renaming the Temp File to Main File hence making it the main file

				system("PAUSE");
				goto start2;
			}
			break;
		case 4:
			//Uploading Work such as Quiz etc..
			cout << "Instructors you can add your course related papers on this page" << endl;
			cout << endl
				 << endl;

			courses.open("course.txt", ios::in); //Opening a file to read

			cout << "Name of your course" << endl;
			cin >> coursename; //NoMatter which Subject  the student enters he will be shown all the papers and quizzes that are uploaded.

			for (i = 0; i < 100; i++)
			{
				courses >> course[i]; //ReadingData
			}
			//I have used only one File to Upload Papers. So Any Student can view these papers. As we are in online system so every student is given a wekk to finish his/her papers. Once he opens the file he will have access to all the papers. And he has to upload all of them on his TEAMS BY THE END OF THE WEEEK.
			for (i = 0; i < 100; i++)
			{
				if (course[i] == coursename)
				{
					system("CLS");
					cout << "Press 1 for Assignment" << endl;
					cout << "Press 2 for Quiz" << endl;
					cout << "Press 3 for Mid-Term" << endl;
					cout << "Press 4 for Final Exam" << endl;
					cout << "Press 5 for Lecture" << endl;
					cin >> choice3;

					if (choice3 == 1)
					{
						system("CLS");
						assignment.open("asgn.txt", ios::in);
						cout << "Assignment for " << course[i] << endl;

						while (getline(assignment, data))
						{
							cout << data << endl; //Using a string to Get all the data
						}
						assignment.close();
						system("PAUSE");
						goto start2;
					}
					if (choice3 == 2)
					{
						system("CLS");
						quizes.open("quiz.txt", ios::in);
						cout << "Quiz for " << course[i] << endl;

						while (getline(quizes, data))
						{
							cout << data << endl;
						}
						quizes.close();
						system("PAUSE");
						goto start2;
					}
					if (choice3 == 3)
					{
						system("CLS");
						mid.open("midterm.txt", ios::in);
						cout << "Mid-Term Paper for " << course[i] << endl;

						while (getline(mid, data))
						{
							cout << data << endl;
						}
						mid.close();
						system("PAUSE");
						goto start2;
					}
					if (choice3 == 4)
					{
						system("CLS");
						final.open("finalterm.txt", ios::in);
						cout << "Final Term for " << course[i] << endl;

						while (getline(final, data))
						{
							cout << data << endl;
						}
						final.close();
						system("PAUSE");
						goto start2;
					}
					if (choice3 == 5)
					{
						system("CLS");
						lec.open("lecture.txt", ios::in);
						cout << "Lectures for " << course[i] << endl;

						while (getline(lec, data))
						{
							cout << data << endl;
						}
						lec.close();
						system("PAUSE");
						goto start2;
					}
				}
			}

			break;

		case 5:
			//UploadMarks
			system("CLS");
			cout << "This page is to designed to upload marks." << endl;
			cout << endl;
			system("CLS");
			//The Marks are categorised into different sheets such as assignment sheet or quiz sheet. THe whole Batch will find their respective marks in here divided into different Faculties.
			cout << "Press 1 to upload Assignment Marks" << endl;
			cout << "Press 2 to upload Quiz Marks" << endl;
			cout << "Press 3 to upload Mid-Term Marks" << endl;
			cout << "Press 4 to upload Final Marks" << endl;
			cin >> choice3;
			system("CLS");

			if (choice3 == 1)
			{
				system("CLS");
				asgn.open("assmarks.csv");
				while (getline(asgn, data2, ',')) //Excel Sheet is Used here (.csv) so the Comma seperates the coulumns and rows
				{
					cout << data2 << endl;
				}
				asgn.close();
				system("PAUSE");
				goto start2;
			}
			if (choice3 == 2)
			{
				system("CLS");
				q_marks.open("quizmarks.csv");
				while (getline(q_marks, data2, ','))
				{
					cout << data2 << endl;
				}
				q_marks.close();
				system("PAUSE");
				goto start2;
			}
			if (choice3 == 3)
			{
				system("CLS");
				mid_marks.open("midmarks.csv");
				while (getline(mid_marks, data2, ','))
				{
					cout << data2 << endl;
				}
				mid_marks.close();
				system("PAUSE");
				goto start2;
			}
			if (choice3 == 4)
			{
				system("CLS");
				final_marks.open("finalmarks.csv");
				while (getline(final_marks, data2, ','))
				{
					cout << data2 << endl;
				}
				final_marks.close();
				system("PAUSE");
				goto start2;
			}

			break;
		case 6:
			//ChangingPassword
			system("CLS");
			cout << "Are you sure you want to change your password? (Y/N)" << endl;
			cin >> ans;

			if (ans == 'Y' || ans == 'y')
			{
				tdata.open("temp1.txt");
				system("CLS");
				cout << "Kindly enter your old password " << ad_username << endl;
				cin >> ad_pw;
				cout << "Enter your new password" << endl;
				cin >> ad_pwNew;
				cout << "Re-enter your new password" << endl;
				cin >> ad_pwNew;

				cout << "Your Old Password = " << inst_pw << endl;
				Temp = inst_pwNew;
				inst_pwNew = inst_pw;
				inst_pw = Temp;

				cout << "Your New password = " << inst_pw << endl;

				tdata << inst_username << endl;
				tdata << inst_pw << endl;

				cout << "You have successfuly changed your password " << inst_username << endl;

				tdata.close(); //ClosingFile
				in.close();

				remove("instusrpw.txt"); //Renaming and Replacing File
				rename("temp1.txt", "instusrpw.txt");

				system("PAUSE");
				goto start2; //GoingBack to the main page of the Instructor Console
				system("CLS");
			}
			if (ans == 'N' || ans == 'n')
			{
				goto start2;
				break;
			}
			system("CLS");
			break;
		case 7:
			//  Student Sending Message to Course Instructor
			int idInst;
			cout << " --------- Message Sending Portal -------\n";
			cout << "----- You have following message ----- \n";

			// RecieveMsg >> idInst;
			getline(RecieveMsg, RecMsg);
			//cout << idInst << endl;
			cout << RecMsg << endl; ///This Is NOT efficient. AS I really couldnt understand it. But I tried to display the Message.
			break;
		case 8:
			//logout
			system("CLS");
			cout << "You have successfully logged out." << endl;
			system("PAUSE");
			goto main;

		} //SwitchChoice2Ended
	}	  //ifEndedChoice2

	if (choice == 3)
	{ //IfChoice3 Started
		//Student Portal
		system("CLS");
		cout << "Welcome to the Student Portal of GIKI-CMS" << endl;
		cout << endl
			 << endl;
		cout << endl
			 << endl;

		ifstream in("stdusrpw.txt"); //reading from a file
		in >> student;
		in >> password3;

		//cout << student << password3 << endl;

	pass3:

		//std_username = student
		//std_pw = 111

		cout << "Enter Username" << endl;
		cin >> std_username; //StudentUsername

		cout << "Enter password" << endl;
		cin >> std_pw; //StudentPassword

		while (attempt < 3) //WhileLoop here is used just incase user enters the wrong username and password
		{					//whileStarted
			if (std_username == student && std_pw == password3)
			{
				cout << "Access Granted" << endl;
				system("PAUSE");
				break;
			}
			if (std_username != student || std_pw != password3)
			{
				cout << "Try Again!" << endl;
				attempt++;
				if (attempt < 3)
				{
					goto pass3;
				}

				if (attempt >= 3)
				{
					cout << "You have reached your limit of trying the username and password" << endl;
					system("PAUSE");
					exit(0);
				}
			}
		} //whileEnded
		system("CLS");

		system("CLS");
	start3:
		system("CLS");

		system("CLS");
		cout << "Press 1 to View and Edit your details" << endl;		   //EditYourDetails
		cout << "Press 2 to View the List of Existing Courses" << endl;	   //View the List of Course
		cout << "Press 3 to Subscribe A Course" << endl;				   //StudentRequest
		cout << "Press 4 to View your Marks" << endl;					   //View Your Marks
		cout << "Press 5 to View Quiz,Assignments and Exams" << endl;	   //View your work
		cout << "Press 6 to Read and Send Messages to Instructor" << endl; //Read/Send Message
		cout << "Press 7 to Change Your Password" << endl;				   //Change your password
		cout << "Press 8 to logout" << endl;							   //Logout

		cin >> choice2;
		system("CLS");

		switch (choice2)
		{ //SwitchChoice started
		case 1:
			//View and edit details
			cout << "You can view and edit your details on this page" << endl;
			cout << endl
				 << endl;

			cout << "Press 1 to View your details" << endl;
			cout << "Press 2 to Edit your details" << endl;
			cin >> choice2;

			indata.open("std_rec.txt", ios::app | ios::in); //ReadingAFile

			if (choice2 == 1)
			{
				//Viewing Details
				cout << "Enter your registration number" << endl;
				cin >> s_id; //ID entered to Compare

				for (i = 0; i < 30; i++)
				{
					getline(sndata, std_name[i]);
					getline(sndata, std_reg[i]);
					getline(sndata, std_fac[i]);  //Reading Data

					if (std_reg[i] == s_id) //Comparison
					{
						cout << std_name[i] << endl;
						cout << std_reg[i] << endl;
						cout << std_fac[i] << endl;

						system("PAUSE");
						goto start3;
					}

					if (indata.eof())
					{
						break; //Reads till the last line and break when the data ends
					}
				}
			}
			if (choice2 == 2)
			{
				//Editing Details
				system("CLS");
				cout << "Enter your registration number" << endl;
				cin >> s_id;

				tdata.open("temp1.txt");

				for (i = 0; i < 30; i++)
				{
					getline(sndata, std_name[i]);
					getline(sndata, std_reg[i]);
					getline(sndata, std_fac[i]);

					if (std_reg[i] == s_id) //comparison
					{
						system("CLS");
						cout << std_name[i] << endl;
						cout << std_reg[i] << endl;
						cout << std_fac[i] << endl;
						cout << endl
							 << endl;
						system("PAUSE");

						system("CLS");
						cout << "Press 1 to Edit Your Name" << endl;
						cout << "Press 2 to Edit Your Faculty" << endl;
						cout << "Press 3 to Return to Student Portal's mainpage" << endl;
						cout << "The ID given to you is registered by the admin and can not be changed." << endl;
						cin >> choice3;

						system("CLS");
						if (choice3 == 1)
						{
							cout << "Enter New Name" << endl;
							cin.ignore();
							getline(cin, std_name[i]);
						}
						else if (choice3 == 2)
						{

							cout << "Enter Faculty" << endl;
							cin.ignore();
							getline(cin, std_fac[i]);
						}
						else if (choice3 == 3)
						{
							goto start3;
						}

						tdata << std_name[i] << endl;
						tdata << std_reg[i] << endl; //Writing the edited Data in new File
						tdata << std_fac[i] << endl;
					}

					sndata.close();
					tdata.close();

					remove("std_rec.txt"); //Replacing the old file with an updated file
					rename("temp1.txt", "std_rec.txt");

					goto start3;
					break;
				}
			}

		case 2:
			//view the list of Courses
			cout << "You can view the list of existing courses on this page" << endl;

			courses.open("course.txt", ios::in);

			while (getline(courses, data2))
			{
				cout << data2 << endl;
			}
			courses.close();
			break;

		case 3:
			//Subscribe to a course
			subdata.open("coursesub.txt", ios::app | ios::in);
			system("PAUSE");
			cout << "You can subscribe a course you want to on this page" << endl;

			system("CLS");
			for (i = 0; i < 30; i++)
			{
				cout << "Enter Student Name" << endl;
				cin.ignore();
				getline(cin, std_name[i]);

				cout << "Enter Your Registration ID" << endl;
				cin >> std_reg[i];

				cout << "Enter your Faculty" << endl;
				cin.ignore();
				getline(cin, std_fac[i]);

				cout << "Enter the Course You Want To Subscribe" << endl;
				//cin.ignore();
				getline(cin, course[i]);

				cout << course[i] << " is the course I want to subscribe" << endl;

				subdata << std_name[i] << endl; //Writing the data in external file
				subdata << std_reg[i] << endl;	//Writing the data in external file
				subdata << std_fac[i] << endl;	//Writing the data in external file
				subdata << course[i] << endl;	//Writing the data in external file

				break;
			}
			cout << "Wait For the course Instructor To Approve your Request" << endl;
			cout << "If the Course Instructor's Class is Full and your request gets rejected. You will recieve an email on your Zimbra Account" << endl;
			system("PAUSE");
			goto start3;
			break;

		case 4:
			//ViewYourMarks
			system("CLS");
			cout << "View your marks" << endl;

			system("CLS");
			cout << "Press 1 to View your Marks for Assignment" << endl;
			cout << "Press 2 to View your Marks for Quiz" << endl;
			cout << "Press 3 to View your Marks for Mid-Term" << endl;
			cout << "Press 4 to View your Marks for Final" << endl;

			cin >> choice2;

			if (choice2 == 1)
			{
				system("CLS");
				asgn.open("assmarks.csv", ios::in);

				while (getline(asgn, data2))
				{
					cout << data2 << endl;
				}
				asgn.close();
				system("PAUSE");
				goto start3;
			}
			if (choice2 == 2)
			{
				system("CLS");
				q_marks.open("quizmarks.csv", ios::in);

				while (getline(q_marks, data2))
				{
					cout << data2 << endl;
				}
				q_marks.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 3)
			{
				system("CLS");
				mid_marks.open("midmarks.csv", ios::in);

				while (getline(mid_marks, data2))
				{
					cout << data2 << endl;
				}
				mid_marks.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 4)
			{
				system("CLS");
				final_marks.open("finalmarks.csv", ios::in);

				while (getline(final_marks, data2))
				{
					cout << data2 << endl;
				}
				final_marks.close();
				system("PAUSE");
				goto start3;
			}
			break;
		case 5:
			//View your Papers and lecutes
			cout << "You can view the uploaded quiz,assignment,lectures and final papers on this page" << endl;
			cout << "PS: All the papers are uploaded in one file. You all have exactly a week to complete your papers and upload them on Microsoft Teams. Teachers are not allowed to HELP" << endl;

			cout << endl
				 << endl;

			system("CLS");
			cout << "Press 1 to View your Assignment" << endl;
			cout << "Press 2 to View your Quiz" << endl;
			cout << "Press 3 to View your Mid-Term Paper" << endl;
			cout << "Press 4 to View your Final-Term Paper" << endl;
			cout << "Press 5 to View Lectures" << endl;
			cin >> choice3;

			if (choice3 == 1)
			{
				system("CLS");
				assignment.open("asgn.txt", ios::in);
				cout << "Assignment for " << course[i] << endl;

				while (getline(assignment, data))
				{
					cout << data << endl;
				}
				assignment.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 2)
			{
				system("CLS");
				quizes.open("quiz.txt", ios::in);
				cout << "Quiz for " << course[i] << endl;

				while (getline(quizes, data))
				{
					cout << data << endl;
				}
				quizes.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 3)
			{
				system("CLS");
				mid.open("midterm.txt", ios::in);
				cout << "Mid-Term Paper for " << course[i] << endl;

				while (getline(mid, data))
				{
					cout << data << endl;
				}
				mid.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 4)
			{
				system("CLS");
				final.open("finalterm.txt", ios::in);
				cout << "Final Term for " << course[i] << endl;

				while (getline(final, data))
				{
					cout << data << endl;
				}
				final.close();
				system("PAUSE");
				goto start3;
			}
			if (choice3 == 5)
			{
				system("CLS");
				lec.open("lecture.txt", ios::in);
				cout << "Lectures for " << course[i] << endl;

				while (getline(lec, data))
				{
					cout << data << endl;
				}
				lec.close();
				system("PAUSE");
				goto start3;
			}
			break;

		case 6:
			//  Student Sending Message to Course Instructor
			int id;
			cout << " --------- Message Sending Portal -------\n";
			// cout << " --- Please Enter the ID of the Instrctor : \n";
			// cin >> id;
			cout << "----- Please Enter the Message you want to Send ----- \n";
			cin.ignore();
			getline(cin, StdntMessage);
			// SendStudentMsg << id << endl;
			SendStudentMsg << StdntMessage << endl;
			goto start3;
			break;
		case 7:
			//Changing the password
			system("CLS");
			cout << "Are you sure you want to change your password? (Y/N)" << endl;
			cin >> ans;

			if (ans == 'Y' || ans == 'y')
			{
				tdata.open("temp1.txt");
				system("CLS");
				cout << "Kindly enter your old password " << ad_username << endl;
				cin >> std_pw;
				cout << "Enter your new password" << endl;
				cin >> std_pwNew;
				cout << "Re-enter your new password" << endl;
				cin >> std_pwNew;

				cout << "Your Old Password = " << inst_pw << endl;
				Temp = std_pwNew;
				std_pwNew = std_pw;
				std_pw = Temp;

				cout << "Your New password = " << std_pw << endl;

				tdata << std_username << endl;
				tdata << std_pw << endl;

				cout << "You have successfuly changed your password " << std_username << endl;

				tdata.close();
				in.close();

				remove("stdusrpw.txt");
				rename("temp1.txt", "stdusrpw.txt");

				system("PAUSE");
				goto start3;
				system("CLS");
			}
			if (ans == 'N' || ans == 'n')
			{
				goto start3;
				break;
			}
			system("CLS");
			break;

		case 8:
			//Logout
			system("CLS");
			cout << "You have successfully logged out." << endl;
			system("PAUSE");
			goto main;
		} //SwitchChoice ended
	}	  //IfChoice3 Ended

//ProgramEnded

} //intmain ended