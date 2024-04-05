#include <iostream>;
#include "windows.h";
#include <string>;
using namespace std;

struct Student {
    string name;
    unsigned int age;
    unsigned int raiting;
};

struct BankAccount {
    string name;
    unsigned int number;
    int balance;
};

struct Product {
    string name;
    unsigned int price;
    unsigned int count;
};

struct Book {
    string name;
    string author;
    unsigned int year;
};

struct Worker {
    string name;
    string position;
    unsigned int salary;
};

struct BoxSize {
    float x;
    float y;
    float z;
};

Product* productPlusOne(Product* product, unsigned int& count) {
    count++;
    Product *tempProduct = new Product[count];
    if (count > 1) for (int i = 0; i < count - 1; i++) tempProduct[i] = product[i];
    delete [] product;
    return tempProduct;
}

void addProduct(Product* product, unsigned int id) {
    cout << "Введіть назву " << (id + 1) << "-го товару: ";
    cin >> product[id].name;
    cout << "Введіть ціну товару \"" << product[id].name << "\": ";
    cin >> product[id].price;
    cout << "Введіть кількість товару \"" << product[id].name << "\": ";
    cin >> product[id].count;
    cout << endl;
    id++;
}

Book* BookPlusOne(Book *book, unsigned int& count) {
    count++;
    Book *tempBook = new Book[count];
    if (count > 1) for (int i = 0; i < count - 1; i++) tempBook[i] = book[i];
    delete[] book;
    return tempBook;
}

void addBook(Book* book, unsigned int id) {
    cout << "Введіть назву " << (id + 1) << "-ї книги: ";
    cin >> book[id].name;
    cout << "Введіть ім'я автора книги \"" << book[id].name << "\": ";
    cin >> book[id].author;
    cout << "Введіть рік видання книги \"" << book[id].name << "\": ";
    cin >> book[id].year;
    cout << endl;
    id++;
}

Worker* WorkerPlusOne(Worker* worker, unsigned int& count) {
    count++;
    Worker* tempWorker = new Worker[count];
    if (count > 1) for (int i = 0; i < count - 1; i++) tempWorker[i] = worker[i];
    delete[] worker;
    return tempWorker;
}

void addWorker(Worker* worker, unsigned int id) {
    cout << "Введіть імя " << (id + 1) << "-го працівника: ";
    cin >> worker[id].name;
    cout << "Введіть посаду працівника \"" << worker[id].name << "\": ";
    cin >> worker[id].position;
    cout << "Введіть зарплатню працівника \"" << worker[id].name << "\": ";
    cin >> worker[id].salary;
    cout << endl;
    id++;
}

float getAvg(int* array, int &count) {
    int sum = 0;
    for (int i = 0; i < count; i++) sum += array[i];
    return (float) sum/count;
}

