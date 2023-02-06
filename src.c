#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
 	char studentID[9]; 
	char name[30]; 
	char surname[30];
	int point; 
	struct Student *next; 
	struct Student *prev;
};
struct Author{
	int authorID;
	char authorName[30]; 
	char authorSur[30]; 
	struct Author *next;
};
struct Copy{
	char labelNo[20]; 
	char status[9]; 
	struct Copy *next;
};
struct Book{
	char bookName[30];
	char ISBN[14];
	int number;
	struct Book *next; 
	struct Copy *head;
};
struct BookAuthor{
	char ISBN[13];
	int authorID;
};
struct Date{
	unsigned int day:5;
	unsigned int month:4;
	unsigned int year:12;
};
struct BorrowRecord{
	char labelNo[20]; 
	char studentID[9]; 
	unsigned int proType:1; 
	struct Date proDate;
};

typedef struct Student student;
typedef struct Author author;
typedef struct Copy copy;
typedef struct Book book;
typedef struct BookAuthor bookAuthor;
typedef struct Date date;
typedef struct BorrowRecord borrowRecord;

void studentUpdateFile(student*);
void studentGetData(student **);
void enrollStudent(student **);
void deleteStudent(student**);
void updateStudent(student**);
void studentList(student *);
void studentFree(student **);
int checkStudent(char *);
void punishedStudentList(student*);
void borrowers(book *);
void studentInfo(student *,borrowRecord*,int *);
void borrowBook(borrowRecord **,int *,book**,student**);
void returnBook(borrowRecord **,int *,student**,book **);
int checkPenalty(borrowRecord*,borrowRecord,int,student**);
int dateCheck(date,date);

int authorGetData(author **);
void addAuthor(author **);
void deleteAuthor(author**,bookAuthor**,int);
void updateAuthor(author**);
void authorList(author *);
int checkAuthor(author*,int);
void authorInfo(author *,book *);
void updateBookAuthor(bookAuthor **,int);
void authorFree(author **);

void bookFileUpdate(book *head);
void bookGetInfo(book **);
void addBook(book **);
void deleteBook(book**,bookAuthor**,int*);
void updateBook(book**,bookAuthor**,int*);
void bookList(book*);
void isbn(char**);
void returnWithPenalty(borrowRecord *,int);
int checkBook(book *,char*);
char* copyStatus(char*);
void bookFree(book **);
void booksOnShelf(book*);

void bookAuthorGetData(bookAuthor **,author*,book*,int*);
void bookAuthorUpdateFile(bookAuthor *,int);
void bookAuthorPair(bookAuthor**,int *,book *,author*);

void copyGetInfo(copy **,char *,int);
void borrowRecordGetInfo(borrowRecord **,int *);
void borrowRecordUpdateData(borrowRecord *,int);

