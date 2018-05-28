#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main ()
{
	 const size_t MAX_SIZE = 256;
    const char* separators = " \r\n,.!?:;()-";
    char text[MAX_SIZE];
    cout<<"Vvedite immia faila : ";
    cin>>text;
    if((strchr(text,'*') != 0)||(strchr(text,'"') != 0) ||
       (strchr(text,'<') != 0)||(strchr(text,'>') != 0)||
       (strchr(text,'?') != 0)||(strchr(text,'|') != 0)){
        cout << "Error! Zapreshennie simvoli";
        return 1;
    }
    if((strchr(text,':') != 0)&&
       (!(((strchr(text,':') - text + 1) == 2)&&
          (((strchr(text,'\\') - text + 1) == 3)||
           isalpha(1) != 0)))){
              cout << "Error! Necorrectnoe imya faila";
              return 1;
          }
    char * lastDot = strrchr(text, '.');
    
    if(lastDot != 0){
        if(strcoll(lastDot, ".txt") != 0){
            strcat(text, ".txt");
        }
    }
    else
    {
        strcat(text, ".txt");
    }
    ifstream ifs(text);
    int FILE_LENGTH = 0;
    if (ifs) {
        ifs.seekg (0, ifs.end);
        FILE_LENGTH = ifs.tellg();
        ifs.seekg (0, ifs.beg);
        char * file_content = new char[FILE_LENGTH];
        ifs.read(file_content, FILE_LENGTH);
        ifs.close();
        
        cout << "Enter a string to search for (up to 255 characters):" << endl;
        char substr[256];
        cin >> substr;
        
        int count = 0;
        const char *tmp = file_content;
        while(tmp = strstr(tmp, substr))
        {
            count++;
            tmp++;
        }
        cout << "The string \"" << substr << "\" occures in the file " << text << " "  << count << " times." << endl;
        delete[] file_content;
        delete[] tmp;
    }
    delete[] lastDot;
}
