// XYZ.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <vector>
#include <iostream>
using namespace std;




//Prototyp Taschenrechner



// hier werden die werte aufgerufen, die der Nutzer angibt und anschließend wieder zurueck gegeben
float InputNum(int number)
{
    float input = 0.0f;
    cout << "Gib die " << number << ". Zahl an: ";
    cin >> input;
    cout << "\n\n";

    return input;
}

//hier gibt der Nutzer die Operanten an die er verwenden moechte zeitgleich wird geprueft ob die Richtigen Parameter eingegeben werden
char InputOp(int number)
{
    char Operator = '+';
    cout << "Gib einen der Folgenden Operatoren ein \n +\n -\n *\n / \n";
    cin >> Operator;
    bool Opueberpruefung = true;
    while (Opueberpruefung) {
        if (Operator != '+' && Operator != '-' && Operator != '*' && Operator != '/')
        {
            cout << "Gib bitte ein Korrekten Parameter an ";
            cin >> Operator;
        }
        else {
            Opueberpruefung = false;
        }
    }
    return Operator;
}


// hier werden die Berechnungen ausgefuehrt. erst werden die werte uebermittelt und
// anschließend werden alle Operanten Multipliziert und Dividierd und sowohl die entsprechnden werte und Operanten aus den Jeweiligen Vectoren entfernt

float berechnung()
{
    float ergebnis = 0.01f;
    int i = 0;
    cout << "Geben sie an wie Viele operationen sie machen wollen : \n";
    cin >> i;
    int test = i;
    vector<float> input(i);
    vector<char> Operator(i - 1);
    int ab = 0;
    int check = 1;

    for (int x = 1; i >= 1; i--) {
        input[ab] = InputNum(x++);
        //  cout << "die " << x-1 << " zahl ist : " << input[ab]  << "\n\n";
        if (check != test)
        {
            Operator[ab] = InputOp(x);
            check++;

        }

        ab++;

    }
    
    //int nextnum = input[i + 1];
    //int lastnum = input[i - 1];

    
    if (!Operator.empty() && !input.empty()) {
        vector<char> gesuchteOperatoren = {'*','/'};
        
        vector<size_t> positionen;

        for (size_t i = 0; i < Operator.size(); i++) {

            if (find(gesuchteOperatoren.begin(), gesuchteOperatoren.end(), Operator[i]) != gesuchteOperatoren.end()) {
                positionen.push_back(i);
                
                
            }
        }

        if(!positionen.empty()){

            size_t pos_diff = 0;
            for (size_t i = 0; i < positionen.size(); i++) {
                //cout << "die positionen sind : " << endl << positionen[i] << endl;
                size_t pos = positionen[i] - pos_diff;
                    switch (Operator[pos]) {
                    case '*':
                        input[pos] = input[pos] * input[pos + 1];
                        
                        break;
                    case '/':
                        input[pos] = input[pos] / input[pos + 1];
                        
                        break;

                        
                    }
                    
                
                //cout << "ergebnis ist " << input[positionen[i]] << endl;
                Operator.erase(Operator.begin() + pos);
                input.erase(input.begin() + pos + 1);
                pos_diff ++ ;
            }
            
        }
        if (!Operator.empty()){
            size_t pos_diff = 0;
            while (!Operator.empty()) {
                size_t pos = pos_diff;

                switch (Operator[pos]) {
                case '+':
                    input[pos] = input[pos] + input[pos + 1];

                    break;
                case '-':
                    input[pos] = input[pos] - input[pos + 1];

                    break;


                }

                Operator.erase(Operator.begin() + pos);
                input.erase(input.begin() + pos + 1);
                

                // for (size_t i = 0; i < Operator.size(); i++ ){
                //     cout << Operator[i] << endl;
                // }
                
            }
            
        }

    }
    ergebnis = input[0];

    return ergebnis;

}




int main()
{
    float ergebnis = berechnung();

    cout << "das Ergebnis Lautet: " << endl  << "=============\n" << ergebnis << "\n=============";


    /*cout << "Diese Operanten wurden verwendet: \n";
    for (int testabfrage = 1; testabfrage < check; testabfrage++) {
        cout << Operator[testabfrage-1] << "\n";
    }
    cout << "welche zahl wollen sie abrufen bedenken sie sie haben " << test << " werte angegeben : ";
    int werteabfrage = 0;
    cin >> werteabfrage;
    cout << "die Zahl in der " << werteabfrage << " Position ist : " << input[werteabfrage-1];
    */
}