int main(){
	int choice,innerChoice,exit=1,innerExit;

	student * studentHead = NULL;
	int studentCount = 0;
	studentGetData(&studentHead);
	
	author *authorHead =NULL;
	int authorCount=0;
	authorGetData(&authorHead);
	
	book *bookHead =NULL;
	int bookCount=0;
	bookGetInfo(&bookHead);

	bookAuthor *bookAuthorArr = NULL;
	int bookInt = 0;
	int *bookAuthorCount = &bookInt;
	bookAuthorGetData(&bookAuthorArr,authorHead,bookHead,bookAuthorCount);

	borrowRecord *borrowArr = NULL;
	int borrowInt = 0;
	int *borrowCount = &borrowInt;
	borrowRecordGetInfo(&borrowArr,borrowCount);
	

	while(exit){
		
		printf("\n---------------------------\n");
		printf("| 1 Student transactions  |\n| 2 Book transactions     |\n| 3 Author transactions   |\n| 0 Exit                  |\n");
		printf("---------------------------\n");
		printf("Choice = ");
		scanf("%d",&choice);
		printf("\n");
		switch (choice){
			case 0:
				exit = 0;
				break;
			case 1:
				innerExit = 1;
				while (innerExit){
					printf("\n-------Student transactions-------\n");
					printf("| 1 Enroll student               |\n| 2 Delete student               |\n| 3 Update student               |\n| 4 Student list                 |\n| 5 Borrow book                  |\n| 6 Return book                  |\n| 7 Punished students list       |\n| 8 Borrower students list       |\n| 9 Get student information      |\n| 0 Main menu                    |\n");
					printf("----------------------------------\n");
					printf("Choice = ");
					scanf("%d",&innerChoice);
					printf("\n");
					switch (innerChoice){
						case 0:
							innerExit = 0;
							break;
						case 1:
							enrollStudent(&studentHead);
							studentCount++;
							break;
						case 2:
							deleteStudent(&studentHead);
							studentCount--;
							break;
						case 3:
							updateStudent(&studentHead);
							break;
						case 4:
							studentList(studentHead);
							break;
						case 5:
							borrowBook(&borrowArr,borrowCount,&bookHead,&studentHead);
							break;
						case 6:
							returnBook(&borrowArr,borrowCount,&studentHead,&bookHead);
							break;
						case 7:
							punishedStudentList(studentHead);
							break;
						case 8:
							borrowers(bookHead);
							break;
						case 9:
							studentInfo(studentHead,borrowArr,borrowCount);
							break;
						default:
							printf("Input a valid number\n");
							break;
						}
					printf("\n");
				}
				break;
			case 2:
				innerExit = 1;
				while (innerExit){
					printf("\n---------Book transactions---------\n");
					printf("| 1 Add book                      |\n| 2 Delete book                   |\n| 3 Update book                   |\n| 4 Book list                     |\n| 5 Return with penalty           |\n| 6 Updade book author            |\n| 7 Pair book author              |\n| 8 Books on shelf                |\n| 0 Main menu                     |\n");
					printf("-----------------------------------\n");
					printf("Choice = ");
					scanf("%d",&innerChoice);
					printf("\n");
					switch (innerChoice){
						case 0:
							innerExit = 0;
							break;
						case 1:
							addBook(&bookHead);
							bookCount++;
							break;
						case 2:
							deleteBook(&bookHead,&bookAuthorArr,bookAuthorCount);
							bookCount--;
							break;
						case 3:
							updateBook(&bookHead,&bookAuthorArr,bookAuthorCount);
							break;
						case 4:
							bookList(bookHead);
							break;
						case 5:
							returnWithPenalty(borrowArr,(*borrowCount));
							break;
						case 6:
							updateBookAuthor(&bookAuthorArr,(*bookAuthorCount));
							break;
						case 7:
							bookAuthorPair(&bookAuthorArr,bookAuthorCount,bookHead,authorHead);
							break;
						case 8:
							booksOnShelf(bookHead);
							break;
						default:
							printf("Input a valid number\n");
							break;
						}
						printf("\n");
					}
				break;
			case 3:	
				innerExit = 1;
				while (innerExit){
					printf("\n-----Author transactions-----\n");
					printf("| 1 Add author              |\n| 2 Delete author           |\n| 3 Update author           |\n| 4 Author list             |\n| 5 Get author information  |\n| 0 Main menu               |\n");
					printf("-----------------------------\n");
					printf("Choice = ");
					scanf("%d",&innerChoice);
					printf("\n");
					switch (innerChoice){
						case 0:
							innerExit= 0;
							break;
						case 1:
							addAuthor(&authorHead);
							authorCount++;
							break;
						case 2:
							deleteAuthor(&authorHead,&bookAuthorArr,(*bookAuthorCount));
							authorCount--;
							break;
						case 3:
							updateAuthor(&authorHead);
							break;
						case 4:
							authorList(authorHead);
							break;
						case 5:
							authorInfo(authorHead,bookHead);
							break;
						default:
							printf("Input a valid number\n");
							break;
					}
					printf("\n");
				}
				break;
			default:
				printf("Input a valid number\n");
				break;
		}
	}
	studentFree(&studentHead);
	bookFree(&bookHead);
	authorFree(&authorHead);
	free(bookAuthorArr);
	free(borrowArr);
	return 0;
}

void studentUpdateFile(student *head){
	FILE *fp = fopen("Students.csv","w");
	while(head!=NULL){
		fprintf(fp,"%s,%s,%s,%d\n",head->studentID,head->name,head->surname,head->point);
		head=head->next;
	}
	fclose(fp);
}

void studentGetData(student **ptr){
	FILE *fp =fopen("Students.csv","r");
	char buffer[sizeof(student)],*token;
	student *first=NULL;
	student *head =NULL;
	student *newStudent=NULL;
	if(fp==NULL){
		fclose(fp);
		(*ptr)==NULL;
		return;
	} 
	else{
		while(fgets(buffer,sizeof(student),fp)!=NULL){
			newStudent=(student*)malloc(sizeof(student));
			token=strtok(buffer,",");
			strcpy(newStudent->studentID,token);
			token=strtok(NULL,",");
			strcpy(newStudent->name,token);
			token=strtok(NULL,",");
			strcpy(newStudent->surname,token);
			token=strtok(NULL,",");
			newStudent->point=atoi(token);
			newStudent->next=NULL;
			if(first==NULL){
				newStudent->prev=NULL;
				first=newStudent;
				head=newStudent;
			}
			else{
				newStudent->prev=head;
				head->next=newStudent;
				head=head->next;
			}
		}
	}
	(*ptr)=first;
	fclose(fp);
}

void enrollStudent(student **ptr){
	student *head = (*ptr);
	student *newStudent = (student*)malloc(sizeof(student));
	
	printf("Give ID of the student = ");
	scanf("%s",newStudent->studentID);
	printf("Give name of the student = ");
	scanf(" %[^\n]%*c",newStudent->name);
	printf("Give surname of the student = ");
	scanf("%s",newStudent->surname);
	newStudent->next=NULL;
	newStudent->point=100;
	if((*ptr)==NULL){
		newStudent->prev=NULL;
		(*ptr)=newStudent;
	}
	else{
		while(head->next!=NULL){
			head=head->next;
		}
		newStudent->prev=head;
		head->next=newStudent;
	}
	printf("Transaction successful\n");
	studentUpdateFile((*ptr));
}

