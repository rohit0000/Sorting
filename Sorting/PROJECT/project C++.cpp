#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
	char name[129];
	char password[129];
	int id;
	int money;
};

struct admin{
	char name[129];
	char password[129];
	int id;
};

struct smartphone{
	char name[129];
	char brand[129];
	int price;
	char description[200];
};


int main()
{
	struct user user_array[20];
	struct admin admin_array[5];
	struct smartphone smartphone_array[100];
	FILE *ptr_file_userID;
	FILE *ptr_file_userpassword;
	FILE *ptr_file_username;
	FILE *ptr_file_usermoney;
	FILE *ptr_file_adminname;
	FILE *ptr_file_adminID;									// This section declares a pointer to a file outside the program
	FILE *ptr_file_adminpassword;
	FILE *ptr_file_smartphonename;
	FILE *ptr_file_smartphonebrand;
	FILE *ptr_file_smartphoneprice;
	FILE *ptr_file_smartphonedescription;



	int i, temp_int, stopper=0, login_ID, user_or_admin=0, identity;
	char temp_string[129], temp_description[200], login_password[129];
	int log_in, pickloop=0, index=-1, approver=0, temp, transaction;



	ptr_file_userID = fopen("User ID Text File.txt", "r");
	ptr_file_userpassword = fopen("User Password Text File.txt", "r");
	ptr_file_username = fopen("User Name Text File.txt", "r");
	ptr_file_usermoney = fopen("User Money Text File.txt", "r");
	ptr_file_adminname = fopen("Admin Name Text File.txt", "r");
	ptr_file_adminID = fopen("Admin ID Text File.txt", "r");					// this sets the pointer to the outside file.
	ptr_file_adminpassword = fopen("Admin Password Text File.txt", "r");		//the fopen function opens the outside file. "r" means read the file
	ptr_file_smartphonename = fopen("Smartphone Name Text File.txt", "r");
	ptr_file_smartphonebrand = fopen("Smartphone Brand Text File.txt", "r");
	ptr_file_smartphoneprice = fopen("Smartphone Price Text File.txt", "r");
	ptr_file_smartphonedescription = fopen("Smartphone Description Text File.txt", "r");




	for(i=0; i<20; i++){
        temp_int=0;
        strcpy(temp_string, "\0");
		fscanf(ptr_file_userID, "%d", &(temp_int));
		user_array[i].id=temp_int;
		fscanf(ptr_file_usermoney, "%d", &(temp_int));
		user_array[i].money=temp_int;
		fgets(temp_string, 129, ptr_file_username);	// the id is set to 8 if it is null, so let's find a way to not let any user use 8 as his/her ID.
		strcpy(user_array[i].name, temp_string);
		fgets(temp_string, 129, ptr_file_userpassword);
		strcpy(user_array[i].password,temp_string);
		printf("id: %d\n", user_array[i].id);	// ROHIT don't remove this line yet. This checks what the initial user ID's are.
        puts(user_array[i].password);
	}
	system("PAUSE");
	for(i=0; i<5; i++){
		fscanf(ptr_file_adminID, "%d", &(temp_int));
		admin_array[i].id=temp_int;								// this section reads every line from the text file and sets it to a structure variable
		fgets(temp_string, 129, ptr_file_adminname);
		strcpy(admin_array[i].name,temp_string);
		fgets(temp_string, 129, ptr_file_adminpassword);
		strcpy(admin_array[i].password,temp_string);
	}
	for(i=0; i<100; i++){
		fgets(temp_string, 129, ptr_file_smartphonename);
		strcpy(smartphone_array[i].name,temp_string);
		fgets(temp_string, 129, ptr_file_smartphonebrand);
		strcpy(smartphone_array[i].brand,temp_string);
		fgets(temp_description, 200, ptr_file_smartphonedescription);
		strcpy(smartphone_array[i].description, temp_description);
	}


	// START PROGRAM

	do
	{
		user_or_admin=0;
		stopper=0;
		system("cls");
		printf("Welcome to the smartphone shopping cart!\nDo you wish to login or register?\n[1] - Login\n[2] - Register\n[3] - Exit the program\n");
		scanf("%d", &log_in);



		// LOG IN



		if(log_in==1){
			system("cls");
			printf("Log In\n\n");
			printf("Please enter your user ID:");
			scanf("%d", &login_ID);
			printf("Please enter your password:");
			getchar();
			gets(login_password);
			system("cls");
			for(i=0; i<20; i++){
                puts(user_array[i].password);
                strcat(login_password, extra);
                puts(login_password);
				if((login_ID==user_array[i].id)&&(strcmp(login_password,user_array[i].password)==0)){
					identity=i;
					user_or_admin=1;
					i=20;
				}
				printf("value: %d\n", strcmp(login_password,user_array[i].password));
				system("PAUSE");
			}
			for(i=0; i<5; i++){
				if((login_ID==admin_array[i].id)&&(strcmp(login_password,admin_array[i].password)==0)){
					identity=i;
					user_or_admin=2;
					i=20;
				}
			}


			// LOGGED IN AS USER



			if(user_or_admin==1){
				system("cls");
				ptr_file_adminID = fopen("User ID Text File.txt", "w");
				ptr_file_adminpassword = fopen("User Password Text File.txt", "w");
				ptr_file_adminname = fopen("User Name Text File.txt", "w");
				do{
					pickloop=0;
					system("cls");
					printf("\nWelcome to the smartphone shopping cart, %s!\n", user_array[identity].name);
					printf("Please choose a transaction:\n\n");
					printf("[1] - Browse smartphone database\n");
					printf("[2] - Search a smartphone\n");
					printf("[3] - My Account\n");
					printf("[4] - Log Out");
					scanf("%d", &transaction);
					switch(transaction)
					{
						case 1:{

							break;
						}
						case 2:{

							break;
						}
						case 3:{

							break;
						}
						case 4:{

							break;
						}
						default:{
							system("cls");
							printf("Invalid input!\n\n");
							system("PAUSE");
						}
					}

				}
				while(pickloop==0);
			}



			// LOGGED IN AS ADMIN



			else if(user_or_admin==2){

			}







			else if(user_or_admin==0){
				printf("I'm sorry. Your ID and password do not match!\n\n");
				system("PAUSE");
			}
		}






		// REGISTER *THIS PART IS DONE*



		else if(log_in==2){
			system("cls");
			ptr_file_userID = fopen("User ID Text File.txt", "w");
			ptr_file_userpassword = fopen("User Password Text File.txt", "w");		// this opens the text files for writing
			ptr_file_username = fopen("User Name Text File.txt", "w");		// this region is very crucial when you're about to input something into the text files
			ptr_file_usermoney = fopen("User Money Text File.txt", "w");
			for(i=0; i<20; i++){
				if(user_array[i].id==8){
					index=i;
					i=20;
				}
			}
			printf("index: %d\n\n", index);
			system("PAUSE");
			if(index==-1){
				system("cls");
				printf("We are very sorry to inform you that the smartphone\n database has reached the maximum number of users.\n\nPlease consult one of the admins information.\n");
				system("PAUSE");
			}
			else if((index>=0)&&(index<20)){
				printf("\t\t\tRegister\nPlease fill up the necessary information:\nNegative and zero ID numbers are considered invalid\n\n");
				printf("Please enter a user ID:");
				do{
					pickloop=0;
					approver=0;
					scanf("%d", &temp);
					for(i=0; i<20; i++){
						if(((temp==user_array[i].id)&&(index!=i))||(temp<=0)){
							approver=1;
						}
					}
					if(approver==1){
						printf("\nI'm sorry. This user ID has either already been taken or invalid.\nYou will be returned to the Main Menu...\n");
						system("PAUSE");
						pickloop=1;
					}
					else if(approver==0){
						printf("\nPlease enter your name:");
						getchar();
						gets(user_array[index].name);
						printf("\nPlease enter a password:");
						getchar();
						gets(user_array[index].password);
						user_array[index].money = 50000;
						user_array[index].id = temp;
						system("cls");
						printf("Welcome to the Smartphone Shopping Cart, %s!\n\nID: %d", user_array[index].name, user_array[index].id);
						printf("\nYou have an initial credit of $50, 000. Spend wisely!\n\n");
						printf("\n\n\n\n\n\n\n\nYou will be returned to the Main Menu. Please log in to access your account.\n\n");
						system("PAUSE");
						pickloop=1;
					}
				}
				while(pickloop==0);

			}
		}



		// EXIT *THIS PART IS DONE*




		else if(log_in==3){
			system("cls");
			printf("Exiting the program...\n\nThank you for using the smartphone shopping cart!\n\n");
			system("PAUSE");
			stopper=1;
		}
		else{
			system("cls");
			printf("Invalid input!\n");
			system("PAUSE");
		}
	}
	while(stopper==0);


	// THIS REGION SAVES THE DATA ON DIFFERENT TEXT FILES *THIS PART IS DONE*



	for(i=0; i<20; i++){
		fprintf(ptr_file_userID, "%d\n", user_array[i].id);
		fprintf(ptr_file_usermoney, "%d\n", user_array[i].money);
		fprintf(ptr_file_username, "%s\n", user_array[i].name);
		fprintf(ptr_file_userpassword, "%s\n", user_array[i].password);
	}
	for(i=0; i<5; i++){
		fprintf(ptr_file_adminID, "%d\n", admin_array[i].id);
		fprintf(ptr_file_adminname, "%s\n", admin_array[i].name);
		fprintf(ptr_file_adminpassword, "%s\n", admin_array[i].password);
	}
	for(i=0; i<100; i++){
		fprintf(ptr_file_smartphonename, "%s\n", smartphone_array[i].name);
		fprintf(ptr_file_smartphonebrand, "%s\n", smartphone_array[i].brand);
		fprintf(ptr_file_smartphoneprice, "%d\n", smartphone_array[i].price);
		fprintf(ptr_file_smartphonedescription, "%s\n", smartphone_array[i].description);
	}


	// THIS REGION SAVES AND CLOSES THE TEXT FILES *THIS PART IS DONE*

	// don't forget this step because forgetting to close the text files will result to unsaved data

	fclose(ptr_file_userID);
	fclose(ptr_file_username);
	fclose(ptr_file_userpassword);
	fclose(ptr_file_usermoney);
	fclose(ptr_file_adminID);
	fclose(ptr_file_adminname);
	fclose(ptr_file_adminpassword);
	fclose(ptr_file_smartphonename);
	fclose(ptr_file_smartphonebrand);
	fclose(ptr_file_smartphoneprice);
	fclose(ptr_file_smartphonedescription);
	return 0;
}
