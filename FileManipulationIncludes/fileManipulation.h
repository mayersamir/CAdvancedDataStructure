
#ifndef FILEMANIPULATION_H_
#define FILEMANIPULATION_H_
#include <stdlib.h>
#include<stdio.h>

typedef struct err{
  char* errorMessage;
  void* ptd;

}fileErrorOrData;


typedef struct filedata{
  void* ptr;
  struct filedata* ptFileData;

}fileData;

typedef struct filelist{

  int size;

  fileData* head;

  fileErrorOrData* feod;


}fileList;

typedef enum fileoperation{

  read = 1,
  write ,
  append ,
  seek
}fileOperation;

void assignCharMode(fileOperation fo);

void changeFileNameDirectory(char*newName);

fileErrorOrData readFromFile(int sizeOfRecord);

int writeToFile(int sizeOfRecord,void* blockOfBytes);

void closeOpenedFile(FILE* ptf);


void fileDataListInitialize(fileList* fl);

int insertIntoFileList(fileList* fl,void* ptd);


void readWholeFile(int sizeOfRecord,fileList* fl);

char* returnErroOrNot(fileList* fl);


#endif
