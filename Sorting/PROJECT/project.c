#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct user{
	char name[129];
	int id;
	int password;
	int money;
}*p_user[20];


struct admin{
	char name[129];
	int id;
	int password;
}*p_admin[5];


struct smartphone{
	char name[129];
	char brand[129];
	char price[129];
	char description[500];
}*p_smartphone[100];

void log_in_screen();

void user_log_in(int ID_identity);

void admin_log_in(int ID_identity);

void registers();

void add_smartphone(int smartphone_identity);

int main(){
	int i, temppass, tempid;
	char string[129];
	int log_in;
	FILE *ptr_file_userID;
	FILE *ptr_file_userpassword;
	FILE *ptr_file_username;
	FILE *ptr_file_usermoney;
	FILE *ptr_file_adminname;
	FILE *ptr_file_adminID;
	FILE *ptr_file_adminpassword;
	FILE *ptr_file_smartphonename;
	FILE *ptr_file_smartphonebrand;
	FILE *ptr_file_smartphoneprice;
	FILE *ptr_file_smartphonedescription;
	int stopper=0;
	ptr_file_userID = fopen("User ID Text File.txt", "w");
	ptr_file_userpassword = fopen("User Password Text File.txt", "w");
	ptr_file_username = fopen("User Name Text File.txt", "w");
	ptr_file_usermoney = fopen("User Money Text File.txt", "w");
	ptr_file_adminname = fopen("Admin Name Text File.txt", "w");
	ptr_file_adminID = fopen("Admin ID Text File.txt", "w");
	ptr_file_adminpassword = fopen("Admin Password Text File.txt", "w");
	ptr_file_smartphonename = fopen("Smartphone Name Text File.txt", "w");
	ptr_file_smartphonebrand = fopen("Smartphone Brand Text File.txt", "w");
	ptr_file_smartphoneprice = fopen("Smartphone Price Text File.txt", "w");
	ptr_file_smartphonedescription = fopen("Smartphone Description Text File.txt", "w");
	for(i=0; i<20; i++){
		p_user[i]->id=0;
		p_user[i]->password=0;
		p_user[i]->money=0;
		p_admin[i]->id=0;
		p_admin[i]->password=0;
	}
	for(i=0; i<20; i++){
		p_user[i] = (struct user *) malloc(sizeof(struct user));
		fgets(string, 129, ptr_file_username);
		strcpy(p_user[i]->name, string);
		fscanf(ptr_file_userID, "%d", &(p_user[i]->id));
		fscanf(ptr_file_userpassword, "%d", &(p_user[i]->password));
		fscanf(ptr_file_usermoney, "%d", &(p_user[i]->money));

	}
	for(i=0; i<5; i++){
		fscanf(ptr_file_adminpassword, "%d", &temppass);
		p_admin[i]->password = temppass;
		fscanf(ptr_file_adminID, "%d", &tempid);
		p_admin[i]->id = tempid;
		p_admin[i] = (struct admin *) malloc(sizeof(struct admin));
		fgets(string, 129, ptr_file_adminname);
		strcpy(p_admin[i]->name, string);
	}
	for(i=0; i<100; i++){
		p_smartphone[i] = (struct smartphones *) malloc(sizeof(struct smartphone));
		fgets(string, 129, ptr_file_smartphonename);
		strcpy(p_smartphone[i]->name, string);
		fgets(string, 129, ptr_file_smartphonebrand);
		strcpy(p_smartphone[i]->brand, string);
		fgets(string, 500, ptr_file_smartphonedescription);
		strcpy(p_smartphone[i]->description, string);
	}
	system("PAUSE");
	do{
		system("cls");
		printf("Welcome to the smartphone shopping cart!\nDo you wish to login or register?\n[1] - Login\n[2] - Register\n[3] - Exit the program\n");
		scanf("%d", &log_in);
		if(log_in==1){
			log_in_screen();
		}
		else if(log_in==2){
			registers();
		}
		else if(log_in==3){
			system("cls");
			printf("Exiting the program...\n\n");
			system("PAUSE");
		}
		else{
			system("cls");
			printf("Invalid input!\n");
			system("PAUSE");
		}

	}
	while(stopper==0);
	system("PAUSE");
	return 0;
}

