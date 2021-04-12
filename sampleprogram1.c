#include<stdio.h>
#include "parson.h"

int isFileExists(const char *path)
{
    FILE *fptr = fopen(path, "r");

    // If file does not exists 
    if (fptr == NULL){

      printf("\nFile doesn't exists %s\n",path);
      return 0;

    }else{
      printf("File exists \n");
    }

    // File exists hence close file and return true.
    fclose(fptr);

    return 1;
}
int ReadConfiguration() {
  /* parsing json and validating output */
  JSON_Value *root_value;

  if (!isFileExists("example.json"))
    {
        printf("\nConfiguration file does not exists\n");
    }

  root_value = json_parse_file("example.json");


  JSON_Object* objs = json_value_get_object(root_value);

  printf("input port number is %f \n",json_object_get_number(objs, "inputPortNumber"));
  printf("output port number is %f \n",json_object_get_number(objs, "outputPortNumber"));
  
  return 1;

}
int main(){
    printf("printing all the configuration data");
    return ReadConfiguration();
    // return 0;
}