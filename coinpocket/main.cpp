#include <iostream>

const int bankovky[]={1,2,5,10,20,50,100,500,1000,2000,5000};
const int indexbank=(sizeof(bankovky)/4)-1;

void vypiš(auto a, auto b){
    std::cout<<a<<"x "<<b<<" korun ceskych"<<std::endl;
}

int celoděl(int a, int b){
    return a/b;
}
void kolikjakýchbankovekv2(std::string l){
    int b=stoi(l);
    int i=indexbank;
    while (i>-1){
        vypiš(celoděl(b,bankovky[i]),bankovky[i]);
        b-=celoděl(b,bankovky[i])*bankovky[i];
        i-=1;
        }
    }
int main()
{
    kolikjakýchbankovekv2("13683");
    return 0;
}

/*

void kolikjakýchbankovekv1(int b){
    int i=10;
    int c=0;
    while (i>-1){
        if(b>=bankovky[i]){
            b-=bankovky[i];
            c+=1;
        }
        else{
            vypiš(c,bankovky[i]);
            c=0;
            i-=1;
        }
    }
}
*/