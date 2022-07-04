#include<iostream>
#include<cstring>
using namespace std;

const int MAX_GRADES = 15;
const int MAX_LENGTH = 30;
const int MAX_SUBJECTS = 100;

struct Subject
{
	int mGradesIndex = 0;
	int mGrades[MAX_GRADES];
	char mName[MAX_LENGTH];
};

struct Gradebook
{
	// int mSubjectIndex = 0;
	Subject mSubjects[MAX_SUBJECTS];
};

void addGradeToSubject(Gradebook& gb, int grade, const char* subjectName)
{
	for (int i = 0; i < MAX_SUBJECTS; i++)
	{
		if (strcmp(gb.mSubjects[i].mName, subjectName) == 0)
		{
			gb.mSubjects[i].mGrades[gb.mSubjects->mGradesIndex++] = grade;
		}
	}

}

void summarizeSubject()
{

}

void summarizeGradebook()
{

}

void checkForGrade()
{

}

int main()
{

	return 0;
}