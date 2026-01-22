#include <iostream>
#include <string>
#include <algorithm>
#include "common.h"
#include <cjson/cJSON.h>

void TranFunc(cJSON *root, const Person &person) //自定义序列化函数
{
    if(root = nullptr) 
    {
        std::cout << "root is NULL" << std::endl; 
        return ;
    }
    cJSON_AddStringToObject(root, "name", person.name.c_str());
    cJSON_AddNumberToObject(root, "age", person.age);
    cJSON_AddNumberToObject(root, "weight", person.weight);
    cJSON_AddStringToObject(root, "sex", person.sex ? "male":"female");
    
}

int main()
{
    // std::cout << "CJSON install successful" << std::endl;

    Person person;
    person.age = 24;
    person.name = "Frank";
    person.sex = 1;
    person.weight = 75;




    cJSON *root = cJSON_CreateObject();
    if(root == nullptr) {
        std::cout << "序列化失败，原因：创建对象失败" << std::endl;
        return 0;
    }

    //将数据序列化成cJSON对象
    TranFunc(root, person);
    char* jsonContent = cJSON_Print(root);
    printf("%s\n", jsonContent);

    FILE* fp = fopen("frank.json", "w");
    if(fp != NULL) {
        fputs(jsonContent, fp);
        fclose(fp);
        std::cout << "successful save cJSON_Object" << std::endl; 
    }

    free(jsonContent);
    cJSON_Delete(root);

    return 0;
}

