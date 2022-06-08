#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM 10

typedef struct student{
  char name[51];
  char matricNo[9];
  float testMarks;
  float finalMarks;
}student;

void getName(student studentArr[], int);
int validName(char name[]);
int repeatedName(student studentArr[], char name[], int);
void getMatricNo(student studentArr[], int);
int validMatricNo(char matricNo[]);
int repeatedMatricNo(student studentArr[], char MatricNo[], int);
void getTestMarks(student studentArr[], int);
void getFinalMarks(student studentArr[], int);
int validMark(char mark[]);
void listOfGoodPerformance(student studentArr[]);
void listOfPoorPerformance(student studentArr[]);
void sortedTestMarks(student studentArr[]);
void sortedFinalMarks(student studentArr[]);
int smallestTestMarkIndex(int, int, student studentArr[]);
int smallestFinalMarkIndex(int, int, student studentArr[]);
void change(student studentArr[], int, int);
void lower(char name[]);
void capitalized(char name[]);

int main() {
  student studentArr[NUM];
  for(int i = 0; i < NUM; i++){
    getName(studentArr, i);
    getMatricNo(studentArr, i);
    getTestMarks(studentArr, i);
    getFinalMarks(studentArr, i);
  }
  listOfGoodPerformance(studentArr);
  listOfPoorPerformance(studentArr);
  sortedTestMarks(studentArr);
  sortedFinalMarks(studentArr);
  return 0;
}

void getName(student studentArr[], int i){
  int result, repeat;
  do{
    printf("\nEnter the student %d name: ", i + 1);
    scanf("\n%[^\n]s", studentArr[i].name);
    result = validName(studentArr[i].name);
    lower(studentArr[i].name);
    capitalized(studentArr[i].name);
    repeat = repeatedName(studentArr, studentArr[i].name, i);
  }while(result == 0 || repeat == 1);
}

int validName(char name[]){
  if(strlen(name) < 3){
    printf("\nThe name shouldn't less than 3 characters, please input again.\n");
    return 0;
  }
  else if(strlen(name) > 50){
    printf("\nThe name shouldn't more than 50 characters, please input again.\n");
    return 0;
  }
  else if(name[strlen(name) - 1] == 32){
    printf("\nYou shouln't leave a space at the end of the name.\n");
    return 0;
  }
  else{
    lower(name);
    for(int j = 0; j < strlen(name); j++){
      if(name[j+1] == 32 && name[j] ==32){
        printf("\nYou shouldn't space more than once between words of the name.\n");
        return 0;
      }
      else if((name[j] < 97 || name[j] > 122) && name[j] != 32){
        printf("\nInvalid name, please input again.\n");
        return 0;
      }
      else if(j == strlen(name) - 1)
        return 1;
    }
  }
}

int repeatedName(student studentArr[], char name[], int num){
  for(int i = 0; i < num; i++){
    if(strcmp(studentArr[i].name, name) == 0){
      printf("\nThe student name is repeated.\n");
      return 1;
    }
  }
  return 0;
}

void getMatricNo(student studentArr[], int i){
  int result, repeat;
  do{
    printf("\nPlease enter No.matric: ");
    scanf("\n%[^\n]s", studentArr[i].matricNo);
    result = validMatricNo(studentArr[i].matricNo);
    repeat = repeatedMatricNo(studentArr, studentArr[i].matricNo, i);
  }while(repeat == 1 || result == 0);
}

int validMatricNo(char matricNo[]){
  for (int j = 0; j < 10; j++){
    matricNo[j] = toupper(matricNo[j]);
  }
  if (strlen(matricNo) < 8){
    printf("\n!!!Too Less!!!\n");
    return 0;
  }else if(strlen(matricNo) > 8){
    printf("\n!!!Too More(8-digit)!!!\n");
    return 0;
  }else if(matricNo[1] < 65 || matricNo[1] > 90 || matricNo[0] < 65 || matricNo[0] > 90){
  printf("\n!!!You enter a wrong no.matric.!!!\n");
  return 0;
  }else{
    for(int k = 2; k < 8; k++){
      if(matricNo[k] < 48 || matricNo[k] > 57){
        printf("\n!!!You enter a wrong no.matric.!!!\n");
        return 0;
      }else{
        return 1;
      }
    }
  }
}

int repeatedMatricNo(student studentArr[], char matricNo[], int num){
  for(int t = 0; t < num; t++){
    if(strcmp(studentArr[t].matricNo, matricNo) == 0){
      printf("\nThe Matric No is repeated.\n");
      return 1;
    }
  }
  return 0;
}

void getTestMarks(student studentArr[], int i){
  int result;
  float floatmarks;
	char marks[5];
	do{
      do{
        printf("\nPlease enter Test mark: ");
        scanf("\n%[^\n]s", marks);
        result = validMark(marks);
      }while(result == 0);
      floatmarks = atof(marks);
      if(floatmarks < 0 || floatmarks > 100){
        printf("\nInvalid mark.\n");
      }
	}while(floatmarks < 0 || floatmarks > 100);
  studentArr[i].testMarks = floatmarks;
}

void getFinalMarks(student studentArr[], int i){
	int result;
  float floatmarks;
	char marks[5];
	do{
        do{
        printf("\nPlease enter Final mark: ");
        scanf("\n%[^\n]s", marks);
        result = validMark(marks);
      }while(result == 0);
      floatmarks = atof(marks);
      if(floatmarks < 0 || floatmarks > 100){
        printf("\nInvalid mark.\n");
      }
	}while(floatmarks < 0 || floatmarks > 100);

  studentArr[i].finalMarks = floatmarks;
}

