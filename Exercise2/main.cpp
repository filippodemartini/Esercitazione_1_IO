#include <iostream>
#include <fstream>
#include <iomanip>
// funzione che trasforma i valori dall'intervallo [1,5] all'intervallo [-1,2]
double cambiointervallo(double valore){
    double valoremappato = ((valore-1.)*(2.+1.))/(5.-1.)-1.;
    return valoremappato;
}

int main()
{
    // apro il file da leggere e faccio un controllo
    std::string nomefile = "data.csv";
    std::ifstream ifstr(nomefile);
    if(ifstr.fail())
    {
        std::cerr << "Il file non esiste " << std::endl;
        return 1;
    }
    // apro il file di output
    std:: ofstream file_di_output("result.csv");

    // capo linea
    file_di_output << "# N Mean" << "\n";

    // inizializzo le variabili
    double valore =0.;
    double somma=0.;
    unsigned int n=0;
    double media =0.;

    while (ifstr >> valore) {
        valore=cambiointervallo(valore);
        somma +=valore;
        n++;
        media=somma/n;
        file_di_output << n << " " << std::scientific << std:: setprecision(16) << media << std:: endl;
    }

    ifstr.close();
    file_di_output.close();

    return 0;
}
