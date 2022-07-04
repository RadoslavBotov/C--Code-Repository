#include<iostream>
using namespace std;

template<typename T>
class MyVector
{
public:
	MyVector(const size_t capacityParam = 10)
	{
		capacity = capacityParam;
		size = 0;

		for (size_t i = 0; i < size; i++)
			array[i] = nullptr;
	}

	template<typename T>
	MyVector(const MyVector& source)
	{
		capacity = source.capacity;
		size = source.size;

		for (size_t i = 0; i < size; i++)
			array[i] = new T[source.array[i]];
	}

	template<typename T>
	MyVector& operator = (const MyVector& source)
	{
		if (this != &source)
		{
			deleteMemory();

			capacity = source.capacity;
			size = source.size;

			for (size_t i = 0; i < size; i++)
				array[i] = new T[source.array[i]];
		}
		return *this;
	}

	~MyVector()
	{
		deleteMemory();
	}

	template<typename T>
	T pop()
	{
		T tempElement = *array[size - 1];
		
		delete array[size - 1];
		array[size - 1] = nullptr;
		
		size--;
	
		return tempElement;
	}

	template<typename T>
	T unshift() // remove element in beginning
	{
		for (size_t i = 0; i < size; i++)
			array[i] = array[i + 1];

		delete array[size - 1];
		array[size - 1] = nullptr;
	}

	template<typename T>
	void shift(T element)// place element in beginning
	{
		insetAt(0, element);
	}

	template<typename T>
	void set(int index, T element)
	{
		if (array[index] == nullptr)
			array[index] = new T[element];
		else
			array[index] = element;
	}

	template<typename T>
	void push(T element) // place element in the end
	{
		if (size == capacity)
			resize<T>();
		
		array[size] = new T;
		*array[size] = element;

		size++;
	}

	template<typename T>
	void insetAt(int index, T element)
	{
		if (size == capacity)
			resize<T>();

		array[size] = new T[array[size - 1]];
		for (size_t i = size - 1; i > index; i--)
			array[i] = array[i - 1];

		array[index] = element;
	}

	template<typename T>
	T get(int index) const
	{
		if (array[index] != nullptr)
			return array[index];
		else
			cout << "No element at index: " << index << endl;
	}

	size_t getLength() const
	{
		return size;
	}

private:
	T** array;
	size_t capacity;
	size_t size;

	void deleteMemory()
	{
		for (size_t i = 0; i < capacity; i++)
			delete array[i];
		delete[] array;
	}

	template<typename T>
	void resize()
	{
		size_t newCapacity = capacity + 10;
		T** newArray = new T * [newCapacity];

		for (size_t i = 0; i < newCapacity; i++)
			newArray[i] = nullptr;

		for (size_t i = 0; i < capacity; i++)
			newArray[i] = new T(*array[i]);

		size_t tempCapacity = capacity;

		deleteMemory();

		size = tempCapacity;
		capacity = newCapacity;
		array = newArray;
		capacity = newCapacity;
	}
};

int main()
{
	MyVector<int> v1;
	
	v1.push(1);
	v1.push(2);
	v1.push(3);

	for (size_t i = 0; i < 3; i++)
		cout << v1.pop<int>() << " ";

	return 0;
}