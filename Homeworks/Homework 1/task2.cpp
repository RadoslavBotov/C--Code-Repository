#include <iostream>

int cinTask2(int number)
{
    do
    {
        std::cout << "All digits ( must be at least 8): ";
        std::cin >> number;

    } while (number < 8);

    return number;
}

void inputBarcodeDigit(int &digit) // input for barcode, digit by digit
{
    do
    {
        std::cin >> digit;

        if (digit < 0)
            std::cout << " ! Digit must be bigger or equal to 0 !\n";

    } while (digit < 0);
}

void barcodeIdentifier(int numberOfDigits)
{
    int jamBlueberries = 0, jamPeaches = 0, jamRoseHip = 0;
    int digit, number = 0;
    int digitBr = 1, numberBr = 0;

    std::cout << "> Barcode digits:\n";
    
    while (numberOfDigits > 0)
    {
        inputBarcodeDigit(digit); // input for barcode, digit by digit

        if (digitBr == 4)
        {
            numberBr++;
            number = number * 10 + digit;
        }
        else
            digitBr++;

        if (numberBr == 4)
        {
            if (number % 7 == 0)
                jamBlueberries++;
            else if (number % 13 == 0)
                jamPeaches++;
            else if (number % 17 == 0)
                jamRoseHip++;

            number = 0;
            numberBr = 0;
            digitBr = 0;
        }

        numberOfDigits--;
    }

    std::cout << "Number of blueberrie jam: " << jamBlueberries << std::endl;   // Мармалад от боровинки
    std::cout << "Number of peach jam : " << jamPeaches << std::endl;           // Мармалад от праскови
    std::cout << "Number of rose hip jam : " << jamRoseHip << std::endl;        // Шипков мармалад
}

  
int main()
{
    int numberOfDigits = cinTask2(numberOfDigits);

    barcodeIdentifier(numberOfDigits);

    return 0;
}

/*
Една фабрика произвежда три различни вида мармалад – от боровинки, от праскови и шипков. Всеки мармалад има баркод – 8-цифрен 
идентификационен номер, в който е закодирана информацията за него: първите три цифри показват кода на държавата производител, 
следващите четири показват вида мармалад, а последната е контролна. Видът на мармалада се определя по следния начин:
ако четирицифреното число се дели на 7, то е от боровинки
ако четирицифреното число се дели на 13, то е от праскови
ако четирицифреното число се дели на 17, то е шипков

Системният администратор един ден натискал произволни бутони и случайно изтрил базата данни на фабриката. За щастие, се пази архив с 
всички налични баркодове. За нещастие, те не са отделени по никакъв начин, а представляват дълга поредица от цифри.
Сега фабриката за мармалад има нужда от помощ. На стандартния вход е подаден броят цифри в архива, а след това на един ред са изброени 
всички цифри, разделени с интервал. На стандартния изход да се изведат броя мармалади от всеки вид, съответно: боровинки, праскови и 
шипков.

Възможно е да има невалидни кодове, които не спадат към нито една категория мармалад.
* Задачата да се реши без използване на масиви.

Упътване:
За стойностите на редицата може да използвате директно оператора за въвеждане.

Пример:
Вход:
40
3 8 0 1 0 3 6 4 3 8 0 2 7 6 9 0 3 8 0 1 4 9 1 4 3 8 0 1 2 3 3 4 3 8 0 8 8 9 1 4
      1 0 3 6 * * * * 2 7 6 9         1 4 9 1         1 2 3 3         8 8 9 1

Изход:
Мармалад от боровинки: 2 
Мармалад от праскови: 1 
Шипков мармалад: 1

Обяснение:
Баркодовете са следните: 38010364, 38027690, 38014914, 38012334, 38088914
*/