#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char* findusername(char* input,char* username) {
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
	const char *p2 = strstr(p1, " ")+1;
	size_t len = input+ strlen(input) - p2;
	password = (char*)malloc(sizeof(char)*(len + 1));
	strncpy(password, p2, len);
	password[len] = '\0';
	printf("%s\n", password);
	return password;
}
char* findinstruction(char* input, char* instruction) {
	int i = 0;
	int model = 0;
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
		size_t len =  input;
		instruction = (char*)malloc(sizeof(char)*(len + 1));
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}
	printf("%s\n", instruction);
	return instruction;
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
	for ( j = 0; j < SizeOfString; j++)
	{
		for ( i = 0; i < SizeOfString; i++)
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
void SignUp(char** usernames, char** passwords,char* username,char* password,int* rank) {
	
	 realloc(usernames, sizeof(char*) * 1);
	 realloc(passwords,sizeof(char*)*1);
	 usernames[*rank] = username;
	 passwords[*rank] = password;
	 (*rank)++;
	 printf("%s\n%s\n%d\n", usernames[(*rank)-1], passwords[(*rank) - 1], *rank);
}
int finduser(char** usernames, char** passwords, char*username, char*password) {
	int i = 0;
	bool find = false;

	int len = (sizeof(usernames)) / (sizeof(usernames[0]));
	for ( i = 0; i < len; i++)
	{
		if (!strcmp(usernames[i],username)&& !strcmp(passwords[i], password))
		{
			find = true;
			return i;

		}
	}
	if (find==false)
	{
		return -1;
	}
}
void checkinstructions(char** usernames,char** passwords,char* input,int* state,int* rank) {
	char* instruction=NULL;
	char* username=NULL;
	char* password = NULL;
	bool correct_instruction = false;
	instruction=findinstruction(input, instruction);
	if (instruction == NULL) {
		printf("error! your instruction is not correct!\n");
		return;
	}
	if (strcmp(instruction,"signup")==0&& (*state==0))
	{
		int spaces = 0;
		int i = 0;
		for (i = 0; i < strlen(input); i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		printf("%d\n", spaces);
		if (spaces == 2) {
			username = findusername(input, username);
			password = findpassword(input, password);
			SignUp(usernames,passwords,username,password,rank);
			*state = 1;
			correct_instruction = true;
			printf("User %s is added to users.\n", username);
		}
		else
		{
			printf("error! your instruction is not correct!\nsignup <username> <password>\n");
			return;
		}
		
		
	}
	if (strcmp(instruction, "login") == 0&&(finduser(usernames,passwords,findusername(input,username),findpassword(input,password))!=-1)&&(*state!=1))
	{
		int spaces = 0;
		int i = 0;
		for (i = 0; i < strlen(input); i++)
		{
			if (input[i] == ' ')
				spaces++;
		}
		printf("%d\n",spaces);
		if (spaces == 2)
		{
			username = findusername(input, username);
			password = findpassword(input, password);
			if (finduser(usernames,passwords,username,password) != -1) {
				printf("%d\n", finduser(usernames, passwords, username, password));
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
	if (strcmp(instruction, "new_project") == 0&&((*state!=0)))
	{

		correct_instruction = true;
	}
	if (strcmp(instruction, "add_user") == 0&&((*state!=0)))
	{
		correct_instruction = true;
	}
	if (strcmp(instruction, "projects_status") == 0 && ((*state != 0)))
	{
		correct_instruction = true;
	}
	if (strcmp(instruction, "logout") == 0 && ((*state != 0)) )
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
}

int main() {
	char* input = (char*)malloc(sizeof(char));
	char** usernames = (char**)malloc(sizeof(char*));
	char** passwords = (char**)malloc(sizeof(char*));
	int state = 0;
	int rank = 0;
	while (true)
	{
		input = getinputasSTRING();
		checkinstructions(usernames,passwords,input, &state,&rank);
	}
	return 0;
}