void divideTwo(BoxSize *size) {
    size->x = size->x / 2;
    size->y = size->y / 2;
    size->z = size->z / 2;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //1. Облік студентів:
    //Створіть структуру Студент, яка містить поля для імені, віку та середнього балу студента. 
    // Напишіть програму, яка дозволяє користувачу вводити інформацію про студентів та виводити її на екран.

    const int studentsCount = 2;
    Student student[studentsCount];

    //Вводимо список студентів
    for (int i = 0; i < studentsCount; i++) {
        cout << "Введіть ім'я " << (i + 1) << "-го студента: ";
        cin >> student[i].name;
        cout << "Введіть вік студетна \"" << student[i].name << "\": ";
        cin >> student[i].age;
        cout << "Введіть середній бал студента \"" << student[i].name << "\": ";
        cin >> student[i].raiting;
        cout << endl;
    }

    //Виводимо список студентів на екран
    cout << "Список студентів:" << endl;
    for (int i = 0; i < studentsCount; i++) {
        cout << student[i].name << ": вік: " << student[i].age << "; середній бал: " << student[i].raiting << "." << endl;
    }
    cout << endl;


    //2. Управління рахунком в банку:
    //Створіть структуру Банківський рахунок, яка містить поля для імені власника рахунку, номера рахунку та балансу.
    // Напишіть програму, яка дозволяє користувачу вносити гроші на рахунок, знімати їх та виводити баланс.

    BankAccount bankAccount;

    //Вводимо інформацію про стан рахунку
    cout << "Введіть ім'я власника рахунку: ";
    cin >> bankAccount.name;
    cout << "Введіть номер рахунку: ";
    cin >> bankAccount.number;
    cout << "Введіть баланс рахунку: ";
    cin >> bankAccount.balance;
    cout << endl;

    //Вносимо гроші на рахунок
    unsigned int sum = 0;
    cout << "Введіть суму поповнення рахунку: ";
    cin >> sum;
    bankAccount.balance += sum;
    cout << "Сума на рахунку: " << bankAccount.balance << endl;

    //Знімаємо гроші з рахунку
    cout << "Введіть суму зняття з рахунку: ";
    cin >> sum;
    bankAccount.balance -= sum;
    cout << "Сума на рахунку: " << bankAccount.balance << endl;

    //Виводимо баланс
    cout << "Рахунок на ім'я \"" << bankAccount.name << "\"; номер рахунку: " << bankAccount.number << "; баланс: " << bankAccount.balance << "." << endl << endl;

    //3. Облік товарів на складі:
    //Створіть структуру Товар, яка містить поля для назви товару, його ціни та кількості на складі.
    //Напишіть програму, яка дозволяє користувачу додавати нові товари, змінювати їх кількість та виводити інформацію про товари.

    //Вводимо товари
    unsigned int productCount;
    cout << "Введіть кількість товарів: ";
    cin >> productCount;
    Product* product = new Product[productCount];

    unsigned int k = 0;
    while (k < productCount) {
        addProduct(product, k);
        k++;
    }

    //Виводимо інформацію про товари на екран
    cout << "Список товарів:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "Назва товару: \"" << product[i].name << "\"; ціна: " << product[i].price << "; кількість: " << product[i].count << "." << endl;
    }
    cout << endl;
    
    //Додаємо товари
    unsigned int addingCount;
    cout << "Введіть кількість товарів, що додаються: ";
    cin >> addingCount;

    for (int i = 0; i < addingCount; i++) {
        product = productPlusOne(product, productCount);
        addProduct(product, productCount - 1);
    }

    //Виводимо інформацію про товари на екран
    cout << "Список товарів:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "Назва товару: \"" << product[i].name << "\"; ціна: " << product[i].price << "; кількість: " << product[i].count << "." << endl;
    }
    cout << endl;

    //Змінюємо кількість товару
    string name;
    cout << "Введіть назву товару, кількість якого треба змінити: ";
    cin >> name;

    int changingProductID = -1;
    for (int i = 0; i < productCount; i++) {
        if (product[i].name == name) {
            changingProductID = i;
            break;
        }
    }
    cout << endl;

    if (changingProductID >= 0) {
        cout << "Введіть нову кількість товару: \"" << product[changingProductID].name << "\" (поточна кількість " << product[changingProductID].count << ") : ";
        cin >> product[changingProductID].count;
        cout << endl;
    }

    //Виводимо інформацію про товари на екран
    cout << "Список товарів:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "Назва товару: \"" << product[i].name << "\"; ціна: " << product[i].price << "; кількість: " << product[i].count << "." << endl;
    }
    cout << endl;

    delete[] product;
    product = nullptr;

    //4. Облік книг в бібліотеці:
    //Створіть структуру Книга, яка містить поля для назви книги, автора та року видання.
    // Напишіть програму, яка дозволяє користувачу додавати нові книги, 
    // шукати книги за автором або роком видання та виводити інформацію про знайдені книги.


    //Вводимо книги
    unsigned int bookCount;
    cout << "Введіть кількість книг: ";
    cin >> bookCount;
    Book *book = new Book[bookCount];

    k = 0;
    while (k < bookCount) {
        addBook(book, k);
        k++;
    }
    cout << endl;

    //Виводимо інформацію про книги на екран
    cout << "Список книг:" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "Назва книги: \"" << book[i].name << "\"; автор: " << book[i].author << "; рік видання: " << book[i].year << "." << endl;
    }
    cout << endl;

    //Додаємо книги
    cout << "Введіть кількість книг, що додаються: ";
    cin >> addingCount;

    for (int i = 0; i < addingCount; i++) {
        book = BookPlusOne(book, bookCount);
        addBook(book, bookCount - 1);
    }
    cout << endl;

    //Виводимо інформацію про книги на екран
    cout << "Список книг:" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "Назва книги: \"" << book[i].name << "\"; автор: " << book[i].author << "; рік видання: " << book[i].year << "." << endl;
    }
    cout << endl;

    // Шукаємо книги за автором або роком видання

    string searchString;
    cout << "Введіть ім'я автора або рік видання книги для пошуку: ";
    cin >> searchString;

    cout << "Знайдені книги: " << endl;
    for (int i = 0; i < bookCount; i++) {
        if ((book[i].author == searchString) || (to_string(book[i].year) == searchString)) {
            cout << "Назва книги: \"" << book[i].name << "\"; автор: " << book[i].author << "; рік видання: " << book[i].year << "." << endl;
        }
    }
    cout << endl;

    delete[] book;
    book = nullptr;

    //5. Облік працівників у компанії:
    //Створіть структуру Працівник, яка містить поля для імені працівника, його посади та зарплати.
    //Напишіть програму, яка дозволяє користувачу додавати нових працівників, змінювати їх посаду та зарплату, 
    //а також виводити інформацію про всіх працівників.

    //Вводимо працівників
    unsigned int workerCount;
    cout << "Введіть кількість працівників: ";
    cin >> workerCount;
    Worker* worker = new Worker[workerCount];

    k = 0;
    while (k < workerCount) {
        addWorker(worker, k);
        k++;
    }
    cout << endl;

    //Виводимо інформацію про працівників на екран
    cout << "Список працівників:" << endl;
    for (int i = 0; i < workerCount; i++) {
        cout << "Ім'я працівника: \"" << worker[i].name << "\"; посада: " << worker[i].position << "; зарплатня: " << worker[i].salary << "." << endl;
    }
    cout << endl;

    //Додаємо працівників
    cout << "Введіть кількість працівників, що додаються: ";
    cin >> addingCount;

    for (int i = 0; i < addingCount; i++) {
        worker = WorkerPlusOne(worker, workerCount);
        addWorker(worker, workerCount - 1);
    }
    cout << endl;

    //Виводимо інформацію про працівників на екран
    cout << "Список працівників:" << endl;
    for (int i = 0; i < workerCount; i++) {
        cout << "Ім'я працівника: \"" << worker[i].name << "\"; посада: " << worker[i].position << "; зарплатня: " << worker[i].salary << "." << endl;
    }
    cout << endl;

    //Змінюємо посаду працівників
    cout << "Введіть ім'я працівника, посаду якого треба змінити: ";
    cin >> name;

    changingProductID = -1;
    for (int i = 0; i < workerCount; i++) {
        if (worker[i].name == name) {
            changingProductID = i;
            break;
        }
    }
    cout << endl;

    if (changingProductID >= 0) {
        cout << "Введіть нову посаду працівника: \"" << worker[changingProductID].name << "\" (поточна посада " << worker[changingProductID].position << ") : ";
        cin >> worker[changingProductID].position;
        cout << endl;
    }

    //Виводимо інформацію про працівників на екран
    cout << "Список працівників:" << endl;
    for (int i = 0; i < workerCount; i++) {
        cout << "Ім'я працівника: \"" << worker[i].name << "\"; посада: " << worker[i].position << "; зарплатня: " << worker[i].salary << "." << endl;
    }
    cout << endl;

    //Змінюємо зарплатню працівників
    cout << "Введіть ім'я працівника, зарплатню якого треба змінити: ";
    cin >> name;

    changingProductID = -1;
    for (int i = 0; i < workerCount; i++) {
        if (worker[i].name == name) {
            changingProductID = i;
            break;
        }
    }
    cout << endl;

    if (changingProductID >= 0) {
        cout << "Введіть нову зарплатню працівника: \"" << worker[changingProductID].name << "\" (поточна зарплатня " << worker[changingProductID].salary << ") : ";
        cin >> worker[changingProductID].salary;
        cout << endl;
    }

    //Виводимо інформацію про працівників на екран
    cout << "Список працівників:" << endl;
    for (int i = 0; i < workerCount; i++) {
        cout << "Ім'я працівника: \"" << worker[i].name << "\"; посада: " << worker[i].position << "; зарплатня: " << worker[i].salary << "." << endl;
    }
    cout << endl; 

    delete[] worker;
    worker = nullptr;
    

    //Покажчики

    //1. Зміна значення змінної за допомогою покажчика:
    //Напишіть програму, яка приймає від користувача число, а потім змінює його значення, використовуючи покажчик.

    int a;
    cout << "Введіть число a: ";
    cin >> a;

    int *b = &a;
    cout << "Введіть нове значення цього числа: ";
    cin >> *b;
    cout << "a = " << a << endl << endl;

    //2. Передача масиву до функції через покажчик:
    //Створіть функцію, яка приймає масив та його розмір через покажчик, та знаходить середнє значення всіх елементів масиву.

    int arraySize = 5;
    int *array = new int[arraySize];

    srand(time(NULL));
    cout << "Масив (" << arraySize << " елементів): ";
    for (int i = 0; i < arraySize; i++) array[i] = rand() % 19 - 9;
    for (int i = 0; i < arraySize; i++) cout << array[i] << "\t";
    cout << endl;

    cout << "Середнє значення елементів масиву: " << getAvg(array, arraySize) << endl << endl;

    delete[] array;
    array = nullptr;

    //3. Використання динамічно виділеної пам'яті:
    //Створіть програму, яка динамічно виділяє пам'ять для масиву чисел, заповнює його значеннями та потім виводить їх на екран.
  
    int sizeOfArray;
    cout << "Введіть кількість елементів масиву: ";
    cin >> sizeOfArray;
    int* dynArray = new int[sizeOfArray];

    srand(time(NULL));
    cout << "Масив (" << sizeOfArray << " елементів): ";
    for (int i = 0; i < sizeOfArray; i++) dynArray[i] = rand() % 19 - 9;
    for (int i = 0; i < sizeOfArray; i++) cout << dynArray[i] << "\t";
    cout << endl << endl;

    delete[] dynArray;
    dynArray = nullptr;

    //4. Використання покажчиків на структури:
    //Створіть структуру, яка містить декілька полів, а потім створіть покажчик на цю структуру і працюйте з ним 
    // (наприклад, змінюйте значення полів чи викликайте функції для обробки цієї структури).

    BoxSize boxsize;

    boxsize.x = 1;
    boxsize.y = 2;
    boxsize.z = 3;

    BoxSize* pBoxSize;

    pBoxSize = &boxsize;

    cout << "Розміри коробки:" << endl;
    cout << "Довжина: " << (*pBoxSize).x << "; глибина: " << pBoxSize->y << "; висота: " << (*pBoxSize).z << "." << endl;

    cout << "Введіть нове значення довжини коробки: ";
    cin >> pBoxSize->x;

    cout << "Розміри коробки:" << endl;
    cout << "Довжина: " << pBoxSize->x << "; глибина: " << (*pBoxSize).y << "; висота: " << pBoxSize->z << "." << endl;


    cout << "Зменьшимо розміри коробки вдвічі:" << endl;
    divideTwo(pBoxSize);
    cout << "Довжина: " << pBoxSize->x << "; глибина: " << (*pBoxSize).y << "; висота: " << pBoxSize->z << "." << endl;
}