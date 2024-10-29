#include <iostream>

const int bankovky[]={1,2,5,10,20,50,100,500,1000,2000,5000};
const int indexbank=(sizeof(bankovky)/4)-1;

void vypiš(auto a, auto b){
    std::cout<<a<<"x "<<b<<" korun ceskych"<<std::endl;
}

int celoděl(int a, int b){
    return a/b;
}
int vstup(){
    std::string l;
    std::cout<<"zadej cele kladne cislo: ";
    std::cin>>l;
    int b=stoi(l);
    if (b>0){
        return b;
    }
    else{
        std::cout<<" zadane cislo '"<<b<<"neni cele kladne, zkus to znovu"<<std::endl;
        vstup();
    }
}
void kolikjakýchbankovekv2(){
    int b=vstup();
    int i=indexbank;
    while (i>-1){
        vypiš(celoděl(b,bankovky[i]),bankovky[i]);
        b-=celoděl(b,bankovky[i])*bankovky[i];
        i-=1;
        }
    }
int main()
{
    kolikjakýchbankovekv2();
    return 0;
}