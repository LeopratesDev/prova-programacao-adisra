#include <iostream>
#include <string>
using namespace std;

class Veiculo {
protected:
    string chassi;
    string motor;
    double custoProducao;
    double imposto; // percentual do imposto (ex: 0.20 = 20%)
public:
    Veiculo(string ch, string mt, double custo, double imp){
        chassi = ch;
        motor = mt;
        custoProducao = custo;
        imposto = imp;
    }

    double custoVenda(){
        // imposto e lucro sao sobre o custo de producao, nao sobrepostos
        double valorImposto = custoProducao * imposto;
        double lucro = custoProducao * 0.25;
        return custoProducao + valorImposto + lucro;
    }

    void mostrarInfo(){
        cout << "Chassi: " << chassi << endl;
        cout << "Motor: " << motor << endl;
        cout << "Custo producao: R$" << custoProducao << endl;
        cout << "Custo venda: R$" << custoVenda() << endl;
    }
};

// carro flex - imposto 20%
class CarroFlex : public Veiculo {
    int portas;
    double cilindrada;
public:
    CarroFlex(string ch, string mt, int p, double cil, double custo)
        : Veiculo(ch, mt, custo, 0.20){
        portas = p;
        cilindrada = cil;
    }

    void mostrar(){
        cout << "=== Carro Flex ===" << endl;
        cout << "Portas: " << portas << " | Cilindrada: " << cilindrada << endl;
        mostrarInfo();
        cout << endl;
    }
};

// carro diesel - imposto 30% (20% base + 10% por poluicao)
class CarroDiesel : public Veiculo {
    double capCarga;
    double volCacamba;
public:
    CarroDiesel(string ch, string mt, double carga, double cacamba, double custo)
        : Veiculo(ch, mt, custo, 0.30){
        capCarga = carga;
        volCacamba = cacamba;
    }

    void mostrar(){
        cout << "=== Carro Diesel ===" << endl;
        cout << "Carga: " << capCarga << "kg | Cacamba: " << volCacamba << "L" << endl;
        mostrarInfo();
        cout << endl;
    }
};

// carro eletrico - imposto 10% (20% base - 10% incentivo)
class CarroEletrico : public Veiculo {
    double potencia;
    double duracaoBat;
public:
    CarroEletrico(string ch, string mt, double pot, double bat, double custo)
        : Veiculo(ch, mt, custo, 0.10){
        potencia = pot;
        duracaoBat = bat;
    }

    void mostrar(){
        cout << "=== Carro Eletrico ===" << endl;
        cout << "Potencia: " << potencia << "cv | Bateria: " << duracaoBat << "h" << endl;
        mostrarInfo();
        cout << endl;
    }
};

int main(){
    CarroFlex f1("CH001", "MT001", 4, 1.6, 50000);
    CarroDiesel d1("CH002", "MT002", 1200, 500, 80000);
    CarroEletrico e1("CH003", "MT003", 200, 12, 120000);

    f1.mostrar();
    d1.mostrar();
    e1.mostrar();

    return 0;
}
