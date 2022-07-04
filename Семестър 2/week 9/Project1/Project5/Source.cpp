#include<iostream>
using namespace std;

class Book;
ostream& operator << (ostream&, const Book&);

class Book
{
public:
	Book()
	{
		copy(name, "\0");
		copy(author, "\0");
		year = 0;
		price = 0;
	}

	Book(const char* nameP, const char* authorP, const unsigned int yearP, const double priceP)
	{
		copy(name, nameP);
		copy(author, authorP);
		year = yearP;
		price = priceP;
	}

	Book(const Book& source)
	{
		copy(name, source.name);
		copy(author, source.author);
		year = source.year;
		price = source.price;
	}

	Book& operator = (const Book& source)
	{
		if (this != &source)
		{
			deleteMemory();

			copy(name, source.name);
			copy(author, source.author);
			year = source.year;
			price = source.price;
		}
		return *this;
	}

	~Book()
	{
		deleteMemory();
	}

	double getPrice()
	{
		return price;
	}

	friend ostream& operator << (ostream& os, const Book& source)
	{
		cout << source.name << " " << source.author << " " << source.year << " " << source.price;
		return os;
	}

private:
	char* name;
	char* author;
	unsigned int year;
	double price;

	void copy(char*& target, const char* source)
	{
		size_t size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] name;
		delete[] author;
	}
};

class BookStore;
void sort(BookStore*&);
ostream& operator << (ostream&, const BookStore&);

class BookStore
{
public:

	BookStore(const char* nameP = "\0", const unsigned int capacityP = 0)
	{
		copy(name, nameP);
		capacity = capacityP;
		catalog = new Book[capacity];
		size = 0;
	}

	BookStore(const BookStore& source)
	{
		copy(name, source.name);
		capacity = source.capacity;
		copy(catalog, source.catalog, capacity);
		size = source.size;
	}

	BookStore& operator = (const BookStore& source)
	{
		if (this != &source)
		{
			deleteMemory();

			copy(name, source.name);
			capacity = source.capacity;
			catalog = new Book[capacity];
			copy(catalog, source.catalog, capacity);
			size = source.size;
		}
		return *this;
	}

	~BookStore()
	{
		deleteMemory();
	}

	void addBook(const Book& source)
	{
		if (size < capacity)
		{
			catalog[size] = source;
			size++;
		}
		else cout<< "> Catalog at capacity." << endl;
	}

	double getCatalogPrice()
	{
		double result = 0;
		for (unsigned int i = 0; i < size; i++)
			result += catalog[i].getPrice();
		return result;
	}

	friend ostream& operator << (ostream& os, const BookStore& source)
	{
		cout << source.name << " :" << endl;
		for (unsigned int i = 0; i < source.size; i++)
			cout << source.catalog[i] << endl;
		return os;
	}

private:
	char* name;
	Book* catalog;
	unsigned int capacity;
	unsigned int size;

	void copy(char*& target, const char* source)
	{
		size_t size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void copy(Book*& target, Book* source, const unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
			target[i] = source[i];
	}

	void deleteMemory()
	{
		delete[] name;
		delete[] catalog;
	}
};

void sortBookStore(BookStore**& arr, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if ((*arr[j]).getCatalogPrice() > (*arr[j + 1]).getCatalogPrice())
			{
				BookStore* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main()
{
	Book book1("Book 1", "Radoslav", 2022, 10);

	BookStore bookStore1("Book store 1", 1);
	BookStore bookStore2("Book store 2", 2);
	BookStore bookStore3("Book store 3", 3);
	BookStore bookStore4("Book store 4", 4);
	BookStore bookStore5("Book store 5", 5);
	BookStore bookStore6("Book store 6", 6);

	bookStore1.addBook(book1);

	bookStore2.addBook(book1);
	bookStore2.addBook(book1);

	bookStore3.addBook(book1);
	bookStore3.addBook(book1);
	bookStore3.addBook(book1);

	bookStore4.addBook(book1);
	bookStore4.addBook(book1);
	bookStore4.addBook(book1);
	bookStore4.addBook(book1);

	bookStore5.addBook(book1);
	bookStore5.addBook(book1);
	bookStore5.addBook(book1);
	bookStore5.addBook(book1);
	bookStore5.addBook(book1);

	bookStore6.addBook(book1);
	bookStore6.addBook(book1);
	bookStore6.addBook(book1);
	bookStore6.addBook(book1);
	bookStore6.addBook(book1);
	bookStore6.addBook(book1);

	BookStore** array = new BookStore*[6];
	array[0] = &bookStore6;
	array[1] = &bookStore5;
	array[2] = &bookStore4;
	array[3] = &bookStore3;
	array[4] = &bookStore2;
	array[5] = &bookStore1;
	
	sortBookStore(array, 6);
	
	// 10 20 30 40 50 60 / BS1 BS2 BS3 BS4 BS5 BS6
	for (int i = 0; i < 6; i++)
		cout << *array[i] << endl;

	return 0;
}