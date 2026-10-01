#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

class napitki1 {
private:
    string namedrink;
    float volute;
    int Container;
    bool isCarbonated;

public:
    string TextContainer() const {
        if (Container == 0) return "Banka";
        else if (Container == 1) return "Bytalka";
        else if (Container == 2) return "Stakan";//реализация выбора для пользователя
    }
    friend ostream& operator<<(ostream& os, const napitki1& drink) {
        os << "\n------------------------\n";
        os << "         napitok          \n";
        os << " name: " << drink.namedrink << "\n";
        os << " vol: " << drink.volute << "\n";
        os << " tara: " << drink.TextContainer() << "\n";
        os << " Carbonated: " << (drink.isCarbonated ? "s gas" : "no gas") << "\n";
        os << "---------------------------\n";//доп перегрузка по заданию(ввщд данных)
        return os;
    }

    friend istream& operator>>(istream& is, napitki1& drink) {
        cout << "name: "; is >> drink.namedrink;
        cout << "vol (ml): "; is >> drink.volute;
        cout << "tara (0-banka, 1-butylka, 2-stakan): "; is >> drink.Container;
        cout << "s gaz? (y/n): ";
        char ch; is >> ch;
        drink.isCarbonated = (ch == 'y');
        return is;//тоже доп перегруз, но на вывод
    }
    //конструктор с параметров
    napitki1(string name, float vol, int Cont, bool isCarbon) {
        namedrink = name;
        volute = vol;
        Container = Cont;
        isCarbonated = isCarbon;//перевод на чел тему для работы проги(поля тополя и тд)
    }
    //конструктор без параметров
    napitki1() : namedrink(""), volute(0.0), Container(0), isCarbonated(false) {
    cout << "Vazvan konstryctor bez parametrov\n";//новое
    }
    //конструктор копирования
    napitki1(const napitki1& other) :
    namedrink(other.namedrink),
    volute(other.volute),
    Container(other.Container),
    isCarbonated(other.isCarbonated) {
    cout << "Vazvan konstryctor kopirovania\n";
    }//новое
    ~napitki1() {
    cout << "Vazvan destructor dla " << namedrink << "\n";
    }//пустой деструктор, тк нет динамической шляпы, но зачем то нужно

    //реализация всех методов
    void SvetOtobragenie() {
        cout << "Vazvan metod SvetOtobragenie()\n";
        if (Container == 1) {
            cout << "Svet est\n";
        } else if (Container == 2) {
            cout << "Svet est\n";
        } else if (Container == 0) {
            cout << "Svet no\n";
        }
    }

    void PopitChytka() {
        cout << "Vazvan metod PopitChytka()\n";
        int glotok = 20;
        if (volute >= glotok) {
            volute -= glotok;
            cout << "vkysno, ostalos " << volute << " ml\n";
        } else {
            cout << "ti vse vipil\n";
            volute = 0;
        }
    }

    void Aromat() {
        cout << "Vazvan metod Aromat()\n";
        cout << "vkysno pahnet\n";
    }

    void PoslehatShipenie() {
        cout << "Vazvan metod PoslehatShipenie()\n";
        if (isCarbonated) {
            cout << "shipit";
        } else {
            cout << "vse tiho";
        }
    }

    //перегруз ПО ЗАДАНИЮ(смещать напитки)
    napitki1 operator+(const napitki1& other) {
        cout << "Vazvan metod operator+\n";
        string newName = namedrink + "+" + other.namedrink;
        float newVol = volute + other.volute;
        int newContainer = 1;//всегда бутылка, идет константой
        bool newGas = isCarbonated or other.isCarbonated;
        return napitki1(newName, newVol, newContainer, newGas);
    }

    //перегруз ПО ЗАДАНИЮ(разбавить напитки)
    napitki1& operator-() {
     cout << "Vazvan metod operator-\n";
    cout << "\n>>> DILUTE <<<" << endl;
    volute *= 1.2f;               // увеличиваем объём на 20%
    if (isCarbonated) {
        int chance = rand() % 100; // случайное число от 0 до 99
        if (chance < 50) {
            isCarbonated = false;
            cout << "Gasa net" << endl;
        } else {
            cout << "Gas esti" << endl;
        }
            }else {
                cout << "Napitok bez gaza, tolko razbavlen." << endl;
            }
        return *this;// возвращаем ссылку на текущий объект
        }

