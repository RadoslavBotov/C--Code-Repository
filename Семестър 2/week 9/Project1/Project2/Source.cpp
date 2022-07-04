#include<iostream>
#include<fstream>
using namespace std;

class BasicInfo;
ostream& operator << (ostream& os, const BasicInfo& source);

class BasicInfo
{
public:
	BasicInfo(const char* EGNParam = "\0", const char* firstNameParam = "\0", const char* familyNameParam = "\0", const char* adressParam = "\0")
	{
		copy(EGN, EGNParam);
		copy(firstName, firstNameParam);
		copy(familyName, familyNameParam);
		copy(adress, adressParam);
	}

	BasicInfo(const BasicInfo& source)
	{
		copy(EGN, source.EGN);
		copy(firstName, source.firstName);
		copy(familyName, source.familyName);
		copy(adress, source.adress);
	}

	BasicInfo operator = (const BasicInfo& source)
	{
		if (this != &source)
		{
			deleteMemory();

			copy(EGN, source.EGN);
			copy(firstName, source.firstName);
			copy(familyName, source.familyName);
			copy(adress, source.adress);
		}
		return *this;
	}

	~BasicInfo()
	{
		deleteMemory();
	}

	char* getEGN() const
	{
		return EGN;
	}

	char* getFirstName() const
	{
		return firstName;
	}

	char* getFamilyName() const
	{
		return familyName;
	}

	void writeToBinaryFile(const char* fileName) const
	{
		std::ofstream out(fileName, std::ios::binary);

		if (!out)
		{
			cout << "> Cannot access " << fileName << " !" << endl;
			return;
		}

		write(out, EGN);
		write(out, firstName);
		write(out, familyName);
		write(out, adress);

		out.close();
	}

	void readFromBinaryFile(const char* fileName) const
	{
		std::ifstream in(fileName, std::ios::binary);

		if (!in)
			return;

		char* str = nullptr;

		read(in, str); // EGN
		read(in, str); // firstName
		read(in, str); // familyName
		read(in, str); // adress

		delete[] str;
		in.close();
	}

	void serialize(ofstream& streamName)
	{
		write(streamName, EGN);
		write(streamName, firstName);
		write(streamName, familyName);
		write(streamName, adress);
	}

	friend ostream& operator << (ostream& os, const BasicInfo& source);

private:
	char* EGN;
	char* firstName;
	char* familyName;
	char* adress;

	void read(ifstream& streamName, char*& target) const
	{
		size_t size = 0;

		streamName.read((char*)&size, sizeof(size_t));
		target = new char[size];
		streamName.read(target, size);

		cout << target << endl;
	}

	void write(ofstream& streamName, const char* source) const
	{
		size_t size = strlen(source) + 1;
		streamName.write((const char*)&size, sizeof(size_t));
		streamName.write(source, size);
	}

	void copy(char *& target, const char* source)
	{
		unsigned int size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] EGN;
		delete[] firstName;
		delete[] familyName;
		delete[] adress;
	}
};

ostream& operator << (ostream& os, const BasicInfo& source)
{
	os << source.EGN << " " << source.firstName << " " << source.familyName << " " << source.adress << endl;
	return os;
}

class User;
ostream& operator << (ostream&, const User&);
istream& operator >> (istream&, const User&);

class PhoneNumber
{
public:
	PhoneNumber(const char* numberParam = "\0")
	{
		unsigned int size = strlen(numberParam) + 1;
		number = new char[size];
		strcpy_s(number, size, numberParam);
	}

	PhoneNumber(const PhoneNumber& source)
	{
		unsigned int size = strlen(source.number) + 1;
		number = new char[size];
		strcpy_s(number, size, source.number);
	}

	PhoneNumber operator = (const PhoneNumber& source)
	{
		if (this != &source)
		{
			delete[] number;

			unsigned int size = strlen(source.number) + 1;
			number = new char[size];
			strcpy_s(number, size, source.number);
		}
		return *this;
	}

	~PhoneNumber()
	{
		delete[] number;
	}

	char* getNumber() const
	{
		return number;
	}

	void serialize(ofstream& fileName)
	{
		size_t size = strlen(number) + 1;
		fileName.write((const char*)&size, sizeof(size_t));
		fileName.write(number, size);
	}

	void serialize(ostream& os)
	{

	}

	void deserialize(istream& os)
	{

	}

private:
	char* number;
};

class User
{
public:
	User(const BasicInfo infoParam ,const char* nameParam, const char* passwordParam, const PhoneNumber numberParam)
	{
		info = infoParam;
		copy(name, nameParam);
		copy(password, passwordParam);
		number = numberParam;
	}

	User(const User& source)
	{
		info = source.info;
		copy(name, source.name);
		copy(password, source.password);
		number = source.number;
	}

	User operator = (const User& source)
	{
		if (this != &source)
		{
			deleteMemory();

			info = source.info;
			copy(name, source.name);
			copy(password, source.password);
			number = source.number;
		}
		return *this;
	}

	~User()
	{
		deleteMemory();
	}

	char* getName() const
	{
		return name;
	}

	PhoneNumber getPhoneNumberObj()
	{
		return number;
	}

	char* getPhoneNumberChar()
	{
		return number.getNumber();
	}

	friend ostream& operator << (ostream&, User&);
	friend istream& operator >> (istream&, User&);

	void serialize(ostream& os)
	{
		char fileName[100] = "Binary_User_";
		strcat_s(fileName, 100, name);

		ofstream out(fileName, ios::binary);

		info.serialize(out);

		copy(out, name);
		copy(out, password);

		number.serialize(out);

		out.close();
	}

	void copy(ofstream& streamName, const char* source) const // source -> char* to write in file
	{
		size_t size = strlen(source) + 1;
		streamName.write((const char*)&size, sizeof(size_t));
		streamName.write(source, size);
	}

	void deserialize(istream& is)
	{

	}

private:
	BasicInfo info;
	char* name;
	char* password;
	PhoneNumber number;

	void copy(char*& target, const char* source)
	{
		unsigned int size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] name;
		delete[] password;
	}
};

ostream& operator << (ostream& os, User& source)
{
	source.serialize(os);
	return os;
}

istream& operator >> (istream& is, User& target)
{
	target.deserialize(is);
	return is;
}

int main()
{
	BasicInfo obj1("02345678", "Radoslav", "Botov", "qwerty");
	
	char fileName[100] = "Binary_BasicInfo_";
	strcat_s(fileName, 100, obj1.getFirstName());

	//obj1.writeToBinaryFile(fileName);
	obj1.readFromBinaryFile(fileName);

	PhoneNumber phone1("1234567890");
	User user1(obj1, obj1.getFirstName(), "0000", phone1);

	cout << user1;

	return 0;
}