void deleteStudent(student **ptr){
	char ID[8];
	int found = 0;
	if((*ptr)==NULL){
		printf("There is no student record\n");
		return;
	}

	printf("Give ID of the student = ");
	scanf("%s",&ID);
	student *head = (*ptr);

	while (!found && head!=NULL){
		if(strcmp(head->studentID,ID)==0){
			found = 1;
			student *first = head->prev;
			student *second = head->next;
			if(first==NULL&&second==NULL){
				(*ptr)=NULL;
				printf("All records are deleted!\n");
			}
			else if(first==NULL){
				(*ptr) = (*ptr)->next;
				(*ptr)->prev =NULL;
			}
			else if(second==NULL){
				first->next = NULL;
			}
			else{
				second->prev = head->prev;
				first->next = head->next;
			}
			head = NULL;
			free(head);
			studentUpdateFile((*ptr));
			printf("Transaction successful\n");
			return;
		}
		head = head->next;
	}
	printf("ID didn't match!\n");
}

void updateStudent(student **ptr){
	char ID[8];
	int succces = 0;

	printf("Give ID of the student that will update = ");
	scanf("%s",&ID);
	
	student *head = (*ptr);

	while (!succces && head!=NULL){
		if(strcmp(head->studentID,ID)==0){
			succces = 1;
			printf("Give new ID of the student = ");
			scanf("%s",head->studentID);
			printf("Give new name of the student = ");
			scanf(" %[^\n]%*c",head->name);
			printf("Give new surname of the student = ");
			scanf(" %[^\n]%*c",head->surname);
			printf("Give new point of the student = ");
			scanf("%d",&head->point);
			studentUpdateFile((*ptr));
			printf("Transaction successful\n");
			return;
		}
		head = head->next;
	}
	printf("ID didn't match!\n");
}

void studentInfo(student *head,borrowRecord*arr,int *count){
	int choice;
	char id[9];
	char name[30];
	char surname[30];
	int i,flag=0;
	printf("\nID ->1\nName-Surname ->2\nWhich information you have about student? = ");
	scanf("%d",&choice);
	if(choice==1){
		printf("Give ID of the student = ");
		scanf("%s",id);
		while (head!=NULL){
			if(strcmp(head->studentID,id)==0){
				printf("\n----------------------------------------------------------------\n\n");
				printf("%s %s %s %d :\n\n",head->studentID,head->name,head->surname,head->point);
				flag = 1;
			}
			head = head->next;
		}
	}
	else if(choice==2){
		printf("Give name of the student = ");
		scanf(" %[^\n]%*c",name);
		printf("Give surname of the student = ");
		scanf(" %s",surname);
		while (head!=NULL){
			if(strcmp(head->name,name)==0&&strcmp(head->surname,surname)==0){
				printf("\n----------------------------------------------------------------\n\n");
				printf("%s %s %s %d :\n\n",head->studentID,head->name,head->surname,head->point);
				strcpy(id,head->studentID);
				flag = 1;
			}
			head = head->next;
		}
	}
	else printf("Input a valid number\n");
	for(i=0;i<(*count);i++){
		if(strcmp(arr[i].studentID,id)==0){
			if(arr[i].proType==0){
				printf("%s is the label number that student borrowed at %u.%u.%u\n",arr[i].labelNo,arr[i].proDate.day,arr[i].proDate.month,arr[i].proDate.year);
			}
			else printf("%s is the label number that student borrowed at %u.%u.%u\n",arr[i].labelNo,arr[i].proDate.day,arr[i].proDate.month,arr[i].proDate.year);
		}
	}
	printf("\n----------------------------------------------------------------\n\n");

	if(flag==0) printf("ID didn't match!\n");
}

void studentList(student *ptr){
	printf("\n-----------Student List-----------\n\n");
	while(ptr!=NULL){
		printf("%s %s %s %d\n",ptr->studentID,ptr->name,ptr->surname,ptr->point);
		ptr=ptr->next;
	}
	printf("\n----------------------------------\n\n");
}

void studentFree(student **ptr){
	student *tmp=NULL;
	while((*ptr)!=NULL){
		tmp=(*ptr);
		(*ptr)=(*ptr)->next;
		free(tmp);
	}
	free((*ptr));
}

int checkStudent(char *ID){
	student newStudent;
	FILE *fp = fopen("Students.csv","r");
	char id[9],name[30],surname[30];
	int point;
	while(!feof(fp)){
		fscanf(fp,"%[^,],%[^,],%[^,],%d\n",id,name,surname,&point);
		if(strcmp(ID,id)==0){
			return 1;
		}
	}
	return 0;
}

void borrowers(book *ptr){
	copy *tail;
	printf("\n------------------Borrower list------------------\n\n");
	while(ptr!=NULL){
		tail = ptr->head;
		while(tail!=NULL){
			if(strcmp(tail->status,"SHELF")!=0){
				printf("Student ID:%s  Book:%s \n",tail->status,tail->labelNo);
			}
			tail = tail->next;
		}
		ptr = ptr->next;
	}
	printf("\n--------------------------------------------------\n");
}

int dateCheck(date begin, date finish){
	int result=0;
	result = (finish.year-begin.year)*360;
	result += (finish.month-begin.month)*30;
	result += (finish.day-begin.day);
	return result;
}

