#include<stdio.h>

#include "../FileManipulationIncludes/fileManipulation.h"


char* fileName=NULL ;
char* mode=NULL;

void fileDataListInitialize(fileList* fl){


  fl->size = 0;
  fl->head = NULL;
  fl->feod = NULL;
}



/*
this coming function si for inserting any specified data inside an opened file

like i told you sir befor using the void* ptr   power 

this the power of c in my opinion !!

*/
int insertIntoFileList(fileList* fl,void* ptd){

  fileData* fd = (fileData*)malloc(sizeof(fileData));


  if(fd){
    fd->ptr = ptd;
    fd->ptFileData = NULL;
    if(fl->size == 0){
      fl->head = fd;
      fl->size++;


    }
    else{

      fileData* tmp = fl->head;

    //  for(int i =1;i<((fl->size)-1);i++){

      //  tmp = tmp->ptFileData;

      //}

      while(tmp->ptFileData){
        tmp=tmp->ptFileData;
      //  printf("lol");
      }

      tmp->ptFileData = fd;
      fl->size++;


    }

    return 1;



  }
  else{

    return 0;
  }

}



/*

knowing the operation which we are going to do on the opened file !

*/

void assignCharMode(fileOperation fo){

  if(mode!=NULL){

    free(mode);
  }

  mode = (char*)malloc(1);


  switch(fo){

    case read:
      mode = "r";
      break;
    case write:
      mode = "w";
      break;
    case append:
      mode = "a";
      break;
  }



}



/*

assigning the directory which the file will be saved at !


*/
void changeFileNameDirectory(char*newName){



  if(newName==NULL){
    fileName = (char*)malloc(150);


    fileName = "C:/Users/mayer/Desktop/ITI-embedded/cms/records/patients.txt";
  }
  else{

    free(fileName);

    fileName = newName;



  }





}



/*
*
this function is for reading the whole file contenet

*/


void readWholeFile(int sizeOfRecord,fileList* fl){

  FILE* fileStream =fopen(fileName,mode);
  void* ptr = malloc(sizeOfRecord);
  //fileList* fl = (fileList*) malloc(sizeof(fileList));



  if(fileStream){
    int returnedValue=fread(ptr,sizeOfRecord,1,fileStream);
    int counter = 1;
    if(returnedValue){
      do{
        insertIntoFileList(fl,ptr);
        printf("**");
        fseek(fileStream,((sizeOfRecord)*counter),SEEK_SET);
        ptr = malloc(sizeOfRecord);
        returnedValue=fread(ptr,sizeOfRecord,1,fileStream);
        counter++;
        printf("*");

      }while(returnedValue>=1);
      closeOpenedFile(fileStream);

    }

    else{

      fl->feod = (fileErrorOrData*)malloc(sizeof(fileErrorOrData));

      fl->feod->errorMessage = "Error happened when i am trying to read from the file !";


    }






  }else{

    fl->feod = (fileErrorOrData*)malloc(sizeof(fileErrorOrData));
    fl->feod->errorMessage = "the file couldn't be open !";





  }


}



/*

this function is for reading a specific bulk of data and returning a pointer to 
it 
for further information read the .h file which contains everysingle detail about the 
types i used 

*/
fileErrorOrData readFromFile(int sizeOfRecord){



  fileErrorOrData fed;

  FILE* fileStream =fopen(fileName,mode);
  void* ptr = malloc(sizeOfRecord);
  //printf("%s",fileName);
  if(fileStream){

      if(fread(ptr,sizeOfRecord,1,fileStream)){

        fed.ptd = ptr;
        fed.errorMessage = NULL;

        //printf("there has not been any errors !");
      }else{

        //rintf("eroooooooooooooooooooooooooooooooooooor\n");
        fed.errorMessage = "Error when trying to read from the ginven file !";
        fed.ptd = NULL;

      }




  }

  closeOpenedFile(fileStream);
  return fed;


}



/*

write a specific bulk of data inside the opeened file 
the writing is done after the latest bulk has been written
that why the file will be opened for append.


*/

int writeToFile(int sizeOfRecord,void* blockOfBytes){


  FILE* fileStream = fopen(fileName,mode);

  //void* ptr = NULL;
  fseek(fileStream, sizeOfRecord, SEEK_END);

  fwrite(blockOfBytes,sizeOfRecord,1,fileStream);
  rewind(fileStream);
 
  closeOpenedFile(fileStream);
  return 1;


}


/*
this function is for closing the opened resource 
*/
void closeOpenedFile(FILE* ptf){

  fclose(ptf);
}


/*

this function is for returning any types of errors that have been specified at the
filemanipulation .h file

*/

char* returnErroOrNot(fileList* fl){
  char* er = NULL;
  if(fl->feod){

    er = (fl->feod->errorMessage);

  //  return  ;
  }

  return er;
}
