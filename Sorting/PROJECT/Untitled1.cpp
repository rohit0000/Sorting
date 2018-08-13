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


void user_editor(struct user *p_user);

void smartphone_editor(struct smartphone *p_smartphone);

int main()
{
	struct user user_array[20];
	struct admin admin_array[5];
	struct user *p_user;
	struct smartphone *p_smartphone;
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
	
	
	
	int i, temp_int, stopper=0, login_ID, user_or_admin=0, identity, edit_user, edit_smartphone;	
	char temp_string[129], temp_description[200], login_password[129];
	int log_in, pickloop=0, index=-1, approver=0, temp, transaction, admin_operation;
	
	
	
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
		fscanf(ptr_file_userID, "%d", &(temp_int));			
		user_array[i].id=temp_int;
		fscanf(ptr_file_usermoney, "%d", &(temp_int));
		user_array[i].money=temp_int;						
		fgets(temp_string, 129, ptr_file_username);	// the id is set to 8 if it is null, so let's find a way to not let any user use 8 as his/her ID.
		strcpy(user_array[i].name, temp_string);
		fgets(temp_string, 129, ptr_file_userpassword);
		strcpy(user_array[i].password,temp_string);
		printf("id: %d\n", user_array[i].id);	// ROHIT don't remove this line yet. This checks what the initial user ID's are.
	}
	system("PAUSE");
	system("cls");
	for(i=0; i<20; i++){
		printf("Name: %s\n", user_array[i].name);
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
		fscanf(ptr_file_smartphoneprice, "%d", &(temp_int));
		smartphone_array[i].price=temp_int;
		fgets(temp_string, 129, ptr_file_smartphonename);
		strcpy(smartphone_array[i].name,temp_string);
		fgets(temp_string, 129, ptr_file_smartphonebrand);
		strcpy(smartphone_array[i].brand,temp_string);
		fgets(temp_description, 200, ptr_file_smartphonedescription);
		strcpy(smartphone_array[i].description, temp_description);
	}
	
	
	// START PROGRAM *THIS PART IS DONE*
	
	do
	{
		user_or_admin=0;
		stopper=0;
		system("cls");
		printf("Welcome to the smartphone shopping cart!\nDo you wish to login or register?\n[1] - Login\n[2] - Register\n[3] - Exit the program\n");
		scanf("%d", &log_in);
		
		
		
		// LOG IN *THIS PART IS DONE*
		
		
		
		if(log_in==1){
			system("cls");
			printf("Log In\n\n");
			printf("Please enter your user ID:");
			scanf("%d", &login_ID);
			printf("Please enter your password:");
			getchar();
			gets(login_password);
			strcat(login_password, "\n");
			system("cls");
			for(i=0; i<20; i++){
				if((login_ID==user_array[i].id)&&(strcmp(user_array[i].password, login_password)==0)){
					identity=i;
					user_or_admin=1;
					i=20;
				}
			}
			if((login_ID==user_array[1].id)&&(strcmp(user_array[i].password, login_password)==0)){
				
			}
			else{
				
			}
			system("PAUSE");
			for(i=0; i<5; i++){
				if((login_ID==admin_array[i].id)&&(strcmp(login_password,admin_array[i].password)==0)){
					identity=i;
					user_or_admin=2;
					i=20;
				}
				if(login_ID==admin_array[i].id){
					printf("MATCH!\n");
				}
				else if (login_ID!=admin_array[i].id){
					printf("Too bad...");
				}
				printf("value: %d\n", strcmp(login_password,admin_array[i].password));
				system("PAUSE");
			}
			
			
			// LOGGED IN AS USER
			
			
			
			if(user_or_admin==1){
				system("cls");
				do{
					pickloop=0;
					system("cls");
					printf("\nWelcome to the smartphone shopping cart, %s\n", user_array[identity].name);
					printf("Please choose a transaction:\n\n");
					printf("[1] - Browse smartphone database\n");
					printf("[2] - Search a smartphone\n");
					printf("[3] - My Account\n");
					printf("[4] - Log Out\n");
					scanf("%d", &transaction);
					switch(transaction)
					{
						case 1:{
							system("cls");
							printf("\t\t\t\tSmartphone Database\n\n");
							for(i=0; i<20; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d\n", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							system("PAUSE");
							system("cls");
							for(i=20; i<40; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d\n", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							system("PAUSE");
							system("cls");
							for(i=40; i<60; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d\n", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							system("PAUSE");
							system("cls");
							for(i=60; i<80; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d\n", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							system("PAUSE");
							system("cls");
							for(i=80; i<100; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d\n", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							system("PAUSE");
							printf("\n[1] - Add a smartphone\t\t[2] - Go Back\n");
							scanf("%d", &admin_operation);
							break;
						}
						case 2:{
							
							break;
						}
						case 3:{
							
							break;
						}
						case 4:{
							system("cls");
							printf("Logging out...\n\n");
							system("PAUSE");
							pickloop=1;
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
			
			
			
			// LOGGED IN AS ADMIN *THIS PART IS DONE*
			
			
			
			else if(user_or_admin==2){
				system("cls");
				ptr_file_userID = fopen("User ID Text File.txt", "w");
				ptr_file_userpassword = fopen("User Password Text File.txt", "w");
				ptr_file_username = fopen("User Name Text File.txt", "w");
				ptr_file_smartphonename = fopen("Smartphone Name Text File.txt", "w");
				ptr_file_smartphonebrand = fopen("Smartphone Brand Text File.txt", "w");
				ptr_file_smartphoneprice = fopen("Smartphone Price Text File.txt", "w");
				ptr_file_smartphonedescription = fopen("Smartphone Description Text File.txt", "w");
				do{
					pickloop=0;
					printf("Administrator:\n\nPlease choose a transaction:\n");
					printf("[1] - View users\n");
					printf("[2] - View Smartphone Database\n");
					printf("[3] - Log Out\n");
					scanf("%d", &transaction);
					switch(transaction){
						case 1:{
							system("cls");
							printf("\t\t\t\tUser Database\n\n");
							for(i=0; i<20; i++){
								printf("\t\t\t\tUSER #%d\n\n", i+1);
								if(user_array[i].id!=8){
									printf("User ID: %d\n", user_array[i].id);
									printf("Username: %s\n", user_array[i].name);
									printf("User Password: %s", user_array[i].password);
									printf("Money of user: P%d\n\n\n", user_array[i].money);
								}
								else{
									printf("NULL user\n\n\n");
								}
							}
							printf("\n[1] - Edit a user\t\t[2] - Remove user\n[3] - Go Back\n");
							scanf("%d", &admin_operation);
							switch(admin_operation){
								case 1:{
									printf("\n\nPlease enter the user number that you want to edit:");
									scanf("%d", &edit_user);
									edit_user= edit_user-1;
									if((edit_user>=0)&&(edit_user<20)){
										p_user = &user_array[edit_user];
										user_editor(p_user);
										printf("\n\nYou have successfully editted a user!");
										system("PAUSE");
									}
									else{
										printf("Invalid entry!\n");
										system("PAUSE");
									}
									
									break;
								}
								case 2:{
									printf("\n\nPlease enter the user number that you want to remove:");
									scanf("%d", &edit_user);
									edit_user= edit_user-1;
									if((edit_user>=0)&&(edit_user<20)){
										user_array[edit_user].id = 8;
										user_array[edit_user].money = 0;
										strcpy(user_array[edit_user].name, "");
										strcpy(user_array[edit_user].password, "");
										printf("\n\nYou have successfully removed a user!");
										system("PAUSE");
									}
									else{
										printf("Invalid entry!\n");
										system("PAUSE");
									}
									break;
								}
								case 3:{
									printf("\n\nReturning to the Main Menu shortly\n\n");
									system("PAUSE");
									break;
								}
								default:{
									system("cls");
									printf("Invalid Input!\n\n");
									system("PAUSE");
								}
							}
							break;
						}
						case 2:{
							system("cls");
							printf("\t\t\t\tSmartphone Database\n\n");
							for(i=0; i<100; i++){
								printf("\t\t\t\tSMARTPHONE #%d\n\n", i+1);
								if(smartphone_array[i].name!= NULL){
									printf("Name: %s\n", smartphone_array[i].name);
									printf("Brand: %s\n", smartphone_array[i].brand);
									printf("Price: P%d", smartphone_array[i].price);
									printf("Description: %s\n\n\n", smartphone_array[i].description);
								}
								else{
									printf("SMARTPHONE UNAVAILABLE\n\n\n");
								}
							}
							printf("\n[1] - Edit a smartphone\t\t[2] - Remove smartphone\n[3] - Go Back\n");
							scanf("%d", &admin_operation);
							switch(admin_operation){
								case 1:{
									printf("\n\nPlease enter the smartphone number that you want to edit:");
									scanf("%d", &edit_smartphone);
									edit_smartphone= edit_smartphone-1;
									if((edit_smartphone>=0)&&(edit_smartphone<100)){
										p_smartphone = &smartphone_array[edit_smartphone];
										smartphone_editor(p_smartphone);
										printf("\n\nYou have successfully editted a smartphonne!");
										system("PAUSE");
									}
									else{
										printf("Invalid entry!\n");
										system("PAUSE");
									}
									break;
								}
								case 2:{
									printf("\n\nPlease enter the smartphone number that you want to edit:");
									scanf("%d", &edit_smartphone);
									edit_smartphone= edit_smartphone-1;
									if((edit_smartphone>=0)&&(edit_smartphone<100)){
										strcpy(smartphone_array[edit_smartphone].name, "");
										strcpy(smartphone_array[edit_smartphone].brand, "");
										strcpy(smartphone_array[edit_smartphone].description, "");
										smartphone_array[edit_smartphone].price = 8;
										printf("\n\nYou have successfully removed a smartphonne!");
										system("PAUSE");
									}
									else{
										printf("Invalid entry!\n");
										system("PAUSE");
									}
									break;
								}
								case 3:{
									printf("\n\nReturn to the Main Menu shortly\n\n");
									system("PAUSE");
									break;
								}
								default:{
									system("cls");
									printf("Invalid Input!\n\n");
									system("PAUSE");
								}
							}
							break;
						}
						case 3:{
							system("cls");
							printf("Logging out...\n\n");
							system("PAUSE");
							pickloop=1;
							break;
						}
						default:{
							system("cls");
							printf("Invalid input!\n\n");
							system("PAUSE");
						}
					}
				}
				while(pickloop=0);
				
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
						user_array[index].money = 500000;
						user_array[index].id = temp;
						system("cls");
						printf("Welcome to the Smartphone Shopping Cart, %s!\n\nID: %d", user_array[index].name, user_array[index].id);
						printf("\nYou have an initial credit of P500, 000. Spend wisely!\n\n");
						printf("\n\n\n\n\n\n\n\nYou will be returned to the Main Menu. Please log in to access your account.\n\n");
						system("PAUSE");
						fclose(ptr_file_userID);
						fclose(ptr_file_username);
						fclose(ptr_file_userpassword);
						fclose(ptr_file_usermoney);
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

void user_editor(struct user *p_user){
	int temp_int;
	char temp_string[129];
	system("cls");
	printf("Current information:\n");
	printf("Username: %s\n", p_user->name);
	printf("User Password: %s", p_user->password);
	printf("Money of user: %d\n\n\n", p_user->money);
	printf("Edit:\n");
	printf("Please enter a new user ID:");
	scanf("%d", &temp_int);
	p_user->id = temp_int;
	printf("Please enter a new username:");
	getchar();
	gets(temp_string);
	strcpy(p_user->name,temp_string);
	printf("Please enter a new user password:");
	getchar();
	gets(temp_string);
	strcpy(p_user->password,temp_string);
	printf("Please enter a new user credit:");
	scanf("%d", &temp_int);
	p_user->money = temp_int;
	return;
}

void smartphone_editor(struct smartphone *p_smartphone){
	int temp_int;
	char temp_string[129];
	system("cls");
	printf("Current information:\n");
	printf("Smartphone Name: %s\n", p_smartphone->name);
	printf("Smartphone Brand: %s\n", p_smartphone->brand);
	printf("Smartphone Price: %d\n", p_smartphone->price);
	printf("Smartphone Description: %s\n", p_smartphone->description);
	printf("Edit:\n");
	printf("Please enter a new Smartphone Name:");
	getchar();
	gets(temp_string);
	strcpy(p_smartphone->name,temp_string);
	printf("Please enter a new Brand:");
	getchar();
	gets(temp_string);
	strcpy(p_smartphone->brand,temp_string);
	printf("Please enter a new Price: P");
	scanf("%d", &temp_int);
	p_smartphone->price = temp_int;
	printf("Please enter a new Description:");
	getchar();
	gets(temp_string);
	strcpy(p_smartphone->description,temp_string);
	return;
}