int checkPenalty(borrowRecord *arr,borrowRecord newRecord,int count,student **ptr){
	int i,flag=0;
	student *head = (*ptr);
	while(head!=NULL){
		if(strcmp(head->studentID,newRecord.studentID)==0){
			if(head->point<1) return -1;
		}
		head = head->next;
	}
	for(i=0;i<count;i++){
		if(strcmp(arr[i].labelNo,newRecord.labelNo)==0&&strcmp(arr[i].studentID,newRecord.studentID)==0&&arr[i].proType==0){
			if(dateCheck(arr[i].proDate,newRecord.proDate)>15){
				flag = 1;
			}
		}
	}
	head = (*ptr);
	if(flag==1){
		while(head!=NULL){
			if(strcmp(head->studentID,newRecord.studentID)==0){
				head->point-=10;
			}
			head = head->next;
		}
	}
	studentUpdateFile((*ptr));
	return 0;
}

void borrowBook(borrowRecord **ptr,int *count,book **bookHead,student **studentHead){
	char isbn[15]=" ";
	int flag =1;
	unsigned int g,a,y;
	borrowRecord newRecord;
	book *head = (*bookHead);
	copy *tail=NULL;
	
	printf("Give the label number of the book = ");
	scanf("%s",newRecord.labelNo);
	strncpy(isbn,newRecord.labelNo,13);	
	if(checkBook(head,isbn)==0){
		printf("This book doesn't exist\n");
	}
	else{
		printf("Give ID of the student that will borrow = ");
		scanf("%s",newRecord.studentID);
		if(checkStudent(newRecord.studentID)==0){
			printf("ID didn't match!\n");
		}
		else if(checkPenalty((*ptr),newRecord,(*count),studentHead)==-1){
			printf("Student's point is 0\n");
		}
		else {
			newRecord.proType=0;
			printf("Borrow date (day.month.year) = ");
			fscanf(stdin,"%u.%u.%u",&g,&a,&y);
			newRecord.proDate.day = g;
			newRecord.proDate.month  = a;
			newRecord.proDate.year = y;
			
			while(head!=NULL){
				if(strncmp(head->ISBN,newRecord.labelNo,13)==0){
					tail = head->head;
					while(tail!=NULL){
						if(strcmp(tail->labelNo,newRecord.labelNo)==0){
							if(strcmp(tail->status,"SHELF")==0){
								flag = 1;
								strcpy(tail->status,newRecord.studentID);
								printf("Transaction successful\n");
							}
							else{
								printf("The book has borrowed by another student. Check the student ID!\n");
							}
						}
						tail = tail->next;
					}
				}
				head =head->next;
			}
			if(flag==1){
				(*count)++;
				if((*count)==1){
					(*ptr) = (borrowRecord*)malloc(sizeof(borrowRecord)); 
					(*ptr)[(*count)-1]=newRecord;
				}
				else{
					(*ptr) = (borrowRecord*)realloc((*ptr),sizeof(borrowRecord)*(*count));
					(*ptr)[(*count)-1]=newRecord;
				}
				borrowRecordUpdateData((*ptr),(*count));
			}
		}
	}
}

void returnBook(borrowRecord **ptr,int *count,student **ogrHead,book **bookHead){
	char isbn[15]=" ";
	unsigned int g,a,y;
	int flag =0;
	borrowRecord newRecord;
	book *head = (*bookHead);
	copy *tail=NULL;
	
	printf("Give the label number of the book = ");
	scanf("%s",newRecord.labelNo);
	strncpy(isbn,newRecord.labelNo,13);
	if(checkBook(head,isbn)==0){
		printf("This book doesn't exist");
	}
	else{
		printf("Give ID of the student that will return = ");
		scanf("%s",newRecord.studentID);
		if(checkStudent(newRecord.studentID)==0){
			printf("ID didn't match!");
		}
		else{
			newRecord.proType=1;
			printf("Return date (day.month.year) = ");
			fscanf(stdin,"%u.%u.%u",&g,&a,&y);
			newRecord.proDate.day = g;
			newRecord.proDate.month  = a;
			newRecord.proDate.year = y;
			
			checkPenalty((*ptr),newRecord,(*count),ogrHead);
			while(head!=NULL){
				if(strncmp(head->ISBN,newRecord.labelNo,13)==0){
					tail = head->head;
					while(tail!=NULL){
						if(strcmp(tail->labelNo,newRecord.labelNo)==0){
							if(strcmp(tail->status,newRecord.studentID)==0){
								flag = 1;
								strcpy(tail->status,"SHELF");
								printf("Transaction successful\n");							
							}
							else{
								printf("The book has returned by student. Check the student ID!\n");
							}
						}
						tail = tail->next;
					}
				}
				head =head->next;
			}
			if(flag ==1){
				(*count)++;
				if((*count)==1){
					(*ptr) = (borrowRecord*)malloc(sizeof(borrowRecord)); 
					(*ptr)[(*count)-1]=newRecord;
				}
				else{
					(*ptr) = (borrowRecord*)realloc((*ptr),sizeof(borrowRecord)*(*count));
					(*ptr)[(*count)-1]=newRecord;
				}
				borrowRecordUpdateData((*ptr),(*count));
			}
		}
	}
}

