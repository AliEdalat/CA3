#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void new_project(char* project_names, char** projects, int rank) {
	char** p1 = NULL;
	char* ali;
	int len_Project_name = strlen(project_names);
	int len_project_rank = strlen(projects[rank]);
	int first_size = 1;
	projects[first_size += 1] = " ";
	ali = (char*)malloc(sizeof(char)*(len_Project_name + len_project_rank + 2));
	strcpy(ali, projects[rank]);
	while ((p1 = realloc(projects, sizeof(char*) * (first_size+=2))) == NULL) {
		
	}
	projects[rank] = (char*)malloc(sizeof(char)*(len_Project_name+len_project_rank+2));
	strcat(ali, " ");
	strcat(ali, project_names);
	strcpy(projects[rank], ali);
	printf("%s\n", projects[rank]);
	free(ali);
}
char* findusername(char* input) {
	char* username;
	const char *p1;
	const char *p2;
	while ((p1 = strstr(input, " ") + 1) == NULL) {

	}
	while ((p2 = strstr(p1, " ")) == NULL) {

	}
	int len = p2 - p1;
	while ((username = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		
	}
	strncpy(username, p1, len);
	username[len] = '\0';
	printf("%s\n", username);
	return username;
}
char* findpassword(char* input ) {
	char* password;
	const char *p1;
	while ((p1 = strstr(input, " ") + 1) == NULL) {

	}
	const char *p2;
	while ((p2 = strstr(p1, " ") + 1) == NULL) {

	}
	int len = input + strlen(input) - p2;
	while ((password = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		
	}
	strncpy(password, p2, len);
	password[len] = '\0';
	printf("%s\n", password);
	return password;
	free(password);
}
char* findinstruction(char* input) {
	char* instruction=" ";
	int i = 0;
	int model = 0;
	int len = strlen(input);
	for (i;i < len;i++) {
		if (input[i] == ' ')
			model++;
	}
	if (model > 2) {
		printf("error!\n");
		return NULL;
	}
	if (model == 2) {
		const char *p1 = strstr(input, " ");
		int len = p1 - input;
		while ((instruction = (char*)malloc(sizeof(char)*(len + 1)))==NULL) {
			
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 1) {
		const char *p1 = strstr(input, " ");
		int len = p1 - input;
		while ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 0) {
		int len = strlen(input);
		while ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	printf("%s\n", instruction);
	return instruction;
	free(instruction);
}
char* findprojectname(char* input ) {
	char* project;
	const char *p1;
	while ((p1 = strstr(input, " ") + 1) == NULL) {
		
	}
	int len = input + strlen(input) - p1;
	while ((project = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		
	}
	strncpy(project, p1, len);
	project[len] = '\0';
	printf("%s\n", project);
	return project;
}

char* getinputasSTRING() {
	int firstsize = 20;
	char* input;
	char* p1;
	input = (char*)malloc(sizeof(char)*firstsize);
	int i = 0;
	char letter = '\0';
	while ((letter = getchar()) != '\n')
	{
		input[i++] = letter;
		if (i == firstsize) {
			input = (char*)realloc(input, sizeof(char)*(firstsize += 20));
		}
	}
	input[i++] = '\0';
	return input;
	free(input);
}
void Replace_Multiple_Space_With_Single(char* input) {
	int SizeOfString = 0;
	int j = 0;
	int i = 0;
	SizeOfString = strlen(input);
	for (j = 0; j < SizeOfString; j++)
	{
		for (i = 0; i < SizeOfString; i++)
		{
			if (input[i] == ' ' && input[i + 1] == ' ') {
				for (int j = i; j < SizeOfString; j++)
				{
					input[j] = input[j + 1];
				}
			}
		}
	}
}
void SignUp(char** usernames, char** passwords, char* username, char* password, int* rank) {
	char** p1=NULL;
	char** p2=NULL;
	int len_username = strlen(username);
	int len_password = strlen(password);
	int first_size = 1;
	while ((p1 = (char**)realloc(usernames, sizeof(char*) * (first_size+=2)) == NULL) && (p2 = (char**)realloc(passwords, sizeof(char*) * (first_size+=2)) == NULL)) {

	}
	usernames[*rank] = (char*)malloc(sizeof(char)*(len_username + 1)); 
	passwords[*rank] = (char*)malloc(sizeof(char)*(len_password + 1));
		strcpy(usernames[*rank], username);
		strcpy(passwords[*rank], password);
		(*rank) = (*rank) + 1;
		printf("%s\n%s\n%d\n", usernames[(*rank) - 1], passwords[(*rank) - 1], *rank);
	
}
int finduser(char** usernames, char** passwords, char*username, char*password, int*rank) {
	int i = 0;
	bool find = false;
	for (i = 0; i < *rank; i++)
	{
		if (!strcmp(usernames[i], username))
		{
			if (!strcmp(passwords[i], password)) {
				find = true;
				return i;
			}
			else
			{
				return -1;
			}
		}
	}
	if (find == false)
	{
		return -1;
	}
}
bool findstring(char* string, char* substring) {
	int len = strlen(substring);
	int len2 = strlen(string);
	char* p1=malloc(sizeof(char)*(len+2));
	char* p2 = malloc(sizeof(char)*(len2 + 2));
	bool find = false;
	strcpy(p1, " ");
	strcat(p1, substring);
	strcpy(p2, string);
	strcat(p2, " ");
	strcat(p1, " ");
	if (strstr(p2, p1) != NULL) {
				find = true;
	}
	return find;
	free(p1);
	free(p2);
}
void projects_status(char**projects,int rank) {
	printf("Your projects :%s\n", projects[rank]);
}
void checkinstructions(char** usernames, char** passwords, char** projects, char* input, int* state, int* signuprank,int* rank) {
	char* instruction = NULL;
	char* username = NULL;
	char* password = NULL;
	char* project = NULL;
	bool correct_instruction = false;
	instruction = findinstruction(input);
	if (instruction == NULL) {
		printf("error! your instruction is not correct!\n");
		return;
	}
	if ((strcmp(instruction, "signup") == 0) && (*state == 0))
	{
		int spaces = 0;
		int i = 0;
		bool find = false;
		int len = strlen(input);
		for (i = 0; i < len; i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		if (spaces == 2) {
			username = findusername(input);
			password = findpassword(input);
			if (*signuprank != 0) {
				for (i = 0; i < *signuprank; i++)
				{
					if (strcmp(usernames[i] ,username)==0) {
						find = true;
						break;
					}
				}

			}
			if (find==false) {
				SignUp(usernames, passwords, username, password, signuprank);
				*state = 1;
				*rank = (*signuprank) - 1;
				printf("User %s is added to users.\n", username);
			}
			else
			{
				printf("I find this username !Please try again!\n ");
			}
			correct_instruction = true;
		}
		else
		{
			printf("error! your instruction is not correct!\nsignup <username> <password>\n");
			return;
		}


	}
	if ((strcmp(instruction, "login") == 0) && (finduser(usernames, passwords, findusername(input, username), findpassword(input, password), signuprank) != -1) && (*state != 1) && (*state != 2))
	{
		int spaces = 0;
		int userID = 0;
		int i = 0;
		int len = strlen(input);
		for (i = 0; i <len; i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		if (spaces == 2)
		{
			username = findusername(input);
			password = findpassword(input);
			if ((*rank = finduser(usernames, passwords, username, password, signuprank)) != -1) {
				printf("%d\n", finduser(usernames, passwords, username, password, signuprank));
				printf("Welcome back dear %s!\n", username);
				*state = 2;
				correct_instruction = true;
			}
			else
			{
				printf("error! your username or password  not found!\nlogin <username> <password>");
				return;
			}
		}
		else
		{
			printf("error! your instruction is not correct!\nlogin <username> <password>");
			return;
		}
	}
	if ((strcmp(instruction, "new_project") == 0) && (*state == 2 || *state == 1))
	{
		int i = 0;
		bool find = false;
		char* projectname;
		int len = strlen(input);
		int spaces = 0;
		for ( i = 0; i < len; i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		if (spaces == 1) {
			project = findprojectname(input);
			if (findstring(projects[*rank],project)==false) {
				new_project(project, projects, *rank);
				printf("New project %s is added for user %s\n", project, usernames[*rank]);
			}
			else
			{
				printf("I find this project in your projects!\n");
			}
		}
		else
		{
			printf("your instruction is not correct!\nnew_project <project's name>\n");
		}
		correct_instruction = true;
	}
	if ((strcmp(instruction, "add_user") == 0)&&(*state==2||*state == 1))
	{
		int i = 0;
		bool find_user = false;
		int userID = 0;
		int spaces = 0;
		int len = strlen(input);
		for (int i = 0; i < len; i++)
		{
			if (input[i] == ' ') {
				spaces++;
			}
		}
		if (spaces == 2) {
			username = findusername(input);
			project = findpassword(input);
			for (i = 0; i < *signuprank; i++)
			{
				if (strcmp(username, usernames[i]) == 0) {
					find_user = true;
					userID = i;
					break;
				}
			}
			if (find_user == true && username!=" " && project!=" ") {
				if (findstring(projects[userID], project) == false && findstring(projects[*rank], project) == true) {
					new_project(project, projects, userID);
					printf("New contributer \"%s\" is added to project \"%s\" now!\n",username,project);
				}
				else if (findstring(projects[*rank], project) == false) {
					printf("You can not use \"add_user\".I can not find this project in your projects!\n");
				}
				else if (username == " " && project == " ") {
					printf("your instruction is not correct!\n");
				}
				else
				{
					printf("I find %s project in %s's projects!\n", project, usernames[userID]);
				}
			}
			else
			{
				printf("User not found!\n");
			}
		}
		else
		{
			printf("Your instruction is not correct!\nadd_user <username> <project's name>\n");
		}
		correct_instruction = true;
	}
	if ((strcmp(instruction, "projects_status") == 0) && (*state == 2||*state == 1))
	{
		projects_status(projects, *rank);
		correct_instruction = true;
	}
	if ((strcmp(instruction, "logout") == 0) && (*state == 1 || *state == 2))
	{
		printf("You signed out successfully. See you soon!\n");
		correct_instruction = true;
		*state = 0;
	}
	if (correct_instruction == false)
		printf("error! your instruction is not correct!\n");
	free(instruction);
	free(username);
	free(password);
	free(project);
}

int main() {
	char** projects;
	char** passwords;
	char** usernames;
	char* input;
	while ((input = (char*)malloc(sizeof(char))) == NULL) {
		free(input);
	}
	while ((usernames = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		free(usernames);
	}
	
	while ((passwords = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		free(passwords);
	}
	
	while ((projects = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		free(projects);
	}
	for (int i = 0; i < 10; i++)
	{
		projects[i] = " ";
	}
	for (int i = 0; i < 10; i++)
	{
		usernames[i] = " ";
	}
	for (int i = 0; i < 10; i++)
	{
		passwords[i] = " ";
	}
	int state = 0;
	int signuprank = 0;
	int rank = 0;
	while (true)
	{
		input = getinputasSTRING();
		checkinstructions(usernames, passwords, projects, input, &state, &signuprank,&rank);
	}
	return 0;
}