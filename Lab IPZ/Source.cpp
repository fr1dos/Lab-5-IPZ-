#include <iostream>
#include <fstream>
using namespace std;

int input(double& x1, double& x2, double& step, double& n, int& choose) {		// Функция для ввода данных
    cout << "input start: " << endl;
    cin >> x1;
    cout << "input end:" << endl;
    cin >> x2;
    cout << "Do you want to record the results?\nYes - 1; No - 0" << endl;
    cin >> choose;


    if (x2 < x1) {
        cout << "end mast be higer than start";
        return 1;
    }

    cout << "input step:" << endl;
    cin >> step;

    if (step > (x2 - x1)) {
        cout << "step to high";
        return 1;
    }

    else if (((x2 - x1) / step) - (int)((x2 - x1) / step) != 0) {
        cout << "step not multiple" << endl;
        return 1;
    }

    cout << "input n: ";
    cin >> n;
}

void checkValidParams(double n) {  // Проверка n на int
    if (n != int(n)) {
        throw "n must be integer";
    }
}

void Filewrite(double x1, double y) // Функция для записи в файл
{
    ofstream file;
    file.open("test.txt");
    file << "x = " << x1 << ", y = " << y << endl;
    file.close();
};

double add(double x, double n) {		// Функция при х <= 0 
    double y = 0;
    for (int i = 2; i <= (n - 1); i++)
    {
        y += (x - 1) / i;
    }
    return y;
}

double mult(double x, double n) {		// Функция при x > 0 
    double y1 = 1;
    for (int i = 0; i <= (n - 1); i++)
    {
        double s = 0;
        for (int j = 0; j <= i; j++)
        {
            s += (i + 1) / (j + x);
        }
        y1 *= s;
    }
    return y1;
}

double calculate(double x, double n) {
    double y = 0;

    if (x <= 0) {
        y = add(x, n);
    }
    else {
        y = mult(x, n);
    }

    return y;
}

int main()
{
    double x1, x2, step, n, s = 0;
    int choose = 0;

    try {
        input(x1, x2, step, n, choose);
        checkValidParams(n);

        for (double x = x1; x <= x2; x += step) 
        {
            cout << "x = " << x << "\t" << "y = " << calculate(x, n) << endl;
            if (choose == 1) {
                Filewrite(x1, calculate(x,n));
            }
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...) 
    {
        cout << "Unknown error" << endl;
        return -2;
    }
}