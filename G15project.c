#include <stdio.h>	
#include <stdlib.h>	
#include <string.h>
//Creating a structure called "employeee" to store different members ass required.	
//Creating members of different data type to store details of employee as shown.
typedef struct {		
	int id;				//stores ID of the employee.
	char name[100];		//stores Name of the employee.
	char post[100];		//stores Post/Designation of the employee.
	int salary;			//stores Salary of the employee.
	char address[100];	//stores Address of the employee.
}employee;				//Name of structure.

int main()
{
	employee emp;	//Creating a variable called "emp" of the structure employee
	int choice;		//Integer data type variable for switch case.
	
	//Choice Menu details for user to choose from.
		printf("Enter <1> to Add employee record");
		printf("\nEnter <2> to Display employee record");
		printf("\nEnter <3> to Modify employee record");
		printf("\nEnter <4> to Delete employee record");
		printf("\nEnter <5> to exit");
	
	while(1)	//Infinite While loop so user can choose multiple choices from the menu.
	{
	printf("\n\nEnter your choice:");	
	scanf("%d", &choice);				//Reading the choice from user.
	
		switch(choice)
		{
			case 1:			//Case 1: Reading the employee details from the User.
				{	
					char ch;
					
					printf("\n\nEnter your ID:");
					scanf("%d", &emp.id);		
					ch=getchar();
					printf("\nEnter your name:");
					fgets(emp.name,100,stdin);
					printf("\nEnter your Designation:");
					fgets(emp.post, 100, stdin);
					printf("\nEnter your Address:");
					fgets(emp.address, 100, stdin);
					printf("\nEnter salary:");
					scanf("%d", &emp.salary);
					break;
				}
			case 2:			//Printing the details of the Employee entered by the user.
				{
					printf("\n\n");
					printf("Employee ID:%d\n", emp.id);
					printf("Employee Name:%s", emp.name);
					printf("Employee Designation:%s", emp.post);
					printf("Employee Address:%s", emp.address);
					printf("Employee Salary:%d", emp.salary);
					break;
				}	
			case 3:		//To Modify Individual detials or All details as user wishes.
				{	
					char ch, field[20];
					
					// User should enter "all" to modify all the details.	
					printf("To Modify all details enter \"all\".");	
					
					//User should enter individual field name as shown to modify individual detials.
					printf("\nTo modify individual detials, enter the field to modify \n[Id/Name/Designation/Address/Salary]:\n");
					scanf("%s",field);
					
					/*If condition checks if the string entered by user matches to the individual field names or "all".
					strcmp() (string compare function) is used for this purpose to compare the string entered by 
					the user with the required string.*/
					
					//Body block of each if/else if condition modifies the specified employee detail.			
					if(strcmp(field,"Id")==0 || strcmp(field,"id")==0 )	 
					{
						printf("\n\nEnter new ID:");
						scanf("%d", &emp.id);
					}
					else if(strcmp(field,"Name")==0 || strcmp(field,"name")==0 )
					{
						printf("\nEnter new name:"); 
						ch=getchar();
						fgets(emp.name,100,stdin);
					}
					else if(strcmp(field,"Designation")==0 || strcmp(field,"designation")==0 )
					{
						printf("\n\nEnter new designation:");
						ch=getchar();
						fgets(emp.post,100,stdin);
					}
					else if(strcmp(field,"Address")==0 || strcmp(field,"address")==0 )
					{
						printf("\nEnter new address:");
						ch=getchar();
						fgets(emp.address, 100, stdin);
					}
					else if(strcmp(field,"Salary")==0 || strcmp(field,"salary")==0 )
					{
						printf("\nEnter new salary:");
						ch=getchar();
						scanf("%d", &emp.salary);
					}
					else if(strcmp(field,"all")==0)
					{
					
						printf("\n\nEnter new ID:");
						scanf("%d", &emp.id);
						ch=getchar();
						printf("\nEnter new name:");
						fgets(emp.name,100,stdin);
						printf("\nEnter new Designation:");
						fgets(emp.post, 100, stdin);
						printf("\nEnter new Address:");
						fgets(emp.address, 100, stdin);
						printf("\nEnter new salary:");
						scanf("%d", &emp.salary);
					}
					else
					{
						printf("Invalid Input. Try Again.");
					}
					break;
				}
				
			case 4:		//To delete the details of the employee. 
				{
				char confirm[2];
					
					//Shows user the warning message and confirms before deleting the details.
					printf("Are you sure you want to delete? (y/n)\n");
					scanf("%s", confirm);	//should should enter either "y" or "n" in the string as per his choice.
					
					if(strcmp(confirm,"y")==0)		//if user enters y, all the employee details are reset.
					{
						//A string called reset is defined which stores "----\n". This string is used to reset the string variables. 
						char reset[10]="----\n";	 
						
						//Using string copy function strcpy() to copy reset string into the employee detail strings.
						strcpy(emp.name,reset);
						strcpy(emp.post,reset);
						strcpy(emp.address,reset);
						
						//resetting the ID and Salary of the employee to zero.
						emp.id=0;
						emp.salary=0;
						
						printf("Your record has been deleted.");
					
					}
					
					//if user enters n, that means he doesn't want to delete the detials and is reverted back to the menu choices.
					else if(strcmp(confirm,"n")==0)	
					{
						break;
					}
					
					//message for the invalid input when user enters anything else other than "y" or "n".
					else
					{
						printf("Invalid input. Try Again.");
						
					}
					break;
				}	
				
			case 5:	//exits the program.
				{
					exit(0);
				}
			default: //displays a message for invalid choice and exits.
			{
				printf("Invalid Choice! Try Again.");
				exit(0);
			}			
		}
		printf("\n\n");	// New lines for tidy look.
	}
	return 0;		
}
