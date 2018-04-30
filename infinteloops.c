
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>


struct node{
	char data[38];
	int no_of_child;
	struct node *child_node[256];
};
char input_string[38];
struct node *root;
struct node *temp;
struct node *node1;
struct node *node2;

void clrscr(){
	printf("\n MYclrscr is not working sorry ----***\n");
}
void print(){
	clrscr();
	printf("\n------***TREE***-----\n");
	
}
struct node* allocate(){
	struct node *allocat;
	allocat= (struct node*) malloc(sizeof(struct node));
	return allocat;
}


int main(){
	int choice,str_len,i,copied=0,j,curr,loc=0;
	char ch,input_string[38];
	int found=0;
	
	root= allocate();
	temp=allocate();
	node1=allocate();
	node2=allocate();
	
	for(i=0;i<256;i++)
	root->child_node[i]=(struct node*)malloc(sizeof(struct node));
	
	//allocate memory to every nodes;
	/*root= (struct node*) malloc(sizeof(struct node));
	temp= (struct node*) malloc(sizeof(struct node));
	node1= (struct node*) malloc(sizeof(struct node));
	node2= (struct node*) malloc(sizeof(struct node));
	*/	
	//9334778884 haldi turmeric 
	
	while(1){
		print();
		printf("1 for Insertion\n2 for searching\n3Exit\nEnter Your Choice\n");
		scanf("%d",&choice);
		print();
		switch(choice){
			case 1: 
			printf("Enter the String Length\n");
			scanf("%d",&str_len);
			printf("Enter the String:\t");
			scanf("%s",input_string);//working
			print();
			curr=0;
			print();
			loc=(int) (input_string[curr]);//working
			temp=root->child_node[loc];
				if(temp->data[0]!=input_string[curr]){
				for(i=0;i<str_len;i++){
					temp->data[i]=input_string[curr];
					
					curr++;
				}
				print();
				printf("\n data have been inserted \n");
				for(i=0;i<str_len;i++){//to check whether data have been inserted or not
					printf("%c \t",temp->data[i]);
				}
				printf("\n");
				print();
				
			}//node empty case if ends
			else{ 
			copied=0;
			print();
				i=0;
				curr=0;
				while(str_len-copied){//correct entry 
					if(temp->data[i]==input_string[curr]){
						print();
						copied++;
						i++;
						curr++;
						
					}//if ends for same character coping
					else{
						node2= (struct node*) malloc(sizeof(struct node));
						node1= (struct node*) malloc(sizeof(struct node));
						loc=(int) temp->data[i];
						while(temp->data[i]!='\0'){
							node1->data[j]=temp->data[i];//copy the data into new node
							temp->data[i]='\0';//reassign NULL
							i++;
							j++;
							
						}
						temp->child_node[loc]=node1;
						loc=(int) input_string[curr];
						temp->child_node[loc]=node2;
						while(str_len-copied){
							node2->data[i]=input_string[curr];
							copied++;
							i++;
							curr++;
						}//new characters have been added to node2
						temp->child_node[loc]=node2;//copied the location
						
						
						
					}
					
				}
			}
				print();
				printf("\n****data Inserted****\n");
				
			break;
			
			
			
			
			case 2:
			print();
			printf("\n****search strted****\n");
			curr=0;
			i=0;
			found=0;
			printf("Enter the length of the String to be searched\n");
			scanf("%d",&str_len);
			printf("Enter the string to be searched\n");
			scanf("%s",input_string);
			loc=(int)input_string[curr];
			temp=root->child_node[loc];
			while(str_len!=found){
				if(temp->data[i]=='\0')
				{
					if(temp->data[0]=='\0'){
						printf("\n ***Not found***\nEnter a charcater now to come home\n");
						getch();
					break;
					}
					loc=(int)input_string[curr];
					temp=temp->child_node[loc];
				i=0;//index reset
				}
				if(temp->data[i]!=input_string[curr]){
					printf("\n not found enter a charcater now to come home\n");
					getch();
					break;
				}
				curr++;
				i++;
				found++;
					printf(" \t %d found\n",found);
			}
			if(found==str_len){
				printf("\nFOUND\n");
				break;
			}
			print();
			printf("seach completed\n");
			break;
			case 3: 
			print();
			printf("Exit Now");
			getch(); 
			exit(1);
			default:  print();
			}//switch ends
		}//while ends
return 1;
}
