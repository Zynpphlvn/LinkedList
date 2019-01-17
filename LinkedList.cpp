#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

struct node {
    char word[33];
	struct node *next;
	struct node *down;
	int count;  //for next

	int ecount [6];  //for each txt   //for down
	int hcount [7];                   //for down
	int mcount [5];                   //for down
	char * documentID;                //for down
    int count2;                       //for down
    int length;                       //for down
    char * ctgname;                   //for down
  };
  
  int iff=0;
 typedef struct node node;
 
int search(char *, node *);
int createSec(int array[][3]);
void print(node *MLL);
void insert(FILE * fptr, node * MLL );
void generatEcontxt();
void generatHealthtxt();
void generatMagazintxt(); 
void printfile(FILE *fptr);
void generatMLL();  //Main LL
void generateLLs();  //for 3 mini LL
int  etxtcount();//finding .txt word count
int  htxtcount();
int  mtxtcount();
int  LLcount( node * LL); //Linked List node count
void fillMiniArrays(int array[], node * LL);
void fillMLLArray(int array[][3]);
void partOfB();
char * findNthWord (int n, node * LL);
void partOFC(int array [][3]);
node * sortintMLL(node * MLL);
node * FindNode(char * word, node * LL);
void insertDown(node * temp2, int array[][3]);


node *eMLL= (node*)malloc(sizeof(node));
FILE *efptr; 

node *hMLL= (node*)malloc(sizeof(node));
FILE *hfptr;  

node *mMLL= (node*)malloc(sizeof(node));
FILE *mfptr; 

node *MLL= (node*)malloc(sizeof(node));  //MAIN LINKED LIST
FILE *fptr;

int x=0, xyz=0;
int totalWord=0;   //MLL`s word count
int etotalWord=0;  //eMLL`s word count
int htotalWord=0;  //hMLL`s word count
int mtotalWord=0;  //mMLL`s word count
int size=0;

int main(){
setlocale(LC_ALL, "Turkish");

 eMLL-> next =NULL;
 hMLL -> next = NULL;
 mMLL -> next = NULL;

 MLL -> next = NULL;  
 
generatMLL();   //generating MLL
generateLLs();  //generating eMLL, hMLL and mMLL
 
etxtcount();  //finding econ.txt word count   returns int
htxtcount();  //finding health.txt word count   returns int
mtxtcount();  //finding magazin.txt word count   returns int

int MLLarray[LLcount(MLL)];   //count data array for Main LL               
int eMLLarray[LLcount(eMLL)];  //count data array for econ LL
int hMLLarray[LLcount(hMLL)];  //count data array for health LL
int mMLLarray[LLcount(mMLL)];  //count data array for magazin LL

size =LLcount(MLL);
int bigArray [1500][3];  //for all words and categories double data array

fillMiniArrays(MLLarray, MLL);          
fillMiniArrays(eMLLarray, eMLL);         
fillMiniArrays(hMLLarray, hMLL);          	
fillMiniArrays(mMLLarray, mMLL);         

fillMLLArray(bigArray);         

print(MLL);
partOfB();   //B part         

partOFC(bigArray);   //C part   

createSec(bigArray);  //generating different linked list for each word

MLL = sortintMLL(MLL);  //MLL is sorted

print(MLL);

}

void insert( FILE * fptr, node * MLL){
	
	node *temp =MLL;
	if (fptr) {
	char mllword[10];
	strcpy(mllword, MLL -> word);  //first inserting

    while (!(feof(fptr))){
    	char gecici[50];  //array of word
 
	fscanf(fptr, "%s", gecici);
	if ( !strcmp(mllword, MLL-> word) || (search(gecici, MLL))) //ayni kelimeden yoksa 1 dondurucek ; varsa 0 dondurucek
	{
		strcpy(temp-> word , gecici);

 		temp -> next = (node*)malloc(sizeof(node));
        temp = temp ->next;  
		temp -> next = NULL;
   }
   
}
}  
}
void print(node *MLL){

	node *temp = MLL;
	while(temp -> next != NULL){

		printf("\n %s", temp -> word);
				printf("- %d", temp -> count);

		temp = temp -> next;
	}
	
	
}