void punishedStudentList(student*ptr){
	printf("\n----------Punished student list----------\n\n");
	while (ptr!=NULL){
		if(ptr->point<100){
			printf("%s %s %s %d\n",ptr->studentID,ptr->name,ptr->surname,ptr->point);
		}
		ptr = ptr->next;
	}
	printf("\n-------------------------------------------\n");
}

void authorFileUpdate(author *head){
	FILE *fp = fopen("Authors.csv","w");
	while(head!=NULL){
		fprintf(fp,"%d,%s,%s\n",head->authorID,head->authorName,head->authorSur);
		head=head->next;
	}
	fclose(fp);
}

int authorGetData(author **ptr){
	FILE *fp =fopen("Authors.csv","r");
	char buffer[sizeof(author)],*token;
	author *first=NULL;
	author *head=NULL;
	author *newAuthor=NULL;
	if(fp==NULL){
		fclose(fp);
		(*ptr)==NULL;
		return 0;
	}
	else{
		while(fgets(buffer,sizeof(author),fp)!=NULL){
			newAuthor=(author*)malloc(sizeof(author));
			token=strtok(buffer,",");
			newAuthor->authorID=atoi(token);
			token=strtok(NULL,",");
			strcpy(newAuthor->authorName,token);
			token=strtok(NULL,",");
			token[strlen(token)-1]='\0';
			strcpy(newAuthor->authorSur,token);
			newAuthor->next=NULL;
			if(first==NULL){
				first=newAuthor;
				head=newAuthor;
			}
			else{
				head->next=newAuthor;
				head=head->next;
			}
		}
	}
	(*ptr)=first;
	fclose(fp);
	return newAuthor->authorID;
	
}

void addAuthor(author **ptr){
	int count = authorGetData(ptr);
	author *head = (*ptr);
	author *newAuthor = (author*)malloc(sizeof(author));

	printf("Give the name of the author that you want to add = ");
	scanf(" %[^\n]%*c",newAuthor->authorName);
	printf("Give the surname of the author that you want to add  = ");
	scanf("%s",newAuthor->authorSur);
	newAuthor->next = NULL;
	newAuthor->authorID = (count+1);
	if((*ptr)==NULL){
		(*ptr)=newAuthor;
	}
	else{
		while(head->next!=NULL){
			head=head->next;
		}
		head->next = newAuthor;
	}
	printf("Transaction successful\n");
	authorFileUpdate((*ptr));
}

void deleteAuthor(author**ptr,bookAuthor**arr,int count){
	int num =authorGetData(ptr);
	int found=0;
	int ID,i;
	if((*ptr)==NULL){
		printf("There is no author record\n");
		return;
	}
	author *head = (*ptr);
	author *first = head->next;
	printf("Give the ID of the author that you want to delete = ");
	scanf("%d",&ID);
	if(head->authorID==ID){
		found = 1;
		(*ptr)=(*ptr)->next;
	}
	else{
		while(first!=NULL && !found){
			if(first->authorID==ID){
				found = 1;
				if(first->next==NULL){
					head->next=NULL;
				}
				else{
					head->next=first->next;
					first->next=first->next->next;
				}
			}
			head = head->next;
			first = first->next;
		}
	}
	if(!found) printf("ID didn't match\n");
	else{
		printf("Transaction successful\n");
		authorFileUpdate((*ptr));
		for(i=0;i<count;i++){
			if(ID==(*arr)[i].authorID){
				(*arr)[i].authorID=-1;
			}
		}
		bookAuthorUpdateFile((*arr),count);
	}
	
}

int checkAuthor(author*ptr,int ID){
	if(ptr==NULL){
		printf("There is no author record\n");
		return 0;
	}
	
	while(ptr!=NULL){
		if(ptr->authorID==ID) return 1;
		ptr=ptr->next;
	}
	return 0;	
}

void updateAuthor(author **ptr){
	int ID;
	int succces = 0;

	printf("Give the ID of the author that you want to update = ");
	scanf("%d",&ID);
	
	author *head = (*ptr);
	while (!succces && head!=NULL){
		if(head->authorID==ID){
			succces = 1;
			printf("Give the new name of the author = ");
			scanf(" %[^\n]%*c",head->authorName);
			printf("Give the new surname of the author = ");
			scanf(" %[^\n]%*c",head->authorSur);
			authorFileUpdate((*ptr));
			printf("Transaction successful\n");
			return;
		}
		head = head->next;
	}
	printf("ID didn't match!\n");
}

void authorList(author *ptr){
	printf("\n---------Author list---------\n\n");
	while(ptr!=NULL){
		printf("%d %s %s\n",ptr->authorID,ptr->authorName,ptr->authorSur);
		ptr=ptr->next;
	}
	printf("\n-----------------------------\n\n");
}

void bookFileUpdate(book *head){
	FILE *fp = fopen("Books.csv","w");
	while(head!=NULL){
		fprintf(fp,"%s,%s,%d\n",head->bookName,head->ISBN,head->number);
		head=head->next;
	}
	fclose(fp);
}