    // присваивание напитков
    napitki1& operator=(const napitki1& other) {
        cout << "Vyzvan operator=\n";
        if (this != &other) {
            namedrink = other.namedrink;
            volute = other.volute;
            Container = other.Container;
            isCarbonated = other.isCarbonated;
        }
    return *this;
    }

    // перегрузка операторов сравнения
    bool operator==(const napitki1& other) const {
        cout << "Vyzvan operator==\n";
        return (namedrink == other.namedrink &&
                volute == other.volute &&
                Container == other.Container &&
                isCarbonated == other.isCarbonated);
    }

    //вывод инфы по напиткам
    void showInfo() {
        cout << "\n-------------------------" << endl;
        cout << "       napitok            " << endl;
        cout << " name: " << namedrink << endl;
        cout << " vol: " << volute << " ml" << endl;
        cout << " tara: " << TextContainer() << endl;
        cout << " Carbonated: " << (isCarbonated ? "s gas" : "no gas") << endl;
        cout << "--------------------------" << endl;
    }
    // Методы установки и получения значений полей
    void setName(const string& name) { namedrink = name; }
    string getName() const { return namedrink; }

    void setVolume(float vol) { volute = vol; }
    float getVolume() const { return volute; }

    void setContainer(int cont) { Container = cont; }
    int getContainer() const { return Container; }

    void setCarbonated(bool carbon) { isCarbonated = carbon; }
    bool getCarbonated() const { return isCarbonated; } // или isCarbonated()
};