int validMark(char mark[]){
	int numberOfPeriod = 0;
  if(mark[0] == 46){
    printf("\nInvalid value, please input again.\n");
    return 0;
  }
  else if(mark[0] == 48){
    if(strlen(mark) == 1){
        return 1;
    }else if(mark[1] != 46){
      printf("\nInvalid value, please input again.\n");
      return 0;
    }
  }
  else if (mark[0] == 45){
    printf("\nThe mark should be a positive value.\n");
    return 0;
  }
  else if (mark[strlen(mark)-1] == 32){
    printf("\nYou shouldn't leave a space at the end of the mark.\n");
    return 0;
  }
  for(int i = 0; i < strlen(mark); i++){
    if(mark[i] == 46){
      numberOfPeriod++;
      if(mark[i + 3] <= 57 && mark[i + 3] >= 48){
        printf("\nThe marks should have only two decimal places.\n");
        return 0;
      }
    }
    else if(numberOfPeriod > 1){
      printf("\nInvalid value, please input again.\n");
      return 0;
    }
    else if((mark[i] < 48 || mark[i] > 57) && mark[i] != 46){
      printf("\nInvalid value, please input again.\n");
      return 0;
    }
    else if(i == strlen(mark) - 1){
      return 1;
    }
  }
}

void listOfGoodPerformance(student studentArr[]){
    int goodStudent = 0;
    int num = 1;
	printf("\n\nThe list of student with good performance:\n\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
  printf("| No |\t\t\t\tName\t\t\t\t| Matric No | Test Marks | Final Marks |\n");
  printf("--------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<NUM;i++){
		if(studentArr[i].testMarks>=80 && studentArr[i].finalMarks>=80){
			printf("|%3d | %-50s\t|  %s | %8.2f\t | %9.2f   |\n",num ,studentArr[i].name,studentArr[i].matricNo,studentArr[i].testMarks,studentArr[i].finalMarks);
			printf("--------------------------------------------------------------------------------------------------------\n");
			goodStudent = 1;
			num++;
		}
	}
	if(goodStudent == 0){
        printf("\nNo student.\n");
	}
}

void listOfPoorPerformance(student studentArr[]){
    int poorStudent = 0;
    int num = 1;
	printf("\n\nThe list of student with poor performance:\n\n");
	printf("--------------------------------------------------------------------------------------------------------\n");
  printf("| No |\t\t\t\tName\t\t\t\t| Matric No | Test Marks | Final Marks |\n");
  printf("--------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<NUM;i++){
		if(studentArr[i].testMarks<=50 && studentArr[i].finalMarks<=50){
			printf("|%3d | %-50s\t|  %s | %8.2f\t | %9.2f   |\n", num,studentArr[i].name,studentArr[i].matricNo,studentArr[i].testMarks,studentArr[i].finalMarks);
			printf("--------------------------------------------------------------------------------------------------------\n");
			poorStudent = 1;
			num++;
		}
	}
	if(poorStudent == 0){
        printf("\nNo student.\n");
	}
}

void sortedTestMarks(student studentArr[]){
  for(int i = 0; i < NUM - 1; i++){
      int j = smallestTestMarkIndex(i, NUM - 1, studentArr);
    if(i != j){
      change(studentArr, i, j);
    }
  }
  printf("\n\nSorted students' records with test marks in ascending:\n\n");
  printf("--------------------------------------------------------------------------------------------------------\n");
  printf("| No |\t\t\t\tName\t\t\t\t| Matric No | Test Marks | Final Marks |\n");
  printf("--------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<NUM;i++){
			printf("|%3d | %-50s\t|  %s | %8.2f\t | %9.2f   |\n",i + 1,studentArr[i].name,studentArr[i].matricNo,studentArr[i].testMarks,studentArr[i].finalMarks);
			printf("--------------------------------------------------------------------------------------------------------\n");
    }
}

void sortedFinalMarks(student studentArr[]){
	for(int i = 0; i < NUM - 1; i++){
      int j = smallestFinalMarkIndex(i, NUM - 1, studentArr);
    if(i != j){
      change(studentArr, i, j);
    }
  }
    printf("\n\nSorted students' records with final markss in ascending:\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| No |\t\t\t\tName\t\t\t\t| Matric No | Test Marks | Final Marks |\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<NUM;i++){
            printf("|%3d | %-50s\t|  %s | %8.2f\t | %9.2f   |\n",i + 1,studentArr[i].name,studentArr[i].matricNo,studentArr[i].testMarks,studentArr[i].finalMarks);
            printf("--------------------------------------------------------------------------------------------------------\n");
    }
}

int smallestTestMarkIndex(int begin, int end, student studentArr[]){
  int smallest = begin;
  for(int i = begin + 1; i <= end; i++){
    if(studentArr[i].testMarks < studentArr[smallest].testMarks){
      smallest = i;
    }
  }
  return smallest;
}

int smallestFinalMarkIndex(int begin, int end, student studentArr[]){
  int smallest = begin;
  for(int i = begin + 1; i <= end; i++){
    if(studentArr[i].finalMarks < studentArr[smallest].finalMarks){
      smallest = i;
    }
  }
  return smallest;
}

void change(student studentArr[], int i, int j){
  student temp = studentArr[i];
  studentArr[i] = studentArr[j];
  studentArr[j] = temp;
}

void lower(char name[]){
  for(int i = 0; i < strlen(name); i++){
    name[i] = tolower(name[i]);
  }
}

void capitalized(char name[]){
  while(name[0]==32){
    for(int i=0;i<strlen(name);i++){
      name[i]=name[i+1];
    }
  }
  name[0]= toupper(name[0]);
  for(int i=0;i<strlen(name);i++){
    if(name[i]==32){
      name[i+1]= toupper(name[i+1]);
    }
  }
}












