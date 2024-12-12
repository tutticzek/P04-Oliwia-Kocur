//kolejna wersja programu, tym razem z wektorami
#include <iostream>//basic strumień wejœcia-wyjœcia
#include <ctime>   //do losowego ziarna
//#include <iomanip> //do robienia setw()
#include <cstdlib> //do robienia srand()/rand()
#include <vector>  //do robienia wektorów
using namespace std;

int N=10, X=10; //N-rozmiar tablicy ,X-zakres wartości

void funkcja (int D[], int M)  //funkcja zapisująca indeksy liczb a następnie szukająca tych spełniających kryteria
{
    vector<vector<int>>indeksy(X, vector<int> (1)); //wektor dwuwymiarowy na wartości i ich indeksy
    vector<int>wynik; //osobny wektor na wyniki

//numerowanie kolumn
    for(int i=0; i<X; i++){
        indeksy[i][0]=i;}

//zapisywanie indeksów w kolumnach poszczególnych wartości
    for(int i=0; i<N; i++){
        indeksy[D[i]].push_back(i+1);}

//sprawdzanie czy odległość między indeksami jest nie większa niż M
    for(int i=0; i<X; i++){
    if(indeksy[i].size()>2){
        for(int k=2; k<=indeksy[i].size(); k++){
           if(indeksy[i][k]-indeksy[i][k-1]<=M)
            wynik.push_back(i);
            break; //przerwanie po znalezieniu wartości żeby nie wypisywać ich wielokrotnie
            }
        }
    }
/*
//podglądowe wypisywanie tablicy (wektorów) indeksów
    for(int i=0; i<indeksy.size();i++){
        cout<<endl;
        for(int j=0;j<indeksy[i].size();j++)
            cout<<indeksy[i][j]<<" ";}
*/

//wypisywanie wyników
    cout<<endl;
    if(wynik.size()==0){
        cout<<"brak elementow spelniajacych zadane kryteria"<<endl;
    }else {
        cout<<"elementy spelniajace kryteria: ";
        for(int i=0; i<wynik.size(); i++)
            cout<<wynik[i]<<" ";
    }
}

int main(){

int D[N],M;  //tworzenie tablicy i zmiennej M
srand( time(NULL)); //ziarno dla generatora pseudolosowych liczb

for(int i = 0; i < N; i++){
    D[i] = rand() % X;
    cout<<D[i]<<" ";}  //losowanie wartości do tablicy D

cout<<endl<<"M: ";
cin>>M;    //definiowanie M

funkcja(D,M); //funkcja szukająca wyników

cout<<endl;
    return 0;
}

