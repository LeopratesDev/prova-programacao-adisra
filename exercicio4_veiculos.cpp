/*
    Exercicio 4 - Modelagem de classes para fabrica de automoveis
    Heranca: Veiculo (classe base) -> CarroFlex, CarroDiesel, CarroEletrico
    Cada tipo tem seu imposto e todos compartilham lucro de 25%.
    Custo de venda = custo de producao + imposto + lucro
    (imposto e lucro sao calculados sobre o custo de producao, sem sobreposicao)
*/

#include <iostream>
#include <string>
using namespace std;

class Veiculo {
protected:
    string numeroChassi;
    string numeroMotor;
    double custoProducao;
    double taxaImposto;

public:
    Veiculo(string chassi, string motor, double custo, double imposto)
        : numeroChassi(chassi), numeroMotor(motor), custoProducao(custo), taxaImposto(imposto) {}

    double calcularCustoVenda() {
        double imposto = custoProducao * taxaImposto;
        double lucro = custoProducao * 0.25;
        return custoProducao + imposto + lucro;
    }

    void exibirCustoVenda() {
        cout << "Chassi: " << numeroChassi << endl;
        cout << "Motor: " << numeroMotor << endl;
        cout << "Custo de producao: R$ " << custoProducao << endl;
        cout << "Imposto (" << (taxaImposto * 100) << "%): R$ " << (custoProducao * taxaImposto) << endl;
        cout << "Lucro (25%): R$ " << (custoProducao * 0.25) << endl;
        cout << "Custo de venda: R$ " << calcularCustoVenda() << endl;
    }
};

class CarroFlex : public Veiculo {
private:
    int numeroPortas;
    double cilindrada;

public:
    CarroFlex(string chassi, string motor, int portas, double cil, double custo)
        : Veiculo(chassi, motor, custo, 0.20), numeroPortas(portas), cilindrada(cil) {}

    void exibir() {
        cout << "--- Carro Flex ---" << endl;
        cout << "Portas: " << numeroPortas << endl;
        cout << "Cilindrada: " << cilindrada << endl;
        exibirCustoVenda();
        cout << endl;
    }
};

class CarroDiesel : public Veiculo {
private:
    double capacidadeCarga;
    double volumeCacamba;

public:
    CarroDiesel(string chassi, string motor, double carga, double cacamba, double custo)
        : Veiculo(chassi, motor, custo, 0.30), capacidadeCarga(carga), volumeCacamba(cacamba) {}

    void exibir() {
        cout << "--- Carro Diesel ---" << endl;
        cout << "Capacidade de carga: " << capacidadeCarga << " kg" << endl;
        cout << "Volume da cacamba: " << volumeCacamba << " litros" << endl;
        exibirCustoVenda();
        cout << endl;
    }
};

class CarroEletrico : public Veiculo {
private:
    double potencia;
    double duracaoBateria;

public:
    CarroEletrico(string chassi, string motor, double pot, double bateria, double custo)
        : Veiculo(chassi, motor, custo, 0.10), potencia(pot), duracaoBateria(bateria) {}

    void exibir() {
        cout << "--- Carro Eletrico ---" << endl;
        cout << "Potencia: " << potencia << " cv" << endl;
        cout << "Duracao da bateria: " << duracaoBateria << " horas" << endl;
        exibirCustoVenda();
        cout << endl;
    }
};

int main() {
    // Exemplos de uso com valores simulados

    CarroFlex flex("CH-001", "MT-001", 4, 1.6, 50000.00);
    CarroDiesel diesel("CH-002", "MT-002", 1200.0, 500.0, 80000.00);
    CarroEletrico eletrico("CH-003", "MT-003", 200.0, 12.0, 120000.00);

    flex.exibir();
    diesel.exibir();
    eletrico.exibir();

    return 0;
}

/*
    Exemplo de saida:

    --- Carro Flex ---
    Portas: 4
    Cilindrada: 1.6
    Chassi: CH-001
    Motor: MT-001
    Custo de producao: R$ 50000
    Imposto (20%): R$ 10000
    Lucro (25%): R$ 12500
    Custo de venda: R$ 72500

    --- Carro Diesel ---
    Capacidade de carga: 1200 kg
    Volume da cacamba: 500 litros
    Chassi: CH-002
    Motor: MT-002
    Custo de producao: R$ 80000
    Imposto (30%): R$ 24000
    Lucro (25%): R$ 20000
    Custo de venda: R$ 124000

    --- Carro Eletrico ---
    Potencia: 200 cv
    Duracao da bateria: 12 horas
    Chassi: CH-003
    Motor: MT-003
    Custo de producao: R$ 120000
    Imposto (10%): R$ 12000
    Lucro (25%): R$ 30000
    Custo de venda: R$ 162000
*/