void log_in_screen()
{
	int i, ID_num, ID_identity, password_identity, control=0;
	char entry_name[129];
	system("cls");
	printf("Log In\n\n");
	printf("Please enter your user ID:");
	scanf("%d", &ID_num);
	printf("Please enter your password:");
	scanf("%d", &password_identity);
	system("cls");
	for(i=0; i<20; i++){
		if((ID_num == p_user[i]->id && password_identity == p_user[i]->password)||(ID_num == p_admin[i]->id && password_identity == p_admin[i]->password))
        {
            control = 1;
            ID_identity = i;
            i=20;
		}
		else
        {
            control = 0;
        }
	}
	if(control == 0)
    {
        printf("ID or password not found");
    }
    else if(ID_num == p_user[ID_identity]->id && password_identity == p_user[ID_identity]->password){
    	system("cls");
    	printf("Welcome to the smartphone shopping cart, %s!\n", p_user[ID_identity]->name);
    	system("PAUSE");
    	user_log_in(ID_identity);

    }
    else if(ID_num == p_admin[ID_identity]->id && password_identity == p_admin[ID_identity]->password){
    	system("cls");
    	printf("Welcome to the smartphone shopping cart, %s!\n", p_user[ID_identity]->name);
    	system("PAUSE");
    	admin_log_in(ID_identity);
    }
	system("PAUSE");
}

void registers()
{
	int pickloop=0, temp, i, index=-1, approver=0;
		system("cls");
		for(i=0; i<20; i++){
			if(p_user[i]->id == NULL){
				index=i;
				i=20;
			}
		}
		if(index== -1){
			system("cls");
			printf("We are very sorry to inform you that the smartphone\n database has reached the maximum number of users.\n\nPlease consult one of the admins information.");
			system("PAUSE");
		}
		else if((index>=0)&&(index>20)){
			printf("Register!\nPlease fill up the necessary information:\n\n");
			printf("Please enter a user ID:");
			do
			{
				scanf("%d", &temp);
				for(i=0; i<20; i++){
					if((temp==p_user[i]->id)&&(index!=i)){
						approver=1;
					}
				}
				if(approver==1){
					printf("\nI'm sorry. This user ID has already been taken.\nPlease enter another one:");
				}
				else if(approver==0){
					p_user[index]->id = temp;
					pickloop=1;
				}

			}
			while(pickloop==0);
			printf("\nPlease enter your name:");
			getchar();
			gets(p_user[index]->name);
			printf("\nPlease enter a password:");
			scanf("%d", &temp);
			p_user[index]->password = temp;
			p_user[index]->money = 50000;
			system("cls");
			printf("Welcome to the Smartphone Shopping Cart, %s!", p_user[index]->name);
			printf("\nYou have an initial credit of $50, 000. Spend wisely!");
		}
		return;
}

void user_log_in(int ID_identity){
	char search_name[129], search_description[500], i, temp_name1[129], temp_name2[129];
	int transaction, stopper=0, search_criteria, innerloop=0, decision, temp, carrier[20], counter=-1;
	do{

		printf("\n");
		printf("Please choose a transaction:\n\n");
		printf("[1] - Browse smartphone database\n");
		printf("[2] - Search a smartphone\n");
		printf("[3] - My Account\n");
		printf("[4] - Log Out");
		scanf("%d", &transaction);
		switch(transaction){
			case 1: {

				break;
			}
			case 2:{
				do{
					system("cls");
					printf("\t\t\tSearch a smartphone\n\n");
					printf("Please choose a search criteria:\n");
					printf("\n[1] - Name");
					printf("\n[2] - Brand");
					printf("\n[3] - Price");
					printf("\n[4] - Description");
					printf("\n[5] - Back");
					switch(search_criteria){
						case 1:{
							system("cls");
							printf("Please enter your search name:");
							getchar();
							gets(search_name);
							printf("Results:\n\n");
							for(i=0; i<20; i++){
								strcpy(temp_name1, strlwr(search_name));
								strcpy(temp_name2, strlwr(p_smartphone[i]->name));
								if(strstr(temp_name1, temp_name2)!= NULL){
									system("cls");
									counter++;
									carrier[counter]=i;

								}
							}
							if(counter>-1){
								printf("%d.) %s\n", i+1, p_smartphone[i]->name);
								system("PAUSE");
								printf("\n[1] - Add to shopping cart\t[ELSE] - Go back\n");
								scanf("%d", &decision);
								if(decision==1){
									printf("Please enter your desired smartphone based from the numbering on the result list:");
									scanf("%d", &temp);
									carrier[temp-1]=temp;
									add_smartphone(temp);
								}
								else{
									// DO NOTHING
								}
							}
							else if(counter==-1){
									system("cls");
									printf("Nothing was found....\n");
									system("PAUSE");
							}
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
						case 5:{

							break;
						}
						default:{
							system("cls");
							printf("Invalid input!\n");
							system("PAUSE");
						}
					}

				}
				while(innerloop==0);
				break;
			}
			case 3: {

				break;
			}
			case 4: {
				system("cls");
				printf("Exiting the program...");
				stopper=1;
				break;
			}
			default:{
				system("cls");
				printf("Invalid input!\n");
				system("PAUSE");
			}
		}

	}while(stopper==0);
	return;
}


void admin_log_in(int ID_identity){

}

void add_smartphone(int smartphone_identity){

}

