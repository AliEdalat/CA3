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
	while ((ali = (char*)malloc(sizeof(char)*(len_Project_name+ len_project_rank +2))) == NULL) {
		free(ali);
	}
	strcpy(ali, projects[rank]);
	while ((p1 = realloc(projects, sizeof(char*) * (rank+6))) == NULL) {
		
	}
	projects[rank + 1] = " ";
	projects[rank] = (char*)malloc(sizeof(char)*(len_Project_name+len_project_rank+2));
	strcat(ali, " ");
	strcat(ali, project_names);
	strcpy(projects[rank], ali);
	printf("%s\n", projects[rank]);
}
char* findusername(char* input, char* username) {
	const char *p1;
	const char *p2;
	while ((p1 = strstr(input, " ") + 1) == NULL) {

	}
	while ((p2 = strstr(p1, " ")) == NULL) {

	}
	int len = p2 - p1;
	while ((username = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		free(username);
	}
	strncpy(username, p1, len);
	username[len] = '\0';
	printf("%s\n", username);
	return username;
}
char* findpassword(char* input, char* password) {
	const char *p1;
	while ((p1 = strstr(input, " ") + 1) == NULL) {

	}
	const char *p2;
	while ((p2 = strstr(p1, " ") + 1) == NULL) {

	}
	int len = input + strlen(input) - p2;
	while ((password = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		free(password);
	}
	strncpy(password, p2, len);
	password[len] = '\0';
	printf("%s\n", password);
	return password;
}
char* findinstruction(char* input, char* instruction) {
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
			free(instruction);
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 1) {
		const char *p1 = strstr(input, " ");
		int len = p1 - input;
		while ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			free(instruction);
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 0) {
		int len = strlen(input);
		while ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			free(instruction);
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	printf("%s\n", instruction);
	return instruction;
}
char* findprojectname(char* input, char* project) {
	const char *p1;
	while ((p1 = strstr(input, " ") + 1) == NULL) {
		
	}
	int len = input + strlen(input) - p1;
	while ((project = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		free(project);
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
	while ((input = (char*)malloc(sizeof(char)*firstsize)) == NULL) {
		free(input);
	}
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
	while ((p1 =( char**)realloc(usernames, sizeof(char*) * (*rank + 6)) == NULL) && (p2 = (char**)realloc(passwords, sizeof(char*) * (*rank + 6)) == NULL))
	{
		
	}
	
		usernames[*rank] = (char*)malloc(sizeof(char)*(len_username+1));
		passwords[*rank] = (char*)malloc(sizeof(char)*(len_password+1));
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
void checkinstructions(char** usernames, char** passwords, char** projects, char* input, int* state, int* signuprank,int* rank) {
	char* instruction = NULL;
	char* username = NULL;
	char* password = NULL;
	char* project = NULL;
	bool correct_instruction = false;
	instruction = findinstruction(input, instruction);
	if (instruction == NULL) {
		printf("error! your instruction is not correct!\n");
		return;
	}
	if ((strcmp(instruction, "signup") == 0) && (*state == 0))
	{
		int spaces = 0;
		int i = 0;
		int len = strlen(input);
		for (i = 0; i < len; i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		if (spaces == 2) {
			username = findusername(input, username);
			password = findpassword(input, password);
			SignUp(usernames, passwords, username, password, signuprank);
			*state = 1;
			*rank = (*signuprank) - 1;
			correct_instruction = true;
			printf("User %s is added to users.\n", username);
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
			username = findusername(input, username);
			password = findpassword(input, password);
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

		project = findprojectname(input, project);
		new_project(project, projects, *rank);
		correct_instruction = true;
	}
	/*
	if ((strcmp(instruction, "add_user") == 0)&&(*state==2||*state == 1))
	{
	int i = 0;
	bool find_user = false;
	int userID = 0;
	username = findusername(input, username);
	project = findpassword(input, project);
	for ( i = 0; i <*rank; i++)
	{
	if (username == usernames[i]) {
	find_user = true;
	userID = i;
	break;
	}
	}
	if (find_user == true) {
	new_project(project, projects, userID);
	}
	else
	{
	printf("User not found!\n");
	}
	correct_instruction = true;
	}
	if ((strcmp(instruction, "projects_status") == 0) && (*state == 2||*state == 1))
	{
	correct_instruction = true;
	}*/
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
	while ((usernames = (char**)malloc(sizeof(char*) * 5)) == NULL) {
		free(usernames);
	}
	
	while ((passwords = (char**)malloc(sizeof(char*) * 5)) == NULL) {
		free(passwords);
	}
	
	while ((projects = (char**)malloc(sizeof(char*) * 5)) == NULL) {
		free(projects);
	}
	projects[0] = " ";
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