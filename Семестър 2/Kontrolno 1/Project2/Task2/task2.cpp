#include<iostream>
#include<fstream>
using namespace std;

class Pencil;
void readFromTextFile(Pencil**&, const char*);
void writeToBinaryFile(Pencil**&, const char*, const int);

class Pencil
{
public:
	Pencil();
	Pencil(const char*, const int, const int);
	Pencil(const Pencil&);
	Pencil& operator = (const Pencil&);
	~Pencil();

	friend void readFromTextFile(Pencil**&, const char*);
	friend void writeToBinaryFile(Pencil**&, const char*, const int);
	bool sameBrand(const char*);

private:
	char* brand;
	unsigned int year;
	unsigned int hardness;

	void copy(char*&, const char*);
	void deleteMemory();
};

Pencil::Pencil()
{
	brand = nullptr;
	year = 0;
	hardness = 0;
}

Pencil::Pencil(const char* brandParam, const int yearParam, const int hardnessParam)
{
	bool a = (strlen(brandParam) >= 100);
	bool b = (yearParam < 0);
	bool c = (hardnessParam < 0 || hardnessParam > 14);
	
	if (a || b || c)
		throw exception("Invalid input.");

	copy(brand, brandParam);
	year = yearParam;
	hardness = hardnessParam;
}

Pencil::Pencil(const Pencil& source)
{
	copy(brand, source.brand);
	year = source.year;
	hardness = source.hardness;
}

Pencil& Pencil::operator = (const Pencil& source)
{
	if (this != &source)
	{
		deleteMemory();

		copy(brand, source.brand);
		year = source.year;
		hardness = source.hardness;
	}
	return *this;
}

Pencil::~Pencil()
{
	deleteMemory();
}

void readFromTextFile(Pencil**& pencils, const char* fileName)
{
	ifstream in(fileName);

	if (!in)
	{
		cout<< "> Could not open file." << endl;
		return;
	}

	char buffer[101];
	size_t i = 0;

	while (in)
	{
		in.getline(buffer, 101, ' ');
		(*pencils[i]).year = atoi(buffer);

		in.getline(buffer, 101, ' ');
		(*pencils[i]).hardness = atoi(buffer);

		in.getline(buffer, 101, ' ');
		if ((*pencils[i]).brand == nullptr)
			(*pencils[i]).brand = new char[strlen(buffer) + 1];
		if ((*pencils[i]).brand != nullptr)
		{
			delete[](*pencils[i]).brand;
			(*pencils[i]).brand = new char[strlen(buffer) + 1];
		}
		strcpy_s((*pencils[i]).brand, strlen(buffer) + 1, buffer);

		in.get();

		i++;
	}

	in.close();
}

void writeToBinaryFile(Pencil**& pencils, const char* fileName, const int size)
{
	ofstream out(fileName, ios::binary);

	if (!out)
	{
		cout << "> Could not open file." << endl;
		return;
	}

	int i = 0;
	while (i < size)
	{
		out.write((const char*)&(*pencils[i]).year, sizeof(unsigned int));
		out.write((const char*)&(*pencils[i]).hardness, sizeof(unsigned int));

		size_t sizeBrand = strlen((*pencils[i]).brand) + 1;
		out.write((*pencils[i]).brand, sizeBrand);
	}
	
	out.close();
}

bool Pencil::sameBrand(const char* toCompare)
{
	return (strcmp(brand, toCompare) == 0);
}

void Pencil::deleteMemory()
{
	delete[] brand;
	brand = nullptr;
}

void Pencil::copy(char*& target, const char* source)
{
	size_t size = strlen(source) + 1;
	target = new char[size];
	strcpy_s(target, size, source);
}

int main()
{
	Pencil p1;
	Pencil p2;
	Pencil p3;

	Pencil** arr = new Pencil * [3];
	*arr[0] = p1;
	*arr[1] = p2;
	*arr[2] = p3;

	readFromTextFile(arr, "pencils.txt");
	writeToBinaryFile(arr, "branded.dat", 3);

	delete[] arr;
	return 0;
}