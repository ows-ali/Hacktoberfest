#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<cctype>
#include<windows.h>
#include<time.h>
using namespace std;
fstream file,ffile;
ifstream fin;
ofstream fout;
char newWName[50]="abcd",newWPass[50]="abcd";																																	//for new worker registration
char adminName[50]="admin";
char workerName[50]="customer";
char adminPass[50]="admin";
char workerPass[50]="customer";
const int n=50;																																	//for number of cabs
int i;																																				//for loops
bool wrong = false;

class cab
{
    	public:
		char pickup[80],drop[80],name[20];																											//for booking initials
		float charges,dist;																															//for booking initials
		int cabno[n];																																//for can number
		int cabstats[n];																															//for cab status
		int av,cb;
		char ch;
			cab()																																		//to initialize Cab number & Status
		{
			for(i=1;i<=n;i++)
			{
				fout.open("CabStatus.txt",ios::app);
				cabno[i]=i;
				fout<<cabno[i]<<"\t";
				cabstats[i]=1;																														//initially all cabs are free
				fout<<cabstats[i]<<"\n";
				fout.close();	
			}
		}	
		
		void showcstat()
		{
			int sh;
			sh=0;
			system("CLS");
        	cout<<"\t\t\t\t\tCAB STATUS\n"<<endl;
        	for(i=1;i<=n;i++)
			{
				if(sh%10==0)
				{
					cout<<"\n";
					if(cabstats[i]==1)
       		   			cout<<"Cab "<<cabno[i]<<" IS FREE\t";
       				else
      	  				cout<<"Cab "<<cabno[i]<<" IS NOT FREE\t";
				}
				else
				{
					if(cabstats[i]==1)
       	   				cout<<"Cab "<<cabno[i]<<" IS FREE\t";
       				else
      	  				cout<<"Cab "<<cabno[i]<<" IS NOT FREE\t";
				}
    	    	 sh++;            
        	}		 		
		}
		
		void book(int mod, int dis)
		{
			av=0;																															//to check availability of cabs
			for(i=0;i<n;i++)
			{
				if(cabstats[i]==1)
					{
						cb=i;
						av=1;
						break;
					}
				else
					continue;	
			}
			if(av==0)
  			{
				   cout<<"All The Cabs Are Book"<<endl;
				   cout<<"We Can Not Book Cab for You"<<endl;
   			}
 			else
 			{  
				 cout<<"Enter your Name : ";
				    cin>>name;
				   cout<<"Enter the PickUp point : ";
				    cin>>pickup;
				   cout<<"Enter the Drop Point : ";
				   cin>>drop;
				charges=(dis*13)+mod;
				cout<<"Calculating Your Total Fare:";
				Sleep(200);
				cout<<endl<<"Charges : Rs"<<charges<<endl;
			}
			char bk;																															//to store customer's book request
 			cout<<endl<<"Do You Want to Book the Cab (Y/N) :- ";
 			cin>>bk;
 			if((bk=='Y')||(bk=='y'))
 			{
    			ffile.open("CabStatus.txt",ios::app);
	 			file.open("Customer Record.txt",ios::app);																								//File Open
				cout<<"Cab id Num "<<cabno[cb]<<" is Booked For You\n";
  				cout<<"Your Booking Has Been Done\n";
    	 		file<<endl<<"\t\tCustomer Record\n";
    			file<<endl<<"Name : "<<name;
     			file<<endl<<"Pick : "<<pickup;
     			file<<endl<<"Drop : "<<drop;
     			file<<endl<<"Distance : "<<dist;
     			file<<endl<<"Charges : Rs."<< charges;
     			file<<endl<<"Cab No. Booked : "<<cabno[cb];
     			file.close();
     			i=0;
				cabstats[cb]=0;
     			ffile.close();
				Sleep(1000);  
 			}
 			else
 			{
 				file.open("CancelBooking.txt",ios::app);																									//File Open
  				cout<<endl<<"Your Booking has been cancelled."<<endl;
 				file<<"\t\tBooking Cancelled\n";																										//writing on file
  				file<<endl<<"Name : "<<name;																												//writing on file
  				file<<endl<<"Pick : "<<pickup;																												//writing on file
  				file<<endl<<"Drop : "<<drop;																													//writing on file
  				file<<endl<<"Distance : "<<dist;																												//writing on file
  				file<<endl<<"Charges : Rs"<<charges;																										//writing on file
  				file.close();																																//File Close
 			}
 			Sleep(1000);
		}
}c;

