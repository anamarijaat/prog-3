#include <iostream>

struct date_of_birth{
    unsigned short day;
    unsigned short mounth;
    unsigned short year;
};

struct Footballer{
    char name_sirname[50];
    char club_name[20];
    date_of_birth d;
};
void strcpy(char *where, char *from){
    while(*from){
        *where = *from;
        where++;
        from++;
    }
    *where = '\0';
}


int main() {
    
    Footballer k;
    strcpy(k.name_sirname, "Flora Trpeska");
    strcpy(k.club_name, "Vardar");
    k.d.day = 10;
    k.d.mounth = 9;
    k.d.year = 2001;
    std::cout << k.name_sirname << ' ' << k.club_name << ' ' << k.d.day<<"."<<k.d.mounth << "." << k.d.year;
    
    return 0;
}
