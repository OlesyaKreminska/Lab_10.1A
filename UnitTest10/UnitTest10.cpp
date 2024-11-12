#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1 A/Lab_10.1 A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(StudentTests)
    {
    public:

        
        TEST_METHOD(TestCountHighAverageGrade)
        {
            
            Student students[3];

            students[0].surname = "Іванов";
            students[0].course = 1;
            students[0].speciality = COMPUTER_SCIENCE;
            students[0].physicsGrade = 5;
            students[0].mathGrade = 5;
            students[0].informaticsGrade = 5;

            students[1].surname = "Петров";
            students[1].course = 2;
            students[1].speciality = INFORMATICS;
            students[1].physicsGrade = 4;
            students[1].mathGrade = 4;
            students[1].informaticsGrade = 4;

            students[2].surname = "Сидоров";
            students[2].course = 3;
            students[2].speciality = MATH_AND_ECON;
            students[2].physicsGrade = 3;
            students[2].mathGrade = 5;
            students[2].informaticsGrade = 4;

           
            int highAvgCount = CountHighAverageGrade(students, 3);

          
            Assert::AreEqual(1, highAvgCount);
        }

       
    };
}
