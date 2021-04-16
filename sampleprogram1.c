#include<stdio.h>
#include "parson.h"

int isFileExists(const char *path)
{
    FILE *fptr = fopen(path, "r");

    // If file does not exists 
    if (fptr == NULL){

      printf("\n File doesn't exists %s\n",path);
      fclose(fptr);
      return 0;

    }else{
      printf("File exists \n");
      fclose(fptr);
      return 1;
    }
}
int ReadConfiguration() {
  JSON_Value *root_value;

  if (!isFileExists("example.json"))
    {
        printf("\n Configuration file does not exists\n");
      return 0;
    }

  root_value = json_parse_file("example.json");


  JSON_Object* objs = json_value_get_object(root_value);

  printf("input port number is %f \n",json_object_get_number(objs, "inputPortNumber"));
  printf("output port number is %f \n",json_object_get_number(objs, "outputPortNumber"));
  
  return 1;

}
int main(){
    printf("print all the configuration data");
    return ReadConfiguration();
}
