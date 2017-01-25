#include <json/json.h>
#include <stdio.h>
#include <fcntl.h>
#include <curl/curl.h>

int main() {

  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);
  struct curl_slist *headers = NULL;
  curl_slist_append(headers, "Content-Type: application/json");

  json_object *data = json_object_new_object();
  json_object_object_add(data, "Hello", json_object_new_string("testing"));

  curl = curl_easy_init();

  if (curl) {

    curl_easy_setopt(curl, CURLOPT_URL, "http://wasch.herokuapp.com");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 1L);

    printf(json_object_to_json_string(data));

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_object_to_json_string(data));
    res = curl_easy_perform(curl);
    printf(curl_easy_strerror(res));

    curl_global_cleanup();
  }

  return 0;
}
