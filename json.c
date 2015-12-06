#include <json/json.h>
#include <stdio.h>

int main() {
  /*Creating a json object*/
  json_object * jobj = json_object_new_object();

  /*Creating a json string*/
  json_object *jstring = json_object_new_string("Joys of Programming");



  /*Creating a json array*/
  json_object *jarray = json_object_new_array();

  /*Creating json strings*/
  json_object *jstring1 = json_object_new_string("c");


  /*Adding the above created json strings to the array*/
  json_object_array_add(jarray,jstring1);

  /*Form the json object*/
  /*Each of these is like a key value pair*/
  json_object_object_add(jobj,"Site Name", jstring);
  json_object_object_add(jobj,"Categories", jarray);

  /*Now printing the json object*/
  printf ("The json object created: %sn",json_object_to_json_string(jobj));

}
