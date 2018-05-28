#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <string.h>
using namespace std;

char nibble_to_hex(uint8_t i){
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void print_in_hex(uint8_t byte){
    cout << nibble_to_hex(byte >> 4)
    << nibble_to_hex(byte & 0b00001111);
}
const uint8_t*
as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}
char* fgets(char* str, int count, std::FILE* stream);
void print_in_hex(const void* data, size_t size){
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char
bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void
print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte,0);
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        // ??? ???????? ??????: ??????? ????? ???????, ?? 4 ????? ?? ??????.
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct student {
    char name[17];
    int year;
    float middlePoint;
    uint8_t sex:1;
    int courseValue;
    student * starosta;
};
int
main() {
    //    assert(nibble_to_hex(0x0) == '0');
    //    assert(nibble_to_hex(0x1) == '1');
    //    assert(nibble_to_hex(0x2) == '2');
    //    assert(nibble_to_hex(0x3) == '3');
    //    assert(nibble_to_hex(0x4) == '4');
    //    assert(nibble_to_hex(0x5) == '5');
    //    assert(nibble_to_hex(0x6) == '6');
    //    assert(nibble_to_hex(0x7) == '7');
    //    assert(nibble_to_hex(0x8) == '8');
    //    assert(nibble_to_hex(0x9) == '9');
    //    assert(nibble_to_hex(0xa) == 'a');
    //    assert(nibble_to_hex(0xb) == 'b');
    //    assert(nibble_to_hex(0xc) == 'c');
    //    assert(nibble_to_hex(0xd) == 'd');
    //    assert(nibble_to_hex(0xe) == 'e');
    //    assert(nibble_to_hex(0xf) == 'f');
    //    uint32_t u32 = 0x42;
    //    cout << "u32 bytes: ";
    //    print_in_hex(&u32, sizeof(u32));
    //    cout << '\n';
    //    uint8_t u8 = 3;
    //    print_in_binary(&u8, sizeof(u8));
    uint16_t x, z, res;
    char y;
    cout<<"vedite x y z\n";
    cin>>x>>y>>z;
    switch (y){
        case '&' :
            res = x&z;
            print_in_hex(&x, sizeof(x));
            cout<<y<<' ';
            print_in_hex(&z, sizeof(z));
            cout<<" = ";
            print_in_hex (&res, sizeof(res));
            cout<<'\n';
            print_in_binary(&x, sizeof(x));
            cout<<y<<' ';
            print_in_binary(&z, sizeof(z));
            cout<<" = ";
            print_in_binary (&res, sizeof(res));
            break;
        case '|' :
            res = x|z;
            print_in_hex(&x, sizeof(x));
            cout<<y<<' ';
            print_in_hex(&z, sizeof(z));
            cout<<" = ";
            print_in_hex (&res, sizeof(res));
            cout<<'\n';
            print_in_binary(&x, sizeof(x));
            cout<<y<<' ';
            print_in_binary(&z, sizeof(z));
            cout<<" = ";
            print_in_binary (&res, sizeof(res));
            break;
        case '^' :
            res = x^z;
            print_in_hex(&x, sizeof(x));
            cout<<y<<' ';
            print_in_hex(&z, sizeof(z));
            cout<<" = ";
            print_in_hex (&res, sizeof(res));
            cout<<'\n';
            print_in_binary(&x, sizeof(x));
            cout<<y<<' ';
            print_in_binary(&z, sizeof(z));
            cout<<" = ";
            print_in_binary (&res, sizeof(res));
            break;
    }
    student k[3]{
        {
            "Tema", 2000, 0.1, 0, 7, nullptr,
        },
        {
            "Oleg", 2000, 4.1, 0, 7, &k[0],
        },
        {
            "Danya", 2000, 3.1, 0, 7, &k[0],
        }
    };
    cout<<"\nAddress of array:"<<&k<<'\n';
    cout<<"Size of array:"<<sizeof(k)<<'\n';
    cout<<"Address of element:"<<"\t Size of element:\n";
    for (int i = 0; i < 3; i++) {
        cout<<i<<'\t'<<&k[i]<<"\t\t"<<sizeof(k[i])<<"\n";
    }
    cout<<"For first elem of array:\n";
    cout<<"\t\tAddress of field:"<<"\t size of field:"<<"\t offset:\n";
    cout<<"NAME: \t"<<&k[0].name<<"\t\t\t";
    cout<<sizeof(k[0].name)<<"\t\t\t"<<offsetof(struct student, name);
    cout<<"\n";
    cout<<"YEAR: \t"<<&k[0].year<<"\t\t\t";
    cout<<sizeof(k[0].year)<<"\t\t\t"<<offsetof(struct student, year);
    cout<<"\n";
    cout<<"MIDDLEPOINT: \t"<<&k[0].middlePoint<<"\t\t\t";
    cout<<sizeof(k[0].middlePoint)<<"\t\t\t"<<offsetof(struct student, middlePoint);
    cout<<"\n";
    cout<<"COURSEVALUE: \t"<<&k[0].courseValue<<"\t\t\t";
    cout<<sizeof(k[0].courseValue)<<"\t\t\t"<<offsetof(struct student, courseValue);
    cout<<"\n";
    cout<<"STAROSTA: \t"<<&k[0].starosta<<"\t\t";
    cout<<sizeof(k[0].starosta)<<"\t\t\t"<<offsetof(struct student, starosta);
    cout<<"\n";
    cout<<"Name:\n";
    cout<<"Binary:\n";
    print_in_binary(&k[0].name, sizeof(k[0].name));
    cout<<"\nHex:\n";
    print_in_hex(&k[0].name, sizeof(k[0].name));
    cout<<"\n\n\n";
    cout<<"Year:\n";
    cout<<"Binary:\n";
    print_in_binary(&k[0].year, sizeof(k[0].year));
    cout<<"\nHex:\n";
    print_in_hex(&k[0].year, sizeof(k[0].year));
    cout<<"\n\n\n";
    cout<<"MiddlePoint:\n";
    cout<<"Binary:\n";
    print_in_binary(&k[0].middlePoint, sizeof(k[0].middlePoint));
    cout<<"\nHex:\n";
    print_in_hex(&k[0].middlePoint, sizeof(k[0].middlePoint));
    cout<<"\n\n\n";
    cout<<"CourseValue:\n";
    cout<<"Binary:\n";
    print_in_binary(&k[0].courseValue, sizeof(k[0].courseValue));
    cout<<"\nHex:\n";
    print_in_hex(&k[0].courseValue, sizeof(k[0].courseValue));
    cout<<"\n\n\n";
    cout<<"Starosta:\n";
    cout<<"Binary:\n";
    print_in_binary(&k[0].starosta, sizeof(k[0].starosta));
    cout<<"\nHex:\n";
    print_in_hex(&k[0].starosta, sizeof(k[0].starosta));
    cout<<"\n\n\n";
    //--------------------------------
    const size_t MAX_SIZE = 256;
    const char* separators = " \r\n,.!?:;()-";
    char text[MAX_SIZE];
    cout<<"Vvedite immia dlya faila : ";
    cin>>text;
    if((strchr(text,'*') != 0)||(strchr(text,'"') != 0) ||
       (strchr(text,'<') != 0)||(strchr(text,'>') != 0)||
       (strchr(text,'?') != 0)||(strchr(text,'|') != 0)){
        cout << "Zapreshennie simvoli";
        return 1;
    }
    if((strchr(text,':') != 0)&&
       (!(((strchr(text,':') - text + 1) == 2)&&
          (((strchr(text,'\\') - text + 1) == 3)||
           isalpha(1) != 0)))){
              cout << "Necorrectnoe imya faila";
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
