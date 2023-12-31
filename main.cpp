#include <iostream>
using namespace std;

/*
    Redes de computacion I

    José González 15-10627
    Ana Santos. 17-10602
    Amaranta Villegas 16-11247

*/

class WaterBottle {
    private:
        int Capacity;
        int CurrentValue;
    
    public:
        WaterBottle(int capacity) {
            Capacity = capacity;
            CurrentValue=0;
        }
    
        void fill() {
            setCurrentValue(Capacity);
        }

        void empty() {
            setCurrentValue(0);
        }

        int getCapacity() {
            return Capacity;
        }

        int getCurrentValue() {
            return CurrentValue;
        }


        void setCapacity(int capacity) {
            Capacity = capacity;
        }


        void setCurrentValue(int currentValue) {
            CurrentValue = currentValue;
        }

     
};

 /*
            La primera botella es la que es vaciada sobre la segunda botella
            Se obtienen los valores de ambas botellas, si la suma del valor actual
            de la primera y segunda botella es menor a la capacidad de la segunda botella
            entonces se le asigna ese valor al valor actual de la botella 2 y se vacia la botella 1.
            En caso de que la suma sea mayor o igual a la capacidad de la botella 2, entonces se le asigna
            el valor de la capacidad de la botella 2 al valor actual de la botella 2 y se realiza el calculo
            del valor que hizo falta de la botella 2 para ser llenada.
        */
        void fillOtherBottle(WaterBottle &firstBottle, WaterBottle &secondBottle) {
            int firstBottleCapacity = firstBottle.getCapacity();
            int secondBottleCapacity = secondBottle.getCapacity();
            int firstBottleCurrentValue = firstBottle.getCurrentValue();
            int secondBottleCurrentValue = secondBottle.getCurrentValue();

            if (firstBottleCurrentValue + secondBottleCurrentValue < secondBottleCapacity) {
                secondBottle.setCurrentValue(firstBottleCurrentValue + secondBottleCurrentValue);
                firstBottle.setCurrentValue(firstBottleCurrentValue - secondBottle.getCurrentValue());
            } else {
                secondBottle.setCurrentValue(secondBottleCapacity);
                firstBottle.setCurrentValue(firstBottleCapacity - (secondBottleCapacity - secondBottleCurrentValue ));
            }
        }

int main()
{
    cout << "Test de las propiedades de esta clase de WaterBottle" << endl;
    cout << "Inicializacion de las botellas de agua:" << endl;
    WaterBottle bottle1(5);
    WaterBottle bottle2(3);

    cout << "Capacidad de la botella 1: " << bottle1.getCapacity() << endl;
    cout << "Capacidad de la botella 2: " << bottle2.getCapacity() << endl;

    cout << "Vamos a llenar la primera botella para vaciarlo sobre la segunda" << endl;

    bottle1.fill();
    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;

    cout << "Transvasar de la botella 1 a la botella 2:  Primera vez" << endl;
    fillOtherBottle(bottle1, bottle2);

    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;

    bottle2.empty();
    cout << "Vaciamos la botella 2: Primera vez"  << endl;
    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;

    cout << "Transvasar de la botella 1 a la botella 2: Segunda vez" << endl;
    fillOtherBottle(bottle1, bottle2);
    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;

    cout << "Llenamos la botella 1: Segunda vez" << endl;
    bottle1.fill();
    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;
    
    cout << "Transvasar de la botella 1 a la botella 2: Tercera vez" << endl;
    fillOtherBottle(bottle1, bottle2);

    cout << "Valor actual de la botella 1: " << bottle1.getCurrentValue() << endl;
    cout << "Valor actual de la botella 2: " << bottle2.getCurrentValue() << endl;

    if (bottle1.getCurrentValue() == 4 ) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    return 0;
}