int createSec(int array[][3]){    //creating new ll for each word
	
	node * temp = MLL;

	while(temp -> next != NULL){
		insertDown(temp, array);
		temp = temp -> next;
	}
	
}

int search(char * name, node * list){   //ayni kelimeden yoksa 1 dondur varsa return 0!
     	
	char x[20], y[20];
     node *temp2= list;

	 	strcpy(x, name);
	 	strcpy(y, temp2 -> word);
	 
	if(strcmp(x, y)==0)  {  (temp2 -> count)++; 
		  return 0;
	  	} 
														
	else  { 
	
    if(temp2 -> next == NULL){  return 1; } //son kelimeye gelindi
	else{	

		temp2= temp2-> next ;  
		search (x, temp2 );  
	
		}
	}  
}

void printfile(FILE *fptr){
	
	 fptr = fopen ("1e.txt", "r");

	char word[20];
	
	while (!(feof(fptr))){	

	fscanf(fptr, "%s ", word);
  
     printf("- %s", word);
}
	
}

void generatEcontxt(){
	
	efptr = fopen ("econ.txt", "a");  

FILE *fptr1 = fopen ("./econ/1.txt", "r");  
FILE *fptr2 = fopen ("./econ/2.txt", "r");  
FILE *fptr3 = fopen ("./econ/3.txt", "r");  
FILE *fptr4 = fopen ("./econ/4.txt", "r");  
FILE *fptr5 = fopen ("./econ/5.txt", "r");  
FILE *fptr6 = fopen ("./econ/6.txt", "r");  
 
 int count = 0;
	char word[20];
  
while (!(feof(fptr1))){
	fscanf(fptr1, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}
        fputs("\n", efptr);
 
 
while (!(feof(fptr2))){
	fscanf(fptr2, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}
        fputs("\n", efptr);
       
while (!(feof(fptr3))){
	fscanf(fptr3, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}
        fputs("\n", efptr);
        
while (!(feof(fptr4))){
	fscanf(fptr4, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}
        fputs("\n", efptr);
        
while (!(feof(fptr5))){
	fscanf(fptr5, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}
        fputs("\n", efptr);
        
while (!(feof(fptr6))){
	fscanf(fptr6, "%s ", word);
    fputs(word, efptr);
        fputs(" ", efptr);
}     

fclose(efptr);

}

void generatHealthtxt(){
	struct dirent *de;
//	DIR *dr = opendir("./econ - Copy/");
	
hfptr = fopen ("health.txt", "a");  

FILE *fptr1 = fopen ("./health/1.txt", "r");  
FILE *fptr2 = fopen ("./health/2.txt", "r");  
FILE *fptr3 = fopen ("./health/3.txt", "r");  
FILE *fptr4 = fopen ("./health/4.txt", "r");  
FILE *fptr5 = fopen ("./health/5.txt", "r");  
FILE *fptr6 = fopen ("./health/6.txt", "r");  
FILE *fptr7 = fopen ("./health/7.txt", "r");  

 char word[20];
  
while (!(feof(fptr1))){
	fscanf(fptr1, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
 
 
while (!(feof(fptr2))){
	fscanf(fptr2, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
       
while (!(feof(fptr3))){
	fscanf(fptr3, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
        
while (!(feof(fptr4))){
	fscanf(fptr4, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
        
while (!(feof(fptr5))){
	fscanf(fptr5, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
        
while (!(feof(fptr6))){
	fscanf(fptr6, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);

while (!(feof(fptr7))){
	fscanf(fptr7, "%s ", word);
    fputs(word, hfptr);
        fputs(" ", hfptr);
}
        fputs("\n", hfptr);
        fclose(hfptr);
    
}

void generatMagazintxt(){
	struct dirent *de;
//	DIR *dr = opendir("./econ - Copy/");
	
mfptr = fopen ("magazin.txt", "a");  

FILE *fptr1 = fopen ("./magazin/1.txt", "r");  
FILE *fptr2 = fopen ("./magazin/2.txt", "r");  
FILE *fptr3 = fopen ("./magazin/3.txt", "r");  
FILE *fptr4 = fopen ("./magazin/4.txt", "r");  
FILE *fptr5 = fopen ("./magazin/5.txt", "r");  

 char word[20];
  
while (!(feof(fptr1))){
	fscanf(fptr1, "%s ", word);
    fputs(word, mfptr);
        fputs(" ", mfptr);
}
        fputs("\n", mfptr);
 
 
while (!(feof(fptr2))){
	fscanf(fptr2, "%s ", word);
    fputs(word, mfptr);
        fputs(" ", mfptr);
}
        fputs("\n", mfptr);
       
while (!(feof(fptr3))){
	fscanf(fptr3, "%s ", word);
    fputs(word, mfptr);
        fputs(" ", mfptr);
}
        fputs("\n", mfptr);
        
while (!(feof(fptr4))){
	fscanf(fptr4, "%s ", word);
    fputs(word, mfptr);
        fputs(" ", mfptr);
}
        fputs("\n", mfptr);
        
while (!(feof(fptr5))){
	fscanf(fptr5, "%s ", word);
    fputs(word, mfptr);
        fputs(" ", mfptr);
}
        fputs("\n", mfptr);
        
        fclose(mfptr);	
}

void generatMLL(){
	
generatEcontxt();
generatHealthtxt();
generatMagazintxt();

fptr = fopen ("MLL.txt", "a");  

char word [20];

  efptr = fopen ("econ.txt", "r");  
	while (!(feof(efptr))){
	fscanf(efptr, "%s ", word);
    fputs(word, fptr);
        fputs(" ", fptr);
	}
        fputs("\n", fptr);
        fclose(efptr);
        
        
  hfptr = fopen ("health.txt", "r"); 
    while (!(feof(hfptr))){
	fscanf(hfptr, "%s ", word);
    fputs(word, fptr);
        fputs(" ", fptr);
	}
        fputs("\n", fptr);
        fclose(hfptr);
        
        
   mfptr = fopen ("magazin.txt", "r"); 
	 while (!(feof(mfptr))){

	 fscanf(mfptr, "%s ", word);
  	 fputs(word, fptr);
    	  fputs(" ", fptr);
     }
       	  fputs("\n", fptr);          
       		 fclose(mfptr);
       		 fclose(fptr);
            
   			 
			 fptr = fopen ("MLL.txt", "r"); 

   			 insert(fptr,MLL);  
    			
		     fclose(fptr);
	
}

void generateLLs(){

efptr = fopen ("econ.txt", "r"); 
 
   insert(efptr,eMLL);  
	fclose(efptr);
	
	
hfptr = fopen ("health.txt", "r"); 

   insert(hfptr,hMLL);
	fclose(hfptr);
	
	
mfptr = fopen ("magazin.txt", "r");
 
   insert(mfptr,mMLL);
	fclose(mfptr);	
	
}

int  LLcount( node * LL) {

int count =0;
node * temp= LL;

while(temp -> next != NULL){   //end of ll
	count++;
	temp= temp -> next;
}
  return count;
	
}

int  etxtcount (){   //file length
	
efptr = fopen ("econ.txt", "r");  

char word [20];

	while (!(feof(efptr))){
		
	fscanf(efptr, "%s ", word);
    etotalWord++;
    }
	
	return  etotalWord;
	
}

int  htxtcount (){  //file length
	
hfptr = fopen ("health.txt", "r");  

char word [20];

	while (!(feof(hfptr))){
		
	fscanf(hfptr, "%s ", word);
    htotalWord++;
    }
	
	return  htotalWord;
	
}

int mtxtcount (){   //file length
	
mfptr = fopen ("magazin.txt", "r");  

char word [20];

	while (!(feof(mfptr))){
		
	fscanf(mfptr, "%s ", word);
    mtotalWord++;
    }
    
	return  mtotalWord;
	
}

void fillMiniArrays(int array[], node * LL){
	node * temp = LL;
	
	for(int i=0; i< sizeof(array); i++){
		array[i]= temp -> count ;
		temp = temp -> next;
	}
	
}

void fillMLLArray(int array [][3]){  
	int i=0;
	
	node * temp = MLL;
	node * temp2;
	
	//fill for econ LL	
	temp2 = eMLL;
	for(i=0; i< LLcount(MLL); i++){
	
	   if(!(strcmp(temp -> word, temp2 -> word))) 
	   {
	   	array[0][i]= temp2 -> count ++;
	   	temp2= temp2 -> next;
	   }
	   else 
	     array [0][i] = 0;
	
	}
	
	//fill for health LL
		temp =MLL;
		temp2 = eMLL;
	for(i=0; i< LLcount(MLL); i++){
	
	   if(!(strcmp(temp -> word, temp2 -> word))) 
	   {
	   	array[1][i]= temp2 -> count ++;
	   	temp2= temp2 -> next;
	   }
	   else 
	     array[1][i] = 0;
	
	}
	
	//fill for magazin LL
    	temp =MLL;
		temp2 = eMLL;
	for(i=0; i< LLcount(MLL); i++){
	
	   if(!(strcmp(temp -> word, temp2 -> word))) 
	   {
	   	array[2][i]= temp2 -> count ++;
	   	temp2= temp2 -> next;
	   }
	   else 
	     array [2][i] = 0;
	
	}
}

void partOfB(){    //once sadece arrayi kullanarak en buyuk elemani bul ardindan for dongusu icinde kacinci elemansa o kadar ilerle o kelimeyi bul

//once MLL arrayini kullanarak en buyuk 5 elemani buldum bunlari siralama arrayinde tuttum. Daha sonra o sayilarin Linked listte hangi kelimeye
//denk geldigini bulup o words [5] arrayini olusturdum daha sonra da words arrayini alfabetik siralayip print ettim

	node * temp =MLL;
   char * words [5]; //double char array for 5 word 

    int siralama[5]; //count array 
   
   int max, y, j , i ;

    max = temp -> count;
    
    for(y=0; y<5 ; y++){       // for generate siralama array. ex; siralama[5] = {9,7,6,3,1} countlar siralamasi. Bunu olusturduk.
	
    for( int i=1; i <LLcount(MLL) ;  i++)  //her seferinde max bulup for sonunda sifiri buluyor bir sonraki max icin
    {
        if( (temp -> next != NULL) && (temp -> next -> count > max) )  //LL sonuna gelinmediyse VE tempin nextinin countu max`tan buyukse
        {
            max = temp -> next -> count;  
            temp = temp -> next;
        }
        else  temp = temp -> next;

    }
     temp -> count = 0;   //for next max value
     siralama[y]= max;  
}

 	temp = MLL;
	for(j=0; j<5 ; j++){    // for generate words of 5 common words array   words[5]= {cc , bb, ee, dd, aa}

	   	 for(i=1; i < siralama[j] ; i++){   // for find first word  //3. kelimeyi bulmak icin 2 defa ilerlemeli

		   temp = temp -> next;  	

  		 }     

      words[j]= temp -> word;

	 }
	
    //WORDS ARRAY SORTING

	for(int j=4 ; j>0 ; j--){        
	
		for(int i=0;  i< 4 ; i++){
			
			if(strcmp(words[i], words[i+1]) > 0 ) {
		
			char * temp2 = words[i];
			words[i]= words[i+1];
			words[i+1]= temp2;
		
			}
		}
	
	}          //  In the end we obtain words[5]= {aa, bb, cc, dd, ee}
	

	//FINAL PRINT PART
	printf("Term-1: %s", words[0]);
	printf("Term-2: %s", words[1]);
	printf("Term-3: %s", words[2]);
	printf("Term-4: %s", words[3]);
	printf("Term-5: %s", words[4]);


}

void partOFC(int array [][3]){  
//double int arrayini kullanarak discriminating wordleri bulup datalari yeni olusturdugum array2[5][3] arrayine dolduruyorum. Sort ettikten sonra print ediyorum.

	int x=0; //for count to 5
	char  * array2 [5][3];
	
	//for array [][0] ECON
	for(int i=0; i<LLcount(MLL) ; i++){
		
		if(array[0][i] >0 && array[1][i] ==0 && array[2][i] ==0  && x!=5){
			x++;
			array2[i][0] = findNthWord( i , MLL);
    	}
    	if(x == 5) break;
		
	}
	
	
		//for array [][1] HEALTH
		x=0;
	for(int i=0; i<LLcount(MLL) ; i++){
		
		if(array[1][i] >0 && array[0][i] ==0 && array[2][i] ==0  && x!=5){
			x++;
			array2[i][1] = findNthWord( i , MLL);
    	}
    	if(x == 5) break;
		
	}
	
		//for array [][2] MAGAZIN
		x=0;
	for(int i=0; i<LLcount(MLL) ; i++){
		
		if(array[2][i] >0 && array[1][i] ==0 && array[0][i] ==0  && x!=5){
			x++;
			array2[i][2] = findNthWord( i , MLL);
    	}
    	if(x == 5) break;
		
	} //FILLED ARRAY2
	
	  
	          //WORDS ARRAY SORTING
		
	
	for(int k=0; k<3 ; k++){  //for 3 columns
		
		for(int j=4 ; j>0 ; j--){        // for 5 rows
	
			for(int i=0;  i< 4 ; i++){
			
				if(strcmp(array2[i][k], array2[i+1][k]) > 0 ) {
		
				char *temp2 = array2[i][k];
				array2[i][k]= array2[i+1][k];
				array2[i+1][k]= temp2;
		
				}
			}
	
		}   
	   		
	}
	
	//PRINT WORDS
	printf("Category-1 \t Category-2 \t Category-3 \n");
	for(int i=0; i<5 ; i++){
			printf("%s \t %s \t %s \n", array2[i][0], array2[i][1], array2[i][2]) ;

	}
		
}

char * findNthWord (int n, node * LL){
	
	node *temp = LL;
	
	for(int i=1 ; i<n; i++){
		temp = temp -> next;
		
	}
	return temp-> word;
}

node * sortintMLL(node * MLL){
	
	node * temp = MLL;
		
		while(temp -> next != NULL){
			
			for(int k=0; k< LLcount(MLL) ; k++){
				
				for(int i=0; i< LLcount(MLL) ; i++){
					
						if(strcmp(temp -> word, temp -> next -> word) > 0 ) {
		
							node * temp2 = temp ;
							temp  = temp -> next;
							temp2 -> next= temp-> next;
							temp -> next = temp2;				
		
						}
					
			   	 }
				
			}	
			
	  }
	return MLL;
}

node * FindNode(char * word, node * LL){
	node * temp = LL;
	
	while(temp -> next != NULL){
		
		if(strcmp(word, temp -> word) == 0){
			return temp;
		}
		else temp = temp -> next;
	}
	
}

void insertDown(node * temp2, int  array[][3]){
	
	char * name;  //category name
	int count;
	node * temp= temp2;
		temp -> down = (node *) malloc(sizeof(node));

	for(int i=0; i<3;  i++){

       if(i==0)  name = "economy";
   	   else if(i==1)  name = "health";
       else name = "magazin";
       
       if(i==0)  count=etxtcount();
   	   else if(i==1)  count=htxtcount();
       else count=mtxtcount();
       

	//	temp -> down -> documenID=
	    temp -> down -> count2 =array[i][x];
        temp -> down -> length = count;
        temp -> down -> ctgname = name;
		
		
		temp= temp -> down;
		if(x!=2) temp -> down = (node *) malloc(sizeof(node));
		else temp -> down = NULL;
		
	
		
	}
	
}

