#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void new_project(char* project_names, char** projects, int rank) {

	char* ali = (char*)malloc(sizeof(char)*((sizeof(projects[rank]) / sizeof(char)) + (sizeof(project_names) / sizeof(char)) + 1));
	strcpy(ali, projects[rank]);
	realloc(projects, sizeof(char*) * ((sizeof(projects) / sizeof(char*)) + 1));
	projects[rank + 1] = " ";
	projects[rank] = (char*)malloc(sizeof(char)*((sizeof(projects[rank]) / sizeof(char)) + (sizeof(project_names) / sizeof(char)) + 1));
	strcat(ali, " ");
	strcat(ali, project_names);
	strcpy(projects[rank], ali);
	printf("%s\n", projects[rank]);
}
char* findusername(char* input, char* username) {
	const char *p1 = strstr(input, " ") + 1;
	const char *p2 = strstr(p1, " ");
	size_t len = p2 - p1;
	username = (char*)malloc(sizeof(char)*(len + 1));
	strncpy(username, p1, len);
	username[len] = '\0';
	printf("%s\n", username);
	return username;
}
char* findpassword(char* input, char* password) {
	const char *p1 = strstr(input, " ") + 1;
	const char *p2 = strstr(p1, " ") + 1;
	size_t len = input + strlen(input) - p2;
	password = (char*)malloc(sizeof(char)*(len + 1));
	strncpy(password, p2, len);
	password[len] = '\0';
	printf("%s\n", password);
	return password;
}
char* findinstruction(char* input, char* instruction) {
	int i = 0;
	int model = 0;
	int len = strlen(input);
	for (i;i < strlen(input);i++) {
		if (input[i] == ' ')
			model++;
	}
	if (model > 2) {
		printf("error!\n");
		return NULL;
	}
	if (model == 2) {
		const char *p1 = strstr(input, " ");
		size_t len = p1 - input;
		instruction = (char*)malloc(sizeof(char)*(len + 1));
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 1) {
		const char *p1 = strstr(input, " ");
		size_t len = p1 - input;
		instruction = (char*)malloc(sizeof(char)*(len + 1));
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	if (model == 0) {
		size_t len = input;
		instruction = (char*)malloc(sizeof(char)*(len + 1));
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	printf("%s\n", instruction);
	return instruction;
}
char* findprojectname(char* input, char* project) {
	const char *p1 = strstr(input, " ") + 1;
	size_t len = input + strlen(input) - p1;
	project = (char*)malloc(sizeof(char)*(len + 1));
	strncpy(project, p1, len);
	project[len] = '\0';
	printf("%s\n", project);
	return project;
}

char* getinputasSTRING() {
	int firstsize = 20;
	char* input;
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
	int t=0;
	while ((p1 = realloc(usernames, sizeof(char*) * (*rank + 1)) == NULL) && (p2 = realloc(passwords, sizeof(char*) * (*rank + 1)) == NULL))
	{
		t++;
	}
	
		usernames[*rank] = (char*)malloc((sizeof(username) / sizeof(char)) + 1);
		passwords[*rank] = (char*)malloc((sizeof(password) / sizeof(char)) + 1);
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
void checkinstructions(char** usernames, char** passwords, char** projects, char* input, int* state, int* signuprank) {
	char* instruction = NULL;
	char* username = NULL;
	char* password = NULL;
	char* project = NULL;
	int rank = 0;
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
			rank = (*signuprank) - 1;
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
			if ((rank = finduser(usernames, passwords, username, password, signuprank)) != -1) {
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
		new_project(project, projects, rank);
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
	instruction = NULL;
	username = NULL;
	password = NULL;
	project = NULL;
}

int main() {
	char* input = (char*)malloc(sizeof(char));
	char** usernames = (char**)malloc(sizeof(char*)*2);
	char** passwords = (char**)malloc(sizeof(char*)*2);
	char** projects = (char**)malloc(sizeof(char*)*2);
	projects[0] = " ";
	int state = 0;
	int signuprank = 0;
	int rank = 0;
	while (true)
	{
		input = getinputasSTRING();
		checkinstructions(usernames, passwords, projects, input, &state, &signuprank);
	}
	return 0;
}