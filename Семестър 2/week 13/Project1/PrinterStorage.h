#pragma once
#include<iostream>
#include"Printer.h"

class PrinterStorage
{
public:
	PrinterStorage(size_t capacityParam = 10)
	{
		capacity = capacityParam;
		size = 0;

		printers = new Printer * [capacity];
		for (size_t i = 0; i < capacity; i++)
			printers[i] = nullptr;
	}

	PrinterStorage(const PrinterStorage& source)
	{
		capacity = source.capacity;
		size = source.size;

		for (size_t i = 0; i < size; i++)
			printers[i] = source.printers[i]->clone();
	}

	PrinterStorage& operator = (const PrinterStorage& source)
	{
		if (this != &source)
		{
			freeMemory();

			capacity = source.capacity;
			size = source.size;

			for (size_t i = 0; i < size; i++)
				printers[i] = source.printers[i]->clone();
		}
		return *this;
	}

	~PrinterStorage()
	{
		freeMemory();
	}

	void addBwLaserPrinter(HelperString modelParam, bool hasWarantyParam, unsigned pagesAMinuteParam, double priceParam)
	{
		if (capacity == size)
		{
			std::cout << "> No more space in storage!\n";
			return;
		}

		BwLaser printer(modelParam, hasWarantyParam, pagesAMinuteParam, priceParam);
		addPrinter(&printer);
	}

	void addColorLaserPrinter(HelperString modelParam, unsigned numberOfColorsParam, unsigned pagesAMinuteParam, double priceParam)
	{
		if (capacity == size)
		{
			std::cout << "> No more space in storage!\n";
			return;
		}

		ColorLaser printer(modelParam, numberOfColorsParam, pagesAMinuteParam, priceParam);
		addPrinter(&printer);
	}

	void addColorInkjetPrinter(HelperString modelParam, unsigned numberOfColorsParam, bool hasWarantyParam, unsigned pagesAMinuteParam, double priceParam)
	{
		if (capacity == size)
		{
			std::cout << "> No more space in storage!\n";
			return;
		}

		ColorInkjet printer(modelParam, numberOfColorsParam, hasWarantyParam, pagesAMinuteParam, priceParam);
		addPrinter(&printer);
	}

	void printByType()
	{
		for (size_t i = 0; i < size - 1; i++)
			for (size_t j = 0; j < size - i - 1; j++)
				if (printers[j] > printers[j + 1])
				{
					// swap
				}

		print();
	}

	void printByBrand()
	{


		print();
	}

private:
	Printer** printers;
	size_t capacity;
	size_t size;

	void freeMemory()
	{
		for (size_t i = 0; i < size; i++)
			delete printers[i];
		delete[] printers;

		capacity = 0;
		size = 0;
	}

	void addPrinter(const Printer* source)
	{
		printers[size++] = source->clone();
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
			printers[i]->print();
	}
};