void copyGetInfo(copy **ptr,char *isbn,int count){
	int i;
	char tmp[3];
	char postfix[10];
	char label[15];
	char *status;
	copy *head = (*ptr);
	
	for(i=1;i<=count;i++){
		copy *newCopy= (copy*)malloc(sizeof(copy));
		newCopy->next = NULL;
		itoa(i,tmp,10);
		strcpy(postfix,"_");
		strcat(postfix,tmp);
		strcpy(label,isbn);
		strcat(label,postfix);
		strcpy(newCopy->labelNo,label);
		status=copyStatus(newCopy->labelNo);
		strcpy(newCopy->status,status);
		
		if((*ptr)==NULL){
			(*ptr)=newCopy;
			head = newCopy;
		}
		else{
			head->next = newCopy;
			head = head->next;
		}
	}
}

char* copyStatus(char* label){
	FILE *fp = fopen("BorrowRecord.csv","r");
	char label1[20];
	char id[9];
	char status[15]="SHELF";
	char *p = status;
	unsigned int pro,b,c,d;
	while(!feof(fp)){
		fscanf(fp,"%[^,],%[^,],%u,%u.%u.%u\n",label1,id,&pro,&b,&c,&d);
		if(strcmp(label1,label)==0){
			if(pro==0) strcpy(status,id);
			else strcpy(status,"SHELF");
		}
	}
	fclose(fp);
	return p;
} 

void bookGetInfo(book **ptr){
	FILE *fp =fopen("Books.csv","r");
	char buffer[sizeof(book)],*token,*tmp;
	book *first=NULL;
	book *head=NULL;
	book *newBook=NULL;
	if(fp==NULL){
		fclose(fp);
		(*ptr)==NULL;
		printf("There is no book record\n");
		return;
	}
	else{
		while(fgets(buffer,sizeof(book),fp)!=NULL){
			newBook=(book*)malloc(sizeof(book));
			token=strtok(buffer,",");
			strcpy(newBook->bookName,token);
			token=strtok(NULL,",");
			strcpy(newBook->ISBN,token);
			token=strtok(NULL,",");
			newBook->number = atoi(token);
			newBook->next=NULL;
			newBook->head=NULL;
			copyGetInfo((&(newBook->head)),newBook->ISBN,newBook->number);
			if(first==NULL){
				first=newBook;
				head=newBook;
			}
			else{
				head->next=newBook;
				head=head->next;
			}
		}
	}
	(*ptr)=first;
	fclose(fp);
}

void addBook(book **ptr){
	int found,ID,flag=0,i;
	char str[30];
	book *head = (*ptr);
	book *newBook = (book*)malloc(sizeof(book));
	printf("Give the name of the book that you want to add= ");
	scanf(" %[^\n]%*c",newBook->bookName);
	printf("Give the ISBN of the book that you want to add= ");
	scanf("%s",newBook->ISBN);
	if(checkBook(head,newBook->ISBN)==0){
		newBook->next=NULL;
		newBook->head =NULL;
		printf("Give the number of copies = ");
		scanf("%d",&newBook->number);
		if((*ptr)==NULL){
			(*ptr)=newBook;
		}
		else{
			while(head->next!=NULL){
				head=head->next;
			}
			head->next = newBook;
		}
		flag=1;
		printf("Transaction successful\n");
	}
	else{
		printf("This book already added!\n");
	}
	bookFileUpdate((*ptr));
}

void deleteBook(book**ptr,bookAuthor **arr,int *count){
	int found=0,i,j;
	char ISBN[13];
	if((*ptr)==NULL){
		printf("There is no book record\n");
		return;
	}
	book *head = (*ptr);
	book *first = head->next;
	
	printf("Give the ISBN of the book that you want to delete = ");
	scanf("%s",&ISBN);
	
	if(strcmp(head->ISBN,ISBN)==0){
		found = 1;
		(*ptr)=(*ptr)->next;
	}
	else{
		while(first!=NULL && !found){
			if(strcmp(first->ISBN,ISBN)==0){
				found = 1;
				if(first->next==NULL){
					head->next=NULL;
				}
				else{
					free(head->next);
					head->next=first->next;
					first->next=first->next->next;
				}
			}
			head = head->next;
			first = first->next; 
		}
	}

	if(found==0) printf("ISBN didn't match");
	else{
		for(i=0;i<(*count);i++){
			if(strcmp((*arr)[i].ISBN,ISBN)==0){
				for(j=i;j<(*count)-1;j++){
					(*arr)[j] = (*arr)[j+1];
				}
				(*count)--;
				i--;
			}
		}
		bookAuthorUpdateFile((*arr),(*count));
		bookFileUpdate((*ptr));
		printf("Transaction successful\n");
	}
}