class admin
{
	public:
	void CheckBookingRecord()
	{
		system("CLS");																															//creating Object to read from file
		char ch;																																	//initializing
		fin.open("CustomerRecord.txt");																										//file open
		while (!fin.eof())  
		{    
		    fin.get(ch) ;
		    cout<<ch;  
		}
		char ch5;
		ifstream obj1;
		obj1.open("CustomerRecord.txt");
		obj1.seekg(0);
		while(obj1.eof())
		{
			obj1>>ch5;
		       if(ch5==0)
		       cout<<"\t\t\t\t\n\nNo Records Found";
		}
	    fin.close();																																//file close
 		cout<<endl;
 		
	}
		
	void showdriverrecord()
	{
		system("CLS");
        char ch;																																	//initiailzing
        fin.open("Registration.txt");																											//file open
        while (!fin.eof())  
          {    
           fin.get(ch) ;
           cout<<ch ;  
          }
        fin.close();																																	//file close
        cout<<endl;
	}
	
	void showcancelrecord()
	{
		system("CLS");																															//creating Object to read from file
        char ch;																																	//initiailzing
        fin.open("CancelBooking.txt");																											//file open
        while (!fin.eof())  
         {    
         fin.get ( ch ) ;
         cout << ch ;  
         }
        fin.close();																																	//file close
        cout<<endl;		
	}
	
	void changeratecharges()
	{
	 char ch;
     do{																																			//Increment  and decrement On rate 
        system("CLS");
     	cout<<"\t\t\t\t\t********************"<<endl;
     	cout<<"\t\t\t\t\t*     WeLCoME     *"<<endl;
        cout<<"\t\t\t\t\t********************"<<endl;
        cout<<endl;
        int Charges;
        cout<<"Enter The Amount That You Want To Increment or Decrement On Km Per Charges :";
        do{
        	cin>>Charges;
        	wrong = cin.fail();																															//if type is opposite
        	if(wrong)
        	  cout<<"Error Wrong Input\nEnter again"<<endl;
            cin.clear();
            cin.ignore(200, '\n');																													  //ignore upto 200 characters
          }while(wrong);
        cout<<"\nThe Changes Has Been Done SuccessFully"<<endl;
        cout<<"Do you Want TO Change The Rate Again(Y/N) : ";
        cin>>ch;
        }while((ch=='Y') || (ch=='y'));
	}
	
	void newworkeracc()
		{
		   system("CLS"); 
           cout<<"\t WELCOME TO THE COOL CAB SERVICE"<<endl;
           cout<<endl;
           cout<<"Enter Customer User Name: ";
           cin>>newWName;																													//for new worker registration
           cout<<endl;
           cout<<"Enter Customer Password: ";
           cin>>newWPass;																													//for new worker registration
           cout<<endl;
           cout<<"The Account Has Been Made Successfully\n";
           cout<<endl;
           cout<<"\tThank YOu"<<endl;
		}
		
}a;