//функция для очистики потока, если пользователь ввел неккоретктное значение(БЕЗ НЕЕ ВСЕ ЛОМАЕТСЯ)
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    srand(time(0));
    int choice;
    bool programRunning = true;

    string name1, name2;
    float vol1, vol2;
    int cont1, cont2;
    char gas1, gas2;
    bool fizzy1, fizzy2;
    cout << "=== CREATE FIRST DRINK ===" << endl;

    // Ввод названия первого
    cout << "name: ";
    getline(cin, name1);

    // Ввод объёма первого
    while (true) {
        cout << "vol (ml): ";
        string line;
        getline(cin, line);//считать фулл строчку.getline-гарантия, что в буфере будет пусто
        size_t pos;
        try {
            vol1 = stof(line, &pos);//stof-преобразование строки в тип флоат
            if (pos == line.length() and vol1 > 0) break;//ес вся строка число и оно > - все хорошо, иначе break
            else cout << "Error! Vvedi polozhitelnoe chislo.\n";//ЛОМАЕТСЯ ВООБЩЕ ВЕСЬ ВЫВОД
        } catch (...) {//обяз тема. по сути catch-перехват всех исключений из stof, что дает гарантию ввода только 0 1 2
            cout << "Error! Vvedi chislo.\n";
        }
    }

    // Ввод тары первого (только 0,1,2)
    while (true) {
        cout << "tara (0-banka, 1-bytalka, 2-stakan): ";
        string line;
        getline(cin, line);
        if (line.length() == 1 and line[0] >= '0' and line[0] <= '2') {//диапозон чисел, которы удовлетворяют
            cont1 = line[0] - '0';//преобразование символьного чсила в норм цифру('2'-'0'=50–48=2)
            break;
        } else {
            cout << "error. tolko 0, 1 ili 2.\n";
        }
    }

    // Ввод газа первого (только y/n)
    while (true) {
        cout << "s gaz? (y/n): ";
        string line;
        getline(cin, line);
        if (line.length() == 1 and (line[0] == 'y' or line[0] == 'n')) {//ВЕСЬ ЭТОТ БЛОК- ОБЯЗ ПРОВЕРКА(ВСЕ ЛОМАЕТСЯ)
            fizzy1 = (line[0] == 'y');
            break;
        } else {
            cout << "error. vvedi y ili n.\n";
        }
    }

    // cout << "\n=== CREATE SECOND DRINK ===" << endl;
    cout << "\nв этой строчке я проверяю работу гита" << endl;


    // Ввод названия второго
    cout << "name: ";
    getline(cin, name2);

    // Ввод объёма второго
    while (true) {
        cout << "vol (ml): ";
        string line;
        getline(cin, line);
        size_t pos;
        try {
            vol2 = stof(line, &pos);
            if (pos == line.length() and vol2 > 0) break;
            else cout << "Error! Vvedi polozhitelnoe chislo.\n";
        } catch (...) {
            cout << "Error! Vvedi chislo.\n";
        }
    }

    // Ввод тары второго
    while (true) {
        cout << "tara (0-banka, 1-bytalka, 2-stakan): ";
        string line;
        getline(cin, line);
        if (line.length() == 1 and line[0] >= '0' and line[0] <= '2') {
            cont2 = line[0] - '0';
            break;
        } else {
            cout << "error. tolko 0, 1 ili 2.\n";
        }
    }

    // Ввод газа второго
    while (true) {
        cout << "s gaz? (y/n): ";
        string line;
        getline(cin, line);
        if (line.length() == 1 and (line[0] == 'y' or line[0] == 'n')) {
            fizzy2 = (line[0] == 'y');
            break;
        } else {
            cout << "error. vvedi y ili n.\n";
        }
    }

    // Создаём напитки
    napitki1 drink1(name1, vol1, cont1, fizzy1);
    napitki1 drink2(name2, vol2, cont2, fizzy2);

    cout << "\n=== DRINKS CREATED ===" << endl;
    drink1.showInfo();
    drink2.showInfo();
    // Главное меню
    while (programRunning) {
        cout << "Chto delaem? (vyberi tsifru):" << endl;
        cout << "1 - Posmotret otrazhenie (napitok 1)" << endl;
        cout << "2 - Posmotret otrazhenie (napitok 2)" << endl;
        cout << "3 - Otpit' nemnogo (napitok 1)" << endl;
        cout << "4 - Otpit' nemnogo (napitok 2)" << endl;
        cout << "5 - Ponyukhat' (napitok 1)" << endl;
        cout << "6 - Ponyukhat' (napitok 2)" << endl;
        cout << "7 - Poslushat' shipenie (napitok 1)" << endl;
        cout << "8 - Poslushat' shipenie (napitok 2)" << endl;
        cout << "9 - Smeshat' napitki (+)" << endl;
        cout << "10 - Razbavit' vodoy (napitok 1) (-)" << endl;
        cout << "11 - Razbavit' vodoy (napitok 2) (-)" << endl;
        cout << "12 - Pokazat' infu o napitkakh" << endl;
        cout << "13 - Prisvoit napitok 2 k napitku 1 (=)" << endl;
        cout << "14 - Sravnit napitki (==)" << endl;
        cout << "0 - Vykhod" << endl;
        cout << "Tvoy vybor: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Oshibka! Nuzhno vvesti chislo.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: drink1.SvetOtobragenie(); break;
            case 2: drink2.SvetOtobragenie(); break;
            case 3: drink1.PopitChytka(); break;
            case 4: drink2.PopitChytka(); break;
            case 5: drink1.Aromat(); break;
            case 6: drink2.Aromat(); break;
            case 7: drink1.PoslehatShipenie(); break;
            case 8: drink2.PoslehatShipenie(); break;
            case 9: {
                napitki1 cocktail = drink1 + drink2;
                cout << "\nnew yapitor!" << endl;
                cocktail.showInfo();
                cout << "\nsohranit koktel kak napitok? (y/n): ";
                char save;
                cin >> save;
                if (save == 'y') {
                    drink1 = cocktail;
                    cout << "sdelal" << endl;
                }
                break;
            }
            case 10: -drink1; break;
            case 11: -drink2; break;
            case 12:
                cout << "\n=== tekyhee sostoanie ===" << endl;
                drink1.showInfo();
                drink2.showInfo();
                break;
            case 13:
                drink2 = drink1;  
                cout << "Prisvoil napitok 2 k napitku 1" << endl;
                break;
            case 14:
            if (drink1 == drink2) {  
                cout << "Napitki odinakovye" << endl;
                } else {
                    cout << "Napitki raznye" << endl;
                }
                break;  
            case 0:
                programRunning = false;
                cout << "poka poka" << endl;
                break;
            default:
                cout << "error. ot 1 do 12" << endl;
        }

        cout << "\nnagmi Enter htob proda";
        cin.ignore();
        cin.get();
    }

    return 0;
}