void updateBook(book**ptr,bookAuthor **arr,int *count){
	char ISBN[13],ISBN2[13];
	int succces = 0,i;
	copy *tmp=NULL;
	book *head = (*ptr);
	
	printf("Give the ISBN of the book that you want to update = ");
	scanf("%s",ISBN);
	
	while (!succces && head!=NULL){
		if(strcmp(head->ISBN,ISBN)==0){
			succces = 1;
			printf("Give the new name of the book = ");
			scanf(" %[^\n]%*c",head->bookName);
			printf("Give the new ISBN of the book= ");
			scanf("%s",head->ISBN);
			strcpy(ISBN2,head->ISBN);
			printf("Give the new number of copies the book = ");
			scanf("%d",&head->number);
			tmp = head->head;
			while(tmp!=NULL){
				strncpy(tmp->labelNo,head->ISBN,13);
				tmp = tmp->next;
			}
			bookFileUpdate((*ptr));
		}
		head = head->next;
	}

	if(succces==0) printf("ID didn't match!\n");
	else{
		for(i=0;i<(*count);i++){
			if(strcmp((*arr)[i].ISBN,ISBN)==0){
				printf("%s",ISBN2);
				strcpy((*arr)[i].ISBN,ISBN2);
				printf("%s",(*arr)[i].ISBN);
			}
		}
		bookAuthorUpdateFile((*arr),(*count));
		printf("Transaction successful\n");	}

}

void bookList(book* ptr){
	bookGetInfo(&ptr);
	copy *tmp=NULL;
	printf("\n-------------------Book list-------------------\n\n");
	while(ptr!=NULL){
		printf("%s %s %d -->\n",ptr->bookName,ptr->ISBN,ptr->number);
		tmp=ptr->head;
		while (tmp!=NULL){
			printf("\t\t\t%s %s\n",tmp->labelNo,tmp->status);
			tmp=tmp->next;
		}
		printf("\n");
		ptr=ptr->next;
	}
	printf("\n-----------------------------------------------\n\n");
}

int checkBook(book *head,char *isbn){
	while(head!=NULL){
		if(strcmp(head->ISBN,isbn)==0){
			return 1;
		}
		head = head->next;
	}
	return 0;
}

void bookAuthorGetData(bookAuthor **ptr,author *ptr1,book *ptr2,int *count){
	FILE *fp =fopen("BookAuthor.csv","r");
	char buffer[sizeof(bookAuthor)],*token;
	bookAuthor newBook;
	if(fp==NULL){
		fclose(fp);
		(*ptr)==NULL;
		printf("There is no BookAuthor record\n");
		return;
	}
	else{
		while(fgets(buffer,sizeof(bookAuthor),fp)!=NULL){
			(*count)++;
			token=strtok(buffer,",");
			strcpy(newBook.ISBN,token);
			token=strtok(NULL,",");
			newBook.authorID = atoi(token);
			if(checkBook(ptr2,newBook.ISBN)!=0){
				if(checkAuthor(ptr1,newBook.authorID)==0){
					newBook.authorID=-1;
				}
				if((*count)==1){
					(*ptr) = (bookAuthor*)malloc(sizeof(bookAuthor)); 
					(*ptr)[(*count)-1]=newBook;
				}
				else{
					(*ptr) = (bookAuthor*)realloc((*ptr),sizeof(bookAuthor)*(*count));
					(*ptr)[(*count)-1]=newBook;
				}
			}
		}
	}
	bookAuthorUpdateFile((*ptr),(*count));
	fclose(fp);
}

void bookAuthorUpdateFile(bookAuthor *ptr,int len){
	int i;
	FILE *fp = fopen("BookAuthor.csv","w");
	for(i=0;i<len;i++){
		fprintf(fp,"%s,%d\n",ptr[i].ISBN,ptr[i].authorID);
	}
	fclose(fp);
}

void borrowRecordUpdateData(borrowRecord *ptr,int count){
	int i;
	FILE *fp = fopen("BorrowRecord.csv","w");
	for(i=0;i<count;i++){
		fprintf(fp,"%s,%s,%u,%u.%u.%u\n",ptr[i].labelNo, ptr[i].studentID, ptr[i].proType, ptr[i].proDate.day, ptr[i].proDate.month, ptr[i].proDate.year);
	}
	fclose(fp);
}

void borrowRecordGetInfo(borrowRecord **ptr,int *count){
	FILE *fp =fopen("BorrowRecord.csv","r");
	
	borrowRecord newRecord;
	char et[20];
	char id[9];
	unsigned int a,b,c,d;
	
	if(fp==NULL){
		fclose(fp);
		(*ptr)==NULL;
		printf("There is no BookAuthor record\n");
		return;
	}
	else{
		while(!feof(fp)){
			(*count)++;
			fscanf(fp,"%[^,],%[^,],%d,%u.%u.%u\n",et,id,&a,&b,&c,&d);
			strcpy(newRecord.labelNo,et);
			strcpy(newRecord.studentID,id);
			newRecord.proType = a;
			newRecord.proDate.day = b;
			newRecord.proDate.month = c;
			newRecord.proDate.year = d;
			if((*count)==1){
				(*ptr) = (borrowRecord*)malloc(sizeof(borrowRecord)); 
				(*ptr)[(*count)-1]=newRecord;
			}
			else{
				(*ptr) = (borrowRecord*)realloc((*ptr),sizeof(borrowRecord)*(*count));
				(*ptr)[(*count)-1]=newRecord;
			}
		}
	}
	borrowRecordUpdateData((*ptr),(*count));
	fclose(fp);
}