int main()
{
    int count=0;
    system("color B4");																							
	for(i=0;i<=100;i=i+10)
    { system("cls"); 		
    cout<<endl;
   	cout<<"\t\t\t\t\t##############################\n"; 
   	cout<<"\t\t\t\t\t#         WELCOME            #\n";
    cout<<"\t\t\t\t\t#            To              #\n"; 
    cout<<"\t\t\t\t\t#     JALANDHAR TRAVELS      #\n";
    cout<<"\t\t\t\t\t##############################\n\n\n\n\n";										
	cout<<"\t\t\t\t\tLOADING  ...PLEASE WAIT.....";
	Sleep(100);
	cout<<i<<"%";
	
    }
    
   cout<<endl<<endl<<endl<<"\t\t\t\t\t\tSuccessfully logged in";

   Sleep(100);																																				
   system("CLS");																																				

    
 hey:	char ch;
 	   int menu;																																		
  
 		system("CLS");
 		cout<<"\t\t\t\t\t############################"<<endl;
 		cout<<"\t\t\t\t\t#     CAB BOOKING SYSTEM   #"<<endl;
 		cout<<"\t\t\t\t\t############################"<<endl;
 		cout<<endl;  
 		cout<<"1.Admin Login"<<endl<<endl<<"2.Customer Login"<<endl<<endl<<"3. For exit"<<endl<<endl;
 		cout<<"select from the option: ";
 		cin>>menu;
		 switch(menu)																																		//Main Menu Switch
 			{
  			case 1:																																			//main menu case 1
    			{	bool LoginSuccess= false;
				 do
      				{    
     				
    				char user[50]="",pass[50]="";
					int z=0,checkuser=0,checkpass=0; 																															//for password I/P
     				system("CLS");
     				cout<<"\t\t\t\t\t####################"<<endl;
    		 		cout<<"\t\t\t\t\t#   ADMIN LOGIN    #"<<endl;
     				cout<<"\t\t\t\t\t####################"<<endl;
     				cout<<endl;
     				Sleep(500);	
					fflush(stdin);
					fflush(stdout); 																															//For Pause
     				cout<<"Hint:- admin\n";
     				cout<<"\nUserName: ";
     				cin>>user;
     				cout<<"Password: ";
     				fflush(stdin);
     				while((ch=getch())!=13)
        				{
          				pass[z]=ch;
          				z++;
          				cout<<"*";
        				}
        			pass[z]='\0';	
					checkuser=strcmp(user,adminName);
          			checkpass=strcmp(pass,adminPass);
          								 
	     			if((checkuser==0) && (checkpass==0))
    	 				{
      					cout<<endl<<endl<<"\t\t\tSuccessfully logged in  \n";
      					 LoginSuccess= true;																														//for do-while condn.
      					Sleep(2000);
      					system("CLS");
      					char ch='y';
						  while(ch=='y'||ch=='Y')																															//for do-while choice
        			      {
								system("CLS");
        					int amenu;																														//For admin menu choice
        					cout<<"\t\t\t\t\t####################"<<endl;
        					cout<<"\t\t\t\t\t# ADMINISTRATION   #"<<endl;
        					cout<<"\t\t\t\t\t####################"<<endl;
        					cout<<endl;
        					cout<<"1. Customer Record"<<endl;
        					cout<<endl;
        					cout<<"2. Cab Driver Record"<<endl;
        					cout<<endl;
        					cout<<"3. Cab Status"<<endl;
        					cout<<endl;
        					cout<<"4. Cancelled Bookings"<<endl;
        					cout<<endl;
        					cout<<"5. Change The Rate Of Per Km Charges"<<endl;
        					cout<<endl;
        					cout<<"6. Create New Customer Account"<<endl;
      			 	 		cout<<endl;
        					cout<<"7. Log Out"<<endl<<endl;
        					cout<<"\tSelect :";
        					cin>>amenu;
        					switch(amenu)																														//Admin Menu Switch
           						{
               					case 1:
        		   					a.CheckBookingRecord();
                   					break;
               					case 2:
                    				a.showdriverrecord();
									break;													  
               					case 3:																															//cab Status
                 					c.showcstat();
									break;  
         						case 4:
                    				a.showcancelrecord();
									break;
                				case 5:
               						a.changeratecharges();
									break;
                				case 6:
           							a.newworkeracc();
									break;
         						case 7:
          							system("CLS");
                    				cout<<"\n\n\tsuccessfully Logged Out...\n";
            						break;    
                				default:
                    				cout<<"\n\tWrong Choice!!!"<<endl;
                    				cout<<"\n\tTry Again..."<<endl;
									break;
								}																															//end of Admin Menu switch
     						if(amenu==7)																													//to go to Previous Menu
     	  						{
     								break;
     	  						}
        					cout<<"\n\tPress any key to continue...... ";
        					ch=getch();
      					  }
      					  
       					}
       						else
      					{
       					cout<<"\n\tIncorrect User Name And Password\n"<<"Please Try Again";
       					Sleep(500);
     					}
     			
    				}while(!LoginSuccess);																														//to check login status
      				break;   
				}																																				//end of main case 1
             
    		case 2:																																			//main menu case 2
   			start:	{	int m;
          	    below:
          			char user[50]="";																																//for username
          			char pass[50]="";
              		int z=0,checkuser=0,checkpass=0,checknuser=0,checknpass=0;																																//for password
          			system("CLS");
        	  		cout<<"\t\t\t\t\t\t####################"<<endl;
              		cout<<"\t\t\t\t\t\t#  CUSTOMER LOGIN  #"<<endl;
              		cout<<"\t\t\t\t\t\t####################"<<endl;
        	  		cout<<"\n\n1. Login\n\n2. Register\n\n3. ForgotPassword \n\n4.Back to main menu";
					cout<<"\n-----------------------\n";
                    cout<<"Enter your choice: ";
                    cin>>m;
                    switch(m)
                    {  
                    	case 1:
                         { char user[50]="";
                            char pass[50]="";
						 cout<<"Enter Username: ";
                         cin>>user;
                         cout<<"Enter Password: ";
             			cin>>pass;
    				    ifstream obj;
   					    obj.open("CustomerDetails.txt");
   						 file.seekg(0);
   							 while(!file.eof())
    						{
      							obj>>newWName>>newWPass;
       							if(strcmp(user,newWName)==0&&strcmp(pass,newWPass)==0)
        						{
            					cout<<"Login Successful";
            					cout<<"\nCOOLCABS WELCOMES YOU HAVE A SAFE AND NICE TRIP\n";
            					getch();
        						    goto base;
										}
                             else
                             {
                             	system("cls");
                                cout<<"\t\t\t\t\t\n\n\n\n\nWrong Username and password\n";
                         		cout<<"\t\t\t\t\t\nIf you haven't created account then please Register"<<endl;
                         		getch();
                    			goto start;
							 }
    						}
                        }
                        case 2:
                        {
							char user[50]="";
                        	char pass[50]="";
                        	system("cls");
                        	cout<<"\t\t\t\t\t\n\n$$$$$$CREATE YOUR ACCOUNT AND GET STARTED$$$$$$\n";
                        	cout<<"\nEnter your name:";
                        	cin>>user;
                        	cout<<"\n\nEnter your password:";
                        	cin>>pass;
                        	ofstream obj;
                        	obj.open("CustomerDetails.txt", ios::app);
                        	obj<<user<<pass<<"\n";
                        	cout<<"\t\t\t\t\t\nCongratulations!! You Successfully registered";
                        	cout<<"\t\t\t\t\t\nWelcome to the Coolcab And Enjoy The Trip"<<endl;
                        	
                        	getch();
                        	break;
                        	
							                        	
                        	
				    	}
					  case 3:
					  	{
						
					  	char user[50]="";
					  	int found=0;
					  	system("cls");
					  	cout<<"\n\n\nForget the password????";
					  	cout<<"\nDon't worry we will find your Password";
					  	getch();
					  	cout<<"\nEnter your username:";
					  	cin>>user;
					  	ifstream abc;
					  	abc.open("CustomerDetails.txt");
					  	cout<<"Searching";
					  			for(int i=0;i<1;i++)
					  			   for(int j=0;j<=4;j++)
									 cout<<".";
									 abc.seekg(0);
					  	while(abc.eof())
					  	{    abc>>newWName>>newWPass;
					  		 if(strcmp(user,newWName)==0)
					  		 {
					  			cout<<"\nYour Password is: "<<newWPass<<endl;
							  }
							  else
							  cout<<"\nNot Found"<<endl;
						  }
						  break;
						 }
						 case 4:
						 {	
						    goto hey;
						    break;
					    }
                      default:
                     {
					 cout<<"\nOoOoOops Wrong choice";
                     goto below;
			     	}
					}
        	  	    base:
       			  		Sleep(1000);
                  		system("CLS");
                        char ch;
 				  		int temp;						
   			  	  		do{
           			  		x:
    				  		system("CLS");
 					  		cout<<"\t\t\t\t\t#####################"<<endl;
 					  		cout<<"\t\t\t\t\t#      CUSTOMER     #"<<endl;
 					  		cout<<"\t\t\t\t\t#####################"<<endl;
 					  		cout<<endl;
 					  		cout<<endl;
    				  		cout<<"1. Booking"<<endl<<endl<<"2. Cab Status"<<endl<<endl<<"3. Customer Record"<<endl<<endl<<"4. To LogOut"<<endl;
					  		cout<<endl<<" Select : ";
 					  		cin>>temp;
    				  		switch(temp)																													
 								{
                  				case 1:																														
                       				{  char ch='y';
									     while(ch=='y'||ch=='Y')
									     {
										system("CLS");
                  						int check;											
               							cout<<"\t\t\t\t\t#####################"<<endl;
               							cout<<"\t\t\t\t\t#    Booking        #"<<endl;
               							cout<<"\t\t\t\t\t#####################"<<endl;
               							cout<<endl;
                  						cout<<endl;
                  					trt:	cout<<"1.Jalandhar to Phagwara"<<endl;
                  						cout<<"2.Jalandhar to Ludhiana"<<endl;
                  						cout<<"3.Jalandhar to Chandigarh"<<endl;
                  						cout<<"4.Jalandhar to Amritsar"<<endl;\
                  						cout<<"5.Jalandhar to Ambala"<<endl;
                  						cout<<"6.Go to previous menu"<<endl;
                  						cout<<" Select : ";
               							cin>>check;																					//converting string to int
                  						switch(check)																										//booking menu switch
               								{
       											count++;
                        						case 1:																										//booking menu case 1
                                   					{ int ctr;
													    system("cls");
													   cout<<"\t\t\t\t\t\n\n";
													   cout<<"1.Want A Luxury Trip??";
													   cout<<"\n\n2.Want a Cheap Trip??";
													   cout<<"\n\n Select the option:\n\n";
													   cin>>ctr;
													   switch(ctr)
													   { 
													   	case 1:
													   	top:	{ int ch;
											                cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Swift Dezire";
													   		cout<<"\n2.XYLO";
													   		cout<<"\n3.Mahindra XUV500";
													   		cout<<"\n4.BOLERO";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(100,25);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(200,25);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(200,25);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(300,25);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	    getch();
																	    goto top;
																		
																    }	
																		
																	
																   	
															   }
															   break;
														}
														case 2:
														bottom: { int ch; 
														cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Maruti Alto";
													   		cout<<"\n2.Wagonar";
													   		cout<<"\n3.Hyundai i10";
													   		cout<<"\n4.Hyundai EON";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(50,25);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(100,25);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(100,25);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(150,25);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	  getch();
																	  goto bottom;
															
														 } 
													   		
													   }
													   break;
												}
                                   						
                                        	}
											cout<<"Do you want to continue press y or n..... ";
       								       	ch=getch();																												//booking menu switch end
       								}
       								case 2:																										//booking menu case 1
                                   				mid:	{ int ctr;
													    system("cls");
													   cout<<"\t\t\t\t\t\n\n";
													   cout<<"1.Want A Luxury Trip??";
													   cout<<"\n\n2.Want a Cheap Trip??";
													   cout<<"\n\n Select the option:\n\n";
													   cin>>ctr;
													   switch(ctr)
													   { 
													   	case 1:
													   		{ int ch;
											                cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Swift Dezire";
													   		cout<<"\n2.XYLO";
													   		cout<<"\n3.Mahindra XUV500";
													   		cout<<"\n4.BOLERO";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(100,50);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(200,50);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(200,50);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(300,50);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	    getch();
																	    goto mid;
																		
																    }
																
																}
																break;
															}
																		
														
														case 2:
														square: { int ch; 
														cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Maruti Alto";
													   		cout<<"\n2.Wagonar";
													   		cout<<"\n3.Hyundai i10";
													   		cout<<"\n4.Hyundai EON";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(50,50);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(100,50);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(100,50);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(150,50);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	  getch();
																	  goto square;
															
         								                            }
                                    
                      			                             	}
                      			                             	break;
                      		                               	}
									  
									  
									                      default:
									                      	{
									                      	cout<<"\nWrong Choice";
															  getch();
															
															  }
													}
									                  break;    	
								}
								case 3:																										//booking menu case 1
                                   				{ int ctr;
													    system("cls");
													   cout<<"\t\t\t\t\t\n\n";
													   cout<<"1.Want A Luxury Trip??";
													   cout<<"\n\n2.Want a Cheap Trip??";
													   cout<<"\n\n Select the option:\n\n";
													   cin>>ctr;
													   switch(ctr)
													   { 
													   	case 1:
													  high: 	{ int ch;
											                cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Swift Dezire";
													   		cout<<"\n2.XYLO";
													   		cout<<"\n3.Mahindra XUV500";
													   		cout<<"\n4.BOLERO";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(100,150);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(200,150);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(200,150);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(300,150);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	    getch();
																	    goto high;
																		
																    }
																
																}
																break;
															}
																		
														
														case 2:
														sec: { int ch; 
														cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Maruti Alto";
													   		cout<<"\n2.Wagonar";
													   		cout<<"\n3.Hyundai i10";
													   		cout<<"\n4.Hyundai EON";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(50,150);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(100,150);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(100,150);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(150,150);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	  getch();
																	  goto sec;
															
         								                            }
                                    
                      			                             	}
                      			                             	break;
                      		                               	}
									  
									  
									                      default:
									                      	{
									                      	cout<<"\nWrong Choice";
															  getch();
															  	goto high;
															  }
													}
									                  break;    	
								}
								case 4:																										//booking menu case 1
                                   				low:	{ int ctr;
													    system("cls");
													   cout<<"\t\t\t\t\t\n\n";
													   cout<<"1.Want A Luxury Trip??";
													   cout<<"\n\n2.Want a Cheap Trip??";
													   cout<<"\n\n Select the option:\n\n";
													   cin>>ctr;
													   switch(ctr)
													   { 
													   	case 1:
													   		{ int ch;
											                cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Swift Dezire";
													   		cout<<"\n2.XYLO";
													   		cout<<"\n3.Mahindra XUV500";
													   		cout<<"\n4.BOLERO";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(100,60);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(200,60);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(200,60);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(300,60);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	    getch();
																	    goto low;
																		
																    }
																
																}
																break;
															}
																		
														
														case 2:
														ptr: { int ch; 
														cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Maruti Alto";
													   		cout<<"\n2.Wagonar";
													   		cout<<"\n3.Hyundai i10";
													   		cout<<"\n4.Hyundai EON";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(50,60);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(100,60);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(100,60);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(150,60);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	  getch();
																	  goto ptr;
															
         								                            }
                                    
                      			                             	}
                      			                             	break;
                      		                               	}
									  
									  
									                      default:
									                      	{
									                      	cout<<"\nWrong Choice";
															  getch();
															  break;
															  }
													}
									                  break;    	
								}
								case 5:																										//booking menu case 1
                                   					{ int ctr;
													    system("cls");
													   cout<<"\t\t\t\t\t\n\n";
													   cout<<"1.Want A Luxury Trip??";
													   cout<<"\n\n2.Want a Cheap Trip??";
													   cout<<"\n\n Select the option:\n\n";
													   cin>>ctr;
													   switch(ctr)
													   { 
													   	case 1:
													   	rent:	{ int ch;
											               cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Swift Dezire";
													   		cout<<"\n2.XYLO";
													   		cout<<"\n3.Mahindra XUV500";
													   		cout<<"\n4.BOLERO";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(100,140);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(200,140);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(200,140);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(300,140);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	    getch();
																	    goto rent ;
																		
																    }
																
																}
																break;
															}
																		
														
														case 2:
														counter: { int ch; 
														cout<<"\nSelect the Vehicle For The Trip:";
													   		cout<<"\n1.Maruti Alto";
													   		cout<<"\n2.Wagonar";
													   		cout<<"\n3.Hyundai i10";
													   		cout<<"\n4.Hyundai EON";
													   		cout<<"\nSelect your choice:";
													   		cin>>ch;
													   		switch(ch)
													   		{
													   			case 1:
													   				{
													   				c.book(50,140);
													   				break;
													   			}
													   			case 2:
													   				{
													   				c.book(100,140);
																	   break;	
																	   }
													   				
													   			case 3:
													   				{
													   					c.book(100,140);
													   					break;
																	   }
																case 4 :
																	{
																		c.book(150,140);
																		break;
																	}
																	default:
																	{ cout<<"\nWrong Choice";
																	  getch();
																	  goto counter;
															
         								                            }
                                    
                      			                             	}
                      			                             	break;
                      		                               	}
									  
									  
									                      default:
									                      	{
									                      	cout<<"\nWrong Choice";
															  getch();
														       goto trt;
															  }
													}
									                  break;    	
								}
								case 6:
									{
										goto x;
										break;
									}
								default:
									{
									cout<<"\n\nWrong Choice";
									break;	
									}
								}
									cout<<"\n\nWant to continue booking???  press y or n";
									cin>>ch;
							}
							break;
						}
								case 2:																														//worker menu case 2
                        			{
                        				c.showcstat();
										break;
									}	
                        		case 3:																														//worker menu case 3	
									{
										a.CheckBookingRecord();
                    	    			break;  	
									}		
                      											
                     			case 4:																														//worker menu case 5
                         			{
										system("CLS");
                         				cout<<"\t\Logging you out\n";
                         				cout<<"\t\t\t\t\t\t\n\nTHANK YOU FOR LOGGING IN"<<endl;
					                   cout<<"\t\t\t\t\t\t\n\nVISIT US AGAIN"<<endl;
                         				break; 	
									}
      				 			default:																													//worker menu default condn.
        				 			{
										cout<<"You Enter Wrong Choice\n";
       					 				break; 	
									}
    							}																															//end of switch
                 		
							cout<<"Press any key to continue...... ";
    						ch=getch();
    						}while(ch);  
                		         
           		 }
             
            	
    		
        		
				case 3:
				{
					cout<<"\t\t\t\t\t\t\n\nTHANK YOU FOR LOGGING IN"<<endl;
					cout<<"\t\t\t\t\t\t\n\nVISIT US AGAIN"<<endl;
					break;
				}
																																					//end of case 3
                 
   			default:																																		//main menu Default Condn.
       			{
         			cout<<"Wrong Choice !!!"<<endl;
     	 			break;
       			}																																			
    		}																																				//Main Menu Switch end

    	
 
return 0; 
  
}
