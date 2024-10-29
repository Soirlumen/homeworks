#include <iostream>
#include <string>

//pole bankovek a jeji velikost
const int bankovky[]={1,2,5,10,20,50,100,500,1000,2000,5000};
const int indexbank=(sizeof(bankovky)/4)-1;

//(zbytecne slozita) funkce na vypsani vseho druhu
template <typename T>
void vypiš(T t) 
{
    std::cout << t;
}
template<typename T, typename... Args>
void vypiš(T t, Args... args)
{
    std::cout << t;

    vypiš(args...) ;
}
//celociselne deleni
int celoděl(int a, int b){
    return a/b;
}
//funkce ktera bere vstup z terminalu, prevede ho na int a catchne pripadne, pokud cislo neni platne nebo moc velke
int vstup(){
    std::string l;
    vypiš("Zadej cele kladne cislo: ");
    std::cin >> l;
    try {
        int b = std::stoi(l);
        if (b > 0) {
            return b;
        } else {
            vypiš("zadane cislo '",b,"' neni kladne, zkus znovu","\n");
        }
    } catch (std::out_of_range&) {
        vypiš("cislo moc velke, zkus znovu","\n");
    }
    catch (std::invalid_argument){
        vypiš("zadana vec neplatna, zkus znovu","\n");
    }
    return vstup();
}
//funkce pro pocitani bankovek
void kolikjakýchbankovek(){
    unsigned int b=vstup();
    int i=indexbank;
    while (i>-1){
        vypiš(celoděl(b,bankovky[i]), "x ",bankovky[i], " korun ceskych","\n");
        b-=celoděl(b,bankovky[i])*bankovky[i];
        i-=1;
        }
    }
int main()
{
    kolikjakýchbankovek();
    return 0;
}