void returnWithPenalty(borrowRecord *arr,int count){
	int i,j;

	for(i=0;i<count-1;i++){
		if(arr[i].proType==0){
			for(j=i;j<count;j++){
				if(arr[j].proType==1&&strcmp(arr[i].labelNo,arr[j].labelNo)==0&&strcmp(arr[i].studentID,arr[j].studentID)==0){
					if(dateCheck(arr[i].proDate,arr[j].proDate)>15){
						printf("Book = %s Student = %s Borrow date = %u.%u.%u Return date = %u.%u.%u\n",arr[i].labelNo,arr[i].studentID,
						arr[i].proDate.day,arr[i].proDate.month,arr[i].proDate.year,arr[j].proDate.day,arr[j].proDate.month,arr[j].proDate.year);
					}
				}
			}
		}
	}
}

void authorInfo(author *authorHead,book *bookHead){
	char name[30],surname[30],ISBN[14];
	int flag=0,id,idFile;
	book *head=NULL;
	copy *tail=NULL;
	FILE *fp = fopen("BookAuthor.csv","r");
	printf("\nGive the name of the author that you want to see information = ");
	scanf(" %[^\n]%*c",name);
	printf("Give the name of the author that you want to see information = ");
	scanf(" %s",surname);
	printf("\n");
	while(authorHead!=NULL&&flag==0){
		if(strcmp(authorHead->authorName,name)==0&&strcmp(authorHead->authorSur,surname)==0){
			id = authorHead->authorID;
			flag = 1;
		}
		authorHead=authorHead->next;
	}
	flag = 0;
	if(fp==NULL){
		printf("There is no BookAuthor file\n");
	}
	else{
		while(!feof(fp)){
			fscanf(fp,"%[^,],%d\n",ISBN,&idFile);
			if(id==idFile){
				head = bookHead;
				while(head!=NULL){
					if(strcmp(head->ISBN,ISBN)==0){
						flag =1;
						tail = head->head;
						printf("%s %s %d -->\n",head->bookName,head->ISBN,head->number);
						while (tail!=NULL){
							printf("\t\t\t%s %s\n",tail->labelNo,tail->status);
							tail=tail->next;
						}
					}
					head = head->next;
				}
			}
		}
	}
	if(flag==0) printf("This author is doesn't exist\n");
	fclose(fp);
}

void updateBookAuthor(bookAuthor **arr,int count){
	char ISBN[14];
	int i,flag =0,ID,prevID;
	printf("Give the ISBN of the book that you want to update its author= ");
	scanf("%s",ISBN);
	printf("Give the old ID = ");
	scanf("%d",&prevID);
	printf("Give the new ID = ");
	scanf("%d",&ID);
	for(i=0;i<count;i++){
		if(strcmp((*arr)[i].ISBN,ISBN)==0&&(*arr)[i].authorID==prevID){
			flag = 1;
			(*arr)[i].authorID=ID;
		}
	}
	if(flag) printf("\nTransaction successful\n");
	else printf("\nOperation failed\n");
	bookAuthorUpdateFile((*arr),count);
}

void bookAuthorPair(bookAuthor**arr,int *count,book *ptr,author* ptr2){
	char ISBN[14];
	int ID,i;
	bookAuthor newBA;
	printf("Give the ISBN of the book that you want to pair with author= ");
	scanf("%s",newBA.ISBN);
	if(checkBook(ptr,newBA.ISBN)==0){
		printf("This book doesn't exist\n");
		return;
	}
	printf("Give the author ID = ");
	scanf("%d",&newBA.authorID);
	if(checkAuthor(ptr2,newBA.authorID)==0){
		printf("This author doesn't exist\n");
		return;
	}
	(*count)++;
	if((*count)==1){
		(*arr) = (bookAuthor*)malloc(sizeof(bookAuthor)); 
		(*arr)[(*count)-1]=newBA;
	}
	else{
		(*arr) = (bookAuthor*)realloc((*arr),sizeof(bookAuthor)*(*count));
		(*arr)[(*count)-1]=newBA;
	}
	bookAuthorUpdateFile((*arr),(*count));
	printf("Transaction successful\n");
}

void bookFree(book **ptr){
	book *tmp=NULL;
	while((*ptr)!=NULL){
		tmp=(*ptr);
		(*ptr)=(*ptr)->next;
		free(tmp);
	}
	free((*ptr));
}

void authorFree(author **ptr){
	author *tmp=NULL;
	while((*ptr)!=NULL){
		tmp=(*ptr);
		(*ptr)=(*ptr)->next;
		free(tmp);
	}
	free((*ptr));
}

void booksOnShelf(book* ptr){
	bookGetInfo(&ptr);
	copy *tmp=NULL;
	printf("\n------------------Books on shelf------------------\n\n");
	while(ptr!=NULL){
		tmp=ptr->head;
		while (tmp!=NULL){
			if(strcmp(tmp->status,"SHELF")==0) printf("%s\n",tmp->labelNo);
			tmp=tmp->next;
		}
		printf("\n");
		ptr=ptr->next;
	}
	printf("\n--------------------------------------------------\n\n");
}
