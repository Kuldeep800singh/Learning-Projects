#include <iostream>
#include <fstream>
#include <string>

std::string filepath;

void CreateNewFile(bool intialized = false);
void WriteFile(bool appendData = false);
void ReadFile();
void AppendFile();
void DeleteFile();

int main()
{
    while (1)
    {
        char choice;
        std::cout << std::endl << std::endl;
        std::cout << "------------- MENU -------------" << std::endl;
        std::cout << "1.CREATE" << std::endl;
        std::cout << "2.WRITE" << std::endl;
        std::cout << "3.READ" << std::endl;
        std::cout << "4.APPEND" << std::endl;
        std::cout << "5.DELETE" << std::endl;
        std::cout << "6.EXIT" << std::endl;
        std::cout << "Enter Your choice :-";
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            CreateNewFile();
            break;
        case '2':
            WriteFile();
            break;
        case '3':
            ReadFile();
            break;
        case '4':
            WriteFile(true);
        break;
        case '5':
            DeleteFile();
        break;
        case '6':
        {
            filepath = "";
            return 0;
        }
        break;
        default:std::cout<<"Please chose correct option" << std::endl; break;
        }
    }
    return 0;
}

//for creating the files
void CreateNewFile(bool initialized)
{
    std::fstream file;
    std::cout << std::endl;
    std::cout << "------------- CREATE FILE -------------" << std::endl;
    if(!initialized)
    {
        std::cout << "Enter filename or filepath + filename :- ";
        std::cin.ignore();
        getline(std::cin, filepath);
    }
    //for opening or creating the file
    file.open(filepath, std::ios::out);
    if (!file)
    {
        std::cout << "Error in creating the file!" << std::endl;
        return;
    }
    std::cout << "File Created Succesfuly." << std::endl;
    file.close();
}

//for writig to the file
void WriteFile(bool appendData)
{
    std::string data;
    std::ofstream file;
    std::cout << std::endl;
    std::cout << "------------- WRITE FILE -------------" << std::endl;
    std::cout << "Enter filename :- ";    
    std::cin.ignore();
    getline(std::cin, filepath);
    std::cout << "Enter the data to insert :- ";
    getline(std::cin,data);
    std::cout << data << std::endl;
    if(appendData)
        file.open(filepath, std::ios::app);
    else
        file.open(filepath);

    if(!file)
    {
        std::cout << "Error unable to create or write to this file." <<std::endl;
        return;
    }
    file << data << std::endl;
    std::cout<<"Data inserted successfully."<<std::endl;
    file.close();
}

//for read from file
void ReadFile(){
    std::ifstream file;
    std::string data;
    std::cout << "------------- READ FILE -------------" << std::endl;
    std::cout << "Enter filename :- ";    
    std::cin.ignore();
    getline(std::cin, filepath);
    file.open(filepath);
    if(!file)
    {
        std::cout << "Unable to find the file" << std::endl;
        return;
    }
    file.seekg(0, std::ios::beg);
    while(file.good()){
        getline(file,data);
        std::cout << data << std::endl; 
    }
    file.close();
}

//for Deleting the file or its data
void DeleteFile(){
    char choice;
    std::ofstream file;
    std::cout << "------------- DELETE FILE -------------" << std::endl;
    std::cout<< "1.Delete the file" << std::endl;
    std::cout<< "2.Delete file data" << std::endl;
    std::cout<< "Choose and option: ";
    std::cin >> choice;
    std::cout << std::endl;
    std::cout << "Enter filename :- ";    
    std::cin.ignore();
    getline(std::cin, filepath);
    switch(choice){
        case '1':std::remove(filepath.c_str());break;
        case '2':file.open(filepath, std::ios::trunc);break;
        default: std::cout<< "Please choose correct option"<<std::endl;
        break;
    };
    
}
